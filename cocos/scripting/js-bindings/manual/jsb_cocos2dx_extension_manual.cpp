//
//  jsb_cocos2dx_extension_manual.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 6/7/17.
//
//

#include "jsb_cocos2dx_extension_manual.hpp"
#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "cocos/scripting/js-bindings/manual/jsb_conversions.hpp"
#include "cocos/scripting/js-bindings/manual/jsb_global.h"
#include "cocos/scripting/js-bindings/auto/jsb_cocos2dx_extension_auto.hpp"

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

static bool jsb_cocos2d_extension_empty_func(se::State& s)
{
    return true;
}
SE_BIND_FUNC(jsb_cocos2d_extension_empty_func)

class JSB_ControlCallbackWrapper : public Ref
{
public:
    JSB_ControlCallbackWrapper(Control* control, const se::Value& target, const se::Value& func, Control::EventType eventType)
    : _target(target)
    , _func(func)
    , _eventType(eventType)
    {
        assert(_target.isObject());
        assert(_func.isObject());
        __controlCallbackWrapperArray.push_back(this);
        control->setCleanupCallback([this](){
            JSB_ControlCallbackWrapper::removeWrapper(this);
        });
        CCLOG("After construction, JSB_ControlCallbackWrapper count: %d", (int)__controlCallbackWrapperArray.size());
    }

    virtual ~JSB_ControlCallbackWrapper()
    {
        removeWrapper(this);
        CCLOG("After destruction, JSB_ControlCallbackWrapper count: %d", (int)__controlCallbackWrapperArray.size());
    }

    void onEvent(Ref* control, Control::EventType eventType)
    {
        se::ScriptEngine::getInstance()->clearException();
        se::AutoHandleScope hs;

        assert(_target.isObject());
        assert(_func.isObject() && _func.toObject()->isFunction());

        se::ValueArray args;
        args.reserve(2);
        se::Value arg1;
        native_ptr_to_seval<Ref>(control, &arg1);
        args.push_back(arg1);

        se::Value arg2;
        int32_to_seval((int32_t)eventType, &arg2);
        args.push_back(arg2);
        _func.toObject()->call(args, _target.toObject());
    }

    static JSB_ControlCallbackWrapper* findWrapper(const se::Value& target, const se::Value& func, Control::EventType eventType)
    {
        assert(target.isObject());
        assert(func.isObject());
        for (auto wrapper : __controlCallbackWrapperArray)
        {
            if (wrapper->_target.toObject()->isSame(target.toObject())
                && wrapper->_func.toObject()->isSame(func.toObject())
                && wrapper->_eventType == eventType)
            {
                return wrapper;
            }
        }

        return nullptr;
    }

    static void removeWrapper(JSB_ControlCallbackWrapper* wrapper)
    {
        if (wrapper == nullptr)
            return;
        auto iter = std::find(__controlCallbackWrapperArray.begin(), __controlCallbackWrapperArray.end(), wrapper);
        if (iter != __controlCallbackWrapperArray.end())
        {
            __controlCallbackWrapperArray.erase(iter);
        }
    }

private:
    se::Value _target;
    se::Value _func;
    Control::EventType _eventType;

    static std::vector<JSB_ControlCallbackWrapper*> __controlCallbackWrapperArray;
};

std::vector<JSB_ControlCallbackWrapper*> JSB_ControlCallbackWrapper::__controlCallbackWrapperArray;

static bool js_cocos2dx_CCControl_addTargetWithActionForControlEvents(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 3)
    {
        se::Value target = args[0];
        se::Value func = args[1];
        int32_t eventType = 0;
        bool ok = false;
        ok = seval_to_int32(args[2], &eventType);
        JSB_PRECONDITION2(ok, false, "%s, Converting 'eventType' failed!", __FUNCTION__);
        Control* cobj = (Control*)s.nativeThisObject();
        JSB_ControlCallbackWrapper* wrapper = JSB_ControlCallbackWrapper::findWrapper(target, func, (Control::EventType)eventType);

        if (wrapper == nullptr)
        {
            s.thisObject()->attachChild(target.toObject());
            s.thisObject()->attachChild(func.toObject());
            wrapper = new JSB_ControlCallbackWrapper(cobj, target, func, (Control::EventType)eventType);
            wrapper->autorelease();
            cobj->setUserObject(wrapper);
            cobj->addTargetWithActionForControlEvents(wrapper, cccontrol_selector(JSB_ControlCallbackWrapper::onEvent), (Control::EventType)eventType);
        }
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_CCControl_addTargetWithActionForControlEvents)

static bool js_cocos2dx_CCControl_removeTargetWithActionForControlEvents(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 3)
    {
        se::Value target = args[0];
        se::Value func = args[1];
        int32_t eventType = 0;
        bool ok = false;
        ok = seval_to_int32(args[2], &eventType);
        JSB_PRECONDITION2(ok, false, "%s, Converting 'eventType' failed!", __FUNCTION__);
        Control* cobj = (Control*)s.nativeThisObject();
        JSB_ControlCallbackWrapper* wrapper = JSB_ControlCallbackWrapper::findWrapper(target, func, (Control::EventType)eventType);
        if (wrapper != nullptr)
        {
            cobj->removeTargetWithActionForControlEvents(wrapper, cccontrol_selector(JSB_ControlCallbackWrapper::onEvent), (Control::EventType)eventType);
        }

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_CCControl_removeTargetWithActionForControlEvents)

bool register_all_cocos2dx_extension_manual(se::Object* obj)
{

    // empty 'retain' 'release' implementation
    se::Object* protosNeedEmptyRetainRelease[] = {
        __jsb_cocos2d_extension_AssetsManagerEx_proto,
        __jsb_cocos2d_extension_Manifest_proto
    };

    for (const auto& e : protosNeedEmptyRetainRelease)
    {
        e->defineFunction("retain", _SE(jsb_cocos2d_extension_empty_func));
        e->defineFunction("release", _SE(jsb_cocos2d_extension_empty_func));
    }

    __jsb_cocos2d_extension_Control_proto->defineFunction("addTargetWithActionForControlEvents", _SE(js_cocos2dx_CCControl_addTargetWithActionForControlEvents));
    __jsb_cocos2d_extension_Control_proto->defineFunction("removeTargetWithActionForControlEvents", _SE(js_cocos2dx_CCControl_removeTargetWithActionForControlEvents));

    return true;
}
