#include "Object.hpp"

#ifdef SCRIPT_ENGINE_JSC

#include "Utils.hpp"
#include "Class.hpp"
#include "ScriptEngine.hpp"

namespace se {
 
    std::unordered_map<void* /*native*/, Object* /*jsobj*/> __nativePtrToObjectMap;

    namespace {
        JSContextRef __cx = nullptr;
    }

    Object::Object()
    : _cls(nullptr)
    , _obj(nullptr)
    , _isRooted(false)
    , _hasPrivateData(false)
    , _isCleanup(false)
    , _finalizeCb(nullptr)
    {
    }

    Object::~Object()
    {
        _cleanup();
    }

    Object* Object::createPlainObject(bool rooted)
    {
        Object* obj = _createJSObject(nullptr, JSObjectMake(__cx, nullptr, nullptr), rooted);
        return obj;
    }

    Object* Object::createObject(const char* clsName, bool rooted)
    {
        Class* cls = nullptr;
        JSObjectRef jsObj = Class::_createJSObject(clsName, &cls);
        Object* obj = _createJSObject(cls, jsObj, rooted);
        return obj;
    }

    Object* Object::getObjectWithPtr(void* ptr)
    {
        Object* obj = nullptr;
        auto iter = __nativePtrToObjectMap.find(ptr);
        if (iter != __nativePtrToObjectMap.end())
        {
            obj = iter->second;
            obj->addRef();
        }
        return obj;
    }

    Object* Object::getOrCreateObjectWithPtr(void* ptr, const char* clsName, bool rooted)
    {
        Object* obj = getObjectWithPtr(ptr);
        if (obj == nullptr)
        {
            obj = createObject(clsName, rooted);
            obj->setPrivateData(ptr);
        }
        return obj;
    }

    Object* Object::createObjectWithClass(Class* cls, bool rooted)
    {
        JSObjectRef jsobj = Class::_createJSObjectWithClass(cls);
        Object* obj = Object::_createJSObject(cls, jsobj, rooted);
        return obj;
    }

    Object* Object::_createJSObject(Class* cls, JSObjectRef obj, bool rooted)
    {
        Object* ret = new Object();
        if (!ret->init(obj, rooted))
        {
            delete ret;
            ret = nullptr;
        }

        ret->_cls = cls;
        return ret;
    }

    bool Object::init(JSObjectRef obj, bool rooted)
    {
        _obj = obj;
        _isRooted = rooted;
        if (_isRooted)
        {
            JSValueProtect(__cx, _obj);
        }
        return true;
    }

    void Object::_cleanup(void* nativeObj/* = nullptr*/)
    {
        if (_isCleanup)
            return;

        if (_hasPrivateData)
        {
            if (nativeObj == nullptr)
            {
                nativeObj = internal::getPrivate(_obj);
            }

            if (nativeObj != nullptr)
            {
                auto iter = __nativePtrToObjectMap.find(nativeObj);
                if (iter != __nativePtrToObjectMap.end())
                {
                    __nativePtrToObjectMap.erase(iter);
                }
            }
            else
            {
                assert(false);
            }
        }

        if (_isRooted)
        {
            JSValueUnprotect(__cx, _obj);
        }

        _isCleanup = true;
    }

    void Object::_setFinalizeCallback(JSObjectFinalizeCallback finalizeCb)
    {
        _finalizeCb = finalizeCb;
    }

    // --- Getter/Setter

    bool Object::getProperty(const char* name, Value* data)
    {
        JSStringRef jsName = JSStringCreateWithUTF8CString(name);
        JSValueRef jsValue = JSObjectGetProperty(__cx, _obj, jsName, nullptr);
        JSStringRelease(jsName);

        internal::jsToSeValue(__cx, jsValue, data);

        return true;
    }

    void Object::setProperty(const char* name, const Value& v)
    {
        JSStringRef jsName = JSStringCreateWithUTF8CString(name);
        JSValueRef jsValue = nullptr;
        JSObjectRef obj = _obj;
        if (v.getType() == Value::Type::Number)
        {
            jsValue = JSValueMakeNumber(__cx, v.toNumber());
        }
        else if (v.getType() == Value::Type::String)
        {
            JSStringRef jsstr = JSStringCreateWithUTF8CString(v.toString().c_str());
            jsValue = JSValueMakeString(__cx, jsstr);
            JSStringRelease(jsstr);
        }
        else if (v.getType() == Value::Type::Boolean)
        {
            jsValue = JSValueMakeBoolean(__cx, v.toBoolean());
        }
        else if (v.getType() == Value::Type::Object)
        {
            jsValue = v.toObject()->_obj;
        }
        else if (v.getType() == Value::Type::Null)
        {
            jsValue = JSValueMakeNull(__cx);
        }
        else
        {
            jsValue = JSValueMakeUndefined(__cx);
        }

        JSObjectSetProperty(__cx, obj, jsName, jsValue, kJSPropertyAttributeNone, nullptr);
        JSStringRelease(jsName);
    }

