#include "Object.hpp"
#include "internal/Utils.hpp"
#include "Class.hpp"
#include "ScriptEngine.hpp"

#ifdef SCRIPT_ENGINE_SM

namespace se {
 
    std::unordered_map<void* /*native*/, Object* /*jsobj*/> __nativePtrToObjectMap;

    namespace {
        JSContext *__cx = nullptr;

        void get_or_create_js_obj(JSContext* cx, JS::HandleObject obj, const std::string &name, JS::MutableHandleObject jsObj)
        {
            JS::RootedValue nsval(cx);
            JS_GetProperty(cx, obj, name.c_str(), &nsval);
            if (nsval.isNullOrUndefined()) {
                jsObj.set(JS_NewPlainObject(cx));
                nsval = JS::ObjectValue(*jsObj);
                JS_SetProperty(cx, obj, name.c_str(), nsval);
            } else {
                jsObj.set(nsval.toObjectOrNull());
            }
        }

//        void on_context_destroy(void* data)
//        {
//            auto self = static_cast<Object*>(data);
//            self->invalidate();
//        }
    }

    // ------------------------------------------------------- Object

    Object::Object(JSObject* obj, bool rooted)
    : _isRooted(false)
    , _hasWeakRef(false)
    , _root(nullptr)
    , m_notify(nullptr)
    , m_data(nullptr)
    , _hasPrivateData(false)
    {
        debug("created");
        if (rooted)
            putToRoot(obj);
        else
            putToHeap(obj);
    }

    Object::~Object()
    {
        if (_hasPrivateData)
        {
            void* nativeObj = JS_GetPrivate(_getJSObject());
            auto iter = __nativePtrToObjectMap.find(nativeObj);
            if (iter != __nativePtrToObjectMap.end())
            {
                __nativePtrToObjectMap.erase(iter);
            }
        }

        if (_isRooted)
            teardownRooting();
    }

    Object* Object::createPlainObject()
    {
        Object* obj = new Object(JS_NewPlainObject(__cx), true);
        return obj;
    }

    Object* Object::createObject(const char* clsName, bool rooted)
    {
        Object* obj = new Object(Class::_createJSObject(clsName), rooted);
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
        Object* obj = nullptr;
        auto iter = __nativePtrToObjectMap.find(ptr);
        if (iter != __nativePtrToObjectMap.end())
        {
            obj = iter->second;
            obj->addRef();
        }
        else
        {
            obj = new Object(Class::_createJSObject(clsName), rooted);
            obj->setPrivateData(ptr);
        }
        return obj;
    }

    // --- Getter/Setter

    bool Object::getProperty(const char* name, Value* data)
    {
        JS::RootedObject object(__cx, _getJSObject());

        JS::RootedValue rcValue(__cx);
        bool ok = JS_GetProperty(__cx, object, name, &rcValue);

        if (ok && data)
        {
            if (rcValue.isString())
            {
                JSString *jsstring = rcValue.toString();
                const char *stringData = JS_EncodeString(__cx, jsstring);

                data->setString( stringData);
                JS_free(__cx, (void *) stringData);
            }
            else if (rcValue.isNumber())
            {
                data->setNumber( rcValue.toNumber());
            }
            else if (rcValue.isBoolean())
            {
                data->setBoolean( rcValue.toBoolean());
            }
            else if (rcValue.isObject())
            {
                Object* obj = new Object(&rcValue.toObject(), true);
                data->setObject(obj);
                obj->release();
            }
            else if (rcValue.isNull())
            {
                data->setNull();
            }
            else
            {
                data->setUndefined();
            }
        }

        return ok;
    }

    void Object::setProperty(const char* name, const Value& v)
    {
        JS::RootedObject object(__cx, _getJSObject());

        if (v.getType() == Value::Type::Number)
        {
            JS::RootedValue value(__cx);
            value.setDouble( v.toNumber());
            JS_SetProperty(__cx, object, name, value);
        }
        else if (v.getType() == Value::Type::String)
        {
            JSString *string = JS_NewStringCopyN(__cx, v.toString().c_str(), v.toString().length());
            JS::RootedValue value(__cx);
            value.setString( string);
            JS_SetProperty(__cx, object, name, value);
        }
        else if (v.getType() == Value::Type::Boolean)
        {
            JS::RootedValue value(__cx);
            value.setBoolean( v.toBoolean());
            JS_SetProperty(__cx, object, name, value);
        }
        else if (v.getType() == Value::Type::Object)
        {
            JS::RootedValue value(__cx);
            value.setObject(*v.toObject()->_getJSObject());
            JS_SetProperty(__cx, object, name, value);
        }
        else if (v.getType() == Value::Type::Null)
        {
            JS::RootedValue value(__cx);
            value.setNull();
            JS_SetProperty(__cx, object, name, value);
        }
        else
        {
            JS::RootedValue value(__cx);
            value.setUndefined();
            JS_SetProperty(__cx, object, name, value);
        }
    }

