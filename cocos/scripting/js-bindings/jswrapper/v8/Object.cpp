#include "Object.hpp"

#ifdef SCRIPT_ENGINE_V8
#include "Utils.hpp"
#include "Class.hpp"
#include "ScriptEngine.hpp"

namespace se {

    std::unordered_map<void* /*native*/, Object* /*jsobj*/> __nativePtrToObjectMap;
    
    namespace {
        v8::Isolate* __isolate = nullptr;
    }

    Object::Object()
    : _cls(nullptr)
    , _isRooted(false)
    , _hasPrivateData(false)
    {
    }

    Object::~Object()
    {
        if (_isRooted)
        {
            _obj.unref();
        }
    }

    /*static*/
    void Object::nativeObjectFinalizeHook(void* nativeObj)
    {
        if (nativeObj == nullptr)
            return;

        auto iter = __nativePtrToObjectMap.find(nativeObj);
        if (iter != __nativePtrToObjectMap.end())
        {
            iter->second->_getClass()->_finalizeFunc(nativeObj);
            iter->second->release();
            __nativePtrToObjectMap.erase(iter);
        }
    }

    /* static */
    void Object::setIsolate(v8::Isolate* isolate)
    {
        __isolate = isolate;
    }

    Object* Object::createPlainObject(bool rooted)
    {
        v8::Local<v8::Object> jsobj = v8::Object::New(__isolate);
        Object* obj = _createJSObject(jsobj, rooted);
        return obj;
    }

