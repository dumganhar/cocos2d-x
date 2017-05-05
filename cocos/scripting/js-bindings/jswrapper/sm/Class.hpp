#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_SM

#include "Base.h"

namespace se {

    class Object;

    class Class
    {
    public:
        Class();
        ~Class();

        static Class* create(const std::string& className, Object* obj, Object* parentProto, JSNative ctor);

        bool init(const std::string& clsName, Object* obj, Object* parentProto, JSNative ctor);

        bool install();
        Object* getProto();

        bool defineFunction(const char *name, JSNative func);
        bool defineProperty(const char *name, JSNative getter, JSNative setter);
        bool defineStaticFunction(const char *name, JSNative func);
        bool defineStaticProperty(const char *name, JSNative getter, JSNative setter);
        bool defineFinalizedFunction(JSFinalizeOp func);

    private:

        static JSObject* _createJSObject(const std::string &clsName);
        static void setContext(JSContext* cx);
        static void cleanup();

        std::string _name;
        Object* _parent;
        Object* _proto;
        Object* _parentProto;

        JSNative _ctor;

        JSClass _jsCls;
        JSClassOps _classOps;

        std::vector<JSFunctionSpec> _funcs;
        std::vector<JSFunctionSpec> _staticFuncs;
        std::vector<JSPropertySpec> _properties;
        std::vector<JSPropertySpec> _staticProperties;
        JSFinalizeOp _finalizeOp;

        friend class ScriptEngine;
        friend class Object;
    };

} // namespace se {

#endif // SCRIPT_ENGINE_SM

