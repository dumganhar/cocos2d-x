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

SE_CTOR_BEGIN(Scene_constructor, "Scene")
{

}
SE_CTOR_END

SE_FINALIZE_FUNC_BEGIN(Scene_finalized)
{
    printf("Scene_finalized ...\n");
    Node* thiz = (Node*) nativeThisObject;
    SAFE_RELEASE(thiz);
}
SE_FINALIZE_FUNC_END

SE_FUNC_BEGIN(Scene_create)
{
    Scene* scene = Scene::create();
    scene->retain();
    auto obj = se::Object::createObject("Scene", false);
    obj->setPrivateData(scene);
    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END

SE_FUNC_BEGIN(Scene_init)
{
    Scene* nativeObj = (Scene*)thisObject->getPrivateData();
    bool ok = nativeObj->init();
    SE_SET_RVAL(se::Value(ok));
}
SE_FUNC_END

SE_CTOR2_BEGIN(Scene_ctor, Scene_finalized)
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

    return true;
}
