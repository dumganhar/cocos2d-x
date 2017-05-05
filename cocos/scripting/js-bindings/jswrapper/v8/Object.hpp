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
        Object(v8::Local<v8::Object> obj);

        virtual ~Object();

        // --- Getter/Setter
        bool get(const char *name, Value* data = NULL);

        void set(const char *name, Value& data);

        // --- Function
        bool isFunction() const;
        bool call(ValueArray *args, Object *object, Value *data = NULL);

        bool registerFunction(const char *funcName, v8::FunctionCallback func);


        // --- TypedArrays
        bool isTypedArray() const;
        void getAsFloat32Array(float **ptr, unsigned int *length);

        void getAsUint8Array(unsigned char **ptr, unsigned int *length);

        void getAsUint16Array(unsigned short **ptr, unsigned int *length);

        void getAsUint32Array(unsigned int **ptr, unsigned int *length);

        // --- Arrays
        bool isArray() const;
        void getArrayLength(unsigned int *length);

        void getArrayElement(unsigned int index, Value *data);

        // --- Private
        void* getPrivateData() const;
        // --- Utility
        void fillArgs(std::vector<v8::Local<v8::Value>> *vector, ValueArray *args);

    private:
        static void setIsolate(v8::Isolate* isolate);
        v8::UniquePersistent<v8::Object> _obj;
    };

} // namespace se {

#endif // SCRIPT_ENGINE_V8
