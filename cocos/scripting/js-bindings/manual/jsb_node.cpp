//
//  jsb_node.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 4/26/17.
//
//

#include "jsb_node.hpp"
#include "jsb_global.h"
#include "jsb_conversions.hpp"
#include "ScriptingCore.h"

#include "cocos2d.h"

using namespace cocos2d;

#define STANDALONE_TEST 1

extern se::Object* __jsb_cocos2dx_Node_proto;
extern se::Class* __jsb_cocos2dx__Node_class;

se::Object* __jsb_Node_proto = nullptr;
se::Class* __jsb_Node_class = nullptr;

SE_FINALIZE_FUNC_BEGIN(Node_finalized)
{
    if (nativeThisObject)
    {
        Node* thiz = (Node*) nativeThisObject;
        printf("Node_finalized %p ...\n", thiz->getUserData());
        SAFE_RELEASE(thiz);
    }
}
SE_FINALIZE_FUNC_END

SE_CTOR_BEGIN(Node_constructor, __jsb_Node_class, Node_finalized)
{
    printf("Node_constructor ...\n");
    Node* obj = new Node();
    thisObject->setPrivateData(obj);
}
SE_CTOR_END

SE_CTOR2_BEGIN(Node_ctor, __jsb_Node_class, Node_finalized)
{
    printf("Node_ctor ...\n");
    Node* obj = new Node();
    thisObject->setPrivateData(obj);
}
SE_CTOR2_END

