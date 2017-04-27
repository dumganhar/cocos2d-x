#pragma once

#define SE_FUNC_BEGIN(funcName) \
    bool funcName(JSContext *cx, unsigned argc, JS::Value* vp) \
    { \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, vp); \
        JS::Value _thiz = _argv.computeThis(cx); \
        se::ValueArray args; \
        se::internal::jsToSeArgs(cx, argc, _argv, &args); \
        se::Object* thisObject = new se::Object(cx, &_thiz.toObject());


#define SE_FUNC_END \
        if (thisObject != nullptr) \
            delete thisObject; \
        return true; \
    }

#define SE_FINALIZE_FUNC_BEGIN(funcName) \
    void funcName(JSFreeOp *fop, JSObject *obj) {


#define SE_FINALIZE_FUNC_END }

// --- Constructor

#define SE_CTOR_BEGIN(funcName, clsName) \
    bool funcName(JSContext* cx, unsigned argc, JS::Value* vp) \
    { \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, vp); \
        se::ValueArray args; \
        se::internal::jsToSeArgs(cx, argc, _argv, &args); \
        se::Class* _cls = se::__clsMap.at(clsName); \
        JS::RootedObject _instanceObject(cx, _cls->_instantiate(_argv)); \
        se::Object* thisObject = new se::Object(cx, _instanceObject);

#define SE_CTOR_SET_NATIVE_OBJ(ptr) \
        JS_SetPrivate(_instanceObject, ptr)

#define SE_CTOR_END \
        if (thisObject != nullptr) \
            delete thisObject; \
        return true; \
    }

// --- Get Property

#define SE_GET_PROPERTY_BEGIN(funcName) \
    bool funcName(JSContext *cx, unsigned argc, JS::Value* vp) \
    { \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, vp);

#define SE_GET_PROPERTY_END \
        return true; \
    }

#define SE_GET_NATIVE_OBJ() \
    JS_GetPrivate(&_argv.computeThis(cx).toObject())

#define SE_SET_RVAL(data) \
    se::internal::setReturnValue(cx, data, _argv);

// --- Set Property

#define SE_SET_PROPERTY_BEGIN(funcName) \
    bool funcName(JSContext *cx, unsigned argc, JS::Value *vp) \
    { \
        JS::CallArgs _argv = JS::CallArgsFromVp( argc, vp ); \
        se::Value data; \
        se::internal::seToJsValue(cx, _argv[0], &data);

#define SE_SET_PROPERTY_END \
        return true; \
    }

