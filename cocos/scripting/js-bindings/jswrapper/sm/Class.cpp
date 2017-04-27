#include "Class.hpp"
#include "Object.hpp"

#ifdef SCRIPT_ENGINE_SM

namespace se {

    // --- Global Lookup for Constructor Functions

    std::unordered_map<std::string, Class*> __clsMap;

    // ------------------------------------------------------- Object
    void myTracer(JSTracer* trc, JSObject* obj);

    Class::Class()
    : _parent(nullptr)
    , _proto(nullptr)
    , _parentProto(nullptr)
    , _cx(nullptr)
    , _ctor(nullptr)
    , _finalizeOp(nullptr)
    {

    }

    Class::~Class()
    {
    }

    bool Class::init(JSContext *cx, const std::string &className, Object* parent, Object *parentProto, JSNative ctor)
    {
        _cx = cx;
        _name = className;
        _parent = parent;
        _parentProto = parentProto;
        _ctor = ctor;

        return true;
    }

    Object* Class::installAndReturnProto()
    {
        assert(__clsMap.find(_name) == __clsMap.end());

        __clsMap.emplace(_name, this);

        _jsCls.name = _name.c_str();
        _jsCls.flags = JSCLASS_HAS_PRIVATE;
        memset(&_classOps, 0, sizeof(_classOps));
        _classOps.finalize = _finalizeOp;
        _classOps.trace = myTracer;
        _jsCls.cOps = &_classOps;

        JSObject* parentObj = _parentProto != nullptr ? _parentProto->getSMValue()->toObjectOrNull() : nullptr;
        JS::RootedObject parent(_cx, _parent->getSMValue()->toObjectOrNull());
        JS::RootedObject parentProto(_cx, parentObj);

        _funcs.push_back(JS_FS_END);
        _properties.push_back(JS_PS_END);
        _staticFuncs.push_back(JS_FS_END);
        _staticProperties.push_back(JS_PS_END);

        JS::RootedObject jsobj(_cx,
                               JS_InitClass(_cx, parent, parentProto, &_jsCls,
                                            _ctor, 0,
                                            _properties.data(), _funcs.data(),
                                            _staticProperties.data(), _staticFuncs.data())
                               );

        _proto = new Object(_cx, jsobj);
        return _proto;
    }

    void Class::registerFunction(const char* name, JSNative func)
    {
        JSFunctionSpec cb = JS_FN(name, func, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE);
        _funcs.push_back(cb);
    }

    void Class::registerProperty(const char* name, JSNative getter, JSNative setter)
    {
        JSPropertySpec property = JS_PSGS(name, getter, setter, JSPROP_ENUMERATE | JSPROP_PERMANENT);
        _properties.push_back(property);
    }

    void Class::registerStaticFunction(const char* name, JSNative func)
    {
        JSFunctionSpec cb = JS_FN(name, func, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE);
        _staticFuncs.push_back(cb);
    }

    void Class::registerStaticProperty(const char* name, JSNative getter, JSNative setter)
    {
        JSPropertySpec property = JS_PSGS(name, getter, setter, JSPROP_ENUMERATE | JSPROP_PERMANENT);
        _staticProperties.push_back(property);
    }

    void Class::registerFinalizeFunction(JSFinalizeOp func)
    {
        _finalizeOp = func;
    }

    JSObject* Class::_instantiate(const JS::CallArgs& args)
    {
        JSObject* proto = _proto != nullptr ? _proto->getSMValue()->toObjectOrNull() : nullptr;
        JS::RootedObject jsProto(_cx, proto);
        JS::RootedObject obj(_cx, JS_NewObjectWithGivenProto(_cx, &_jsCls, jsProto));

        args.rval().set( JS::ObjectValue( *obj ) );

        return obj;
    }

} // namespace se {

#endif // SCRIPT_ENGINE_SM