SE_FUNC_BEGIN(Node_create, se::DONT_NEED_THIS)
{
    Node* node = Node::create();
    node->retain();
    auto obj = se::Object::createObjectWithClass(__jsb_Node_class, false);
    obj->setPrivateData(node);
    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END

SE_FUNC_BEGIN(Node_onEnter, se::DONT_NEED_THIS)
{
    ScriptingCore::getInstance()->setCalledFromScript(true);
    Node* thiz = (Node*)nativeThisObject;
    thiz->onEnter();
}
SE_FUNC_END

SE_FUNC_BEGIN(Node_onExit, se::DONT_NEED_THIS)
{
    ScriptingCore::getInstance()->setCalledFromScript(true);
    Node* thiz = (Node*)nativeThisObject;
    thiz->onExit();
}
SE_FUNC_END

SE_FUNC_BEGIN(Node_onEnterTransitionDidFinish, se::DONT_NEED_THIS)
{
    ScriptingCore::getInstance()->setCalledFromScript(true);
    Node* thiz = (Node*)nativeThisObject;
    thiz->onEnterTransitionDidFinish();
}
SE_FUNC_END

SE_FUNC_BEGIN(Node_onExitTransitionDidStart, se::DONT_NEED_THIS)
{
    ScriptingCore::getInstance()->setCalledFromScript(true);
    Node* thiz = (Node*) nativeThisObject;
    thiz->onExitTransitionDidStart();
}
SE_FUNC_END

SE_FUNC_BEGIN(Node_cleanup, se::DONT_NEED_THIS)
{
    ScriptingCore::getInstance()->setCalledFromScript(true);
    Node* thiz = (Node*)nativeThisObject;
    thiz->cleanup();
}
SE_FUNC_END

SE_FUNC_BEGIN(Node_addChild, se::DONT_NEED_THIS)
{
    Node* thiz = (Node*)nativeThisObject;
    Node* child = (Node*)args[0].toObject()->getPrivateData();
    thiz->addChild(child);
}
SE_FUNC_END

static std::unordered_map<se::Object*, std::unordered_map<se::Object*, std::string>> __jsthis_schedulekey_map;

static bool isScheduleExist(se::Object* jsFunc, se::Object* jsThis, se::Object** outJsFunc, se::Object** outJsThis, std::string* outKey)
{
    bool found = false;
    for (const auto& e : __jsthis_schedulekey_map)
    {
        if (e.first->isSame(jsThis))
        {
            for (const auto& e2 : e.second)
            {
                if (e2.first->isSame(jsFunc))
                {
                    *outJsThis = e.first;
                    *outJsFunc = e2.first;
                    *outKey = e2.second;
                    break;
                }
            }
        }
        if (!(*outKey).empty())
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        (*outKey).clear();
        (*outJsThis) = nullptr;
        (*outJsFunc) = nullptr;
    }

    return found;
}

static void removeSchedule(se::Object* jsFunc, se::Object* jsThis)
{
    auto funcObjKeyMapIter = __jsthis_schedulekey_map.find(jsThis);
    if (funcObjKeyMapIter != __jsthis_schedulekey_map.end())
    {
        jsThis->detachChild(jsFunc);
        funcObjKeyMapIter->second.erase(jsFunc);
        if (funcObjKeyMapIter->second.empty())
            __jsthis_schedulekey_map.erase(funcObjKeyMapIter);

        jsFunc->release();
        jsThis->release();
    }
}

static void removeScheduleByKey(const std::string& key)
{
    se::Object* jsFunc = nullptr;
    se::Object* jsThis = nullptr;

    for (const auto& e : __jsthis_schedulekey_map)
    {
        for (const auto& e2 : e.second)
        {
            if (e2.second == key)
            {
                jsThis = e.first;
                jsFunc = e2.first;
                break;
            }
        }

        if (jsThis != nullptr && jsFunc != nullptr)
            break;
    }

    removeSchedule(jsFunc, jsThis);
}

static void insertSchedule(se::Object* jsFunc, se::Object* jsThis, const std::string& key)
{
    auto& funcKeyMap = __jsthis_schedulekey_map[jsThis];
    funcKeyMap.emplace(jsFunc, key);
    jsFunc->addRef();
    jsThis->addRef();
}

class UnscheduleNotifier
{
public:
    UnscheduleNotifier(Node* node, const std::string& key)
    : _node(node)
    , _key(key)
    {
        _node->retain();
    }
    ~UnscheduleNotifier()
    {
        printf("~UnscheduleNotifier, node: %p, key: %s\n", _node, _key.c_str());

        Node* node = _node;
        std::string key = _key;
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([node, key](){
            removeScheduleByKey(key);
            if (node->isScheduled(key))
                node->unschedule(key);

            node->release();
        });
    }

private:
    Node* _node;
    std::string _key;
};

SE_FUNC_BEGIN(Node_schedule, se::NEED_THIS)
{
    printf("--------------------------\ntarget count: %d\n", (int)__jsthis_schedulekey_map.size());
    for (const auto& e1 : __jsthis_schedulekey_map)
    {
        printf("target: %p, functions: %d\n", e1.first, (int)e1.second.size());
    }
    printf("-------------------------- \n");
    static uint32_t __idx = 0;
    Node* thiz = (Node*)nativeThisObject;
    se::Value jsThis(thisObject);
    se::Value jsFunc(args[0]);
    jsThis.toObject()->attachChild(jsFunc.toObject());

    se::Object* foundThisObj = nullptr;
    se::Object* foundFuncObj = nullptr;
    std::string key;

    bool found = isScheduleExist(jsFunc.toObject(), jsThis.toObject(), &foundFuncObj, &foundThisObj, &key);
    if (found && !key.empty())
    {
        removeSchedule(foundFuncObj, foundThisObj);
        thiz->unschedule(key);
    }

    float interval = 0.0f;
    unsigned int repeat = CC_REPEAT_FOREVER;
    float delay = 0.0f;
    key = StringUtils::format("__node_schedule_key:%u", __idx++);

    if (argc >= 2)
        interval = args[1].toNumber();

    if (argc >= 3)
        repeat = args[2].toNumber();

    if (argc >= 4)
        delay = args[3].toNumber();

    insertSchedule(jsFunc.toObject(), jsThis.toObject(), key);
    std::shared_ptr<UnscheduleNotifier> unscheduleNotifier = std::make_shared<UnscheduleNotifier>(thiz, key);

    thiz->schedule([jsThis, jsFunc, unscheduleNotifier](float dt){
        se::Object* thisObj = jsThis.toObject();
        se::Object* funcObj = jsFunc.toObject();

        se::ValueArray args;
        args.push_back(se::Value((double)dt));
        funcObj->call(args, thisObj);

    }, interval, repeat, delay, key);
}
SE_FUNC_END

SE_FUNC_BEGIN(Node_unschedule, se::NEED_THIS)
{
    Node* thiz = (Node*)nativeThisObject;
    se::Value jsThis(thisObject);
    se::Value jsFunc(args[0]);
    se::Object* foundThisObj = nullptr;
    se::Object* foundFuncObj = nullptr;
    std::string key;

    bool found = isScheduleExist(jsFunc.toObject(), jsThis.toObject(), &foundFuncObj, &foundThisObj, &key);

    if (found && !key.empty())
    {
        removeSchedule(foundFuncObj, foundThisObj);
        thiz->unschedule(key);
    }
    else
    {
        printf("Node_unschedule not found\n");
    }
}
SE_FUNC_END

SE_FUNC_BEGIN(Node_getChildren, se::DONT_NEED_THIS)
{
    Node* thiz = (Node*)nativeThisObject;
    const auto& children = thiz->getChildren();
    se::Value v;
    if (Vector_to_seval(children, &v))
    {
        SE_SET_RVAL(v);
    }
}
SE_FUNC_END

SE_FUNC_BEGIN(Node_foo, se::DONT_NEED_THIS)
{
    SE_SET_RVAL(se::Value("hello world"));
}
SE_FUNC_END

SE_SET_PROPERTY_BEGIN(Node_set_x, se::DONT_NEED_THIS)
{
    Node* thiz = (Node*)nativeThisObject;
    float x = data.toNumber();
    printf("cc.Node set_x (%f) native obj: %p\n", x, thiz);
    thiz->setPositionX(x);
}
SE_SET_PROPERTY_END

SE_GET_PROPERTY_BEGIN(Node_get_x, se::DONT_NEED_THIS)
{
    Node* thiz = (Node*)nativeThisObject;
    SE_SET_RVAL(se::Value(thiz->getPositionX()));
}
SE_GET_PROPERTY_END

SE_SET_PROPERTY_BEGIN(Node_set_y, se::DONT_NEED_THIS)
{
    Node* thiz = (Node*)nativeThisObject;
    float y = data.toNumber();
    printf("cc.Node set_y (%f) native obj: %p\n", y, thiz);
    thiz->setPositionY(y);
}
SE_SET_PROPERTY_END

SE_GET_PROPERTY_BEGIN(Node_get_y, se::DONT_NEED_THIS)
{
    Node* thiz = (Node*)nativeThisObject;
    SE_SET_RVAL(se::Value(thiz->getPositionY()));
}
SE_GET_PROPERTY_END

SE_FUNC_BEGIN(Node_setContentSize, se::DONT_NEED_THIS)
{
    Node* cobj = (Node*)nativeThisObject;
    bool ok = true;
    if (argc == 1)
    {
        cocos2d::Size arg0;
        ok &= seval_to_Size(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");
        cobj->setContentSize(arg0);
    }
    else if (argc == 2)
    {
        float width = 0.0f;
        float height = 0.0f;
        ok &= seval_to_float(args[0], &width);
        ok &= seval_to_float(args[1], &height);
        cobj->setContentSize(cocos2d::Size(width, height));
    }
}
SE_FUNC_END

SE_FUNC_BEGIN(Node_setAnchorPoint, se::DONT_NEED_THIS)
{
    Node* cobj = (Node*)nativeThisObject;
    bool ok = true;
    if (argc == 1)
    {
        cocos2d::Vec2 arg0;
        ok &= seval_to_Vec2(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");
        cobj->setAnchorPoint(arg0);
    }
    else if (argc == 2)
    {
        float x = 0.0f;
        float y = 0.0f;
        ok &= seval_to_float(args[0], &x);
        ok &= seval_to_float(args[1], &y);
        cobj->setAnchorPoint(cocos2d::Vec2(x, y));
    }
}
SE_FUNC_END

bool jsb_register_Node_manual()
{
#if STANDALONE_TEST
    auto cls = se::Class::create("Node", __ccObj, nullptr, Node_constructor);
    cls->defineStaticFunction("create", Node_create);
    cls->defineProperty("x", Node_get_x, Node_set_x);
    cls->defineProperty("y", Node_get_y, Node_set_y);
    cls->defineFunction("ctor", Node_ctor);
#else
    auto cls = __jsb_cocos2dx_Node_proto;
#endif

    cls->defineFunction("onEnter", Node_onEnter);
    cls->defineFunction("onExit", Node_onExit);
    cls->defineFunction("onEnterTransitionDidFinish", Node_onEnterTransitionDidFinish);
    cls->defineFunction("onExitTransitionDidStart", Node_onExitTransitionDidStart);
    cls->defineFunction("cleanup", Node_cleanup);
    cls->defineFunction("schedule", Node_schedule);
    cls->defineFunction("unschedule", Node_unschedule);
    cls->defineFunction("setContentSize", Node_setContentSize);
    cls->defineFunction("setAnchorPoint", Node_setAnchorPoint);

#if STANDALONE_TEST
    cls->defineFunction("addChild", Node_addChild);
    cls->defineFunction("getChildren", Node_getChildren);
    cls->defineFinalizedFunction(Node_finalized);

    cls->install();

    __jsb_Node_proto = cls->getProto();
    __jsb_Node_class = cls;

    __jsb_Node_proto->defineFunction("foo", Node_foo);
    __jsb_Node_proto->setProperty("var1", se::Value("I'm var1"));
    __jsb_Node_proto->setProperty("var2", se::Value(10000.323));
#endif

    return true;
}
