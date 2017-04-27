#pragma once

#include "config.hpp"

#ifdef SCRIPT_ENGINE_SM

#include "Base.h"

namespace se {

    class Object;
    class Class;
    class Value;

    extern std::unordered_map<std::string, Class*> __clsMap;

    class ScriptEngine
    {
    public:
        ScriptEngine(char*);
        ~ScriptEngine();

    public:

        // --- Global Object
        Object* globalObject();

        // --- Classes
        Class* createClass(const std::string& className, Object* obj, Object* parentProto, JSNative constructor);

        // --- Execute
        bool executeBuffer(const char *string, Value *data = nullptr, const char *fileName = nullptr);
        bool executeBuffer(const char *string, size_t length, Value *data = nullptr, const char *fileName = nullptr);
        bool executeFile(const std::string& filePath, Value* rval = nullptr);

        // --- Run GC
        void gc() { JS_GC( _cx );  }

        bool isValid() { return _isValid; }

    private:

        JSContext* _cx;
        JS::PersistentRootedObject* _global;
        JSCompartment* _oldCompartment;

        Object* _globalObj;

        bool _isValid;
    };

 } // namespace se {

#endif // SCRIPT_ENGINE_SM


