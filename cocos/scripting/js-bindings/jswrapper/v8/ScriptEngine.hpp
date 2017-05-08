#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Base.h"
#include "../Value.hpp"

namespace se {

    class Object;
    class Class;
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

    class AutoHandleScope
    {
    public:
        AutoHandleScope()
        : _handleScope(v8::Isolate::GetCurrent())
        {
        }
        ~AutoHandleScope()
        {
        }
    private:
        v8::HandleScope _handleScope;
    };

    class ScriptEngine
    {
    private:
        ScriptEngine();
        ~ScriptEngine();
    public:

        static ScriptEngine* getInstance();
        static void destroyInstance();

        bool init();

        // --- Returns the global object
        Object* getGlobalObject() const;

        // --- Execute
        bool executeScriptBuffer(const char *string, Value *data = nullptr, const char *fileName = nullptr);
        bool executeScriptBuffer(const char *string, size_t length, Value *data = nullptr, const char *fileName = nullptr);
        bool executeScriptFile(const std::string &filePath, Value *rval = nullptr);

        // --- Run GC
        void gc();

        bool isValid() const;

        void _retainScriptObject(void* owner, void* target);
        void _releaseScriptObject(void* owner, void* target);

        enum class NodeEventType
        {
            ENTER,
            EXIT,
            ENTER_TRANSITION_DID_FINISH,
            EXIT_TRANSITION_DID_START,
            CLEANUP
        };
        void _onReceiveNodeEvent(void* node, NodeEventType type);

    private:

        v8::Platform* _platform;
        v8::Isolate* _isolate;

        v8::Persistent<v8::Context> _context;

        v8::HandleScope* _handleScope;

        ArrayBufferAllocator _allocator;
        v8::Isolate::CreateParams _createParams;
        Object* _globalObj;

        bool _isValid;
    };

} // namespace se {

#endif // SCRIPT_ENGINE_V8
