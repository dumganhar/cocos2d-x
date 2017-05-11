#pragma once

#define SE_UNUSED_PARAM(unusedparam) (void)unusedparam

#define SAFE_ADD_REF(obj) if (obj != nullptr) obj->addRef()

#define SAFE_RELEASE(obj) if (obj != nullptr) obj->release()


#define SE_DECLARE_FUNC(funcName) \
    JsValueRef funcName(JsValueRef _callee, bool _isConstructCall, JsValueRef* _argv, unsigned short argc, void* _callbackState)

#define SE_FUNC_BEGIN(funcName) \
    JsValueRef funcName(JsValueRef _callee, bool _isConstructCall, JsValueRef* _argv, unsigned short argc, void* _callbackState) \
    { \
        assert(argc > 0); \
        --argc; \
        JsValueRef _jsRet = JS_INVALID_REFERENCE; \
        bool ret = true; \
        se::ValueArray args; \
        se::internal::jsToSeArgs(argc, _argv+1, &args); \
        se::Object* thisObject = nullptr; \
        void* _nativeObj = nullptr; \
        JsGetExternalData(_argv[0], &_nativeObj); \
        if (_nativeObj != nullptr) \
        { \
            thisObject = se::Object::getObjectWithPtr(_nativeObj); \
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
        return _jsRet; \
    }

#define SE_FINALIZE_FUNC_BEGIN(funcName) \
    void funcName(void* nativeThisObject) \
    { \
        se::Object* _thisObject = nullptr; \
        if (nativeThisObject != nullptr) \
        { \
            _thisObject = se::Object::getObjectWithPtr(nativeThisObject); \
            if (_thisObject) _thisObject->_cleanup(); \
            SAFE_RELEASE(_thisObject); \
            SAFE_RELEASE(_thisObject); \
        }

#define SE_FINALIZE_FUNC_END \
    }

// --- Constructor
#define SE_CTOR_BEGIN(funcName, clsName) \
    JsValueRef funcName(JsValueRef _callee, bool _isConstructCall, JsValueRef* _argv, unsigned short argc, void* _callbackState) \
    { \
        bool ret = true; \
        se::ValueArray args; \
        se::internal::jsToSeArgs(argc, _argv, &args); \
        se::Object* thisObject = se::Object::createObject(clsName, false); \
        JsValueRef _jsRet = thisObject->_getJSObject();

#define SE_CTOR_END \
        SAFE_RELEASE(thisObject); \
        return _argv[0]; \
    }

// --- Get Property

#define SE_GET_PROPERTY_BEGIN(funcName) \
    JsValueRef funcName(JsValueRef _callee, bool _isConstructCall, JsValueRef* _argv, unsigned short _argc, void* _callbackState) \
    { \
        assert(_argc == 1); \
        JsValueRef _jsRet = JS_INVALID_REFERENCE; \
        bool ret = true; \
        void* _nativeObj = nullptr; \
        JsGetExternalData(_argv[0], &_nativeObj); \
        se::Object* thisObject = nullptr; \
        if (_nativeObj != nullptr) \
        { \
            thisObject = se::Object::getObjectWithPtr(_nativeObj); \
        }

#define SE_GET_PROPERTY_END \
        SAFE_RELEASE(thisObject); \
        return _jsRet; \
    }

#define SE_SET_RVAL(data) \
    se::internal::seToJsValue(data, &_jsRet)

// --- Set Property

#define SE_SET_PROPERTY_BEGIN(funcName) \
    JsValueRef funcName(JsValueRef _callee, bool _isConstructCall, JsValueRef* _argv, unsigned short _argc, void* _callbackState) \
    { \
        assert(_argc == 2); \
        bool ret = true; \
        void* _nativeObj = nullptr; \
        JsGetExternalData(_argv[0], &_nativeObj); \
        se::Object* thisObject = nullptr; \
        if (_nativeObj != nullptr) \
        { \
            thisObject = se::Object::getObjectWithPtr(_nativeObj); \
        } \
        se::Value data; \
        se::internal::jsToSeValue(_argv[1], &data);

#define SE_SET_PROPERTY_END \
        SAFE_RELEASE(thisObject); \
        return JS_INVALID_REFERENCE; \
    }

