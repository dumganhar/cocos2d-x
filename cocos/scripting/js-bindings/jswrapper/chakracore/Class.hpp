#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_CHAKRACORE

#include "Base.h"

namespace se {

    class Object;

    class Class
    {
    public:
        Class();
        ~Class();

        static Class* create(const std::string& className, Object* obj, Object* parentProto, JsNativeFunction ctor);

        bool init(const std::string& clsName, Object* obj, Object* parentProto, JsNativeFunction ctor);

        bool install();
        Object* getProto();

        bool defineFunction(const char *name, JsNativeFunction func);
        bool defineProperty(const char *name, JSObjectGetPropertyCallback getter, JSObjectSetPropertyCallback setter);
        bool defineStaticFunction(const char *name, JsNativeFunction func);
        bool defineStaticProperty(const char *name, JSObjectGetPropertyCallback getter, JSObjectSetPropertyCallback setter);
        bool defineFinalizedFunction(JsFinalizeCallback func);

    private:

        static JsValueRef _createJSObject(const std::string &clsName, Class** outCls);
        static void setContext(JsContextRef cx);
        static void cleanup();

        std::string _name;
        Object* _parent;
        Object* _proto;
        Object* _parentProto;

        JsNativeFunction _ctor;

        JSClassRef _jsCls;
        JSClassDefinition _jsClsDef;

        std::vector<JsNativeFunction> _funcs;
        std::vector<JsNativeFunction> _staticFuncs;
        std::vector<JSStaticValue> _properties;
        std::vector<JSStaticValue> _staticProperties;
        JsFinalizeCallback _finalizeOp;

        friend class ScriptEngine;
        friend class Object;
    };

} // namespace se {

#endif // SCRIPT_ENGINE_CHAKRACORE