    // --- call

    bool Object::call(const ValueArray& args, Object* thisObject, Value* rval/* = nullptr*/)
    {
        assert(isFunction());

        JS::AutoValueVector jsarr(__cx);
        jsarr.reserve(args.size());
        internal::seToJsArgs(__cx, args, &jsarr);

        JS::RootedObject contextObject(__cx);
        if (thisObject != nullptr)
        {
            contextObject.set(thisObject->_getJSObject());
        }
        else
        {
            contextObject.set(JS::CurrentGlobalOrNull(__cx));
        }

        JSObject* funcObj = _getJSObject();
        JS::RootedValue func(__cx, JS::ObjectValue(*funcObj));
        JS::RootedValue rcValue(__cx);

        bool ok = JS_CallFunctionValue(__cx, contextObject, func, jsarr, &rcValue);

        if (ok && rval != nullptr)
        {
            if (rcValue.isString())
            {
                JSString *jsstring = rcValue.toString();
                const char *stringData=JS_EncodeString(__cx, jsstring);
                rval->setString( stringData);
                JS_free(__cx, (void *) stringData);
            }
            else if (rcValue.isNumber())
            {
                rval->setNumber(rcValue.toNumber());
            }
            else if (rcValue.isBoolean())
            {
                rval->setBoolean(rcValue.toBoolean());
            }
            else if (rcValue.isObject())
            {
                Object* obj = new Object(&rcValue.toObject(), true);
                rval->setObject(obj);
                obj->release();
            }
            else if (rcValue.isNull())
            {
                rval->setNull();
            }
            else
            {
                rval->setUndefined();
            }
        }

        return ok;    
    }

    // --- Register Function

    bool Object::defineFunction(const char *funcName, JSNative func, int minArgs)
    {
        JS::RootedObject object(__cx, _getJSObject());
        bool ok = JS_DefineFunction(__cx, object, funcName, func, minArgs, 0);
        return ok;
    }

    // --- Arrays

    void Object::getArrayLength( unsigned int *length) 
    {
        unsigned int len;
        JS::RootedObject object(__cx, _getJSObject());
        JS_GetArrayLength(__cx, object, &len);
        *length=len;
    }

    void Object::getArrayElement( unsigned int index, Value *data) 
    {
        JS::RootedObject object(__cx, _getJSObject());
        JS::RootedValue rcValue(__cx);
        JS_GetElement(__cx, object, index, &rcValue);

        if (data)
        {
            if (rcValue.isString())
            {
                JSString *jsstring = rcValue.toString();
                const char *stringData=JS_EncodeString(__cx, jsstring);

                data->setString( stringData);
                JS_free(__cx, (void *) stringData);
            }
            else if (rcValue.isNumber())
            {
                data->setNumber( rcValue.toNumber());
            }
            else if (rcValue.isBoolean())
            {
                data->setBoolean( rcValue.toBoolean());
            }
            else if (rcValue.isObject())
            {
                Object* obj = new Object(&rcValue.toObject(), true);
                data->setObject(obj);
                obj->release();
            }
            else if (rcValue.isNull())
            {
                data->setNull();
            }
            else
            {
                data->setUndefined();
            }
        }    
    }

    bool Object::isFunction() const
    {
        return JS_ObjectIsFunction(__cx, _getJSObject());
    }

    bool Object::isNativeFunction(JSNative func) const
    {
        JSObject* obj = _getJSObject();
        return JS_ObjectIsFunction(__cx, obj) && JS_IsNativeFunction(obj, func);
    }

    void Object::getAsUint8Array(unsigned char **ptr, unsigned int *length)
    {
        uint8_t *pt; uint32_t len;
        bool isSharedMemory = false;
        JS_GetObjectAsUint8Array(_getJSObject(), &len, &isSharedMemory, &pt);
        *ptr=pt; *length=len;
    }

