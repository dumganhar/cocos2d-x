#include "ScriptEngine.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Object.hpp"

namespace se {



// ------------------------------------------------------- ScriptEngine

    ScriptEngine::ScriptEngine(char *arg) : m_isValid(false) {
        printf("Initializing V8\n");

        v8::V8::InitializeICU();
        v8::V8::InitializeExternalStartupData(arg);
        m_platform = v8::platform::CreateDefaultPlatform();
        v8::V8::InitializePlatform(m_platform);
        v8::V8::Initialize();

        // Create a new Isolate and make it the current one.
        m_create_params.array_buffer_allocator = &m_allocator;
        m_isolate = v8::Isolate::New(m_create_params);

        m_isolate_scope = new v8::Isolate::Scope(m_isolate);
        m_scope = new JSWrapperScope(m_isolate);

        m_context = v8::Context::New(m_isolate);
        m_context_scope = new v8::Context::Scope(m_context);

        m_isValid = true;
    }

    Object *ScriptEngine::globalObject() {
        Object *object = new Object(m_isolate, m_context->Global());
        return object;
    }

    bool ScriptEngine::execute(const char *scr, Value *data, const char *fileName) {
        v8::HandleScope handle_scope(m_isolate);

        v8::Local<v8::String> source = v8::String::NewFromUtf8(m_isolate, scr, v8::NewStringType::kNormal).ToLocalChecked();

        v8::ScriptOrigin origin(v8::String::NewFromUtf8(m_isolate, fileName ? fileName : "Unknown"));
        v8::MaybeLocal <v8::Script> maybeScript = v8::Script::Compile(m_context, source, &origin);

        bool success = false;

        if (!maybeScript.IsEmpty()) {
            v8::Local <v8::Script> script = maybeScript.ToLocalChecked();
            v8::MaybeLocal<v8::Value> maybeResult = script->Run(m_context);

            if (!maybeResult.IsEmpty()) {
                v8::Local<v8::Value> result = maybeResult.ToLocalChecked();

                if (data) {
                    v8::String::Utf8Value type(result->TypeOf(m_isolate));
                    printf("return : %s\n", *type);
                    if (result->IsNumber())
                        data->setNumber(result->ToNumber()->Value());
                    else if (result->IsString()) {
                        v8::String::Utf8Value utf8(result);
                        data->setString(*utf8);
                    } else if (result->IsBoolean())
                        data->setBoolean(result->ToBoolean()->Value());
                    else if (result->IsObject())
                        data->setObject(new Object(m_isolate, result->ToObject()));
                    else if (result->IsNull())
                        data->setNull();
                    else data->setUndefined();
                }

                success = true;
            }
        }

        return success;
    }

    ScriptEngine::~ScriptEngine() {
        delete m_context_scope;
        delete m_scope;
        delete m_isolate_scope;

        m_isolate->Dispose();

        v8::V8::Dispose();
        v8::V8::ShutdownPlatform();
        delete m_platform;
    }

} // namespace se {

#endif // SCRIPT_ENGINE_V8
