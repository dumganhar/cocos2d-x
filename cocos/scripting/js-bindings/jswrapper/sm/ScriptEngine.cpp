#include "ScriptEngine.hpp"

#include "Object.hpp"
#include "Class.hpp"
#include "Utils.hpp"

#ifdef SCRIPT_ENGINE_SM

SE_DECLARE_FUNC(Node_onEnter);
SE_DECLARE_FUNC(Node_onExit);
SE_DECLARE_FUNC(Node_onEnterTransitionDidFinish);
SE_DECLARE_FUNC(Node_onExitTransitionDidStart);
SE_DECLARE_FUNC(Node_cleanup);

namespace se {

    Class* __jsb_CCPrivateData_class = nullptr;

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
            JSString *string = JS::ToString(cx, args[0]);
            if (string) {
                JS::RootedString jsstr(cx, string);
                char* buffer = JS_EncodeStringToUTF8(cx, jsstr);

                printf("JS: %s\n", buffer);

                JS_free(cx, (void*)buffer);
            }
        }
        args.rval().setUndefined();
        return true;
    }

    // Private data class
    static bool privateDataContructor(JSContext* cx, uint32_t argc, JS::Value* vp)
    {
        return true;
    }

    static void privateDataFinalize(JSFreeOp* fop, JSObject* obj)
    {
        internal::PrivateData* p = (internal::PrivateData*)JS_GetPrivate(obj);
        JS_SetPrivate(obj, p->data);
        if (p->finalizeCb != nullptr)
            p->finalizeCb(fop, obj);
        free(p);
    }

    // ------------------------------------------------------- ScriptEngine

    static void
    on_garbage_collect(JSContext* cx, JSGCStatus status, void* data)
    {
        /* We finalize any pending toggle refs before doing any garbage collection,
         * so that we can collect the JS wrapper objects, and in order to minimize
         * the chances of objects having a pending toggle up queued when they are
         * garbage collected. */
        if (status == JSGC_BEGIN)
        {
            printf("on_garbage_collect: begin, Native -> JS map count: %d\n", (int)__nativePtrToObjectMap.size());
        }
        else if (status == JSGC_END)
        {
            printf("on_garbage_collect: end, Native -> JS map count: %d\n", (int)__nativePtrToObjectMap.size());
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
                    iter->second->release();
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

        _cx = JS_NewContext(JS::DefaultHeapMaxBytes);

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

        _globalObj = Object::_createJSObject(nullptr, globalObj, true);
        JS::RootedObject rootedGlobalObj(_cx, _globalObj->_getJSObject());

        _oldCompartment = JS_EnterCompartment(_cx, rootedGlobalObj);
        JS_InitStandardClasses(_cx, rootedGlobalObj) ;

        JS_DefineFunction(_cx, rootedGlobalObj, "log", __log, 0, JSPROP_PERMANENT);
        JS_DefineFunction(_cx, rootedGlobalObj, "forceGC", __forceGC, 0, JSPROP_READONLY | JSPROP_PERMANENT);

//        JS_AddExtraGCRootsTracer(_cx, ScriptEngine::myExtraGCRootsTracer, nullptr);
//        JS_AddWeakPointerZoneGroupCallback(_cx, ScriptEngine::myWeakPointerZoneGroupCallback, nullptr);
        JS_AddWeakPointerCompartmentCallback(_cx, ScriptEngine::myWeakPointerCompartmentCallback, nullptr);

        JS_FireOnNewGlobalObject(_cx, rootedGlobalObj);

        __jsb_CCPrivateData_class = Class::create("__CCPrivateData", _globalObj, nullptr, privateDataContructor);
        __jsb_CCPrivateData_class->defineFinalizedFunction(privateDataFinalize);
        __jsb_CCPrivateData_class->install();

        _isValid = true;

        return true;
    }

    ScriptEngine::~ScriptEngine()
    {
        cleanup();
    }

    void ScriptEngine::cleanup()
    {
        Class::cleanup();
//        JS_RemoveExtraGCRootsTracer(_cx, ScriptEngine::myExtraGCRootsTracer, nullptr);
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
            clearException();
        }
        assert(ok);

        if (ok && data && !rcValue.isNullOrUndefined())
        {
            internal::jsToSeValue(_cx, rcValue, data);
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

        clearException();
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

        clearException();
        iterOwner->second->detachChild(iterTarget->second);
    }

    bool ScriptEngine::_onReceiveNodeEvent(void* node, NodeEventType type)
    {
//        printf("ScriptEngine::_onReceiveNodeEvent, node: %p, type: %d\n", node, (int) type);

        auto iter = __nativePtrToObjectMap.find(node);
        if (iter  == __nativePtrToObjectMap.end())
            return false;

        clearException();

        JS::RootedValue retval(_cx);
        Object* target = iter->second;
        const char* funcName = nullptr;
        JSNative func = nullptr;
        if (type == NodeEventType::ENTER)
        {
            funcName = "onEnter";
            func = Node_onEnter;
        }
        else if (type == NodeEventType::EXIT)
        {
            funcName = "onExit";
            func = Node_onExit;
        }
        else if (type == NodeEventType::ENTER_TRANSITION_DID_FINISH)
        {
            funcName = "onEnterTransitionDidFinish";
            func = Node_onEnterTransitionDidFinish;
        }
        else if (type == NodeEventType::EXIT_TRANSITION_DID_START)
        {
            funcName = "onExitTransitionDidStart";
            func = Node_onExitTransitionDidStart;
        }
        else if (type == NodeEventType::CLEANUP)
        {
            funcName = "cleanup";
            func = Node_cleanup;
        }
        else
        {
            assert(false);
        }

        bool ret = false;
        Value funcVal;
        bool ok = target->getProperty(funcName, &funcVal);
        if (ok && !funcVal.toObject()->_isNativeFunction(func))
        {
            ret = funcVal.toObject()->call(EmptyValueArray, target);
        }

        return ret;
    }

    void ScriptEngine::clearException()
    {
        if (JS_IsExceptionPending(_cx))
        {
            JS::RootedValue exceptionValue(_cx);
            JS_GetPendingException(_cx, &exceptionValue);
            JS_ClearPendingException(_cx);
            assert(exceptionValue.isObject());
            JS::RootedObject exceptionObj(_cx, exceptionValue.toObjectOrNull());
            JSErrorReport* report = JS_ErrorFromException(_cx, exceptionObj);
            const char* fileName = report->filename != nullptr ? report->filename : "(no filename)";
            printf("ERROR: %s, file: %s, lineno: %u\n", report->message().c_str(), fileName, report->lineno);
            JS_ClearPendingException(_cx);
        }
    }

} // namespace se {

#endif // SCRIPT_ENGINE_SM
