#include "Class.hpp"
#include "Object.hpp"
#include "Utils.hpp"

#ifdef SCRIPT_ENGINE_SM

namespace se {

    // --- Global Lookup for Constructor Functions

    namespace {
        std::unordered_map<std::string, Class *> __clsMap;
        JSContext* __cx = nullptr;

        bool empty_contructor(JSContext* cx, uint32_t argc, JS::Value* vp)
        {
            return true;
        }

//        std::string _JSStringToStdString(JSContext* cx, JSString* jsStr)
//        {
//            char* str = JS_EncodeString(cx, jsStr);
//            std::string ret(str);
//            JS_free(cx, str);
//            printf(">>>> key: %s\n", ret.c_str());
//            return ret;
//        }
//
//        bool _getKeys(JSContext* cx, JS::HandleObject obj, std::vector<std::string>* outArr)
//        {
//            if (outArr == nullptr)
//                return false;
//            outArr->clear();
//
//            JS::Rooted<JS::IdVector> props(cx, JS::IdVector(cx));
//            if (!JS_Enumerate(cx, obj, &props))
//                return false;
//
//            std::vector<std::string> keys;
//            for (size_t i = 0, length = props.length(); i < length; ++i)
//            {
//                JS::RootedId id(cx, props[i]);
//                assert(JSID_IS_STRING(id));
//
//                JS::RootedValue keyVal(cx);
//                JS_IdToValue(cx, id, &keyVal);
//
//                JSString* jsKey = keyVal.toString();
//                outArr->push_back(_JSStringToStdString(cx, jsKey));
//            }
//
//            return true;
//        }
//
//        bool _extend(JSContext* cx, unsigned argc, JS::Value* vp)
//        {
//            assert(argc == 3);
//            JS::CallArgs argv = JS::CallArgsFromVp(argc, vp);
//            JS::RootedObject proto(cx, argv[0].toObjectOrNull());
//
//            std::string className = _JSStringToStdString(cx, argv[1].toString());
//
//            JSType type = JS_TypeOfValue(cx, argv[2]);
//            Object* parent = Object::_createJSObject(argv[2].toObjectOrNull(), false);
//
//            std::vector<std::string> keys;
//            _getKeys(cx, proto, &keys);
//
//            JS::RootedValue jsParentCtorVal(cx, argv.thisv());
//            JSFunction* func = JS_ValueToFunction(cx, jsParentCtorVal);
//            JSString* funcName = JS_GetFunctionDisplayId(func);
//            std::string parentCtorName = _JSStringToStdString(cx, funcName);
//
//            auto iter = __clsMap.find(parentCtorName);
//            if (iter == __clsMap.end())
//                return false;
//
//            Class* parentCls = iter->second;
//            Class* subCls = Class::create(className.c_str(), parent, parentCls->getProto(), nullptr);
//            subCls->install();
//            Object* subClsProto = subCls->getProto();
//
//            printf("======: is func: %d\n", subClsProto->isFunction());
//
//            JS::RootedObject jsSubClsProto(cx, subClsProto->_getJSObject());
//            for (const auto& k : keys)
//            {
//                JS::RootedValue v(cx);
//                JS_GetProperty(cx, proto, k.c_str(), &v);
//                JS_SetProperty(cx, jsSubClsProto, k.c_str(), v);
//            }
//
//
////
////            Object* parent = Object::_createJSObject(jsParentCtorObj, false);
//
//            return true;
//        }
    }

    Class::Class()
    : _parent(nullptr)
    , _proto(nullptr)
    , _parentProto(nullptr)
    , _ctor(nullptr)
    , _finalizeOp(nullptr)
    {
        memset(&_jsCls, 0, sizeof(_jsCls));
        memset(&_classOps, 0, sizeof(_classOps));
    }

    Class::~Class()
    {
        SAFE_RELEASE(_parent);
        SAFE_RELEASE(_proto);
        SAFE_RELEASE(_parentProto);
    }

    Class* Class::create(const char* className, Object* obj, Object* parentProto, JSNative ctor)
    {
        Class* cls = new Class();
        if (cls != nullptr && !cls->init(className, obj, parentProto, ctor))
        {
            delete cls;
            cls = nullptr;
        }
        return cls;
    }