    Object* Object::createObject(const char* clsName, bool rooted)
    {
        Class* cls = nullptr;
        auto jsobj = Class::_createJSObject(clsName, &cls);
        Object* obj = _createJSObject(jsobj, rooted);
        obj->_cls = cls;
        obj->_obj.setFinalizeCallback(nativeObjectFinalizeHook);
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

    Object* Object::_createJSObject(v8::Local<v8::Object> obj, bool rooted)
    {
        Object* ret = new Object();
        if (!ret->init(obj, rooted))
        {
            delete ret;
            ret = nullptr;
        }
        return ret;
    }

    bool Object::init(v8::Local<v8::Object> obj, bool rooted)
    {
        _isRooted = rooted;
        _obj.init(obj);

        if (_isRooted)
        {
            _obj.ref();
        }

        return true;
    }

    bool Object::getProperty(const char *name, Value *data)
    {
        v8::HandleScope handle_scope(__isolate);

        v8::Local<v8::String> nameValue = v8::String::NewFromUtf8(__isolate, name, v8::NewStringType::kNormal).ToLocalChecked();
        v8::Local<v8::Value> result = _obj.handle(__isolate)->Get(nameValue);

        if (data) {
            if (result->IsNumber())
                data->setNumber(result->ToNumber()->Value());
            else if (result->IsString()) {
                v8::String::Utf8Value utf8(result);
                data->setString(*utf8);
            } else if (result->IsBoolean())
                data->setBoolean(result->ToBoolean()->Value());
            else if (result->IsObject())
            {
                Object* obj = Object::_createJSObject(result->ToObject(), false);
                data->setObject(obj);
                obj->release();
            }
            else if (result->IsFunction()) {
                printf("I'm function\n");
            } else if (result->IsNull())
                data->setNull();
            else data->setUndefined();
        }

        return true;
    }

    void Object::setProperty(const char *name, const Value& data)
    {
        v8::Local<v8::String> nameValue = v8::String::NewFromUtf8(__isolate, name, v8::NewStringType::kNormal).ToLocalChecked();

        if (data.getType() == Value::Type::Number) {
            v8::Local<v8::Value> value = v8::Number::New(__isolate, data.toNumber());
            _obj.handle(__isolate)->Set(nameValue, value);
        } else if (data.getType() == Value::Type::String) {
            v8::Local<v8::String> value = v8::String::NewFromUtf8(__isolate, data.toString().c_str(), v8::NewStringType::kNormal).ToLocalChecked();
            _obj.handle(__isolate)->Set(nameValue, value);
        } else if (data.getType() == Value::Type::Boolean) {
            v8::Local<v8::Value> value = v8::Boolean::New(__isolate, data.toBoolean());
            _obj.handle(__isolate)->Set(nameValue, value);
        } else if (data.getType() == Value::Type::Object) {
            _obj.handle(__isolate)->Set(nameValue, data.toObject()->_obj.handle(__isolate));
        } else if (data.getType() == Value::Type::Null) {
            _obj.handle(__isolate)->Set(nameValue, v8::Null(__isolate));
        } else _obj.handle(__isolate)->Set(nameValue, v8::Undefined(__isolate));
    }

    bool Object::isFunction() const
    {
        return const_cast<Object*>(this)->_obj.handle(__isolate)->IsCallable();
    }

    bool Object::isTypedArray() const
    {
        return const_cast<Object*>(this)->_obj.handle(__isolate)->IsTypedArray();
    }

    bool Object::isArray() const
    {
        return const_cast<Object*>(this)->_obj.handle(__isolate)->IsArray();
    }

    void Object::setPrivateData(void* data)
    {
        _obj.wrap(data);
        __nativePtrToObjectMap.emplace(data, this);
        _hasPrivateData = true;
    }

    void* Object::getPrivateData() const
    {
        return ObjectWrap::unwrap(const_cast<Object*>(this)->_obj.handle(__isolate));
    }

    v8::Local<v8::Object> Object::_getJSObject() const
    {
        return const_cast<Object*>(this)->_obj.handle(__isolate);
    }

// --- Call Function

    bool Object::call(const ValueArray& args, Object* thisObject, Value* rval/* = nullptr*/)
    {
        AutoHandleScope hs;
        size_t argc = 0;
        std::vector<v8::Local<v8::Value>> argv;
        argc = args.size();
        internal::seToJsArgs(__isolate, args, &argv);

        v8::Local<v8::Object> thiz = v8::Local<v8::Object>::Cast(v8::Undefined(__isolate));
        if (thisObject != nullptr)
        {
            assert(!thisObject->_obj.persistent().IsEmpty());
            thiz = thisObject->_obj.handle(__isolate);
        }

        assert(!_obj.persistent().IsEmpty());

        for (size_t i = 0; i < argc; ++i)
        {
            if (argv[i].IsEmpty())
            {
                printf("%s argv[%d] is removed!\n", __FUNCTION__, (int)i);
                return false;
            }
        }

        v8::Local<v8::Value> result = _obj.handle(__isolate)->CallAsFunction(thiz, (int)argc, argv.data());

        if (rval)
        {
            if (result->IsNumber())
                rval->setNumber(result->ToNumber()->Value());
            else if (result->IsString()) {
                v8::String::Utf8Value utf8(result);
                rval->setString(*utf8);
            } else if (result->IsBoolean())
                rval->setBoolean(result->ToBoolean()->Value());
            else if (result->IsObject())
            {
                Object* obj = Object::_createJSObject(result->ToObject(), false);
                rval->setObject(obj);
                obj->release();
            }
            else if (result->IsNull())
                rval->setNull();
            else rval->setUndefined();
        }

        return true;
    }

// --- Register Function

    bool Object::defineFunction(const char *funcName, void (*func)(const v8::FunctionCallbackInfo<v8::Value> &args))
    {
        _obj.handle(__isolate)->Set(v8::String::NewFromUtf8(__isolate, funcName), v8::FunctionTemplate::New(__isolate, func)->GetFunction());
        return true;
    }

// --- Arrays

    void Object::getArrayLength(unsigned int *length) {
        int len = _obj.handle(__isolate)->Get(v8::String::NewFromUtf8(__isolate, "length"))->ToObject()->Int32Value();
        *length = len;
    }

    void Object::getArrayElement(unsigned int index, Value *data) {
        v8::Local<v8::Value> result = _obj.handle(__isolate)->Get(index);

        if (data) {
            if (result->IsNumber())
                data->setNumber(result->ToNumber()->Value());
            else if (result->IsString()) {
                v8::String::Utf8Value utf8(result);
                data->setString(*utf8);
            } else if (result->IsBoolean())
                data->setBoolean(result->ToBoolean()->Value());
            else if (result->IsObject())
            {
                Object* obj = Object::_createJSObject(result->ToObject(), false);
                data->setObject(obj);
                obj->release();
            }
            else if (result->IsNull())
                data->setNull();
            else data->setUndefined();
        }
    }

    void Object::getAsFloat32Array(float **ptr, unsigned int *length) {
        float *pt;
        unsigned int len;

        v8::Local<v8::Value> value = _obj.handle(__isolate);

        v8::Local<v8::Float32Array> myarr = _obj.handle(__isolate).As<v8::Float32Array>();
        len = myarr->Length();
        pt = (float *) ((char *) myarr->Buffer()->GetContents().Data() + myarr->ByteOffset());

        *length = len;
        *ptr = pt;
    }

    void Object::getAsUint8Array(unsigned char **ptr, unsigned int *length) {
        unsigned char *pt;
        unsigned int len;

        v8::Local<v8::Value> value = _obj.handle(__isolate);

        v8::Local<v8::Uint8Array> myarr = _obj.handle(__isolate).As<v8::Uint8Array>();

        len = myarr->Length();
        pt = (unsigned char *) myarr->Buffer()->GetContents().Data() + myarr->ByteOffset();

        *length = len;
        *ptr = pt;
    }

    void Object::getAsUint16Array(unsigned short **ptr, unsigned int *length) {
        unsigned short *pt;
        unsigned int len;

        v8::Local<v8::Value> value = _obj.handle(__isolate);

        v8::Local<v8::Uint16Array> myarr = _obj.handle(__isolate).As<v8::Uint16Array>();

        len = myarr->Length();
        pt = (unsigned short *) myarr->Buffer()->GetContents().Data();

        *length = len;
        *ptr = pt;
    }

    void Object::getAsUint32Array(unsigned int **ptr, unsigned int *length) {
        unsigned int *pt;
        unsigned int len;

        v8::Local<v8::Value> value = _obj.handle(__isolate);

        v8::Local<v8::Uint32Array> myarr = _obj.handle(__isolate).As<v8::Uint32Array>();

        len = myarr->Length();

        //ArrayBuffer::Contents float_c=pt=myarr->Buffer()->GetContents();
        pt = (unsigned int *) myarr->Buffer()->GetContents().Data();

        *length = len;
        *ptr = pt;
    }

    Class *Object::_getClass() const {
        return _cls;
    }

    void Object::switchToUnrooted() {
        if (_isRooted) {
            _obj.unref();
        }
    }

    bool Object::isRooted() const {
        return _isRooted;
    }

    bool Object::isSame(Object *o) const {
        Object* a = const_cast<Object*>(this);
        return a->_obj.handle(__isolate) == o->_obj.handle(__isolate);
    }

    bool Object::attachChild(Object *child) {
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

    bool Object::detachChild(Object *child) {
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

#endif // SCRIPT_ENGINE_V8
