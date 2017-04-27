#include "ScriptEngine.hpp"

#include "Object.hpp"
#include "Class.hpp"
#include "Value.hpp"

#ifdef SCRIPT_ENGINE_SM

namespace se {

    void myWeakPointerZoneGroupCallback(JSContext* cx, void* data);

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

    ScriptEngine::ScriptEngine( char *arg )
    : _cx(nullptr)
    , _global(nullptr)
    , _oldCompartment(nullptr)
    , _isValid(false)
    {
        printf("Initializing SpiderMonkey \n");

        if (JS_Init())
        {
            _cx = JS_NewContext(JS::DefaultHeapMaxBytes / 8);

            if (_cx)
            {
                JS_SetGCParameter(_cx, JSGC_MAX_BYTES, 0xffffffff);
                JS_SetGCParameter(_cx, JSGC_MODE, JSGC_MODE_ZONE);
                JS_SetNativeStackQuota(_cx, 5000000);

                JS_SetGCCallback(_cx, on_garbage_collect, nullptr);

                if (!JS::InitSelfHostedCode(_cx))
                    return;

                // Waiting is allowed on the shell's main thread, for now.
                JS_SetFutexCanWait(_cx);

                JS::SetWarningReporter(_cx, reportWarning);
                JS_BeginRequest(_cx);

                JS::CompartmentOptions options;
                SetStandardCompartmentOptions(options);

                JS::ContextOptionsRef(_cx)
                            .setExtraWarnings(true)
                            .setIon(true)
                            .setBaseline(true)
                            .setAsmJS(true);

                _global = new JS::PersistentRootedObject(_cx, JS_NewGlobalObject(_cx, &globalClass, nullptr,
                                         JS::DontFireOnNewGlobalHook, options));

                if (_global != nullptr)
                {
                    _oldCompartment = JS_EnterCompartment(_cx, *_global);
                    JS_InitStandardClasses( _cx, *_global) ;

                    JS_DefineFunction(_cx, *_global, "log", __log, 0, JSPROP_PERMANENT);
                    JS_DefineFunction(_cx, *_global, "forceGC", __forceGC, 0, JSPROP_READONLY | JSPROP_PERMANENT);

                    JS_AddWeakPointerZoneGroupCallback(_cx, myWeakPointerZoneGroupCallback, nullptr);


                    _isValid=true;
                }
            }
        }
    }

    Object* ScriptEngine::globalObject()
    {
        Object *object = new Object(_cx, *_global);
        return object;
    }

    bool ScriptEngine::executeBuffer(const char *string, Value *data, const char *fileName)
    {
        return executeBuffer(string, strlen(string), data, fileName);
    }

    bool ScriptEngine::executeBuffer(const char *script, size_t length, Value *data, const char *fileName )
    {
        JS::CompileOptions options( _cx );
        options.setFile( fileName )
               .setVersion(JSVERSION_LATEST);

        JS::RootedValue rcValue( _cx );
        bool ok = JS::Evaluate( _cx, options, script, strlen(script), &rcValue );

        if (ok && data)
        {
            if (rcValue.isNullOrUndefined())
            {
                printf("is null\n");
            }
            else if (rcValue.isString() )
            {
                JSString *jsstring = rcValue.toString();
                const char *stringData=JS_EncodeString( _cx, jsstring );

                data->setString( stringData );
                JS_free( _cx, (void *) stringData );
            }
            else if (rcValue.isNumber() )
            {
                data->setNumber( rcValue.toNumber() );
            }
            else if (rcValue.isBoolean() )
            {
                data->setBoolean( rcValue.toBoolean() );
            }
            else if (rcValue.isObject() )
            {
                Object *obj=new Object( _cx, &rcValue.toObject() );
                data->setObject( obj );
            }
            else if (rcValue.isNull() )
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

    bool ScriptEngine::executeFile(const std::string& filePath, Value* rval/* = nullptr*/)
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
            ret = executeBuffer(buffer, fileSize, rval, filePath.c_str());
            free(buffer);
            fclose(fp);
        }

        return ret;
    }

    // --- Classes

    Class* ScriptEngine::createClass(const std::string& className, Object* obj, Object* parentProto, JSNative constructor)
    {
        Class* cls = new Class();
        if (cls != nullptr && !cls->init(_cx, className, obj, parentProto, constructor))
        {
            delete cls;
            cls = nullptr;
        }
        return cls;
    }

    ScriptEngine::~ScriptEngine()
    {
        if (_oldCompartment)
            JS_LeaveCompartment(_cx, _oldCompartment);
        JS_EndRequest(_cx);
        JS_DestroyContext( _cx );
        JS_ShutDown();
    }

} // namespace se {

#endif // SCRIPT_ENGINE_SM
