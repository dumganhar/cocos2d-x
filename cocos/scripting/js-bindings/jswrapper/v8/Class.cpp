#include "Class.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Object.hpp"

namespace se {
// ------------------------------------------------------- Object

    namespace {
        std::unordered_map<std::string, Class *> __clsMap;
        v8::Isolate* __isolate = nullptr;
    }

    Class::Class()
    : _parent(nullptr)
    , _parentProto(nullptr)
    , _ctor(nullptr)
    {

    }

    Class::~Class()
    {

    }

    /* static */
    Class* Class::create(const std::string& clsName, se::Object* parent, Object* parentProto, v8::FunctionCallback ctor)
    {
        Class* cls = new Class();
        if (cls != nullptr && !cls->init(clsName, parent, parentProto, ctor))
        {
            delete cls;
            cls = nullptr;
        }
        return cls;
    }

    bool Class::init(const std::string& clsName, Object* parent, Object* parentProto, v8::FunctionCallback ctor)
    {
        _name = clsName;
        _parent = parent;
        _parentProto = parentProto;

        _ctorTemplate = v8::FunctionTemplate::New(__isolate, _ctor);
        _ctorInstanceTemplate = _ctorTemplate->InstanceTemplate();
        _ctorInstanceTemplate->SetInternalFieldCount(1);

        return true;
    }

    bool Class::install()
    {
        assert(__clsMap.find(_name) == __clsMap.end());

        __clsMap.emplace(_name, this);
        _parent->_obj.Get(__isolate)->Set(v8::String::NewFromUtf8(__isolate, _name.c_str()), _ctorTemplate->GetFunction());
        return true;
    }

    bool Class::defineFunction(const char *name, v8::FunctionCallback func)
    {
        _ctorTemplate->PrototypeTemplate()->Set(v8::String::NewFromUtf8(__isolate, name), v8::FunctionTemplate::New(__isolate, func));
        return true;
    }

    bool Class::defineProperty(const char *name, v8::AccessorGetterCallback getter, v8::AccessorSetterCallback setter)
    {
        _ctorTemplate->PrototypeTemplate()->SetAccessor(v8::String::NewFromUtf8(__isolate, name), getter, setter);
        return true;
    }

    bool Class::defineStaticFunction(const char *name, v8::FunctionCallback func)
    {
        assert(false);
        return true;
    }

    bool Class::defineStaticProperty(const char *name, v8::AccessorGetterCallback getter, v8::AccessorSetterCallback setter)
    {
        assert(false);
        return true;
    }

    v8::Local<v8::Object> Class::_createJSObject(const std::string &clsName)
    {
        auto iter = __clsMap.find(clsName);
        if (iter == __clsMap.end())
            return v8::Local<v8::Object>();

        return iter->second->_ctorInstanceTemplate->NewInstance();
    }

    /* static */
    void Class::setIsolate(v8::Isolate* isolate)
    {
        __isolate = isolate;
    }

} // namespace se {

#endif // SCRIPT_ENGINE_V8
