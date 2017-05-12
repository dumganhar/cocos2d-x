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
        void getAsUint8Array(unsigned char **ptr, unsigned int *length);
        void getAsUint16Array(unsigned short **ptr, unsigned int *length);
        void getAsUint32Array(unsigned int **ptr, unsigned int *length);
        void getAsFloat32Array(float **ptr, unsigned int *length);

        // --- Arrays
        bool isArray() const;
        void getArrayLength(unsigned int *length);
        void getArrayElement(unsigned int index, Value *data);

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

