#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_CHAKRACORE

#ifdef __GNUC__
#define SE_UNUSED __attribute__ ((unused))
#else
#define SE_UNUSED
#endif

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
        SE_UNUSED bool ret = true; \
        se::ValueArray args; \
        se::internal::jsToSeArgs(argc, _argv+1, &args); \
        se::Object* thisObject = nullptr; \
        void* nativeThisObject = se::internal::getPrivate(_argv[0]); \
        if (nativeThisObject != nullptr) \
        { \
            thisObject = se::Object::getObjectWithPtr(nativeThisObject); \
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
            if (_thisObject) _thisObject->_cleanup(nativeThisObject); \
            SAFE_RELEASE(_thisObject); \
            SAFE_RELEASE(_thisObject); \
        }

#define SE_FINALIZE_FUNC_END \
    }

// --- Constructor
#define SE_CTOR_BEGIN(funcName, clsName, finalizeCb) \
    JsValueRef funcName(JsValueRef _callee, bool _isConstructCall, JsValueRef* _argv, unsigned short argc, void* _callbackState) \
    { \
        assert(argc > 0); \
        --argc; \
        SE_UNUSED bool ret = true; \
        se::ValueArray args; \
        se::internal::jsToSeArgs(argc, _argv+1, &args); \
        se::Object* thisObject = se::Object::createObjectWithClass(__jsb_##clsName##_class, false); \
        JsValueRef _jsRet = thisObject->_getJSObject();

#define SE_CTOR_END \
        se::Value _property; \
        bool _found = false; \
        _found = thisObject->getProperty("_ctor", &_property); \
        if (_found) _property.toObject()->call(args, thisObject); \
        for (auto& v : args) \
        { \
            if (v.isObject() && v.toObject()->isRooted()) \
            { \
                v.toObject()->switchToUnrooted(); \
            } \
        } \
        return _jsRet; \
    }

#define SE_CTOR2_BEGIN(funcName, clsName, finalizeCb) \
    JsValueRef funcName(JsValueRef _callee, bool _isConstructCall, JsValueRef* _argv, unsigned short argc, void* _callbackState) \
    { \
        assert(argc > 0); \
        --argc; \
        JsValueRef _jsRet = JS_INVALID_REFERENCE; \
        SE_UNUSED bool ret = true; \
        se::ValueArray args; \
        se::internal::jsToSeArgs(argc, _argv+1, &args); \
        se::Object* thisObject = se::Object::_createJSObject(__jsb_##clsName##_class, _argv[0], false); \
        thisObject->_setFinalizeCallback(finalizeCb); \

#define SE_CTOR2_END \
        se::Value _property; \
        bool _found = false; \
        _found = thisObject->getProperty("_ctor", &_property); \
        if (_found) _property.toObject()->call(args, thisObject); \
        for (auto& v : args) \
        { \
            if (v.isObject() && v.toObject()->isRooted()) \
            { \
                v.toObject()->switchToUnrooted(); \
            } \
        } \
        return _jsRet; \
    }


// --- Get Property

#define SE_GET_PROPERTY_BEGIN(funcName) \
    JsValueRef funcName(JsValueRef _callee, bool _isConstructCall, JsValueRef* _argv, unsigned short _argc, void* _callbackState) \
    { \
        assert(_argc == 1); \
        JsValueRef _jsRet = JS_INVALID_REFERENCE; \
        SE_UNUSED bool ret = true; \
        void* nativeThisObject = se::internal::getPrivate(_argv[0]); \
        se::Object* thisObject = nullptr; \
        if (nativeThisObject != nullptr) \
        { \
            thisObject = se::Object::getObjectWithPtr(nativeThisObject); \
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
        SE_UNUSED bool ret = true; \
        void* nativeThisObject = se::internal::getPrivate(_argv[0]); \
        se::Object* thisObject = nullptr; \
        if (nativeThisObject != nullptr) \
        { \
            thisObject = se::Object::getObjectWithPtr(nativeThisObject); \
        } \
        se::Value data; \
        se::internal::jsToSeValue(_argv[1], &data);

#define SE_SET_PROPERTY_END \
        SAFE_RELEASE(thisObject); \
        return JS_INVALID_REFERENCE; \
    }

#endif // #ifdef SCRIPT_ENGINE_CHAKRACORE
