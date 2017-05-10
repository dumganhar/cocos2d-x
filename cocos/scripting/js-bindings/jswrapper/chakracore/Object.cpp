#include "Object.hpp"
#include "Utils.hpp"
#include "Class.hpp"
#include "ScriptEngine.hpp"

#ifdef SCRIPT_ENGINE_CHAKRACORE

namespace se {
 
    std::unordered_map<void* /*native*/, Object* /*jsobj*/> __nativePtrToObjectMap;

    namespace {
        JsContextRef __cx = nullptr;
    }

    Object::Object()
    : _cls(nullptr)
    , _obj(JS_INVALID_REFERENCE)
    , _isRooted(false)
    , _hasPrivateData(false)
    , _isCleanup(false)
    {
    }

    Object::~Object()
    {
        _cleanup();
    }

    Object* Object::createPlainObject(bool rooted)
    {
        JsValueRef jsobj;
        JsCreateObject(&jsobj);
        Object* obj = _createJSObject(nullptr, jsobj, rooted);
        return obj;
    }

    Object* Object::createObject(const char* clsName, bool rooted)
    {
        Class* cls = nullptr;
        JsValueRef jsObj = Class::_createJSObject(clsName, &cls);
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

    Object* Object::_createJSObject(Class* cls, JsValueRef obj, bool rooted)
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

    bool Object::init(JsValueRef obj, bool rooted)
    {
        _obj = obj;
        _isRooted = rooted;
        if (_isRooted)
        {
            unsigned int count = 0;
            JsAddRef(_obj, &count);
        }
        return true;
    }

    void Object::_cleanup()
    {
        if (_isCleanup)
            return;

        if (_hasPrivateData)
        {
            if (_obj != nullptr)
            {
                void* nativeObj = nullptr;
                JsGetExternalData(_obj, &nativeObj);

                if (nativeObj != nullptr)
                {
                    auto iter = __nativePtrToObjectMap.find(nativeObj);
                    if (iter != __nativePtrToObjectMap.end())
                    {
                        __nativePtrToObjectMap.erase(iter);
                    }
                }
            }
        }

        if (_isRooted)
        {
            unsigned int count = 0;
            JsRelease(_obj, &count);
        }

        _isCleanup = true;
    }

    // --- Getter/Setter

    bool Object::getProperty(const char* name, Value* data)
    {
        JsPropertyIdRef propertyId;
        JsCreatePropertyIdUtf8(name, strlen(name), &propertyId);
        JsValueRef jsValue;
        JsGetProperty(_obj, propertyId, &jsValue);
        internal::jsToSeValue(jsValue, data);

        return true;
    }

    void Object::setProperty(const char* name, const Value& v)
    {
        JsValueRef jsValue = JS_INVALID_REFERENCE;
        internal::seToJsValue(v, &jsValue);
        JsPropertyIdRef propertyId;
        JsCreatePropertyIdUtf8(name, strlen(name), &propertyId);
        JsSetProperty(_obj, propertyId, jsValue, true);
    }

    // --- call

    bool Object::call(const ValueArray& args, Object* thisObject, Value* rval/* = nullptr*/)
    {
        assert(isFunction());

        JsValueRef contextObject = nullptr;
        if (thisObject != nullptr)
        {
            contextObject = thisObject->_obj;
        }

        JsValueRef* jsArgs = (JsValueRef*)malloc(sizeof(JsValueRef) * args.size() + 1); // Requires thisArg as first argument of arguments.

        if (!args.empty())
        {
            internal::seToJsArgs(args, jsArgs + 1);
        }

        jsArgs[0] = contextObject;
        JsValueRef rcValue = JS_INVALID_REFERENCE;
        JsCallFunction(_obj, jsArgs, args.size() + 1, &rcValue);
        free(jsArgs);

        JsValueType type;
        JsGetValueType(rcValue, &type);
        if (rval != JS_INVALID_REFERENCE && type != JsUndefined)
        {
            internal::jsToSeValue(rcValue, rval);
            return true;
        }

        return false;
    }

    bool Object::defineFunction(const char* funcName, JsNativeFunction func)
    {
        JsPropertyIdRef propertyId;
        JsCreatePropertyIdUtf8(funcName, strlen(funcName), &propertyId);

        JsValueRef funcVal = JS_INVALID_REFERENCE;
        JsCreateFunction(func, nullptr, &funcVal);

        JsSetProperty(_obj, propertyId, funcVal, true);
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
        JsValueType type;
        JsGetValueType(_obj, &type);
        if (_obj != JS_INVALID_REFERENCE && type != JsFunction)
        {
            return true;
        }
        return false;
    }

    bool Object::_isNativeFunction() const
    {
        if (isFunction())
        {
            std::string info;
            internal::forceConvertJsValueToStdString(_obj, &info);
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
        void* nativeObj = nullptr;
        JsGetExternalData(_obj, &nativeObj);
        return nativeObj;
    }

    void Object::setPrivateData(void *data)
    {
        JsSetExternalData(_obj, data);
        __nativePtrToObjectMap.emplace(data, this);
        _hasPrivateData = true;
    }

    void Object::debug(const char *what)
    {
//        printf("Object %p %s\n", this,
//               what);
    }

    JsValueRef Object::_getJSObject() const
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

        unsigned int count = 0;
        JsAddRef(_obj, &count);
        _isRooted = true;
    }

    void Object::switchToUnrooted()
    {
        debug("switch to unrooted");
        assert(_isRooted);

        unsigned int count = 0;
        JsRelease(_obj, &count);
        _isRooted = false;
    }
    
    bool Object::isRooted() const
    {
        return _isRooted;
    }

    bool Object::isSame(Object* o) const
    {
        bool same = false;
        JsStrictEquals(_obj, o->_obj, &same);
        return same;
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

#endif // SCRIPT_ENGINE_CHAKRACORE
