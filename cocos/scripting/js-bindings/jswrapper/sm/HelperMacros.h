#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_SM

#define SAFE_ADD_REF(obj) if (obj != nullptr) obj->addRef()

#define SAFE_RELEASE(obj) if (obj != nullptr) obj->release()


#define SE_DECLARE_FUNC(funcName) \
    bool funcName(JSContext* _cx, unsigned argc, JS::Value* _vp)

#define SE_FUNC_BEGIN(funcName) \
    bool funcName(JSContext* _cx, unsigned argc, JS::Value* _vp) \
    { \
        bool ret = true; \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, _vp); \
        JS::Value _thiz = _argv.computeThis(_cx); \
        se::ValueArray args; \
        se::internal::jsToSeArgs(_cx, argc, _argv, &args); \
        se::Object* thisObject = nullptr; \
        JS::RootedObject _thizObj(_cx, _thiz.toObjectOrNull()); \
        if (se::internal::hasPrivate(_cx, _thizObj)) \
        { \
            void* _nativeObj = se::internal::getPrivate(_cx, _thizObj); \
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
    void funcName(JSFreeOp* _fop, JSObject* _obj) \
    { \
        void* nativeThisObject = JS_GetPrivate(_obj); \
        se::Object* thisObject = nullptr; \
        if (nativeThisObject != nullptr) \
        { \
            thisObject = se::Object::getObjectWithPtr(nativeThisObject); \
        }

// Should release twice since getObjectWithPtr will addRef.
#define SE_FINALIZE_FUNC_END \
        SAFE_RELEASE(thisObject); \
        SAFE_RELEASE(thisObject); \
    }

// --- Constructor
#define SE_CTOR_BEGIN(funcName, clsName) \
    bool funcName(JSContext* _cx, unsigned argc, JS::Value* _vp) \
    { \
        bool ret = true; \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, _vp); \
        se::ValueArray args; \
        se::internal::jsToSeArgs(_cx, argc, _argv, &args); \
        se::Object* thisObject = se::Object::createObject(clsName, false); \
        _argv.rval().setObject(*thisObject->_getJSObject());


#define SE_CTOR_END \
        se::Value _property; \
        bool _found = false; \
        _found = thisObject->getProperty("_ctor", &_property); \
        if (_found) _property.toObject()->call(args, thisObject); \
        return ret; \
    }

#define SE_CTOR2_BEGIN(funcName, finalizeCb) \
    bool funcName(JSContext* _cx, unsigned argc, JS::Value* _vp) \
    { \
        bool ret = true; \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, _vp); \
        JS::Value _thiz = _argv.computeThis(_cx); \
        se::ValueArray args; \
        se::internal::jsToSeArgs(_cx, argc, _argv, &args); \
        se::Object* thisObject = se::Object::_createJSObject(nullptr, _thiz.toObjectOrNull(), false); \
        thisObject->_setFinalizeCallback(finalizeCb);


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
        return ret; \
    }

// --- Get Property

#define SE_GET_PROPERTY_BEGIN(funcName) \
    bool funcName(JSContext *_cx, unsigned argc, JS::Value* _vp) \
    { \
        bool ret = true; \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, _vp); \
        JS::Value _thiz = _argv.computeThis(_cx); \
        JS::RootedObject _thizObj(_cx, _thiz.toObjectOrNull()); \
        void* _nativeObj = se::internal::getPrivate(_cx, _thizObj); \
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
    se::internal::setReturnValue(_cx, data, _argv);

// --- Set Property

#define SE_SET_PROPERTY_BEGIN(funcName) \
    bool funcName(JSContext *_cx, unsigned argc, JS::Value *_vp) \
    { \
        bool ret = true; \
        JS::CallArgs _argv = JS::CallArgsFromVp(argc, _vp); \
        JS::Value _thiz = _argv.computeThis(_cx); \
        JS::RootedObject _thizObj(_cx, _thiz.toObjectOrNull()); \
        void* _nativeObj = se::internal::getPrivate(_cx, _thizObj); \
        se::Object* thisObject = nullptr; \
        if (_nativeObj != nullptr) \
        { \
            thisObject = se::Object::getObjectWithPtr(_nativeObj); \
        } \
        se::Value data; \
        se::internal::jsToSeValue(_cx, _argv[0], &data);

#define SE_SET_PROPERTY_END \
        SAFE_RELEASE(thisObject); \
        return ret; \
    }

#endif // #ifdef SCRIPT_ENGINE_SM
