#include "scripting/js-bindings/auto/jsb_cocos2dx_3d_auto.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "cocos2d.h"
#include "3d/CCBundle3D.h"


se::Object* __jsb_cocos2d_Animation3D_proto = nullptr;
se::Class* __jsb_cocos2d_Animation3D_class = nullptr;

static bool js_cocos2dx_3d_Animation3D_initWithFile(se::State& s)
{
    cocos2d::Animation3D* cobj = (cocos2d::Animation3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animation3D_initWithFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animation3D_initWithFile : Error processing arguments");
        bool result = cobj->initWithFile(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animation3D_initWithFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animation3D_initWithFile)

static bool js_cocos2dx_3d_Animation3D_init(se::State& s)
{
    cocos2d::Animation3D* cobj = (cocos2d::Animation3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animation3D_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Animation3DData arg0;
        #pragma warning NO CONVERSION TO NATIVE FOR Animation3DData
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animation3D_init : Error processing arguments");
        bool result = cobj->init(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animation3D_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animation3D_init)

static bool js_cocos2dx_3d_Animation3D_getBoneCurveByName(se::State& s)
{
    cocos2d::Animation3D* cobj = (cocos2d::Animation3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animation3D_getBoneCurveByName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animation3D_getBoneCurveByName : Error processing arguments");
        cocos2d::Animation3D::Curve* result = cobj->getBoneCurveByName(arg0);
        ok &= native_ptr_to_seval<cocos2d::Animation3D::Curve>((cocos2d::Animation3D::Curve*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animation3D_getBoneCurveByName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animation3D_getBoneCurveByName)

static bool js_cocos2dx_3d_Animation3D_getDuration(se::State& s)
{
    cocos2d::Animation3D* cobj = (cocos2d::Animation3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animation3D_getDuration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDuration();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animation3D_getDuration : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animation3D_getDuration)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Animation3D_finalize)

static bool js_cocos2dx_3d_Animation3D_constructor(se::State& s)
{
    cocos2d::Animation3D* cobj = new (std::nothrow) cocos2d::Animation3D();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_Animation3D_constructor, __jsb_cocos2d_Animation3D_class, js_cocos2d_Animation3D_finalize)




bool js_cocos2d_Animation3D_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::Animation3D)", s.nativeThisObject());
        cocos2d::Animation3D* cobj = (cocos2d::Animation3D*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Animation3D_finalize)

bool js_register_cocos2dx_3d_Animation3D(se::Object* obj)
{
    auto cls = se::Class::create("Animation3D", obj, nullptr, _SE(js_cocos2dx_3d_Animation3D_constructor));

    cls->defineFunction("initWithFile", _SE(js_cocos2dx_3d_Animation3D_initWithFile));
    cls->defineFunction("init", _SE(js_cocos2dx_3d_Animation3D_init));
    cls->defineFunction("getBoneCurveByName", _SE(js_cocos2dx_3d_Animation3D_getBoneCurveByName));
    cls->defineFunction("getDuration", _SE(js_cocos2dx_3d_Animation3D_getDuration));
    cls->defineFinalizedFunction(_SE(js_cocos2d_Animation3D_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Animation3D>(cls);

    __jsb_cocos2d_Animation3D_proto = cls->getProto();
    __jsb_cocos2d_Animation3D_class = cls;

    return true;
}

se::Object* __jsb_cocos2d_Animate3D_proto = nullptr;
se::Class* __jsb_cocos2d_Animate3D_class = nullptr;

static bool js_cocos2dx_3d_Animate3D_setKeyFrameUserInfo(se::State& s)
{
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animate3D_setKeyFrameUserInfo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        cocos2d::ValueMap arg1;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        ok &= seval_to_ccvaluemap(args[1], &arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_setKeyFrameUserInfo : Error processing arguments");
        cobj->setKeyFrameUserInfo(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_setKeyFrameUserInfo)

static bool js_cocos2dx_3d_Animate3D_getSpeed(se::State& s)
{
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animate3D_getSpeed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSpeed();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_getSpeed : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_getSpeed)

static bool js_cocos2dx_3d_Animate3D_setQuality(se::State& s)
{
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animate3D_setQuality : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Animate3DQuality arg0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_setQuality : Error processing arguments");
        cobj->setQuality(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_setQuality)

static bool js_cocos2dx_3d_Animate3D_setWeight(se::State& s)
{
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animate3D_setWeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_setWeight : Error processing arguments");
        cobj->setWeight(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_setWeight)

static bool js_cocos2dx_3d_Animate3D_removeFromMap(se::State& s)
{
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animate3D_removeFromMap : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->removeFromMap();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_removeFromMap)

static bool js_cocos2dx_3d_Animate3D_initWithFrames(se::State& s)
{
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animate3D_initWithFrames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        cocos2d::Animation3D* arg0 = nullptr;
        int arg1 = 0;
        int arg2 = 0;
        float arg3 = 0;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        ok &= seval_to_int32(args[2], (int32_t *)&arg2);
        ok &= seval_to_float(args[3], &arg3);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_initWithFrames : Error processing arguments");
        bool result = cobj->initWithFrames(arg0, arg1, arg2, arg3);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_initWithFrames : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_initWithFrames)

static bool js_cocos2dx_3d_Animate3D_getOriginInterval(se::State& s)
{
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animate3D_getOriginInterval : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getOriginInterval();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_getOriginInterval : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_getOriginInterval)

static bool js_cocos2dx_3d_Animate3D_setSpeed(se::State& s)
{
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animate3D_setSpeed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_setSpeed : Error processing arguments");
        cobj->setSpeed(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_setSpeed)

static bool js_cocos2dx_3d_Animate3D_init(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_3d_Animate3D_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 3) {
            cocos2d::Animation3D* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(args[2], &arg2);
            if (!ok) { ok = true; break; }
            bool result = cobj->init(arg0, arg1, arg2);
            ok &= boolean_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_init : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            cocos2d::Animation3D* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            bool result = cobj->init(arg0);
            ok &= boolean_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_init : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_init)

static bool js_cocos2dx_3d_Animate3D_setOriginInterval(se::State& s)
{
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animate3D_setOriginInterval : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_setOriginInterval : Error processing arguments");
        cobj->setOriginInterval(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_setOriginInterval)

static bool js_cocos2dx_3d_Animate3D_getWeight(se::State& s)
{
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animate3D_getWeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getWeight();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_getWeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_getWeight)

static bool js_cocos2dx_3d_Animate3D_getQuality(se::State& s)
{
    cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Animate3D_getQuality : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getQuality();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_getQuality : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_getQuality)

static bool js_cocos2dx_3d_Animate3D_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 3) {
            cocos2d::Animation3D* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Animate3D* result = cocos2d::Animate3D::create(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<cocos2d::Animate3D>((cocos2d::Animate3D*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 1) {
            cocos2d::Animation3D* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Animate3D* result = cocos2d::Animate3D::create(arg0);
            ok &= native_ptr_to_seval<cocos2d::Animate3D>((cocos2d::Animate3D*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_create)

static bool js_cocos2dx_3d_Animate3D_getTransitionTime(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cocos2d::Animate3D::getTransitionTime();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_getTransitionTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_getTransitionTime)

static bool js_cocos2dx_3d_Animate3D_createWithFrames(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        cocos2d::Animation3D* arg0 = nullptr;
        int arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        ok &= seval_to_int32(args[2], (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_createWithFrames : Error processing arguments");
        auto result = cocos2d::Animate3D::createWithFrames(arg0, arg1, arg2);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_Animate3D_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    if (argc == 4) {
        cocos2d::Animation3D* arg0 = nullptr;
        int arg1 = 0;
        int arg2 = 0;
        float arg3 = 0;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        ok &= seval_to_int32(args[2], (int32_t *)&arg2);
        ok &= seval_to_float(args[3], &arg3);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_createWithFrames : Error processing arguments");
        auto result = cocos2d::Animate3D::createWithFrames(arg0, arg1, arg2, arg3);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_Animate3D_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_createWithFrames)

static bool js_cocos2dx_3d_Animate3D_setTransitionTime(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Animate3D_setTransitionTime : Error processing arguments");
        cocos2d::Animate3D::setTransitionTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Animate3D_setTransitionTime)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Animate3D_finalize)

static bool js_cocos2dx_3d_Animate3D_constructor(se::State& s)
{
    cocos2d::Animate3D* cobj = new (std::nothrow) cocos2d::Animate3D();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_Animate3D_constructor, __jsb_cocos2d_Animate3D_class, js_cocos2d_Animate3D_finalize)



extern se::Object* __jsb_cocos2d_ActionInterval_proto;

bool js_cocos2d_Animate3D_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::Animate3D)", s.nativeThisObject());
        cocos2d::Animate3D* cobj = (cocos2d::Animate3D*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Animate3D_finalize)

bool js_register_cocos2dx_3d_Animate3D(se::Object* obj)
{
    auto cls = se::Class::create("Animate3D", obj, __jsb_cocos2d_ActionInterval_proto, _SE(js_cocos2dx_3d_Animate3D_constructor));

    cls->defineFunction("setKeyFrameUserInfo", _SE(js_cocos2dx_3d_Animate3D_setKeyFrameUserInfo));
    cls->defineFunction("getSpeed", _SE(js_cocos2dx_3d_Animate3D_getSpeed));
    cls->defineFunction("setQuality", _SE(js_cocos2dx_3d_Animate3D_setQuality));
    cls->defineFunction("setWeight", _SE(js_cocos2dx_3d_Animate3D_setWeight));
    cls->defineFunction("removeFromMap", _SE(js_cocos2dx_3d_Animate3D_removeFromMap));
    cls->defineFunction("initWithFrames", _SE(js_cocos2dx_3d_Animate3D_initWithFrames));
    cls->defineFunction("getOriginInterval", _SE(js_cocos2dx_3d_Animate3D_getOriginInterval));
    cls->defineFunction("setSpeed", _SE(js_cocos2dx_3d_Animate3D_setSpeed));
    cls->defineFunction("init", _SE(js_cocos2dx_3d_Animate3D_init));
    cls->defineFunction("setOriginInterval", _SE(js_cocos2dx_3d_Animate3D_setOriginInterval));
    cls->defineFunction("getWeight", _SE(js_cocos2dx_3d_Animate3D_getWeight));
    cls->defineFunction("getQuality", _SE(js_cocos2dx_3d_Animate3D_getQuality));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_3d_Animate3D_create));
    cls->defineStaticFunction("getTransitionTime", _SE(js_cocos2dx_3d_Animate3D_getTransitionTime));
    cls->defineStaticFunction("createWithFrames", _SE(js_cocos2dx_3d_Animate3D_createWithFrames));
    cls->defineStaticFunction("setTransitionTime", _SE(js_cocos2dx_3d_Animate3D_setTransitionTime));
    cls->defineFinalizedFunction(_SE(js_cocos2d_Animate3D_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Animate3D>(cls);

    __jsb_cocos2d_Animate3D_proto = cls->getProto();
    __jsb_cocos2d_Animate3D_class = cls;

    return true;
}

se::Object* __jsb_cocos2d_TextureCube_proto = nullptr;
se::Class* __jsb_cocos2d_TextureCube_class = nullptr;

static bool js_cocos2dx_3d_TextureCube_reloadTexture(se::State& s)
{
    cocos2d::TextureCube* cobj = (cocos2d::TextureCube*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_TextureCube_reloadTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->reloadTexture();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_TextureCube_reloadTexture : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_TextureCube_reloadTexture)

static bool js_cocos2dx_3d_TextureCube_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 6) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        std::string arg5;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        ok &= seval_to_std_string(args[4], &arg4);
        ok &= seval_to_std_string(args[5], &arg5);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_TextureCube_create : Error processing arguments");
        auto result = cocos2d::TextureCube::create(arg0, arg1, arg2, arg3, arg4, arg5);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_TextureCube_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 6);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_TextureCube_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_TextureCube_finalize)

static bool js_cocos2dx_3d_TextureCube_constructor(se::State& s)
{
    cocos2d::TextureCube* cobj = new (std::nothrow) cocos2d::TextureCube();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_TextureCube_constructor, __jsb_cocos2d_TextureCube_class, js_cocos2d_TextureCube_finalize)



extern se::Object* __jsb_cocos2d_Texture2D_proto;

bool js_cocos2d_TextureCube_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::TextureCube)", s.nativeThisObject());
        cocos2d::TextureCube* cobj = (cocos2d::TextureCube*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_TextureCube_finalize)

bool js_register_cocos2dx_3d_TextureCube(se::Object* obj)
{
    auto cls = se::Class::create("TextureCube", obj, __jsb_cocos2d_Texture2D_proto, _SE(js_cocos2dx_3d_TextureCube_constructor));

    cls->defineFunction("reloadTexture", _SE(js_cocos2dx_3d_TextureCube_reloadTexture));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_3d_TextureCube_create));
    cls->defineFinalizedFunction(_SE(js_cocos2d_TextureCube_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::TextureCube>(cls);

    __jsb_cocos2d_TextureCube_proto = cls->getProto();
    __jsb_cocos2d_TextureCube_class = cls;

    return true;
}

se::Object* __jsb_cocos2d_AttachNode_proto = nullptr;
se::Class* __jsb_cocos2d_AttachNode_class = nullptr;

static bool js_cocos2dx_3d_AttachNode_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Bone3D* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_AttachNode_create : Error processing arguments");
        auto result = cocos2d::AttachNode::create(arg0);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_AttachNode_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_AttachNode_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_AttachNode_finalize)

static bool js_cocos2dx_3d_AttachNode_constructor(se::State& s)
{
    cocos2d::AttachNode* cobj = new (std::nothrow) cocos2d::AttachNode();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_AttachNode_constructor, __jsb_cocos2d_AttachNode_class, js_cocos2d_AttachNode_finalize)



extern se::Object* __jsb_cocos2d_Node_proto;

bool js_cocos2d_AttachNode_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::AttachNode)", s.nativeThisObject());
        cocos2d::AttachNode* cobj = (cocos2d::AttachNode*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_AttachNode_finalize)

bool js_register_cocos2dx_3d_AttachNode(se::Object* obj)
{
    auto cls = se::Class::create("AttachNode", obj, __jsb_cocos2d_Node_proto, _SE(js_cocos2dx_3d_AttachNode_constructor));

    cls->defineStaticFunction("create", _SE(js_cocos2dx_3d_AttachNode_create));
    cls->defineFinalizedFunction(_SE(js_cocos2d_AttachNode_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::AttachNode>(cls);

    __jsb_cocos2d_AttachNode_proto = cls->getProto();
    __jsb_cocos2d_AttachNode_class = cls;

    return true;
}

se::Object* __jsb_cocos2d_BillBoard_proto = nullptr;
se::Class* __jsb_cocos2d_BillBoard_class = nullptr;

static bool js_cocos2dx_3d_BillBoard_getMode(se::State& s)
{
    cocos2d::BillBoard* cobj = (cocos2d::BillBoard*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_BillBoard_getMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getMode();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_BillBoard_getMode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_BillBoard_getMode)

static bool js_cocos2dx_3d_BillBoard_setMode(se::State& s)
{
    cocos2d::BillBoard* cobj = (cocos2d::BillBoard*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_BillBoard_setMode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::BillBoard::Mode arg0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_BillBoard_setMode : Error processing arguments");
        cobj->setMode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_BillBoard_setMode)

static bool js_cocos2dx_3d_BillBoard_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::BillBoard* result = cocos2d::BillBoard::create(arg0);
            ok &= native_ptr_to_seval<cocos2d::BillBoard>((cocos2d::BillBoard*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_BillBoard_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::BillBoard::Mode arg1;
            ok &= seval_to_int32(args[1], (int32_t *)&arg1);
            if (!ok) { ok = true; break; }
            cocos2d::BillBoard* result = cocos2d::BillBoard::create(arg0, arg1);
            ok &= native_ptr_to_seval<cocos2d::BillBoard>((cocos2d::BillBoard*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_BillBoard_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            cocos2d::BillBoard* result = cocos2d::BillBoard::create();
            ok &= native_ptr_to_seval<cocos2d::BillBoard>((cocos2d::BillBoard*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_BillBoard_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 1) {
            cocos2d::BillBoard::Mode arg0;
            ok &= seval_to_int32(args[0], (int32_t *)&arg0);
            if (!ok) { ok = true; break; }
            cocos2d::BillBoard* result = cocos2d::BillBoard::create(arg0);
            ok &= native_ptr_to_seval<cocos2d::BillBoard>((cocos2d::BillBoard*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_BillBoard_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Rect arg1;
            ok &= seval_to_Rect(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::BillBoard* result = cocos2d::BillBoard::create(arg0, arg1);
            ok &= native_ptr_to_seval<cocos2d::BillBoard>((cocos2d::BillBoard*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_BillBoard_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Rect arg1;
            ok &= seval_to_Rect(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::BillBoard::Mode arg2;
            ok &= seval_to_int32(args[2], (int32_t *)&arg2);
            if (!ok) { ok = true; break; }
            cocos2d::BillBoard* result = cocos2d::BillBoard::create(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<cocos2d::BillBoard>((cocos2d::BillBoard*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_BillBoard_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_BillBoard_create)

static bool js_cocos2dx_3d_BillBoard_createWithTexture(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Texture2D* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_BillBoard_createWithTexture : Error processing arguments");
        auto result = cocos2d::BillBoard::createWithTexture(arg0);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_BillBoard_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    if (argc == 2) {
        cocos2d::Texture2D* arg0 = nullptr;
        cocos2d::BillBoard::Mode arg1;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_BillBoard_createWithTexture : Error processing arguments");
        auto result = cocos2d::BillBoard::createWithTexture(arg0, arg1);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_BillBoard_class, false);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_BillBoard_createWithTexture)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_BillBoard_finalize)

static bool js_cocos2dx_3d_BillBoard_constructor(se::State& s)
{
    cocos2d::BillBoard* cobj = new (std::nothrow) cocos2d::BillBoard();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_BillBoard_constructor, __jsb_cocos2d_BillBoard_class, js_cocos2d_BillBoard_finalize)



extern se::Object* __jsb_cocos2d_Sprite_proto;

bool js_cocos2d_BillBoard_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::BillBoard)", s.nativeThisObject());
        cocos2d::BillBoard* cobj = (cocos2d::BillBoard*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_BillBoard_finalize)

bool js_register_cocos2dx_3d_BillBoard(se::Object* obj)
{
    auto cls = se::Class::create("BillBoard", obj, __jsb_cocos2d_Sprite_proto, _SE(js_cocos2dx_3d_BillBoard_constructor));

    cls->defineFunction("getMode", _SE(js_cocos2dx_3d_BillBoard_getMode));
    cls->defineFunction("setMode", _SE(js_cocos2dx_3d_BillBoard_setMode));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_3d_BillBoard_create));
    cls->defineStaticFunction("createWithTexture", _SE(js_cocos2dx_3d_BillBoard_createWithTexture));
    cls->defineFinalizedFunction(_SE(js_cocos2d_BillBoard_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::BillBoard>(cls);

    __jsb_cocos2d_BillBoard_proto = cls->getProto();
    __jsb_cocos2d_BillBoard_class = cls;

    return true;
}

se::Object* __jsb_cocos2d_Mesh_proto = nullptr;
se::Class* __jsb_cocos2d_Mesh_class = nullptr;

static bool js_cocos2dx_3d_Mesh_getSkin(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::MeshSkin* result = cobj->getSkin();
        ok &= native_ptr_to_seval<cocos2d::MeshSkin>((cocos2d::MeshSkin*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getSkin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getSkin)

static bool js_cocos2dx_3d_Mesh_getMaterial(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getMaterial : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Material* result = cobj->getMaterial();
        ok &= native_ptr_to_seval<cocos2d::Material>((cocos2d::Material*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getMaterial : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getMaterial)

static bool js_cocos2dx_3d_Mesh_getVertexSizeInBytes(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getVertexSizeInBytes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getVertexSizeInBytes();
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getVertexSizeInBytes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getVertexSizeInBytes)

static bool js_cocos2dx_3d_Mesh_setMaterial(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_setMaterial : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Material* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_setMaterial : Error processing arguments");
        cobj->setMaterial(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_setMaterial)

static bool js_cocos2dx_3d_Mesh_getName(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cobj->getName();
        ok &= std_string_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getName)

static bool js_cocos2dx_3d_Mesh_getIndexFormat(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getIndexFormat : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getIndexFormat();
        ok &= uint32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getIndexFormat : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getIndexFormat)

static bool js_cocos2dx_3d_Mesh_getGLProgramState(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getGLProgramState : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::GLProgramState* result = cobj->getGLProgramState();
        ok &= native_ptr_to_seval<cocos2d::GLProgramState>((cocos2d::GLProgramState*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getGLProgramState : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getGLProgramState)

static bool js_cocos2dx_3d_Mesh_getVertexBuffer(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getVertexBuffer : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getVertexBuffer();
        ok &= uint32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getVertexBuffer : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getVertexBuffer)

static bool js_cocos2dx_3d_Mesh_calculateAABB(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_calculateAABB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->calculateAABB();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_calculateAABB)

static bool js_cocos2dx_3d_Mesh_hasVertexAttrib(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_hasVertexAttrib : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_hasVertexAttrib : Error processing arguments");
        bool result = cobj->hasVertexAttrib(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_hasVertexAttrib : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_hasVertexAttrib)

static bool js_cocos2dx_3d_Mesh_getBlendFunc(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::BlendFunc& result = cobj->getBlendFunc();
        ok &= blendfunc_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getBlendFunc : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getBlendFunc)

static bool js_cocos2dx_3d_Mesh_getMeshIndexData(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getMeshIndexData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::MeshIndexData* result = cobj->getMeshIndexData();
        ok &= native_ptr_to_seval<cocos2d::MeshIndexData>((cocos2d::MeshIndexData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getMeshIndexData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getMeshIndexData)

static bool js_cocos2dx_3d_Mesh_setName(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_setName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_setName : Error processing arguments");
        cobj->setName(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_setName)

static bool js_cocos2dx_3d_Mesh_getIndexCount(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getIndexCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        ssize_t result = cobj->getIndexCount();
        ok &= ssize_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getIndexCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getIndexCount)

static bool js_cocos2dx_3d_Mesh_setMeshIndexData(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_setMeshIndexData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::MeshIndexData* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_setMeshIndexData : Error processing arguments");
        cobj->setMeshIndexData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_setMeshIndexData)

static bool js_cocos2dx_3d_Mesh_getMeshVertexAttribCount(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getMeshVertexAttribCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        ssize_t result = cobj->getMeshVertexAttribCount();
        ok &= ssize_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getMeshVertexAttribCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getMeshVertexAttribCount)

static bool js_cocos2dx_3d_Mesh_setBlendFunc(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_setBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::BlendFunc arg0;
        ok &= seval_to_blendfunc(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_setBlendFunc : Error processing arguments");
        cobj->setBlendFunc(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_setBlendFunc)

static bool js_cocos2dx_3d_Mesh_setForce2DQueue(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_setForce2DQueue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_setForce2DQueue : Error processing arguments");
        cobj->setForce2DQueue(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_setForce2DQueue)

static bool js_cocos2dx_3d_Mesh_getPrimitiveType(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getPrimitiveType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getPrimitiveType();
        ok &= uint32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getPrimitiveType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getPrimitiveType)

static bool js_cocos2dx_3d_Mesh_setSkin(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_setSkin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::MeshSkin* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_setSkin : Error processing arguments");
        cobj->setSkin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_setSkin)

static bool js_cocos2dx_3d_Mesh_isVisible(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_isVisible : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isVisible();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_isVisible : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_isVisible)

static bool js_cocos2dx_3d_Mesh_getIndexBuffer(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_getIndexBuffer : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getIndexBuffer();
        ok &= uint32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_getIndexBuffer : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_getIndexBuffer)

static bool js_cocos2dx_3d_Mesh_setGLProgramState(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_setGLProgramState : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::GLProgramState* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_setGLProgramState : Error processing arguments");
        cobj->setGLProgramState(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_setGLProgramState)

static bool js_cocos2dx_3d_Mesh_setVisible(se::State& s)
{
    cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Mesh_setVisible : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Mesh_setVisible : Error processing arguments");
        cobj->setVisible(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Mesh_setVisible)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Mesh_finalize)

static bool js_cocos2dx_3d_Mesh_constructor(se::State& s)
{
    cocos2d::Mesh* cobj = new (std::nothrow) cocos2d::Mesh();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_Mesh_constructor, __jsb_cocos2d_Mesh_class, js_cocos2d_Mesh_finalize)




bool js_cocos2d_Mesh_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::Mesh)", s.nativeThisObject());
        cocos2d::Mesh* cobj = (cocos2d::Mesh*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Mesh_finalize)

bool js_register_cocos2dx_3d_Mesh(se::Object* obj)
{
    auto cls = se::Class::create("Mesh", obj, nullptr, _SE(js_cocos2dx_3d_Mesh_constructor));

    cls->defineFunction("getSkin", _SE(js_cocos2dx_3d_Mesh_getSkin));
    cls->defineFunction("getMaterial", _SE(js_cocos2dx_3d_Mesh_getMaterial));
    cls->defineFunction("getVertexSizeInBytes", _SE(js_cocos2dx_3d_Mesh_getVertexSizeInBytes));
    cls->defineFunction("setMaterial", _SE(js_cocos2dx_3d_Mesh_setMaterial));
    cls->defineFunction("getName", _SE(js_cocos2dx_3d_Mesh_getName));
    cls->defineFunction("getIndexFormat", _SE(js_cocos2dx_3d_Mesh_getIndexFormat));
    cls->defineFunction("getGLProgramState", _SE(js_cocos2dx_3d_Mesh_getGLProgramState));
    cls->defineFunction("getVertexBuffer", _SE(js_cocos2dx_3d_Mesh_getVertexBuffer));
    cls->defineFunction("calculateAABB", _SE(js_cocos2dx_3d_Mesh_calculateAABB));
    cls->defineFunction("hasVertexAttrib", _SE(js_cocos2dx_3d_Mesh_hasVertexAttrib));
    cls->defineFunction("getBlendFunc", _SE(js_cocos2dx_3d_Mesh_getBlendFunc));
    cls->defineFunction("getMeshIndexData", _SE(js_cocos2dx_3d_Mesh_getMeshIndexData));
    cls->defineFunction("setName", _SE(js_cocos2dx_3d_Mesh_setName));
    cls->defineFunction("getIndexCount", _SE(js_cocos2dx_3d_Mesh_getIndexCount));
    cls->defineFunction("setMeshIndexData", _SE(js_cocos2dx_3d_Mesh_setMeshIndexData));
    cls->defineFunction("getMeshVertexAttribCount", _SE(js_cocos2dx_3d_Mesh_getMeshVertexAttribCount));
    cls->defineFunction("setBlendFunc", _SE(js_cocos2dx_3d_Mesh_setBlendFunc));
    cls->defineFunction("setForce2DQueue", _SE(js_cocos2dx_3d_Mesh_setForce2DQueue));
    cls->defineFunction("getPrimitiveType", _SE(js_cocos2dx_3d_Mesh_getPrimitiveType));
    cls->defineFunction("setSkin", _SE(js_cocos2dx_3d_Mesh_setSkin));
    cls->defineFunction("isVisible", _SE(js_cocos2dx_3d_Mesh_isVisible));
    cls->defineFunction("getIndexBuffer", _SE(js_cocos2dx_3d_Mesh_getIndexBuffer));
    cls->defineFunction("setGLProgramState", _SE(js_cocos2dx_3d_Mesh_setGLProgramState));
    cls->defineFunction("setVisible", _SE(js_cocos2dx_3d_Mesh_setVisible));
    cls->defineFinalizedFunction(_SE(js_cocos2d_Mesh_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Mesh>(cls);

    __jsb_cocos2d_Mesh_proto = cls->getProto();
    __jsb_cocos2d_Mesh_class = cls;

    return true;
}

se::Object* __jsb_cocos2d_Skeleton3D_proto = nullptr;
se::Class* __jsb_cocos2d_Skeleton3D_class = nullptr;

static bool js_cocos2dx_3d_Skeleton3D_removeAllBones(se::State& s)
{
    cocos2d::Skeleton3D* cobj = (cocos2d::Skeleton3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skeleton3D_removeAllBones : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->removeAllBones();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skeleton3D_removeAllBones)

static bool js_cocos2dx_3d_Skeleton3D_addBone(se::State& s)
{
    cocos2d::Skeleton3D* cobj = (cocos2d::Skeleton3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skeleton3D_addBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Bone3D* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skeleton3D_addBone : Error processing arguments");
        cobj->addBone(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skeleton3D_addBone)

static bool js_cocos2dx_3d_Skeleton3D_getBoneByName(se::State& s)
{
    cocos2d::Skeleton3D* cobj = (cocos2d::Skeleton3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skeleton3D_getBoneByName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skeleton3D_getBoneByName : Error processing arguments");
        cocos2d::Bone3D* result = cobj->getBoneByName(arg0);
        ok &= native_ptr_to_seval<cocos2d::Bone3D>((cocos2d::Bone3D*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skeleton3D_getBoneByName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skeleton3D_getBoneByName)

static bool js_cocos2dx_3d_Skeleton3D_getRootBone(se::State& s)
{
    cocos2d::Skeleton3D* cobj = (cocos2d::Skeleton3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skeleton3D_getRootBone : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skeleton3D_getRootBone : Error processing arguments");
        cocos2d::Bone3D* result = cobj->getRootBone(arg0);
        ok &= native_ptr_to_seval<cocos2d::Bone3D>((cocos2d::Bone3D*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skeleton3D_getRootBone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skeleton3D_getRootBone)

static bool js_cocos2dx_3d_Skeleton3D_updateBoneMatrix(se::State& s)
{
    cocos2d::Skeleton3D* cobj = (cocos2d::Skeleton3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skeleton3D_updateBoneMatrix : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateBoneMatrix();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skeleton3D_updateBoneMatrix)

static bool js_cocos2dx_3d_Skeleton3D_getBoneByIndex(se::State& s)
{
    cocos2d::Skeleton3D* cobj = (cocos2d::Skeleton3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skeleton3D_getBoneByIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skeleton3D_getBoneByIndex : Error processing arguments");
        cocos2d::Bone3D* result = cobj->getBoneByIndex(arg0);
        ok &= native_ptr_to_seval<cocos2d::Bone3D>((cocos2d::Bone3D*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skeleton3D_getBoneByIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skeleton3D_getBoneByIndex)

static bool js_cocos2dx_3d_Skeleton3D_getRootCount(se::State& s)
{
    cocos2d::Skeleton3D* cobj = (cocos2d::Skeleton3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skeleton3D_getRootCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        ssize_t result = cobj->getRootCount();
        ok &= ssize_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skeleton3D_getRootCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skeleton3D_getRootCount)

static bool js_cocos2dx_3d_Skeleton3D_getBoneIndex(se::State& s)
{
    cocos2d::Skeleton3D* cobj = (cocos2d::Skeleton3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skeleton3D_getBoneIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Bone3D* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skeleton3D_getBoneIndex : Error processing arguments");
        int result = cobj->getBoneIndex(arg0);
        ok &= int32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skeleton3D_getBoneIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skeleton3D_getBoneIndex)

static bool js_cocos2dx_3d_Skeleton3D_getBoneCount(se::State& s)
{
    cocos2d::Skeleton3D* cobj = (cocos2d::Skeleton3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skeleton3D_getBoneCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        ssize_t result = cobj->getBoneCount();
        ok &= ssize_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skeleton3D_getBoneCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skeleton3D_getBoneCount)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Skeleton3D_finalize)

static bool js_cocos2dx_3d_Skeleton3D_constructor(se::State& s)
{
    cocos2d::Skeleton3D* cobj = new (std::nothrow) cocos2d::Skeleton3D();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_Skeleton3D_constructor, __jsb_cocos2d_Skeleton3D_class, js_cocos2d_Skeleton3D_finalize)




bool js_cocos2d_Skeleton3D_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::Skeleton3D)", s.nativeThisObject());
        cocos2d::Skeleton3D* cobj = (cocos2d::Skeleton3D*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Skeleton3D_finalize)

bool js_register_cocos2dx_3d_Skeleton3D(se::Object* obj)
{
    auto cls = se::Class::create("Skeleton3D", obj, nullptr, _SE(js_cocos2dx_3d_Skeleton3D_constructor));

    cls->defineFunction("removeAllBones", _SE(js_cocos2dx_3d_Skeleton3D_removeAllBones));
    cls->defineFunction("addBone", _SE(js_cocos2dx_3d_Skeleton3D_addBone));
    cls->defineFunction("getBoneByName", _SE(js_cocos2dx_3d_Skeleton3D_getBoneByName));
    cls->defineFunction("getRootBone", _SE(js_cocos2dx_3d_Skeleton3D_getRootBone));
    cls->defineFunction("updateBoneMatrix", _SE(js_cocos2dx_3d_Skeleton3D_updateBoneMatrix));
    cls->defineFunction("getBoneByIndex", _SE(js_cocos2dx_3d_Skeleton3D_getBoneByIndex));
    cls->defineFunction("getRootCount", _SE(js_cocos2dx_3d_Skeleton3D_getRootCount));
    cls->defineFunction("getBoneIndex", _SE(js_cocos2dx_3d_Skeleton3D_getBoneIndex));
    cls->defineFunction("getBoneCount", _SE(js_cocos2dx_3d_Skeleton3D_getBoneCount));
    cls->defineFinalizedFunction(_SE(js_cocos2d_Skeleton3D_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Skeleton3D>(cls);

    __jsb_cocos2d_Skeleton3D_proto = cls->getProto();
    __jsb_cocos2d_Skeleton3D_class = cls;

    return true;
}

se::Object* __jsb_cocos2d_Skybox_proto = nullptr;
se::Class* __jsb_cocos2d_Skybox_class = nullptr;

static bool js_cocos2dx_3d_Skybox_reload(se::State& s)
{
    cocos2d::Skybox* cobj = (cocos2d::Skybox*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skybox_reload : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->reload();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skybox_reload)

static bool js_cocos2dx_3d_Skybox_init(se::State& s)
{
    cocos2d::Skybox* cobj = (cocos2d::Skybox*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skybox_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 6) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        std::string arg5;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        ok &= seval_to_std_string(args[4], &arg4);
        ok &= seval_to_std_string(args[5], &arg5);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skybox_init : Error processing arguments");
        bool result = cobj->init(arg0, arg1, arg2, arg3, arg4, arg5);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skybox_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 6);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skybox_init)

static bool js_cocos2dx_3d_Skybox_setTexture(se::State& s)
{
    cocos2d::Skybox* cobj = (cocos2d::Skybox*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Skybox_setTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::TextureCube* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skybox_setTexture : Error processing arguments");
        cobj->setTexture(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skybox_setTexture)

static bool js_cocos2dx_3d_Skybox_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 6) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(args[1], &arg1);
            if (!ok) { ok = true; break; }
            std::string arg2;
            ok &= seval_to_std_string(args[2], &arg2);
            if (!ok) { ok = true; break; }
            std::string arg3;
            ok &= seval_to_std_string(args[3], &arg3);
            if (!ok) { ok = true; break; }
            std::string arg4;
            ok &= seval_to_std_string(args[4], &arg4);
            if (!ok) { ok = true; break; }
            std::string arg5;
            ok &= seval_to_std_string(args[5], &arg5);
            if (!ok) { ok = true; break; }
            cocos2d::Skybox* result = cocos2d::Skybox::create(arg0, arg1, arg2, arg3, arg4, arg5);
            ok &= native_ptr_to_seval<cocos2d::Skybox>((cocos2d::Skybox*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skybox_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            cocos2d::Skybox* result = cocos2d::Skybox::create();
            ok &= native_ptr_to_seval<cocos2d::Skybox>((cocos2d::Skybox*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Skybox_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Skybox_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Skybox_finalize)

static bool js_cocos2dx_3d_Skybox_constructor(se::State& s)
{
    cocos2d::Skybox* cobj = new (std::nothrow) cocos2d::Skybox();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_Skybox_constructor, __jsb_cocos2d_Skybox_class, js_cocos2d_Skybox_finalize)



extern se::Object* __jsb_cocos2d_Node_proto;

bool js_cocos2d_Skybox_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::Skybox)", s.nativeThisObject());
        cocos2d::Skybox* cobj = (cocos2d::Skybox*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Skybox_finalize)

bool js_register_cocos2dx_3d_Skybox(se::Object* obj)
{
    auto cls = se::Class::create("Skybox", obj, __jsb_cocos2d_Node_proto, _SE(js_cocos2dx_3d_Skybox_constructor));

    cls->defineFunction("reload", _SE(js_cocos2dx_3d_Skybox_reload));
    cls->defineFunction("init", _SE(js_cocos2dx_3d_Skybox_init));
    cls->defineFunction("setTexture", _SE(js_cocos2dx_3d_Skybox_setTexture));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_3d_Skybox_create));
    cls->defineFinalizedFunction(_SE(js_cocos2d_Skybox_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Skybox>(cls);

    __jsb_cocos2d_Skybox_proto = cls->getProto();
    __jsb_cocos2d_Skybox_class = cls;

    return true;
}

se::Object* __jsb_cocos2d_Sprite3D_proto = nullptr;
se::Class* __jsb_cocos2d_Sprite3D_class = nullptr;

static bool js_cocos2dx_3d_Sprite3D_setCullFaceEnabled(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_setCullFaceEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_setCullFaceEnabled : Error processing arguments");
        cobj->setCullFaceEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_setCullFaceEnabled)

static bool js_cocos2dx_3d_Sprite3D_setTexture(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_3d_Sprite3D_setTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            cocos2d::Texture2D* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->setTexture(arg0);
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->setTexture(arg0);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_setTexture)

static bool js_cocos2dx_3d_Sprite3D_getLightMask(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_getLightMask : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getLightMask();
        ok &= uint32_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getLightMask : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_getLightMask)

static bool js_cocos2dx_3d_Sprite3D_createAttachSprite3DNode(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_createAttachSprite3DNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::NodeData* arg0 = nullptr;
        cocos2d::MaterialDatas arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR NodeData*
        ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR MaterialDatas
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_createAttachSprite3DNode : Error processing arguments");
        cobj->createAttachSprite3DNode(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_createAttachSprite3DNode)

static bool js_cocos2dx_3d_Sprite3D_loadFromFile(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_loadFromFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        std::string arg0;
        cocos2d::NodeDatas* arg1 = nullptr;
        cocos2d::MeshDatas* arg2 = nullptr;
        cocos2d::MaterialDatas* arg3 = nullptr;
        ok &= seval_to_std_string(args[0], &arg0);
        #pragma warning NO CONVERSION TO NATIVE FOR NodeDatas*
        ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR MeshDatas*
        ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR MaterialDatas*
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_loadFromFile : Error processing arguments");
        bool result = cobj->loadFromFile(arg0, arg1, arg2, arg3);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_loadFromFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_loadFromFile)

static bool js_cocos2dx_3d_Sprite3D_getMaterial(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_getMaterial : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getMaterial : Error processing arguments");
        cocos2d::Material* result = cobj->getMaterial(arg0);
        ok &= native_ptr_to_seval<cocos2d::Material>((cocos2d::Material*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getMaterial : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_getMaterial)

static bool js_cocos2dx_3d_Sprite3D_setCullFace(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_setCullFace : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_setCullFace : Error processing arguments");
        cobj->setCullFace(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_setCullFace)

static bool js_cocos2dx_3d_Sprite3D_getMeshes(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_getMeshes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::Vector<cocos2d::Mesh *>& result = cobj->getMeshes();
        ok &= Vector_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getMeshes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_getMeshes)

static bool js_cocos2dx_3d_Sprite3D_addMesh(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_addMesh : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Mesh* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_addMesh : Error processing arguments");
        cobj->addMesh(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_addMesh)

static bool js_cocos2dx_3d_Sprite3D_removeAllAttachNode(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_removeAllAttachNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->removeAllAttachNode();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_removeAllAttachNode)

static bool js_cocos2dx_3d_Sprite3D_setMaterial(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_3d_Sprite3D_setMaterial : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            cocos2d::Material* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            int arg1 = 0;
            ok &= seval_to_int32(args[1], (int32_t *)&arg1);
            if (!ok) { ok = true; break; }
            cobj->setMaterial(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            cocos2d::Material* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->setMaterial(arg0);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_setMaterial)

static bool js_cocos2dx_3d_Sprite3D_getMesh(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_getMesh : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mesh* result = cobj->getMesh();
        ok &= native_ptr_to_seval<cocos2d::Mesh>((cocos2d::Mesh*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getMesh : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_getMesh)

static bool js_cocos2dx_3d_Sprite3D_createSprite3DNode(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_createSprite3DNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        cocos2d::NodeData* arg0 = nullptr;
        cocos2d::ModelData* arg1 = nullptr;
        cocos2d::MaterialDatas arg2;
        #pragma warning NO CONVERSION TO NATIVE FOR NodeData*
        ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR ModelData*
        ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR MaterialDatas
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_createSprite3DNode : Error processing arguments");
        cocos2d::Sprite3D* result = cobj->createSprite3DNode(arg0, arg1, arg2);
        ok &= native_ptr_to_seval<cocos2d::Sprite3D>((cocos2d::Sprite3D*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_createSprite3DNode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_createSprite3DNode)

static bool js_cocos2dx_3d_Sprite3D_getMeshCount(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_getMeshCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        ssize_t result = cobj->getMeshCount();
        ok &= ssize_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getMeshCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_getMeshCount)

static bool js_cocos2dx_3d_Sprite3D_onAABBDirty(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_onAABBDirty : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->onAABBDirty();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_onAABBDirty)

static bool js_cocos2dx_3d_Sprite3D_getMeshByIndex(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_getMeshByIndex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getMeshByIndex : Error processing arguments");
        cocos2d::Mesh* result = cobj->getMeshByIndex(arg0);
        ok &= native_ptr_to_seval<cocos2d::Mesh>((cocos2d::Mesh*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getMeshByIndex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_getMeshByIndex)

static bool js_cocos2dx_3d_Sprite3D_createNode(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_createNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        cocos2d::NodeData* arg0 = nullptr;
        cocos2d::Node* arg1 = nullptr;
        cocos2d::MaterialDatas arg2;
        bool arg3;
        #pragma warning NO CONVERSION TO NATIVE FOR NodeData*
        ok = false;
        ok &= seval_to_native_ptr(args[1], &arg1);
        #pragma warning NO CONVERSION TO NATIVE FOR MaterialDatas
        ok = false;
        ok &= seval_to_boolean(args[3], &arg3);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_createNode : Error processing arguments");
        cobj->createNode(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_createNode)

static bool js_cocos2dx_3d_Sprite3D_isForceDepthWrite(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_isForceDepthWrite : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isForceDepthWrite();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_isForceDepthWrite : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_isForceDepthWrite)

static bool js_cocos2dx_3d_Sprite3D_getBlendFunc(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_getBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::BlendFunc& result = cobj->getBlendFunc();
        ok &= blendfunc_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getBlendFunc : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_getBlendFunc)

static bool js_cocos2dx_3d_Sprite3D_getMeshIndexData(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_getMeshIndexData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getMeshIndexData : Error processing arguments");
        cocos2d::MeshIndexData* result = cobj->getMeshIndexData(arg0);
        ok &= native_ptr_to_seval<cocos2d::MeshIndexData>((cocos2d::MeshIndexData*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getMeshIndexData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_getMeshIndexData)

static bool js_cocos2dx_3d_Sprite3D_setLightMask(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_setLightMask : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_setLightMask : Error processing arguments");
        cobj->setLightMask(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_setLightMask)

static bool js_cocos2dx_3d_Sprite3D_afterAsyncLoad(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_afterAsyncLoad : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        void* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR void*
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_afterAsyncLoad : Error processing arguments");
        cobj->afterAsyncLoad(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_afterAsyncLoad)

static bool js_cocos2dx_3d_Sprite3D_loadFromCache(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_loadFromCache : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_loadFromCache : Error processing arguments");
        bool result = cobj->loadFromCache(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_loadFromCache : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_loadFromCache)

static bool js_cocos2dx_3d_Sprite3D_initFrom(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_initFrom : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        cocos2d::NodeDatas arg0;
        cocos2d::MeshDatas arg1;
        cocos2d::MaterialDatas arg2;
        #pragma warning NO CONVERSION TO NATIVE FOR NodeDatas
        ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR MeshDatas
        ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR MaterialDatas
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_initFrom : Error processing arguments");
        bool result = cobj->initFrom(arg0, arg1, arg2);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_initFrom : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_initFrom)

static bool js_cocos2dx_3d_Sprite3D_getAttachNode(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_getAttachNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getAttachNode : Error processing arguments");
        cocos2d::AttachNode* result = cobj->getAttachNode(arg0);
        ok &= native_ptr_to_seval<cocos2d::AttachNode>((cocos2d::AttachNode*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getAttachNode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_getAttachNode)

static bool js_cocos2dx_3d_Sprite3D_initWithFile(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_initWithFile : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_initWithFile : Error processing arguments");
        bool result = cobj->initWithFile(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_initWithFile : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_initWithFile)

static bool js_cocos2dx_3d_Sprite3D_setBlendFunc(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_setBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::BlendFunc arg0;
        ok &= seval_to_blendfunc(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_setBlendFunc : Error processing arguments");
        cobj->setBlendFunc(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_setBlendFunc)

static bool js_cocos2dx_3d_Sprite3D_setForce2DQueue(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_setForce2DQueue : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_setForce2DQueue : Error processing arguments");
        cobj->setForce2DQueue(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_setForce2DQueue)

static bool js_cocos2dx_3d_Sprite3D_genMaterial(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_genMaterial : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cobj->genMaterial();
        return true;
    }
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_genMaterial : Error processing arguments");
        cobj->genMaterial(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_genMaterial)

static bool js_cocos2dx_3d_Sprite3D_removeAttachNode(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_removeAttachNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_removeAttachNode : Error processing arguments");
        cobj->removeAttachNode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_removeAttachNode)

static bool js_cocos2dx_3d_Sprite3D_getSkeleton(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_getSkeleton : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Skeleton3D* result = cobj->getSkeleton();
        ok &= native_ptr_to_seval<cocos2d::Skeleton3D>((cocos2d::Skeleton3D*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getSkeleton : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_getSkeleton)

static bool js_cocos2dx_3d_Sprite3D_setForceDepthWrite(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_setForceDepthWrite : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_setForceDepthWrite : Error processing arguments");
        cobj->setForceDepthWrite(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_setForceDepthWrite)

static bool js_cocos2dx_3d_Sprite3D_getMeshByName(se::State& s)
{
    cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3D_getMeshByName : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getMeshByName : Error processing arguments");
        cocos2d::Mesh* result = cobj->getMeshByName(arg0);
        ok &= native_ptr_to_seval<cocos2d::Mesh>((cocos2d::Mesh*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_getMeshByName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_getMeshByName)

static bool js_cocos2dx_3d_Sprite3D_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Sprite3D* result = cocos2d::Sprite3D::create(arg0);
            ok &= native_ptr_to_seval<cocos2d::Sprite3D>((cocos2d::Sprite3D*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            cocos2d::Sprite3D* result = cocos2d::Sprite3D::create();
            ok &= native_ptr_to_seval<cocos2d::Sprite3D>((cocos2d::Sprite3D*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_create : Error processing arguments");
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
            cocos2d::Sprite3D* result = cocos2d::Sprite3D::create(arg0, arg1);
            ok &= native_ptr_to_seval<cocos2d::Sprite3D>((cocos2d::Sprite3D*)result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3D_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3D_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Sprite3D_finalize)

static bool js_cocos2dx_3d_Sprite3D_constructor(se::State& s)
{
    cocos2d::Sprite3D* cobj = new (std::nothrow) cocos2d::Sprite3D();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_Sprite3D_constructor, __jsb_cocos2d_Sprite3D_class, js_cocos2d_Sprite3D_finalize)

static bool js_cocos2dx_3d_Sprite3D_ctor(se::State& s)
{
    cocos2d::Sprite3D* cobj = new (std::nothrow) cocos2d::Sprite3D();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_SUB_CLS_CTOR(js_cocos2dx_3d_Sprite3D_ctor, __jsb_cocos2d_Sprite3D_class, js_cocos2d_Sprite3D_finalize)


    

extern se::Object* __jsb_cocos2d_Node_proto;

bool js_cocos2d_Sprite3D_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::Sprite3D)", s.nativeThisObject());
        cocos2d::Sprite3D* cobj = (cocos2d::Sprite3D*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Sprite3D_finalize)

bool js_register_cocos2dx_3d_Sprite3D(se::Object* obj)
{
    auto cls = se::Class::create("Sprite3D", obj, __jsb_cocos2d_Node_proto, _SE(js_cocos2dx_3d_Sprite3D_constructor));

    cls->defineFunction("setCullFaceEnabled", _SE(js_cocos2dx_3d_Sprite3D_setCullFaceEnabled));
    cls->defineFunction("setTexture", _SE(js_cocos2dx_3d_Sprite3D_setTexture));
    cls->defineFunction("getLightMask", _SE(js_cocos2dx_3d_Sprite3D_getLightMask));
    cls->defineFunction("createAttachSprite3DNode", _SE(js_cocos2dx_3d_Sprite3D_createAttachSprite3DNode));
    cls->defineFunction("loadFromFile", _SE(js_cocos2dx_3d_Sprite3D_loadFromFile));
    cls->defineFunction("getMaterial", _SE(js_cocos2dx_3d_Sprite3D_getMaterial));
    cls->defineFunction("setCullFace", _SE(js_cocos2dx_3d_Sprite3D_setCullFace));
    cls->defineFunction("getMeshes", _SE(js_cocos2dx_3d_Sprite3D_getMeshes));
    cls->defineFunction("addMesh", _SE(js_cocos2dx_3d_Sprite3D_addMesh));
    cls->defineFunction("removeAllAttachNode", _SE(js_cocos2dx_3d_Sprite3D_removeAllAttachNode));
    cls->defineFunction("setMaterial", _SE(js_cocos2dx_3d_Sprite3D_setMaterial));
    cls->defineFunction("getMesh", _SE(js_cocos2dx_3d_Sprite3D_getMesh));
    cls->defineFunction("createSprite3DNode", _SE(js_cocos2dx_3d_Sprite3D_createSprite3DNode));
    cls->defineFunction("getMeshCount", _SE(js_cocos2dx_3d_Sprite3D_getMeshCount));
    cls->defineFunction("onAABBDirty", _SE(js_cocos2dx_3d_Sprite3D_onAABBDirty));
    cls->defineFunction("getMeshByIndex", _SE(js_cocos2dx_3d_Sprite3D_getMeshByIndex));
    cls->defineFunction("createNode", _SE(js_cocos2dx_3d_Sprite3D_createNode));
    cls->defineFunction("isForceDepthWrite", _SE(js_cocos2dx_3d_Sprite3D_isForceDepthWrite));
    cls->defineFunction("getBlendFunc", _SE(js_cocos2dx_3d_Sprite3D_getBlendFunc));
    cls->defineFunction("getMeshIndexData", _SE(js_cocos2dx_3d_Sprite3D_getMeshIndexData));
    cls->defineFunction("setLightMask", _SE(js_cocos2dx_3d_Sprite3D_setLightMask));
    cls->defineFunction("afterAsyncLoad", _SE(js_cocos2dx_3d_Sprite3D_afterAsyncLoad));
    cls->defineFunction("loadFromCache", _SE(js_cocos2dx_3d_Sprite3D_loadFromCache));
    cls->defineFunction("initFrom", _SE(js_cocos2dx_3d_Sprite3D_initFrom));
    cls->defineFunction("getAttachNode", _SE(js_cocos2dx_3d_Sprite3D_getAttachNode));
    cls->defineFunction("initWithFile", _SE(js_cocos2dx_3d_Sprite3D_initWithFile));
    cls->defineFunction("setBlendFunc", _SE(js_cocos2dx_3d_Sprite3D_setBlendFunc));
    cls->defineFunction("setForce2DQueue", _SE(js_cocos2dx_3d_Sprite3D_setForce2DQueue));
    cls->defineFunction("genMaterial", _SE(js_cocos2dx_3d_Sprite3D_genMaterial));
    cls->defineFunction("removeAttachNode", _SE(js_cocos2dx_3d_Sprite3D_removeAttachNode));
    cls->defineFunction("getSkeleton", _SE(js_cocos2dx_3d_Sprite3D_getSkeleton));
    cls->defineFunction("setForceDepthWrite", _SE(js_cocos2dx_3d_Sprite3D_setForceDepthWrite));
    cls->defineFunction("getMeshByName", _SE(js_cocos2dx_3d_Sprite3D_getMeshByName));
    cls->defineFunction("ctor", _SE(js_cocos2dx_3d_Sprite3D_ctor));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_3d_Sprite3D_create));
    cls->defineFinalizedFunction(_SE(js_cocos2d_Sprite3D_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Sprite3D>(cls);

    __jsb_cocos2d_Sprite3D_proto = cls->getProto();
    __jsb_cocos2d_Sprite3D_class = cls;

    se::ScriptEngine::getInstance()->executeScriptBuffer("(function () { jsb.Sprite3D.extend = cc.Class.extend; })()");
    return true;
}

se::Object* __jsb_cocos2d_Sprite3DCache_proto = nullptr;
se::Class* __jsb_cocos2d_Sprite3DCache_class = nullptr;

static bool js_cocos2dx_3d_Sprite3DCache_removeSprite3DData(se::State& s)
{
    cocos2d::Sprite3DCache* cobj = (cocos2d::Sprite3DCache*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3DCache_removeSprite3DData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3DCache_removeSprite3DData : Error processing arguments");
        cobj->removeSprite3DData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3DCache_removeSprite3DData)

static bool js_cocos2dx_3d_Sprite3DCache_removeAllSprite3DData(se::State& s)
{
    cocos2d::Sprite3DCache* cobj = (cocos2d::Sprite3DCache*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Sprite3DCache_removeAllSprite3DData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->removeAllSprite3DData();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3DCache_removeAllSprite3DData)

static bool js_cocos2dx_3d_Sprite3DCache_destroyInstance(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cocos2d::Sprite3DCache::destroyInstance();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3DCache_destroyInstance)

static bool js_cocos2dx_3d_Sprite3DCache_getInstance(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Sprite3DCache* result = cocos2d::Sprite3DCache::getInstance();
        ok &= native_ptr_to_seval<cocos2d::Sprite3DCache>((cocos2d::Sprite3DCache*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Sprite3DCache_getInstance : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Sprite3DCache_getInstance)




bool js_register_cocos2dx_3d_Sprite3DCache(se::Object* obj)
{
    auto cls = se::Class::create("Sprite3DCache", obj, nullptr, nullptr);

    cls->defineFunction("removeSprite3DData", _SE(js_cocos2dx_3d_Sprite3DCache_removeSprite3DData));
    cls->defineFunction("removeAllSprite3DData", _SE(js_cocos2dx_3d_Sprite3DCache_removeAllSprite3DData));
    cls->defineStaticFunction("destroyInstance", _SE(js_cocos2dx_3d_Sprite3DCache_destroyInstance));
    cls->defineStaticFunction("getInstance", _SE(js_cocos2dx_3d_Sprite3DCache_getInstance));
    cls->install();
    JSBClassType::registerClass<cocos2d::Sprite3DCache>(cls);

    __jsb_cocos2d_Sprite3DCache_proto = cls->getProto();
    __jsb_cocos2d_Sprite3DCache_class = cls;

    return true;
}

se::Object* __jsb_cocos2d_Terrain_proto = nullptr;
se::Class* __jsb_cocos2d_Terrain_class = nullptr;

static bool js_cocos2dx_3d_Terrain_initHeightMap(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_initHeightMap : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_initHeightMap : Error processing arguments");
        bool result = cobj->initHeightMap(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_initHeightMap : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_initHeightMap)

static bool js_cocos2dx_3d_Terrain_setMaxDetailMapAmount(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_setMaxDetailMapAmount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_setMaxDetailMapAmount : Error processing arguments");
        cobj->setMaxDetailMapAmount(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_setMaxDetailMapAmount)

static bool js_cocos2dx_3d_Terrain_setDrawWire(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_setDrawWire : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_setDrawWire : Error processing arguments");
        cobj->setDrawWire(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_setDrawWire)

static bool js_cocos2dx_3d_Terrain_setDetailMap(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_setDetailMap : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned int arg0 = 0;
        cocos2d::Terrain::DetailMap arg1;
        ok &= seval_to_uint32(args[0], &arg0);
        #pragma warning NO CONVERSION TO NATIVE FOR DetailMap
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_setDetailMap : Error processing arguments");
        cobj->setDetailMap(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_setDetailMap)

static bool js_cocos2dx_3d_Terrain_resetHeightMap(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_resetHeightMap : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_resetHeightMap : Error processing arguments");
        cobj->resetHeightMap(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_resetHeightMap)

static bool js_cocos2dx_3d_Terrain_setLightDir(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_setLightDir : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_setLightDir : Error processing arguments");
        cobj->setLightDir(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_setLightDir)

static bool js_cocos2dx_3d_Terrain_setAlphaMap(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_setAlphaMap : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Texture2D* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_setAlphaMap : Error processing arguments");
        cobj->setAlphaMap(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_setAlphaMap)

static bool js_cocos2dx_3d_Terrain_setSkirtHeightRatio(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_setSkirtHeightRatio : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_setSkirtHeightRatio : Error processing arguments");
        cobj->setSkirtHeightRatio(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_setSkirtHeightRatio)

static bool js_cocos2dx_3d_Terrain_convertToTerrainSpace(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_convertToTerrainSpace : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec2 arg0;
        ok &= seval_to_Vec2(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_convertToTerrainSpace : Error processing arguments");
        cocos2d::Vec2 result = cobj->convertToTerrainSpace(arg0);
        ok &= Vec2_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_convertToTerrainSpace : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_convertToTerrainSpace)

static bool js_cocos2dx_3d_Terrain_initTextures(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_initTextures : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->initTextures();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_initTextures : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_initTextures)

static bool js_cocos2dx_3d_Terrain_initProperties(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_initProperties : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->initProperties();
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_initProperties : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_initProperties)

static bool js_cocos2dx_3d_Terrain_getHeight(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_3d_Terrain_getHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            cocos2d::Vec2 arg0;
            ok &= seval_to_Vec2(args[0], &arg0);
            if (!ok) { ok = true; break; }
            float result = cobj->getHeight(arg0);
            ok &= float_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getHeight : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            cocos2d::Vec2 arg0;
            ok &= seval_to_Vec2(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            float result = cobj->getHeight(arg0, arg1);
            ok &= float_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getHeight : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            float arg0 = 0;
            ok &= seval_to_float(args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(args[1], &arg1);
            if (!ok) { ok = true; break; }
            float result = cobj->getHeight(arg0, arg1);
            ok &= float_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getHeight : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 3) {
            float arg0 = 0;
            ok &= seval_to_float(args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3* arg2 = nullptr;
            ok &= seval_to_native_ptr(args[2], &arg2);
            if (!ok) { ok = true; break; }
            float result = cobj->getHeight(arg0, arg1, arg2);
            ok &= float_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getHeight : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_getHeight)

static bool js_cocos2dx_3d_Terrain_initWithTerrainData(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_initWithTerrainData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::Terrain::TerrainData arg0;
        cocos2d::Terrain::CrackFixedType arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR TerrainData
        ok = false;
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_initWithTerrainData : Error processing arguments");
        bool result = cobj->initWithTerrainData(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_initWithTerrainData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_initWithTerrainData)

static bool js_cocos2dx_3d_Terrain_setLODDistance(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_setLODDistance : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        ok &= seval_to_float(args[2], &arg2);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_setLODDistance : Error processing arguments");
        cobj->setLODDistance(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_setLODDistance)

static bool js_cocos2dx_3d_Terrain_getTerrainSize(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_getTerrainSize : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Size result = cobj->getTerrainSize();
        ok &= Size_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getTerrainSize : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_getTerrainSize)

static bool js_cocos2dx_3d_Terrain_getIntersectionPoint(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_3d_Terrain_getIntersectionPoint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            cocos2d::Ray arg0;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg1;
            ok &= seval_to_Vec3(args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool result = cobj->getIntersectionPoint(arg0, arg1);
            ok &= boolean_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getIntersectionPoint : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            cocos2d::Ray arg0;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 result = cobj->getIntersectionPoint(arg0);
            ok &= Vec3_to_seval(result, &s.rval());
            JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getIntersectionPoint : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_getIntersectionPoint)

static bool js_cocos2dx_3d_Terrain_getNormal(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_getNormal : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getNormal : Error processing arguments");
        cocos2d::Vec3 result = cobj->getNormal(arg0, arg1);
        ok &= Vec3_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getNormal : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_getNormal)

static bool js_cocos2dx_3d_Terrain_reload(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_reload : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->reload();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_reload)

static bool js_cocos2dx_3d_Terrain_getImageHeight(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_getImageHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t *)&arg0);
        ok &= seval_to_int32(args[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getImageHeight : Error processing arguments");
        float result = cobj->getImageHeight(arg0, arg1);
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getImageHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_getImageHeight)

static bool js_cocos2dx_3d_Terrain_setLightMap(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_setLightMap : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_setLightMap : Error processing arguments");
        cobj->setLightMap(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_setLightMap)

static bool js_cocos2dx_3d_Terrain_setIsEnableFrustumCull(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_setIsEnableFrustumCull : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_setIsEnableFrustumCull : Error processing arguments");
        cobj->setIsEnableFrustumCull(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_setIsEnableFrustumCull)

static bool js_cocos2dx_3d_Terrain_getMinHeight(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_getMinHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMinHeight();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getMinHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_getMinHeight)

static bool js_cocos2dx_3d_Terrain_getMaxHeight(se::State& s)
{
    cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Terrain_getMaxHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMaxHeight();
        ok &= float_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Terrain_getMaxHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Terrain_getMaxHeight)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Terrain_finalize)

static bool js_cocos2dx_3d_Terrain_constructor(se::State& s)
{
    cocos2d::Terrain* cobj = new (std::nothrow) cocos2d::Terrain();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_Terrain_constructor, __jsb_cocos2d_Terrain_class, js_cocos2d_Terrain_finalize)



extern se::Object* __jsb_cocos2d_Node_proto;

bool js_cocos2d_Terrain_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::Terrain)", s.nativeThisObject());
        cocos2d::Terrain* cobj = (cocos2d::Terrain*)s.nativeThisObject();
        if (cobj->getReferenceCount() == 1)
            cobj->autorelease();
        else
            cobj->release();
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Terrain_finalize)

bool js_register_cocos2dx_3d_Terrain(se::Object* obj)
{
    auto cls = se::Class::create("Terrain", obj, __jsb_cocos2d_Node_proto, _SE(js_cocos2dx_3d_Terrain_constructor));

    cls->defineFunction("initHeightMap", _SE(js_cocos2dx_3d_Terrain_initHeightMap));
    cls->defineFunction("setMaxDetailMapAmount", _SE(js_cocos2dx_3d_Terrain_setMaxDetailMapAmount));
    cls->defineFunction("setDrawWire", _SE(js_cocos2dx_3d_Terrain_setDrawWire));
    cls->defineFunction("setDetailMap", _SE(js_cocos2dx_3d_Terrain_setDetailMap));
    cls->defineFunction("resetHeightMap", _SE(js_cocos2dx_3d_Terrain_resetHeightMap));
    cls->defineFunction("setLightDir", _SE(js_cocos2dx_3d_Terrain_setLightDir));
    cls->defineFunction("setAlphaMap", _SE(js_cocos2dx_3d_Terrain_setAlphaMap));
    cls->defineFunction("setSkirtHeightRatio", _SE(js_cocos2dx_3d_Terrain_setSkirtHeightRatio));
    cls->defineFunction("convertToTerrainSpace", _SE(js_cocos2dx_3d_Terrain_convertToTerrainSpace));
    cls->defineFunction("initTextures", _SE(js_cocos2dx_3d_Terrain_initTextures));
    cls->defineFunction("initProperties", _SE(js_cocos2dx_3d_Terrain_initProperties));
    cls->defineFunction("getHeight", _SE(js_cocos2dx_3d_Terrain_getHeight));
    cls->defineFunction("initWithTerrainData", _SE(js_cocos2dx_3d_Terrain_initWithTerrainData));
    cls->defineFunction("setLODDistance", _SE(js_cocos2dx_3d_Terrain_setLODDistance));
    cls->defineFunction("getTerrainSize", _SE(js_cocos2dx_3d_Terrain_getTerrainSize));
    cls->defineFunction("getIntersectionPoint", _SE(js_cocos2dx_3d_Terrain_getIntersectionPoint));
    cls->defineFunction("getNormal", _SE(js_cocos2dx_3d_Terrain_getNormal));
    cls->defineFunction("reload", _SE(js_cocos2dx_3d_Terrain_reload));
    cls->defineFunction("getImageHeight", _SE(js_cocos2dx_3d_Terrain_getImageHeight));
    cls->defineFunction("setLightMap", _SE(js_cocos2dx_3d_Terrain_setLightMap));
    cls->defineFunction("setIsEnableFrustumCull", _SE(js_cocos2dx_3d_Terrain_setIsEnableFrustumCull));
    cls->defineFunction("getMinHeight", _SE(js_cocos2dx_3d_Terrain_getMinHeight));
    cls->defineFunction("getMaxHeight", _SE(js_cocos2dx_3d_Terrain_getMaxHeight));
    cls->defineFinalizedFunction(_SE(js_cocos2d_Terrain_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Terrain>(cls);

    __jsb_cocos2d_Terrain_proto = cls->getProto();
    __jsb_cocos2d_Terrain_class = cls;

    return true;
}

se::Object* __jsb_cocos2d_Bundle3D_proto = nullptr;
se::Class* __jsb_cocos2d_Bundle3D_class = nullptr;

static bool js_cocos2dx_3d_Bundle3D_load(se::State& s)
{
    cocos2d::Bundle3D* cobj = (cocos2d::Bundle3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Bundle3D_load : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_load : Error processing arguments");
        bool result = cobj->load(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_load : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Bundle3D_load)

static bool js_cocos2dx_3d_Bundle3D_loadSkinData(se::State& s)
{
    cocos2d::Bundle3D* cobj = (cocos2d::Bundle3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Bundle3D_loadSkinData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        cocos2d::SkinData* arg1 = nullptr;
        ok &= seval_to_std_string(args[0], &arg0);
        #pragma warning NO CONVERSION TO NATIVE FOR SkinData*
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadSkinData : Error processing arguments");
        bool result = cobj->loadSkinData(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadSkinData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Bundle3D_loadSkinData)

static bool js_cocos2dx_3d_Bundle3D_clear(se::State& s)
{
    cocos2d::Bundle3D* cobj = (cocos2d::Bundle3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Bundle3D_clear : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->clear();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Bundle3D_clear)

static bool js_cocos2dx_3d_Bundle3D_loadMaterials(se::State& s)
{
    cocos2d::Bundle3D* cobj = (cocos2d::Bundle3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Bundle3D_loadMaterials : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::MaterialDatas arg0;
        #pragma warning NO CONVERSION TO NATIVE FOR MaterialDatas
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadMaterials : Error processing arguments");
        bool result = cobj->loadMaterials(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadMaterials : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Bundle3D_loadMaterials)

static bool js_cocos2dx_3d_Bundle3D_loadMeshDatas(se::State& s)
{
    cocos2d::Bundle3D* cobj = (cocos2d::Bundle3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Bundle3D_loadMeshDatas : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::MeshDatas arg0;
        #pragma warning NO CONVERSION TO NATIVE FOR MeshDatas
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadMeshDatas : Error processing arguments");
        bool result = cobj->loadMeshDatas(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadMeshDatas : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Bundle3D_loadMeshDatas)

static bool js_cocos2dx_3d_Bundle3D_loadNodes(se::State& s)
{
    cocos2d::Bundle3D* cobj = (cocos2d::Bundle3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Bundle3D_loadNodes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::NodeDatas arg0;
        #pragma warning NO CONVERSION TO NATIVE FOR NodeDatas
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadNodes : Error processing arguments");
        bool result = cobj->loadNodes(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadNodes : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Bundle3D_loadNodes)

static bool js_cocos2dx_3d_Bundle3D_loadAnimationData(se::State& s)
{
    cocos2d::Bundle3D* cobj = (cocos2d::Bundle3D*)s.nativeThisObject();
    JSB_PRECONDITION2(cobj, false, "js_cocos2dx_3d_Bundle3D_loadAnimationData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        cocos2d::Animation3DData* arg1 = nullptr;
        ok &= seval_to_std_string(args[0], &arg0);
        #pragma warning NO CONVERSION TO NATIVE FOR Animation3DData*
        ok = false;
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadAnimationData : Error processing arguments");
        bool result = cobj->loadAnimationData(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadAnimationData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Bundle3D_loadAnimationData)

static bool js_cocos2dx_3d_Bundle3D_createBundle(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Bundle3D* result = cocos2d::Bundle3D::createBundle();
        ok &= native_ptr_to_seval<cocos2d::Bundle3D>((cocos2d::Bundle3D*)result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_createBundle : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Bundle3D_createBundle)

static bool js_cocos2dx_3d_Bundle3D_destroyBundle(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Bundle3D* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_destroyBundle : Error processing arguments");
        cocos2d::Bundle3D::destroyBundle(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Bundle3D_destroyBundle)

static bool js_cocos2dx_3d_Bundle3D_loadObj(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        cocos2d::MeshDatas arg0;
        cocos2d::MaterialDatas arg1;
        cocos2d::NodeDatas arg2;
        std::string arg3;
        #pragma warning NO CONVERSION TO NATIVE FOR MeshDatas
        ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR MaterialDatas
        ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR NodeDatas
        ok = false;
        ok &= seval_to_std_string(args[3], &arg3);
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadObj : Error processing arguments");
        bool result = cocos2d::Bundle3D::loadObj(arg0, arg1, arg2, arg3);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadObj : Error processing arguments");
        return true;
    }
    if (argc == 5) {
        cocos2d::MeshDatas arg0;
        cocos2d::MaterialDatas arg1;
        cocos2d::NodeDatas arg2;
        std::string arg3;
        const char* arg4 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR MeshDatas
        ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR MaterialDatas
        ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR NodeDatas
        ok = false;
        ok &= seval_to_std_string(args[3], &arg3);
        std::string arg4_tmp; ok &= seval_to_std_string(args[4], &arg4_tmp); arg4 = arg4_tmp.c_str();
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadObj : Error processing arguments");
        bool result = cocos2d::Bundle3D::loadObj(arg0, arg1, arg2, arg3, arg4);
        ok &= boolean_to_seval(result, &s.rval());
        JSB_PRECONDITION2(ok, false, "js_cocos2dx_3d_Bundle3D_loadObj : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_3d_Bundle3D_loadObj)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Bundle3D_finalize)

static bool js_cocos2dx_3d_Bundle3D_constructor(se::State& s)
{
    cocos2d::Bundle3D* cobj = new (std::nothrow) cocos2d::Bundle3D();
    s.thisObject()->setPrivateData(cobj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(js_cocos2dx_3d_Bundle3D_constructor, __jsb_cocos2d_Bundle3D_class, js_cocos2d_Bundle3D_finalize)




bool js_cocos2d_Bundle3D_finalize(se::State& s)
{
    if (s.nativeThisObject() != nullptr)
    {
        cocos2d::log("jsbindings: finalizing JS object %p (cocos2d::Bundle3D)", s.nativeThisObject());
        cocos2d::Bundle3D* cobj = (cocos2d::Bundle3D*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Bundle3D_finalize)

bool js_register_cocos2dx_3d_Bundle3D(se::Object* obj)
{
    auto cls = se::Class::create("Bundle3D", obj, nullptr, _SE(js_cocos2dx_3d_Bundle3D_constructor));

    cls->defineFunction("load", _SE(js_cocos2dx_3d_Bundle3D_load));
    cls->defineFunction("loadSkinData", _SE(js_cocos2dx_3d_Bundle3D_loadSkinData));
    cls->defineFunction("clear", _SE(js_cocos2dx_3d_Bundle3D_clear));
    cls->defineFunction("loadMaterials", _SE(js_cocos2dx_3d_Bundle3D_loadMaterials));
    cls->defineFunction("loadMeshDatas", _SE(js_cocos2dx_3d_Bundle3D_loadMeshDatas));
    cls->defineFunction("loadNodes", _SE(js_cocos2dx_3d_Bundle3D_loadNodes));
    cls->defineFunction("loadAnimationData", _SE(js_cocos2dx_3d_Bundle3D_loadAnimationData));
    cls->defineStaticFunction("createBundle", _SE(js_cocos2dx_3d_Bundle3D_createBundle));
    cls->defineStaticFunction("destroyBundle", _SE(js_cocos2dx_3d_Bundle3D_destroyBundle));
    cls->defineStaticFunction("loadObj", _SE(js_cocos2dx_3d_Bundle3D_loadObj));
    cls->defineFinalizedFunction(_SE(js_cocos2d_Bundle3D_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Bundle3D>(cls);

    __jsb_cocos2d_Bundle3D_proto = cls->getProto();
    __jsb_cocos2d_Bundle3D_class = cls;

    return true;
}

bool register_all_cocos2dx_3d(se::Object* obj)
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

    js_register_cocos2dx_3d_Animate3D(ns);
    js_register_cocos2dx_3d_Sprite3D(ns);
    js_register_cocos2dx_3d_AttachNode(ns);
    js_register_cocos2dx_3d_TextureCube(ns);
    js_register_cocos2dx_3d_Sprite3DCache(ns);
    js_register_cocos2dx_3d_Terrain(ns);
    js_register_cocos2dx_3d_Skybox(ns);
    js_register_cocos2dx_3d_Bundle3D(ns);
    js_register_cocos2dx_3d_Skeleton3D(ns);
    js_register_cocos2dx_3d_BillBoard(ns);
    js_register_cocos2dx_3d_Animation3D(ns);
    js_register_cocos2dx_3d_Mesh(ns);
    return true;
}

