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

SE_FINALIZE_FUNC_BEGIN(Scene_finalized)
{
    printf("Scene_finalized ...\n");
    Node* thiz = (Node*)nativeThisObject;
    SAFE_RELEASE(thiz);
}
SE_FINALIZE_FUNC_END

SE_FUNC_BEGIN(Scene_create)
{
    Scene* scene = Scene::create();
    scene->retain();
    auto obj = se::Object::createObjectWithClass(__jsb_Scene_class, false);
    obj->setPrivateData(scene);
    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END

SE_FUNC_BEGIN(Scene_init)
{
    auto scene = (Scene*)nativeThisObject;
    bool ok = scene->init();
    SE_SET_RVAL(se::Value(ok));
}
SE_FUNC_END

SE_CTOR_BEGIN(Scene_constructor, Scene, Scene_finalized)
{
    printf("Scene constructor\n");
    Scene* obj = new Scene();
    thisObject->setPrivateData(obj);
}
SE_CTOR_END

SE_CTOR2_BEGIN(Scene_ctor, Scene, Scene_finalized)
{
    Scene* obj = new Scene();
    thisObject->setPrivateData(obj);
}
SE_CTOR2_END

bool jsb_register_Scene()
{
    auto cls = se::Class::create("Scene", __ccObj, __jsb_Node_proto, Scene_constructor);
    cls->defineStaticFunction("create", Scene_create);
    cls->defineFunction("init", Scene_init);
    cls->defineFunction("ctor", Scene_ctor);

    cls->defineFinalizedFunction(Scene_finalized);

    cls->install();

    __jsb_Scene_proto = cls->getProto();
    __jsb_Scene_class = cls;

    return true;
}
