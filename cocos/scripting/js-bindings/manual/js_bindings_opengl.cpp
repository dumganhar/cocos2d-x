/*
 * Copyright (c) 2013-2017 Chukong Technologies Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "scripting/js-bindings/manual/js_bindings_opengl.h"

#include "base/CCDirector.h"
#include "renderer/CCRenderer.h"

NS_CC_BEGIN

void GLNode::draw(Renderer *renderer, const Mat4& transform, uint32_t flags) {
    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(GLNode::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);
}

void GLNode::onDraw(Mat4 &transform, uint32_t flags)
{
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();

    js_type_class_t *typeClass = js_get_type_from_native<cocos2d::GLNode>(this);
    JS::RootedObject jsObj(cx, jsb_ref_get_or_create_jsobject(cx, this, typeClass, "cocos2d::GLNode"));

    if (jsObj.get())
    {
         bool found = false;
         JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET

         JS_HasProperty(cx, jsObj, "draw", &found);
         if (found) {
             auto director = Director::getInstance();
             director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
             director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);

             JS::RootedValue rval(cx);
             JS::RootedValue fval(cx);
             JS_GetProperty(cx, jsObj, "draw", &fval);

             JS_CallFunctionValue(cx, jsObj, fval, JS::HandleValueArray::empty(), &rval);

             director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
        }
    }
}

NS_CC_END

const JSClass  *js_cocos2dx_GLNode_class;
JSObject *js_cocos2dx_GLNode_prototype;

bool js_cocos2dx_GLNode_constructor(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    if (argc == 0) {
        cocos2d::GLNode* cobj = new (std::nothrow) cocos2d::GLNode;

        js_type_class_t *typeClass = js_get_type_from_native<cocos2d::GLNode>(cobj);
        JS::RootedObject jsobj(cx, jsb_ref_create_jsobject(cx, cobj, typeClass, "cocos2d::GLNode"));

        JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
        args.rval().set(JS::ObjectValue(*jsobj));

        bool ok=false;
        if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
            ScriptingCore::getInstance()->executeFunctionWithOwner(JS::ObjectValue(*jsobj), "_ctor", args);

        return true;
    }
    JS_ReportErrorUTF8(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

static bool js_cocos2dx_GLNode_ctor(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    cocos2d::GLNode *nobj = new (std::nothrow) cocos2d::GLNode;
    auto newproxy = jsb_new_proxy(nobj, obj);
    jsb_ref_init(cx, &newproxy->obj, nobj, "cocos2d::GLNode");
    bool isFound = false;
    if (JS_HasProperty(cx, obj, "_ctor", &isFound) && isFound)
        ScriptingCore::getInstance()->executeFunctionWithOwner(JS::ObjectValue(*obj), "_ctor", args);
    args.rval().setUndefined();
    return true;
}

bool js_cocos2dx_GLNode_create(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    cocos2d::GLNode* ret = new (std::nothrow) cocos2d::GLNode;
    JS::Value jsret = JS::NullValue();

    if (ret) {
        js_type_class_t *typeClass = js_get_type_from_native<cocos2d::GLNode>(ret);

        auto jsobj = jsb_ref_create_jsobject(cx, ret, typeClass, "cocos2d::GLNode");
        jsret = JS::ObjectValue(*jsobj);
    }

    args.rval().set(jsret);
    return true;
}

extern JSObject* jsb_cocos2d_Node_prototype;

void js_register_cocos2dx_GLNode(JSContext *cx, JS::HandleObject global) {

    static const JSClassOps classOps = {
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr,
        nullptr,
        nullptr,
        nullptr, nullptr, nullptr,
        JS_GlobalObjectTraceHook
    };

    static const JSClass cls = {
        "GLNode",
        JSCLASS_HAS_RESERVED_SLOTS(2),
        &classOps
    };

    js_cocos2dx_GLNode_class = &cls;

    static JSPropertySpec properties[] = {
        {0, 0, 0, 0, 0}
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("ctor", js_cocos2dx_GLNode_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("create", js_cocos2dx_GLNode_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parentProto(cx, jsb_cocos2d_Node_prototype);
    js_cocos2dx_GLNode_prototype = JS_InitClass(
        cx, global,
        parentProto,
        js_cocos2dx_GLNode_class,
        js_cocos2dx_GLNode_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    // add the proto and JSClass to the type->js info hash table
    JS::RootedObject proto(cx, js_cocos2dx_GLNode_prototype);
    jsb_register_class<cocos2d::GLNode>(cx, js_cocos2dx_GLNode_class, proto, parentProto);

    anonEvaluate(cx, global, "(function () { cc.GLNode.extend = cc.Class.extend; })()");
}
