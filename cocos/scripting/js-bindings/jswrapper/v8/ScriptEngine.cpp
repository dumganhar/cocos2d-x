#include "ScriptEngine.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Object.hpp"
#include "Class.hpp"

#define RETRUN_VAL_IF_FAIL(cond, val) \
    if (!(cond)) return val

namespace se {
    namespace {
        ScriptEngine* __instance = nullptr;

        void __log(const v8::FunctionCallbackInfo<v8::Value>& info)
        {
            if (info[0]->IsString())
            {
                v8::String::Utf8Value utf8(info[0]);
                printf("JS: %s\n", *utf8);
            }
        }

        void __forceGC(const v8::FunctionCallbackInfo<v8::Value>& info)
        {
            ScriptEngine::getInstance()->gc();
        }
    }

    ScriptEngine *ScriptEngine::getInstance()
    {
        if (__instance == nullptr)
        {
            __instance = new ScriptEngine();
            if (!__instance->init())
            {
                delete __instance;
                __instance = nullptr;
            }
        }

        return __instance;
    }

    void ScriptEngine::destroyInstance()
    {
        delete __instance;
        __instance = nullptr;
    }

    ScriptEngine::ScriptEngine()
    : _platform(nullptr)
    , _isolate(nullptr)
    , _globalObj(nullptr)
    , _isValid(false)
    {

    }

    ScriptEngine::~ScriptEngine()
    {
        cleanup();
    }

    bool ScriptEngine::init()
    {
        printf("Initializing V8\n");

//        RETRUN_VAL_IF_FAIL(v8::V8::InitializeICUDefaultLocation(nullptr, "/Users/james/Project/v8/out.gn/x64.debug/icudtl.dat"), false);
//        v8::V8::InitializeExternalStartupData("/Users/james/Project/v8/out.gn/x64.debug/natives_blob.bin", "/Users/james/Project/v8/out.gn/x64.debug/snapshot_blob.bin"); //TODO
        _platform = v8::platform::CreateDefaultPlatform();
        v8::V8::InitializePlatform(_platform);
        RETRUN_VAL_IF_FAIL(v8::V8::Initialize(), false);

        // Create a new Isolate and make it the current one.
        _createParams.array_buffer_allocator = &_allocator;
        _isolate = v8::Isolate::New(_createParams);
        v8::HandleScope hs(_isolate);
        _isolate->Enter();

        _context.Reset(_isolate, v8::Context::New(_isolate));
        _context.Get(_isolate)->Enter();

        Class::setIsolate(_isolate);
        Object::setIsolate(_isolate);

        _globalObj = Object::_createJSObject(_context.Get(_isolate)->Global(), true);

        _globalObj->defineFunction("log", __log);
        _globalObj->defineFunction("forceGC", __forceGC);

        _isValid = true;

        return _isValid;
    }

    void ScriptEngine::cleanup()
    {
        SAFE_RELEASE(_globalObj);

        Class::cleanup();
        _context.Get(_isolate)->Exit();
        _context.Reset();
        _isolate->Exit();

        _isolate->Dispose();

        v8::V8::Dispose();
        v8::V8::ShutdownPlatform();
        delete _platform;
    }

    Object* ScriptEngine::getGlobalObject() const
    {
        return _globalObj;
    }

    void ScriptEngine::gc()
    {
        printf("GC begin ...\n");
        const double kLongIdlePauseInSeconds = 1.0;
        _isolate->ContextDisposedNotification();
        _isolate->IdleNotificationDeadline(_platform->MonotonicallyIncreasingTime() + kLongIdlePauseInSeconds);
        // By sending a low memory notifications, we will try hard to collect all
        // garbage and will therefore also invoke all weak callbacks of actually
        // unreachable persistent handles.
        _isolate->LowMemoryNotification();
        printf("GC end ...\n");
    }

    bool ScriptEngine::isValid() const
    {
        return _isValid;
    }


    bool ScriptEngine::executeScriptBuffer(const char* string, Value *data, const char *fileName)
    {
        return executeScriptBuffer(string, strlen(string), data, fileName);
    }

