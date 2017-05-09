#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_JSC

#include "Base.h"

namespace se {

    class Object;

    class Class
    {
    public:
        Class();
        ~Class();

        static Class* create(const std::string& className, Object* obj, Object* parentProto, JSObjectCallAsConstructorCallback ctor);

        bool init(const std::string& clsName, Object* obj, Object* parentProto, JSObjectCallAsConstructorCallback ctor);

        bool install();
        Object* getProto();

        bool defineFunction(const char *name, JSObjectCallAsFunctionCallback func);
        bool defineProperty(const char *name, JSObjectGetPropertyCallback getter, JSObjectSetPropertyCallback setter);
        bool defineStaticFunction(const char *name, JSObjectCallAsFunctionCallback func);
        bool defineStaticProperty(const char *name, JSObjectGetPropertyCallback getter, JSObjectSetPropertyCallback setter);
        bool defineFinalizedFunction(JSObjectFinalizeCallback func);

    private:

        static JSObjectRef _createJSObject(const std::string &clsName, Class** outCls);
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
        std::vector<JSStaticValue> _properties;
        std::vector<JSStaticValue> _staticProperties;
        JSObjectFinalizeCallback _finalizeOp;

        friend class ScriptEngine;
        friend class Object;
    };

} // namespace se {

#endif // SCRIPT_ENGINE_JSC

