#include "scripting/js-bindings/auto/jsb_cocos2dx_network_auto.hpp"
#include "scripting/js-bindings/manual/cocos2d_specifics.hpp"
#include "network/CCDownloader.h"
#include "scripting/js-bindings/manual/network/js_network_manual.h"

template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS_ReportErrorUTF8(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, JS::Value *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
const JSClass  *jsb_cocos2d_network_Downloader_class;
JSObject *jsb_cocos2d_network_Downloader_prototype;

bool js_cocos2dx_network_Downloader_setOnTaskError(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::network::Downloader* cobj = (cocos2d::network::Downloader *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_network_Downloader_setOnTaskError : Invalid Native Object");
    if (argc == 1) {
        std::function<void (const cocos2d::network::DownloadTask &, int, int, const std::basic_string<char> &)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
		        auto lambda = [=](const cocos2d::network::DownloadTask & larg0, int larg1, int larg2, const std::basic_string<char> & larg3) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[4];
		            largv[0] = downloadTask_to_jsval(cx, larg0);
		            largv[1] = int32_to_jsval(cx, larg1);
		            largv[2] = int32_to_jsval(cx, larg2);
		            largv[3] = std_string_to_jsval(cx, larg3);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(4, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_network_Downloader_setOnTaskError : Error processing arguments");
        cobj->setOnTaskError(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_network_Downloader_setOnTaskError : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_network_Downloader_setOnTaskProgress(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::network::Downloader* cobj = (cocos2d::network::Downloader *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_network_Downloader_setOnTaskProgress : Invalid Native Object");
    if (argc == 1) {
        std::function<void (const cocos2d::network::DownloadTask &, long long, long long, long long)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
		        auto lambda = [=](const cocos2d::network::DownloadTask & larg0, long long larg1, long long larg2, long long larg3) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[4];
		            largv[0] = downloadTask_to_jsval(cx, larg0);
		            largv[1] = long_long_to_jsval(cx, larg1);
		            largv[2] = long_long_to_jsval(cx, larg2);
		            largv[3] = long_long_to_jsval(cx, larg3);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(4, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_network_Downloader_setOnTaskProgress : Error processing arguments");
        cobj->setOnTaskProgress(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_network_Downloader_setOnTaskProgress : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_network_Downloader_createDownloadFileTask(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::network::Downloader* cobj = (cocos2d::network::Downloader *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_network_Downloader_createDownloadFileTask : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_network_Downloader_createDownloadFileTask : Error processing arguments");
        std::shared_ptr<const cocos2d::network::DownloadTask> ret = cobj->createDownloadFileTask(arg0, arg1);
        JS::RootedValue jsret(cx);
        jsret = downloadTask_to_jsval(cx, *ret);
        args.rval().set(jsret);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_network_Downloader_createDownloadFileTask : Error processing arguments");
        std::shared_ptr<const cocos2d::network::DownloadTask> ret = cobj->createDownloadFileTask(arg0, arg1, arg2);
        JS::RootedValue jsret(cx);
        jsret = downloadTask_to_jsval(cx, *ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_network_Downloader_createDownloadFileTask : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_network_Downloader_setOnFileTaskSuccess(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::network::Downloader* cobj = (cocos2d::network::Downloader *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_network_Downloader_setOnFileTaskSuccess : Invalid Native Object");
    if (argc == 1) {
        std::function<void (const cocos2d::network::DownloadTask &)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx, args.thisv().toObjectOrNull());
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
		        auto lambda = [=](const cocos2d::network::DownloadTask & larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::Value largv[1];
		            largv[0] = downloadTask_to_jsval(cx, larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		//cjh                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_network_Downloader_setOnFileTaskSuccess : Error processing arguments");
        cobj->setOnFileTaskSuccess(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_cocos2dx_network_Downloader_setOnFileTaskSuccess : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_network_Downloader_constructor(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    bool ok = true;
    cocos2d::network::Downloader* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    do {
        if (argc == 1) {
            cocos2d::network::DownloaderHints arg0;
            ok &= jsval_to_DownloaderHints(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            cobj = new (std::nothrow) cocos2d::network::Downloader(arg0);

            js_type_class_t *typeClass = js_get_type_from_native<cocos2d::network::Downloader>(cobj);
            JS::RootedObject proto(cx, typeClass->proto.ref());
            obj = JS_NewObjectWithGivenProto(cx, typeClass->jsclass, proto);
            js_proxy_t* p = jsb_new_proxy(cobj, obj);
            jsb_non_ref_init(cx, &p->obj, cobj, "cocos2d::network::Downloader");
        }
    } while(0);

    do {
        if (argc == 0) {
            cobj = new (std::nothrow) cocos2d::network::Downloader();

            js_type_class_t *typeClass = js_get_type_from_native<cocos2d::network::Downloader>(cobj);
            JS::RootedObject proto(cx, typeClass->proto.ref());
            obj = JS_NewObjectWithGivenProto(cx, typeClass->jsclass, proto);
            js_proxy_t* p = jsb_new_proxy(cobj, obj);
            jsb_non_ref_init(cx, &p->obj, cobj, "cocos2d::network::Downloader");
        }
    } while(0);

    if (cobj) {
        if (JS_HasProperty(cx, obj, "_ctor", &ok) && ok)
                ScriptingCore::getInstance()->executeFunctionWithOwner(JS::ObjectValue(*obj), "_ctor", args);

        args.rval().set(JS::ObjectValue(*obj));
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_cocos2dx_network_Downloader_constructor : wrong number of arguments");
    return false;
}


void js_cocos2d_network_Downloader_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Downloader)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        cocos2d::network::Downloader *nobj = static_cast<cocos2d::network::Downloader *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            JS::RootedValue flagValue(cx);
            JS_GetProperty(cx, jsobj, "__cppCreated", &flagValue);
            if (flagValue.isNullOrUndefined()){
                delete nobj;
            }
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_cocos2dx_network_Downloader(JSContext *cx, JS::HandleObject global) {
    static const JSClassOps classOps = {
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr,
        nullptr,
        js_cocos2d_network_Downloader_finalize,
        nullptr, nullptr, nullptr,
        JS_GlobalObjectTraceHook
    };

    static const JSClass cls = {
        "Downloader",
        JSCLASS_HAS_RESERVED_SLOTS(2),
        &classOps
    };

    jsb_cocos2d_network_Downloader_class = &cls;

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("setOnTaskError", js_cocos2dx_network_Downloader_setOnTaskError, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setOnTaskProgress", js_cocos2dx_network_Downloader_setOnTaskProgress, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("createDownloadFileTask", js_cocos2dx_network_Downloader_createDownloadFileTask, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setOnFileTaskSuccess", js_cocos2dx_network_Downloader_setOnFileTaskSuccess, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_cocos2d_network_Downloader_prototype = JS_InitClass(
        cx, global,
        nullptr,
        jsb_cocos2d_network_Downloader_class,
        js_cocos2dx_network_Downloader_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_cocos2d_network_Downloader_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "Downloader"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<cocos2d::network::Downloader>(cx, jsb_cocos2d_network_Downloader_class, proto, nullptr);
}

void register_all_cocos2dx_network(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "jsb", &ns);

    js_register_cocos2dx_network_Downloader(cx, ns);
}

