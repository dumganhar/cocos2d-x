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


#define SE_DECLARE_FUNC(funcName) \
    void funcName(const v8::FunctionCallbackInfo<v8::Value>& v8args)

#define SE_FUNC_BEGIN(funcName) \
    void funcName(const v8::FunctionCallbackInfo<v8::Value>& _v8args) \
    { \
        v8::HandleScope _hs(_v8args.GetIsolate()); \
        SE_UNUSED bool ret = false; \
        SE_UNUSED unsigned argc = (unsigned)_v8args.Length(); \
        se::ValueArray args; \
        se::internal::jsToSeArgs(_v8args, &args); \
        se::Object* thisObject = nullptr; \
        if (se::internal::hasPrivate(_v8args.This())) \
        { \
            void* _nativeObj = se::ObjectWrap::unwrap(_v8args.This()); \
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
    }

#define SE_FINALIZE_FUNC_BEGIN(funcName) \
    void funcName(void* nativeThisObject) \
    { \

#define SE_FINALIZE_FUNC_END \
    }

#define SE_CTOR_BEGIN(funcName, clsName) \
    void funcName(const v8::FunctionCallbackInfo<v8::Value>& _v8args) \
    { \
        v8::HandleScope _hs(_v8args.GetIsolate()); \
        SE_UNUSED bool ret = false;

#define SE_CTOR_END \
    }

// --- Get Property

#define SE_GET_PROPERTY_BEGIN(funcName) \
    void funcName(v8::Local<v8::String> _property, const v8::PropertyCallbackInfo<v8::Value>& _v8args) \
    { \
        v8::HandleScope _hs(_v8args.GetIsolate()); \
        SE_UNUSED bool ret = false; \
        se::Object* thisObject = nullptr; \
        if (se::internal::hasPrivate(_v8args.This())) \
        { \
            void* _nativeObj = se::ObjectWrap::unwrap(_v8args.This()); \
            if (_nativeObj != nullptr) \
            { \
                thisObject = se::Object::getObjectWithPtr(_nativeObj); \
            } \
        }

#define SE_GET_PROPERTY_END \
        SAFE_RELEASE(thisObject); \
    }

#define SE_SET_RVAL(data) \
    se::internal::setReturnValue(data, _v8args);

// --- Set Property

#define SE_SET_PROPERTY_BEGIN(funcName) \
    void funcName(v8::Local<v8::String> _property, v8::Local<v8::Value> _value, const v8::PropertyCallbackInfo<void>& _v8args) \
    { \
        v8::HandleScope _hs(_v8args.GetIsolate()); \
        SE_UNUSED bool ret = false; \
        se::Object* thisObject = nullptr; \
        if (se::internal::hasPrivate(_v8args.This())) \
        { \
            void* _nativeObj = se::ObjectWrap::unwrap(_v8args.This()); \
            if (_nativeObj != nullptr) \
            { \
                thisObject = se::Object::getObjectWithPtr(_nativeObj); \
            } \
        } \
        se::Value data; \
        se::internal::jsToSeValue(_v8args, _value, &data);

#define SE_SET_PROPERTY_END \
        SAFE_RELEASE(thisObject); \
    }


#endif // #ifdef SCRIPT_ENGINE_V8
