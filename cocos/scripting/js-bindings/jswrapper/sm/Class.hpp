#pragma once

#include "config.hpp"

#ifdef SCRIPT_ENGINE_SM

#include "Base.h"

namespace se {

    class Object;

    class Class
    {
    public:
        Class();
        ~Class();

        bool init(JSContext* cx, const std::string& className, Object* obj, Object* parentProto, JSNative ctor);

        Object* installAndReturnProto();

        void registerFunction(const char* name, JSNative func);
        void registerProperty(const char* name, JSNative getter, JSNative setter);
        void registerStaticFunction(const char* name, JSNative func);
        void registerStaticProperty(const char* name, JSNative getter, JSNative setter);
        void registerFinalizeFunction(JSFinalizeOp func);

        JSObject* _instantiate(const JS::CallArgs& args);

    private:
        std::string _name;
        Object* _parent;
        Object* _proto;
        Object* _parentProto;

        JSContext* _cx;
        JSNative _ctor;

        JSClass _jsCls;
        JSClassOps _classOps;

        std::vector<JSFunctionSpec> _funcs;
        std::vector<JSFunctionSpec> _staticFuncs;
        std::vector<JSPropertySpec> _properties;
        std::vector<JSPropertySpec> _staticProperties;
        JSFinalizeOp _finalizeOp;
    };

} // namespace se {

#endif // SCRIPT_ENGINE_SM

