#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_SM

#include "Base.h"
#include "../Value.hpp"
#include "../Ref.hpp"

namespace se {

    class Class;

    class Object : public Ref
    {
    private:
        Object();
        bool init(Class* cls, JSObject* obj, bool rooted);
    public:
        virtual ~Object();

        static Object* createPlainObject(bool rooted);
        static Object* createObject(const char* clsName, bool rooted);
        static Object* createObjectWithClass(Class* cls, bool rooted);
        static Object* createArrayObject(size_t length, bool rooted);
        static Object* createArrayBufferObject(void* data, size_t byteLength, bool rooted);
        static Object* createJSONObject(const std::string& jsonStr, bool rooted);
        static Object* getObjectWithPtr(void* ptr);
        static Object* getOrCreateObjectWithPtr(void* ptr, const char* clsName, bool rooted);

        static Object* _createJSObject(Class* cls, JSObject* obj, bool rooted);

        void _setFinalizeCallback(JSFinalizeOp finalizeCb);

        // --- Getter/Setter
        bool getProperty(const char* name, Value* data);
        void setProperty(const char* name, const Value& v);

        JSObject* _getJSObject() const;

        // --- Function
        bool isFunction() const;
        bool _isNativeFunction(JSNative func) const;
        bool call(const ValueArray& args, Object* thisObject, Value* rval = nullptr);

        bool defineFunction(const char *funcName, JSNative func, int minArgs = 0);

        // --- TypedArrays
        bool isTypedArray() const;
        bool getTypedArrayData(uint8_t** ptr, size_t* length) const;

//        bool getAsUint8Array(uint8_t** ptr, size_t* length) const;
//        bool getAsUint16Array(uint16_t** ptr, size_t* length) const;
//        bool getAsUint32Array(uint32_t** ptr, size_t* length) const;
//        bool getAsFloat32Array(float** ptr, size_t* length) const;

        // --- Arrays
        bool isArray() const;
        bool getArrayLength(uint32_t* length) const;
        bool getArrayElement(uint32_t index, Value* data) const;
        bool setArrayElement(uint32_t index, const Value& data);

        // --- ArrayBuffer
        bool isArrayBuffer() const;
        bool getArrayBufferData(uint8_t** ptr, size_t* length) const;

        bool getAllKeys(std::vector<std::string>* allKeys);

        // --- Private
        void setPrivateData(void* data);
        void* getPrivateData();

        typedef void (*DestroyNotify)(JS::HandleObject thing, void *data);


        void switchToRooted(DestroyNotify notify = nullptr, void *data = nullptr);
        void switchToUnrooted();
        bool isRooted() const;

        bool isSame(Object* o) const;
        bool attachChild(Object* child);
        bool detachChild(Object* child);

    private:
        static void setContext(JSContext* cx);

        void putToRoot(JSObject* thing, DestroyNotify notify = nullptr, void* data = nullptr);
        void putToHeap(JSObject* thing);
        void debug(const char *what);
        void teardownRooting();
        void invalidate();
        void reset();

        void trace(JSTracer* tracer, void* data);
        bool updateAfterGC(void* data);

        bool _isRooted;  /* wrapper is in rooted mode */
        bool _hasWeakRef;  /* we have a weak reference to the GjsContext */

        JS::Heap<JSObject*> _heap;  /* should be untouched if in rooted mode */
        JS::PersistentRootedObject* _root;  /* should be null if not in rooted mode */

        DestroyNotify m_notify;
        void* m_data;
        bool _hasPrivateData;

        Class* _cls;
        JSFinalizeOp _finalizeCb;

        friend class ScriptEngine;
    };


    extern std::unordered_map<void* /*native*/, Object* /*jsobj*/> __nativePtrToObjectMap;

} // namespace se {

#endif // SCRIPT_ENGINE_SM

