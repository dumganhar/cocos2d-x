#pragma once

#define SAFE_ADD_REF(obj) if (obj != nullptr) obj->addRef()

#define SAFE_RELEASE(obj) if (obj != nullptr) obj->release()


#define SE_DECLARE_FUNC(funcName) \
    bool funcName(JSContext *cx, unsigned argc, JS::Value* vp)

#define SE_FUNC_BEGIN(funcName) \
    bool funcName(JSContext *cx, unsigned argc, JS::Value* vp) \
    { \
        bool ret = true; \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, vp); \
        JS::Value _thiz = _argv.computeThis(cx); \
        se::ValueArray args; \
        se::internal::jsToSeArgs(cx, argc, _argv, &args); \
        se::Object* thisObject = nullptr; \
        if (se::internal::hasPrivate(_thiz.toObjectOrNull())) \
        { \
            void* _nativeObj = JS_GetPrivate(_thiz.toObjectOrNull()); \
            if (_nativeObj != nullptr) \
            { \
                thisObject = se::Object::getObjectWithPtr(_nativeObj); \
            } \
        }

#define SE_FUNC_END \
        for (auto& v : args) \
        { \
            if (v.isObject() && v.toObject()->isRooted()) \
            { \
                v.toObject()->switchToUnrooted(); \
            } \
        } \
        SAFE_RELEASE(thisObject); \
        return ret; \
    }

#define SE_FINALIZE_FUNC_BEGIN(funcName) \
    void funcName(JSFreeOp* fop, JSObject* obj) \
    { \
        void* nativeThisObject = JS_GetPrivate(obj); \
        se::Object* thisObject = nullptr; \
        if (nativeThisObject != nullptr) \
        { \
            thisObject = se::Object::getObjectWithPtr(nativeThisObject); \
        }

#define SE_FINALIZE_FUNC_END \
        SAFE_RELEASE(thisObject); \
    }

#define SE_FINALIZE_FUNC_GET_PRIVATE_OBJ(jsobj) JS_GetPrivate(obj)

// --- Constructor

#define SE_CTOR_BEGIN(funcName, clsName) \
    bool funcName(JSContext* cx, unsigned argc, JS::Value* vp) \
    { \
        bool ret = true; \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, vp); \
        se::ValueArray args; \
        se::internal::jsToSeArgs(cx, argc, _argv, &args); \
        se::Object* thisObject = se::Object::createObject(clsName, false); \
        _argv.rval().setObject(*thisObject->_getJSObject());

#define SE_CTOR_END \
        SAFE_RELEASE(thisObject); \
        return ret; \
    }

// --- Get Property

#define SE_GET_PROPERTY_BEGIN(funcName) \
    bool funcName(JSContext *cx, unsigned argc, JS::Value* vp) \
    { \
        bool ret = true; \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, vp); \
        JS::Value _thiz = _argv.computeThis(cx); \
        void* _nativeObj = JS_GetPrivate(_thiz.toObjectOrNull()); \
        se::Object* thisObject = nullptr; \
        if (_nativeObj != nullptr) \
        { \
            thisObject = se::Object::getObjectWithPtr(_nativeObj); \
        }

#define SE_GET_PROPERTY_END \
        SAFE_RELEASE(thisObject); \
        return ret; \
    }

#define SE_SET_RVAL(data) \
    se::internal::setReturnValue(cx, data, _argv);

// --- Set Property

#define SE_SET_PROPERTY_BEGIN(funcName) \
    bool funcName(JSContext *cx, unsigned argc, JS::Value *vp) \
    { \
        bool ret = true; \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, vp); \
        JS::Value _thiz = _argv.computeThis(cx); \
        void* _nativeObj = JS_GetPrivate(_thiz.toObjectOrNull()); \
        se::Object* thisObject = nullptr; \
        if (_nativeObj != nullptr) \
        { \
            thisObject = se::Object::getObjectWithPtr(_nativeObj); \
        } \
        se::Value data; \
        se::internal::seToJsValue(cx, _argv[0], &data);

#define SE_SET_PROPERTY_END \
        SAFE_RELEASE(thisObject); \
        return ret; \
    }