    // --- call

    bool Object::call(const ValueArray& args, Object* thisObject, Value* rval/* = nullptr*/)
    {
        assert(isFunction());

        JSObjectRef contextObject = nullptr;
        if (thisObject != nullptr)
        {
            contextObject = thisObject->_obj;
        }

        JSValueRef* jsArgs = nullptr;

        if (!args.empty())
        {
            jsArgs = (JSValueRef*)malloc(sizeof(JSValueRef) * args.size());
            internal::seToJsArgs(__cx, args, jsArgs);
        }

        JSValueRef rcValue = JSObjectCallAsFunction(__cx, _obj, contextObject, args.size(), jsArgs, nullptr);
        free(jsArgs);

        if (rval != nullptr && !JSValueIsUndefined(__cx, rcValue))
        {
            internal::jsToSeValue(__cx, rcValue, rval);
            return true;
        }

        return false;
    }

    bool Object::defineFunction(const char* funcName, JSObjectCallAsFunctionCallback func)
    {
        JSStringRef jsName = JSStringCreateWithUTF8CString(funcName);
        JSObjectRef jsFunc = JSObjectMakeFunctionWithCallback(__cx, nullptr, func);
        JSObjectSetProperty(__cx, _obj, jsName, jsFunc, kJSPropertyAttributeNone, nullptr);
        JSStringRelease(jsName);
        return true;
    }

    // --- Arrays

    void Object::getArrayLength( unsigned int *length) 
    {
        assert(false);
    }

    void Object::getArrayElement( unsigned int index, Value *data) 
    {
        assert(false);
    }

    bool Object::isFunction() const
    {
        return JSObjectIsFunction(__cx, _obj);
    }

    bool Object::_isNativeFunction() const
    {
        if (isFunction())
        {
            std::string info;
            internal::forceConvertJsValueToStdString(__cx, _obj, &info);
            if (info.find("[native code]") != std::string::npos)
            {
                return true;
            }
        }
        return false;
    }

    void Object::getAsUint8Array(unsigned char **ptr, unsigned int *length)
    {
        assert(false);
    }

    void Object::getAsUint16Array(unsigned short **ptr, unsigned int *length)
    {
        assert(false);
    }

    bool Object::isTypedArray() const
    {
        assert(false);
        return false;
    }

    void Object::getAsUint32Array(unsigned int **ptr, unsigned int *length)
    {
        assert(false);
    }

    void Object::getAsFloat32Array(float **ptr, unsigned int *length)
    {
        assert(false);
    }

    bool Object::isArray() const
    {
        assert(false);
        return false;
    }

    void* Object::getPrivateData()
    {
        return internal::getPrivate(_obj);
    }

    void Object::setPrivateData(void *data)
    {
        internal::setPrivate(_obj, data, _finalizeCb);
        __nativePtrToObjectMap.emplace(data, this);
        _hasPrivateData = true;
    }

    void Object::setContext(JSContextRef cx)
    {
        __cx = cx;
    }

    void Object::debug(const char *what)
    {
//        printf("Object %p %s\n", this,
//               what);
    }

    JSObjectRef Object::_getJSObject() const
    {
        return _obj;
    }

    Class* Object::_getClass() const
    {
        return _cls;
    }

    void Object::switchToRooted()
    {
        debug("switch to rooted");
        assert(!_isRooted);

        JSValueProtect(__cx, _obj);
        _isRooted = true;
    }

    void Object::switchToUnrooted()
    {
        debug("switch to unrooted");
        assert(_isRooted);

        JSValueUnprotect(__cx, _obj);
        _isRooted = false;
    }
    
    bool Object::isRooted() const
    {
        return _isRooted;
    }

    bool Object::isSame(Object* o) const
    {
        return JSValueIsStrictEqual(__cx, _obj, o->_obj);
    }

    bool Object::attachChild(Object* child)
    {
        assert(child);

        Object* global = ScriptEngine::getInstance()->getGlobalObject();
        Value jsbVal;
        if (!global->getProperty("jsb", &jsbVal))
            return false;
        Object* jsbObj = jsbVal.toObject();

        Value func;

        if (!jsbObj->getProperty("registerNativeRef", &func))
            return false;

        ValueArray args;
        args.push_back(Value(this));
        args.push_back(Value(child));
        func.toObject()->call(args, global);
        return true;
    }

    bool Object::detachChild(Object* child)
    {
        assert(child);
        Object* global = ScriptEngine::getInstance()->getGlobalObject();
        Value jsbVal;
        if (!global->getProperty("jsb", &jsbVal))
            return false;
        Object* jsbObj = jsbVal.toObject();

        Value func;

        if (!jsbObj->getProperty("unregisterNativeRef", &func))
            return false;

        ValueArray args;
        args.push_back(Value(this));
        args.push_back(Value(child));
        func.toObject()->call(args, global);
        return true;
    }

} // namespace se {

#endif // SCRIPT_ENGINE_JSC