    void Object::getAsUint16Array(unsigned short **ptr, unsigned int *length)
    {
        unsigned short *pt; unsigned int len;
        bool isSharedMemory = false;
        JS_GetObjectAsUint16Array(_getJSObject(), &len, &isSharedMemory, &pt);
        *ptr=pt; *length=len;
    }

    bool Object::isTypedArray() const
    {
        return JS_IsTypedArrayObject( _getJSObject());
    }

    void Object::getAsUint32Array(unsigned int **ptr, unsigned int *length)
    {
        unsigned int *pt; unsigned int len;
        bool isSharedMemory = false;
        JS_GetObjectAsUint32Array(_getJSObject(), &len, &isSharedMemory, &pt);
        *ptr=pt; *length=len;
    }

    void Object::getAsFloat32Array(float **ptr, unsigned int *length)
    {
        float *pt; unsigned int len;
        bool isSharedMemory = false;
        JS_GetObjectAsFloat32Array( _getJSObject(), &len, &isSharedMemory, &pt);
        *ptr=pt; *length=len;
    }

    bool Object::isArray() const
    {
        JS::RootedValue value(__cx, JS::ObjectValue(*_getJSObject()));
        bool isArray = false;
        return JS_IsArrayObject(__cx, value, &isArray) && isArray;
    }

    void* Object::getPrivateData()
    {
        return JS_GetPrivate(_getJSObject());
    }

    void Object::setPrivateData(void *data)
    {
        JS_SetPrivate(_getJSObject(), data);
        __nativePtrToObjectMap.emplace(data, this);
        _hasPrivateData = true;
    }

    void Object::setContext(JSContext *cx)
    {
        __cx = cx;
    }

    void Object::debug(const char *what)
    {
//        printf("Object %p %s\n", this,
//               what);
    }

    void Object::teardownRooting()
    {
        debug("teardownRooting()");
        assert(_isRooted);

        delete _root;
        _root = nullptr;
        _isRooted = false;

        if (!_hasWeakRef)
            return;

        //cjh        auto gjs_cx = static_cast<GjsContext *>(JS_GetContextPrivate(__cx));
        //        g_object_weak_unref(G_OBJECT(gjs_cx), on_context_destroy, this);
        _hasWeakRef = false;
    }

    /* Called for a rooted wrapper when the JSContext is about to be destroyed.
     * This calls the destroy-notify callback if one was passed to root(), and
     * then removes all rooting from the object. */
    void Object::invalidate()
    {
        debug("invalidate()");
        assert(_isRooted);

        /* The weak ref is already gone because the context is dead, so no need
         * to remove it. */
        _hasWeakRef = false;

        /* The object is still live across this callback. */
        if (m_notify)
        {
            JS::RootedObject rootedObj(__cx, _getJSObject());
            m_notify(rootedObj, m_data);
        }
        
        reset();
    }

    /* To access the GC thing, call get(). In many cases you can just use the
     * MaybeOwned wrapper in place of the GC thing itself due to the implicit
     * cast operator. But if you want to call methods on the GC thing, for
     * example if it's a JS::Value, you have to use get(). */
    JSObject* Object::_getJSObject() const
    {
        return _isRooted ? _root->get() : _heap.get();
    }

    /* Roots the GC thing. You must not use this if you're already using the
     * wrapper to store a non-rooted GC thing. */
    void Object::putToRoot(JSObject* thing, DestroyNotify notify/* = nullptr*/, void* data/* = nullptr*/)
    {
        debug("root()");
        assert(!_isRooted);
        assert(_heap.get() == JS::GCPolicy<JSObject*>::initial());
        _isRooted = true;
        m_notify = notify;
        m_data = data;
        _root = new JS::PersistentRootedObject(__cx, thing);

        //cjh        auto gjs_cx = static_cast<GjsContext *>(JS_GetContextPrivate(__cx));
        //        assert(GJS_IS_CONTEXT(gjs_cx));
        //        g_object_weak_ref(G_OBJECT(gjs_cx), on_context_destroy, this);
        _hasWeakRef = true;
    }

    void Object::putToHeap(JSObject* thing)
    {
        _heap = thing;
        _heap.get();
        _isRooted = false;
    }

    void Object::reset()
    {
        debug("reset()");
        if (!_isRooted) {
            _heap = JS::GCPolicy<JSObject*>::initial();
            return;
        }

        teardownRooting();
        m_notify = nullptr;
        m_data = nullptr;
    }

