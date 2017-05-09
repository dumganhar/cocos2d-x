#include "Class.hpp"
#include "Object.hpp"

#ifdef SCRIPT_ENGINE_JSC

namespace se {

#define JS_FN(name, func, attr) {name, func, attr}
#define JS_FS_END JS_FN(0, 0, 0)
#define JS_PSGS(name, getter, setter, attr) {name, getter, setter, attr}
#define JS_PS_END JS_PSGS(0, 0, 0, 0)

    // --- Global Lookup for Constructor Functions

    namespace {
        std::unordered_map<std::string, Class *> __clsMap;
        JSContextRef __cx = nullptr;

        JSValueRef _getPropertyCallback(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
        {
            SE_UNUSED_PARAM(context);
            SE_UNUSED_PARAM(object);
            return JSValueMakeUndefined(__cx);
        }

        bool _setPropertyCallback(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef value, JSValueRef* exception)
        {
            SE_UNUSED_PARAM(context);
            SE_UNUSED_PARAM(object);

            return false;
        }

        bool _hasPropertyCallback(JSContextRef context, JSObjectRef object, JSStringRef propertyName)
        {
            SE_UNUSED_PARAM(context);
            SE_UNUSED_PARAM(object);
            
            return false;
        }
    }

    Class::Class()
    : _parent(nullptr)
    , _proto(nullptr)
    , _parentProto(nullptr)
    , _ctor(nullptr)
    , _jsCls(nullptr)
    , _finalizeOp(nullptr)
    {
        _jsClsDef = kJSClassDefinitionEmpty;
    }

    Class::~Class()
    {
        SAFE_RELEASE(_parent);
        SAFE_RELEASE(_proto);
        SAFE_RELEASE(_parentProto);

        JSClassRelease(_jsCls);
    }

    Class* Class::create(const std::string& className, Object* obj, Object* parentProto, JSObjectCallAsConstructorCallback ctor)
    {
        Class* cls = new Class();
        if (cls != nullptr && !cls->init(className, obj, parentProto, ctor))
        {
            delete cls;
            cls = nullptr;
        }
        return cls;
    }

    bool Class::init(const std::string &clsName, Object* parent, Object *parentProto, JSObjectCallAsConstructorCallback ctor)
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

        _jsClsDef.version = 0;
        _jsClsDef.attributes = kJSClassAttributeNone;
        _jsClsDef.className = _name.c_str();
        if (_parentProto != nullptr)
        {
            _jsClsDef.parentClass = _parentProto->_getClass()->_jsCls;
        }

        _funcs.push_back(JS_FS_END);
        _properties.push_back(JS_PS_END);

        _jsClsDef.staticValues = _properties.data();
        _jsClsDef.staticFunctions = _funcs.data();

        _jsClsDef.getProperty = _getPropertyCallback;
        _jsClsDef.setProperty = _setPropertyCallback;
        _jsClsDef.hasProperty = _hasPropertyCallback;

        _jsClsDef.finalize = _finalizeOp;

        _jsCls = JSClassCreate(&_jsClsDef);

        JSObjectRef jsCtor = JSObjectMakeConstructor(__cx, _jsCls, _ctor);

        for (const auto& staticfunc : _staticFuncs)
        {
            JSStringRef name = JSStringCreateWithUTF8CString(staticfunc.name);
            JSObjectRef func = JSObjectMakeFunctionWithCallback(__cx, nullptr, staticfunc.callAsFunction);
            JSObjectSetProperty(__cx, jsCtor, name, func, kJSPropertyAttributeNone, nullptr);
            JSStringRelease(name);

        }
        _proto = Object::_createJSObject(jsCtor, true);
        return true;
    }

    bool Class::defineFunction(const char *name, JSObjectCallAsFunctionCallback func)
    {
        JSStaticFunction cb = JS_FN(name, func, kJSPropertyAttributeNone);
        _funcs.push_back(cb);
        return true;
    }

    bool Class::defineProperty(const char *name, JSObjectGetPropertyCallback getter, JSObjectSetPropertyCallback setter)
    {
        JSStaticValue property = JS_PSGS(name, getter, setter, kJSPropertyAttributeNone);
        _properties.push_back(property);
        return true;
    }

    bool Class::defineStaticFunction(const char *name, JSObjectCallAsFunctionCallback func)
    {
        JSStaticFunction cb = JS_FN(name, func, kJSPropertyAttributeNone);
        _staticFuncs.push_back(cb);
        return true;
    }

    bool Class::defineStaticProperty(const char *name, JSObjectGetPropertyCallback getter, JSObjectSetPropertyCallback setter)
    {
        JSStaticValue property = JS_PSGS(name, getter, setter, kJSPropertyAttributeNone);
        _staticProperties.push_back(property);
        return true;
    }

    bool Class::defineFinalizedFunction(JSObjectFinalizeCallback func)
    {
        _finalizeOp = func;
        return true;
    }

    JSObjectRef Class::_createJSObject(const std::string &clsName, Class** outCls)
    {
        auto iter = __clsMap.find(clsName);
        if (iter == __clsMap.end())
        {
            *outCls = nullptr;
            return nullptr;
        }

        Class* thiz = iter->second;
        JSObjectRef obj = JSObjectMake(__cx, thiz->_jsCls, nullptr);
        *outCls = thiz;
        return obj;
    }

    void Class::setContext(JSContextRef cx)
    {
        __cx = cx;
    }

    Object *Class::getProto()
    {
        return _proto;
    }

    void Class::cleanup()
    {// TODO:

    }

} // namespace se {

#endif // SCRIPT_ENGINE_JSC
