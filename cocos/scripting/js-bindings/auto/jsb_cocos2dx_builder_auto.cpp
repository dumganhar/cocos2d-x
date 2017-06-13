#include "scripting/js-bindings/auto/jsb_cocos2dx_builder_auto.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "editor-support/cocosbuilder/CocosBuilder.h"

se::Object* __jsb_cocosbuilder_CCBAnimationManager_proto = nullptr;
se::Class* __jsb_cocosbuilder_CCBAnimationManager_class = nullptr;

static bool js_cocos2dx_builder_CCBAnimationManager_moveAnimationsFromNode(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_moveAnimationsFromNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::Node* arg0 = nullptr;
        cocos2d::Node* arg1 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_moveAnimationsFromNode : Error processing arguments");
        cobj->moveAnimationsFromNode(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_moveAnimationsFromNode)

static bool js_cocos2dx_builder_CCBAnimationManager_setAutoPlaySequenceId(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_setAutoPlaySequenceId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_setAutoPlaySequenceId : Error processing arguments");
        cobj->setAutoPlaySequenceId(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_setAutoPlaySequenceId)

static bool js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackNames(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackNames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::ValueVector& result = cobj->getDocumentCallbackNames();
        ok &= ccvaluevector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackNames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackNames)

static bool js_cocos2dx_builder_CCBAnimationManager_actionForSoundChannel(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_actionForSoundChannel : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocosbuilder::CCBSequenceProperty* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_actionForSoundChannel : Error processing arguments");
        cocos2d::Sequence* result = cobj->actionForSoundChannel(arg0);
        ok &= native_ptr_to_seval<cocos2d::Sequence>((cocos2d::Sequence*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_actionForSoundChannel : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_actionForSoundChannel)

static bool js_cocos2dx_builder_CCBAnimationManager_setBaseValue(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_setBaseValue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        cocos2d::Value arg0;
        cocos2d::Node* arg1 = nullptr;
        std::string arg2;
        ok &= seval_to_ccvalue(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_setBaseValue : Error processing arguments");
        cobj->setBaseValue(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_setBaseValue)

static bool js_cocos2dx_builder_CCBAnimationManager_getDocumentOutletNodes(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentOutletNodes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vector<cocos2d::Node *>& result = cobj->getDocumentOutletNodes();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentOutletNodes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getDocumentOutletNodes)

static bool js_cocos2dx_builder_CCBAnimationManager_getLastCompletedSequenceName(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getLastCompletedSequenceName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = cobj->getLastCompletedSequenceName();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getLastCompletedSequenceName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getLastCompletedSequenceName)

static bool js_cocos2dx_builder_CCBAnimationManager_setRootNode(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_setRootNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Node* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_setRootNode : Error processing arguments");
        cobj->setRootNode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_setRootNode)

static bool js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceNamedTweenDuration(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceNamedTweenDuration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const char* arg0 = nullptr;
        float arg1 = 0;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= seval_to_float(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceNamedTweenDuration : Error processing arguments");
        cobj->runAnimationsForSequenceNamedTweenDuration(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceNamedTweenDuration)

static bool js_cocos2dx_builder_CCBAnimationManager_addDocumentOutletName(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_addDocumentOutletName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_addDocumentOutletName : Error processing arguments");
        cobj->addDocumentOutletName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_addDocumentOutletName)

static bool js_cocos2dx_builder_CCBAnimationManager_getRootContainerSize(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getRootContainerSize : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::Size& result = cobj->getRootContainerSize();
        ok &= Size_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getRootContainerSize : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getRootContainerSize)

static bool js_cocos2dx_builder_CCBAnimationManager_setDocumentControllerName(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_setDocumentControllerName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_setDocumentControllerName : Error processing arguments");
        cobj->setDocumentControllerName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_setDocumentControllerName)

static bool js_cocos2dx_builder_CCBAnimationManager_setObject(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_setObject : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        cocos2d::Ref* arg0 = nullptr;
        cocos2d::Node* arg1 = nullptr;
        std::string arg2;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_setObject : Error processing arguments");
        cobj->setObject(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_setObject)

static bool js_cocos2dx_builder_CCBAnimationManager_getContainerSize(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getContainerSize : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Node* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getContainerSize : Error processing arguments");
        const cocos2d::Size& result = cobj->getContainerSize(arg0);
        ok &= Size_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getContainerSize : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getContainerSize)

static bool js_cocos2dx_builder_CCBAnimationManager_actionForCallbackChannel(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_actionForCallbackChannel : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocosbuilder::CCBSequenceProperty* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_actionForCallbackChannel : Error processing arguments");
        cocos2d::Sequence* result = cobj->actionForCallbackChannel(arg0);
        ok &= native_ptr_to_seval<cocos2d::Sequence>((cocos2d::Sequence*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_actionForCallbackChannel : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_actionForCallbackChannel)

static bool js_cocos2dx_builder_CCBAnimationManager_getDocumentOutletNames(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentOutletNames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::ValueVector& result = cobj->getDocumentOutletNames();
        ok &= ccvaluevector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentOutletNames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getDocumentOutletNames)

static bool js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackControlEvents(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackControlEvents : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::extension::Control::EventType arg0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackControlEvents : Error processing arguments");
        cobj->addDocumentCallbackControlEvents(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackControlEvents)

static bool js_cocos2dx_builder_CCBAnimationManager_init(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->init();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_init)

static bool js_cocos2dx_builder_CCBAnimationManager_getKeyframeCallbacks(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getKeyframeCallbacks : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::ValueVector& result = cobj->getKeyframeCallbacks();
        ok &= ccvaluevector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getKeyframeCallbacks : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getKeyframeCallbacks)

static bool js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackControlEvents(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackControlEvents : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::ValueVector& result = cobj->getDocumentCallbackControlEvents();
        ok &= ccvaluevector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackControlEvents : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackControlEvents)

static bool js_cocos2dx_builder_CCBAnimationManager_setRootContainerSize(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_setRootContainerSize : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Size arg0;
        ok &= seval_to_Size(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_setRootContainerSize : Error processing arguments");
        cobj->setRootContainerSize(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_setRootContainerSize)

static bool js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceIdTweenDuration(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceIdTweenDuration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        ok &= seval_to_float(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceIdTweenDuration : Error processing arguments");
        cobj->runAnimationsForSequenceIdTweenDuration(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceIdTweenDuration)

static bool js_cocos2dx_builder_CCBAnimationManager_getRunningSequenceName(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getRunningSequenceName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const char* result = cobj->getRunningSequenceName();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getRunningSequenceName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getRunningSequenceName)

static bool js_cocos2dx_builder_CCBAnimationManager_getAutoPlaySequenceId(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getAutoPlaySequenceId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getAutoPlaySequenceId();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getAutoPlaySequenceId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getAutoPlaySequenceId)

static bool js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackName(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackName : Error processing arguments");
        cobj->addDocumentCallbackName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackName)

static bool js_cocos2dx_builder_CCBAnimationManager_getRootNode(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getRootNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Node* result = cobj->getRootNode();
        ok &= native_ptr_to_seval<cocos2d::Node>((cocos2d::Node*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getRootNode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getRootNode)

static bool js_cocos2dx_builder_CCBAnimationManager_addDocumentOutletNode(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_addDocumentOutletNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Node* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_addDocumentOutletNode : Error processing arguments");
        cobj->addDocumentOutletNode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_addDocumentOutletNode)

static bool js_cocos2dx_builder_CCBAnimationManager_setDelegate(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_setDelegate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocosbuilder::CCBAnimationManagerDelegate* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_setDelegate : Error processing arguments");
        cobj->setDelegate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_setDelegate)

static bool js_cocos2dx_builder_CCBAnimationManager_getSequenceDuration(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getSequenceDuration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getSequenceDuration : Error processing arguments");
        float result = cobj->getSequenceDuration(arg0);
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getSequenceDuration : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getSequenceDuration)

static bool js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackNode(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Node* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackNode : Error processing arguments");
        cobj->addDocumentCallbackNode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackNode)

static bool js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceNamed(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceNamed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceNamed : Error processing arguments");
        cobj->runAnimationsForSequenceNamed(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceNamed)

static bool js_cocos2dx_builder_CCBAnimationManager_getSequenceId(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getSequenceId : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getSequenceId : Error processing arguments");
        int result = cobj->getSequenceId(arg0);
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getSequenceId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getSequenceId)

static bool js_cocos2dx_builder_CCBAnimationManager_setCallFunc(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_setCallFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::CallFunc* arg0 = nullptr;
        std::string arg1;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_setCallFunc : Error processing arguments");
        cobj->setCallFunc(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_setCallFunc)

static bool js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackNodes(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackNodes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vector<cocos2d::Node *>& result = cobj->getDocumentCallbackNodes();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackNodes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackNodes)

static bool js_cocos2dx_builder_CCBAnimationManager_setSequences(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_setSequences : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vector<cocosbuilder::CCBSequence *> arg0;
        ok &= seval_to_Vector(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_setSequences : Error processing arguments");
        cobj->setSequences(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_setSequences)

static bool js_cocos2dx_builder_CCBAnimationManager_debug(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_debug : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->debug();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_debug)

static bool js_cocos2dx_builder_CCBAnimationManager_getDocumentControllerName(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentControllerName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = cobj->getDocumentControllerName();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBAnimationManager_getDocumentControllerName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBAnimationManager_getDocumentControllerName)

SE_DECLARE_FINALIZE_FUNC(js_cocosbuilder_CCBAnimationManager_finalize)

static bool js_cocos2dx_builder_CCBAnimationManager_constructor(se::State& s)
{
    cocosbuilder::CCBAnimationManager* cobj = new (std::nothrow) cocosbuilder::CCBAnimationManager();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_builder_CCBAnimationManager_constructor, __jsb_cocosbuilder_CCBAnimationManager_class, js_cocosbuilder_CCBAnimationManager_finalize)




bool js_cocosbuilder_CCBAnimationManager_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocosbuilder::CCBAnimationManager)", s.nativeThisObject());
        cocosbuilder::CCBAnimationManager* cobj = (cocosbuilder::CCBAnimationManager*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocosbuilder_CCBAnimationManager_finalize)

bool js_register_cocos2dx_builder_CCBAnimationManager(se::Object* obj)
{
    auto cls = se::Class::create("BuilderAnimationManager", obj, nullptr, _SE(js_cocos2dx_builder_CCBAnimationManager_constructor));

    cls->defineFunction("moveAnimationsFromNode", _SE(js_cocos2dx_builder_CCBAnimationManager_moveAnimationsFromNode));
    cls->defineFunction("setAutoPlaySequenceId", _SE(js_cocos2dx_builder_CCBAnimationManager_setAutoPlaySequenceId));
    cls->defineFunction("getDocumentCallbackNames", _SE(js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackNames));
    cls->defineFunction("actionForSoundChannel", _SE(js_cocos2dx_builder_CCBAnimationManager_actionForSoundChannel));
    cls->defineFunction("setBaseValue", _SE(js_cocos2dx_builder_CCBAnimationManager_setBaseValue));
    cls->defineFunction("getDocumentOutletNodes", _SE(js_cocos2dx_builder_CCBAnimationManager_getDocumentOutletNodes));
    cls->defineFunction("getLastCompletedSequenceName", _SE(js_cocos2dx_builder_CCBAnimationManager_getLastCompletedSequenceName));
    cls->defineFunction("setRootNode", _SE(js_cocos2dx_builder_CCBAnimationManager_setRootNode));
    cls->defineFunction("runAnimationsForSequenceNamedTweenDuration", _SE(js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceNamedTweenDuration));
    cls->defineFunction("addDocumentOutletName", _SE(js_cocos2dx_builder_CCBAnimationManager_addDocumentOutletName));
    cls->defineFunction("getRootContainerSize", _SE(js_cocos2dx_builder_CCBAnimationManager_getRootContainerSize));
    cls->defineFunction("setDocumentControllerName", _SE(js_cocos2dx_builder_CCBAnimationManager_setDocumentControllerName));
    cls->defineFunction("setObject", _SE(js_cocos2dx_builder_CCBAnimationManager_setObject));
    cls->defineFunction("getContainerSize", _SE(js_cocos2dx_builder_CCBAnimationManager_getContainerSize));
    cls->defineFunction("actionForCallbackChannel", _SE(js_cocos2dx_builder_CCBAnimationManager_actionForCallbackChannel));
    cls->defineFunction("getDocumentOutletNames", _SE(js_cocos2dx_builder_CCBAnimationManager_getDocumentOutletNames));
    cls->defineFunction("addDocumentCallbackControlEvents", _SE(js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackControlEvents));
    cls->defineFunction("init", _SE(js_cocos2dx_builder_CCBAnimationManager_init));
    cls->defineFunction("getKeyframeCallbacks", _SE(js_cocos2dx_builder_CCBAnimationManager_getKeyframeCallbacks));
    cls->defineFunction("getDocumentCallbackControlEvents", _SE(js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackControlEvents));
    cls->defineFunction("setRootContainerSize", _SE(js_cocos2dx_builder_CCBAnimationManager_setRootContainerSize));
    cls->defineFunction("runAnimationsForSequenceIdTweenDuration", _SE(js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceIdTweenDuration));
    cls->defineFunction("getRunningSequenceName", _SE(js_cocos2dx_builder_CCBAnimationManager_getRunningSequenceName));
    cls->defineFunction("getAutoPlaySequenceId", _SE(js_cocos2dx_builder_CCBAnimationManager_getAutoPlaySequenceId));
    cls->defineFunction("addDocumentCallbackName", _SE(js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackName));
    cls->defineFunction("getRootNode", _SE(js_cocos2dx_builder_CCBAnimationManager_getRootNode));
    cls->defineFunction("addDocumentOutletNode", _SE(js_cocos2dx_builder_CCBAnimationManager_addDocumentOutletNode));
    cls->defineFunction("setDelegate", _SE(js_cocos2dx_builder_CCBAnimationManager_setDelegate));
    cls->defineFunction("getSequenceDuration", _SE(js_cocos2dx_builder_CCBAnimationManager_getSequenceDuration));
    cls->defineFunction("addDocumentCallbackNode", _SE(js_cocos2dx_builder_CCBAnimationManager_addDocumentCallbackNode));
    cls->defineFunction("runAnimationsForSequenceNamed", _SE(js_cocos2dx_builder_CCBAnimationManager_runAnimationsForSequenceNamed));
    cls->defineFunction("getSequenceId", _SE(js_cocos2dx_builder_CCBAnimationManager_getSequenceId));
    cls->defineFunction("setCallFunc", _SE(js_cocos2dx_builder_CCBAnimationManager_setCallFunc));
    cls->defineFunction("getDocumentCallbackNodes", _SE(js_cocos2dx_builder_CCBAnimationManager_getDocumentCallbackNodes));
    cls->defineFunction("setSequences", _SE(js_cocos2dx_builder_CCBAnimationManager_setSequences));
    cls->defineFunction("debug", _SE(js_cocos2dx_builder_CCBAnimationManager_debug));
    cls->defineFunction("getDocumentControllerName", _SE(js_cocos2dx_builder_CCBAnimationManager_getDocumentControllerName));
    cls->defineFinalizedFunction(_SE(js_cocosbuilder_CCBAnimationManager_finalize));
    cls->install();
    JSBClassType::registerClass<cocosbuilder::CCBAnimationManager>(cls);

    __jsb_cocosbuilder_CCBAnimationManager_proto = cls->getProto();
    __jsb_cocosbuilder_CCBAnimationManager_class = cls;

    return true;
}

se::Object* __jsb_cocosbuilder_CCBReader_proto = nullptr;
se::Class* __jsb_cocosbuilder_CCBReader_class = nullptr;

static bool js_cocos2dx_builder_CCBReader_readNodeGraphFromFile(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_builder_CCBReader_readNodeGraphFromFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            cocos2d::Ref* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Node* result = cobj->readNodeGraphFromFile(arg0, arg1);
            ok &= native_ptr_to_seval<cocos2d::Node>((cocos2d::Node*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_readNodeGraphFromFile : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            cocos2d::Node* result = cobj->readNodeGraphFromFile(arg0);
            ok &= native_ptr_to_seval<cocos2d::Node>((cocos2d::Node*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_readNodeGraphFromFile : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            cocos2d::Ref* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Size arg2;
            ok &= seval_to_Size(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Node* result = cobj->readNodeGraphFromFile(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<cocos2d::Node>((cocos2d::Node*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_readNodeGraphFromFile : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_readNodeGraphFromFile)

static bool js_cocos2dx_builder_CCBReader_getAnimationManager(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_getAnimationManager : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocosbuilder::CCBAnimationManager* result = cobj->getAnimationManager();
        ok &= native_ptr_to_seval<cocosbuilder::CCBAnimationManager>((cocosbuilder::CCBAnimationManager*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_getAnimationManager : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_getAnimationManager)

static bool js_cocos2dx_builder_CCBReader_setAnimationManager(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_setAnimationManager : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocosbuilder::CCBAnimationManager* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_setAnimationManager : Error processing arguments");
        cobj->setAnimationManager(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_setAnimationManager)

static bool js_cocos2dx_builder_CCBReader_addOwnerOutletName(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_addOwnerOutletName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_addOwnerOutletName : Error processing arguments");
        cobj->addOwnerOutletName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_addOwnerOutletName)

static bool js_cocos2dx_builder_CCBReader_getOwnerCallbackNames(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_getOwnerCallbackNames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::ValueVector result = cobj->getOwnerCallbackNames();
        ok &= ccvaluevector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_getOwnerCallbackNames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_getOwnerCallbackNames)

static bool js_cocos2dx_builder_CCBReader_addDocumentCallbackControlEvents(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_addDocumentCallbackControlEvents : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::extension::Control::EventType arg0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_addDocumentCallbackControlEvents : Error processing arguments");
        cobj->addDocumentCallbackControlEvents(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_addDocumentCallbackControlEvents)

static bool js_cocos2dx_builder_CCBReader_setCCBRootPath(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_setCCBRootPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_setCCBRootPath : Error processing arguments");
        cobj->setCCBRootPath(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_setCCBRootPath)

static bool js_cocos2dx_builder_CCBReader_addOwnerOutletNode(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_addOwnerOutletNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Node* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_addOwnerOutletNode : Error processing arguments");
        cobj->addOwnerOutletNode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_addOwnerOutletNode)

static bool js_cocos2dx_builder_CCBReader_getOwnerCallbackNodes(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_getOwnerCallbackNodes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vector<cocos2d::Node *>& result = cobj->getOwnerCallbackNodes();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_getOwnerCallbackNodes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_getOwnerCallbackNodes)

static bool js_cocos2dx_builder_CCBReader_readSoundKeyframesForSeq(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_readSoundKeyframesForSeq : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocosbuilder::CCBSequence* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_readSoundKeyframesForSeq : Error processing arguments");
        bool result = cobj->readSoundKeyframesForSeq(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_readSoundKeyframesForSeq : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_readSoundKeyframesForSeq)

static bool js_cocos2dx_builder_CCBReader_getCCBRootPath(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_getCCBRootPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getCCBRootPath();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_getCCBRootPath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_getCCBRootPath)

static bool js_cocos2dx_builder_CCBReader_createSceneWithNodeGraphFromFile(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_builder_CCBReader_createSceneWithNodeGraphFromFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            cocos2d::Ref* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Scene* result = cobj->createSceneWithNodeGraphFromFile(arg0, arg1);
            ok &= native_ptr_to_seval<cocos2d::Scene>((cocos2d::Scene*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_createSceneWithNodeGraphFromFile : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            cocos2d::Scene* result = cobj->createSceneWithNodeGraphFromFile(arg0);
            ok &= native_ptr_to_seval<cocos2d::Scene>((cocos2d::Scene*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_createSceneWithNodeGraphFromFile : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            cocos2d::Ref* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Size arg2;
            ok &= seval_to_Size(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Scene* result = cobj->createSceneWithNodeGraphFromFile(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<cocos2d::Scene>((cocos2d::Scene*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_createSceneWithNodeGraphFromFile : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_createSceneWithNodeGraphFromFile)

static bool js_cocos2dx_builder_CCBReader_getOwnerCallbackControlEvents(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_getOwnerCallbackControlEvents : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::ValueVector& result = cobj->getOwnerCallbackControlEvents();
        ok &= ccvaluevector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_getOwnerCallbackControlEvents : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_getOwnerCallbackControlEvents)

static bool js_cocos2dx_builder_CCBReader_getOwnerOutletNodes(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_getOwnerOutletNodes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vector<cocos2d::Node *>& result = cobj->getOwnerOutletNodes();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_getOwnerOutletNodes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_getOwnerOutletNodes)

static bool js_cocos2dx_builder_CCBReader_readUTF8(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_readUTF8 : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = cobj->readUTF8();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_readUTF8 : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_readUTF8)

static bool js_cocos2dx_builder_CCBReader_addOwnerCallbackControlEvents(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_addOwnerCallbackControlEvents : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::extension::Control::EventType arg0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_addOwnerCallbackControlEvents : Error processing arguments");
        cobj->addOwnerCallbackControlEvents(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_addOwnerCallbackControlEvents)

static bool js_cocos2dx_builder_CCBReader_getOwnerOutletNames(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_getOwnerOutletNames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::ValueVector result = cobj->getOwnerOutletNames();
        ok &= ccvaluevector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_getOwnerOutletNames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_getOwnerOutletNames)

static bool js_cocos2dx_builder_CCBReader_readCallbackKeyframesForSeq(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_readCallbackKeyframesForSeq : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocosbuilder::CCBSequence* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_readCallbackKeyframesForSeq : Error processing arguments");
        bool result = cobj->readCallbackKeyframesForSeq(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_readCallbackKeyframesForSeq : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_readCallbackKeyframesForSeq)

static bool js_cocos2dx_builder_CCBReader_getAnimationManagersForNodes(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_getAnimationManagersForNodes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vector<cocosbuilder::CCBAnimationManager *>& result = cobj->getAnimationManagersForNodes();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_getAnimationManagersForNodes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_getAnimationManagersForNodes)

static bool js_cocos2dx_builder_CCBReader_getNodesWithAnimationManagers(se::State& s)
{
    cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_builder_CCBReader_getNodesWithAnimationManagers : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vector<cocos2d::Node *>& result = cobj->getNodesWithAnimationManagers();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_getNodesWithAnimationManagers : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_getNodesWithAnimationManagers)

static bool js_cocos2dx_builder_CCBReader_setResolutionScale(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_builder_CCBReader_setResolutionScale : Error processing arguments");
        cocosbuilder::CCBReader::setResolutionScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_builder_CCBReader_setResolutionScale)

SE_DECLARE_FINALIZE_FUNC(js_cocosbuilder_CCBReader_finalize)

static bool js_cocos2dx_builder_CCBReader_constructor(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            cocosbuilder::CCBReader* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocosbuilder::CCBReader* cobj = new (std::nothrow) cocosbuilder::CCBReader(arg0);
            s.thisObject()->setPrivateData(cobj);
            s.thisObject()->addRef();
            return true;
        }
    } while(false);
    do {
        if (argc == 4) {
            cocosbuilder::NodeLoaderLibrary* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocosbuilder::CCBMemberVariableAssigner* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocosbuilder::CCBSelectorResolver* arg2 = nullptr;
            ok &= seval_to_native_ptr(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocosbuilder::NodeLoaderListener* arg3 = nullptr;
            ok &= seval_to_native_ptr(args[3], &arg3);
            if (!ok) { ok = true; break; }
            cocosbuilder::CCBReader* cobj = new (std::nothrow) cocosbuilder::CCBReader(arg0, arg1, arg2, arg3);
            s.thisObject()->setPrivateData(cobj);
            s.thisObject()->addRef();
            return true;
        }
    } while(false);
    do {
        if (argc == 0) {
            cocosbuilder::CCBReader* cobj = new (std::nothrow) cocosbuilder::CCBReader();
            s.thisObject()->setPrivateData(cobj);
            s.thisObject()->addRef();
            return true;
        }
    } while(false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_CTOR(js_cocos2dx_builder_CCBReader_constructor, __jsb_cocosbuilder_CCBReader_class, js_cocosbuilder_CCBReader_finalize)




bool js_cocosbuilder_CCBReader_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocosbuilder::CCBReader)", s.nativeThisObject());
        cocosbuilder::CCBReader* cobj = (cocosbuilder::CCBReader*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocosbuilder_CCBReader_finalize)

bool js_register_cocos2dx_builder_CCBReader(se::Object* obj)
{
    auto cls = se::Class::create("_Reader", obj, nullptr, _SE(js_cocos2dx_builder_CCBReader_constructor));

    cls->defineFunction("load", _SE(js_cocos2dx_builder_CCBReader_readNodeGraphFromFile));
    cls->defineFunction("getAnimationManager", _SE(js_cocos2dx_builder_CCBReader_getAnimationManager));
    cls->defineFunction("setAnimationManager", _SE(js_cocos2dx_builder_CCBReader_setAnimationManager));
    cls->defineFunction("addOwnerOutletName", _SE(js_cocos2dx_builder_CCBReader_addOwnerOutletName));
    cls->defineFunction("getOwnerCallbackNames", _SE(js_cocos2dx_builder_CCBReader_getOwnerCallbackNames));
    cls->defineFunction("addDocumentCallbackControlEvents", _SE(js_cocos2dx_builder_CCBReader_addDocumentCallbackControlEvents));
    cls->defineFunction("setCCBRootPath", _SE(js_cocos2dx_builder_CCBReader_setCCBRootPath));
    cls->defineFunction("addOwnerOutletNode", _SE(js_cocos2dx_builder_CCBReader_addOwnerOutletNode));
    cls->defineFunction("getOwnerCallbackNodes", _SE(js_cocos2dx_builder_CCBReader_getOwnerCallbackNodes));
    cls->defineFunction("readSoundKeyframesForSeq", _SE(js_cocos2dx_builder_CCBReader_readSoundKeyframesForSeq));
    cls->defineFunction("getCCBRootPath", _SE(js_cocos2dx_builder_CCBReader_getCCBRootPath));
    cls->defineFunction("loadScene", _SE(js_cocos2dx_builder_CCBReader_createSceneWithNodeGraphFromFile));
    cls->defineFunction("getOwnerCallbackControlEvents", _SE(js_cocos2dx_builder_CCBReader_getOwnerCallbackControlEvents));
    cls->defineFunction("getOwnerOutletNodes", _SE(js_cocos2dx_builder_CCBReader_getOwnerOutletNodes));
    cls->defineFunction("readUTF8", _SE(js_cocos2dx_builder_CCBReader_readUTF8));
    cls->defineFunction("addOwnerCallbackControlEvents", _SE(js_cocos2dx_builder_CCBReader_addOwnerCallbackControlEvents));
    cls->defineFunction("getOwnerOutletNames", _SE(js_cocos2dx_builder_CCBReader_getOwnerOutletNames));
    cls->defineFunction("readCallbackKeyframesForSeq", _SE(js_cocos2dx_builder_CCBReader_readCallbackKeyframesForSeq));
    cls->defineFunction("getAnimationManagersForNodes", _SE(js_cocos2dx_builder_CCBReader_getAnimationManagersForNodes));
    cls->defineFunction("getNodesWithAnimationManagers", _SE(js_cocos2dx_builder_CCBReader_getNodesWithAnimationManagers));
    cls->defineStaticFunction("setResolutionScale", _SE(js_cocos2dx_builder_CCBReader_setResolutionScale));
    cls->defineFinalizedFunction(_SE(js_cocosbuilder_CCBReader_finalize));
    cls->install();
    JSBClassType::registerClass<cocosbuilder::CCBReader>(cls);

    __jsb_cocosbuilder_CCBReader_proto = cls->getProto();
    __jsb_cocosbuilder_CCBReader_class = cls;

    return true;
}

bool register_all_cocos2dx_builder(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("cc", &nsVal))
    {
        se::Object* jsobj = se::Object::createPlainObject(false);
        nsVal.setObject(jsobj);
        obj->setProperty("cc", nsVal);
        jsobj->release();
    }
    se::Object* ns = nsVal.toObject();

    js_register_cocos2dx_builder_CCBAnimationManager(ns);
    js_register_cocos2dx_builder_CCBReader(ns);
    return true;
}

