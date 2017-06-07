#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_JSC

#include "Base.h"

namespace se {

    class Object;

    struct JSPropertySpec
    {
        const char* name;
        JSObjectCallAsFunctionCallback getter;
        JSObjectCallAsFunctionCallback setter;
        JSPropertyAttributes attributes;
    };

    class Class
    {
    public:
        Class();
        ~Class();

        static Class* create(const std::string& className, Object* obj, Object* parentProto, JSObjectCallAsConstructorCallback ctor);

        bool install();
        Object* getProto();

        bool defineFunction(const char *name, JSObjectCallAsFunctionCallback func);
        bool defineProperty(const char *name, JSObjectCallAsFunctionCallback getter, JSObjectCallAsFunctionCallback setter);
        bool defineStaticFunction(const char *name, JSObjectCallAsFunctionCallback func);
        bool defineStaticProperty(const char *name, JSObjectCallAsFunctionCallback getter, JSObjectCallAsFunctionCallback setter);
        bool defineFinalizedFunction(JSObjectFinalizeCallback func);

    private:
        bool init(const std::string& clsName, Object* obj, Object* parentProto, JSObjectCallAsConstructorCallback ctor);

//        static JSObjectRef _createJSObject(const std::string &clsName, Class** outCls);
        static JSObjectRef _createJSObjectWithClass(Class* cls);
        
        static void setContext(JSContextRef cx);
        static void cleanup();

        std::string _name;
        Object* _parent;
        Object* _proto;
        Object* _parentProto;

        JSObjectCallAsConstructorCallback _ctor;

        JSClassRef _jsCls;
        JSClassDefinition _jsClsDef;

        std::vector<JSStaticFunction> _funcs;
        std::vector<JSStaticFunction> _staticFuncs;
        std::vector<JSPropertySpec> _properties;
        std::vector<JSPropertySpec> _staticProperties;
        JSObjectFinalizeCallback _finalizeOp;

        friend class ScriptEngine;
        friend class Object;
    };

} // namespace se {

#endif // SCRIPT_ENGINE_JSC

