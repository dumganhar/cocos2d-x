#include "scripting/js-bindings/auto/jsb_cocos2dx_studio_auto.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "editor-support/cocostudio/CocoStudio.h"
#include "editor-support/cocostudio/CCComExtensionData.h"

se::Object* __jsb_cocostudio_ActionObject_proto = nullptr;
se::Class* __jsb_cocostudio_ActionObject_class = nullptr;

static bool js_cocos2dx_studio_ActionObject_setCurrentTime(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_setCurrentTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_setCurrentTime : Error processing arguments");
        cobj->setCurrentTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_setCurrentTime)

static bool js_cocos2dx_studio_ActionObject_pause(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_pause : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->pause();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_pause)

static bool js_cocos2dx_studio_ActionObject_setName(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_setName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_setName : Error processing arguments");
        cobj->setName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_setName)

static bool js_cocos2dx_studio_ActionObject_setUnitTime(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_setUnitTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_setUnitTime : Error processing arguments");
        cobj->setUnitTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_setUnitTime)

static bool js_cocos2dx_studio_ActionObject_getTotalTime(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_getTotalTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTotalTime();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_getTotalTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_getTotalTime)

static bool js_cocos2dx_studio_ActionObject_getName(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const char* result = cobj->getName();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_getName)

static bool js_cocos2dx_studio_ActionObject_stop(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_stop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stop();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_stop)

