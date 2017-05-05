#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Base.h"

namespace se {

	class Object;

	class Class {

	public:
        Class(v8::Isolate* isolate, const std::string& clsName, Object* parentObj, v8::FunctionCallback ctor);
		~Class();

		void install();

		void registerFunction(const char* name, v8::FunctionCallback func);
        void registerProperty(const char* name, v8::AccessorGetterCallback getter, v8::AccessorSetterCallback setter);

	private:

		v8::Isolate* m_isolate;
		std::string m_name;
		Object* m_parentObject;

        v8::FunctionCallback m_constructor;

		v8::Handle<v8::FunctionTemplate> m_constructorTemplate;
		v8::Handle<v8::ObjectTemplate> m_constructorInstanceTemplate;
	};

} // namespace se {

#endif // SCRIPT_ENGINE_V8
