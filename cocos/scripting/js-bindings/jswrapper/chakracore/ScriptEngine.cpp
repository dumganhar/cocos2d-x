#include "ScriptEngine.hpp"

#include "Object.hpp"
#include "Class.hpp"
#include "Utils.hpp"

#ifdef SCRIPT_ENGINE_CHAKRACORE

#define FAIL_CHECK(cmd)                     \
    do                                      \
    {                                       \
        JsErrorCode _errCode = cmd;          \
        if (_errCode != JsNoError)           \
        {                                   \
            printf("Error %d at '%s'\n",    \
                _errCode, #cmd);             \
            return false;                   \
        }                                   \
    } while(0)

namespace se {

    namespace {
        ScriptEngine* __instance = nullptr;

        JsValueRef __forceGC(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState)
        {
            printf("GC begin ..., (Native -> JS map) count: %d\n", (int)__nativePtrToObjectMap.size());
            ScriptEngine::getInstance()->gc();
            printf("GC end ..., (Native -> JS map) count: %d\n", (int)__nativePtrToObjectMap.size());
            return JS_INVALID_REFERENCE;
        }

        JsValueRef __log(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState)
        {
            if (argumentCount > 1)
            {
                std::string str;
                internal::forceConvertJsValueToStdString(arguments[1], &str);
                printf("JS: %s\n", str.c_str());
            }
            return JS_INVALID_REFERENCE;
        }

        JsValueRef privateDataContructor(JsValueRef callee, bool isConstructCall, JsValueRef *arguments, unsigned short argumentCount, void *callbackState)
        {
            return JS_INVALID_REFERENCE;
        }

        void privateDataFinalize(void *data)
        {
            internal::PrivateData* p = (internal::PrivateData*)data;
            if (p->finalizeCb != nullptr)
                p->finalizeCb(p->data);
            free(p);
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
            : _rt(JS_INVALID_RUNTIME_HANDLE)
            , _cx(JS_INVALID_REFERENCE)
            , _globalObj(nullptr)
            , _isValid(false)
            , _currentSourceContext(0)
    {
    }

    bool ScriptEngine::init()
    {
        printf("Initializing ChakraCore ... \n");

        FAIL_CHECK(JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &_rt));
        FAIL_CHECK(JsCreateContext(_rt, &_cx));
        FAIL_CHECK(JsSetCurrentContext(_cx));

        // Set up ES6 Promise
//        if (JsSetPromiseContinuationCallback(PromiseContinuationCallback, &taskQueue) != JsNoError)

        JsValueRef globalObj = JS_INVALID_REFERENCE;
        FAIL_CHECK(JsGetGlobalObject(&globalObj));

        _globalObj = Object::_createJSObject(nullptr, globalObj, true);

        _globalObj->defineFunction("log", __log);
        _globalObj->defineFunction("forceGC", __forceGC);

        Class* privateDataCls = Class::create("__CCPrivateData", _globalObj, nullptr, privateDataContructor);
        privateDataCls->defineFinalizedFunction(privateDataFinalize);
        privateDataCls->install();

        _isValid = true;

        return true;
    }

    ScriptEngine::~ScriptEngine()
    {
        cleanup();
    }

    void ScriptEngine::cleanup()
    {
        SAFE_RELEASE(_globalObj);

        Class::cleanup();

        JsSetCurrentContext(JS_INVALID_REFERENCE);
        JsDisposeRuntime(_rt);
    }

    std::string ScriptEngine::formatException(JsValueRef exception)
    {
        std::string ret;
        JsValueRef propertyNames = JS_INVALID_REFERENCE;
        JsGetOwnPropertyNames(exception, &propertyNames);
        JsValueType type;
        JsGetValueType(propertyNames, &type);
        assert(type == JsArray);

        for (int i = 0; ; ++i)
        {
            JsValueRef index = JS_INVALID_REFERENCE;
            JsValueRef result = JS_INVALID_REFERENCE;
            JsIntToNumber(i, &index);
            if (JsNoError != JsGetIndexedProperty(propertyNames, index, &result))
                break;
            JsGetValueType(result, &type);

            if (type == JsUndefined)
                break;

            assert(type == JsString);

            Value key;
            internal::jsToSeValue(result, &key);
            std::string keyStr = key.toString();

            if (keyStr == "stack")
            {
                JsPropertyIdRef propertyId = JS_INVALID_REFERENCE;

                if (JsCreatePropertyId(keyStr.c_str(), keyStr.length(), &propertyId) != JsNoError)
                {
                    return "failed to get and clear exception";
                }

                JsValueRef jsValue;
                if (JsGetProperty(exception, propertyId, &jsValue) != JsNoError)
                {
                    return "failed to get error message";
                }

                internal::forceConvertJsValueToStdString(jsValue, &ret);

//                printf("[%s]=%s\n", keyStr.c_str(), tmp.c_str());

                break;
            }
        }

        return ret;
    }

    Object* ScriptEngine::getGlobalObject()
    {
        return _globalObj;
    }

    void ScriptEngine::gc()
    {
        JsCollectGarbage(_rt);
    }

    bool ScriptEngine::executeScriptBuffer(const char *string, Value *data, const char *fileName)
    {
        return executeScriptBuffer(string, strlen(string), data, fileName);
    }

    bool ScriptEngine::executeScriptBuffer(const char *script, size_t length, Value *data, const char *fileName)
    {
        JsValueRef fname;
        FAIL_CHECK(JsCreateString(fileName, strlen(fileName), &fname));

        JsValueRef scriptSource;
        FAIL_CHECK(JsCreateString(script, length, &scriptSource));

        JsValueRef result;
        // Run the script.
        JsErrorCode errCode = JsRun(scriptSource, _currentSourceContext++, fname, JsParseScriptAttributeNone, &result);

        if (errCode != JsNoError)
        {
            bool hasException = false;
            FAIL_CHECK(JsHasException(&hasException));

            if (hasException)
            {
                JsValueRef exception;
                FAIL_CHECK(JsGetAndClearException(&exception));

                std::string exceptionMsg = formatException(exception);
                printf("%s\n", exceptionMsg.c_str());
                
            }
            return false;
        }

        if (data != nullptr)
        {
            JsValueType type;
            JsGetValueType(result, &type);
            if (type != JsUndefined)
            {
                internal::jsToSeValue(result, data);
            }
            else
            {
                data->setUndefined();
            }
        }

        return true;
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

    bool ScriptEngine::_onReceiveNodeEvent(void* node, NodeEventType type)
    {
//        printf("ScriptEngine::_onReceiveNodeEvent, node: %p, type: %d\n", node, (int) type);

        auto iter = __nativePtrToObjectMap.find(node);
        if (iter  == __nativePtrToObjectMap.end())
            return false;

        Object* target = iter->second;
        const char* funcName = nullptr;
        if (type == NodeEventType::ENTER)
        {
            funcName = "onEnter";
        }
        else if (type == NodeEventType::EXIT)
        {
            funcName = "onExit";
        }
        else if (type == NodeEventType::ENTER_TRANSITION_DID_FINISH)
        {
            funcName = "onEnterTransitionDidFinish";
        }
        else if (type == NodeEventType::EXIT_TRANSITION_DID_START)
        {
            funcName = "onExitTransitionDidStart";
        }
        else if (type == NodeEventType::CLEANUP)
        {
            funcName = "cleanup";
        }
        else
        {
            assert(false);
        }

        bool ret = false;
        Value funcVal;
        bool ok = target->getProperty(funcName, &funcVal);
        if (ok && !funcVal.toObject()->_isNativeFunction())
        {
            ret = funcVal.toObject()->call(EmptyValueArray, target);
        }
        return ret;
    }

} // namespace se {

#endif // SCRIPT_ENGINE_CHAKRACORE
