#include "scripting/js-bindings/auto/jsb_cocos2dx_spine_auto.hpp"
#include "scripting/js-bindings/manual/cocos2d_specifics.hpp"
#include "editor-support/spine/spine-cocos2dx.h"

template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS_ReportErrorUTF8(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, JS::Value *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
const JSClass  *jsb_spine_SkeletonRenderer_class;
JSObject *jsb_spine_SkeletonRenderer_prototype;

bool js_cocos2dx_spine_SkeletonRenderer_setTimeScale(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setTimeScale : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setTimeScale : Error processing arguments");
        cobj->setTimeScale(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_setTimeScale : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_getDebugSlotsEnabled(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_getDebugSlotsEnabled : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->getDebugSlotsEnabled();
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_getDebugSlotsEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_setAttachment(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    bool ok = true;
    spine::SkeletonRenderer* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setAttachment : Invalid Native Object");
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            const char* arg1 = nullptr;
            std::string arg1_tmp; ok &= jsval_to_std_string(cx, args.get(1), &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { ok = true; break; }
            bool ret = cobj->setAttachment(arg0, arg1);
            JS::Value jsret = JS::NullValue();
            jsret = JS::BooleanValue(ret);
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            bool ret = cobj->setAttachment(arg0, arg1);
            JS::Value jsret = JS::NullValue();
            jsret = JS::BooleanValue(ret);
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_setAttachment : wrong number of arguments");
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_setBonesToSetupPose(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setBonesToSetupPose : Invalid Native Object");
    if (argc == 0) {
        cobj->setBonesToSetupPose();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_setBonesToSetupPose : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_initWithData(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_initWithData : Invalid Native Object");
    if (argc == 1) {
        spSkeletonData* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR spSkeletonData*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonRenderer_initWithData : Error processing arguments");
        cobj->initWithData(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        spSkeletonData* arg0 = nullptr;
        bool arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR spSkeletonData*
		ok = false;
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonRenderer_initWithData : Error processing arguments");
        cobj->initWithData(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_initWithData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_setDebugSlotsEnabled(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setDebugSlotsEnabled : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setDebugSlotsEnabled : Error processing arguments");
        cobj->setDebugSlotsEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_setDebugSlotsEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_initWithJsonFile(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    bool ok = true;
    spine::SkeletonRenderer* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_initWithJsonFile : Invalid Native Object");
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            cobj->initWithJsonFile(arg0, arg1);
            args.rval().setUndefined();
            return true;
        }
    } while(0);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            cobj->initWithJsonFile(arg0, arg1, arg2);
            args.rval().setUndefined();
            return true;
        }
    } while(0);

    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            cobj->initWithJsonFile(arg0, arg1);
            args.rval().setUndefined();
            return true;
        }
    } while(0);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            cobj->initWithJsonFile(arg0, arg1, arg2);
            args.rval().setUndefined();
            return true;
        }
    } while(0);

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_initWithJsonFile : wrong number of arguments");
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_setSlotsToSetupPose(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setSlotsToSetupPose : Invalid Native Object");
    if (argc == 0) {
        cobj->setSlotsToSetupPose();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_setSlotsToSetupPose : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_initWithBinaryFile(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    bool ok = true;
    spine::SkeletonRenderer* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_initWithBinaryFile : Invalid Native Object");
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            cobj->initWithBinaryFile(arg0, arg1);
            args.rval().setUndefined();
            return true;
        }
    } while(0);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            cobj->initWithBinaryFile(arg0, arg1, arg2);
            args.rval().setUndefined();
            return true;
        }
    } while(0);

    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            cobj->initWithBinaryFile(arg0, arg1);
            args.rval().setUndefined();
            return true;
        }
    } while(0);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            cobj->initWithBinaryFile(arg0, arg1, arg2);
            args.rval().setUndefined();
            return true;
        }
    } while(0);

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_initWithBinaryFile : wrong number of arguments");
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_setToSetupPose(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setToSetupPose : Invalid Native Object");
    if (argc == 0) {
        cobj->setToSetupPose();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_setToSetupPose : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_getBlendFunc(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_getBlendFunc : Invalid Native Object");
    if (argc == 0) {
        const cocos2d::BlendFunc& ret = cobj->getBlendFunc();
        JS::RootedValue jsret(cx);
        jsret = blendfunc_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_getBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_updateWorldTransform(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_updateWorldTransform : Invalid Native Object");
    if (argc == 0) {
        cobj->updateWorldTransform();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_updateWorldTransform : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_initialize(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_initialize : Invalid Native Object");
    if (argc == 0) {
        cobj->initialize();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_initialize : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_setDebugBonesEnabled(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setDebugBonesEnabled : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setDebugBonesEnabled : Error processing arguments");
        cobj->setDebugBonesEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_setDebugBonesEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_getDebugBonesEnabled(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_getDebugBonesEnabled : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->getDebugBonesEnabled();
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_getDebugBonesEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_getTimeScale(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_getTimeScale : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->getTimeScale();
        JS::RootedValue jsret(cx);
        jsret = JS::DoubleValue(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_getTimeScale : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_setBlendFunc(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setBlendFunc : Invalid Native Object");
    if (argc == 1) {
        cocos2d::BlendFunc arg0;
        ok &= jsval_to_blendfunc(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setBlendFunc : Error processing arguments");
        cobj->setBlendFunc(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_setBlendFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_setSkin(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    bool ok = true;
    spine::SkeletonRenderer* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_setSkin : Invalid Native Object");
    do {
        if (argc == 1) {
            const char* arg0 = nullptr;
            std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            bool ret = cobj->setSkin(arg0);
            JS::Value jsret = JS::NullValue();
            jsret = JS::BooleanValue(ret);
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 1) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            bool ret = cobj->setSkin(arg0);
            JS::Value jsret = JS::NullValue();
            jsret = JS::BooleanValue(ret);
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_setSkin : wrong number of arguments");
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_getSkeleton(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_getSkeleton : Invalid Native Object");
    if (argc == 0) {
        spSkeleton* ret = cobj->getSkeleton();
        JS::RootedValue jsret(cx);
        jsret = spskeleton_to_jsval(cx, *ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_getSkeleton : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_drawDebug(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonRenderer* cobj = (spine::SkeletonRenderer *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonRenderer_drawDebug : Invalid Native Object");
    if (argc == 3) {
        cocos2d::Renderer* arg0 = nullptr;
        cocos2d::Mat4 arg1;
        unsigned int arg2 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (cocos2d::Renderer*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_matrix(cx, args.get(1), &arg1);
        ok &= jsval_to_uint32(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonRenderer_drawDebug : Error processing arguments");
        cobj->drawDebug(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_drawDebug : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_createWithFile(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* ret = spine::SkeletonRenderer::createWithFile(arg0, arg1);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonRenderer>(cx, (spine::SkeletonRenderer*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* ret = spine::SkeletonRenderer::createWithFile(arg0, arg1, arg2);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonRenderer>(cx, (spine::SkeletonRenderer*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 0) {
            spine::SkeletonRenderer* ret = spine::SkeletonRenderer::create();
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonRenderer>(cx, (spine::SkeletonRenderer*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* ret = spine::SkeletonRenderer::createWithFile(arg0, arg1);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonRenderer>(cx, (spine::SkeletonRenderer*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonRenderer* ret = spine::SkeletonRenderer::createWithFile(arg0, arg1, arg2);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonRenderer>(cx, (spine::SkeletonRenderer*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_createWithFile : wrong number of arguments");
    return false;
}
bool js_cocos2dx_spine_SkeletonRenderer_constructor(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    bool ok = true;
    spine::SkeletonRenderer* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    do {
        if (argc == 1) {
            spSkeletonData* arg0 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spSkeletonData*
			ok = false;
            if (!ok) { ok = true; break; }
            cobj = new (std::nothrow) spine::SkeletonRenderer(arg0);

            js_type_class_t *typeClass = js_get_type_from_native<spine::SkeletonRenderer>(cobj);
            JS::RootedObject proto(cx, typeClass->proto.ref());
            obj = JS_NewObjectWithGivenProto(cx, typeClass->jsclass, proto);
            js_proxy_t* p = jsb_new_proxy(cobj, obj);
            jsb_ref_init(cx, &p->obj, cobj, "spine::SkeletonRenderer");
        }
    } while(0);

    do {
        if (argc == 2) {
            spSkeletonData* arg0 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spSkeletonData*
			ok = false;
            if (!ok) { ok = true; break; }
            bool arg1;
            arg1 = JS::ToBoolean(args.get(1));
            cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1);

            js_type_class_t *typeClass = js_get_type_from_native<spine::SkeletonRenderer>(cobj);
            JS::RootedObject proto(cx, typeClass->proto.ref());
            obj = JS_NewObjectWithGivenProto(cx, typeClass->jsclass, proto);
            js_proxy_t* p = jsb_new_proxy(cobj, obj);
            jsb_ref_init(cx, &p->obj, cobj, "spine::SkeletonRenderer");
        }
    } while(0);

    do {
        if (argc == 0) {
            cobj = new (std::nothrow) spine::SkeletonRenderer();

            js_type_class_t *typeClass = js_get_type_from_native<spine::SkeletonRenderer>(cobj);
            JS::RootedObject proto(cx, typeClass->proto.ref());
            obj = JS_NewObjectWithGivenProto(cx, typeClass->jsclass, proto);
            js_proxy_t* p = jsb_new_proxy(cobj, obj);
            jsb_ref_init(cx, &p->obj, cobj, "spine::SkeletonRenderer");
        }
    } while(0);

    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1);

            js_type_class_t *typeClass = js_get_type_from_native<spine::SkeletonRenderer>(cobj);
            JS::RootedObject proto(cx, typeClass->proto.ref());
            obj = JS_NewObjectWithGivenProto(cx, typeClass->jsclass, proto);
            js_proxy_t* p = jsb_new_proxy(cobj, obj);
            jsb_ref_init(cx, &p->obj, cobj, "spine::SkeletonRenderer");
        }
    } while(0);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1, arg2);

            js_type_class_t *typeClass = js_get_type_from_native<spine::SkeletonRenderer>(cobj);
            JS::RootedObject proto(cx, typeClass->proto.ref());
            obj = JS_NewObjectWithGivenProto(cx, typeClass->jsclass, proto);
            js_proxy_t* p = jsb_new_proxy(cobj, obj);
            jsb_ref_init(cx, &p->obj, cobj, "spine::SkeletonRenderer");
        }
    } while(0);

    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1);

            js_type_class_t *typeClass = js_get_type_from_native<spine::SkeletonRenderer>(cobj);
            JS::RootedObject proto(cx, typeClass->proto.ref());
            obj = JS_NewObjectWithGivenProto(cx, typeClass->jsclass, proto);
            js_proxy_t* p = jsb_new_proxy(cobj, obj);
            jsb_ref_init(cx, &p->obj, cobj, "spine::SkeletonRenderer");
        }
    } while(0);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            cobj = new (std::nothrow) spine::SkeletonRenderer(arg0, arg1, arg2);

            js_type_class_t *typeClass = js_get_type_from_native<spine::SkeletonRenderer>(cobj);
            JS::RootedObject proto(cx, typeClass->proto.ref());
            obj = JS_NewObjectWithGivenProto(cx, typeClass->jsclass, proto);
            js_proxy_t* p = jsb_new_proxy(cobj, obj);
            jsb_ref_init(cx, &p->obj, cobj, "spine::SkeletonRenderer");
        }
    } while(0);

    if (cobj) {
        if (JS_HasProperty(cx, obj, "_ctor", &ok) && ok)
                ScriptingCore::getInstance()->executeFunctionWithOwner(JS::ObjectValue(*obj), "_ctor", args);

        args.rval().set(JS::ObjectValue(*obj));
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonRenderer_constructor : wrong number of arguments");
    return false;
}


extern JSObject *jsb_cocos2d_Node_prototype;

void js_register_cocos2dx_spine_SkeletonRenderer(JSContext *cx, JS::HandleObject global) {
    static const JSClassOps classOps = {
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr,
        nullptr,
        nullptr,
        nullptr, nullptr, nullptr,
        JS_GlobalObjectTraceHook
    };

    static const JSClass cls = {
        "Skeleton",
        JSCLASS_HAS_RESERVED_SLOTS(2),
        &classOps
    };

    jsb_spine_SkeletonRenderer_class = &cls;

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("setTimeScale", js_cocos2dx_spine_SkeletonRenderer_setTimeScale, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getDebugSlotsEnabled", js_cocos2dx_spine_SkeletonRenderer_getDebugSlotsEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAttachment", js_cocos2dx_spine_SkeletonRenderer_setAttachment, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBonesToSetupPose", js_cocos2dx_spine_SkeletonRenderer_setBonesToSetupPose, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("initWithData", js_cocos2dx_spine_SkeletonRenderer_initWithData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDebugSlotsEnabled", js_cocos2dx_spine_SkeletonRenderer_setDebugSlotsEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("initWithJsonFile", js_cocos2dx_spine_SkeletonRenderer_initWithJsonFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSlotsToSetupPose", js_cocos2dx_spine_SkeletonRenderer_setSlotsToSetupPose, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("initWithBinaryFile", js_cocos2dx_spine_SkeletonRenderer_initWithBinaryFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setToSetupPose", js_cocos2dx_spine_SkeletonRenderer_setToSetupPose, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getBlendFunc", js_cocos2dx_spine_SkeletonRenderer_getBlendFunc, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("updateWorldTransform", js_cocos2dx_spine_SkeletonRenderer_updateWorldTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("initialize", js_cocos2dx_spine_SkeletonRenderer_initialize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDebugBonesEnabled", js_cocos2dx_spine_SkeletonRenderer_setDebugBonesEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getDebugBonesEnabled", js_cocos2dx_spine_SkeletonRenderer_getDebugBonesEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getTimeScale", js_cocos2dx_spine_SkeletonRenderer_getTimeScale, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBlendFunc", js_cocos2dx_spine_SkeletonRenderer_setBlendFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSkin", js_cocos2dx_spine_SkeletonRenderer_setSkin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSkeleton", js_cocos2dx_spine_SkeletonRenderer_getSkeleton, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("drawDebug", js_cocos2dx_spine_SkeletonRenderer_drawDebug, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("create", js_cocos2dx_spine_SkeletonRenderer_createWithFile, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
    jsb_spine_SkeletonRenderer_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_spine_SkeletonRenderer_class,
        js_cocos2dx_spine_SkeletonRenderer_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_spine_SkeletonRenderer_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "SkeletonRenderer"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<spine::SkeletonRenderer>(cx, jsb_spine_SkeletonRenderer_class, proto, parent_proto);
}

const JSClass  *jsb_spine_SkeletonAnimation_class;
JSObject *jsb_spine_SkeletonAnimation_prototype;

bool js_cocos2dx_spine_SkeletonAnimation_setTrackCompleteListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackCompleteListener : Invalid Native Object");
    if (argc == 2) {
        spTrackEntry* arg0 = nullptr;
        std::function<void (spTrackEntry *)> arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR spTrackEntry*
		ok = false;
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[1];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackCompleteListener : Error processing arguments");
        cobj->setTrackCompleteListener(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setTrackCompleteListener : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_findAnimation(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_findAnimation : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_findAnimation : Error processing arguments");
        spAnimation* ret = cobj->findAnimation(arg0);
        JS::RootedValue jsret(cx);
        jsret = spanimation_to_jsval(cx, *ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_findAnimation : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setTrackEventListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackEventListener : Invalid Native Object");
    if (argc == 2) {
        spTrackEntry* arg0 = nullptr;
        std::function<void (spTrackEntry *, spEvent *)> arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR spTrackEntry*
		ok = false;
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0, spEvent* larg1) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[2];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            largv[1] = spevent_to_jsval(cx, *larg1);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(2, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackEventListener : Error processing arguments");
        cobj->setTrackEventListener(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setTrackEventListener : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setMix(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setMix : Invalid Native Object");
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        double arg2 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setMix : Error processing arguments");
        cobj->setMix(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setMix : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setTrackStartListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackStartListener : Invalid Native Object");
    if (argc == 2) {
        spTrackEntry* arg0 = nullptr;
        std::function<void (spTrackEntry *)> arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR spTrackEntry*
		ok = false;
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[1];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackStartListener : Error processing arguments");
        cobj->setTrackStartListener(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setTrackStartListener : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_onTrackEntryEvent(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_onTrackEntryEvent : Invalid Native Object");
    if (argc == 3) {
        spTrackEntry* arg0 = nullptr;
        spEventType arg1;
        spEvent* arg2 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR spTrackEntry*
		ok = false;
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        #pragma warning NO CONVERSION TO NATIVE FOR spEvent*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_onTrackEntryEvent : Error processing arguments");
        cobj->onTrackEntryEvent(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_onTrackEntryEvent : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setDisposeListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setDisposeListener : Invalid Native Object");
    if (argc == 1) {
        std::function<void (spTrackEntry *)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[1];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setDisposeListener : Error processing arguments");
        cobj->setDisposeListener(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setDisposeListener : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setTrackInterruptListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackInterruptListener : Invalid Native Object");
    if (argc == 2) {
        spTrackEntry* arg0 = nullptr;
        std::function<void (spTrackEntry *)> arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR spTrackEntry*
		ok = false;
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[1];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackInterruptListener : Error processing arguments");
        cobj->setTrackInterruptListener(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setTrackInterruptListener : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setEndListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setEndListener : Invalid Native Object");
    if (argc == 1) {
        std::function<void (spTrackEntry *)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[1];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setEndListener : Error processing arguments");
        cobj->setEndListener(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setEndListener : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_getState(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_getState : Invalid Native Object");
    if (argc == 0) {
        spAnimationState* ret = cobj->getState();
        JS::RootedValue jsret(cx);
        jsret = spanimationstate_to_jsval(cx, *ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_getState : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setTrackDisposeListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackDisposeListener : Invalid Native Object");
    if (argc == 2) {
        spTrackEntry* arg0 = nullptr;
        std::function<void (spTrackEntry *)> arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR spTrackEntry*
		ok = false;
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[1];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackDisposeListener : Error processing arguments");
        cobj->setTrackDisposeListener(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setTrackDisposeListener : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setEventListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setEventListener : Invalid Native Object");
    if (argc == 1) {
        std::function<void (spTrackEntry *, spEvent *)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0, spEvent* larg1) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[2];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            largv[1] = spevent_to_jsval(cx, *larg1);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(2, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setEventListener : Error processing arguments");
        cobj->setEventListener(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setEventListener : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setCompleteListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setCompleteListener : Invalid Native Object");
    if (argc == 1) {
        std::function<void (spTrackEntry *)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[1];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setCompleteListener : Error processing arguments");
        cobj->setCompleteListener(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setCompleteListener : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_clearTrack(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_clearTrack : Invalid Native Object");
    if (argc == 0) {
        cobj->clearTrack();
        args.rval().setUndefined();
        return true;
    }
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_clearTrack : Error processing arguments");
        cobj->clearTrack(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_clearTrack : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setInterruptListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setInterruptListener : Invalid Native Object");
    if (argc == 1) {
        std::function<void (spTrackEntry *)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[1];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setInterruptListener : Error processing arguments");
        cobj->setInterruptListener(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setInterruptListener : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_onAnimationStateEvent(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_onAnimationStateEvent : Invalid Native Object");
    if (argc == 3) {
        spTrackEntry* arg0 = nullptr;
        spEventType arg1;
        spEvent* arg2 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR spTrackEntry*
		ok = false;
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        #pragma warning NO CONVERSION TO NATIVE FOR spEvent*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_onAnimationStateEvent : Error processing arguments");
        cobj->onAnimationStateEvent(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_onAnimationStateEvent : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_clearTracks(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_clearTracks : Invalid Native Object");
    if (argc == 0) {
        cobj->clearTracks();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_clearTracks : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setTrackEndListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackEndListener : Invalid Native Object");
    if (argc == 2) {
        spTrackEntry* arg0 = nullptr;
        std::function<void (spTrackEntry *)> arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR spTrackEntry*
		ok = false;
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[1];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setTrackEndListener : Error processing arguments");
        cobj->setTrackEndListener(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setTrackEndListener : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_setStartListener(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    spine::SkeletonAnimation* cobj = (spine::SkeletonAnimation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setStartListener : Invalid Native Object");
    if (argc == 1) {
        std::function<void (spTrackEntry *)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
		        auto lambda = [=](spTrackEntry* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[1];
		            largv[0] = sptrackentry_to_jsval(cx, *larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_spine_SkeletonAnimation_setStartListener : Error processing arguments");
        cobj->setStartListener(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_setStartListener : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_createWithBinaryFile(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* ret = spine::SkeletonAnimation::createWithBinaryFile(arg0, arg1);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonAnimation>(cx, (spine::SkeletonAnimation*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* ret = spine::SkeletonAnimation::createWithBinaryFile(arg0, arg1, arg2);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonAnimation>(cx, (spine::SkeletonAnimation*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* ret = spine::SkeletonAnimation::createWithBinaryFile(arg0, arg1);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonAnimation>(cx, (spine::SkeletonAnimation*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* ret = spine::SkeletonAnimation::createWithBinaryFile(arg0, arg1, arg2);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonAnimation>(cx, (spine::SkeletonAnimation*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_createWithBinaryFile : wrong number of arguments");
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_create(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        auto ret = spine::SkeletonAnimation::create();
        js_type_class_t *typeClass = js_get_type_from_native<spine::SkeletonAnimation>(ret);
        JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "spine::SkeletonAnimation"));
        args.rval().set(JS::ObjectValue(*jsret));
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_create : wrong number of arguments");
    return false;
}

bool js_cocos2dx_spine_SkeletonAnimation_createWithJsonFile(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* ret = spine::SkeletonAnimation::createWithJsonFile(arg0, arg1);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonAnimation>(cx, (spine::SkeletonAnimation*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* ret = spine::SkeletonAnimation::createWithJsonFile(arg0, arg1, arg2);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonAnimation>(cx, (spine::SkeletonAnimation*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* ret = spine::SkeletonAnimation::createWithJsonFile(arg0, arg1);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonAnimation>(cx, (spine::SkeletonAnimation*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            spAtlas* arg1 = nullptr;
            #pragma warning NO CONVERSION TO NATIVE FOR spAtlas*
			ok = false;
            if (!ok) { ok = true; break; }
            double arg2 = 0;
            ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
            if (!ok) { ok = true; break; }
            spine::SkeletonAnimation* ret = spine::SkeletonAnimation::createWithJsonFile(arg0, arg1, arg2);
            JS::Value jsret = JS::NullValue();
            if (ret) {
                jsret = JS::ObjectValue(*js_get_or_create_jsobject<spine::SkeletonAnimation>(cx, (spine::SkeletonAnimation*)ret));
            } else {
                jsret = JS::NullValue();
            };
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    JS_ReportErrorUTF8(cx, "js_cocos2dx_spine_SkeletonAnimation_createWithJsonFile : wrong number of arguments");
    return false;
}
bool js_cocos2dx_spine_SkeletonAnimation_constructor(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    spine::SkeletonAnimation* cobj = new (std::nothrow) spine::SkeletonAnimation();

    js_type_class_t *typeClass = js_get_type_from_native<spine::SkeletonAnimation>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "spine::SkeletonAnimation"));
    args.rval().set(JS::ObjectValue(*jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(JS::ObjectValue(*jsobj), "_ctor", args);
    return true;
}
static bool js_cocos2dx_spine_SkeletonAnimation_ctor(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    spine::SkeletonAnimation *nobj = new (std::nothrow) spine::SkeletonAnimation();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    jsb_ref_init(cx, &p->obj, nobj, "spine::SkeletonAnimation");
    bool isFound = false;
    if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
        ScriptingCore::getInstance()->executeFunctionWithOwner(JS::ObjectValue(*obj), "_ctor", args);
    args.rval().setUndefined();
    return true;
}


extern JSObject *jsb_spine_SkeletonRenderer_prototype;

    
void js_register_cocos2dx_spine_SkeletonAnimation(JSContext *cx, JS::HandleObject global) {
    static const JSClassOps classOps = {
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr,
        nullptr,
        nullptr,
        nullptr, nullptr, nullptr,
        JS_GlobalObjectTraceHook
    };

    static const JSClass cls = {
        "SkeletonAnimation",
        JSCLASS_HAS_RESERVED_SLOTS(2),
        &classOps
    };

    jsb_spine_SkeletonAnimation_class = &cls;

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("setTrackCompleteListener", js_cocos2dx_spine_SkeletonAnimation_setTrackCompleteListener, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("findAnimation", js_cocos2dx_spine_SkeletonAnimation_findAnimation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTrackEventListener", js_cocos2dx_spine_SkeletonAnimation_setTrackEventListener, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setMix", js_cocos2dx_spine_SkeletonAnimation_setMix, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTrackStartListener", js_cocos2dx_spine_SkeletonAnimation_setTrackStartListener, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("onTrackEntryEvent", js_cocos2dx_spine_SkeletonAnimation_onTrackEntryEvent, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDisposeListener", js_cocos2dx_spine_SkeletonAnimation_setDisposeListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTrackInterruptListener", js_cocos2dx_spine_SkeletonAnimation_setTrackInterruptListener, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEndListener", js_cocos2dx_spine_SkeletonAnimation_setEndListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getState", js_cocos2dx_spine_SkeletonAnimation_getState, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTrackDisposeListener", js_cocos2dx_spine_SkeletonAnimation_setTrackDisposeListener, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEventListener", js_cocos2dx_spine_SkeletonAnimation_setEventListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCompleteListener", js_cocos2dx_spine_SkeletonAnimation_setCompleteListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("clearTrack", js_cocos2dx_spine_SkeletonAnimation_clearTrack, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterruptListener", js_cocos2dx_spine_SkeletonAnimation_setInterruptListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("onAnimationStateEvent", js_cocos2dx_spine_SkeletonAnimation_onAnimationStateEvent, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("clearTracks", js_cocos2dx_spine_SkeletonAnimation_clearTracks, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTrackEndListener", js_cocos2dx_spine_SkeletonAnimation_setTrackEndListener, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setStartListener", js_cocos2dx_spine_SkeletonAnimation_setStartListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_cocos2dx_spine_SkeletonAnimation_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("createWithBinaryFile", js_cocos2dx_spine_SkeletonAnimation_createWithBinaryFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("create", js_cocos2dx_spine_SkeletonAnimation_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("createWithJsonFile", js_cocos2dx_spine_SkeletonAnimation_createWithJsonFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_spine_SkeletonRenderer_prototype);
    jsb_spine_SkeletonAnimation_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_spine_SkeletonAnimation_class,
        js_cocos2dx_spine_SkeletonAnimation_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_spine_SkeletonAnimation_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "SkeletonAnimation"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<spine::SkeletonAnimation>(cx, jsb_spine_SkeletonAnimation_class, proto, parent_proto);
    anonEvaluate(cx, global, "(function () { sp.SkeletonAnimation.extend = cc.Class.extend; })()");
}

void register_all_cocos2dx_spine(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sp", &ns);

    js_register_cocos2dx_spine_SkeletonRenderer(cx, ns);
    js_register_cocos2dx_spine_SkeletonAnimation(cx, ns);
}

