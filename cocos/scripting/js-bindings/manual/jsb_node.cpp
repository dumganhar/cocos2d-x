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

static bool Node_finalized(se::State& s)
{
    if (s.nativeThisObject())
    {
        Node* thiz = (Node*) s.nativeThisObject();
        printf("Node_finalized %p ...\n", thiz->getUserData());
        SAFE_RELEASE(thiz);
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(Node_finalized)

static bool Node_constructor(se::State& s)
{
    printf("Node_constructor ...\n");
    Node* obj = new Node();
    s.thisObject()->setPrivateData(obj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(Node_constructor, __jsb_Node_class, Node_finalized);

static bool Node_ctor(se::State& s)
{
    printf("Node_ctor ...\n");
    Node* obj = new Node();
    s.thisObject()->setPrivateData(obj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR2(Node_ctor, __jsb_Node_class, Node_finalized)

static bool Node_create(se::State& s)
{
    Node* node = Node::create();
    node->retain();
    auto obj = se::Object::createObjectWithClass(__jsb_Node_class, false);
    obj->setPrivateData(node);
    s.rval().setObject(obj);
    return true;
}
SE_BIND_FUNC(Node_create)

static bool Node_onEnter(se::State& s)
{
    ScriptingCore::getInstance()->setCalledFromScript(true);
    Node* thiz = (Node*)s.nativeThisObject();
    thiz->onEnter();
    return true;
}
SE_BIND_FUNC(Node_onEnter)

static bool Node_onExit(se::State& s)
{
    ScriptingCore::getInstance()->setCalledFromScript(true);
    Node* thiz = (Node*)s.nativeThisObject();
    thiz->onExit();
    return true;
}
SE_BIND_FUNC(Node_onExit)

static bool Node_onEnterTransitionDidFinish(se::State& s)
{
    ScriptingCore::getInstance()->setCalledFromScript(true);
    Node* thiz = (Node*)s.nativeThisObject();
    thiz->onEnterTransitionDidFinish();
    return true;
}
SE_BIND_FUNC(Node_onEnterTransitionDidFinish)

static bool Node_onExitTransitionDidStart(se::State& s)
{
    ScriptingCore::getInstance()->setCalledFromScript(true);
    Node* thiz = (Node*)s.nativeThisObject();
    thiz->onExitTransitionDidStart();
    return true;
}
SE_BIND_FUNC(Node_onExitTransitionDidStart)

static bool Node_cleanup(se::State& s)
{
    ScriptingCore::getInstance()->setCalledFromScript(true);
    Node* thiz = (Node*)s.nativeThisObject();
    thiz->cleanup();
    return true;
}
SE_BIND_FUNC(Node_cleanup)

static bool Node_addChild(se::State& s)
{
    const auto& args = s.args();
    Node* thiz = (Node*)s.nativeThisObject();
    Node* child = (Node*)args[0].toObject()->getPrivateData();
    thiz->addChild(child);
    return true;
}
SE_BIND_FUNC(Node_addChild)

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

static bool Node_schedule(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    printf("--------------------------\ntarget count: %d\n", (int)__jsthis_schedulekey_map.size());
    for (const auto& e1 : __jsthis_schedulekey_map)
    {
        printf("target: %p, functions: %d\n", e1.first, (int)e1.second.size());
    }
    printf("-------------------------- \n");
    static uint32_t __idx = 0;
    Node* thiz = (Node*)s.nativeThisObject();
    se::Value jsThis(s.thisObject());
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

    return true;
}
SE_BIND_FUNC(Node_schedule)

static bool Node_unschedule(se::State& s)
{
    const auto& args = s.args();
    Node* thiz = (Node*)s.nativeThisObject();
    se::Value jsThis(s.thisObject());
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
    return true;
}
SE_BIND_FUNC(Node_unschedule)

static bool Node_getChildren(se::State& s)
{
    Node* thiz = (Node*)s.nativeThisObject();
    const auto& children = thiz->getChildren();
    bool ok = Vector_to_seval(children, &s.rval());
    return ok;
}
SE_BIND_FUNC(Node_getChildren)

static bool Node_foo(se::State& s)
{
    s.rval().setString("hello world");
    return true;
}
SE_BIND_FUNC(Node_foo)

static bool Node_set_x(se::State& s)
{
    const auto& args = s.args();
    Node* thiz = (Node*)s.nativeThisObject();
    float x = args[0].toNumber();
    printf("cc.Node set_x (%f) native obj: %p\n", x, thiz);
    thiz->setPositionX(x);
    return true;
}
SE_BIND_PROP_SET(Node_set_x)

static bool Node_get_x(se::State& s)
{
    Node* thiz = (Node*)s.nativeThisObject();
    s.rval().setFloat(thiz->getPositionX());
    return true;
}
SE_BIND_PROP_GET(Node_get_x)

static bool Node_set_y(se::State& s)
{
    const auto& args = s.args();
    Node* thiz = (Node*)s.nativeThisObject();
    float y = args[0].toNumber();
    printf("cc.Node set_y (%f) native obj: %p\n", y, thiz);
    thiz->setPositionY(y);
    return true;
}
SE_BIND_PROP_SET(Node_set_y)

static bool Node_get_y(se::State& s)
{
    Node* thiz = (Node*)s.nativeThisObject();
    s.rval().setFloat(thiz->getPositionY());
    return true;
}
SE_BIND_PROP_GET(Node_get_y)

static bool Node_setContentSize(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    Node* cobj = (Node*)s.nativeThisObject();
    bool ok = true;
    if (argc == 1)
    {
        cocos2d::Size arg0;
        ok &= seval_to_Size(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");
        cobj->setContentSize(arg0);
        return true;
    }
    else if (argc == 2)
    {
        float width = 0.0f;
        float height = 0.0f;
        ok &= seval_to_float(args[0], &width);
        ok &= seval_to_float(args[1], &height);
        cobj->setContentSize(cocos2d::Size(width, height));
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(Node_setContentSize)

static bool Node_setAnchorPoint(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    Node* cobj = (Node*)s.nativeThisObject();
    bool ok = true;
    if (argc == 1)
    {
        cocos2d::Vec2 arg0;
        ok &= seval_to_Vec2(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");
        cobj->setAnchorPoint(arg0);
        return true;
    }
    else if (argc == 2)
    {
        float x = 0.0f;
        float y = 0.0f;
        ok &= seval_to_float(args[0], &x);
        ok &= seval_to_float(args[1], &y);
        cobj->setAnchorPoint(cocos2d::Vec2(x, y));
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(Node_setAnchorPoint)

bool jsb_register_Node_manual()
{
#if STANDALONE_TEST
    auto cls = se::Class::create("Node", __ccObj, nullptr, _SE(Node_constructor));
    cls->defineStaticFunction("create", _SE(Node_create));
    cls->defineProperty("x", _SE(Node_get_x), _SE(Node_set_x));
    cls->defineProperty("y", _SE(Node_get_y), _SE(Node_set_y));
    cls->defineFunction("ctor", _SE(Node_ctor));
#else
    auto cls = __jsb_cocos2dx_Node_proto;
#endif

    cls->defineFunction("onEnter", _SE(Node_onEnter));
    cls->defineFunction("onExit", _SE(Node_onExit));
    cls->defineFunction("onEnterTransitionDidFinish", _SE(Node_onEnterTransitionDidFinish));
    cls->defineFunction("onExitTransitionDidStart", _SE(Node_onExitTransitionDidStart));
    cls->defineFunction("cleanup", _SE(Node_cleanup));
    cls->defineFunction("schedule", _SE(Node_schedule));
    cls->defineFunction("unschedule", _SE(Node_unschedule));
    cls->defineFunction("setContentSize", _SE(Node_setContentSize));
    cls->defineFunction("setAnchorPoint", _SE(Node_setAnchorPoint));

#if STANDALONE_TEST
    cls->defineFunction("addChild", _SE(Node_addChild));
    cls->defineFunction("getChildren", _SE(Node_getChildren));
    cls->defineFinalizedFunction(_SE(Node_finalized));

    cls->install();

    __jsb_Node_proto = cls->getProto();
    __jsb_Node_class = cls;

    __jsb_Node_proto->defineFunction("foo", _SE(Node_foo));
    __jsb_Node_proto->setProperty("var1", se::Value("I'm var1"));
    __jsb_Node_proto->setProperty("var2", se::Value(10000.323));
#endif

    return true;
}