    void Object::switchToRooted(DestroyNotify notify/* = nullptr*/, void *data/* = nullptr*/)
    {
        debug("switch to rooted");
        assert(!_isRooted);

        /* Prevent the thing from being garbage collected while it is in neither
         * _heap nor _root */
        JSAutoRequest ar(__cx);
        JS::RootedObject thing(__cx, _heap);

        reset();
        putToRoot(thing, notify, data);
        assert(_isRooted);
    }

    void Object::switchToUnrooted()
    {
        debug("switch to unrooted");
        assert(_isRooted);
        /* Prevent the thing from being garbage collected while it is in neither
         * _heap nor _root */
        JSAutoRequest ar(__cx);
        JS::RootedObject rootedThing(__cx, *_root);
        reset();
        putToHeap(rootedThing);
        assert(!_isRooted);
    }

    /* Tracing makes no sense in the rooted case, because JS::PersistentRooted
     * already takes care of that. */
    void Object::trace(JSTracer* tracer, void* data)
    {
        debug("trace()");
        assert(!_isRooted);
        JS::TraceEdge(tracer, &_heap, "ccobj tracing");
    }

    /* If not tracing, then you must call this method during GC in order to
     * update the object's location if it was moved, or null it out if it was
     * finalized. If the object was finalized, returns true. */
    bool Object::updateAfterGC(void* data)
    {
        debug("updateAfterGC()");
        assert(!_isRooted);
        JSObject* oldPtr = _heap.unbarrieredGet();
        if (_heap.unbarrieredGet() != nullptr)
            JS_UpdateWeakPointerAfterGC(&_heap);

        JSObject* newPtr = _heap.unbarrieredGet();
        if (newPtr == nullptr)
        {
            _isRooted = false;
        }

        // FIXME: test to see ggc
        if (oldPtr != nullptr && newPtr != nullptr)
        {
            assert(oldPtr == newPtr);
        }
        return (newPtr == nullptr);
    }
    
    bool Object::isRooted() const
    {
        return _isRooted;
    }

    bool Object::isSame(Object* o) const
    {
        JSObject* thisObj = _getJSObject();
        JSObject* oThisObj = o->_getJSObject();
        if ((thisObj == nullptr || oThisObj == nullptr) && thisObj != oThisObj)
            return false;

        assert(thisObj);
        assert(oThisObj);
        JS::RootedValue v1(__cx, JS::ObjectValue(*_getJSObject()));
        JS::RootedValue v2(__cx, JS::ObjectValue(*o->_getJSObject()));
        bool same = false;
        bool ok = JS_SameValue(__cx, v1, v2, &same);
        return ok && same;
    }

    bool Object::attachChild(Object* child)
    {
        assert(child);
        JS::RootedValue valOwner(__cx, JS::ObjectValue(*_getJSObject()));
        JS::RootedValue valTarget(__cx, JS::ObjectValue(*child->_getJSObject()));

        JS::RootedObject jsbObj(__cx);
        JS::RootedObject globalObj(__cx, ScriptEngine::getInstance()->getGlobalObject()->_getJSObject());
        get_or_create_js_obj(__cx, globalObj, "jsb", &jsbObj);

        JS::AutoValueVector args(__cx);
        args.resize(2);
        args[0].set(valOwner);
        args[1].set(valTarget);

        JS::RootedValue rval(__cx);

        return JS_CallFunctionName(__cx, jsbObj, "registerNativeRef", args, &rval);
    }

    bool Object::detachChild(Object* child)
    {
        assert(child);
        JS::RootedValue valOwner(__cx, JS::ObjectValue(*_getJSObject()));
        JS::RootedValue valTarget(__cx, JS::ObjectValue(*child->_getJSObject()));

        JS::RootedObject jsbObj(__cx);
        JS::RootedObject globalObj(__cx, ScriptEngine::getInstance()->getGlobalObject()->_getJSObject());
        get_or_create_js_obj(__cx, globalObj, "jsb", &jsbObj);

        JS::AutoValueVector args(__cx);
        args.resize(2);
        args[0].set(valOwner);
        args[1].set(valTarget);

        JS::RootedValue rval(__cx);

        return JS_CallFunctionName(__cx, jsbObj, "unregisterNativeRef", args, &rval);
    }

} // namespace se {

#endif // SCRIPT_ENGINE_SM