    bool Class::init(const char* clsName, Object* parent, Object *parentProto, JSNative ctor)
    {
        _name = clsName;
        _parent = parent;
        if (_parent != nullptr)
            _parent->addRef();
        _parentProto = parentProto;

        if (_parentProto != nullptr)
            _parentProto->addRef();

        _ctor = ctor;
        if (_ctor == nullptr)
        {
            _ctor = empty_contructor;
        }

        return true;
    }

    bool Class::install()
    {
        assert(__clsMap.find(_name) == __clsMap.end());

        __clsMap.emplace(_name, this);

        _jsCls.name = _name;
        _jsCls.flags = JSCLASS_HAS_PRIVATE | JSCLASS_FOREGROUND_FINALIZE; //FIXME: Use JSCLASS_BACKGROUND_FINALIZE to improve GC performance

        _classOps.finalize = _finalizeOp;
        _classOps.trace = nullptr;
        _jsCls.cOps = &_classOps;

        JSObject* parentObj = _parentProto != nullptr ? _parentProto->_getJSObject() : nullptr;
        JS::RootedObject parent(__cx, _parent->_getJSObject());
        JS::RootedObject parentProto(__cx, parentObj);

        _funcs.push_back(JS_FS_END);
        _properties.push_back(JS_PS_END);
        _staticFuncs.push_back(JS_FS_END);
        _staticProperties.push_back(JS_PS_END);

        JS::RootedObject jsobj(__cx,
                               JS_InitClass(__cx, parent, parentProto, &_jsCls,
                                            _ctor, 0,
                                            _properties.data(), _funcs.data(),
                                            _staticProperties.data(), _staticFuncs.data())
                               );

        if (jsobj)
        {
            _proto = Object::_createJSObject(nullptr, jsobj, true);
            return true;
        }

        return false;
    }

    bool Class::defineFunction(const char *name, JSNative func)
    {
        JSFunctionSpec cb = JS_FN(name, func, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE);
        _funcs.push_back(cb);
        return true;
    }

    bool Class::defineProperty(const char *name, JSNative getter, JSNative setter)
    {
        JSPropertySpec property = JS_PSGS(name, getter, setter, JSPROP_ENUMERATE | JSPROP_PERMANENT);
        _properties.push_back(property);
        return true;
    }

    bool Class::defineStaticFunction(const char *name, JSNative func)
    {
        JSFunctionSpec cb = JS_FN(name, func, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE);
        _staticFuncs.push_back(cb);
        return true;
    }

    bool Class::defineStaticProperty(const char *name, JSNative getter, JSNative setter)
    {
        JSPropertySpec property = JS_PSGS(name, getter, setter, JSPROP_ENUMERATE | JSPROP_PERMANENT);
        _staticProperties.push_back(property);
        return true;
    }

    bool Class::defineFinalizedFunction(JSFinalizeOp func)
    {
        _finalizeOp = func;
        return true;
    }

    JSObject* Class::_createJSObject(const std::string &clsName, Class** outCls)
    {
        auto iter = __clsMap.find(clsName);
        if (iter == __clsMap.end())
        {
            *outCls = nullptr;
            return nullptr;
        }

        Class* thiz = iter->second;
        JS::RootedObject obj(__cx, _createJSObjectWithClass(thiz));
        *outCls = thiz;
        return obj;
    }

    JSObject* Class::_createJSObjectWithClass(Class* cls)
    {
        JSObject* proto = cls->_proto != nullptr ? cls->_proto->_getJSObject() : nullptr;
        JS::RootedObject jsProto(__cx, proto);
        JS::RootedObject obj(__cx, JS_NewObjectWithGivenProto(__cx, &cls->_jsCls, jsProto));
        return obj;
    }

    void Class::setContext(JSContext* cx)
    {
        __cx = cx;
    }

    Object *Class::getProto()
    {
        return _proto;
    }

    JSFinalizeOp Class::_getFinalizeCb() const
    {
        return _finalizeOp;
    }

    void Class::cleanup()
    {// TODO:

    }

} // namespace se {

#endif // SCRIPT_ENGINE_SM