    bool ScriptEngine::executeScriptBuffer(const char* script, size_t length, Value *data, const char *fileName)
    {
        std::string scriptStr(script, length);

        v8::Local<v8::String> source = v8::String::NewFromUtf8(_isolate, scriptStr.c_str(), v8::NewStringType::kNormal).ToLocalChecked();

        v8::ScriptOrigin origin(v8::String::NewFromUtf8(_isolate, fileName ? fileName : "Unknown"));
        v8::MaybeLocal<v8::Script> maybeScript = v8::Script::Compile(_context.Get(_isolate), source, &origin);

        bool success = false;

        if (!maybeScript.IsEmpty()) {
            v8::Local <v8::Script> v8Script = maybeScript.ToLocalChecked();
            v8::MaybeLocal<v8::Value> maybeResult = v8Script->Run(_context.Get(_isolate));

            if (!maybeResult.IsEmpty()) {
                v8::Local<v8::Value> result = maybeResult.ToLocalChecked();

                if (data) {
                    v8::String::Utf8Value type(result->TypeOf(_isolate));
                    printf("return : %s\n", *type);
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

                success = true;
            }
        }

        return success;
    }

    bool ScriptEngine::executeScriptFile(const std::string& filePath, Value* rval/* = nullptr*/)
    {
        bool ret = false;
        FILE* fp = fopen(filePath.c_str(), "rb");
        if (fp != nullptr)
        {
            fseek(fp, 0, SEEK_END);
            size_t fileSize = (size_t)ftell(fp);
            fseek(fp, 0, SEEK_SET);
            char* buffer = (char*) malloc(fileSize);
            fread(buffer, fileSize, 1, fp);
            ret = executeScriptBuffer(buffer, fileSize, rval, filePath.c_str());
            free(buffer);
            fclose(fp);
        }

        return ret;
    }

    void ScriptEngine::_retainScriptObject(void* owner, void* target)
    {
        auto iterOwner = __nativePtrToObjectMap.find(owner);
        if (iterOwner == __nativePtrToObjectMap.end())
        {
            return;
        }

        auto iterTarget = __nativePtrToObjectMap.find(target);
        if (iterTarget == __nativePtrToObjectMap.end())
        {
            return;
        }

        iterOwner->second->attachChild(iterTarget->second);
    }

    void ScriptEngine::_releaseScriptObject(void* owner, void* target)
    {
        auto iterOwner = __nativePtrToObjectMap.find(owner);
        if (iterOwner == __nativePtrToObjectMap.end())
        {
            return;
        }

        auto iterTarget = __nativePtrToObjectMap.find(target);
        if (iterTarget == __nativePtrToObjectMap.end())
        {
            return;
        }

        iterOwner->second->detachChild(iterTarget->second);
    }

    void ScriptEngine::_onReceiveNodeEvent(void* node, NodeEventType type)
    {
        //        printf("ScriptEngine::_onReceiveNodeEvent, node: %p, type: %d\n", node, (int) type);

        auto iter = __nativePtrToObjectMap.find(node);
        if (iter  == __nativePtrToObjectMap.end())
            return;

        assert(false);
        //FIXME:
//        JS::RootedValue retval(_cx);
//        Object* target = iter->second;
//        const char* funcName = nullptr;
//        JSNative func = nullptr;
//        if (type == NodeEventType::ENTER)
//        {
//            funcName = "onEnter";
//            func = Node_onEnter;
//        }
//        else if (type == NodeEventType::EXIT)
//        {
//            funcName = "onExit";
//            func = Node_onExit;
//        }
//        else if (type == NodeEventType::ENTER_TRANSITION_DID_FINISH)
//        {
//            funcName = "onEnterTransitionDidFinish";
//            func = Node_onEnterTransitionDidFinish;
//        }
//        else if (type == NodeEventType::EXIT_TRANSITION_DID_START)
//        {
//            funcName = "onExitTransitionDidStart";
//            func = Node_onExitTransitionDidStart;
//        }
//        else if (type == NodeEventType::CLEANUP)
//        {
//            funcName = "cleanup";
//            func = Node_cleanup;
//        }
//        else
//        {
//            assert(false);
//        }
//        
//        Value funcVal;
//        bool ok = target->getProperty(funcName, &funcVal);
//        if (ok && !funcVal.toObject()->isNativeFunction(func))
//        {
//            funcVal.toObject()->call(EmptyValueArray, target);
//        }
    }

} // namespace se {

#endif // SCRIPT_ENGINE_V8
