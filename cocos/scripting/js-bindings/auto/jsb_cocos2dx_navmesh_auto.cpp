#include "scripting/js-bindings/auto/jsb_cocos2dx_navmesh_auto.hpp"
#if CC_USE_NAVMESH
#include "scripting/js-bindings/manual/cocos2d_specifics.hpp"
#include "navmesh/CCNavMesh.h"
#include "scripting/js-bindings/manual/navmesh/jsb_cocos2dx_navmesh_conversions.h"

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

#endif
