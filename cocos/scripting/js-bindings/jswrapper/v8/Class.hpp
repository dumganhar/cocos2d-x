#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Base.h"

namespace se {

	class Object;

	class Class {

	public:
        Class();
		~Class();

        static Class* create(const std::string& clsName, Object* parent, Object* parentProto, v8::FunctionCallback ctor);

        bool init(const std::string& clsName, Object* parent, Object* parentProto, v8::FunctionCallback ctor);
		bool install();

        bool defineFunction(const char *name, v8::FunctionCallback func);
        bool defineProperty(const char *name, v8::AccessorGetterCallback getter, v8::AccessorSetterCallback setter);
        bool defineStaticFunction(const char *name, v8::FunctionCallback func);
        bool defineStaticProperty(const char *name, v8::AccessorGetterCallback getter, v8::AccessorSetterCallback setter);

	private:

        static v8::Local<v8::Object> _createJSObject(const std::string &clsName);
        static void setIsolate(v8::Isolate* isolate);
		
		std::string _name;
		Object* _parent;
        Object* _parentProto;

        v8::FunctionCallback _ctor;

		v8::Handle<v8::FunctionTemplate> _ctorTemplate;
		v8::Handle<v8::ObjectTemplate> _ctorInstanceTemplate;

        friend class ScriptEngine;
	};

} // namespace se {

#endif // SCRIPT_ENGINE_V8
