//
//  jsb_scene.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 4/26/17.
//
//

#include "jsb_scene.hpp"
#include "jsb_global.h"
#include "jsb_node.hpp"


#include "cocos2d.h"

using namespace cocos2d;

se::Object* __jsb_Scene_proto = nullptr;
se::Class* __jsb_Scene_class = nullptr;

static bool Scene_finalized(se::State& s)
{
    printf("Scene_finalized ...\n");
    Node* thiz = (Node*)s.nativeThisObject();
    SAFE_RELEASE(thiz);
    return true;
}
SE_BIND_FINALIZE_FUNC(Scene_finalized)

static bool Scene_create(se::State& s)
{
    Scene* scene = Scene::create();
    scene->retain();
    auto obj = se::Object::createObjectWithClass(__jsb_Scene_class, false);
    obj->setPrivateData(scene);
    s.rval().setObject(obj);
    return true;
}
SE_BIND_FUNC(Scene_create)

static bool Scene_init(se::State& s)
{
    auto scene = (Scene*)s.nativeThisObject();
    bool ok = scene->init();
    s.rval().setBoolean(ok);
    return true;
}
SE_BIND_FUNC(Scene_init)

static bool Scene_constructor(se::State& s)
{
    printf("Scene constructor\n");
    Scene* obj = new Scene();
    s.thisObject()->setPrivateData(obj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_CTOR(Scene_constructor, __jsb_Scene_class, Scene_finalized)

static bool Scene_ctor(se::State& s)
{
    Scene* obj = new Scene();
    s.thisObject()->setPrivateData(obj);
    s.thisObject()->addRef();
    return true;
}
SE_BIND_SUB_CLS_CTOR(Scene_ctor, __jsb_Scene_class, Scene_finalized)

bool jsb_register_Scene()
{
    auto cls = se::Class::create("Scene", __ccObj, __jsb_Node_proto, _SE(Scene_constructor));
    cls->defineStaticFunction("create", _SE(Scene_create));
    cls->defineFunction("init", _SE(Scene_init));
    cls->defineFunction("ctor", _SE(Scene_ctor));

    cls->defineFinalizedFunction(_SE(Scene_finalized));

    cls->install();

    __jsb_Scene_proto = cls->getProto();
    __jsb_Scene_class = cls;

    return true;
}
