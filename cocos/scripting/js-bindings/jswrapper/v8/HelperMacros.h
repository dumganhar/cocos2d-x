#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_V8

#ifdef __GNUC__
#define SE_UNUSED __attribute__ ((unused))
#else
#define SE_UNUSED
#endif

#define SAFE_ADD_REF(obj) if (obj != nullptr) obj->addRef()

#define SAFE_RELEASE(obj) if (obj != nullptr) obj->release()


// FIXME: expose nativeThisObjectect for all macros

#define SE_DECLARE_FUNC(funcName) \
    void funcName(const v8::FunctionCallbackInfo<v8::Value>& v8args)


#define SE_FUNC_BEGIN(funcName, needThisObject) \
    void funcName(const v8::FunctionCallbackInfo<v8::Value>& _v8args) \
    { \
        v8::Isolate* _isolate = _v8args.GetIsolate(); \
        v8::HandleScope _hs(_isolate); \
        SE_UNUSED bool ret = true; \
        SE_UNUSED unsigned argc = (unsigned)_v8args.Length(); \
        se::ValueArray args; \
        se::internal::jsToSeArgs(_v8args, &args); \
        se::Object* thisObject = nullptr; \
        void* nativeThisObject = se::internal::getPrivate(_isolate, _v8args.This()); \
        if (nativeThisObject != nullptr && needThisObject) \
        { \
            thisObject = se::Object::getObjectWithPtr(nativeThisObject); \
        } \

#define SE_FUNC_END \
        for (auto& v : args) \
        { \
            if (v.isObject() && v.toObject()->isRooted()) \
            { \
                v.toObject()->switchToUnrooted(); \
            } \
        } \
        SAFE_RELEASE(thisObject); \
    }

#define SE_FINALIZE_FUNC_BEGIN(funcName) \
    void funcName(void* nativeThisObject) \
    { \

#define SE_FINALIZE_FUNC_END \
    }

// v8 doesn't need to create a new JSObject in SE_CTOR_BEGIN while SpiderMonkey needs.
#define SE_CTOR_BEGIN(funcName, clsName, finalizeCb) \
    void funcName(const v8::FunctionCallbackInfo<v8::Value>& _v8args) \
    { \
        v8::Isolate* _isolate = _v8args.GetIsolate(); \
        v8::HandleScope _hs(_isolate); \
        SE_UNUSED bool ret = true; \
        se::ValueArray args; \
        se::internal::jsToSeArgs(_v8args, &args); \
        se::Object* thisObject = se::Object::_createJSObject(__jsb_##clsName##_class, _v8args.This(), false); \
        thisObject->_setFinalizeCallback(finalizeCb);


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
    }

#define SE_CTOR2_BEGIN SE_CTOR_BEGIN
#define SE_CTOR2_END SE_CTOR_END

// --- Get Property

#define SE_GET_PROPERTY_BEGIN(funcName, needThisObject) \
    void funcName(v8::Local<v8::String> _property, const v8::PropertyCallbackInfo<v8::Value>& _v8args) \
    { \
        v8::Isolate* _isolate = _v8args.GetIsolate(); \
        v8::HandleScope _hs(_isolate); \
        SE_UNUSED bool ret = true; \
        se::Object* thisObject = nullptr; \
        void* nativeThisObject = se::internal::getPrivate(_isolate, _v8args.This()); \
        if (nativeThisObject != nullptr && needThisObject) \
        { \
            thisObject = se::Object::getObjectWithPtr(nativeThisObject); \
        } \

#define SE_GET_PROPERTY_END \
        SAFE_RELEASE(thisObject); \
    }

#define SE_SET_RVAL(data) \
    se::internal::setReturnValue(data, _v8args);

// --- Set Property

#define SE_SET_PROPERTY_BEGIN(funcName, needThisObject) \
    void funcName(v8::Local<v8::String> _property, v8::Local<v8::Value> _value, const v8::PropertyCallbackInfo<void>& _v8args) \
    { \
        v8::Isolate* _isolate = _v8args.GetIsolate(); \
        v8::HandleScope _hs(_isolate); \
        SE_UNUSED bool ret = true; \
        se::Object* thisObject = nullptr; \
        void* nativeThisObject = se::internal::getPrivate(_isolate, _v8args.This()); \
        if (nativeThisObject != nullptr && needThisObject) \
        { \
            thisObject = se::Object::getObjectWithPtr(nativeThisObject); \
        } \
        se::Value data; \
        se::internal::jsToSeValue(_isolate, _value, &data);

#define SE_SET_PROPERTY_END \
        SAFE_RELEASE(thisObject); \
    }


#endif // #ifdef SCRIPT_ENGINE_V8
