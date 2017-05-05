#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Base.h"
#include "../Value.hpp"

namespace se {

    class Value;

    class ArrayBufferAllocator : public v8::ArrayBuffer::Allocator {
    public:
        virtual void *Allocate(size_t length) {
            void *data = AllocateUninitialized(length);
            return data == NULL ? data : memset(data, 0, length);
        }

        virtual void *AllocateUninitialized(size_t length) {
            return malloc(length);
        }

        virtual void Free(void *data, size_t) {
            free(data);
        }
    };

    class JSWrapperScope {

    public:

        JSWrapperScope(v8::Isolate *isolate) : m_handle_scope(isolate) {
        }

    private:

        v8::HandleScope m_handle_scope;
    };

    class ScriptEngine {

    public:

        ScriptEngine(char *arg);

        ~ScriptEngine();

    public:

        // --- Returns the global object
        Object *globalObject();

        // --- Execute a script
        bool execute(const char *string, Value *data = NULL, const char *fileName = NULL);

        // --- Run GC
        void gc() {
            while (!m_isolate->IdleNotification(100)) {};
        }

        bool isValid() {
            return m_isValid;
        }

    private:

        v8::Platform *m_platform;
        v8::Isolate *m_isolate;

        v8::Isolate::Scope *m_isolate_scope;

        v8::Local<v8::Context> m_context;
        v8::Context::Scope *m_context_scope;

        JSWrapperScope *m_scope;

        ArrayBufferAllocator m_allocator;
        v8::Isolate::CreateParams m_create_params;

        bool m_isValid;
    };

} // namespace se {

#endif // SCRIPT_ENGINE_V8
