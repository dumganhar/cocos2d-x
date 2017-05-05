#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Base.h"
#include "../Ref.hpp"
#include "../Value.hpp"

namespace se {

    class Class;

    class Object : public Ref
    {
    public:
        Object(v8::Isolate* isolate, v8::Local<v8::Object> obj);

        Object(Object *);

        ~Object();

        // --- Getter/Setter
        bool get(const char *name, Value* data = NULL);

        void set(const char *name, Value& data);

        // --- Function
        bool isFunction() {
            return m_obj.Get(m_isolate)->IsCallable();
        }

        bool call(ValueArray *args, Object *object, Value *data = NULL);

        bool registerFunction(const char *funcName, v8::FunctionCallback func);

        // --- Classes
        Class *createClass(const char *className, v8::FunctionCallback ctor);

        // ---
        Object *copy();

        // --- TypedArrays
        bool isTypedArray() {
            return m_obj.Get(m_isolate)->IsTypedArray();
        }

        void getAsFloat32Array(float **ptr, unsigned int *length);

        void getAsUint8Array(unsigned char **ptr, unsigned int *length);

        void getAsUint16Array(unsigned short **ptr, unsigned int *length);

        void getAsUint32Array(unsigned int **ptr, unsigned int *length);

        // --- Arrays
        bool isArray() {
            return m_obj.Get(m_isolate)->IsArray();
        }

        void getArrayLength(unsigned int *length);

        void getArrayElement(unsigned int index, Value *data);

        // --- Private
        void *getPrivate() {
            return v8::Local<v8::External>::Cast(m_obj.Get(m_isolate)->GetInternalField(0))->Value();
        }

        // --- Utility
        void fillArgs(std::vector<v8::Local<v8::Value>> *vector, ValueArray *args);

        v8::Isolate *m_isolate;
        v8::UniquePersistent<v8::Object> m_obj;
    };

} // namespace se {

#endif // SCRIPT_ENGINE_V8
