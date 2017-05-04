//
//  jsb_sprite.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 4/26/17.
//
//

#include "jsb_sprite.hpp"
#include "jsb_global.h"
#include "jsb_node.hpp"

#include "cocos2d.h"

using namespace cocos2d;

se::Object* __jsb_Sprite_proto = nullptr;

SE_CTOR_BEGIN(Sprite_ctor, "Sprite")
{

}
SE_CTOR_END

SE_FINALIZE_FUNC_BEGIN(Sprite_finalized)
{
    printf("Sprite_finalized ...\n");
    Node* thiz = (Node*) nativeThisObject;
    thiz->release();
    SAFE_RELEASE(thisObject);
}
SE_FINALIZE_FUNC_END

SE_FUNC_BEGIN(Sprite_create)
{
    std::string filePath = args[0].toString();
    Sprite* sprite = Sprite::create(filePath);
    sprite->retain();
    auto obj = se::Object::createObject("Sprite", false);
    obj->setPrivateData(sprite);
    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END


bool jsb_register_Sprite()
{
    auto cls = se::Class::create("Sprite", __ccObj, __jsb_Node_proto, Sprite_ctor);
    cls->defineStaticFunction("create", Sprite_create);

    cls->defineFinalizedFunction(Sprite_finalized);

    cls->install();

    __jsb_Sprite_proto = cls->getProto();

    return true;
}