static bool js_cocos2dx_studio_ActionObject_play(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_ActionObject_play : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            cocos2d::CallFunc* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->play(arg0);
            return true;
        }
    } while(false);

    do {
        if (argc == 0) {
            cobj->play();
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_play)

static bool js_cocos2dx_studio_ActionObject_getCurrentTime(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_getCurrentTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getCurrentTime();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_getCurrentTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_getCurrentTime)

static bool js_cocos2dx_studio_ActionObject_removeActionNode(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_removeActionNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::ActionNode* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_removeActionNode : Error processing arguments");
        cobj->removeActionNode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_removeActionNode)

static bool js_cocos2dx_studio_ActionObject_getLoop(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_getLoop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getLoop();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_getLoop : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_getLoop)

static bool js_cocos2dx_studio_ActionObject_initWithBinary(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_initWithBinary : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        cocostudio::CocoLoader* arg0 = nullptr;
        cocostudio::stExpCocoNode* arg1 = nullptr;
        cocos2d::Ref* arg2 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        #pragma warning NO CONVERSION TO NATIVE FOR stExpCocoNode*
        ok = false;
        ok &= seval_to_native_ptr(args[2], &arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_initWithBinary : Error processing arguments");
        cobj->initWithBinary(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_initWithBinary)

static bool js_cocos2dx_studio_ActionObject_addActionNode(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_addActionNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::ActionNode* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_addActionNode : Error processing arguments");
        cobj->addActionNode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_addActionNode)

static bool js_cocos2dx_studio_ActionObject_getUnitTime(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_getUnitTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getUnitTime();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_getUnitTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_getUnitTime)

static bool js_cocos2dx_studio_ActionObject_isPlaying(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_isPlaying : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isPlaying();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_isPlaying : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_isPlaying)

static bool js_cocos2dx_studio_ActionObject_updateToFrameByTime(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_updateToFrameByTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_updateToFrameByTime : Error processing arguments");
        cobj->updateToFrameByTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_updateToFrameByTime)

static bool js_cocos2dx_studio_ActionObject_setLoop(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_setLoop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_setLoop : Error processing arguments");
        cobj->setLoop(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_setLoop)

static bool js_cocos2dx_studio_ActionObject_simulationActionUpdate(se::State& s)
{
    cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionObject_simulationActionUpdate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionObject_simulationActionUpdate : Error processing arguments");
        cobj->simulationActionUpdate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionObject_simulationActionUpdate)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_ActionObject_finalize)

static bool js_cocos2dx_studio_ActionObject_constructor(se::State& s)
{
    cocostudio::ActionObject* cobj = new (std::nothrow) cocostudio::ActionObject();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ActionObject_constructor, __jsb_cocostudio_ActionObject_class, js_cocostudio_ActionObject_finalize)




bool js_cocostudio_ActionObject_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::ActionObject)", s.nativeThisObject());
        cocostudio::ActionObject* cobj = (cocostudio::ActionObject*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_ActionObject_finalize)

bool js_register_cocos2dx_studio_ActionObject(se::Object* obj)
{
    auto cls = se::Class::create("ActionObject", obj, nullptr, _SE(js_cocos2dx_studio_ActionObject_constructor));

    cls->defineFunction("setCurrentTime", _SE(js_cocos2dx_studio_ActionObject_setCurrentTime));
    cls->defineFunction("pause", _SE(js_cocos2dx_studio_ActionObject_pause));
    cls->defineFunction("setName", _SE(js_cocos2dx_studio_ActionObject_setName));
    cls->defineFunction("setUnitTime", _SE(js_cocos2dx_studio_ActionObject_setUnitTime));
    cls->defineFunction("getTotalTime", _SE(js_cocos2dx_studio_ActionObject_getTotalTime));
    cls->defineFunction("getName", _SE(js_cocos2dx_studio_ActionObject_getName));
    cls->defineFunction("stop", _SE(js_cocos2dx_studio_ActionObject_stop));
    cls->defineFunction("play", _SE(js_cocos2dx_studio_ActionObject_play));
    cls->defineFunction("getCurrentTime", _SE(js_cocos2dx_studio_ActionObject_getCurrentTime));
    cls->defineFunction("removeActionNode", _SE(js_cocos2dx_studio_ActionObject_removeActionNode));
    cls->defineFunction("getLoop", _SE(js_cocos2dx_studio_ActionObject_getLoop));
    cls->defineFunction("initWithBinary", _SE(js_cocos2dx_studio_ActionObject_initWithBinary));
    cls->defineFunction("addActionNode", _SE(js_cocos2dx_studio_ActionObject_addActionNode));
    cls->defineFunction("getUnitTime", _SE(js_cocos2dx_studio_ActionObject_getUnitTime));
    cls->defineFunction("isPlaying", _SE(js_cocos2dx_studio_ActionObject_isPlaying));
    cls->defineFunction("updateToFrameByTime", _SE(js_cocos2dx_studio_ActionObject_updateToFrameByTime));
    cls->defineFunction("setLoop", _SE(js_cocos2dx_studio_ActionObject_setLoop));
    cls->defineFunction("simulationActionUpdate", _SE(js_cocos2dx_studio_ActionObject_simulationActionUpdate));
    cls->defineFinalizedFunction(_SE(js_cocostudio_ActionObject_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::ActionObject>(cls);

    __jsb_cocostudio_ActionObject_proto = cls->getProto();
    __jsb_cocostudio_ActionObject_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_ActionManagerEx_proto = nullptr;
se::Class* __jsb_cocostudio_ActionManagerEx_class = nullptr;

static bool js_cocos2dx_studio_ActionManagerEx_stopActionByName(se::State& s)
{
    cocostudio::ActionManagerEx* cobj = (cocostudio::ActionManagerEx*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionManagerEx_stopActionByName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        const char* arg1 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionManagerEx_stopActionByName : Error processing arguments");
        cocostudio::ActionObject* result = cobj->stopActionByName(arg0, arg1);
        ok &= native_ptr_to_seval<cocostudio::ActionObject>((cocostudio::ActionObject*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionManagerEx_stopActionByName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionManagerEx_stopActionByName)

static bool js_cocos2dx_studio_ActionManagerEx_getActionByName(se::State& s)
{
    cocostudio::ActionManagerEx* cobj = (cocostudio::ActionManagerEx*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionManagerEx_getActionByName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        const char* arg1 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionManagerEx_getActionByName : Error processing arguments");
        cocostudio::ActionObject* result = cobj->getActionByName(arg0, arg1);
        ok &= native_ptr_to_seval<cocostudio::ActionObject>((cocostudio::ActionObject*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionManagerEx_getActionByName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionManagerEx_getActionByName)

static bool js_cocos2dx_studio_ActionManagerEx_getStudioVersionNumber(se::State& s)
{
    cocostudio::ActionManagerEx* cobj = (cocostudio::ActionManagerEx*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionManagerEx_getStudioVersionNumber : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getStudioVersionNumber();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionManagerEx_getStudioVersionNumber : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionManagerEx_getStudioVersionNumber)

static bool js_cocos2dx_studio_ActionManagerEx_initWithBinary(se::State& s)
{
    cocostudio::ActionManagerEx* cobj = (cocostudio::ActionManagerEx*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionManagerEx_initWithBinary : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        const char* arg0 = nullptr;
        cocos2d::Ref* arg1 = nullptr;
        cocostudio::CocoLoader* arg2 = nullptr;
        cocostudio::stExpCocoNode* arg3 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_native_ptr(args[1], &arg1);
        ok &= seval_to_native_ptr(args[2], &arg2);
        #pragma warning NO CONVERSION TO NATIVE FOR stExpCocoNode*
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionManagerEx_initWithBinary : Error processing arguments");
        cobj->initWithBinary(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionManagerEx_initWithBinary)

static bool js_cocos2dx_studio_ActionManagerEx_playActionByName(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::ActionManagerEx* cobj = (cocostudio::ActionManagerEx*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_ActionManagerEx_playActionByName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 3) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg1 = nullptr;
            std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { ok = true; break; }
            cocos2d::CallFunc* arg2 = nullptr;
            ok &= seval_to_native_ptr(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocostudio::ActionObject* result = cobj->playActionByName(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<cocostudio::ActionObject>((cocostudio::ActionObject*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionManagerEx_playActionByName : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg1 = nullptr;
            std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { ok = true; break; }
            cocostudio::ActionObject* result = cobj->playActionByName(arg0, arg1);
            ok &= native_ptr_to_seval<cocostudio::ActionObject>((cocostudio::ActionObject*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionManagerEx_playActionByName : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionManagerEx_playActionByName)

static bool js_cocos2dx_studio_ActionManagerEx_releaseActions(se::State& s)
{
    cocostudio::ActionManagerEx* cobj = (cocostudio::ActionManagerEx*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionManagerEx_releaseActions : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->releaseActions();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionManagerEx_releaseActions)

static bool js_cocos2dx_studio_ActionManagerEx_destroyInstance(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cocostudio::ActionManagerEx::destroyInstance();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionManagerEx_destroyInstance)

static bool js_cocos2dx_studio_ActionManagerEx_getInstance(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::ActionManagerEx::getInstance();
        se::Object* obj = nullptr;
        if (result->_scriptObject == nullptr)
        {
            obj = se::Object::createObjectWithClass(__jsb_cocostudio_ActionManagerEx_class, true);
            obj->setPrivateData(result);
            result->_scriptObject = obj;
        }
        else
        {
            obj = se::Object::getObjectWithPtr(result);
        }
        assert(obj);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionManagerEx_getInstance)




bool js_register_cocos2dx_studio_ActionManagerEx(se::Object* obj)
{
    auto cls = se::Class::create("ActionManager", obj, nullptr, nullptr);

    cls->defineFunction("stopActionByName", _SE(js_cocos2dx_studio_ActionManagerEx_stopActionByName));
    cls->defineFunction("getActionByName", _SE(js_cocos2dx_studio_ActionManagerEx_getActionByName));
    cls->defineFunction("getStudioVersionNumber", _SE(js_cocos2dx_studio_ActionManagerEx_getStudioVersionNumber));
    cls->defineFunction("initWithBinary", _SE(js_cocos2dx_studio_ActionManagerEx_initWithBinary));
    cls->defineFunction("playActionByName", _SE(js_cocos2dx_studio_ActionManagerEx_playActionByName));
    cls->defineFunction("releaseActions", _SE(js_cocos2dx_studio_ActionManagerEx_releaseActions));
    cls->defineStaticFunction("destroyInstance", _SE(js_cocos2dx_studio_ActionManagerEx_destroyInstance));
    cls->defineStaticFunction("getInstance", _SE(js_cocos2dx_studio_ActionManagerEx_getInstance));
    cls->install();
    JSBClassType::registerClass<cocostudio::ActionManagerEx>(cls);

    __jsb_cocostudio_ActionManagerEx_proto = cls->getProto();
    __jsb_cocostudio_ActionManagerEx_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_BaseData_proto = nullptr;
se::Class* __jsb_cocostudio_BaseData_class = nullptr;

static bool js_cocos2dx_studio_BaseData_getColor(se::State& s)
{
    cocostudio::BaseData* cobj = (cocostudio::BaseData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BaseData_getColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Color4B result = cobj->getColor();
        ok &= Color4B_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BaseData_getColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BaseData_getColor)

static bool js_cocos2dx_studio_BaseData_setColor(se::State& s)
{
    cocostudio::BaseData* cobj = (cocostudio::BaseData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BaseData_setColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Color4B arg0;
        ok &= seval_to_Color4B(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BaseData_setColor : Error processing arguments");
        cobj->setColor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BaseData_setColor)

static bool js_cocos2dx_studio_BaseData_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::BaseData::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_BaseData_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BaseData_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_BaseData_finalize)

static bool js_cocos2dx_studio_BaseData_constructor(se::State& s)
{
    cocostudio::BaseData* cobj = new (std::nothrow) cocostudio::BaseData();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_BaseData_constructor, __jsb_cocostudio_BaseData_class, js_cocostudio_BaseData_finalize)




bool js_cocostudio_BaseData_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::BaseData)", s.nativeThisObject());
        cocostudio::BaseData* cobj = (cocostudio::BaseData*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_BaseData_finalize)

bool js_register_cocos2dx_studio_BaseData(se::Object* obj)
{
    auto cls = se::Class::create("BaseData", obj, nullptr, _SE(js_cocos2dx_studio_BaseData_constructor));

    cls->defineFunction("getColor", _SE(js_cocos2dx_studio_BaseData_getColor));
    cls->defineFunction("setColor", _SE(js_cocos2dx_studio_BaseData_setColor));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_BaseData_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_BaseData_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::BaseData>(cls);

    __jsb_cocostudio_BaseData_proto = cls->getProto();
    __jsb_cocostudio_BaseData_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_MovementData_proto = nullptr;
se::Class* __jsb_cocostudio_MovementData_class = nullptr;

static bool js_cocos2dx_studio_MovementData_getMovementBoneData(se::State& s)
{
    cocostudio::MovementData* cobj = (cocostudio::MovementData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_MovementData_getMovementBoneData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_MovementData_getMovementBoneData : Error processing arguments");
        cocostudio::MovementBoneData* result = cobj->getMovementBoneData(arg0);
        ok &= native_ptr_to_seval<cocostudio::MovementBoneData>((cocostudio::MovementBoneData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_MovementData_getMovementBoneData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_MovementData_getMovementBoneData)

static bool js_cocos2dx_studio_MovementData_addMovementBoneData(se::State& s)
{
    cocostudio::MovementData* cobj = (cocostudio::MovementData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_MovementData_addMovementBoneData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::MovementBoneData* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_MovementData_addMovementBoneData : Error processing arguments");
        cobj->addMovementBoneData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_MovementData_addMovementBoneData)

static bool js_cocos2dx_studio_MovementData_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::MovementData::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_MovementData_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_MovementData_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_MovementData_finalize)

static bool js_cocos2dx_studio_MovementData_constructor(se::State& s)
{
    cocostudio::MovementData* cobj = new (std::nothrow) cocostudio::MovementData();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_MovementData_constructor, __jsb_cocostudio_MovementData_class, js_cocostudio_MovementData_finalize)




bool js_cocostudio_MovementData_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::MovementData)", s.nativeThisObject());
        cocostudio::MovementData* cobj = (cocostudio::MovementData*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_MovementData_finalize)

bool js_register_cocos2dx_studio_MovementData(se::Object* obj)
{
    auto cls = se::Class::create("MovementData", obj, nullptr, _SE(js_cocos2dx_studio_MovementData_constructor));

    cls->defineFunction("getMovementBoneData", _SE(js_cocos2dx_studio_MovementData_getMovementBoneData));
    cls->defineFunction("addMovementBoneData", _SE(js_cocos2dx_studio_MovementData_addMovementBoneData));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_MovementData_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_MovementData_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::MovementData>(cls);

    __jsb_cocostudio_MovementData_proto = cls->getProto();
    __jsb_cocostudio_MovementData_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_AnimationData_proto = nullptr;
se::Class* __jsb_cocostudio_AnimationData_class = nullptr;

static bool js_cocos2dx_studio_AnimationData_getMovement(se::State& s)
{
    cocostudio::AnimationData* cobj = (cocostudio::AnimationData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_AnimationData_getMovement : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_AnimationData_getMovement : Error processing arguments");
        cocostudio::MovementData* result = cobj->getMovement(arg0);
        ok &= native_ptr_to_seval<cocostudio::MovementData>((cocostudio::MovementData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_AnimationData_getMovement : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_AnimationData_getMovement)

static bool js_cocos2dx_studio_AnimationData_getMovementCount(se::State& s)
{
    cocostudio::AnimationData* cobj = (cocostudio::AnimationData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_AnimationData_getMovementCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        ssize_t result = cobj->getMovementCount();
        ok &= ssize_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_AnimationData_getMovementCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_AnimationData_getMovementCount)

static bool js_cocos2dx_studio_AnimationData_addMovement(se::State& s)
{
    cocostudio::AnimationData* cobj = (cocostudio::AnimationData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_AnimationData_addMovement : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::MovementData* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_AnimationData_addMovement : Error processing arguments");
        cobj->addMovement(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_AnimationData_addMovement)

static bool js_cocos2dx_studio_AnimationData_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::AnimationData::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_AnimationData_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_AnimationData_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_AnimationData_finalize)

static bool js_cocos2dx_studio_AnimationData_constructor(se::State& s)
{
    cocostudio::AnimationData* cobj = new (std::nothrow) cocostudio::AnimationData();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_AnimationData_constructor, __jsb_cocostudio_AnimationData_class, js_cocostudio_AnimationData_finalize)




bool js_cocostudio_AnimationData_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::AnimationData)", s.nativeThisObject());
        cocostudio::AnimationData* cobj = (cocostudio::AnimationData*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_AnimationData_finalize)

bool js_register_cocos2dx_studio_AnimationData(se::Object* obj)
{
    auto cls = se::Class::create("AnimationData", obj, nullptr, _SE(js_cocos2dx_studio_AnimationData_constructor));

    cls->defineFunction("getMovement", _SE(js_cocos2dx_studio_AnimationData_getMovement));
    cls->defineFunction("getMovementCount", _SE(js_cocos2dx_studio_AnimationData_getMovementCount));
    cls->defineFunction("addMovement", _SE(js_cocos2dx_studio_AnimationData_addMovement));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_AnimationData_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_AnimationData_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::AnimationData>(cls);

    __jsb_cocostudio_AnimationData_proto = cls->getProto();
    __jsb_cocostudio_AnimationData_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_ContourData_proto = nullptr;
se::Class* __jsb_cocostudio_ContourData_class = nullptr;

static bool js_cocos2dx_studio_ContourData_init(se::State& s)
{
    cocostudio::ContourData* cobj = (cocostudio::ContourData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ContourData_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->init();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ContourData_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ContourData_init)

static bool js_cocos2dx_studio_ContourData_addVertex(se::State& s)
{
    cocostudio::ContourData* cobj = (cocostudio::ContourData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ContourData_addVertex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec2 arg0;
        ok &= seval_to_Vec2(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ContourData_addVertex : Error processing arguments");
        cobj->addVertex(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ContourData_addVertex)

static bool js_cocos2dx_studio_ContourData_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::ContourData::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_ContourData_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ContourData_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_ContourData_finalize)

static bool js_cocos2dx_studio_ContourData_constructor(se::State& s)
{
    cocostudio::ContourData* cobj = new (std::nothrow) cocostudio::ContourData();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ContourData_constructor, __jsb_cocostudio_ContourData_class, js_cocostudio_ContourData_finalize)




bool js_cocostudio_ContourData_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::ContourData)", s.nativeThisObject());
        cocostudio::ContourData* cobj = (cocostudio::ContourData*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_ContourData_finalize)

bool js_register_cocos2dx_studio_ContourData(se::Object* obj)
{
    auto cls = se::Class::create("ContourData", obj, nullptr, _SE(js_cocos2dx_studio_ContourData_constructor));

    cls->defineFunction("init", _SE(js_cocos2dx_studio_ContourData_init));
    cls->defineFunction("addVertex", _SE(js_cocos2dx_studio_ContourData_addVertex));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ContourData_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_ContourData_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::ContourData>(cls);

    __jsb_cocostudio_ContourData_proto = cls->getProto();
    __jsb_cocostudio_ContourData_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_TextureData_proto = nullptr;
se::Class* __jsb_cocostudio_TextureData_class = nullptr;

static bool js_cocos2dx_studio_TextureData_getContourData(se::State& s)
{
    cocostudio::TextureData* cobj = (cocostudio::TextureData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_TextureData_getContourData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_TextureData_getContourData : Error processing arguments");
        cocostudio::ContourData* result = cobj->getContourData(arg0);
        ok &= native_ptr_to_seval<cocostudio::ContourData>((cocostudio::ContourData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_TextureData_getContourData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_TextureData_getContourData)

static bool js_cocos2dx_studio_TextureData_init(se::State& s)
{
    cocostudio::TextureData* cobj = (cocostudio::TextureData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_TextureData_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->init();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_TextureData_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_TextureData_init)

static bool js_cocos2dx_studio_TextureData_addContourData(se::State& s)
{
    cocostudio::TextureData* cobj = (cocostudio::TextureData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_TextureData_addContourData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::ContourData* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_TextureData_addContourData : Error processing arguments");
        cobj->addContourData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_TextureData_addContourData)

static bool js_cocos2dx_studio_TextureData_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::TextureData::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_TextureData_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_TextureData_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_TextureData_finalize)

static bool js_cocos2dx_studio_TextureData_constructor(se::State& s)
{
    cocostudio::TextureData* cobj = new (std::nothrow) cocostudio::TextureData();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_TextureData_constructor, __jsb_cocostudio_TextureData_class, js_cocostudio_TextureData_finalize)




bool js_cocostudio_TextureData_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::TextureData)", s.nativeThisObject());
        cocostudio::TextureData* cobj = (cocostudio::TextureData*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_TextureData_finalize)

bool js_register_cocos2dx_studio_TextureData(se::Object* obj)
{
    auto cls = se::Class::create("TextureData", obj, nullptr, _SE(js_cocos2dx_studio_TextureData_constructor));

    cls->defineFunction("getContourData", _SE(js_cocos2dx_studio_TextureData_getContourData));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_TextureData_init));
    cls->defineFunction("addContourData", _SE(js_cocos2dx_studio_TextureData_addContourData));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_TextureData_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_TextureData_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::TextureData>(cls);

    __jsb_cocostudio_TextureData_proto = cls->getProto();
    __jsb_cocostudio_TextureData_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_ProcessBase_proto = nullptr;
se::Class* __jsb_cocostudio_ProcessBase_class = nullptr;

static bool js_cocos2dx_studio_ProcessBase_play(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_play : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        int arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        ok &= seval_to_int32(args[2], (int32_t *)&arg2);
        ok &= seval_to_int32(args[3], (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_play : Error processing arguments");
        cobj->play(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_play)

static bool js_cocos2dx_studio_ProcessBase_pause(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_pause : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->pause();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_pause)

static bool js_cocos2dx_studio_ProcessBase_getRawDuration(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_getRawDuration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getRawDuration();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_getRawDuration : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_getRawDuration)

static bool js_cocos2dx_studio_ProcessBase_resume(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_resume : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->resume();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_resume)

static bool js_cocos2dx_studio_ProcessBase_setIsComplete(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_setIsComplete : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_setIsComplete : Error processing arguments");
        cobj->setIsComplete(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_setIsComplete)

static bool js_cocos2dx_studio_ProcessBase_stop(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_stop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stop();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_stop)

static bool js_cocos2dx_studio_ProcessBase_update(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_update : Error processing arguments");
        cobj->update(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_update)

static bool js_cocos2dx_studio_ProcessBase_getCurrentFrameIndex(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_getCurrentFrameIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getCurrentFrameIndex();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_getCurrentFrameIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_getCurrentFrameIndex)

static bool js_cocos2dx_studio_ProcessBase_isComplete(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_isComplete : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isComplete();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_isComplete : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_isComplete)

static bool js_cocos2dx_studio_ProcessBase_getCurrentPercent(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_getCurrentPercent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getCurrentPercent();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_getCurrentPercent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_getCurrentPercent)

static bool js_cocos2dx_studio_ProcessBase_setIsPause(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_setIsPause : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_setIsPause : Error processing arguments");
        cobj->setIsPause(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_setIsPause)

static bool js_cocos2dx_studio_ProcessBase_getProcessScale(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_getProcessScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getProcessScale();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_getProcessScale : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_getProcessScale)

static bool js_cocos2dx_studio_ProcessBase_isPause(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_isPause : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isPause();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_isPause : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_isPause)

static bool js_cocos2dx_studio_ProcessBase_isPlaying(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_isPlaying : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isPlaying();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_isPlaying : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_isPlaying)

static bool js_cocos2dx_studio_ProcessBase_setProcessScale(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_setProcessScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_setProcessScale : Error processing arguments");
        cobj->setProcessScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_setProcessScale)

static bool js_cocos2dx_studio_ProcessBase_setIsPlaying(se::State& s)
{
    cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ProcessBase_setIsPlaying : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ProcessBase_setIsPlaying : Error processing arguments");
        cobj->setIsPlaying(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ProcessBase_setIsPlaying)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_ProcessBase_finalize)

static bool js_cocos2dx_studio_ProcessBase_constructor(se::State& s)
{
    cocostudio::ProcessBase* cobj = new (std::nothrow) cocostudio::ProcessBase();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ProcessBase_constructor, __jsb_cocostudio_ProcessBase_class, js_cocostudio_ProcessBase_finalize)




bool js_cocostudio_ProcessBase_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::ProcessBase)", s.nativeThisObject());
        cocostudio::ProcessBase* cobj = (cocostudio::ProcessBase*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_ProcessBase_finalize)

bool js_register_cocos2dx_studio_ProcessBase(se::Object* obj)
{
    auto cls = se::Class::create("ProcessBase", obj, nullptr, _SE(js_cocos2dx_studio_ProcessBase_constructor));

    cls->defineFunction("play", _SE(js_cocos2dx_studio_ProcessBase_play));
    cls->defineFunction("pause", _SE(js_cocos2dx_studio_ProcessBase_pause));
    cls->defineFunction("getRawDuration", _SE(js_cocos2dx_studio_ProcessBase_getRawDuration));
    cls->defineFunction("resume", _SE(js_cocos2dx_studio_ProcessBase_resume));
    cls->defineFunction("setIsComplete", _SE(js_cocos2dx_studio_ProcessBase_setIsComplete));
    cls->defineFunction("stop", _SE(js_cocos2dx_studio_ProcessBase_stop));
    cls->defineFunction("update", _SE(js_cocos2dx_studio_ProcessBase_update));
    cls->defineFunction("getCurrentFrameIndex", _SE(js_cocos2dx_studio_ProcessBase_getCurrentFrameIndex));
    cls->defineFunction("isComplete", _SE(js_cocos2dx_studio_ProcessBase_isComplete));
    cls->defineFunction("getCurrentPercent", _SE(js_cocos2dx_studio_ProcessBase_getCurrentPercent));
    cls->defineFunction("setIsPause", _SE(js_cocos2dx_studio_ProcessBase_setIsPause));
    cls->defineFunction("getProcessScale", _SE(js_cocos2dx_studio_ProcessBase_getProcessScale));
    cls->defineFunction("isPause", _SE(js_cocos2dx_studio_ProcessBase_isPause));
    cls->defineFunction("isPlaying", _SE(js_cocos2dx_studio_ProcessBase_isPlaying));
    cls->defineFunction("setProcessScale", _SE(js_cocos2dx_studio_ProcessBase_setProcessScale));
    cls->defineFunction("setIsPlaying", _SE(js_cocos2dx_studio_ProcessBase_setIsPlaying));
    cls->defineFinalizedFunction(_SE(js_cocostudio_ProcessBase_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::ProcessBase>(cls);

    __jsb_cocostudio_ProcessBase_proto = cls->getProto();
    __jsb_cocostudio_ProcessBase_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_Tween_proto = nullptr;
se::Class* __jsb_cocostudio_Tween_class = nullptr;

static bool js_cocos2dx_studio_Tween_getAnimation(se::State& s)
{
    cocostudio::Tween* cobj = (cocostudio::Tween*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Tween_getAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::ArmatureAnimation* result = cobj->getAnimation();
        ok &= native_ptr_to_seval<cocostudio::ArmatureAnimation>((cocostudio::ArmatureAnimation*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Tween_getAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Tween_getAnimation)

static bool js_cocos2dx_studio_Tween_gotoAndPause(se::State& s)
{
    cocostudio::Tween* cobj = (cocostudio::Tween*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Tween_gotoAndPause : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Tween_gotoAndPause : Error processing arguments");
        cobj->gotoAndPause(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Tween_gotoAndPause)

static bool js_cocos2dx_studio_Tween_play(se::State& s)
{
    cocostudio::Tween* cobj = (cocostudio::Tween*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Tween_play : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        cocostudio::MovementBoneData* arg0 = nullptr;
        int arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        int arg4 = 0;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        ok &= seval_to_int32(args[2], (int32_t *)&arg2);
        ok &= seval_to_int32(args[3], (int32_t *)&arg3);
        ok &= seval_to_int32(args[4], (int32_t *)&arg4);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Tween_play : Error processing arguments");
        cobj->play(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Tween_play)

static bool js_cocos2dx_studio_Tween_gotoAndPlay(se::State& s)
{
    cocostudio::Tween* cobj = (cocostudio::Tween*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Tween_gotoAndPlay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Tween_gotoAndPlay : Error processing arguments");
        cobj->gotoAndPlay(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Tween_gotoAndPlay)

static bool js_cocos2dx_studio_Tween_init(se::State& s)
{
    cocostudio::Tween* cobj = (cocostudio::Tween*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Tween_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Tween_init : Error processing arguments");
        bool result = cobj->init(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Tween_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Tween_init)

static bool js_cocos2dx_studio_Tween_setAnimation(se::State& s)
{
    cocostudio::Tween* cobj = (cocostudio::Tween*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Tween_setAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::ArmatureAnimation* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Tween_setAnimation : Error processing arguments");
        cobj->setAnimation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Tween_setAnimation)

static bool js_cocos2dx_studio_Tween_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Tween_create : Error processing arguments");
        auto result = cocostudio::Tween::create(arg0);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_Tween_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Tween_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_Tween_finalize)

static bool js_cocos2dx_studio_Tween_constructor(se::State& s)
{
    cocostudio::Tween* cobj = new (std::nothrow) cocostudio::Tween();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_Tween_constructor, __jsb_cocostudio_Tween_class, js_cocostudio_Tween_finalize)



extern se::Object* __jsb_cocostudio_ProcessBase_proto;

bool js_cocostudio_Tween_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::Tween)", s.nativeThisObject());
        cocostudio::Tween* cobj = (cocostudio::Tween*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_Tween_finalize)

bool js_register_cocos2dx_studio_Tween(se::Object* obj)
{
    auto cls = se::Class::create("Tween", obj, __jsb_cocostudio_ProcessBase_proto, _SE(js_cocos2dx_studio_Tween_constructor));

    cls->defineFunction("getAnimation", _SE(js_cocos2dx_studio_Tween_getAnimation));
    cls->defineFunction("gotoAndPause", _SE(js_cocos2dx_studio_Tween_gotoAndPause));
    cls->defineFunction("play", _SE(js_cocos2dx_studio_Tween_play));
    cls->defineFunction("gotoAndPlay", _SE(js_cocos2dx_studio_Tween_gotoAndPlay));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_Tween_init));
    cls->defineFunction("setAnimation", _SE(js_cocos2dx_studio_Tween_setAnimation));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_Tween_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_Tween_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::Tween>(cls);

    __jsb_cocostudio_Tween_proto = cls->getProto();
    __jsb_cocostudio_Tween_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_ColliderFilter_proto = nullptr;
se::Class* __jsb_cocostudio_ColliderFilter_class = nullptr;




bool js_register_cocos2dx_studio_ColliderFilter(se::Object* obj)
{
    auto cls = se::Class::create("ColliderFilter", obj, nullptr, nullptr);

    cls->install();
    JSBClassType::registerClass<cocostudio::ColliderFilter>(cls);

    __jsb_cocostudio_ColliderFilter_proto = cls->getProto();
    __jsb_cocostudio_ColliderFilter_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_ColliderBody_proto = nullptr;
se::Class* __jsb_cocostudio_ColliderBody_class = nullptr;




bool js_register_cocos2dx_studio_ColliderBody(se::Object* obj)
{
    auto cls = se::Class::create("ColliderBody", obj, nullptr, nullptr);

    cls->install();
    JSBClassType::registerClass<cocostudio::ColliderBody>(cls);

    __jsb_cocostudio_ColliderBody_proto = cls->getProto();
    __jsb_cocostudio_ColliderBody_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_ColliderDetector_proto = nullptr;
se::Class* __jsb_cocostudio_ColliderDetector_class = nullptr;

static bool js_cocos2dx_studio_ColliderDetector_getBone(se::State& s)
{
    cocostudio::ColliderDetector* cobj = (cocostudio::ColliderDetector*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ColliderDetector_getBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::Bone* result = cobj->getBone();
        ok &= native_ptr_to_seval<cocostudio::Bone>((cocostudio::Bone*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColliderDetector_getBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColliderDetector_getBone)

static bool js_cocos2dx_studio_ColliderDetector_getActive(se::State& s)
{
    cocostudio::ColliderDetector* cobj = (cocostudio::ColliderDetector*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ColliderDetector_getActive : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getActive();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColliderDetector_getActive : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColliderDetector_getActive)

static bool js_cocos2dx_studio_ColliderDetector_getColliderBodyList(se::State& s)
{
    cocostudio::ColliderDetector* cobj = (cocostudio::ColliderDetector*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ColliderDetector_getColliderBodyList : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::Vector<cocostudio::ColliderBody *>& result = cobj->getColliderBodyList();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColliderDetector_getColliderBodyList : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColliderDetector_getColliderBodyList)

static bool js_cocos2dx_studio_ColliderDetector_updateTransform(se::State& s)
{
    cocostudio::ColliderDetector* cobj = (cocostudio::ColliderDetector*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ColliderDetector_updateTransform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Mat4 arg0;
        ok &= seval_to_Mat4(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColliderDetector_updateTransform : Error processing arguments");
        cobj->updateTransform(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColliderDetector_updateTransform)

static bool js_cocos2dx_studio_ColliderDetector_removeAll(se::State& s)
{
    cocostudio::ColliderDetector* cobj = (cocostudio::ColliderDetector*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ColliderDetector_removeAll : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->removeAll();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColliderDetector_removeAll)

static bool js_cocos2dx_studio_ColliderDetector_init(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::ColliderDetector* cobj = (cocostudio::ColliderDetector*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_ColliderDetector_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            cocostudio::Bone* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool result = cobj->init(arg0);
            ok &= boolean_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColliderDetector_init : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 0) {
            bool result = cobj->init();
            ok &= boolean_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColliderDetector_init : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColliderDetector_init)

static bool js_cocos2dx_studio_ColliderDetector_setActive(se::State& s)
{
    cocostudio::ColliderDetector* cobj = (cocostudio::ColliderDetector*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ColliderDetector_setActive : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColliderDetector_setActive : Error processing arguments");
        cobj->setActive(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColliderDetector_setActive)

static bool js_cocos2dx_studio_ColliderDetector_setBone(se::State& s)
{
    cocostudio::ColliderDetector* cobj = (cocostudio::ColliderDetector*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ColliderDetector_setBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColliderDetector_setBone : Error processing arguments");
        cobj->setBone(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColliderDetector_setBone)

static bool js_cocos2dx_studio_ColliderDetector_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            cocostudio::Bone* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocostudio::ColliderDetector* result = cocostudio::ColliderDetector::create(arg0);
            ok &= native_ptr_to_seval<cocostudio::ColliderDetector>((cocostudio::ColliderDetector*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColliderDetector_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            cocostudio::ColliderDetector* result = cocostudio::ColliderDetector::create();
            ok &= native_ptr_to_seval<cocostudio::ColliderDetector>((cocostudio::ColliderDetector*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColliderDetector_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColliderDetector_create)




bool js_register_cocos2dx_studio_ColliderDetector(se::Object* obj)
{
    auto cls = se::Class::create("ColliderDetector", obj, nullptr, nullptr);

    cls->defineFunction("getBone", _SE(js_cocos2dx_studio_ColliderDetector_getBone));
    cls->defineFunction("getActive", _SE(js_cocos2dx_studio_ColliderDetector_getActive));
    cls->defineFunction("getColliderBodyList", _SE(js_cocos2dx_studio_ColliderDetector_getColliderBodyList));
    cls->defineFunction("updateTransform", _SE(js_cocos2dx_studio_ColliderDetector_updateTransform));
    cls->defineFunction("removeAll", _SE(js_cocos2dx_studio_ColliderDetector_removeAll));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_ColliderDetector_init));
    cls->defineFunction("setActive", _SE(js_cocos2dx_studio_ColliderDetector_setActive));
    cls->defineFunction("setBone", _SE(js_cocos2dx_studio_ColliderDetector_setBone));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ColliderDetector_create));
    cls->install();
    JSBClassType::registerClass<cocostudio::ColliderDetector>(cls);

    __jsb_cocostudio_ColliderDetector_proto = cls->getProto();
    __jsb_cocostudio_ColliderDetector_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_DecorativeDisplay_proto = nullptr;
se::Class* __jsb_cocostudio_DecorativeDisplay_class = nullptr;

static bool js_cocos2dx_studio_DecorativeDisplay_getColliderDetector(se::State& s)
{
    cocostudio::DecorativeDisplay* cobj = (cocostudio::DecorativeDisplay*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DecorativeDisplay_getColliderDetector : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::ColliderDetector* result = cobj->getColliderDetector();
        ok &= native_ptr_to_seval<cocostudio::ColliderDetector>((cocostudio::ColliderDetector*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DecorativeDisplay_getColliderDetector : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DecorativeDisplay_getColliderDetector)

static bool js_cocos2dx_studio_DecorativeDisplay_getDisplay(se::State& s)
{
    cocostudio::DecorativeDisplay* cobj = (cocostudio::DecorativeDisplay*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DecorativeDisplay_getDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Node* result = cobj->getDisplay();
        ok &= native_ptr_to_seval<cocos2d::Node>((cocos2d::Node*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DecorativeDisplay_getDisplay : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DecorativeDisplay_getDisplay)

static bool js_cocos2dx_studio_DecorativeDisplay_setDisplay(se::State& s)
{
    cocostudio::DecorativeDisplay* cobj = (cocostudio::DecorativeDisplay*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DecorativeDisplay_setDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Node* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DecorativeDisplay_setDisplay : Error processing arguments");
        cobj->setDisplay(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DecorativeDisplay_setDisplay)

static bool js_cocos2dx_studio_DecorativeDisplay_init(se::State& s)
{
    cocostudio::DecorativeDisplay* cobj = (cocostudio::DecorativeDisplay*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DecorativeDisplay_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->init();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DecorativeDisplay_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DecorativeDisplay_init)

static bool js_cocos2dx_studio_DecorativeDisplay_setDisplayData(se::State& s)
{
    cocostudio::DecorativeDisplay* cobj = (cocostudio::DecorativeDisplay*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DecorativeDisplay_setDisplayData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::DisplayData* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DecorativeDisplay_setDisplayData : Error processing arguments");
        cobj->setDisplayData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DecorativeDisplay_setDisplayData)

static bool js_cocos2dx_studio_DecorativeDisplay_getDisplayData(se::State& s)
{
    cocostudio::DecorativeDisplay* cobj = (cocostudio::DecorativeDisplay*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DecorativeDisplay_getDisplayData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::DisplayData* result = cobj->getDisplayData();
        ok &= native_ptr_to_seval<cocostudio::DisplayData>((cocostudio::DisplayData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DecorativeDisplay_getDisplayData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DecorativeDisplay_getDisplayData)

static bool js_cocos2dx_studio_DecorativeDisplay_setColliderDetector(se::State& s)
{
    cocostudio::DecorativeDisplay* cobj = (cocostudio::DecorativeDisplay*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DecorativeDisplay_setColliderDetector : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::ColliderDetector* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DecorativeDisplay_setColliderDetector : Error processing arguments");
        cobj->setColliderDetector(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DecorativeDisplay_setColliderDetector)

static bool js_cocos2dx_studio_DecorativeDisplay_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::DecorativeDisplay::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_DecorativeDisplay_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DecorativeDisplay_create)




bool js_register_cocos2dx_studio_DecorativeDisplay(se::Object* obj)
{
    auto cls = se::Class::create("DecorativeDisplay", obj, nullptr, nullptr);

    cls->defineFunction("getColliderDetector", _SE(js_cocos2dx_studio_DecorativeDisplay_getColliderDetector));
    cls->defineFunction("getDisplay", _SE(js_cocos2dx_studio_DecorativeDisplay_getDisplay));
    cls->defineFunction("setDisplay", _SE(js_cocos2dx_studio_DecorativeDisplay_setDisplay));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_DecorativeDisplay_init));
    cls->defineFunction("setDisplayData", _SE(js_cocos2dx_studio_DecorativeDisplay_setDisplayData));
    cls->defineFunction("getDisplayData", _SE(js_cocos2dx_studio_DecorativeDisplay_getDisplayData));
    cls->defineFunction("setColliderDetector", _SE(js_cocos2dx_studio_DecorativeDisplay_setColliderDetector));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_DecorativeDisplay_create));
    cls->install();
    JSBClassType::registerClass<cocostudio::DecorativeDisplay>(cls);

    __jsb_cocostudio_DecorativeDisplay_proto = cls->getProto();
    __jsb_cocostudio_DecorativeDisplay_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_DisplayManager_proto = nullptr;
se::Class* __jsb_cocostudio_DisplayManager_class = nullptr;

static bool js_cocos2dx_studio_DisplayManager_getCurrentDecorativeDisplay(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_getCurrentDecorativeDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::DecorativeDisplay* result = cobj->getCurrentDecorativeDisplay();
        ok &= native_ptr_to_seval<cocostudio::DecorativeDisplay>((cocostudio::DecorativeDisplay*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_getCurrentDecorativeDisplay : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_getCurrentDecorativeDisplay)

static bool js_cocos2dx_studio_DisplayManager_getDisplayRenderNode(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_getDisplayRenderNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Node* result = cobj->getDisplayRenderNode();
        ok &= native_ptr_to_seval<cocos2d::Node>((cocos2d::Node*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_getDisplayRenderNode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_getDisplayRenderNode)

static bool js_cocos2dx_studio_DisplayManager_getAnchorPointInPoints(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_getAnchorPointInPoints : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec2 result = cobj->getAnchorPointInPoints();
        ok &= Vec2_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_getAnchorPointInPoints : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_getAnchorPointInPoints)

static bool js_cocos2dx_studio_DisplayManager_setCurrentDecorativeDisplay(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_setCurrentDecorativeDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::DecorativeDisplay* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_setCurrentDecorativeDisplay : Error processing arguments");
        cobj->setCurrentDecorativeDisplay(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_setCurrentDecorativeDisplay)

static bool js_cocos2dx_studio_DisplayManager_getDisplayRenderNodeType(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_getDisplayRenderNodeType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getDisplayRenderNodeType();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_getDisplayRenderNodeType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_getDisplayRenderNodeType)

static bool js_cocos2dx_studio_DisplayManager_removeDisplay(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_removeDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_removeDisplay : Error processing arguments");
        cobj->removeDisplay(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_removeDisplay)

static bool js_cocos2dx_studio_DisplayManager_setForceChangeDisplay(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_setForceChangeDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_setForceChangeDisplay : Error processing arguments");
        cobj->setForceChangeDisplay(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_setForceChangeDisplay)

static bool js_cocos2dx_studio_DisplayManager_init(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_init : Error processing arguments");
        bool result = cobj->init(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_init)

static bool js_cocos2dx_studio_DisplayManager_getContentSize(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_getContentSize : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Size result = cobj->getContentSize();
        ok &= Size_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_getContentSize : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_getContentSize)

static bool js_cocos2dx_studio_DisplayManager_getBoundingBox(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_getBoundingBox : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Rect result = cobj->getBoundingBox();
        ok &= Rect_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_getBoundingBox : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_getBoundingBox)

static bool js_cocos2dx_studio_DisplayManager_addDisplay(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_DisplayManager_addDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            cocos2d::Node* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            int arg1 = 0;
            ok &= seval_to_int32(args[1], (int32_t *)&arg1);
            if (!ok) { ok = true; break; }
            cobj->addDisplay(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            cocostudio::DisplayData* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            int arg1 = 0;
            ok &= seval_to_int32(args[1], (int32_t *)&arg1);
            if (!ok) { ok = true; break; }
            cobj->addDisplay(arg0, arg1);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_addDisplay)

static bool js_cocos2dx_studio_DisplayManager_containPoint(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_DisplayManager_containPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            float arg0 = 0;
            ok &= seval_to_float(args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool result = cobj->containPoint(arg0, arg1);
            ok &= boolean_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_containPoint : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            cocos2d::Vec2 arg0;
            ok &= seval_to_Vec2(args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool result = cobj->containPoint(arg0);
            ok &= boolean_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_containPoint : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_containPoint)

static bool js_cocos2dx_studio_DisplayManager_initDisplayList(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_initDisplayList : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::BoneData* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_initDisplayList : Error processing arguments");
        cobj->initDisplayList(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_initDisplayList)

static bool js_cocos2dx_studio_DisplayManager_changeDisplayWithIndex(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_changeDisplayWithIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        bool arg1;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_changeDisplayWithIndex : Error processing arguments");
        cobj->changeDisplayWithIndex(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_changeDisplayWithIndex)

static bool js_cocos2dx_studio_DisplayManager_changeDisplayWithName(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_changeDisplayWithName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_changeDisplayWithName : Error processing arguments");
        cobj->changeDisplayWithName(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_changeDisplayWithName)

static bool js_cocos2dx_studio_DisplayManager_isForceChangeDisplay(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_isForceChangeDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isForceChangeDisplay();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_isForceChangeDisplay : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_isForceChangeDisplay)

static bool js_cocos2dx_studio_DisplayManager_getDecorativeDisplayByIndex(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_getDecorativeDisplayByIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_getDecorativeDisplayByIndex : Error processing arguments");
        cocostudio::DecorativeDisplay* result = cobj->getDecorativeDisplayByIndex(arg0);
        ok &= native_ptr_to_seval<cocostudio::DecorativeDisplay>((cocostudio::DecorativeDisplay*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_getDecorativeDisplayByIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_getDecorativeDisplayByIndex)

static bool js_cocos2dx_studio_DisplayManager_getCurrentDisplayIndex(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_getCurrentDisplayIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getCurrentDisplayIndex();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_getCurrentDisplayIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_getCurrentDisplayIndex)

static bool js_cocos2dx_studio_DisplayManager_getAnchorPoint(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_getAnchorPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec2 result = cobj->getAnchorPoint();
        ok &= Vec2_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_getAnchorPoint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_getAnchorPoint)

static bool js_cocos2dx_studio_DisplayManager_getDecorativeDisplayList(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_getDecorativeDisplayList : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::Vector<cocostudio::DecorativeDisplay *>& result = cobj->getDecorativeDisplayList();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_getDecorativeDisplayList : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_getDecorativeDisplayList)

static bool js_cocos2dx_studio_DisplayManager_isVisible(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_isVisible : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isVisible();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_isVisible : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_isVisible)

static bool js_cocos2dx_studio_DisplayManager_setVisible(se::State& s)
{
    cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_DisplayManager_setVisible : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_setVisible : Error processing arguments");
        cobj->setVisible(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_setVisible)

static bool js_cocos2dx_studio_DisplayManager_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_DisplayManager_create : Error processing arguments");
        auto result = cocostudio::DisplayManager::create(arg0);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_DisplayManager_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_DisplayManager_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_DisplayManager_finalize)

static bool js_cocos2dx_studio_DisplayManager_constructor(se::State& s)
{
    cocostudio::DisplayManager* cobj = new (std::nothrow) cocostudio::DisplayManager();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_DisplayManager_constructor, __jsb_cocostudio_DisplayManager_class, js_cocostudio_DisplayManager_finalize)




bool js_cocostudio_DisplayManager_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::DisplayManager)", s.nativeThisObject());
        cocostudio::DisplayManager* cobj = (cocostudio::DisplayManager*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_DisplayManager_finalize)

bool js_register_cocos2dx_studio_DisplayManager(se::Object* obj)
{
    auto cls = se::Class::create("DisplayManager", obj, nullptr, _SE(js_cocos2dx_studio_DisplayManager_constructor));

    cls->defineFunction("getCurrentDecorativeDisplay", _SE(js_cocos2dx_studio_DisplayManager_getCurrentDecorativeDisplay));
    cls->defineFunction("getDisplayRenderNode", _SE(js_cocos2dx_studio_DisplayManager_getDisplayRenderNode));
    cls->defineFunction("getAnchorPointInPoints", _SE(js_cocos2dx_studio_DisplayManager_getAnchorPointInPoints));
    cls->defineFunction("setCurrentDecorativeDisplay", _SE(js_cocos2dx_studio_DisplayManager_setCurrentDecorativeDisplay));
    cls->defineFunction("getDisplayRenderNodeType", _SE(js_cocos2dx_studio_DisplayManager_getDisplayRenderNodeType));
    cls->defineFunction("removeDisplay", _SE(js_cocos2dx_studio_DisplayManager_removeDisplay));
    cls->defineFunction("setForceChangeDisplay", _SE(js_cocos2dx_studio_DisplayManager_setForceChangeDisplay));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_DisplayManager_init));
    cls->defineFunction("getContentSize", _SE(js_cocos2dx_studio_DisplayManager_getContentSize));
    cls->defineFunction("getBoundingBox", _SE(js_cocos2dx_studio_DisplayManager_getBoundingBox));
    cls->defineFunction("addDisplay", _SE(js_cocos2dx_studio_DisplayManager_addDisplay));
    cls->defineFunction("containPoint", _SE(js_cocos2dx_studio_DisplayManager_containPoint));
    cls->defineFunction("initDisplayList", _SE(js_cocos2dx_studio_DisplayManager_initDisplayList));
    cls->defineFunction("changeDisplayWithIndex", _SE(js_cocos2dx_studio_DisplayManager_changeDisplayWithIndex));
    cls->defineFunction("changeDisplayWithName", _SE(js_cocos2dx_studio_DisplayManager_changeDisplayWithName));
    cls->defineFunction("isForceChangeDisplay", _SE(js_cocos2dx_studio_DisplayManager_isForceChangeDisplay));
    cls->defineFunction("getDecorativeDisplayByIndex", _SE(js_cocos2dx_studio_DisplayManager_getDecorativeDisplayByIndex));
    cls->defineFunction("getCurrentDisplayIndex", _SE(js_cocos2dx_studio_DisplayManager_getCurrentDisplayIndex));
    cls->defineFunction("getAnchorPoint", _SE(js_cocos2dx_studio_DisplayManager_getAnchorPoint));
    cls->defineFunction("getDecorativeDisplayList", _SE(js_cocos2dx_studio_DisplayManager_getDecorativeDisplayList));
    cls->defineFunction("isVisible", _SE(js_cocos2dx_studio_DisplayManager_isVisible));
    cls->defineFunction("setVisible", _SE(js_cocos2dx_studio_DisplayManager_setVisible));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_DisplayManager_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_DisplayManager_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::DisplayManager>(cls);

    __jsb_cocostudio_DisplayManager_proto = cls->getProto();
    __jsb_cocostudio_DisplayManager_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_Bone_proto = nullptr;
se::Class* __jsb_cocostudio_Bone_class = nullptr;

static bool js_cocos2dx_studio_Bone_isTransformDirty(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_isTransformDirty : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isTransformDirty();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_isTransformDirty : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_isTransformDirty)

static bool js_cocos2dx_studio_Bone_setBlendFunc(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_setBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::BlendFunc arg0;
        ok &= seval_to_blendfunc(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_setBlendFunc : Error processing arguments");
        cobj->setBlendFunc(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_setBlendFunc)

static bool js_cocos2dx_studio_Bone_isIgnoreMovementBoneData(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_isIgnoreMovementBoneData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isIgnoreMovementBoneData();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_isIgnoreMovementBoneData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_isIgnoreMovementBoneData)

static bool js_cocos2dx_studio_Bone_updateZOrder(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_updateZOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateZOrder();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_updateZOrder)

static bool js_cocos2dx_studio_Bone_getDisplayRenderNode(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_getDisplayRenderNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Node* result = cobj->getDisplayRenderNode();
        ok &= native_ptr_to_seval<cocos2d::Node>((cocos2d::Node*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_getDisplayRenderNode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_getDisplayRenderNode)

static bool js_cocos2dx_studio_Bone_isBlendDirty(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_isBlendDirty : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isBlendDirty();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_isBlendDirty : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_isBlendDirty)

static bool js_cocos2dx_studio_Bone_addChildBone(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_addChildBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_addChildBone : Error processing arguments");
        cobj->addChildBone(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_addChildBone)

static bool js_cocos2dx_studio_Bone_getWorldInfo(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_getWorldInfo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::BaseData* result = cobj->getWorldInfo();
        ok &= native_ptr_to_seval<cocostudio::BaseData>((cocostudio::BaseData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_getWorldInfo : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_getWorldInfo)

static bool js_cocos2dx_studio_Bone_getTween(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_getTween : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::Tween* result = cobj->getTween();
        ok &= native_ptr_to_seval<cocostudio::Tween>((cocostudio::Tween*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_getTween : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_getTween)

static bool js_cocos2dx_studio_Bone_getParentBone(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_getParentBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::Bone* result = cobj->getParentBone();
        ok &= native_ptr_to_seval<cocostudio::Bone>((cocostudio::Bone*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_getParentBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_getParentBone)

static bool js_cocos2dx_studio_Bone_updateColor(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_updateColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateColor();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_updateColor)

static bool js_cocos2dx_studio_Bone_setTransformDirty(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_setTransformDirty : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_setTransformDirty : Error processing arguments");
        cobj->setTransformDirty(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_setTransformDirty)

static bool js_cocos2dx_studio_Bone_getDisplayRenderNodeType(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_getDisplayRenderNodeType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getDisplayRenderNodeType();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_getDisplayRenderNodeType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_getDisplayRenderNodeType)

static bool js_cocos2dx_studio_Bone_removeDisplay(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_removeDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_removeDisplay : Error processing arguments");
        cobj->removeDisplay(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_removeDisplay)

static bool js_cocos2dx_studio_Bone_setBoneData(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_setBoneData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::BoneData* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_setBoneData : Error processing arguments");
        cobj->setBoneData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_setBoneData)

static bool js_cocos2dx_studio_Bone_init(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_init : Error processing arguments");
        bool result = cobj->init(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_init)

static bool js_cocos2dx_studio_Bone_setParentBone(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_setParentBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_setParentBone : Error processing arguments");
        cobj->setParentBone(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_setParentBone)

static bool js_cocos2dx_studio_Bone_addDisplay(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_Bone_addDisplay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            cocos2d::Node* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            int arg1 = 0;
            ok &= seval_to_int32(args[1], (int32_t *)&arg1);
            if (!ok) { ok = true; break; }
            cobj->addDisplay(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            cocostudio::DisplayData* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            int arg1 = 0;
            ok &= seval_to_int32(args[1], (int32_t *)&arg1);
            if (!ok) { ok = true; break; }
            cobj->addDisplay(arg0, arg1);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_addDisplay)

static bool js_cocos2dx_studio_Bone_setIgnoreMovementBoneData(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_setIgnoreMovementBoneData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_setIgnoreMovementBoneData : Error processing arguments");
        cobj->setIgnoreMovementBoneData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_setIgnoreMovementBoneData)

static bool js_cocos2dx_studio_Bone_getBlendFunc(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_getBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::BlendFunc result = cobj->getBlendFunc();
        ok &= blendfunc_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_getBlendFunc : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_getBlendFunc)

static bool js_cocos2dx_studio_Bone_removeFromParent(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_removeFromParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_removeFromParent : Error processing arguments");
        cobj->removeFromParent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_removeFromParent)

static bool js_cocos2dx_studio_Bone_getColliderDetector(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_getColliderDetector : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::ColliderDetector* result = cobj->getColliderDetector();
        ok &= native_ptr_to_seval<cocostudio::ColliderDetector>((cocostudio::ColliderDetector*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_getColliderDetector : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_getColliderDetector)

static bool js_cocos2dx_studio_Bone_getChildArmature(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_getChildArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::Armature* result = cobj->getChildArmature();
        ok &= native_ptr_to_seval<cocostudio::Armature>((cocostudio::Armature*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_getChildArmature : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_getChildArmature)

static bool js_cocos2dx_studio_Bone_changeDisplayWithIndex(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_changeDisplayWithIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        bool arg1;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_changeDisplayWithIndex : Error processing arguments");
        cobj->changeDisplayWithIndex(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_changeDisplayWithIndex)

static bool js_cocos2dx_studio_Bone_changeDisplayWithName(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_changeDisplayWithName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_changeDisplayWithName : Error processing arguments");
        cobj->changeDisplayWithName(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_changeDisplayWithName)

static bool js_cocos2dx_studio_Bone_setArmature(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_setArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Armature* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_setArmature : Error processing arguments");
        cobj->setArmature(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_setArmature)

static bool js_cocos2dx_studio_Bone_setBlendDirty(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_setBlendDirty : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_setBlendDirty : Error processing arguments");
        cobj->setBlendDirty(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_setBlendDirty)

static bool js_cocos2dx_studio_Bone_removeChildBone(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_removeChildBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocostudio::Bone* arg0 = nullptr;
        bool arg1;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_removeChildBone : Error processing arguments");
        cobj->removeChildBone(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_removeChildBone)

static bool js_cocos2dx_studio_Bone_setChildArmature(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_setChildArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Armature* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_setChildArmature : Error processing arguments");
        cobj->setChildArmature(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_setChildArmature)

static bool js_cocos2dx_studio_Bone_getNodeToArmatureTransform(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_getNodeToArmatureTransform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getNodeToArmatureTransform();
        ok &= Mat4_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_getNodeToArmatureTransform : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_getNodeToArmatureTransform)

static bool js_cocos2dx_studio_Bone_getDisplayManager(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_getDisplayManager : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::DisplayManager* result = cobj->getDisplayManager();
        ok &= native_ptr_to_seval<cocostudio::DisplayManager>((cocostudio::DisplayManager*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_getDisplayManager : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_getDisplayManager)

static bool js_cocos2dx_studio_Bone_getArmature(se::State& s)
{
    cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Bone_getArmature : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::Armature* result = cobj->getArmature();
        ok &= native_ptr_to_seval<cocostudio::Armature>((cocostudio::Armature*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_getArmature : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_getArmature)

static bool js_cocos2dx_studio_Bone_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocostudio::Bone* result = cocostudio::Bone::create(arg0);
            ok &= native_ptr_to_seval<cocostudio::Bone>((cocostudio::Bone*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            cocostudio::Bone* result = cocostudio::Bone::create();
            ok &= native_ptr_to_seval<cocostudio::Bone>((cocostudio::Bone*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Bone_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Bone_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_Bone_finalize)

static bool js_cocos2dx_studio_Bone_constructor(se::State& s)
{
    cocostudio::Bone* cobj = new (std::nothrow) cocostudio::Bone();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_Bone_constructor, __jsb_cocostudio_Bone_class, js_cocostudio_Bone_finalize)



extern se::Object* __jsb_cocos2d_Node_proto;

bool js_cocostudio_Bone_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::Bone)", s.nativeThisObject());
        cocostudio::Bone* cobj = (cocostudio::Bone*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_Bone_finalize)

bool js_register_cocos2dx_studio_Bone(se::Object* obj)
{
    auto cls = se::Class::create("Bone", obj, __jsb_cocos2d_Node_proto, _SE(js_cocos2dx_studio_Bone_constructor));

    cls->defineFunction("isTransformDirty", _SE(js_cocos2dx_studio_Bone_isTransformDirty));
    cls->defineFunction("setBlendFunc", _SE(js_cocos2dx_studio_Bone_setBlendFunc));
    cls->defineFunction("isIgnoreMovementBoneData", _SE(js_cocos2dx_studio_Bone_isIgnoreMovementBoneData));
    cls->defineFunction("updateZOrder", _SE(js_cocos2dx_studio_Bone_updateZOrder));
    cls->defineFunction("getDisplayRenderNode", _SE(js_cocos2dx_studio_Bone_getDisplayRenderNode));
    cls->defineFunction("isBlendDirty", _SE(js_cocos2dx_studio_Bone_isBlendDirty));
    cls->defineFunction("addChildBone", _SE(js_cocos2dx_studio_Bone_addChildBone));
    cls->defineFunction("getWorldInfo", _SE(js_cocos2dx_studio_Bone_getWorldInfo));
    cls->defineFunction("getTween", _SE(js_cocos2dx_studio_Bone_getTween));
    cls->defineFunction("getParentBone", _SE(js_cocos2dx_studio_Bone_getParentBone));
    cls->defineFunction("updateColor", _SE(js_cocos2dx_studio_Bone_updateColor));
    cls->defineFunction("setTransformDirty", _SE(js_cocos2dx_studio_Bone_setTransformDirty));
    cls->defineFunction("getDisplayRenderNodeType", _SE(js_cocos2dx_studio_Bone_getDisplayRenderNodeType));
    cls->defineFunction("removeDisplay", _SE(js_cocos2dx_studio_Bone_removeDisplay));
    cls->defineFunction("setBoneData", _SE(js_cocos2dx_studio_Bone_setBoneData));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_Bone_init));
    cls->defineFunction("setParentBone", _SE(js_cocos2dx_studio_Bone_setParentBone));
    cls->defineFunction("addDisplay", _SE(js_cocos2dx_studio_Bone_addDisplay));
    cls->defineFunction("setIgnoreMovementBoneData", _SE(js_cocos2dx_studio_Bone_setIgnoreMovementBoneData));
    cls->defineFunction("getBlendFunc", _SE(js_cocos2dx_studio_Bone_getBlendFunc));
    cls->defineFunction("removeFromParent", _SE(js_cocos2dx_studio_Bone_removeFromParent));
    cls->defineFunction("getColliderDetector", _SE(js_cocos2dx_studio_Bone_getColliderDetector));
    cls->defineFunction("getChildArmature", _SE(js_cocos2dx_studio_Bone_getChildArmature));
    cls->defineFunction("changeDisplayWithIndex", _SE(js_cocos2dx_studio_Bone_changeDisplayWithIndex));
    cls->defineFunction("changeDisplayWithName", _SE(js_cocos2dx_studio_Bone_changeDisplayWithName));
    cls->defineFunction("setArmature", _SE(js_cocos2dx_studio_Bone_setArmature));
    cls->defineFunction("setBlendDirty", _SE(js_cocos2dx_studio_Bone_setBlendDirty));
    cls->defineFunction("removeChildBone", _SE(js_cocos2dx_studio_Bone_removeChildBone));
    cls->defineFunction("setChildArmature", _SE(js_cocos2dx_studio_Bone_setChildArmature));
    cls->defineFunction("getNodeToArmatureTransform", _SE(js_cocos2dx_studio_Bone_getNodeToArmatureTransform));
    cls->defineFunction("getDisplayManager", _SE(js_cocos2dx_studio_Bone_getDisplayManager));
    cls->defineFunction("getArmature", _SE(js_cocos2dx_studio_Bone_getArmature));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_Bone_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_Bone_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::Bone>(cls);

    __jsb_cocostudio_Bone_proto = cls->getProto();
    __jsb_cocostudio_Bone_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_BatchNode_proto = nullptr;
se::Class* __jsb_cocostudio_BatchNode_class = nullptr;

static bool js_cocos2dx_studio_BatchNode_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::BatchNode::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_BatchNode_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BatchNode_create)


extern se::Object* __jsb_cocos2d_Node_proto;


bool js_register_cocos2dx_studio_BatchNode(se::Object* obj)
{
    auto cls = se::Class::create("BatchNode", obj, __jsb_cocos2d_Node_proto, nullptr);

    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_BatchNode_create));
    cls->install();
    JSBClassType::registerClass<cocostudio::BatchNode>(cls);

    __jsb_cocostudio_BatchNode_proto = cls->getProto();
    __jsb_cocostudio_BatchNode_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_ArmatureAnimation_proto = nullptr;
se::Class* __jsb_cocostudio_ArmatureAnimation_class = nullptr;

static bool js_cocos2dx_studio_ArmatureAnimation_getSpeedScale(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_getSpeedScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSpeedScale();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_getSpeedScale : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_getSpeedScale)

static bool js_cocos2dx_studio_ArmatureAnimation_play(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_play : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_play : Error processing arguments");
        cobj->play(arg0);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_play : Error processing arguments");
        cobj->play(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        ok &= seval_to_int32(args[2], (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_play : Error processing arguments");
        cobj->play(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_play)

static bool js_cocos2dx_studio_ArmatureAnimation_gotoAndPause(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_gotoAndPause : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_gotoAndPause : Error processing arguments");
        cobj->gotoAndPause(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_gotoAndPause)

static bool js_cocos2dx_studio_ArmatureAnimation_playWithIndexes(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_playWithIndexes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::vector<int> arg0;
        ok &= seval_to_std_vector_int(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_playWithIndexes : Error processing arguments");
        cobj->playWithIndexes(arg0);
        return true;
    }
    if (argc == 2) {
        std::vector<int> arg0;
        int arg1 = 0;
        ok &= seval_to_std_vector_int(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_playWithIndexes : Error processing arguments");
        cobj->playWithIndexes(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        std::vector<int> arg0;
        int arg1 = 0;
        bool arg2;
        ok &= seval_to_std_vector_int(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        ok &= seval_to_boolean(args[2], &arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_playWithIndexes : Error processing arguments");
        cobj->playWithIndexes(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_playWithIndexes)

static bool js_cocos2dx_studio_ArmatureAnimation_setAnimationData(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_setAnimationData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::AnimationData* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_setAnimationData : Error processing arguments");
        cobj->setAnimationData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_setAnimationData)

static bool js_cocos2dx_studio_ArmatureAnimation_setSpeedScale(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_setSpeedScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_setSpeedScale : Error processing arguments");
        cobj->setSpeedScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_setSpeedScale)

static bool js_cocos2dx_studio_ArmatureAnimation_getAnimationData(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_getAnimationData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::AnimationData* result = cobj->getAnimationData();
        ok &= native_ptr_to_seval<cocostudio::AnimationData>((cocostudio::AnimationData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_getAnimationData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_getAnimationData)

static bool js_cocos2dx_studio_ArmatureAnimation_gotoAndPlay(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_gotoAndPlay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_gotoAndPlay : Error processing arguments");
        cobj->gotoAndPlay(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_gotoAndPlay)

static bool js_cocos2dx_studio_ArmatureAnimation_init(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Armature* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_init : Error processing arguments");
        bool result = cobj->init(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_init)

static bool js_cocos2dx_studio_ArmatureAnimation_playWithNames(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_playWithNames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::vector<std::string> arg0;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_playWithNames : Error processing arguments");
        cobj->playWithNames(arg0);
        return true;
    }
    if (argc == 2) {
        std::vector<std::string> arg0;
        int arg1 = 0;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_playWithNames : Error processing arguments");
        cobj->playWithNames(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        std::vector<std::string> arg0;
        int arg1 = 0;
        bool arg2;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        ok &= seval_to_boolean(args[2], &arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_playWithNames : Error processing arguments");
        cobj->playWithNames(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_playWithNames)

static bool js_cocos2dx_studio_ArmatureAnimation_getMovementCount(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_getMovementCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        ssize_t result = cobj->getMovementCount();
        ok &= ssize_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_getMovementCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_getMovementCount)

static bool js_cocos2dx_studio_ArmatureAnimation_playWithIndex(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_playWithIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_playWithIndex : Error processing arguments");
        cobj->playWithIndex(arg0);
        return true;
    }
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_playWithIndex : Error processing arguments");
        cobj->playWithIndex(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        int arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        ok &= seval_to_int32(args[2], (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_playWithIndex : Error processing arguments");
        cobj->playWithIndex(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_playWithIndex)

static bool js_cocos2dx_studio_ArmatureAnimation_getCurrentMovementID(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureAnimation_getCurrentMovementID : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = cobj->getCurrentMovementID();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_getCurrentMovementID : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_getCurrentMovementID)

static bool js_cocos2dx_studio_ArmatureAnimation_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Armature* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureAnimation_create : Error processing arguments");
        auto result = cocostudio::ArmatureAnimation::create(arg0);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_ArmatureAnimation_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureAnimation_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_ArmatureAnimation_finalize)

static bool js_cocos2dx_studio_ArmatureAnimation_constructor(se::State& s)
{
    cocostudio::ArmatureAnimation* cobj = new (std::nothrow) cocostudio::ArmatureAnimation();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ArmatureAnimation_constructor, __jsb_cocostudio_ArmatureAnimation_class, js_cocostudio_ArmatureAnimation_finalize)



extern se::Object* __jsb_cocostudio_ProcessBase_proto;

bool js_cocostudio_ArmatureAnimation_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::ArmatureAnimation)", s.nativeThisObject());
        cocostudio::ArmatureAnimation* cobj = (cocostudio::ArmatureAnimation*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_ArmatureAnimation_finalize)

bool js_register_cocos2dx_studio_ArmatureAnimation(se::Object* obj)
{
    auto cls = se::Class::create("ArmatureAnimation", obj, __jsb_cocostudio_ProcessBase_proto, _SE(js_cocos2dx_studio_ArmatureAnimation_constructor));

    cls->defineFunction("getSpeedScale", _SE(js_cocos2dx_studio_ArmatureAnimation_getSpeedScale));
    cls->defineFunction("play", _SE(js_cocos2dx_studio_ArmatureAnimation_play));
    cls->defineFunction("gotoAndPause", _SE(js_cocos2dx_studio_ArmatureAnimation_gotoAndPause));
    cls->defineFunction("playWithIndexes", _SE(js_cocos2dx_studio_ArmatureAnimation_playWithIndexes));
    cls->defineFunction("setAnimationData", _SE(js_cocos2dx_studio_ArmatureAnimation_setAnimationData));
    cls->defineFunction("setSpeedScale", _SE(js_cocos2dx_studio_ArmatureAnimation_setSpeedScale));
    cls->defineFunction("getAnimationData", _SE(js_cocos2dx_studio_ArmatureAnimation_getAnimationData));
    cls->defineFunction("gotoAndPlay", _SE(js_cocos2dx_studio_ArmatureAnimation_gotoAndPlay));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_ArmatureAnimation_init));
    cls->defineFunction("playWithNames", _SE(js_cocos2dx_studio_ArmatureAnimation_playWithNames));
    cls->defineFunction("getMovementCount", _SE(js_cocos2dx_studio_ArmatureAnimation_getMovementCount));
    cls->defineFunction("playWithIndex", _SE(js_cocos2dx_studio_ArmatureAnimation_playWithIndex));
    cls->defineFunction("getCurrentMovementID", _SE(js_cocos2dx_studio_ArmatureAnimation_getCurrentMovementID));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ArmatureAnimation_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_ArmatureAnimation_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::ArmatureAnimation>(cls);

    __jsb_cocostudio_ArmatureAnimation_proto = cls->getProto();
    __jsb_cocostudio_ArmatureAnimation_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_ArmatureDataManager_proto = nullptr;
se::Class* __jsb_cocostudio_ArmatureDataManager_class = nullptr;

static bool js_cocos2dx_studio_ArmatureDataManager_getAnimationDatas(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_getAnimationDatas : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::Map<std::string, cocostudio::AnimationData *>& result = cobj->getAnimationDatas();
        ok &= native_ptr_to_seval<cocos2d::Map<std::basic_string<char>, cocostudio::AnimationData >&>((cocos2d::Map<std::basic_string<char>, cocostudio::AnimationData *>&)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_getAnimationDatas : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_getAnimationDatas)

static bool js_cocos2dx_studio_ArmatureDataManager_removeAnimationData(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_removeAnimationData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_removeAnimationData : Error processing arguments");
        cobj->removeAnimationData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_removeAnimationData)

static bool js_cocos2dx_studio_ArmatureDataManager_addArmatureData(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_addArmatureData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        cocostudio::ArmatureData* arg1 = nullptr;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_addArmatureData : Error processing arguments");
        cobj->addArmatureData(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        cocostudio::ArmatureData* arg1 = nullptr;
        std::string arg2;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_addArmatureData : Error processing arguments");
        cobj->addArmatureData(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_addArmatureData)

static bool js_cocos2dx_studio_ArmatureDataManager_addArmatureFileInfo(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_ArmatureDataManager_addArmatureFileInfo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(args[1], &arg1);
            if (!ok) { ok = true; break; }
            std::string arg2;
            ok &= seval_to_std_string(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cobj->addArmatureFileInfo(arg0, arg1, arg2);
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->addArmatureFileInfo(arg0);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_addArmatureFileInfo)

static bool js_cocos2dx_studio_ArmatureDataManager_removeArmatureFileInfo(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_removeArmatureFileInfo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_removeArmatureFileInfo : Error processing arguments");
        cobj->removeArmatureFileInfo(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_removeArmatureFileInfo)

static bool js_cocos2dx_studio_ArmatureDataManager_getTextureData(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_getTextureData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_getTextureData : Error processing arguments");
        cocostudio::TextureData* result = cobj->getTextureData(arg0);
        ok &= native_ptr_to_seval<cocostudio::TextureData>((cocostudio::TextureData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_getTextureData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_getTextureData)

static bool js_cocos2dx_studio_ArmatureDataManager_getArmatureData(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_getArmatureData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_getArmatureData : Error processing arguments");
        cocostudio::ArmatureData* result = cobj->getArmatureData(arg0);
        ok &= native_ptr_to_seval<cocostudio::ArmatureData>((cocostudio::ArmatureData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_getArmatureData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_getArmatureData)

static bool js_cocos2dx_studio_ArmatureDataManager_getAnimationData(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_getAnimationData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_getAnimationData : Error processing arguments");
        cocostudio::AnimationData* result = cobj->getAnimationData(arg0);
        ok &= native_ptr_to_seval<cocostudio::AnimationData>((cocostudio::AnimationData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_getAnimationData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_getAnimationData)

static bool js_cocos2dx_studio_ArmatureDataManager_addAnimationData(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_addAnimationData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        cocostudio::AnimationData* arg1 = nullptr;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_addAnimationData : Error processing arguments");
        cobj->addAnimationData(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        cocostudio::AnimationData* arg1 = nullptr;
        std::string arg2;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_addAnimationData : Error processing arguments");
        cobj->addAnimationData(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_addAnimationData)

static bool js_cocos2dx_studio_ArmatureDataManager_init(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->init();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_init)

static bool js_cocos2dx_studio_ArmatureDataManager_removeArmatureData(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_removeArmatureData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_removeArmatureData : Error processing arguments");
        cobj->removeArmatureData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_removeArmatureData)

static bool js_cocos2dx_studio_ArmatureDataManager_getArmatureDatas(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_getArmatureDatas : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::Map<std::string, cocostudio::ArmatureData *>& result = cobj->getArmatureDatas();
        ok &= native_ptr_to_seval<cocos2d::Map<std::basic_string<char>, cocostudio::ArmatureData >&>((cocos2d::Map<std::basic_string<char>, cocostudio::ArmatureData *>&)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_getArmatureDatas : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_getArmatureDatas)

static bool js_cocos2dx_studio_ArmatureDataManager_removeTextureData(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_removeTextureData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_removeTextureData : Error processing arguments");
        cobj->removeTextureData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_removeTextureData)

static bool js_cocos2dx_studio_ArmatureDataManager_addTextureData(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_addTextureData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        cocostudio::TextureData* arg1 = nullptr;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_addTextureData : Error processing arguments");
        cobj->addTextureData(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        cocostudio::TextureData* arg1 = nullptr;
        std::string arg2;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_addTextureData : Error processing arguments");
        cobj->addTextureData(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_addTextureData)

static bool js_cocos2dx_studio_ArmatureDataManager_isAutoLoadSpriteFile(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_isAutoLoadSpriteFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isAutoLoadSpriteFile();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_isAutoLoadSpriteFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_isAutoLoadSpriteFile)

static bool js_cocos2dx_studio_ArmatureDataManager_addSpriteFrameFromFile(se::State& s)
{
    cocostudio::ArmatureDataManager* cobj = (cocostudio::ArmatureDataManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ArmatureDataManager_addSpriteFrameFromFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_addSpriteFrameFromFile : Error processing arguments");
        cobj->addSpriteFrameFromFile(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ArmatureDataManager_addSpriteFrameFromFile : Error processing arguments");
        cobj->addSpriteFrameFromFile(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_addSpriteFrameFromFile)

static bool js_cocos2dx_studio_ArmatureDataManager_destroyInstance(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cocostudio::ArmatureDataManager::destroyInstance();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_destroyInstance)

static bool js_cocos2dx_studio_ArmatureDataManager_getInstance(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::ArmatureDataManager::getInstance();
        se::Object* obj = nullptr;
        if (result->_scriptObject == nullptr)
        {
            obj = se::Object::createObjectWithClass(__jsb_cocostudio_ArmatureDataManager_class, true);
            obj->setPrivateData(result);
            result->_scriptObject = obj;
        }
        else
        {
            obj = se::Object::getObjectWithPtr(result);
        }
        assert(obj);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ArmatureDataManager_getInstance)




bool js_register_cocos2dx_studio_ArmatureDataManager(se::Object* obj)
{
    auto cls = se::Class::create("ArmatureDataManager", obj, nullptr, nullptr);

    cls->defineFunction("getAnimationDatas", _SE(js_cocos2dx_studio_ArmatureDataManager_getAnimationDatas));
    cls->defineFunction("removeAnimationData", _SE(js_cocos2dx_studio_ArmatureDataManager_removeAnimationData));
    cls->defineFunction("addArmatureData", _SE(js_cocos2dx_studio_ArmatureDataManager_addArmatureData));
    cls->defineFunction("addArmatureFileInfo", _SE(js_cocos2dx_studio_ArmatureDataManager_addArmatureFileInfo));
    cls->defineFunction("removeArmatureFileInfo", _SE(js_cocos2dx_studio_ArmatureDataManager_removeArmatureFileInfo));
    cls->defineFunction("getTextureData", _SE(js_cocos2dx_studio_ArmatureDataManager_getTextureData));
    cls->defineFunction("getArmatureData", _SE(js_cocos2dx_studio_ArmatureDataManager_getArmatureData));
    cls->defineFunction("getAnimationData", _SE(js_cocos2dx_studio_ArmatureDataManager_getAnimationData));
    cls->defineFunction("addAnimationData", _SE(js_cocos2dx_studio_ArmatureDataManager_addAnimationData));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_ArmatureDataManager_init));
    cls->defineFunction("removeArmatureData", _SE(js_cocos2dx_studio_ArmatureDataManager_removeArmatureData));
    cls->defineFunction("getArmatureDatas", _SE(js_cocos2dx_studio_ArmatureDataManager_getArmatureDatas));
    cls->defineFunction("removeTextureData", _SE(js_cocos2dx_studio_ArmatureDataManager_removeTextureData));
    cls->defineFunction("addTextureData", _SE(js_cocos2dx_studio_ArmatureDataManager_addTextureData));
    cls->defineFunction("isAutoLoadSpriteFile", _SE(js_cocos2dx_studio_ArmatureDataManager_isAutoLoadSpriteFile));
    cls->defineFunction("addSpriteFrameFromFile", _SE(js_cocos2dx_studio_ArmatureDataManager_addSpriteFrameFromFile));
    cls->defineStaticFunction("destroyInstance", _SE(js_cocos2dx_studio_ArmatureDataManager_destroyInstance));
    cls->defineStaticFunction("getInstance", _SE(js_cocos2dx_studio_ArmatureDataManager_getInstance));
    cls->install();
    JSBClassType::registerClass<cocostudio::ArmatureDataManager>(cls);

    __jsb_cocostudio_ArmatureDataManager_proto = cls->getProto();
    __jsb_cocostudio_ArmatureDataManager_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_Armature_proto = nullptr;
se::Class* __jsb_cocostudio_Armature_class = nullptr;

static bool js_cocos2dx_studio_Armature_getBone(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getBone : Error processing arguments");
        cocostudio::Bone* result = cobj->getBone(arg0);
        ok &= native_ptr_to_seval<cocostudio::Bone>((cocostudio::Bone*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getBone)

static bool js_cocos2dx_studio_Armature_changeBoneParent(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_changeBoneParent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocostudio::Bone* arg0 = nullptr;
        std::string arg1;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_changeBoneParent : Error processing arguments");
        cobj->changeBoneParent(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_changeBoneParent)

static bool js_cocos2dx_studio_Armature_setAnimation(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_setAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::ArmatureAnimation* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_setAnimation : Error processing arguments");
        cobj->setAnimation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_setAnimation)

static bool js_cocos2dx_studio_Armature_getBoneAtPoint(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getBoneAtPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getBoneAtPoint : Error processing arguments");
        cocostudio::Bone* result = cobj->getBoneAtPoint(arg0, arg1);
        ok &= native_ptr_to_seval<cocostudio::Bone>((cocostudio::Bone*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getBoneAtPoint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getBoneAtPoint)

static bool js_cocos2dx_studio_Armature_getArmatureTransformDirty(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getArmatureTransformDirty : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getArmatureTransformDirty();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getArmatureTransformDirty : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getArmatureTransformDirty)

static bool js_cocos2dx_studio_Armature_setVersion(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_setVersion : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_setVersion : Error processing arguments");
        cobj->setVersion(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_setVersion)

static bool js_cocos2dx_studio_Armature_updateOffsetPoint(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_updateOffsetPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateOffsetPoint();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_updateOffsetPoint)

static bool js_cocos2dx_studio_Armature_getParentBone(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getParentBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::Bone* result = cobj->getParentBone();
        ok &= native_ptr_to_seval<cocostudio::Bone>((cocostudio::Bone*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getParentBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getParentBone)

static bool js_cocos2dx_studio_Armature_removeBone(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_removeBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocostudio::Bone* arg0 = nullptr;
        bool arg1;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_removeBone : Error processing arguments");
        cobj->removeBone(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_removeBone)

static bool js_cocos2dx_studio_Armature_getBatchNode(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getBatchNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::BatchNode* result = cobj->getBatchNode();
        ok &= native_ptr_to_seval<cocostudio::BatchNode>((cocostudio::BatchNode*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getBatchNode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getBatchNode)

static bool js_cocos2dx_studio_Armature_init(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_Armature_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocostudio::Bone* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool result = cobj->init(arg0, arg1);
            ok &= boolean_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_init : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool result = cobj->init(arg0);
            ok &= boolean_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_init : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_init)

static bool js_cocos2dx_studio_Armature_setParentBone(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_setParentBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_setParentBone : Error processing arguments");
        cobj->setParentBone(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_setParentBone)

static bool js_cocos2dx_studio_Armature_setBatchNode(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_setBatchNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::BatchNode* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_setBatchNode : Error processing arguments");
        cobj->setBatchNode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_setBatchNode)

static bool js_cocos2dx_studio_Armature_getBlendFunc(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::BlendFunc& result = cobj->getBlendFunc();
        ok &= blendfunc_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getBlendFunc : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getBlendFunc)

static bool js_cocos2dx_studio_Armature_setArmatureData(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_setArmatureData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::ArmatureData* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_setArmatureData : Error processing arguments");
        cobj->setArmatureData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_setArmatureData)

static bool js_cocos2dx_studio_Armature_addBone(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_addBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocostudio::Bone* arg0 = nullptr;
        std::string arg1;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_addBone : Error processing arguments");
        cobj->addBone(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_addBone)

static bool js_cocos2dx_studio_Armature_getArmatureData(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getArmatureData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::ArmatureData* result = cobj->getArmatureData();
        ok &= native_ptr_to_seval<cocostudio::ArmatureData>((cocostudio::ArmatureData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getArmatureData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getArmatureData)

static bool js_cocos2dx_studio_Armature_getBoundingBox(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getBoundingBox : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Rect result = cobj->getBoundingBox();
        ok &= Rect_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getBoundingBox : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getBoundingBox)

static bool js_cocos2dx_studio_Armature_getVersion(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getVersion : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getVersion();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getVersion : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getVersion)

static bool js_cocos2dx_studio_Armature_getAnimation(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getAnimation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::ArmatureAnimation* result = cobj->getAnimation();
        ok &= native_ptr_to_seval<cocostudio::ArmatureAnimation>((cocostudio::ArmatureAnimation*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getAnimation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getAnimation)

static bool js_cocos2dx_studio_Armature_getOffsetPoints(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getOffsetPoints : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::Vec2& result = cobj->getOffsetPoints();
        ok &= Vec2_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getOffsetPoints : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getOffsetPoints)

static bool js_cocos2dx_studio_Armature_setBlendFunc(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_setBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::BlendFunc arg0;
        ok &= seval_to_blendfunc(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_setBlendFunc : Error processing arguments");
        cobj->setBlendFunc(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_setBlendFunc)

static bool js_cocos2dx_studio_Armature_getBoneDic(se::State& s)
{
    cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Armature_getBoneDic : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::Map<std::string, cocostudio::Bone *>& result = cobj->getBoneDic();
        ok &= native_ptr_to_seval<cocos2d::Map<std::basic_string<char>, cocostudio::Bone >&>((cocos2d::Map<std::basic_string<char>, cocostudio::Bone *>&)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_getBoneDic : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_getBoneDic)

static bool js_cocos2dx_studio_Armature_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocostudio::Armature* result = cocostudio::Armature::create(arg0);
            ok &= native_ptr_to_seval<cocostudio::Armature>((cocostudio::Armature*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            cocostudio::Armature* result = cocostudio::Armature::create();
            ok &= native_ptr_to_seval<cocostudio::Armature>((cocostudio::Armature*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocostudio::Bone* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocostudio::Armature* result = cocostudio::Armature::create(arg0, arg1);
            ok &= native_ptr_to_seval<cocostudio::Armature>((cocostudio::Armature*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Armature_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Armature_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_Armature_finalize)

static bool js_cocos2dx_studio_Armature_constructor(se::State& s)
{
    cocostudio::Armature* cobj = new (std::nothrow) cocostudio::Armature();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_Armature_constructor, __jsb_cocostudio_Armature_class, js_cocostudio_Armature_finalize)

static bool js_cocos2dx_studio_Armature_ctor(se::State& s)
{
    cocostudio::Armature* cobj = new (std::nothrow) cocostudio::Armature();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_SUB_CLS_CTOR(js_cocos2dx_studio_Armature_ctor, __jsb_cocostudio_Armature_class, js_cocostudio_Armature_finalize)


    

extern se::Object* __jsb_cocos2d_Node_proto;

bool js_cocostudio_Armature_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::Armature)", s.nativeThisObject());
        cocostudio::Armature* cobj = (cocostudio::Armature*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_Armature_finalize)

bool js_register_cocos2dx_studio_Armature(se::Object* obj)
{
    auto cls = se::Class::create("Armature", obj, __jsb_cocos2d_Node_proto, _SE(js_cocos2dx_studio_Armature_constructor));

    cls->defineFunction("getBone", _SE(js_cocos2dx_studio_Armature_getBone));
    cls->defineFunction("changeBoneParent", _SE(js_cocos2dx_studio_Armature_changeBoneParent));
    cls->defineFunction("setAnimation", _SE(js_cocos2dx_studio_Armature_setAnimation));
    cls->defineFunction("getBoneAtPoint", _SE(js_cocos2dx_studio_Armature_getBoneAtPoint));
    cls->defineFunction("getArmatureTransformDirty", _SE(js_cocos2dx_studio_Armature_getArmatureTransformDirty));
    cls->defineFunction("setVersion", _SE(js_cocos2dx_studio_Armature_setVersion));
    cls->defineFunction("updateOffsetPoint", _SE(js_cocos2dx_studio_Armature_updateOffsetPoint));
    cls->defineFunction("getParentBone", _SE(js_cocos2dx_studio_Armature_getParentBone));
    cls->defineFunction("removeBone", _SE(js_cocos2dx_studio_Armature_removeBone));
    cls->defineFunction("getBatchNode", _SE(js_cocos2dx_studio_Armature_getBatchNode));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_Armature_init));
    cls->defineFunction("setParentBone", _SE(js_cocos2dx_studio_Armature_setParentBone));
    cls->defineFunction("setBatchNode", _SE(js_cocos2dx_studio_Armature_setBatchNode));
    cls->defineFunction("getBlendFunc", _SE(js_cocos2dx_studio_Armature_getBlendFunc));
    cls->defineFunction("setArmatureData", _SE(js_cocos2dx_studio_Armature_setArmatureData));
    cls->defineFunction("addBone", _SE(js_cocos2dx_studio_Armature_addBone));
    cls->defineFunction("getArmatureData", _SE(js_cocos2dx_studio_Armature_getArmatureData));
    cls->defineFunction("boundingBox", _SE(js_cocos2dx_studio_Armature_getBoundingBox));
    cls->defineFunction("getVersion", _SE(js_cocos2dx_studio_Armature_getVersion));
    cls->defineFunction("getAnimation", _SE(js_cocos2dx_studio_Armature_getAnimation));
    cls->defineFunction("getOffsetPoints", _SE(js_cocos2dx_studio_Armature_getOffsetPoints));
    cls->defineFunction("setBlendFunc", _SE(js_cocos2dx_studio_Armature_setBlendFunc));
    cls->defineFunction("getBoneDic", _SE(js_cocos2dx_studio_Armature_getBoneDic));
    cls->defineFunction("ctor", _SE(js_cocos2dx_studio_Armature_ctor));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_Armature_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_Armature_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::Armature>(cls);

    __jsb_cocostudio_Armature_proto = cls->getProto();
    __jsb_cocostudio_Armature_class = cls;

    se::ScriptEngine::getInstance()->executeScriptBuffer("(function () { ccs.Armature.extend = cc.Class.extend; })()");
    return true;
}

se::Object* __jsb_cocostudio_Skin_proto = nullptr;
se::Class* __jsb_cocostudio_Skin_class = nullptr;

static bool js_cocos2dx_studio_Skin_getBone(se::State& s)
{
    cocostudio::Skin* cobj = (cocostudio::Skin*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Skin_getBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::Bone* result = cobj->getBone();
        ok &= native_ptr_to_seval<cocostudio::Bone>((cocostudio::Bone*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Skin_getBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Skin_getBone)

static bool js_cocos2dx_studio_Skin_getNodeToWorldTransformAR(se::State& s)
{
    cocostudio::Skin* cobj = (cocostudio::Skin*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Skin_getNodeToWorldTransformAR : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getNodeToWorldTransformAR();
        ok &= Mat4_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Skin_getNodeToWorldTransformAR : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Skin_getNodeToWorldTransformAR)

static bool js_cocos2dx_studio_Skin_getDisplayName(se::State& s)
{
    cocostudio::Skin* cobj = (cocostudio::Skin*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Skin_getDisplayName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getDisplayName();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Skin_getDisplayName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Skin_getDisplayName)

static bool js_cocos2dx_studio_Skin_updateArmatureTransform(se::State& s)
{
    cocostudio::Skin* cobj = (cocostudio::Skin*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Skin_updateArmatureTransform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateArmatureTransform();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Skin_updateArmatureTransform)

static bool js_cocos2dx_studio_Skin_setBone(se::State& s)
{
    cocostudio::Skin* cobj = (cocostudio::Skin*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Skin_setBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::Bone* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Skin_setBone : Error processing arguments");
        cobj->setBone(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Skin_setBone)

static bool js_cocos2dx_studio_Skin_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocostudio::Skin* result = cocostudio::Skin::create(arg0);
            ok &= native_ptr_to_seval<cocostudio::Skin>((cocostudio::Skin*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Skin_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            cocostudio::Skin* result = cocostudio::Skin::create();
            ok &= native_ptr_to_seval<cocostudio::Skin>((cocostudio::Skin*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Skin_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Skin_create)

static bool js_cocos2dx_studio_Skin_createWithSpriteFrameName(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Skin_createWithSpriteFrameName : Error processing arguments");
        auto result = cocostudio::Skin::createWithSpriteFrameName(arg0);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_Skin_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Skin_createWithSpriteFrameName)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_Skin_finalize)

static bool js_cocos2dx_studio_Skin_constructor(se::State& s)
{
    cocostudio::Skin* cobj = new (std::nothrow) cocostudio::Skin();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_Skin_constructor, __jsb_cocostudio_Skin_class, js_cocostudio_Skin_finalize)



extern se::Object* __jsb_cocos2d_Sprite_proto;

bool js_cocostudio_Skin_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::Skin)", s.nativeThisObject());
        cocostudio::Skin* cobj = (cocostudio::Skin*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_Skin_finalize)

bool js_register_cocos2dx_studio_Skin(se::Object* obj)
{
    auto cls = se::Class::create("Skin", obj, __jsb_cocos2d_Sprite_proto, _SE(js_cocos2dx_studio_Skin_constructor));

    cls->defineFunction("getBone", _SE(js_cocos2dx_studio_Skin_getBone));
    cls->defineFunction("getNodeToWorldTransformAR", _SE(js_cocos2dx_studio_Skin_getNodeToWorldTransformAR));
    cls->defineFunction("getDisplayName", _SE(js_cocos2dx_studio_Skin_getDisplayName));
    cls->defineFunction("updateArmatureTransform", _SE(js_cocos2dx_studio_Skin_updateArmatureTransform));
    cls->defineFunction("setBone", _SE(js_cocos2dx_studio_Skin_setBone));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_Skin_create));
    cls->defineStaticFunction("createWithSpriteFrameName", _SE(js_cocos2dx_studio_Skin_createWithSpriteFrameName));
    cls->defineFinalizedFunction(_SE(js_cocostudio_Skin_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::Skin>(cls);

    __jsb_cocostudio_Skin_proto = cls->getProto();
    __jsb_cocostudio_Skin_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_ComAttribute_proto = nullptr;
se::Class* __jsb_cocostudio_ComAttribute_class = nullptr;

static bool js_cocos2dx_studio_ComAttribute_getFloat(se::State& s)
{
    cocostudio::ComAttribute* cobj = (cocostudio::ComAttribute*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAttribute_getFloat : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getFloat : Error processing arguments");
        float result = cobj->getFloat(arg0);
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getFloat : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        float arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getFloat : Error processing arguments");
        float result = cobj->getFloat(arg0, arg1);
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getFloat : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAttribute_getFloat)

static bool js_cocos2dx_studio_ComAttribute_getBool(se::State& s)
{
    cocostudio::ComAttribute* cobj = (cocostudio::ComAttribute*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAttribute_getBool : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getBool : Error processing arguments");
        bool result = cobj->getBool(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getBool : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getBool : Error processing arguments");
        bool result = cobj->getBool(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getBool : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAttribute_getBool)

static bool js_cocos2dx_studio_ComAttribute_getString(se::State& s)
{
    cocostudio::ComAttribute* cobj = (cocostudio::ComAttribute*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAttribute_getString : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getString : Error processing arguments");
        std::string result = cobj->getString(arg0);
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getString : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getString : Error processing arguments");
        std::string result = cobj->getString(arg0, arg1);
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getString : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAttribute_getString)

static bool js_cocos2dx_studio_ComAttribute_setFloat(se::State& s)
{
    cocostudio::ComAttribute* cobj = (cocostudio::ComAttribute*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAttribute_setFloat : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        float arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_setFloat : Error processing arguments");
        cobj->setFloat(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAttribute_setFloat)

static bool js_cocos2dx_studio_ComAttribute_setString(se::State& s)
{
    cocostudio::ComAttribute* cobj = (cocostudio::ComAttribute*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAttribute_setString : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_setString : Error processing arguments");
        cobj->setString(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAttribute_setString)

static bool js_cocos2dx_studio_ComAttribute_setInt(se::State& s)
{
    cocostudio::ComAttribute* cobj = (cocostudio::ComAttribute*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAttribute_setInt : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_setInt : Error processing arguments");
        cobj->setInt(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAttribute_setInt)

static bool js_cocos2dx_studio_ComAttribute_parse(se::State& s)
{
    cocostudio::ComAttribute* cobj = (cocostudio::ComAttribute*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAttribute_parse : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_parse : Error processing arguments");
        bool result = cobj->parse(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_parse : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAttribute_parse)

static bool js_cocos2dx_studio_ComAttribute_getInt(se::State& s)
{
    cocostudio::ComAttribute* cobj = (cocostudio::ComAttribute*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAttribute_getInt : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getInt : Error processing arguments");
        int result = cobj->getInt(arg0);
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getInt : Error processing arguments");
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getInt : Error processing arguments");
        int result = cobj->getInt(arg0, arg1);
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_getInt : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAttribute_getInt)

static bool js_cocos2dx_studio_ComAttribute_setBool(se::State& s)
{
    cocostudio::ComAttribute* cobj = (cocostudio::ComAttribute*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAttribute_setBool : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAttribute_setBool : Error processing arguments");
        cobj->setBool(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAttribute_setBool)

static bool js_cocos2dx_studio_ComAttribute_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::ComAttribute::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_ComAttribute_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAttribute_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_ComAttribute_finalize)

static bool js_cocos2dx_studio_ComAttribute_constructor(se::State& s)
{
    cocostudio::ComAttribute* cobj = new (std::nothrow) cocostudio::ComAttribute();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ComAttribute_constructor, __jsb_cocostudio_ComAttribute_class, js_cocostudio_ComAttribute_finalize)



extern se::Object* __jsb_cocos2d_Component_proto;

bool js_cocostudio_ComAttribute_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::ComAttribute)", s.nativeThisObject());
        cocostudio::ComAttribute* cobj = (cocostudio::ComAttribute*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_ComAttribute_finalize)

bool js_register_cocos2dx_studio_ComAttribute(se::Object* obj)
{
    auto cls = se::Class::create("ComAttribute", obj, __jsb_cocos2d_Component_proto, _SE(js_cocos2dx_studio_ComAttribute_constructor));

    cls->defineFunction("getFloat", _SE(js_cocos2dx_studio_ComAttribute_getFloat));
    cls->defineFunction("getBool", _SE(js_cocos2dx_studio_ComAttribute_getBool));
    cls->defineFunction("getString", _SE(js_cocos2dx_studio_ComAttribute_getString));
    cls->defineFunction("setFloat", _SE(js_cocos2dx_studio_ComAttribute_setFloat));
    cls->defineFunction("setString", _SE(js_cocos2dx_studio_ComAttribute_setString));
    cls->defineFunction("setInt", _SE(js_cocos2dx_studio_ComAttribute_setInt));
    cls->defineFunction("parse", _SE(js_cocos2dx_studio_ComAttribute_parse));
    cls->defineFunction("getInt", _SE(js_cocos2dx_studio_ComAttribute_getInt));
    cls->defineFunction("setBool", _SE(js_cocos2dx_studio_ComAttribute_setBool));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ComAttribute_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_ComAttribute_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::ComAttribute>(cls);

    __jsb_cocostudio_ComAttribute_proto = cls->getProto();
    __jsb_cocostudio_ComAttribute_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_ComAudio_proto = nullptr;
se::Class* __jsb_cocostudio_ComAudio_class = nullptr;

static bool js_cocos2dx_studio_ComAudio_stopAllEffects(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_stopAllEffects : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stopAllEffects();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_stopAllEffects)

static bool js_cocos2dx_studio_ComAudio_getEffectsVolume(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_getEffectsVolume : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getEffectsVolume();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_getEffectsVolume : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_getEffectsVolume)

static bool js_cocos2dx_studio_ComAudio_stopEffect(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_stopEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_stopEffect : Error processing arguments");
        cobj->stopEffect(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_stopEffect)

static bool js_cocos2dx_studio_ComAudio_getBackgroundMusicVolume(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_getBackgroundMusicVolume : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getBackgroundMusicVolume();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_getBackgroundMusicVolume : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_getBackgroundMusicVolume)

static bool js_cocos2dx_studio_ComAudio_willPlayBackgroundMusic(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_willPlayBackgroundMusic : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->willPlayBackgroundMusic();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_willPlayBackgroundMusic : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_willPlayBackgroundMusic)

static bool js_cocos2dx_studio_ComAudio_setBackgroundMusicVolume(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_setBackgroundMusicVolume : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_setBackgroundMusicVolume : Error processing arguments");
        cobj->setBackgroundMusicVolume(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_setBackgroundMusicVolume)

static bool js_cocos2dx_studio_ComAudio_end(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_end : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->end();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_end)

static bool js_cocos2dx_studio_ComAudio_start(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_start : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->start();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_start)

static bool js_cocos2dx_studio_ComAudio_stopBackgroundMusic(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_ComAudio_stopBackgroundMusic : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 0) {
            cobj->stopBackgroundMusic();
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            bool arg0;
            ok &= seval_to_boolean(args[0], &arg0);
            cobj->stopBackgroundMusic(arg0);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_stopBackgroundMusic)

static bool js_cocos2dx_studio_ComAudio_pauseBackgroundMusic(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_pauseBackgroundMusic : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->pauseBackgroundMusic();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_pauseBackgroundMusic)

static bool js_cocos2dx_studio_ComAudio_isBackgroundMusicPlaying(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_isBackgroundMusicPlaying : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isBackgroundMusicPlaying();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_isBackgroundMusicPlaying : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_isBackgroundMusicPlaying)

static bool js_cocos2dx_studio_ComAudio_isLoop(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_isLoop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isLoop();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_isLoop : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_isLoop)

static bool js_cocos2dx_studio_ComAudio_resumeAllEffects(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_resumeAllEffects : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->resumeAllEffects();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_resumeAllEffects)

static bool js_cocos2dx_studio_ComAudio_pauseAllEffects(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_pauseAllEffects : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->pauseAllEffects();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_pauseAllEffects)

static bool js_cocos2dx_studio_ComAudio_preloadBackgroundMusic(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_preloadBackgroundMusic : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_preloadBackgroundMusic : Error processing arguments");
        cobj->preloadBackgroundMusic(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_preloadBackgroundMusic)

static bool js_cocos2dx_studio_ComAudio_playBackgroundMusic(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_ComAudio_playBackgroundMusic : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            cobj->playBackgroundMusic(arg0);
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            bool arg1;
            ok &= seval_to_boolean(args[1], &arg1);
            cobj->playBackgroundMusic(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 0) {
            cobj->playBackgroundMusic();
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_playBackgroundMusic)

static bool js_cocos2dx_studio_ComAudio_stop(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_stop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stop();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_stop)

static bool js_cocos2dx_studio_ComAudio_playEffect(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_ComAudio_playEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            unsigned int result = cobj->playEffect(arg0);
            ok &= uint32_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_playEffect : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            bool arg1;
            ok &= seval_to_boolean(args[1], &arg1);
            unsigned int result = cobj->playEffect(arg0, arg1);
            ok &= uint32_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_playEffect : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 0) {
            unsigned int result = cobj->playEffect();
            ok &= uint32_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_playEffect : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_playEffect)

static bool js_cocos2dx_studio_ComAudio_preloadEffect(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_preloadEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_preloadEffect : Error processing arguments");
        cobj->preloadEffect(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_preloadEffect)

static bool js_cocos2dx_studio_ComAudio_setLoop(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_setLoop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_setLoop : Error processing arguments");
        cobj->setLoop(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_setLoop)

static bool js_cocos2dx_studio_ComAudio_unloadEffect(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_unloadEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_unloadEffect : Error processing arguments");
        cobj->unloadEffect(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_unloadEffect)

static bool js_cocos2dx_studio_ComAudio_rewindBackgroundMusic(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_rewindBackgroundMusic : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->rewindBackgroundMusic();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_rewindBackgroundMusic)

static bool js_cocos2dx_studio_ComAudio_pauseEffect(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_pauseEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_pauseEffect : Error processing arguments");
        cobj->pauseEffect(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_pauseEffect)

static bool js_cocos2dx_studio_ComAudio_resumeBackgroundMusic(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_resumeBackgroundMusic : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->resumeBackgroundMusic();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_resumeBackgroundMusic)

static bool js_cocos2dx_studio_ComAudio_setFile(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_setFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_setFile : Error processing arguments");
        cobj->setFile(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_setFile)

static bool js_cocos2dx_studio_ComAudio_setEffectsVolume(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_setEffectsVolume : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_setEffectsVolume : Error processing arguments");
        cobj->setEffectsVolume(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_setEffectsVolume)

static bool js_cocos2dx_studio_ComAudio_getFile(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_getFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const char* result = cobj->getFile();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_getFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_getFile)

static bool js_cocos2dx_studio_ComAudio_resumeEffect(se::State& s)
{
    cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComAudio_resumeEffect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComAudio_resumeEffect : Error processing arguments");
        cobj->resumeEffect(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_resumeEffect)

static bool js_cocos2dx_studio_ComAudio_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::ComAudio::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_ComAudio_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComAudio_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_ComAudio_finalize)

static bool js_cocos2dx_studio_ComAudio_constructor(se::State& s)
{
    cocostudio::ComAudio* cobj = new (std::nothrow) cocostudio::ComAudio();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ComAudio_constructor, __jsb_cocostudio_ComAudio_class, js_cocostudio_ComAudio_finalize)



extern se::Object* __jsb_cocos2d_Component_proto;

bool js_cocostudio_ComAudio_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::ComAudio)", s.nativeThisObject());
        cocostudio::ComAudio* cobj = (cocostudio::ComAudio*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_ComAudio_finalize)

bool js_register_cocos2dx_studio_ComAudio(se::Object* obj)
{
    auto cls = se::Class::create("ComAudio", obj, __jsb_cocos2d_Component_proto, _SE(js_cocos2dx_studio_ComAudio_constructor));

    cls->defineFunction("stopAllEffects", _SE(js_cocos2dx_studio_ComAudio_stopAllEffects));
    cls->defineFunction("getEffectsVolume", _SE(js_cocos2dx_studio_ComAudio_getEffectsVolume));
    cls->defineFunction("stopEffect", _SE(js_cocos2dx_studio_ComAudio_stopEffect));
    cls->defineFunction("getBackgroundMusicVolume", _SE(js_cocos2dx_studio_ComAudio_getBackgroundMusicVolume));
    cls->defineFunction("willPlayBackgroundMusic", _SE(js_cocos2dx_studio_ComAudio_willPlayBackgroundMusic));
    cls->defineFunction("setBackgroundMusicVolume", _SE(js_cocos2dx_studio_ComAudio_setBackgroundMusicVolume));
    cls->defineFunction("end", _SE(js_cocos2dx_studio_ComAudio_end));
    cls->defineFunction("start", _SE(js_cocos2dx_studio_ComAudio_start));
    cls->defineFunction("stopBackgroundMusic", _SE(js_cocos2dx_studio_ComAudio_stopBackgroundMusic));
    cls->defineFunction("pauseBackgroundMusic", _SE(js_cocos2dx_studio_ComAudio_pauseBackgroundMusic));
    cls->defineFunction("isBackgroundMusicPlaying", _SE(js_cocos2dx_studio_ComAudio_isBackgroundMusicPlaying));
    cls->defineFunction("isLoop", _SE(js_cocos2dx_studio_ComAudio_isLoop));
    cls->defineFunction("resumeAllEffects", _SE(js_cocos2dx_studio_ComAudio_resumeAllEffects));
    cls->defineFunction("pauseAllEffects", _SE(js_cocos2dx_studio_ComAudio_pauseAllEffects));
    cls->defineFunction("preloadBackgroundMusic", _SE(js_cocos2dx_studio_ComAudio_preloadBackgroundMusic));
    cls->defineFunction("playBackgroundMusic", _SE(js_cocos2dx_studio_ComAudio_playBackgroundMusic));
    cls->defineFunction("stop", _SE(js_cocos2dx_studio_ComAudio_stop));
    cls->defineFunction("playEffect", _SE(js_cocos2dx_studio_ComAudio_playEffect));
    cls->defineFunction("preloadEffect", _SE(js_cocos2dx_studio_ComAudio_preloadEffect));
    cls->defineFunction("setLoop", _SE(js_cocos2dx_studio_ComAudio_setLoop));
    cls->defineFunction("unloadEffect", _SE(js_cocos2dx_studio_ComAudio_unloadEffect));
    cls->defineFunction("rewindBackgroundMusic", _SE(js_cocos2dx_studio_ComAudio_rewindBackgroundMusic));
    cls->defineFunction("pauseEffect", _SE(js_cocos2dx_studio_ComAudio_pauseEffect));
    cls->defineFunction("resumeBackgroundMusic", _SE(js_cocos2dx_studio_ComAudio_resumeBackgroundMusic));
    cls->defineFunction("setFile", _SE(js_cocos2dx_studio_ComAudio_setFile));
    cls->defineFunction("setEffectsVolume", _SE(js_cocos2dx_studio_ComAudio_setEffectsVolume));
    cls->defineFunction("getFile", _SE(js_cocos2dx_studio_ComAudio_getFile));
    cls->defineFunction("resumeEffect", _SE(js_cocos2dx_studio_ComAudio_resumeEffect));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ComAudio_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_ComAudio_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::ComAudio>(cls);

    __jsb_cocostudio_ComAudio_proto = cls->getProto();
    __jsb_cocostudio_ComAudio_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_InputDelegate_proto = nullptr;
se::Class* __jsb_cocostudio_InputDelegate_class = nullptr;

static bool js_cocos2dx_studio_InputDelegate_isAccelerometerEnabled(se::State& s)
{
    cocostudio::InputDelegate* cobj = (cocostudio::InputDelegate*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InputDelegate_isAccelerometerEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isAccelerometerEnabled();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InputDelegate_isAccelerometerEnabled : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InputDelegate_isAccelerometerEnabled)

static bool js_cocos2dx_studio_InputDelegate_setKeypadEnabled(se::State& s)
{
    cocostudio::InputDelegate* cobj = (cocostudio::InputDelegate*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InputDelegate_setKeypadEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InputDelegate_setKeypadEnabled : Error processing arguments");
        cobj->setKeypadEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InputDelegate_setKeypadEnabled)

static bool js_cocos2dx_studio_InputDelegate_getTouchMode(se::State& s)
{
    cocostudio::InputDelegate* cobj = (cocostudio::InputDelegate*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InputDelegate_getTouchMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getTouchMode();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InputDelegate_getTouchMode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InputDelegate_getTouchMode)

static bool js_cocos2dx_studio_InputDelegate_setAccelerometerEnabled(se::State& s)
{
    cocostudio::InputDelegate* cobj = (cocostudio::InputDelegate*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InputDelegate_setAccelerometerEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InputDelegate_setAccelerometerEnabled : Error processing arguments");
        cobj->setAccelerometerEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InputDelegate_setAccelerometerEnabled)

static bool js_cocos2dx_studio_InputDelegate_isKeypadEnabled(se::State& s)
{
    cocostudio::InputDelegate* cobj = (cocostudio::InputDelegate*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InputDelegate_isKeypadEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isKeypadEnabled();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InputDelegate_isKeypadEnabled : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InputDelegate_isKeypadEnabled)

static bool js_cocos2dx_studio_InputDelegate_isTouchEnabled(se::State& s)
{
    cocostudio::InputDelegate* cobj = (cocostudio::InputDelegate*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InputDelegate_isTouchEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isTouchEnabled();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InputDelegate_isTouchEnabled : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InputDelegate_isTouchEnabled)

static bool js_cocos2dx_studio_InputDelegate_setTouchPriority(se::State& s)
{
    cocostudio::InputDelegate* cobj = (cocostudio::InputDelegate*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InputDelegate_setTouchPriority : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InputDelegate_setTouchPriority : Error processing arguments");
        cobj->setTouchPriority(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InputDelegate_setTouchPriority)

static bool js_cocos2dx_studio_InputDelegate_getTouchPriority(se::State& s)
{
    cocostudio::InputDelegate* cobj = (cocostudio::InputDelegate*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InputDelegate_getTouchPriority : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getTouchPriority();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InputDelegate_getTouchPriority : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InputDelegate_getTouchPriority)

static bool js_cocos2dx_studio_InputDelegate_setTouchEnabled(se::State& s)
{
    cocostudio::InputDelegate* cobj = (cocostudio::InputDelegate*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InputDelegate_setTouchEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InputDelegate_setTouchEnabled : Error processing arguments");
        cobj->setTouchEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InputDelegate_setTouchEnabled)

static bool js_cocos2dx_studio_InputDelegate_setTouchMode(se::State& s)
{
    cocostudio::InputDelegate* cobj = (cocostudio::InputDelegate*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InputDelegate_setTouchMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Touch::DispatchMode arg0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InputDelegate_setTouchMode : Error processing arguments");
        cobj->setTouchMode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InputDelegate_setTouchMode)




bool js_register_cocos2dx_studio_InputDelegate(se::Object* obj)
{
    auto cls = se::Class::create("InputDelegate", obj, nullptr, nullptr);

    cls->defineFunction("isAccelerometerEnabled", _SE(js_cocos2dx_studio_InputDelegate_isAccelerometerEnabled));
    cls->defineFunction("setKeypadEnabled", _SE(js_cocos2dx_studio_InputDelegate_setKeypadEnabled));
    cls->defineFunction("getTouchMode", _SE(js_cocos2dx_studio_InputDelegate_getTouchMode));
    cls->defineFunction("setAccelerometerEnabled", _SE(js_cocos2dx_studio_InputDelegate_setAccelerometerEnabled));
    cls->defineFunction("isKeypadEnabled", _SE(js_cocos2dx_studio_InputDelegate_isKeypadEnabled));
    cls->defineFunction("isTouchEnabled", _SE(js_cocos2dx_studio_InputDelegate_isTouchEnabled));
    cls->defineFunction("setTouchPriority", _SE(js_cocos2dx_studio_InputDelegate_setTouchPriority));
    cls->defineFunction("getTouchPriority", _SE(js_cocos2dx_studio_InputDelegate_getTouchPriority));
    cls->defineFunction("setTouchEnabled", _SE(js_cocos2dx_studio_InputDelegate_setTouchEnabled));
    cls->defineFunction("setTouchMode", _SE(js_cocos2dx_studio_InputDelegate_setTouchMode));
    cls->install();
    JSBClassType::registerClass<cocostudio::InputDelegate>(cls);

    __jsb_cocostudio_InputDelegate_proto = cls->getProto();
    __jsb_cocostudio_InputDelegate_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_ComController_proto = nullptr;
se::Class* __jsb_cocostudio_ComController_class = nullptr;

static bool js_cocos2dx_studio_ComController_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::ComController::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_ComController_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComController_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_ComController_finalize)

static bool js_cocos2dx_studio_ComController_constructor(se::State& s)
{
    cocostudio::ComController* cobj = new (std::nothrow) cocostudio::ComController();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ComController_constructor, __jsb_cocostudio_ComController_class, js_cocostudio_ComController_finalize)

static bool js_cocos2dx_studio_ComController_ctor(se::State& s)
{
    cocostudio::ComController* cobj = new (std::nothrow) cocostudio::ComController();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_SUB_CLS_CTOR(js_cocos2dx_studio_ComController_ctor, __jsb_cocostudio_ComController_class, js_cocostudio_ComController_finalize)


    

extern se::Object* __jsb_cocos2d_Component_proto;

bool js_cocostudio_ComController_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::ComController)", s.nativeThisObject());
        cocostudio::ComController* cobj = (cocostudio::ComController*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_ComController_finalize)

bool js_register_cocos2dx_studio_ComController(se::Object* obj)
{
    auto cls = se::Class::create("ComController", obj, __jsb_cocos2d_Component_proto, _SE(js_cocos2dx_studio_ComController_constructor));

    cls->defineFunction("ctor", _SE(js_cocos2dx_studio_ComController_ctor));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ComController_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_ComController_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::ComController>(cls);

    __jsb_cocostudio_ComController_proto = cls->getProto();
    __jsb_cocostudio_ComController_class = cls;

    se::ScriptEngine::getInstance()->executeScriptBuffer("(function () { ccs.ComController.extend = cc.Class.extend; })()");
    return true;
}

se::Object* __jsb_cocostudio_ComRender_proto = nullptr;
se::Class* __jsb_cocostudio_ComRender_class = nullptr;

static bool js_cocos2dx_studio_ComRender_setNode(se::State& s)
{
    cocostudio::ComRender* cobj = (cocostudio::ComRender*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComRender_setNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Node* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComRender_setNode : Error processing arguments");
        cobj->setNode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComRender_setNode)

static bool js_cocos2dx_studio_ComRender_getNode(se::State& s)
{
    cocostudio::ComRender* cobj = (cocostudio::ComRender*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComRender_getNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Node* result = cobj->getNode();
        ok &= native_ptr_to_seval<cocos2d::Node>((cocos2d::Node*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComRender_getNode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComRender_getNode)

static bool js_cocos2dx_studio_ComRender_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            cocos2d::Node* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            const char* arg1 = nullptr;
            std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { ok = true; break; }
            cocostudio::ComRender* result = cocostudio::ComRender::create(arg0, arg1);
            ok &= native_ptr_to_seval<cocostudio::ComRender>((cocostudio::ComRender*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComRender_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            cocostudio::ComRender* result = cocostudio::ComRender::create();
            ok &= native_ptr_to_seval<cocostudio::ComRender>((cocostudio::ComRender*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComRender_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComRender_create)

static bool js_cocos2dx_studio_ComRender_constructor(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::ComRender* cobj = (cocostudio::ComRender*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_ComRender_constructor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            cocos2d::Node* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            const char* arg1 = nullptr;
            std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { ok = true; break; }
            cobj->ComRender(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 0) {
            cobj->ComRender();
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComRender_constructor)



extern se::Object* __jsb_cocos2d_Component_proto;

bool js_cocostudio_ComRender_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::ComRender)", s.nativeThisObject());
        cocostudio::ComRender* cobj = (cocostudio::ComRender*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_ComRender_finalize)

bool js_register_cocos2dx_studio_ComRender(se::Object* obj)
{
    auto cls = se::Class::create("ComRender", obj, __jsb_cocos2d_Component_proto, _SE(js_cocos2dx_studio_ComRender_constructor));

    cls->defineFunction("setNode", _SE(js_cocos2dx_studio_ComRender_setNode));
    cls->defineFunction("getNode", _SE(js_cocos2dx_studio_ComRender_getNode));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ComRender_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_ComRender_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::ComRender>(cls);

    __jsb_cocostudio_ComRender_proto = cls->getProto();
    __jsb_cocostudio_ComRender_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_Frame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_Frame_class = nullptr;

static bool js_cocos2dx_studio_Frame_clone(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_clone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::timeline::Frame* result = cobj->clone();
        ok &= native_ptr_to_seval<cocostudio::timeline::Frame>((cocostudio::timeline::Frame*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_clone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_clone)

static bool js_cocos2dx_studio_Frame_setTweenType(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_setTweenType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::tweenfunc::TweenType arg0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_setTweenType : Error processing arguments");
        cobj->setTweenType(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_setTweenType)

static bool js_cocos2dx_studio_Frame_setNode(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_setNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Node* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_setNode : Error processing arguments");
        cobj->setNode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_setNode)

static bool js_cocos2dx_studio_Frame_setTimeline(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_setTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::timeline::Timeline* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_setTimeline : Error processing arguments");
        cobj->setTimeline(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_setTimeline)

static bool js_cocos2dx_studio_Frame_isEnterWhenPassed(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_isEnterWhenPassed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isEnterWhenPassed();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_isEnterWhenPassed : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_isEnterWhenPassed)

static bool js_cocos2dx_studio_Frame_getTweenType(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_getTweenType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getTweenType();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_getTweenType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_getTweenType)

static bool js_cocos2dx_studio_Frame_getFrameIndex(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_getFrameIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getFrameIndex();
        ok &= uint32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_getFrameIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_getFrameIndex)

static bool js_cocos2dx_studio_Frame_apply(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_apply : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_apply : Error processing arguments");
        cobj->apply(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_apply)

static bool js_cocos2dx_studio_Frame_isTween(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_isTween : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isTween();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_isTween : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_isTween)

static bool js_cocos2dx_studio_Frame_setFrameIndex(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_setFrameIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_setFrameIndex : Error processing arguments");
        cobj->setFrameIndex(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_setFrameIndex)

static bool js_cocos2dx_studio_Frame_setTween(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_setTween : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_setTween : Error processing arguments");
        cobj->setTween(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_setTween)

static bool js_cocos2dx_studio_Frame_getTimeline(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_getTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::timeline::Timeline* result = cobj->getTimeline();
        ok &= native_ptr_to_seval<cocostudio::timeline::Timeline>((cocostudio::timeline::Timeline*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_getTimeline : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_getTimeline)

static bool js_cocos2dx_studio_Frame_getNode(se::State& s)
{
    cocostudio::timeline::Frame* cobj = (cocostudio::timeline::Frame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Frame_getNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Node* result = cobj->getNode();
        ok &= native_ptr_to_seval<cocos2d::Node>((cocos2d::Node*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Frame_getNode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Frame_getNode)




bool js_register_cocos2dx_studio_Frame(se::Object* obj)
{
    auto cls = se::Class::create("Frame", obj, nullptr, nullptr);

    cls->defineFunction("clone", _SE(js_cocos2dx_studio_Frame_clone));
    cls->defineFunction("setTweenType", _SE(js_cocos2dx_studio_Frame_setTweenType));
    cls->defineFunction("setNode", _SE(js_cocos2dx_studio_Frame_setNode));
    cls->defineFunction("setTimeline", _SE(js_cocos2dx_studio_Frame_setTimeline));
    cls->defineFunction("isEnterWhenPassed", _SE(js_cocos2dx_studio_Frame_isEnterWhenPassed));
    cls->defineFunction("getTweenType", _SE(js_cocos2dx_studio_Frame_getTweenType));
    cls->defineFunction("getFrameIndex", _SE(js_cocos2dx_studio_Frame_getFrameIndex));
    cls->defineFunction("apply", _SE(js_cocos2dx_studio_Frame_apply));
    cls->defineFunction("isTween", _SE(js_cocos2dx_studio_Frame_isTween));
    cls->defineFunction("setFrameIndex", _SE(js_cocos2dx_studio_Frame_setFrameIndex));
    cls->defineFunction("setTween", _SE(js_cocos2dx_studio_Frame_setTween));
    cls->defineFunction("getTimeline", _SE(js_cocos2dx_studio_Frame_getTimeline));
    cls->defineFunction("getNode", _SE(js_cocos2dx_studio_Frame_getNode));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::Frame>(cls);

    __jsb_cocostudio_timeline_Frame_proto = cls->getProto();
    __jsb_cocostudio_timeline_Frame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_VisibleFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_VisibleFrame_class = nullptr;

static bool js_cocos2dx_studio_VisibleFrame_isVisible(se::State& s)
{
    cocostudio::timeline::VisibleFrame* cobj = (cocostudio::timeline::VisibleFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_VisibleFrame_isVisible : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isVisible();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_VisibleFrame_isVisible : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_VisibleFrame_isVisible)

static bool js_cocos2dx_studio_VisibleFrame_setVisible(se::State& s)
{
    cocostudio::timeline::VisibleFrame* cobj = (cocostudio::timeline::VisibleFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_VisibleFrame_setVisible : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_VisibleFrame_setVisible : Error processing arguments");
        cobj->setVisible(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_VisibleFrame_setVisible)

static bool js_cocos2dx_studio_VisibleFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::VisibleFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_VisibleFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_VisibleFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_VisibleFrame_finalize)

static bool js_cocos2dx_studio_VisibleFrame_constructor(se::State& s)
{
    cocostudio::timeline::VisibleFrame* cobj = new (std::nothrow) cocostudio::timeline::VisibleFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_VisibleFrame_constructor, __jsb_cocostudio_timeline_VisibleFrame_class, js_cocostudio_timeline_VisibleFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_VisibleFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::VisibleFrame)", s.nativeThisObject());
        cocostudio::timeline::VisibleFrame* cobj = (cocostudio::timeline::VisibleFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_VisibleFrame_finalize)

bool js_register_cocos2dx_studio_VisibleFrame(se::Object* obj)
{
    auto cls = se::Class::create("VisibleFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_VisibleFrame_constructor));

    cls->defineFunction("isVisible", _SE(js_cocos2dx_studio_VisibleFrame_isVisible));
    cls->defineFunction("setVisible", _SE(js_cocos2dx_studio_VisibleFrame_setVisible));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_VisibleFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_VisibleFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::VisibleFrame>(cls);

    __jsb_cocostudio_timeline_VisibleFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_VisibleFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_TextureFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_TextureFrame_class = nullptr;

static bool js_cocos2dx_studio_TextureFrame_getTextureName(se::State& s)
{
    cocostudio::timeline::TextureFrame* cobj = (cocostudio::timeline::TextureFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_TextureFrame_getTextureName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = cobj->getTextureName();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_TextureFrame_getTextureName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_TextureFrame_getTextureName)

static bool js_cocos2dx_studio_TextureFrame_setTextureName(se::State& s)
{
    cocostudio::timeline::TextureFrame* cobj = (cocostudio::timeline::TextureFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_TextureFrame_setTextureName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_TextureFrame_setTextureName : Error processing arguments");
        cobj->setTextureName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_TextureFrame_setTextureName)

static bool js_cocos2dx_studio_TextureFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::TextureFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_TextureFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_TextureFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_TextureFrame_finalize)

static bool js_cocos2dx_studio_TextureFrame_constructor(se::State& s)
{
    cocostudio::timeline::TextureFrame* cobj = new (std::nothrow) cocostudio::timeline::TextureFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_TextureFrame_constructor, __jsb_cocostudio_timeline_TextureFrame_class, js_cocostudio_timeline_TextureFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_TextureFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::TextureFrame)", s.nativeThisObject());
        cocostudio::timeline::TextureFrame* cobj = (cocostudio::timeline::TextureFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_TextureFrame_finalize)

bool js_register_cocos2dx_studio_TextureFrame(se::Object* obj)
{
    auto cls = se::Class::create("TextureFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_TextureFrame_constructor));

    cls->defineFunction("getTextureName", _SE(js_cocos2dx_studio_TextureFrame_getTextureName));
    cls->defineFunction("setTextureName", _SE(js_cocos2dx_studio_TextureFrame_setTextureName));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_TextureFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_TextureFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::TextureFrame>(cls);

    __jsb_cocostudio_timeline_TextureFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_TextureFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_RotationFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_RotationFrame_class = nullptr;

static bool js_cocos2dx_studio_RotationFrame_setRotation(se::State& s)
{
    cocostudio::timeline::RotationFrame* cobj = (cocostudio::timeline::RotationFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_RotationFrame_setRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_RotationFrame_setRotation : Error processing arguments");
        cobj->setRotation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_RotationFrame_setRotation)

static bool js_cocos2dx_studio_RotationFrame_getRotation(se::State& s)
{
    cocostudio::timeline::RotationFrame* cobj = (cocostudio::timeline::RotationFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_RotationFrame_getRotation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRotation();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_RotationFrame_getRotation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_RotationFrame_getRotation)

static bool js_cocos2dx_studio_RotationFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::RotationFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_RotationFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_RotationFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_RotationFrame_finalize)

static bool js_cocos2dx_studio_RotationFrame_constructor(se::State& s)
{
    cocostudio::timeline::RotationFrame* cobj = new (std::nothrow) cocostudio::timeline::RotationFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_RotationFrame_constructor, __jsb_cocostudio_timeline_RotationFrame_class, js_cocostudio_timeline_RotationFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_RotationFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::RotationFrame)", s.nativeThisObject());
        cocostudio::timeline::RotationFrame* cobj = (cocostudio::timeline::RotationFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_RotationFrame_finalize)

bool js_register_cocos2dx_studio_RotationFrame(se::Object* obj)
{
    auto cls = se::Class::create("RotationFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_RotationFrame_constructor));

    cls->defineFunction("setRotation", _SE(js_cocos2dx_studio_RotationFrame_setRotation));
    cls->defineFunction("getRotation", _SE(js_cocos2dx_studio_RotationFrame_getRotation));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_RotationFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_RotationFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::RotationFrame>(cls);

    __jsb_cocostudio_timeline_RotationFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_RotationFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_SkewFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_SkewFrame_class = nullptr;

static bool js_cocos2dx_studio_SkewFrame_getSkewY(se::State& s)
{
    cocostudio::timeline::SkewFrame* cobj = (cocostudio::timeline::SkewFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_SkewFrame_getSkewY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSkewY();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_SkewFrame_getSkewY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_SkewFrame_getSkewY)

static bool js_cocos2dx_studio_SkewFrame_setSkewX(se::State& s)
{
    cocostudio::timeline::SkewFrame* cobj = (cocostudio::timeline::SkewFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_SkewFrame_setSkewX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_SkewFrame_setSkewX : Error processing arguments");
        cobj->setSkewX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_SkewFrame_setSkewX)

static bool js_cocos2dx_studio_SkewFrame_setSkewY(se::State& s)
{
    cocostudio::timeline::SkewFrame* cobj = (cocostudio::timeline::SkewFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_SkewFrame_setSkewY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_SkewFrame_setSkewY : Error processing arguments");
        cobj->setSkewY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_SkewFrame_setSkewY)

static bool js_cocos2dx_studio_SkewFrame_getSkewX(se::State& s)
{
    cocostudio::timeline::SkewFrame* cobj = (cocostudio::timeline::SkewFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_SkewFrame_getSkewX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSkewX();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_SkewFrame_getSkewX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_SkewFrame_getSkewX)

static bool js_cocos2dx_studio_SkewFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::SkewFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_SkewFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_SkewFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_SkewFrame_finalize)

static bool js_cocos2dx_studio_SkewFrame_constructor(se::State& s)
{
    cocostudio::timeline::SkewFrame* cobj = new (std::nothrow) cocostudio::timeline::SkewFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_SkewFrame_constructor, __jsb_cocostudio_timeline_SkewFrame_class, js_cocostudio_timeline_SkewFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_SkewFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::SkewFrame)", s.nativeThisObject());
        cocostudio::timeline::SkewFrame* cobj = (cocostudio::timeline::SkewFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_SkewFrame_finalize)

bool js_register_cocos2dx_studio_SkewFrame(se::Object* obj)
{
    auto cls = se::Class::create("SkewFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_SkewFrame_constructor));

    cls->defineFunction("getSkewY", _SE(js_cocos2dx_studio_SkewFrame_getSkewY));
    cls->defineFunction("setSkewX", _SE(js_cocos2dx_studio_SkewFrame_setSkewX));
    cls->defineFunction("setSkewY", _SE(js_cocos2dx_studio_SkewFrame_setSkewY));
    cls->defineFunction("getSkewX", _SE(js_cocos2dx_studio_SkewFrame_getSkewX));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_SkewFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_SkewFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::SkewFrame>(cls);

    __jsb_cocostudio_timeline_SkewFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_SkewFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_RotationSkewFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_RotationSkewFrame_class = nullptr;

static bool js_cocos2dx_studio_RotationSkewFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::RotationSkewFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_RotationSkewFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_RotationSkewFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_RotationSkewFrame_finalize)

static bool js_cocos2dx_studio_RotationSkewFrame_constructor(se::State& s)
{
    cocostudio::timeline::RotationSkewFrame* cobj = new (std::nothrow) cocostudio::timeline::RotationSkewFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_RotationSkewFrame_constructor, __jsb_cocostudio_timeline_RotationSkewFrame_class, js_cocostudio_timeline_RotationSkewFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_SkewFrame_proto;

bool js_cocostudio_timeline_RotationSkewFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::RotationSkewFrame)", s.nativeThisObject());
        cocostudio::timeline::RotationSkewFrame* cobj = (cocostudio::timeline::RotationSkewFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_RotationSkewFrame_finalize)

bool js_register_cocos2dx_studio_RotationSkewFrame(se::Object* obj)
{
    auto cls = se::Class::create("RotationSkewFrame", obj, __jsb_cocostudio_timeline_SkewFrame_proto, _SE(js_cocos2dx_studio_RotationSkewFrame_constructor));

    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_RotationSkewFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_RotationSkewFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::RotationSkewFrame>(cls);

    __jsb_cocostudio_timeline_RotationSkewFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_RotationSkewFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_PositionFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_PositionFrame_class = nullptr;

static bool js_cocos2dx_studio_PositionFrame_getX(se::State& s)
{
    cocostudio::timeline::PositionFrame* cobj = (cocostudio::timeline::PositionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_PositionFrame_getX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getX();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_PositionFrame_getX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_PositionFrame_getX)

static bool js_cocos2dx_studio_PositionFrame_getY(se::State& s)
{
    cocostudio::timeline::PositionFrame* cobj = (cocostudio::timeline::PositionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_PositionFrame_getY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getY();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_PositionFrame_getY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_PositionFrame_getY)

static bool js_cocos2dx_studio_PositionFrame_setPosition(se::State& s)
{
    cocostudio::timeline::PositionFrame* cobj = (cocostudio::timeline::PositionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_PositionFrame_setPosition : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Point arg0;
        ok &= seval_to_Vec2(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_PositionFrame_setPosition : Error processing arguments");
        cobj->setPosition(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_PositionFrame_setPosition)

static bool js_cocos2dx_studio_PositionFrame_setX(se::State& s)
{
    cocostudio::timeline::PositionFrame* cobj = (cocostudio::timeline::PositionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_PositionFrame_setX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_PositionFrame_setX : Error processing arguments");
        cobj->setX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_PositionFrame_setX)

static bool js_cocos2dx_studio_PositionFrame_setY(se::State& s)
{
    cocostudio::timeline::PositionFrame* cobj = (cocostudio::timeline::PositionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_PositionFrame_setY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_PositionFrame_setY : Error processing arguments");
        cobj->setY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_PositionFrame_setY)

static bool js_cocos2dx_studio_PositionFrame_getPosition(se::State& s)
{
    cocostudio::timeline::PositionFrame* cobj = (cocostudio::timeline::PositionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_PositionFrame_getPosition : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Point result = cobj->getPosition();
        ok &= Vec2_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_PositionFrame_getPosition : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_PositionFrame_getPosition)

static bool js_cocos2dx_studio_PositionFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::PositionFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_PositionFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_PositionFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_PositionFrame_finalize)

static bool js_cocos2dx_studio_PositionFrame_constructor(se::State& s)
{
    cocostudio::timeline::PositionFrame* cobj = new (std::nothrow) cocostudio::timeline::PositionFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_PositionFrame_constructor, __jsb_cocostudio_timeline_PositionFrame_class, js_cocostudio_timeline_PositionFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_PositionFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::PositionFrame)", s.nativeThisObject());
        cocostudio::timeline::PositionFrame* cobj = (cocostudio::timeline::PositionFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_PositionFrame_finalize)

bool js_register_cocos2dx_studio_PositionFrame(se::Object* obj)
{
    auto cls = se::Class::create("PositionFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_PositionFrame_constructor));

    cls->defineFunction("getX", _SE(js_cocos2dx_studio_PositionFrame_getX));
    cls->defineFunction("getY", _SE(js_cocos2dx_studio_PositionFrame_getY));
    cls->defineFunction("setPosition", _SE(js_cocos2dx_studio_PositionFrame_setPosition));
    cls->defineFunction("setX", _SE(js_cocos2dx_studio_PositionFrame_setX));
    cls->defineFunction("setY", _SE(js_cocos2dx_studio_PositionFrame_setY));
    cls->defineFunction("getPosition", _SE(js_cocos2dx_studio_PositionFrame_getPosition));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_PositionFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_PositionFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::PositionFrame>(cls);

    __jsb_cocostudio_timeline_PositionFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_PositionFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_ScaleFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_ScaleFrame_class = nullptr;

static bool js_cocos2dx_studio_ScaleFrame_setScaleY(se::State& s)
{
    cocostudio::timeline::ScaleFrame* cobj = (cocostudio::timeline::ScaleFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ScaleFrame_setScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ScaleFrame_setScaleY : Error processing arguments");
        cobj->setScaleY(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ScaleFrame_setScaleY)

static bool js_cocos2dx_studio_ScaleFrame_setScaleX(se::State& s)
{
    cocostudio::timeline::ScaleFrame* cobj = (cocostudio::timeline::ScaleFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ScaleFrame_setScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ScaleFrame_setScaleX : Error processing arguments");
        cobj->setScaleX(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ScaleFrame_setScaleX)

static bool js_cocos2dx_studio_ScaleFrame_getScaleY(se::State& s)
{
    cocostudio::timeline::ScaleFrame* cobj = (cocostudio::timeline::ScaleFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ScaleFrame_getScaleY : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleY();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ScaleFrame_getScaleY : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ScaleFrame_getScaleY)

static bool js_cocos2dx_studio_ScaleFrame_getScaleX(se::State& s)
{
    cocostudio::timeline::ScaleFrame* cobj = (cocostudio::timeline::ScaleFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ScaleFrame_getScaleX : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getScaleX();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ScaleFrame_getScaleX : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ScaleFrame_getScaleX)

static bool js_cocos2dx_studio_ScaleFrame_setScale(se::State& s)
{
    cocostudio::timeline::ScaleFrame* cobj = (cocostudio::timeline::ScaleFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ScaleFrame_setScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ScaleFrame_setScale : Error processing arguments");
        cobj->setScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ScaleFrame_setScale)

static bool js_cocos2dx_studio_ScaleFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::ScaleFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_ScaleFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ScaleFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_ScaleFrame_finalize)

static bool js_cocos2dx_studio_ScaleFrame_constructor(se::State& s)
{
    cocostudio::timeline::ScaleFrame* cobj = new (std::nothrow) cocostudio::timeline::ScaleFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ScaleFrame_constructor, __jsb_cocostudio_timeline_ScaleFrame_class, js_cocostudio_timeline_ScaleFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_ScaleFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::ScaleFrame)", s.nativeThisObject());
        cocostudio::timeline::ScaleFrame* cobj = (cocostudio::timeline::ScaleFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_ScaleFrame_finalize)

bool js_register_cocos2dx_studio_ScaleFrame(se::Object* obj)
{
    auto cls = se::Class::create("ScaleFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_ScaleFrame_constructor));

    cls->defineFunction("setScaleY", _SE(js_cocos2dx_studio_ScaleFrame_setScaleY));
    cls->defineFunction("setScaleX", _SE(js_cocos2dx_studio_ScaleFrame_setScaleX));
    cls->defineFunction("getScaleY", _SE(js_cocos2dx_studio_ScaleFrame_getScaleY));
    cls->defineFunction("getScaleX", _SE(js_cocos2dx_studio_ScaleFrame_getScaleX));
    cls->defineFunction("setScale", _SE(js_cocos2dx_studio_ScaleFrame_setScale));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ScaleFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_ScaleFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::ScaleFrame>(cls);

    __jsb_cocostudio_timeline_ScaleFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_ScaleFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_AnchorPointFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_AnchorPointFrame_class = nullptr;

static bool js_cocos2dx_studio_AnchorPointFrame_setAnchorPoint(se::State& s)
{
    cocostudio::timeline::AnchorPointFrame* cobj = (cocostudio::timeline::AnchorPointFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_AnchorPointFrame_setAnchorPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Point arg0;
        ok &= seval_to_Vec2(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_AnchorPointFrame_setAnchorPoint : Error processing arguments");
        cobj->setAnchorPoint(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_AnchorPointFrame_setAnchorPoint)

static bool js_cocos2dx_studio_AnchorPointFrame_getAnchorPoint(se::State& s)
{
    cocostudio::timeline::AnchorPointFrame* cobj = (cocostudio::timeline::AnchorPointFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_AnchorPointFrame_getAnchorPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Point result = cobj->getAnchorPoint();
        ok &= Vec2_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_AnchorPointFrame_getAnchorPoint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_AnchorPointFrame_getAnchorPoint)

static bool js_cocos2dx_studio_AnchorPointFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::AnchorPointFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_AnchorPointFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_AnchorPointFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_AnchorPointFrame_finalize)

static bool js_cocos2dx_studio_AnchorPointFrame_constructor(se::State& s)
{
    cocostudio::timeline::AnchorPointFrame* cobj = new (std::nothrow) cocostudio::timeline::AnchorPointFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_AnchorPointFrame_constructor, __jsb_cocostudio_timeline_AnchorPointFrame_class, js_cocostudio_timeline_AnchorPointFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_AnchorPointFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::AnchorPointFrame)", s.nativeThisObject());
        cocostudio::timeline::AnchorPointFrame* cobj = (cocostudio::timeline::AnchorPointFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_AnchorPointFrame_finalize)

bool js_register_cocos2dx_studio_AnchorPointFrame(se::Object* obj)
{
    auto cls = se::Class::create("AnchorPointFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_AnchorPointFrame_constructor));

    cls->defineFunction("setAnchorPoint", _SE(js_cocos2dx_studio_AnchorPointFrame_setAnchorPoint));
    cls->defineFunction("getAnchorPoint", _SE(js_cocos2dx_studio_AnchorPointFrame_getAnchorPoint));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_AnchorPointFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_AnchorPointFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::AnchorPointFrame>(cls);

    __jsb_cocostudio_timeline_AnchorPointFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_AnchorPointFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_InnerActionFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_InnerActionFrame_class = nullptr;

static bool js_cocos2dx_studio_InnerActionFrame_getEndFrameIndex(se::State& s)
{
    cocostudio::timeline::InnerActionFrame* cobj = (cocostudio::timeline::InnerActionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InnerActionFrame_getEndFrameIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getEndFrameIndex();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InnerActionFrame_getEndFrameIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InnerActionFrame_getEndFrameIndex)

static bool js_cocos2dx_studio_InnerActionFrame_getStartFrameIndex(se::State& s)
{
    cocostudio::timeline::InnerActionFrame* cobj = (cocostudio::timeline::InnerActionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InnerActionFrame_getStartFrameIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getStartFrameIndex();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InnerActionFrame_getStartFrameIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InnerActionFrame_getStartFrameIndex)

static bool js_cocos2dx_studio_InnerActionFrame_getInnerActionType(se::State& s)
{
    cocostudio::timeline::InnerActionFrame* cobj = (cocostudio::timeline::InnerActionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InnerActionFrame_getInnerActionType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getInnerActionType();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InnerActionFrame_getInnerActionType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InnerActionFrame_getInnerActionType)

static bool js_cocos2dx_studio_InnerActionFrame_setEndFrameIndex(se::State& s)
{
    cocostudio::timeline::InnerActionFrame* cobj = (cocostudio::timeline::InnerActionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InnerActionFrame_setEndFrameIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InnerActionFrame_setEndFrameIndex : Error processing arguments");
        cobj->setEndFrameIndex(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InnerActionFrame_setEndFrameIndex)

static bool js_cocos2dx_studio_InnerActionFrame_setEnterWithName(se::State& s)
{
    cocostudio::timeline::InnerActionFrame* cobj = (cocostudio::timeline::InnerActionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InnerActionFrame_setEnterWithName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InnerActionFrame_setEnterWithName : Error processing arguments");
        cobj->setEnterWithName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InnerActionFrame_setEnterWithName)

static bool js_cocos2dx_studio_InnerActionFrame_setSingleFrameIndex(se::State& s)
{
    cocostudio::timeline::InnerActionFrame* cobj = (cocostudio::timeline::InnerActionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InnerActionFrame_setSingleFrameIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InnerActionFrame_setSingleFrameIndex : Error processing arguments");
        cobj->setSingleFrameIndex(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InnerActionFrame_setSingleFrameIndex)

static bool js_cocos2dx_studio_InnerActionFrame_setStartFrameIndex(se::State& s)
{
    cocostudio::timeline::InnerActionFrame* cobj = (cocostudio::timeline::InnerActionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InnerActionFrame_setStartFrameIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InnerActionFrame_setStartFrameIndex : Error processing arguments");
        cobj->setStartFrameIndex(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InnerActionFrame_setStartFrameIndex)

static bool js_cocos2dx_studio_InnerActionFrame_getSingleFrameIndex(se::State& s)
{
    cocostudio::timeline::InnerActionFrame* cobj = (cocostudio::timeline::InnerActionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InnerActionFrame_getSingleFrameIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getSingleFrameIndex();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InnerActionFrame_getSingleFrameIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InnerActionFrame_getSingleFrameIndex)

static bool js_cocos2dx_studio_InnerActionFrame_setInnerActionType(se::State& s)
{
    cocostudio::timeline::InnerActionFrame* cobj = (cocostudio::timeline::InnerActionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InnerActionFrame_setInnerActionType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::timeline::InnerActionType arg0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InnerActionFrame_setInnerActionType : Error processing arguments");
        cobj->setInnerActionType(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InnerActionFrame_setInnerActionType)

static bool js_cocos2dx_studio_InnerActionFrame_setAnimationName(se::State& s)
{
    cocostudio::timeline::InnerActionFrame* cobj = (cocostudio::timeline::InnerActionFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_InnerActionFrame_setAnimationName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_InnerActionFrame_setAnimationName : Error processing arguments");
        cobj->setAnimationName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InnerActionFrame_setAnimationName)

static bool js_cocos2dx_studio_InnerActionFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::InnerActionFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_InnerActionFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_InnerActionFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_InnerActionFrame_finalize)

static bool js_cocos2dx_studio_InnerActionFrame_constructor(se::State& s)
{
    cocostudio::timeline::InnerActionFrame* cobj = new (std::nothrow) cocostudio::timeline::InnerActionFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_InnerActionFrame_constructor, __jsb_cocostudio_timeline_InnerActionFrame_class, js_cocostudio_timeline_InnerActionFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_InnerActionFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::InnerActionFrame)", s.nativeThisObject());
        cocostudio::timeline::InnerActionFrame* cobj = (cocostudio::timeline::InnerActionFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_InnerActionFrame_finalize)

bool js_register_cocos2dx_studio_InnerActionFrame(se::Object* obj)
{
    auto cls = se::Class::create("InnerActionFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_InnerActionFrame_constructor));

    cls->defineFunction("getEndFrameIndex", _SE(js_cocos2dx_studio_InnerActionFrame_getEndFrameIndex));
    cls->defineFunction("getStartFrameIndex", _SE(js_cocos2dx_studio_InnerActionFrame_getStartFrameIndex));
    cls->defineFunction("getInnerActionType", _SE(js_cocos2dx_studio_InnerActionFrame_getInnerActionType));
    cls->defineFunction("setEndFrameIndex", _SE(js_cocos2dx_studio_InnerActionFrame_setEndFrameIndex));
    cls->defineFunction("setEnterWithName", _SE(js_cocos2dx_studio_InnerActionFrame_setEnterWithName));
    cls->defineFunction("setSingleFrameIndex", _SE(js_cocos2dx_studio_InnerActionFrame_setSingleFrameIndex));
    cls->defineFunction("setStartFrameIndex", _SE(js_cocos2dx_studio_InnerActionFrame_setStartFrameIndex));
    cls->defineFunction("getSingleFrameIndex", _SE(js_cocos2dx_studio_InnerActionFrame_getSingleFrameIndex));
    cls->defineFunction("setInnerActionType", _SE(js_cocos2dx_studio_InnerActionFrame_setInnerActionType));
    cls->defineFunction("setAnimationName", _SE(js_cocos2dx_studio_InnerActionFrame_setAnimationName));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_InnerActionFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_InnerActionFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::InnerActionFrame>(cls);

    __jsb_cocostudio_timeline_InnerActionFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_InnerActionFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_ColorFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_ColorFrame_class = nullptr;

static bool js_cocos2dx_studio_ColorFrame_getColor(se::State& s)
{
    cocostudio::timeline::ColorFrame* cobj = (cocostudio::timeline::ColorFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ColorFrame_getColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Color3B result = cobj->getColor();
        ok &= Color3B_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColorFrame_getColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColorFrame_getColor)

static bool js_cocos2dx_studio_ColorFrame_setColor(se::State& s)
{
    cocostudio::timeline::ColorFrame* cobj = (cocostudio::timeline::ColorFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ColorFrame_setColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Color3B arg0;
        ok &= seval_to_Color3B(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ColorFrame_setColor : Error processing arguments");
        cobj->setColor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColorFrame_setColor)

static bool js_cocos2dx_studio_ColorFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::ColorFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_ColorFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ColorFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_ColorFrame_finalize)

static bool js_cocos2dx_studio_ColorFrame_constructor(se::State& s)
{
    cocostudio::timeline::ColorFrame* cobj = new (std::nothrow) cocostudio::timeline::ColorFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ColorFrame_constructor, __jsb_cocostudio_timeline_ColorFrame_class, js_cocostudio_timeline_ColorFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_ColorFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::ColorFrame)", s.nativeThisObject());
        cocostudio::timeline::ColorFrame* cobj = (cocostudio::timeline::ColorFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_ColorFrame_finalize)

bool js_register_cocos2dx_studio_ColorFrame(se::Object* obj)
{
    auto cls = se::Class::create("ColorFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_ColorFrame_constructor));

    cls->defineFunction("getColor", _SE(js_cocos2dx_studio_ColorFrame_getColor));
    cls->defineFunction("setColor", _SE(js_cocos2dx_studio_ColorFrame_setColor));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ColorFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_ColorFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::ColorFrame>(cls);

    __jsb_cocostudio_timeline_ColorFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_ColorFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_AlphaFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_AlphaFrame_class = nullptr;

static bool js_cocos2dx_studio_AlphaFrame_getAlpha(se::State& s)
{
    cocostudio::timeline::AlphaFrame* cobj = (cocostudio::timeline::AlphaFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_AlphaFrame_getAlpha : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        uint8_t result = cobj->getAlpha();
        ok &= uint8_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_AlphaFrame_getAlpha : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_AlphaFrame_getAlpha)

static bool js_cocos2dx_studio_AlphaFrame_setAlpha(se::State& s)
{
    cocostudio::timeline::AlphaFrame* cobj = (cocostudio::timeline::AlphaFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_AlphaFrame_setAlpha : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        uint8_t arg0;
        ok &= seval_to_uint8(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_AlphaFrame_setAlpha : Error processing arguments");
        cobj->setAlpha(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_AlphaFrame_setAlpha)

static bool js_cocos2dx_studio_AlphaFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::AlphaFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_AlphaFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_AlphaFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_AlphaFrame_finalize)

static bool js_cocos2dx_studio_AlphaFrame_constructor(se::State& s)
{
    cocostudio::timeline::AlphaFrame* cobj = new (std::nothrow) cocostudio::timeline::AlphaFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_AlphaFrame_constructor, __jsb_cocostudio_timeline_AlphaFrame_class, js_cocostudio_timeline_AlphaFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_AlphaFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::AlphaFrame)", s.nativeThisObject());
        cocostudio::timeline::AlphaFrame* cobj = (cocostudio::timeline::AlphaFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_AlphaFrame_finalize)

bool js_register_cocos2dx_studio_AlphaFrame(se::Object* obj)
{
    auto cls = se::Class::create("AlphaFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_AlphaFrame_constructor));

    cls->defineFunction("getAlpha", _SE(js_cocos2dx_studio_AlphaFrame_getAlpha));
    cls->defineFunction("setAlpha", _SE(js_cocos2dx_studio_AlphaFrame_setAlpha));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_AlphaFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_AlphaFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::AlphaFrame>(cls);

    __jsb_cocostudio_timeline_AlphaFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_AlphaFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_EventFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_EventFrame_class = nullptr;

static bool js_cocos2dx_studio_EventFrame_setEvent(se::State& s)
{
    cocostudio::timeline::EventFrame* cobj = (cocostudio::timeline::EventFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_EventFrame_setEvent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_EventFrame_setEvent : Error processing arguments");
        cobj->setEvent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_EventFrame_setEvent)

static bool js_cocos2dx_studio_EventFrame_init(se::State& s)
{
    cocostudio::timeline::EventFrame* cobj = (cocostudio::timeline::EventFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_EventFrame_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->init();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_EventFrame_init)

static bool js_cocos2dx_studio_EventFrame_getEvent(se::State& s)
{
    cocostudio::timeline::EventFrame* cobj = (cocostudio::timeline::EventFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_EventFrame_getEvent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = cobj->getEvent();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_EventFrame_getEvent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_EventFrame_getEvent)

static bool js_cocos2dx_studio_EventFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::EventFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_EventFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_EventFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_EventFrame_finalize)

static bool js_cocos2dx_studio_EventFrame_constructor(se::State& s)
{
    cocostudio::timeline::EventFrame* cobj = new (std::nothrow) cocostudio::timeline::EventFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_EventFrame_constructor, __jsb_cocostudio_timeline_EventFrame_class, js_cocostudio_timeline_EventFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_EventFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::EventFrame)", s.nativeThisObject());
        cocostudio::timeline::EventFrame* cobj = (cocostudio::timeline::EventFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_EventFrame_finalize)

bool js_register_cocos2dx_studio_EventFrame(se::Object* obj)
{
    auto cls = se::Class::create("EventFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_EventFrame_constructor));

    cls->defineFunction("setEvent", _SE(js_cocos2dx_studio_EventFrame_setEvent));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_EventFrame_init));
    cls->defineFunction("getEvent", _SE(js_cocos2dx_studio_EventFrame_getEvent));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_EventFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_EventFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::EventFrame>(cls);

    __jsb_cocostudio_timeline_EventFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_EventFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_ZOrderFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_ZOrderFrame_class = nullptr;

static bool js_cocos2dx_studio_ZOrderFrame_getZOrder(se::State& s)
{
    cocostudio::timeline::ZOrderFrame* cobj = (cocostudio::timeline::ZOrderFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ZOrderFrame_getZOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getZOrder();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ZOrderFrame_getZOrder : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ZOrderFrame_getZOrder)

static bool js_cocos2dx_studio_ZOrderFrame_setZOrder(se::State& s)
{
    cocostudio::timeline::ZOrderFrame* cobj = (cocostudio::timeline::ZOrderFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ZOrderFrame_setZOrder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ZOrderFrame_setZOrder : Error processing arguments");
        cobj->setZOrder(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ZOrderFrame_setZOrder)

static bool js_cocos2dx_studio_ZOrderFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::ZOrderFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_ZOrderFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ZOrderFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_ZOrderFrame_finalize)

static bool js_cocos2dx_studio_ZOrderFrame_constructor(se::State& s)
{
    cocostudio::timeline::ZOrderFrame* cobj = new (std::nothrow) cocostudio::timeline::ZOrderFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ZOrderFrame_constructor, __jsb_cocostudio_timeline_ZOrderFrame_class, js_cocostudio_timeline_ZOrderFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_ZOrderFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::ZOrderFrame)", s.nativeThisObject());
        cocostudio::timeline::ZOrderFrame* cobj = (cocostudio::timeline::ZOrderFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_ZOrderFrame_finalize)

bool js_register_cocos2dx_studio_ZOrderFrame(se::Object* obj)
{
    auto cls = se::Class::create("ZOrderFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_ZOrderFrame_constructor));

    cls->defineFunction("getZOrder", _SE(js_cocos2dx_studio_ZOrderFrame_getZOrder));
    cls->defineFunction("setZOrder", _SE(js_cocos2dx_studio_ZOrderFrame_setZOrder));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ZOrderFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_ZOrderFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::ZOrderFrame>(cls);

    __jsb_cocostudio_timeline_ZOrderFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_ZOrderFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_BlendFuncFrame_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_BlendFuncFrame_class = nullptr;

static bool js_cocos2dx_studio_BlendFuncFrame_getBlendFunc(se::State& s)
{
    cocostudio::timeline::BlendFuncFrame* cobj = (cocostudio::timeline::BlendFuncFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BlendFuncFrame_getBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::BlendFunc result = cobj->getBlendFunc();
        ok &= blendfunc_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BlendFuncFrame_getBlendFunc : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BlendFuncFrame_getBlendFunc)

static bool js_cocos2dx_studio_BlendFuncFrame_setBlendFunc(se::State& s)
{
    cocostudio::timeline::BlendFuncFrame* cobj = (cocostudio::timeline::BlendFuncFrame*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BlendFuncFrame_setBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::BlendFunc arg0;
        ok &= seval_to_blendfunc(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BlendFuncFrame_setBlendFunc : Error processing arguments");
        cobj->setBlendFunc(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BlendFuncFrame_setBlendFunc)

static bool js_cocos2dx_studio_BlendFuncFrame_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::BlendFuncFrame::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_BlendFuncFrame_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BlendFuncFrame_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_BlendFuncFrame_finalize)

static bool js_cocos2dx_studio_BlendFuncFrame_constructor(se::State& s)
{
    cocostudio::timeline::BlendFuncFrame* cobj = new (std::nothrow) cocostudio::timeline::BlendFuncFrame();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_BlendFuncFrame_constructor, __jsb_cocostudio_timeline_BlendFuncFrame_class, js_cocostudio_timeline_BlendFuncFrame_finalize)



extern se::Object* __jsb_cocostudio_timeline_Frame_proto;

bool js_cocostudio_timeline_BlendFuncFrame_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::BlendFuncFrame)", s.nativeThisObject());
        cocostudio::timeline::BlendFuncFrame* cobj = (cocostudio::timeline::BlendFuncFrame*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_BlendFuncFrame_finalize)

bool js_register_cocos2dx_studio_BlendFuncFrame(se::Object* obj)
{
    auto cls = se::Class::create("BlendFuncFrame", obj, __jsb_cocostudio_timeline_Frame_proto, _SE(js_cocos2dx_studio_BlendFuncFrame_constructor));

    cls->defineFunction("getBlendFunc", _SE(js_cocos2dx_studio_BlendFuncFrame_getBlendFunc));
    cls->defineFunction("setBlendFunc", _SE(js_cocos2dx_studio_BlendFuncFrame_setBlendFunc));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_BlendFuncFrame_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_BlendFuncFrame_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::BlendFuncFrame>(cls);

    __jsb_cocostudio_timeline_BlendFuncFrame_proto = cls->getProto();
    __jsb_cocostudio_timeline_BlendFuncFrame_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_Timeline_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_Timeline_class = nullptr;

static bool js_cocos2dx_studio_Timeline_clone(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_clone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::timeline::Timeline* result = cobj->clone();
        ok &= native_ptr_to_seval<cocostudio::timeline::Timeline>((cocostudio::timeline::Timeline*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_clone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_clone)

static bool js_cocos2dx_studio_Timeline_gotoFrame(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_gotoFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_gotoFrame : Error processing arguments");
        cobj->gotoFrame(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_gotoFrame)

static bool js_cocos2dx_studio_Timeline_setNode(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_setNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Node* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_setNode : Error processing arguments");
        cobj->setNode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_setNode)

static bool js_cocos2dx_studio_Timeline_getActionTimeline(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_getActionTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::timeline::ActionTimeline* result = cobj->getActionTimeline();
        ok &= native_ptr_to_seval<cocostudio::timeline::ActionTimeline>((cocostudio::timeline::ActionTimeline*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_getActionTimeline : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_getActionTimeline)

static bool js_cocos2dx_studio_Timeline_insertFrame(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_insertFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocostudio::timeline::Frame* arg0 = nullptr;
        int arg1 = 0;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_insertFrame : Error processing arguments");
        cobj->insertFrame(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_insertFrame)

static bool js_cocos2dx_studio_Timeline_setActionTag(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_setActionTag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_setActionTag : Error processing arguments");
        cobj->setActionTag(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_setActionTag)

static bool js_cocos2dx_studio_Timeline_addFrame(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_addFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::timeline::Frame* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_addFrame : Error processing arguments");
        cobj->addFrame(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_addFrame)

static bool js_cocos2dx_studio_Timeline_getFrames(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_getFrames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::Vector<cocostudio::timeline::Frame *>& result = cobj->getFrames();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_getFrames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_getFrames)

static bool js_cocos2dx_studio_Timeline_getActionTag(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_getActionTag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getActionTag();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_getActionTag : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_getActionTag)

static bool js_cocos2dx_studio_Timeline_getNode(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_getNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Node* result = cobj->getNode();
        ok &= native_ptr_to_seval<cocos2d::Node>((cocos2d::Node*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_getNode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_getNode)

static bool js_cocos2dx_studio_Timeline_removeFrame(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_removeFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::timeline::Frame* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_removeFrame : Error processing arguments");
        cobj->removeFrame(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_removeFrame)

static bool js_cocos2dx_studio_Timeline_setActionTimeline(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_setActionTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::timeline::ActionTimeline* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_setActionTimeline : Error processing arguments");
        cobj->setActionTimeline(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_setActionTimeline)

static bool js_cocos2dx_studio_Timeline_stepToFrame(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_Timeline_stepToFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_Timeline_stepToFrame : Error processing arguments");
        cobj->stepToFrame(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_stepToFrame)

static bool js_cocos2dx_studio_Timeline_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::Timeline::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_Timeline_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_Timeline_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_Timeline_finalize)

static bool js_cocos2dx_studio_Timeline_constructor(se::State& s)
{
    cocostudio::timeline::Timeline* cobj = new (std::nothrow) cocostudio::timeline::Timeline();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_Timeline_constructor, __jsb_cocostudio_timeline_Timeline_class, js_cocostudio_timeline_Timeline_finalize)




bool js_cocostudio_timeline_Timeline_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::Timeline)", s.nativeThisObject());
        cocostudio::timeline::Timeline* cobj = (cocostudio::timeline::Timeline*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_Timeline_finalize)

bool js_register_cocos2dx_studio_Timeline(se::Object* obj)
{
    auto cls = se::Class::create("Timeline", obj, nullptr, _SE(js_cocos2dx_studio_Timeline_constructor));

    cls->defineFunction("clone", _SE(js_cocos2dx_studio_Timeline_clone));
    cls->defineFunction("gotoFrame", _SE(js_cocos2dx_studio_Timeline_gotoFrame));
    cls->defineFunction("setNode", _SE(js_cocos2dx_studio_Timeline_setNode));
    cls->defineFunction("getActionTimeline", _SE(js_cocos2dx_studio_Timeline_getActionTimeline));
    cls->defineFunction("insertFrame", _SE(js_cocos2dx_studio_Timeline_insertFrame));
    cls->defineFunction("setActionTag", _SE(js_cocos2dx_studio_Timeline_setActionTag));
    cls->defineFunction("addFrame", _SE(js_cocos2dx_studio_Timeline_addFrame));
    cls->defineFunction("getFrames", _SE(js_cocos2dx_studio_Timeline_getFrames));
    cls->defineFunction("getActionTag", _SE(js_cocos2dx_studio_Timeline_getActionTag));
    cls->defineFunction("getNode", _SE(js_cocos2dx_studio_Timeline_getNode));
    cls->defineFunction("removeFrame", _SE(js_cocos2dx_studio_Timeline_removeFrame));
    cls->defineFunction("setActionTimeline", _SE(js_cocos2dx_studio_Timeline_setActionTimeline));
    cls->defineFunction("stepToFrame", _SE(js_cocos2dx_studio_Timeline_stepToFrame));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_Timeline_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_Timeline_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::Timeline>(cls);

    __jsb_cocostudio_timeline_Timeline_proto = cls->getProto();
    __jsb_cocostudio_timeline_Timeline_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_ActionTimelineData_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_ActionTimelineData_class = nullptr;

static bool js_cocos2dx_studio_ActionTimelineData_setActionTag(se::State& s)
{
    cocostudio::timeline::ActionTimelineData* cobj = (cocostudio::timeline::ActionTimelineData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimelineData_setActionTag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimelineData_setActionTag : Error processing arguments");
        cobj->setActionTag(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimelineData_setActionTag)

static bool js_cocos2dx_studio_ActionTimelineData_init(se::State& s)
{
    cocostudio::timeline::ActionTimelineData* cobj = (cocostudio::timeline::ActionTimelineData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimelineData_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimelineData_init : Error processing arguments");
        bool result = cobj->init(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimelineData_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimelineData_init)

static bool js_cocos2dx_studio_ActionTimelineData_getActionTag(se::State& s)
{
    cocostudio::timeline::ActionTimelineData* cobj = (cocostudio::timeline::ActionTimelineData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimelineData_getActionTag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getActionTag();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimelineData_getActionTag : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimelineData_getActionTag)

static bool js_cocos2dx_studio_ActionTimelineData_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimelineData_create : Error processing arguments");
        auto result = cocostudio::timeline::ActionTimelineData::create(arg0);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_ActionTimelineData_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimelineData_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_ActionTimelineData_finalize)

static bool js_cocos2dx_studio_ActionTimelineData_constructor(se::State& s)
{
    cocostudio::timeline::ActionTimelineData* cobj = new (std::nothrow) cocostudio::timeline::ActionTimelineData();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ActionTimelineData_constructor, __jsb_cocostudio_timeline_ActionTimelineData_class, js_cocostudio_timeline_ActionTimelineData_finalize)




bool js_cocostudio_timeline_ActionTimelineData_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::ActionTimelineData)", s.nativeThisObject());
        cocostudio::timeline::ActionTimelineData* cobj = (cocostudio::timeline::ActionTimelineData*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_ActionTimelineData_finalize)

bool js_register_cocos2dx_studio_ActionTimelineData(se::Object* obj)
{
    auto cls = se::Class::create("ActionTimelineData", obj, nullptr, _SE(js_cocos2dx_studio_ActionTimelineData_constructor));

    cls->defineFunction("setActionTag", _SE(js_cocos2dx_studio_ActionTimelineData_setActionTag));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_ActionTimelineData_init));
    cls->defineFunction("getActionTag", _SE(js_cocos2dx_studio_ActionTimelineData_getActionTag));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ActionTimelineData_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_ActionTimelineData_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::ActionTimelineData>(cls);

    __jsb_cocostudio_timeline_ActionTimelineData_proto = cls->getProto();
    __jsb_cocostudio_timeline_ActionTimelineData_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_ActionTimeline_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_ActionTimeline_class = nullptr;

static bool js_cocos2dx_studio_ActionTimeline_setFrameEventCallFunc(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_setFrameEventCallFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void (cocostudio::timeline::Frame *)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject());
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachChild(jsFunc.toObject());
                auto lambda = [=](cocostudio::timeline::Frame* larg0) -> void {
                    se::ScriptEngine::getInstance()->clearException();
                    se::AutoHandleScope hs;
        
                    CC_UNUSED bool ok = true;
                    se::ValueArray args;
                    args.resize(1);
                    ok &= native_ptr_to_seval<cocostudio::timeline::Frame>((cocostudio::timeline::Frame*)larg0, &args[0]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        se::ScriptEngine::getInstance()->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_setFrameEventCallFunc : Error processing arguments");
        cobj->setFrameEventCallFunc(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_setFrameEventCallFunc)

static bool js_cocos2dx_studio_ActionTimeline_clearFrameEndCallFuncs(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_clearFrameEndCallFuncs : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->clearFrameEndCallFuncs();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_clearFrameEndCallFuncs)

static bool js_cocos2dx_studio_ActionTimeline_setAnimationEndCallFunc(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_setAnimationEndCallFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::function<void ()> arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        do {
            if (args[1].isObject() && args[1].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject());
                se::Value jsFunc(args[1]);
                jsThis.toObject()->attachChild(jsFunc.toObject());
                auto lambda = [=]() -> void {
                    se::ScriptEngine::getInstance()->clearException();
                    se::AutoHandleScope hs;
        
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(se::EmptyValueArray, thisObj, &rval);
                    if (!succeed) {
                        se::ScriptEngine::getInstance()->clearException();
                    }
                };
                arg1 = lambda;
            }
            else
            {
                arg1 = nullptr;
            }
        } while(false)
        ;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_setAnimationEndCallFunc : Error processing arguments");
        cobj->setAnimationEndCallFunc(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_setAnimationEndCallFunc)

static bool js_cocos2dx_studio_ActionTimeline_addTimeline(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_addTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::timeline::Timeline* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_addTimeline : Error processing arguments");
        cobj->addTimeline(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_addTimeline)

static bool js_cocos2dx_studio_ActionTimeline_getCurrentFrame(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_getCurrentFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getCurrentFrame();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_getCurrentFrame : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_getCurrentFrame)

static bool js_cocos2dx_studio_ActionTimeline_getStartFrame(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_getStartFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getStartFrame();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_getStartFrame : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_getStartFrame)

static bool js_cocos2dx_studio_ActionTimeline_pause(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_pause : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->pause();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_pause)

static bool js_cocos2dx_studio_ActionTimeline_start(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_start : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->start();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_start)

static bool js_cocos2dx_studio_ActionTimeline_init(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->init();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_init)

static bool js_cocos2dx_studio_ActionTimeline_removeTimeline(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_removeTimeline : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::timeline::Timeline* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_removeTimeline : Error processing arguments");
        cobj->removeTimeline(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_removeTimeline)

static bool js_cocos2dx_studio_ActionTimeline_setLastFrameCallFunc(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_setLastFrameCallFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::function<void ()> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject());
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachChild(jsFunc.toObject());
                auto lambda = [=]() -> void {
                    se::ScriptEngine::getInstance()->clearException();
                    se::AutoHandleScope hs;
        
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(se::EmptyValueArray, thisObj, &rval);
                    if (!succeed) {
                        se::ScriptEngine::getInstance()->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false)
        ;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_setLastFrameCallFunc : Error processing arguments");
        cobj->setLastFrameCallFunc(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_setLastFrameCallFunc)

static bool js_cocos2dx_studio_ActionTimeline_IsAnimationInfoExists(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_IsAnimationInfoExists : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_IsAnimationInfoExists : Error processing arguments");
        bool result = cobj->IsAnimationInfoExists(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_IsAnimationInfoExists : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_IsAnimationInfoExists)

static bool js_cocos2dx_studio_ActionTimeline_getTimelines(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_getTimelines : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::Vector<cocostudio::timeline::Timeline *>& result = cobj->getTimelines();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_getTimelines : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_getTimelines)

static bool js_cocos2dx_studio_ActionTimeline_play(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_play : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_play : Error processing arguments");
        cobj->play(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_play)

static bool js_cocos2dx_studio_ActionTimeline_getAnimationInfo(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_getAnimationInfo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_getAnimationInfo : Error processing arguments");
        const cocostudio::timeline::AnimationInfo& result = cobj->getAnimationInfo(arg0);
        #pragma warning NO CONVERSION FROM NATIVE FOR AnimationInfo;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_getAnimationInfo : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_getAnimationInfo)

static bool js_cocos2dx_studio_ActionTimeline_resume(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_resume : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->resume();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_resume)

static bool js_cocos2dx_studio_ActionTimeline_addFrameEndCallFunc(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_addFrameEndCallFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        std::string arg1;
        std::function<void ()> arg2;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        do {
            if (args[2].isObject() && args[2].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject());
                se::Value jsFunc(args[2]);
                jsThis.toObject()->attachChild(jsFunc.toObject());
                auto lambda = [=]() -> void {
                    se::ScriptEngine::getInstance()->clearException();
                    se::AutoHandleScope hs;
        
                    se::Value rval;
                    se::Object* thisObj = jsThis.isObject() ? jsThis.toObject() : nullptr;
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(se::EmptyValueArray, thisObj, &rval);
                    if (!succeed) {
                        se::ScriptEngine::getInstance()->clearException();
                    }
                };
                arg2 = lambda;
            }
            else
            {
                arg2 = nullptr;
            }
        } while(false)
        ;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_addFrameEndCallFunc : Error processing arguments");
        cobj->addFrameEndCallFunc(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_addFrameEndCallFunc)

static bool js_cocos2dx_studio_ActionTimeline_removeAnimationInfo(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_removeAnimationInfo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_removeAnimationInfo : Error processing arguments");
        cobj->removeAnimationInfo(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_removeAnimationInfo)

static bool js_cocos2dx_studio_ActionTimeline_getTimeSpeed(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_getTimeSpeed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTimeSpeed();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_getTimeSpeed : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_getTimeSpeed)

static bool js_cocos2dx_studio_ActionTimeline_addAnimationInfo(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_addAnimationInfo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocostudio::timeline::AnimationInfo arg0;
        #pragma warning NO CONVERSION TO NATIVE FOR AnimationInfo
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_addAnimationInfo : Error processing arguments");
        cobj->addAnimationInfo(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_addAnimationInfo)

static bool js_cocos2dx_studio_ActionTimeline_getDuration(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_getDuration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getDuration();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_getDuration : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_getDuration)

static bool js_cocos2dx_studio_ActionTimeline_gotoFrameAndPause(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_gotoFrameAndPause : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_gotoFrameAndPause : Error processing arguments");
        cobj->gotoFrameAndPause(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_gotoFrameAndPause)

static bool js_cocos2dx_studio_ActionTimeline_isPlaying(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_isPlaying : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isPlaying();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_isPlaying : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_isPlaying)

static bool js_cocos2dx_studio_ActionTimeline_removeFrameEndCallFuncs(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_removeFrameEndCallFuncs : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_removeFrameEndCallFuncs : Error processing arguments");
        cobj->removeFrameEndCallFuncs(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_removeFrameEndCallFuncs)

static bool js_cocos2dx_studio_ActionTimeline_gotoFrameAndPlay(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_ActionTimeline_gotoFrameAndPlay : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            int arg0 = 0;
            ok &= seval_to_int32(args[0], (int32_t *)&arg0);
            if (!ok) { ok = true; break; }
            bool arg1;
            ok &= seval_to_boolean(args[1], &arg1);
            cobj->gotoFrameAndPlay(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            int arg0 = 0;
            ok &= seval_to_int32(args[0], (int32_t *)&arg0);
            if (!ok) { ok = true; break; }
            cobj->gotoFrameAndPlay(arg0);
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            int arg0 = 0;
            ok &= seval_to_int32(args[0], (int32_t *)&arg0);
            if (!ok) { ok = true; break; }
            int arg1 = 0;
            ok &= seval_to_int32(args[1], (int32_t *)&arg1);
            if (!ok) { ok = true; break; }
            bool arg2;
            ok &= seval_to_boolean(args[2], &arg2);
            cobj->gotoFrameAndPlay(arg0, arg1, arg2);
            return true;
        }
    } while(false);

    do {
        if (argc == 4) {
            int arg0 = 0;
            ok &= seval_to_int32(args[0], (int32_t *)&arg0);
            if (!ok) { ok = true; break; }
            int arg1 = 0;
            ok &= seval_to_int32(args[1], (int32_t *)&arg1);
            if (!ok) { ok = true; break; }
            int arg2 = 0;
            ok &= seval_to_int32(args[2], (int32_t *)&arg2);
            if (!ok) { ok = true; break; }
            bool arg3;
            ok &= seval_to_boolean(args[3], &arg3);
            cobj->gotoFrameAndPlay(arg0, arg1, arg2, arg3);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_gotoFrameAndPlay)

static bool js_cocos2dx_studio_ActionTimeline_clearFrameEventCallFunc(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_clearFrameEventCallFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->clearFrameEventCallFunc();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_clearFrameEventCallFunc)

static bool js_cocos2dx_studio_ActionTimeline_getEndFrame(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_getEndFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getEndFrame();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_getEndFrame : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_getEndFrame)

static bool js_cocos2dx_studio_ActionTimeline_setTimeSpeed(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_setTimeSpeed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_setTimeSpeed : Error processing arguments");
        cobj->setTimeSpeed(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_setTimeSpeed)

static bool js_cocos2dx_studio_ActionTimeline_clearLastFrameCallFunc(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_clearLastFrameCallFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->clearLastFrameCallFunc();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_clearLastFrameCallFunc)

static bool js_cocos2dx_studio_ActionTimeline_setDuration(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_setDuration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_setDuration : Error processing arguments");
        cobj->setDuration(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_setDuration)

static bool js_cocos2dx_studio_ActionTimeline_setCurrentFrame(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_setCurrentFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_setCurrentFrame : Error processing arguments");
        cobj->setCurrentFrame(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_setCurrentFrame)

static bool js_cocos2dx_studio_ActionTimeline_removeFrameEndCallFunc(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ActionTimeline_removeFrameEndCallFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ActionTimeline_removeFrameEndCallFunc : Error processing arguments");
        cobj->removeFrameEndCallFunc(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_removeFrameEndCallFunc)

static bool js_cocos2dx_studio_ActionTimeline_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::ActionTimeline::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_ActionTimeline_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ActionTimeline_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_ActionTimeline_finalize)

static bool js_cocos2dx_studio_ActionTimeline_constructor(se::State& s)
{
    cocostudio::timeline::ActionTimeline* cobj = new (std::nothrow) cocostudio::timeline::ActionTimeline();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ActionTimeline_constructor, __jsb_cocostudio_timeline_ActionTimeline_class, js_cocostudio_timeline_ActionTimeline_finalize)



extern se::Object* __jsb_cocos2d_Action_proto;

bool js_cocostudio_timeline_ActionTimeline_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::ActionTimeline)", s.nativeThisObject());
        cocostudio::timeline::ActionTimeline* cobj = (cocostudio::timeline::ActionTimeline*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_ActionTimeline_finalize)

bool js_register_cocos2dx_studio_ActionTimeline(se::Object* obj)
{
    auto cls = se::Class::create("ActionTimeline", obj, __jsb_cocos2d_Action_proto, _SE(js_cocos2dx_studio_ActionTimeline_constructor));

    cls->defineFunction("setFrameEventCallFunc", _SE(js_cocos2dx_studio_ActionTimeline_setFrameEventCallFunc));
    cls->defineFunction("clearFrameEndCallFuncs", _SE(js_cocos2dx_studio_ActionTimeline_clearFrameEndCallFuncs));
    cls->defineFunction("setAnimationEndCallFunc", _SE(js_cocos2dx_studio_ActionTimeline_setAnimationEndCallFunc));
    cls->defineFunction("addTimeline", _SE(js_cocos2dx_studio_ActionTimeline_addTimeline));
    cls->defineFunction("getCurrentFrame", _SE(js_cocos2dx_studio_ActionTimeline_getCurrentFrame));
    cls->defineFunction("getStartFrame", _SE(js_cocos2dx_studio_ActionTimeline_getStartFrame));
    cls->defineFunction("pause", _SE(js_cocos2dx_studio_ActionTimeline_pause));
    cls->defineFunction("start", _SE(js_cocos2dx_studio_ActionTimeline_start));
    cls->defineFunction("init", _SE(js_cocos2dx_studio_ActionTimeline_init));
    cls->defineFunction("removeTimeline", _SE(js_cocos2dx_studio_ActionTimeline_removeTimeline));
    cls->defineFunction("setLastFrameCallFunc", _SE(js_cocos2dx_studio_ActionTimeline_setLastFrameCallFunc));
    cls->defineFunction("isAnimationInfoExists", _SE(js_cocos2dx_studio_ActionTimeline_IsAnimationInfoExists));
    cls->defineFunction("getTimelines", _SE(js_cocos2dx_studio_ActionTimeline_getTimelines));
    cls->defineFunction("play", _SE(js_cocos2dx_studio_ActionTimeline_play));
    cls->defineFunction("getAnimationInfo", _SE(js_cocos2dx_studio_ActionTimeline_getAnimationInfo));
    cls->defineFunction("resume", _SE(js_cocos2dx_studio_ActionTimeline_resume));
    cls->defineFunction("addFrameEndCallFunc", _SE(js_cocos2dx_studio_ActionTimeline_addFrameEndCallFunc));
    cls->defineFunction("removeAnimationInfo", _SE(js_cocos2dx_studio_ActionTimeline_removeAnimationInfo));
    cls->defineFunction("getTimeSpeed", _SE(js_cocos2dx_studio_ActionTimeline_getTimeSpeed));
    cls->defineFunction("addAnimationInfo", _SE(js_cocos2dx_studio_ActionTimeline_addAnimationInfo));
    cls->defineFunction("getDuration", _SE(js_cocos2dx_studio_ActionTimeline_getDuration));
    cls->defineFunction("gotoFrameAndPause", _SE(js_cocos2dx_studio_ActionTimeline_gotoFrameAndPause));
    cls->defineFunction("isPlaying", _SE(js_cocos2dx_studio_ActionTimeline_isPlaying));
    cls->defineFunction("removeFrameEndCallFuncs", _SE(js_cocos2dx_studio_ActionTimeline_removeFrameEndCallFuncs));
    cls->defineFunction("gotoFrameAndPlay", _SE(js_cocos2dx_studio_ActionTimeline_gotoFrameAndPlay));
    cls->defineFunction("clearFrameEventCallFunc", _SE(js_cocos2dx_studio_ActionTimeline_clearFrameEventCallFunc));
    cls->defineFunction("getEndFrame", _SE(js_cocos2dx_studio_ActionTimeline_getEndFrame));
    cls->defineFunction("setTimeSpeed", _SE(js_cocos2dx_studio_ActionTimeline_setTimeSpeed));
    cls->defineFunction("clearLastFrameCallFunc", _SE(js_cocos2dx_studio_ActionTimeline_clearLastFrameCallFunc));
    cls->defineFunction("setDuration", _SE(js_cocos2dx_studio_ActionTimeline_setDuration));
    cls->defineFunction("setCurrentFrame", _SE(js_cocos2dx_studio_ActionTimeline_setCurrentFrame));
    cls->defineFunction("removeFrameEndCallFunc", _SE(js_cocos2dx_studio_ActionTimeline_removeFrameEndCallFunc));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ActionTimeline_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_ActionTimeline_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::ActionTimeline>(cls);

    __jsb_cocostudio_timeline_ActionTimeline_proto = cls->getProto();
    __jsb_cocostudio_timeline_ActionTimeline_class = cls;

    return true;
}

se::Object* __jsb_cocostudio_timeline_BoneNode_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_BoneNode_class = nullptr;

static bool js_cocos2dx_studio_BoneNode_getDebugDrawWidth(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_getDebugDrawWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDebugDrawWidth();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getDebugDrawWidth : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_getDebugDrawWidth)

static bool js_cocos2dx_studio_BoneNode_getChildBones(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_BoneNode_getChildBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 0) {
            cocos2d::Vector<cocostudio::timeline::BoneNode *>& result = cobj->getChildBones();
            ok &= Vector_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getChildBones : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 0) {
            const cocos2d::Vector<cocostudio::timeline::BoneNode *>& result = cobj->getChildBones();
            ok &= Vector_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getChildBones : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_getChildBones)

static bool js_cocos2dx_studio_BoneNode_getBlendFunc(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_getBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::BlendFunc& result = cobj->getBlendFunc();
        ok &= blendfunc_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getBlendFunc : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_getBlendFunc)

static bool js_cocos2dx_studio_BoneNode_getAllSubBones(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_getAllSubBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vector<cocostudio::timeline::BoneNode *> result = cobj->getAllSubBones();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getAllSubBones : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_getAllSubBones)

static bool js_cocos2dx_studio_BoneNode_setBlendFunc(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_setBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::BlendFunc arg0;
        ok &= seval_to_blendfunc(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_setBlendFunc : Error processing arguments");
        cobj->setBlendFunc(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_setBlendFunc)

static bool js_cocos2dx_studio_BoneNode_setDebugDrawEnabled(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_setDebugDrawEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_setDebugDrawEnabled : Error processing arguments");
        cobj->setDebugDrawEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_setDebugDrawEnabled)

static bool js_cocos2dx_studio_BoneNode_getVisibleSkinsRect(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_getVisibleSkinsRect : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Rect result = cobj->getVisibleSkinsRect();
        ok &= Rect_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getVisibleSkinsRect : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_getVisibleSkinsRect)

static bool js_cocos2dx_studio_BoneNode_getAllSubSkins(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_getAllSubSkins : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vector<cocos2d::Node *> result = cobj->getAllSubSkins();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getAllSubSkins : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_getAllSubSkins)

static bool js_cocos2dx_studio_BoneNode_displaySkin(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_BoneNode_displaySkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool arg1;
            ok &= seval_to_boolean(args[1], &arg1);
            cobj->displaySkin(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            cocos2d::Node* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool arg1;
            ok &= seval_to_boolean(args[1], &arg1);
            cobj->displaySkin(arg0, arg1);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_displaySkin)

static bool js_cocos2dx_studio_BoneNode_isDebugDrawEnabled(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_isDebugDrawEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isDebugDrawEnabled();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_isDebugDrawEnabled : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_isDebugDrawEnabled)

static bool js_cocos2dx_studio_BoneNode_addSkin(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_BoneNode_addSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 3) {
            cocos2d::Node* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool arg1;
            ok &= seval_to_boolean(args[1], &arg1);
            bool arg2;
            ok &= seval_to_boolean(args[2], &arg2);
            cobj->addSkin(arg0, arg1, arg2);
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            cocos2d::Node* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool arg1;
            ok &= seval_to_boolean(args[1], &arg1);
            cobj->addSkin(arg0, arg1);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_addSkin)

static bool js_cocos2dx_studio_BoneNode_getRootSkeletonNode(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_getRootSkeletonNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocostudio::timeline::SkeletonNode* result = cobj->getRootSkeletonNode();
        ok &= native_ptr_to_seval<cocostudio::timeline::SkeletonNode>((cocostudio::timeline::SkeletonNode*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getRootSkeletonNode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_getRootSkeletonNode)

static bool js_cocos2dx_studio_BoneNode_setDebugDrawLength(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_setDebugDrawLength : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_setDebugDrawLength : Error processing arguments");
        cobj->setDebugDrawLength(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_setDebugDrawLength)

static bool js_cocos2dx_studio_BoneNode_getSkins(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_BoneNode_getSkins : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 0) {
            cocos2d::Vector<cocos2d::Node *>& result = cobj->getSkins();
            ok &= Vector_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getSkins : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 0) {
            const cocos2d::Vector<cocos2d::Node *>& result = cobj->getSkins();
            ok &= Vector_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getSkins : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_getSkins)

static bool js_cocos2dx_studio_BoneNode_getVisibleSkins(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_getVisibleSkins : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vector<cocos2d::Node *> result = cobj->getVisibleSkins();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getVisibleSkins : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_getVisibleSkins)

static bool js_cocos2dx_studio_BoneNode_setDebugDrawWidth(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_setDebugDrawWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_setDebugDrawWidth : Error processing arguments");
        cobj->setDebugDrawWidth(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_setDebugDrawWidth)

static bool js_cocos2dx_studio_BoneNode_getDebugDrawLength(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_getDebugDrawLength : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDebugDrawLength();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getDebugDrawLength : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_getDebugDrawLength)

static bool js_cocos2dx_studio_BoneNode_setDebugDrawColor(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_setDebugDrawColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Color4F arg0;
        ok &= seval_to_Color4F(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_setDebugDrawColor : Error processing arguments");
        cobj->setDebugDrawColor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_setDebugDrawColor)

static bool js_cocos2dx_studio_BoneNode_getDebugDrawColor(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_BoneNode_getDebugDrawColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Color4F result = cobj->getDebugDrawColor();
        ok &= Color4F_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_getDebugDrawColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_getDebugDrawColor)

static bool js_cocos2dx_studio_BoneNode_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            int arg0 = 0;
            ok &= seval_to_int32(args[0], (int32_t *)&arg0);
            if (!ok) { ok = true; break; }
            cocostudio::timeline::BoneNode* result = cocostudio::timeline::BoneNode::create(arg0);
            ok &= native_ptr_to_seval<cocostudio::timeline::BoneNode>((cocostudio::timeline::BoneNode*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            cocostudio::timeline::BoneNode* result = cocostudio::timeline::BoneNode::create();
            ok &= native_ptr_to_seval<cocostudio::timeline::BoneNode>((cocostudio::timeline::BoneNode*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_BoneNode_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_BoneNode_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_BoneNode_finalize)

static bool js_cocos2dx_studio_BoneNode_constructor(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = new (std::nothrow) cocostudio::timeline::BoneNode();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_BoneNode_constructor, __jsb_cocostudio_timeline_BoneNode_class, js_cocostudio_timeline_BoneNode_finalize)

static bool js_cocos2dx_studio_BoneNode_ctor(se::State& s)
{
    cocostudio::timeline::BoneNode* cobj = new (std::nothrow) cocostudio::timeline::BoneNode();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_SUB_CLS_CTOR(js_cocos2dx_studio_BoneNode_ctor, __jsb_cocostudio_timeline_BoneNode_class, js_cocostudio_timeline_BoneNode_finalize)


    

extern se::Object* __jsb_cocos2d_Node_proto;

bool js_cocostudio_timeline_BoneNode_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::BoneNode)", s.nativeThisObject());
        cocostudio::timeline::BoneNode* cobj = (cocostudio::timeline::BoneNode*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_BoneNode_finalize)

bool js_register_cocos2dx_studio_BoneNode(se::Object* obj)
{
    auto cls = se::Class::create("BoneNode", obj, __jsb_cocos2d_Node_proto, _SE(js_cocos2dx_studio_BoneNode_constructor));

    cls->defineFunction("getDebugDrawWidth", _SE(js_cocos2dx_studio_BoneNode_getDebugDrawWidth));
    cls->defineFunction("getChildBones", _SE(js_cocos2dx_studio_BoneNode_getChildBones));
    cls->defineFunction("getBlendFunc", _SE(js_cocos2dx_studio_BoneNode_getBlendFunc));
    cls->defineFunction("getAllSubBones", _SE(js_cocos2dx_studio_BoneNode_getAllSubBones));
    cls->defineFunction("setBlendFunc", _SE(js_cocos2dx_studio_BoneNode_setBlendFunc));
    cls->defineFunction("setDebugDrawEnabled", _SE(js_cocos2dx_studio_BoneNode_setDebugDrawEnabled));
    cls->defineFunction("getVisibleSkinsRect", _SE(js_cocos2dx_studio_BoneNode_getVisibleSkinsRect));
    cls->defineFunction("getAllSubSkins", _SE(js_cocos2dx_studio_BoneNode_getAllSubSkins));
    cls->defineFunction("displaySkin", _SE(js_cocos2dx_studio_BoneNode_displaySkin));
    cls->defineFunction("isDebugDrawEnabled", _SE(js_cocos2dx_studio_BoneNode_isDebugDrawEnabled));
    cls->defineFunction("addSkin", _SE(js_cocos2dx_studio_BoneNode_addSkin));
    cls->defineFunction("getRootSkeletonNode", _SE(js_cocos2dx_studio_BoneNode_getRootSkeletonNode));
    cls->defineFunction("setDebugDrawLength", _SE(js_cocos2dx_studio_BoneNode_setDebugDrawLength));
    cls->defineFunction("getSkins", _SE(js_cocos2dx_studio_BoneNode_getSkins));
    cls->defineFunction("getVisibleSkins", _SE(js_cocos2dx_studio_BoneNode_getVisibleSkins));
    cls->defineFunction("setDebugDrawWidth", _SE(js_cocos2dx_studio_BoneNode_setDebugDrawWidth));
    cls->defineFunction("getDebugDrawLength", _SE(js_cocos2dx_studio_BoneNode_getDebugDrawLength));
    cls->defineFunction("setDebugDrawColor", _SE(js_cocos2dx_studio_BoneNode_setDebugDrawColor));
    cls->defineFunction("getDebugDrawColor", _SE(js_cocos2dx_studio_BoneNode_getDebugDrawColor));
    cls->defineFunction("ctor", _SE(js_cocos2dx_studio_BoneNode_ctor));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_BoneNode_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_BoneNode_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::BoneNode>(cls);

    __jsb_cocostudio_timeline_BoneNode_proto = cls->getProto();
    __jsb_cocostudio_timeline_BoneNode_class = cls;

    se::ScriptEngine::getInstance()->executeScriptBuffer("(function () { ccs.BoneNode.extend = cc.Class.extend; })()");
    return true;
}

se::Object* __jsb_cocostudio_timeline_SkeletonNode_proto = nullptr;
se::Class* __jsb_cocostudio_timeline_SkeletonNode_class = nullptr;

static bool js_cocos2dx_studio_SkeletonNode_getBoneNode(se::State& s)
{
    cocostudio::timeline::SkeletonNode* cobj = (cocostudio::timeline::SkeletonNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_SkeletonNode_getBoneNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_SkeletonNode_getBoneNode : Error processing arguments");
        cocostudio::timeline::BoneNode* result = cobj->getBoneNode(arg0);
        ok &= native_ptr_to_seval<cocostudio::timeline::BoneNode>((cocostudio::timeline::BoneNode*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_SkeletonNode_getBoneNode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_SkeletonNode_getBoneNode)

static bool js_cocos2dx_studio_SkeletonNode_changeSkins(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocostudio::timeline::SkeletonNode* cobj = (cocostudio::timeline::SkeletonNode*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_studio_SkeletonNode_changeSkins : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->changeSkins(arg0);
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            std::map<std::string, std::string> arg0;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->changeSkins(arg0);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_SkeletonNode_changeSkins)

static bool js_cocos2dx_studio_SkeletonNode_addSkinGroup(se::State& s)
{
    cocostudio::timeline::SkeletonNode* cobj = (cocostudio::timeline::SkeletonNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_SkeletonNode_addSkinGroup : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::map<std::string, std::string> arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_SkeletonNode_addSkinGroup : Error processing arguments");
        cobj->addSkinGroup(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_SkeletonNode_addSkinGroup)

static bool js_cocos2dx_studio_SkeletonNode_getAllSubBonesMap(se::State& s)
{
    cocostudio::timeline::SkeletonNode* cobj = (cocostudio::timeline::SkeletonNode*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_SkeletonNode_getAllSubBonesMap : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::Map<std::string, cocostudio::timeline::BoneNode *>& result = cobj->getAllSubBonesMap();
        ok &= native_ptr_to_seval<cocos2d::Map<std::basic_string<char>, cocostudio::timeline::BoneNode >&>((cocos2d::Map<std::basic_string<char>, cocostudio::timeline::BoneNode *>&)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_SkeletonNode_getAllSubBonesMap : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_SkeletonNode_getAllSubBonesMap)

static bool js_cocos2dx_studio_SkeletonNode_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::timeline::SkeletonNode::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_timeline_SkeletonNode_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_SkeletonNode_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_timeline_SkeletonNode_finalize)

static bool js_cocos2dx_studio_SkeletonNode_constructor(se::State& s)
{
    cocostudio::timeline::SkeletonNode* cobj = new (std::nothrow) cocostudio::timeline::SkeletonNode();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_SkeletonNode_constructor, __jsb_cocostudio_timeline_SkeletonNode_class, js_cocostudio_timeline_SkeletonNode_finalize)

static bool js_cocos2dx_studio_SkeletonNode_ctor(se::State& s)
{
    cocostudio::timeline::SkeletonNode* cobj = new (std::nothrow) cocostudio::timeline::SkeletonNode();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_SUB_CLS_CTOR(js_cocos2dx_studio_SkeletonNode_ctor, __jsb_cocostudio_timeline_SkeletonNode_class, js_cocostudio_timeline_SkeletonNode_finalize)


    

extern se::Object* __jsb_cocostudio_timeline_BoneNode_proto;

bool js_cocostudio_timeline_SkeletonNode_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::timeline::SkeletonNode)", s.nativeThisObject());
        cocostudio::timeline::SkeletonNode* cobj = (cocostudio::timeline::SkeletonNode*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_timeline_SkeletonNode_finalize)

bool js_register_cocos2dx_studio_SkeletonNode(se::Object* obj)
{
    auto cls = se::Class::create("SkeletonNode", obj, __jsb_cocostudio_timeline_BoneNode_proto, _SE(js_cocos2dx_studio_SkeletonNode_constructor));

    cls->defineFunction("getBoneNode", _SE(js_cocos2dx_studio_SkeletonNode_getBoneNode));
    cls->defineFunction("changeSkins", _SE(js_cocos2dx_studio_SkeletonNode_changeSkins));
    cls->defineFunction("addSkinGroup", _SE(js_cocos2dx_studio_SkeletonNode_addSkinGroup));
    cls->defineFunction("getAllSubBonesMap", _SE(js_cocos2dx_studio_SkeletonNode_getAllSubBonesMap));
    cls->defineFunction("ctor", _SE(js_cocos2dx_studio_SkeletonNode_ctor));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_SkeletonNode_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_timeline_SkeletonNode_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::timeline::SkeletonNode>(cls);

    __jsb_cocostudio_timeline_SkeletonNode_proto = cls->getProto();
    __jsb_cocostudio_timeline_SkeletonNode_class = cls;

    se::ScriptEngine::getInstance()->executeScriptBuffer("(function () { ccs.SkeletonNode.extend = cc.Class.extend; })()");
    return true;
}

se::Object* __jsb_cocostudio_ComExtensionData_proto = nullptr;
se::Class* __jsb_cocostudio_ComExtensionData_class = nullptr;

static bool js_cocos2dx_studio_ComExtensionData_setActionTag(se::State& s)
{
    cocostudio::ComExtensionData* cobj = (cocostudio::ComExtensionData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComExtensionData_setActionTag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComExtensionData_setActionTag : Error processing arguments");
        cobj->setActionTag(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComExtensionData_setActionTag)

static bool js_cocos2dx_studio_ComExtensionData_getCustomProperty(se::State& s)
{
    cocostudio::ComExtensionData* cobj = (cocostudio::ComExtensionData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComExtensionData_getCustomProperty : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = cobj->getCustomProperty();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComExtensionData_getCustomProperty : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComExtensionData_getCustomProperty)

static bool js_cocos2dx_studio_ComExtensionData_getActionTag(se::State& s)
{
    cocostudio::ComExtensionData* cobj = (cocostudio::ComExtensionData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComExtensionData_getActionTag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getActionTag();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComExtensionData_getActionTag : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComExtensionData_getActionTag)

static bool js_cocos2dx_studio_ComExtensionData_setCustomProperty(se::State& s)
{
    cocostudio::ComExtensionData* cobj = (cocostudio::ComExtensionData*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_studio_ComExtensionData_setCustomProperty : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_studio_ComExtensionData_setCustomProperty : Error processing arguments");
        cobj->setCustomProperty(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComExtensionData_setCustomProperty)

static bool js_cocos2dx_studio_ComExtensionData_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        auto result = cocostudio::ComExtensionData::create();
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocostudio_ComExtensionData_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_studio_ComExtensionData_create)

SE_DECLARE_FINALIZE_FUNC(js_cocostudio_ComExtensionData_finalize)

static bool js_cocos2dx_studio_ComExtensionData_constructor(se::State& s)
{
    cocostudio::ComExtensionData* cobj = new (std::nothrow) cocostudio::ComExtensionData();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_studio_ComExtensionData_constructor, __jsb_cocostudio_ComExtensionData_class, js_cocostudio_ComExtensionData_finalize)



extern se::Object* __jsb_cocos2d_Component_proto;

bool js_cocostudio_ComExtensionData_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocostudio::ComExtensionData)", s.nativeThisObject());
        cocostudio::ComExtensionData* cobj = (cocostudio::ComExtensionData*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocostudio_ComExtensionData_finalize)

bool js_register_cocos2dx_studio_ComExtensionData(se::Object* obj)
{
    auto cls = se::Class::create("ComExtensionData", obj, __jsb_cocos2d_Component_proto, _SE(js_cocos2dx_studio_ComExtensionData_constructor));

    cls->defineFunction("setActionTag", _SE(js_cocos2dx_studio_ComExtensionData_setActionTag));
    cls->defineFunction("getCustomProperty", _SE(js_cocos2dx_studio_ComExtensionData_getCustomProperty));
    cls->defineFunction("getActionTag", _SE(js_cocos2dx_studio_ComExtensionData_getActionTag));
    cls->defineFunction("setCustomProperty", _SE(js_cocos2dx_studio_ComExtensionData_setCustomProperty));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_studio_ComExtensionData_create));
    cls->defineFinalizedFunction(_SE(js_cocostudio_ComExtensionData_finalize));
    cls->install();
    JSBClassType::registerClass<cocostudio::ComExtensionData>(cls);

    __jsb_cocostudio_ComExtensionData_proto = cls->getProto();
    __jsb_cocostudio_ComExtensionData_class = cls;

    return true;
}

bool register_all_cocos2dx_studio(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("ccs", &nsVal))
    {
        se::Object* jsobj = se::Object::createPlainObject(false);
        nsVal.setObject(jsobj);
        obj->setProperty("ccs", nsVal);
        jsobj->release();
    }
    se::Object* ns = nsVal.toObject();

    js_register_cocos2dx_studio_BoneNode(ns);
    js_register_cocos2dx_studio_SkeletonNode(ns);
    js_register_cocos2dx_studio_Frame(ns);
    js_register_cocos2dx_studio_ScaleFrame(ns);
    js_register_cocos2dx_studio_ProcessBase(ns);
    js_register_cocos2dx_studio_Tween(ns);
    js_register_cocos2dx_studio_ContourData(ns);
    js_register_cocos2dx_studio_ComAudio(ns);
    js_register_cocos2dx_studio_ActionTimeline(ns);
    js_register_cocos2dx_studio_InnerActionFrame(ns);
    js_register_cocos2dx_studio_ActionTimelineData(ns);
    js_register_cocos2dx_studio_MovementData(ns);
    js_register_cocos2dx_studio_ArmatureDataManager(ns);
    js_register_cocos2dx_studio_ColorFrame(ns);
    js_register_cocos2dx_studio_ZOrderFrame(ns);
    js_register_cocos2dx_studio_Timeline(ns);
    js_register_cocos2dx_studio_ColliderBody(ns);
    js_register_cocos2dx_studio_InputDelegate(ns);
    js_register_cocos2dx_studio_ComController(ns);
    js_register_cocos2dx_studio_DecorativeDisplay(ns);
    js_register_cocos2dx_studio_SkewFrame(ns);
    js_register_cocos2dx_studio_RotationSkewFrame(ns);
    js_register_cocos2dx_studio_ColliderFilter(ns);
    js_register_cocos2dx_studio_VisibleFrame(ns);
    js_register_cocos2dx_studio_PositionFrame(ns);
    js_register_cocos2dx_studio_RotationFrame(ns);
    js_register_cocos2dx_studio_ColliderDetector(ns);
    js_register_cocos2dx_studio_BatchNode(ns);
    js_register_cocos2dx_studio_ActionObject(ns);
    js_register_cocos2dx_studio_Skin(ns);
    js_register_cocos2dx_studio_EventFrame(ns);
    js_register_cocos2dx_studio_ComRender(ns);
    js_register_cocos2dx_studio_DisplayManager(ns);
    js_register_cocos2dx_studio_ArmatureAnimation(ns);
    js_register_cocos2dx_studio_Armature(ns);
    js_register_cocos2dx_studio_ActionManagerEx(ns);
    js_register_cocos2dx_studio_Bone(ns);
    js_register_cocos2dx_studio_ComAttribute(ns);
    js_register_cocos2dx_studio_TextureData(ns);
    js_register_cocos2dx_studio_BlendFuncFrame(ns);
    js_register_cocos2dx_studio_AlphaFrame(ns);
    js_register_cocos2dx_studio_ComExtensionData(ns);
    js_register_cocos2dx_studio_AnimationData(ns);
    js_register_cocos2dx_studio_AnchorPointFrame(ns);
    js_register_cocos2dx_studio_TextureFrame(ns);
    js_register_cocos2dx_studio_BaseData(ns);
    return true;
}

