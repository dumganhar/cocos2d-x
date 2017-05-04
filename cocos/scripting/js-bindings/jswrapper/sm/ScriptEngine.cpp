#include "ScriptEngine.hpp"

#include "Object.hpp"
#include "Class.hpp"

#ifdef SCRIPT_ENGINE_SM

namespace se {

    namespace {
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
    }

    // --- SM Global Class

    static const JSClassOps sandbox_classOps = {
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr,
        nullptr, nullptr,
        nullptr, nullptr, nullptr,
        JS_GlobalObjectTraceHook
    };

    static JSClass globalClass = {
        "global",
        JSCLASS_GLOBAL_FLAGS,
        &sandbox_classOps
    };

    // --- SM Error Reporter

    static void reportWarning(JSContext* cx, JSErrorReport* report) {
        MOZ_RELEASE_ASSERT(report);
        MOZ_RELEASE_ASSERT(JSREPORT_IS_WARNING(report->flags));

        fprintf(stderr, "%s:%u:%s\n",
                report->filename ? report->filename : "<no filename>",
                (unsigned int) report->lineno,
                report->message().c_str());
    }


    static void
    SetStandardCompartmentOptions(JS::CompartmentOptions& options)
    {
        bool enableSharedMemory = true;
        options.behaviors().setVersion(JSVERSION_LATEST);
        options.creationOptions().setSharedMemoryAndAtomicsEnabled(enableSharedMemory);
    }

    static bool __forceGC(JSContext *cx, uint32_t argc, JS::Value* vp)
    {
        JS_GC(cx);
        return true;
    }

    static bool __log(JSContext *cx, uint32_t argc, JS::Value* vp)
    {
        JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
        if (argc > 0) {
            JSString *string = args[0].toString();
            if (string) {
                JS::RootedString jsstr(cx, string);
                char* buffer = JS_EncodeStringToUTF8(cx, jsstr);

                printf("%s\n", buffer);

                JS_free(cx, (void*)buffer);
            }
        }
        args.rval().setUndefined();
        return true;
    }

    // ------------------------------------------------------- JSWrapper

    static void
    on_garbage_collect(JSContext* cx, JSGCStatus status, void* data)
    {
        /* We finalize any pending toggle refs before doing any garbage collection,
         * so that we can collect the JS wrapper objects, and in order to minimize
         * the chances of objects having a pending toggle up queued when they are
         * garbage collected. */
        if (status == JSGC_BEGIN)
        {
            printf("on_garbage_collect: begin\n");
        }
        else if (status == JSGC_END)
        {
            printf("on_garbage_collect: end\n");
        }
    }

    namespace {
        ScriptEngine* __instance = nullptr;
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
            : _cx(nullptr)
            , _globalObj(nullptr)
            , _oldCompartment(nullptr)
            , _isValid(false)
    {
    }

    void ScriptEngine::myWeakPointerCompartmentCallback(JSContext* cx, JSCompartment* comp, void* data)
    {
        myWeakPointerZoneGroupCallback(cx, data);
    }

    void ScriptEngine::myWeakPointerZoneGroupCallback(JSContext* cx, void* data)
    {
        bool isIterUpdated = false;
        auto iter = __nativePtrToObjectMap.begin();
        for (; iter != __nativePtrToObjectMap.end();)
        {
            isIterUpdated = false;
            if (!iter->second->isRooted())
            {
                if (iter->second->updateAfterGC(data))
                {
                    iter = __nativePtrToObjectMap.erase(iter);
                    isIterUpdated = true;
                }
            }

            if (!isIterUpdated)
                ++iter;
        }
    }

    void ScriptEngine::myExtraGCRootsTracer(JSTracer* trc, void* data)
    {
//        for (const auto& e : __nativePtrToObjectMap)
//        {
//            if (!e.second->isRooted())
//                e.second->trace(trc, data);
//        }
    }

    bool ScriptEngine::init()
    {
        printf("Initializing SpiderMonkey \n");

        if (!JS_Init())
            return false;

        _cx = JS_NewContext(JS::DefaultHeapMaxBytes / 8);

        if (nullptr == _cx)
            return false;

        Class::setContext(_cx);
        Object::setContext(_cx);

        JS_SetGCParameter(_cx, JSGC_MAX_BYTES, 0xffffffff);
        JS_SetGCParameter(_cx, JSGC_MODE, JSGC_MODE_INCREMENTAL);
        JS_SetNativeStackQuota(_cx, 5000000);

        JS_SetGCCallback(_cx, on_garbage_collect, nullptr);

        if (!JS::InitSelfHostedCode(_cx))
            return false;


        // Waiting is allowed on the shell's main thread, for now.
        JS_SetFutexCanWait(_cx);

        JS::SetWarningReporter(_cx, reportWarning);

#if defined(JS_GC_ZEAL) && defined(DEBUG)
        JS_SetGCZeal(_cx, 2, JS_DEFAULT_ZEAL_FREQ);
#endif

        JS_SetDefaultLocale(_cx, "UTF-8");

        JS_BeginRequest(_cx);

        JS::CompartmentOptions options;
        SetStandardCompartmentOptions(options);

#ifndef DEBUG
        JS::ContextOptionsRef(_cx)
                    .setExtraWarnings(true)
                    .setIon(true)
                    .setBaseline(true)
                    .setAsmJS(true);
#endif

        JSObject* globalObj = JS_NewGlobalObject(_cx, &globalClass, nullptr, JS::DontFireOnNewGlobalHook, options);

        if (nullptr == globalObj)
            return false;

        _globalObj = new Object(globalObj, true);
        JS::RootedObject rootedGlobalObj(_cx, _globalObj->_getJSObject());

        _oldCompartment = JS_EnterCompartment(_cx, rootedGlobalObj);
        JS_InitStandardClasses(_cx, rootedGlobalObj) ;

        JS_DefineFunction(_cx, rootedGlobalObj, "log", __log, 0, JSPROP_PERMANENT);
        JS_DefineFunction(_cx, rootedGlobalObj, "forceGC", __forceGC, 0, JSPROP_READONLY | JSPROP_PERMANENT);

        JS_AddExtraGCRootsTracer(_cx, ScriptEngine::myExtraGCRootsTracer, nullptr);
//        JS_AddWeakPointerZoneGroupCallback(_cx, ScriptEngine::myWeakPointerZoneGroupCallback, nullptr);
        JS_AddWeakPointerCompartmentCallback(_cx, ScriptEngine::myWeakPointerCompartmentCallback, nullptr);

        JS_FireOnNewGlobalObject(_cx, rootedGlobalObj);

        _isValid = true;

        return true;
    }

