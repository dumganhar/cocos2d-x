#include "Class.hpp"

#ifdef SCRIPT_ENGINE_CHAKRACORE

#include "Object.hpp"
#include "Utils.hpp"

namespace se {

#define JS_FN(name, func) {name, func}
#define JS_FS_END JS_FN(0, 0)
#define JS_PSGS(name, getter, setter) {name, getter, setter}
#define JS_PS_END JS_PSGS(0, 0, 0)

    namespace {
        std::unordered_map<std::string, Class *> __clsMap;

        JsValueRef emptyContructor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState)
        {
            return JS_INVALID_REFERENCE;
        }
    }

    Class::Class()
    : _parent(nullptr)
    , _proto(nullptr)
    , _parentProto(nullptr)
    , _ctor(nullptr)
    , _finalizeOp(nullptr)
    {
    }

    Class::~Class()
    {
        SAFE_RELEASE(_parent);
        SAFE_RELEASE(_proto);
        SAFE_RELEASE(_parentProto);
    }

    Class* Class::create(const std::string& className, Object* obj, Object* parentProto, JsNativeFunction ctor)
    {
        Class* cls = new Class();
        if (cls != nullptr && !cls->init(className, obj, parentProto, ctor))
        {
            delete cls;
            cls = nullptr;
        }
        return cls;
    }

    bool Class::init(const std::string &clsName, Object* parent, Object *parentProto, JsNativeFunction ctor)
    {
        _name = clsName;
        _parent = parent;
        if (_parent != nullptr)
            _parent->addRef();
        _parentProto = parentProto;

        if (_parentProto != nullptr)
            _parentProto->addRef();
        _ctor = ctor;

        return true;
    }

    bool Class::install()
    {
        assert(__clsMap.find(_name) == __clsMap.end());

        __clsMap.emplace(_name, this);

        JsValueRef funcName;
        _CHECK(JsCreateString(_name.c_str(), _name.length(), &funcName));
        JsValueRef jsConstructor;
        if (_ctor == nullptr)
        {
            _ctor = emptyContructor;
        }
        _CHECK(JsCreateNamedFunction(funcName, _ctor, nullptr, &jsConstructor));

        Object* ctorObj = Object::_createJSObject(nullptr, jsConstructor, false);

        // create class's prototype and project its member functions
        JsValueRef prototype;
        _CHECK(JsCreateObject(&prototype));

        Object* prototypeObj = Object::_createJSObject(nullptr, prototype, true);

        for (const auto& func : _funcs)
        {
            prototypeObj->defineFunction(func.name, func.func);
        }

        for (const auto& property : _properties)
        {
            internal::defineProperty(prototype, property.name, property.getter, property.setter, true, true);
        }

        ctorObj->setProperty("prototype", Value(prototypeObj));
        if (_parentProto != nullptr)
        {
            _CHECK(JsSetPrototype(prototype, _parentProto->_getJSObject()));
        }

        for (const auto& sfunc : _staticFuncs)
        {
            ctorObj->defineFunction(sfunc.name, sfunc.func);
        }

        for (const auto& property : _staticProperties)
        {
            internal::defineProperty(jsConstructor, property.name, property.getter, property.setter, true, true);
        }

        _proto = prototypeObj;
        _parent->setProperty(_name.c_str(), Value(ctorObj));

        ctorObj->release();

        return true;
    }

    bool Class::defineFunction(const char *name, JsNativeFunction func)
    {
        JSFunctionSpec cb = JS_FN(name, func);
        _funcs.push_back(cb);
        return true;
    }

    bool Class::defineProperty(const char *name, JsNativeFunction getter, JsNativeFunction setter)
    {
        JSPropertySpec property = JS_PSGS(name, getter, setter);
        _properties.push_back(property);
        return true;
    }

    bool Class::defineStaticFunction(const char *name, JsNativeFunction func)
    {
        JSFunctionSpec cb = JS_FN(name, func);
        _staticFuncs.push_back(cb);
        return true;
    }

    bool Class::defineStaticProperty(const char *name, JsNativeFunction getter, JsNativeFunction setter)
    {
        JSPropertySpec property = JS_PSGS(name, getter, setter);
        _staticProperties.push_back(property);
        return true;
    }

    bool Class::defineFinalizedFunction(JsFinalizeCallback func)
    {
        _finalizeOp = func;
        return true;
    }

    JsValueRef Class::_createJSObject(const std::string &clsName, Class** outCls)
    {
        auto iter = __clsMap.find(clsName);
        if (iter == __clsMap.end())
        {
            *outCls = nullptr;
            return nullptr;
        }

        Class* thiz = iter->second;
        *outCls = thiz;
        return _createJSObjectWithClass(thiz);
    }

    JsValueRef Class::_createJSObjectWithClass(Class* cls)
    {
        JsValueRef obj;
        _CHECK(JsCreateExternalObject(nullptr, cls->_finalizeOp, &obj));

        _CHECK(JsSetPrototype(obj, cls->getProto()->_getJSObject()));
        return obj;
    }

    Object* Class::getProto()
    {
        return _proto;
    }

    void Class::cleanup()
    {// TODO:
        assert(false);
    }

} // namespace se {

#endif // SCRIPT_ENGINE_CHAKRACORE
