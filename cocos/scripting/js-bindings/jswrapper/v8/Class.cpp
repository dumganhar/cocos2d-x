#include "Class.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Object.hpp"

namespace se {
// ------------------------------------------------------- Object


    Class::Class(v8::Isolate* isolate, const std::string& clsName, Object* parentObj, v8::FunctionCallback ctor)
    : m_isolate(isolate)
    , m_name(clsName)
    , m_parentObject(parentObj)
    , m_constructor(ctor)
    {
        m_constructorTemplate = v8::FunctionTemplate::New(m_isolate, m_constructor);
        m_constructorInstanceTemplate = m_constructorTemplate->InstanceTemplate();
        m_constructorInstanceTemplate->SetInternalFieldCount(1);
    }

    Class::~Class()
    {

    }

    void Class::install()
    {
        m_parentObject->m_obj.Get(m_isolate)->Set(v8::String::NewFromUtf8(m_isolate, m_name.c_str()), m_constructorTemplate->GetFunction());
    }

    void Class::registerFunction(const char* name, v8::FunctionCallback func)
    {
        m_constructorInstanceTemplate->Set(v8::String::NewFromUtf8(m_isolate, name), v8::FunctionTemplate::New(m_isolate, func));
    }

    void Class::registerProperty(const char* name, v8::AccessorGetterCallback getter, v8::AccessorSetterCallback setter)
    {
        m_constructorInstanceTemplate->SetAccessor(v8::String::NewFromUtf8(m_isolate, name), getter, setter);
    }

} // namespace se {

#endif // SCRIPT_ENGINE_V8
