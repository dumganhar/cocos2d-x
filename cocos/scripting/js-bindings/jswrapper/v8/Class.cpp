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
    , _proto(nullptr)
    , _ctor(nullptr)
    {

    }

    Class::~Class()
    {
        SAFE_RELEASE(_proto);
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

        _ctorTemplate.Reset(__isolate, v8::FunctionTemplate::New(__isolate, _ctor));
        _ctorTemplate.Get(__isolate)->InstanceTemplate()->SetInternalFieldCount(1);

        return true;
    }

    void Class::cleanup()
    {
        //TODO:
        assert(false);
    }

    bool Class::install()
    {
        assert(__clsMap.find(_name) == __clsMap.end());

        __clsMap.emplace(_name, this);

        if (_parentProto != nullptr)
        {
            _ctorTemplate.Get(__isolate)->Inherit(_parentProto->_getClass()->_ctorTemplate.Get(__isolate));
        }

        _parent->_getJSObject()->Set(v8::String::NewFromUtf8(__isolate, _name.c_str()), _ctorTemplate.Get(__isolate)->GetFunction());

        _proto = Object::createObject(_name.c_str(), true);
        return true;
    }

    bool Class::defineFunction(const char *name, v8::FunctionCallback func)
    {
        _ctorTemplate.Get(__isolate)->PrototypeTemplate()->Set(v8::String::NewFromUtf8(__isolate, name), v8::FunctionTemplate::New(__isolate, func));
        return true;
    }

    bool Class::defineProperty(const char *name, v8::AccessorGetterCallback getter, v8::AccessorSetterCallback setter)
    {
        _ctorTemplate.Get(__isolate)->PrototypeTemplate()->SetAccessor(v8::String::NewFromUtf8(__isolate, name), getter, setter);
        return true;
    }

    bool Class::defineStaticFunction(const char *name, v8::FunctionCallback func)
    {
        _ctorTemplate.Get(__isolate)->Set(v8::String::NewFromUtf8(__isolate, name), v8::FunctionTemplate::New(__isolate, func));
        return true;
    }

    bool Class::defineStaticProperty(const char *name, v8::AccessorGetterCallback getter, v8::AccessorSetterCallback setter)
    {
//        _ctorTemplate.Get(__isolate)->SetAccessorProperty(v8::String::NewFromUtf8(__isolate, name), v8::FunctionTemplate::New(__isolate, getter), v8::FunctionTemplate::New(__isolate, setter));
        assert(false);
        return true;
    }

    bool Class::defineFinalizedFunction(V8FinalizeFunc finalizeFunc)
    {
        _finalizeFunc = finalizeFunc;
        return true;
    }

    v8::Local<v8::Object> Class::_createJSObject(const std::string &clsName, Class** outCls)
    {
        auto iter = __clsMap.find(clsName);
        if (iter == __clsMap.end())
        {
            *outCls = nullptr;
            return v8::Local<v8::Object>::Cast(v8::Undefined(__isolate));
        }

        *outCls = iter->second;
        return iter->second->_ctorTemplate.Get(__isolate)->InstanceTemplate()->NewInstance();
    }

    Object* Class::getProto() const
    {
        return _proto;
    }

    /* static */
    void Class::setIsolate(v8::Isolate* isolate)
    {
        __isolate = isolate;
    }

} // namespace se {

#endif // SCRIPT_ENGINE_V8