    ScriptEngine::~ScriptEngine()
    {
        cleanup();
    }

    void ScriptEngine::cleanup()
    {
        JS_RemoveExtraGCRootsTracer(_cx, ScriptEngine::myExtraGCRootsTracer, nullptr);
//        JS_RemoveWeakPointerZoneGroupCallback(_cx, ScriptEngine::myWeakPointerZoneGroupCallback);
        JS_RemoveWeakPointerCompartmentCallback(_cx, ScriptEngine::myWeakPointerCompartmentCallback);

        if (_oldCompartment)
            JS_LeaveCompartment(_cx, _oldCompartment);

        SAFE_RELEASE(_globalObj);

        JS_EndRequest(_cx);
        JS_DestroyContext(_cx);
        JS_ShutDown();
    }

    Object* ScriptEngine::getGlobalObject()
    {
        return _globalObj;
    }

    bool ScriptEngine::executeScriptBuffer(const char *string, Value *data, const char *fileName)
    {
        return executeScriptBuffer(string, strlen(string), data, fileName);
    }

    bool ScriptEngine::executeScriptBuffer(const char *script, size_t length, Value *data, const char *fileName)
    {
        JS::CompileOptions options( _cx );
        options.setFile( fileName )
               .setVersion(JSVERSION_LATEST);

        JS::RootedValue rcValue( _cx );
        bool ok = JS::Evaluate( _cx, options, script, length, &rcValue);
        if (!ok)
        {
            if (JS_IsExceptionPending(_cx))
            {
                JS::RootedValue exceptionValue(_cx);
                JS_GetPendingException(_cx, &exceptionValue);
                JS_ClearPendingException(_cx);
                assert(exceptionValue.isObject());
                JS::RootedObject exceptionObj(_cx, exceptionValue.toObjectOrNull());
                JSErrorReport* report = JS_ErrorFromException(_cx, exceptionObj);
                printf("ERROR: %s, file: %s, lineno: %u\n", report->message().c_str(), report->filename, report->lineno);
                JS_ClearPendingException(_cx);
            }
        }
        assert(ok);

        if (ok && data)
        {
            if (rcValue.isNullOrUndefined())
            {
                printf("JS::Evaluate returns null or undefined!\n");
            }
            else if (rcValue.isString())
            {
                JSString *jsstring = rcValue.toString();
                const char *stringData = JS_EncodeString( _cx, jsstring );

                data->setString( stringData );
                JS_free(_cx, (void *) stringData );
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
                Object *obj = new Object(&rcValue.toObject(), true);
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

    bool ScriptEngine::executeScriptFile(const std::string &filePath, Value *rval/* = nullptr*/)
    {
        bool ret = false;
        FILE* fp = fopen(filePath.c_str(), "rb");
        if (fp != nullptr)
        {
            fseek(fp, 0, SEEK_END);
            long fileSize = ftell(fp);
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

        JS::RootedValue valOwner(_cx, JS::ObjectValue(*iterOwner->second->_getJSObject()));
        JS::RootedValue valTarget(_cx, JS::ObjectValue(*iterTarget->second->_getJSObject()));

        JS::RootedObject jsbObj(_cx);
        JS::RootedObject globalObj(_cx, _globalObj->_getJSObject());
        get_or_create_js_obj(_cx, globalObj, "jsb", &jsbObj);

        JS::AutoValueVector args(_cx);
        args.resize(2);
        args[0].set(valOwner);
        args[1].set(valTarget);

        JS::RootedValue rval(_cx);

        JS_CallFunctionName(_cx, jsbObj, "registerNativeRef", args, &rval);
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

        JS::RootedValue valOwner(_cx, JS::ObjectValue(*iterOwner->second->_getJSObject()));
        JS::RootedValue valTarget(_cx, JS::ObjectValue(*iterTarget->second->_getJSObject()));

        JS::RootedObject jsbObj(_cx);
        JS::RootedObject globalObj(_cx, _globalObj->_getJSObject());
        get_or_create_js_obj(_cx, globalObj, "jsb", &jsbObj);

        JS::AutoValueVector args(_cx);
        args.resize(2);
        args[0].set(valOwner);
        args[1].set(valTarget);

        JS::RootedValue rval(_cx);

        JS_CallFunctionName(_cx, jsbObj, "unregisterNativeRef", args, &rval);
    }

} // namespace se {

#endif // SCRIPT_ENGINE_SM
