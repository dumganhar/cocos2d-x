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

#define _SE(name) name##Registry

#define SE_DECLARE_FUNC(funcName) \
    void funcName##Registry(const v8::FunctionCallbackInfo<v8::Value>& v8args)


#define SE_BIND_FUNC(funcName) \
    void funcName##Registry(const v8::FunctionCallbackInfo<v8::Value>& _v8args) \
    { \
        bool ret = false; \
        v8::Isolate* _isolate = _v8args.GetIsolate(); \
        v8::HandleScope _hs(_isolate); \
        SE_UNUSED unsigned argc = (unsigned)_v8args.Length(); \
        se::ValueArray args; \
        se::internal::jsToSeArgs(_v8args, &args); \
        void* nativeThisObject = se::internal::getPrivate(_isolate, _v8args.This()); \
        se::State state(nativeThisObject, args); \
        ret = funcName(state); \
        if (ret) \
        { \
            if (!state.rval().isUndefined()) \
                se::internal::setReturnValue(state.rval(), _v8args); \
        } \
        for (auto& v : args) \
        { \
            if (v.isObject() && v.toObject()->isRooted()) \
            { \
                v.toObject()->switchToUnrooted(); \
            } \
        } \
    }

#define SE_BIND_FINALIZE_FUNC(funcName) \
    void funcName##Registry(void* nativeThisObject) \
    { \
        se::State state(nativeThisObject); \
        if (!funcName(state)) \
            return; \
    }

#define SE_DECLARE_FINALIZE_FUNC(funcName) \
    void funcName##Registry(void* nativeThisObject);

// v8 doesn't need to create a new JSObject in SE_BIND_CTOR while SpiderMonkey needs.
#define SE_BIND_CTOR(funcName, cls, finalizeCb) \
    void funcName##Registry(const v8::FunctionCallbackInfo<v8::Value>& _v8args) \
    { \
        v8::Isolate* _isolate = _v8args.GetIsolate(); \
        v8::HandleScope _hs(_isolate); \
        SE_UNUSED bool ret = true; \
        se::ValueArray args; \
        se::internal::jsToSeArgs(_v8args, &args); \
        se::Object* thisObject = se::Object::_createJSObject(cls, _v8args.This(), false); \
        thisObject->_setFinalizeCallback(_SE(finalizeCb)); \
        se::State state(thisObject, args); \
        ret = funcName(state); \
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

#define SE_BIND_SUB_CLS_CTOR SE_BIND_CTOR


#define SE_BIND_PROP_GET(funcName) \
    void funcName##Registry(v8::Local<v8::String> _property, const v8::PropertyCallbackInfo<v8::Value>& _v8args) \
    { \
        v8::Isolate* _isolate = _v8args.GetIsolate(); \
        v8::HandleScope _hs(_isolate); \
        bool ret = true; \
        void* nativeThisObject = se::internal::getPrivate(_isolate, _v8args.This()); \
        se::State state(nativeThisObject); \
        ret = funcName(state); \
        if (ret) \
        { \
            if (!state.rval().isUndefined()) \
                se::internal::setReturnValue(state.rval(), _v8args); \
        } \
    }


#define SE_BIND_PROP_SET(funcName) \
    void funcName##Registry(v8::Local<v8::String> _property, v8::Local<v8::Value> _value, const v8::PropertyCallbackInfo<void>& _v8args) \
    { \
        v8::Isolate* _isolate = _v8args.GetIsolate(); \
        v8::HandleScope _hs(_isolate); \
        bool ret = true; \
        void* nativeThisObject = se::internal::getPrivate(_isolate, _v8args.This()); \
        se::Value data; \
        se::internal::jsToSeValue(_isolate, _value, &data); \
        se::ValueArray args; \
        args.push_back(std::move(data)); \
        se::State state(nativeThisObject, args); \
        ret = funcName(state); \
        if (args[0].isObject() && args[0].toObject()->isRooted()) \
        { \
            args[0].toObject()->switchToUnrooted(); \
        } \
    }



#define SE_TYPE_NAME(t) typeid(t).name()

#define SE_QUOTEME_(x) #x
#define SE_QUOTEME(x) SE_QUOTEME_(x)

//FIXME: implement this macro
#define SE_REPORT_ERROR(fmt, ...) printf("ERROR (" __FILE__ ", " SE_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)

#if COCOS2D_DEBUG > 0

#define SE_ASSERT(cond, fmt, ...) \
    do \
    { \
        if (!(cond)) \
        { \
            printf("ASSERT (" __FILE__ ", " SE_QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__); \
            assert(false); \
        } \
    } while(false)

#else

#define SE_ASSERT(cond, fmt, ...) 

#endif // #if COCOS2D_DEBUG > 0


#endif // #ifdef SCRIPT_ENGINE_V8
