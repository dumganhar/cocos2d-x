#include "scripting/js-bindings/auto/jsb_cocos2dx_3d_extension_auto.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "cocos-ext.h"

se::Object* __jsb_cocos2d_ParticleSystem3D_proto = nullptr;
se::Class* __jsb_cocos2d_ParticleSystem3D_class = nullptr;

static bool js_cocos2dx_3d_extension_ParticleSystem3D_resumeParticleSystem(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_resumeParticleSystem : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->resumeParticleSystem();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_resumeParticleSystem)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_startParticleSystem(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_startParticleSystem : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->startParticleSystem();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_startParticleSystem)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_isEnabled(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_isEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isEnabled();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_ParticleSystem3D_isEnabled : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_isEnabled)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_getRender(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_getRender : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Particle3DRender* result = cobj->getRender();
        ok &= native_ptr_to_seval<cocos2d::Particle3DRender>((cocos2d::Particle3DRender*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_ParticleSystem3D_getRender : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_getRender)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_isKeepLocal(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_isKeepLocal : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isKeepLocal();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_ParticleSystem3D_isKeepLocal : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_isKeepLocal)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_setEnabled(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_setEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_ParticleSystem3D_setEnabled : Error processing arguments");
        cobj->setEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_setEnabled)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_getParticleQuota(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_getParticleQuota : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getParticleQuota();
        ok &= uint32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_ParticleSystem3D_getParticleQuota : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_getParticleQuota)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_getBlendFunc(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_getBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::BlendFunc& result = cobj->getBlendFunc();
        ok &= blendfunc_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_ParticleSystem3D_getBlendFunc : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_getBlendFunc)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_pauseParticleSystem(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_pauseParticleSystem : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->pauseParticleSystem();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_pauseParticleSystem)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_getState(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_getState : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getState();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_ParticleSystem3D_getState : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_getState)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_getAliveParticleCount(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_getAliveParticleCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getAliveParticleCount();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_ParticleSystem3D_getAliveParticleCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_getAliveParticleCount)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_setParticleQuota(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_setParticleQuota : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_ParticleSystem3D_setParticleQuota : Error processing arguments");
        cobj->setParticleQuota(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_setParticleQuota)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_setBlendFunc(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_setBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::BlendFunc arg0;
        ok &= seval_to_blendfunc(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_ParticleSystem3D_setBlendFunc : Error processing arguments");
        cobj->setBlendFunc(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_setBlendFunc)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_stopParticleSystem(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_stopParticleSystem : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stopParticleSystem();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_stopParticleSystem)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_setKeepLocal(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_ParticleSystem3D_setKeepLocal : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_ParticleSystem3D_setKeepLocal : Error processing arguments");
        cobj->setKeepLocal(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_ParticleSystem3D_setKeepLocal)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_ParticleSystem3D_finalize)

static bool js_cocos2dx_3d_extension_ParticleSystem3D_constructor(se::State& s)
{
    cocos2d::ParticleSystem3D* cobj = new (std::nothrow) cocos2d::ParticleSystem3D();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_extension_ParticleSystem3D_constructor, __jsb_cocos2d_ParticleSystem3D_class, js_cocos2d_ParticleSystem3D_finalize)



extern se::Object* __jsb_cocos2d_Node_proto;

bool js_cocos2d_ParticleSystem3D_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::ParticleSystem3D)", s.nativeThisObject());
        cocos2d::ParticleSystem3D* cobj = (cocos2d::ParticleSystem3D*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_ParticleSystem3D_finalize)

bool js_register_cocos2dx_3d_extension_ParticleSystem3D(se::Object* obj)
{
    auto cls = se::Class::create("ParticleSystem3D", obj, __jsb_cocos2d_Node_proto, _SE(js_cocos2dx_3d_extension_ParticleSystem3D_constructor));

    cls->defineFunction("resumeParticleSystem", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_resumeParticleSystem));
    cls->defineFunction("startParticleSystem", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_startParticleSystem));
    cls->defineFunction("isEnabled", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_isEnabled));
    cls->defineFunction("getRender", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_getRender));
    cls->defineFunction("isKeepLocal", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_isKeepLocal));
    cls->defineFunction("setEnabled", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_setEnabled));
    cls->defineFunction("getParticleQuota", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_getParticleQuota));
    cls->defineFunction("getBlendFunc", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_getBlendFunc));
    cls->defineFunction("pauseParticleSystem", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_pauseParticleSystem));
    cls->defineFunction("getState", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_getState));
    cls->defineFunction("getAliveParticleCount", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_getAliveParticleCount));
    cls->defineFunction("setParticleQuota", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_setParticleQuota));
    cls->defineFunction("setBlendFunc", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_setBlendFunc));
    cls->defineFunction("stopParticleSystem", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_stopParticleSystem));
    cls->defineFunction("setKeepLocal", _SE(js_cocos2dx_3d_extension_ParticleSystem3D_setKeepLocal));
    cls->defineFinalizedFunction(_SE(js_cocos2d_ParticleSystem3D_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::ParticleSystem3D>(cls);

    __jsb_cocos2d_ParticleSystem3D_proto = cls->getProto();
    __jsb_cocos2d_ParticleSystem3D_class = cls;

    return true;
}

se::Object* __jsb_cocos2d_PUParticleSystem3D_proto = nullptr;
se::Class* __jsb_cocos2d_PUParticleSystem3D_class = nullptr;

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePath(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePath : Error processing arguments");
        bool result = cobj->initWithFilePath(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePath)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getParticleSystemScaleVelocity(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getParticleSystemScaleVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getParticleSystemScaleVelocity();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getParticleSystemScaleVelocity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getParticleSystemScaleVelocity)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_setEmittedSystemQuota(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setEmittedSystemQuota : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setEmittedSystemQuota : Error processing arguments");
        cobj->setEmittedSystemQuota(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_setEmittedSystemQuota)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultDepth(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultDepth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDefaultDepth();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultDepth : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultDepth)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getEmittedSystemQuota(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getEmittedSystemQuota : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getEmittedSystemQuota();
        ok &= uint32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getEmittedSystemQuota : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getEmittedSystemQuota)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePathAndMaterialPath(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePathAndMaterialPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePathAndMaterialPath : Error processing arguments");
        bool result = cobj->initWithFilePathAndMaterialPath(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePathAndMaterialPath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePathAndMaterialPath)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_clearAllParticles(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_clearAllParticles : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->clearAllParticles();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_clearAllParticles)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getMaterialName(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getMaterialName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getMaterialName();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getMaterialName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getMaterialName)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_calulateRotationOffset(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_calulateRotationOffset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->calulateRotationOffset();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_calulateRotationOffset)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getMaxVelocity(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getMaxVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMaxVelocity();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getMaxVelocity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getMaxVelocity)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_forceUpdate(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_forceUpdate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_forceUpdate : Error processing arguments");
        cobj->forceUpdate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_forceUpdate)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getTimeElapsedSinceStart(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getTimeElapsedSinceStart : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTimeElapsedSinceStart();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getTimeElapsedSinceStart : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getTimeElapsedSinceStart)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getEmittedEmitterQuota(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getEmittedEmitterQuota : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getEmittedEmitterQuota();
        ok &= uint32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getEmittedEmitterQuota : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getEmittedEmitterQuota)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_isMarkedForEmission(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_isMarkedForEmission : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isMarkedForEmission();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_isMarkedForEmission : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_isMarkedForEmission)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultWidth(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDefaultWidth();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultWidth : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultWidth)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_setEmittedEmitterQuota(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setEmittedEmitterQuota : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setEmittedEmitterQuota : Error processing arguments");
        cobj->setEmittedEmitterQuota(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_setEmittedEmitterQuota)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_setMarkedForEmission(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setMarkedForEmission : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setMarkedForEmission : Error processing arguments");
        cobj->setMarkedForEmission(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_setMarkedForEmission)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_clone(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_clone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::PUParticleSystem3D* result = cobj->clone();
        ok &= native_ptr_to_seval<cocos2d::PUParticleSystem3D>((cocos2d::PUParticleSystem3D*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_clone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_clone)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultWidth(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultWidth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultWidth : Error processing arguments");
        cobj->setDefaultWidth(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultWidth)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_copyAttributesTo(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_copyAttributesTo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::PUParticleSystem3D* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_copyAttributesTo : Error processing arguments");
        cobj->copyAttributesTo(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_copyAttributesTo)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_setMaterialName(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setMaterialName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setMaterialName : Error processing arguments");
        cobj->setMaterialName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_setMaterialName)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getParentParticleSystem(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getParentParticleSystem : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::PUParticleSystem3D* result = cobj->getParentParticleSystem();
        ok &= native_ptr_to_seval<cocos2d::PUParticleSystem3D>((cocos2d::PUParticleSystem3D*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getParentParticleSystem : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getParentParticleSystem)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_setMaxVelocity(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setMaxVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setMaxVelocity : Error processing arguments");
        cobj->setMaxVelocity(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_setMaxVelocity)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultHeight(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDefaultHeight();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultHeight)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedPosition(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedPosition : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getDerivedPosition();
        ok &= Vec3_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedPosition : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedPosition)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_rotationOffset(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_rotationOffset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_rotationOffset : Error processing arguments");
        cobj->rotationOffset(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_rotationOffset)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedOrientation(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedOrientation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Quaternion result = cobj->getDerivedOrientation();
        ok &= Quaternion_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedOrientation : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedOrientation)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_removeAllEmitter(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_removeAllEmitter : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->removeAllEmitter();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_removeAllEmitter)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_setParticleSystemScaleVelocity(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setParticleSystemScaleVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setParticleSystemScaleVelocity : Error processing arguments");
        cobj->setParticleSystemScaleVelocity(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_setParticleSystemScaleVelocity)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedScale(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getDerivedScale();
        ok &= Vec3_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedScale : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedScale)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultHeight(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultHeight : Error processing arguments");
        cobj->setDefaultHeight(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultHeight)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_removeAllListener(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_removeAllListener : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->removeAllListener();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_removeAllListener)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_initSystem(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_initSystem : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_initSystem : Error processing arguments");
        bool result = cobj->initSystem(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_initSystem : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_initSystem)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultDepth(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultDepth : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultDepth : Error processing arguments");
        cobj->setDefaultDepth(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultDepth)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::PUParticleSystem3D* result = cocos2d::PUParticleSystem3D::create(arg0);
            ok &= native_ptr_to_seval<cocos2d::PUParticleSystem3D>((cocos2d::PUParticleSystem3D*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            cocos2d::PUParticleSystem3D* result = cocos2d::PUParticleSystem3D::create();
            ok &= native_ptr_to_seval<cocos2d::PUParticleSystem3D>((cocos2d::PUParticleSystem3D*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::PUParticleSystem3D* result = cocos2d::PUParticleSystem3D::create(arg0, arg1);
            ok &= native_ptr_to_seval<cocos2d::PUParticleSystem3D>((cocos2d::PUParticleSystem3D*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_extension_PUParticleSystem3D_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_extension_PUParticleSystem3D_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_PUParticleSystem3D_finalize)

static bool js_cocos2dx_3d_extension_PUParticleSystem3D_constructor(se::State& s)
{
    cocos2d::PUParticleSystem3D* cobj = new (std::nothrow) cocos2d::PUParticleSystem3D();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_extension_PUParticleSystem3D_constructor, __jsb_cocos2d_PUParticleSystem3D_class, js_cocos2d_PUParticleSystem3D_finalize)



extern se::Object* __jsb_cocos2d_ParticleSystem3D_proto;

bool js_cocos2d_PUParticleSystem3D_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::PUParticleSystem3D)", s.nativeThisObject());
        cocos2d::PUParticleSystem3D* cobj = (cocos2d::PUParticleSystem3D*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_PUParticleSystem3D_finalize)

bool js_register_cocos2dx_3d_extension_PUParticleSystem3D(se::Object* obj)
{
    auto cls = se::Class::create("PUParticleSystem3D", obj, __jsb_cocos2d_ParticleSystem3D_proto, _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_constructor));

    cls->defineFunction("initWithFilePath", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePath));
    cls->defineFunction("getParticleSystemScaleVelocity", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getParticleSystemScaleVelocity));
    cls->defineFunction("setEmittedSystemQuota", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_setEmittedSystemQuota));
    cls->defineFunction("getDefaultDepth", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultDepth));
    cls->defineFunction("getEmittedSystemQuota", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getEmittedSystemQuota));
    cls->defineFunction("initWithFilePathAndMaterialPath", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_initWithFilePathAndMaterialPath));
    cls->defineFunction("clearAllParticles", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_clearAllParticles));
    cls->defineFunction("getMaterialName", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getMaterialName));
    cls->defineFunction("calulateRotationOffset", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_calulateRotationOffset));
    cls->defineFunction("getMaxVelocity", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getMaxVelocity));
    cls->defineFunction("forceUpdate", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_forceUpdate));
    cls->defineFunction("getTimeElapsedSinceStart", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getTimeElapsedSinceStart));
    cls->defineFunction("getEmittedEmitterQuota", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getEmittedEmitterQuota));
    cls->defineFunction("isMarkedForEmission", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_isMarkedForEmission));
    cls->defineFunction("getDefaultWidth", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultWidth));
    cls->defineFunction("setEmittedEmitterQuota", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_setEmittedEmitterQuota));
    cls->defineFunction("setMarkedForEmission", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_setMarkedForEmission));
    cls->defineFunction("clone", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_clone));
    cls->defineFunction("setDefaultWidth", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultWidth));
    cls->defineFunction("copyAttributesTo", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_copyAttributesTo));
    cls->defineFunction("setMaterialName", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_setMaterialName));
    cls->defineFunction("getParentParticleSystem", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getParentParticleSystem));
    cls->defineFunction("setMaxVelocity", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_setMaxVelocity));
    cls->defineFunction("getDefaultHeight", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getDefaultHeight));
    cls->defineFunction("getDerivedPosition", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedPosition));
    cls->defineFunction("rotationOffset", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_rotationOffset));
    cls->defineFunction("getDerivedOrientation", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedOrientation));
    cls->defineFunction("removeAllEmitter", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_removeAllEmitter));
    cls->defineFunction("setParticleSystemScaleVelocity", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_setParticleSystemScaleVelocity));
    cls->defineFunction("getDerivedScale", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_getDerivedScale));
    cls->defineFunction("setDefaultHeight", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultHeight));
    cls->defineFunction("removeAllListener", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_removeAllListener));
    cls->defineFunction("initSystem", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_initSystem));
    cls->defineFunction("setDefaultDepth", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_setDefaultDepth));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_3d_extension_PUParticleSystem3D_create));
    cls->defineFinalizedFunction(_SE(js_cocos2d_PUParticleSystem3D_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::PUParticleSystem3D>(cls);

    __jsb_cocos2d_PUParticleSystem3D_proto = cls->getProto();
    __jsb_cocos2d_PUParticleSystem3D_class = cls;

    return true;
}

bool register_all_cocos2dx_3d_extension(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("jsb", &nsVal))
    {
        se::Object* jsobj = se::Object::createPlainObject(false);
        nsVal.setObject(jsobj);
        obj->setProperty("jsb", nsVal);
        jsobj->release();
    }
    se::Object* ns = nsVal.toObject();

    js_register_cocos2dx_3d_extension_ParticleSystem3D(ns);
    js_register_cocos2dx_3d_extension_PUParticleSystem3D(ns);
    return true;
}

