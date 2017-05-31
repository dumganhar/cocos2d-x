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
se::Class* __jsb_Sprite_class = nullptr;

SE_FINALIZE_FUNC_BEGIN(Sprite_finalized)
{
    if (nativeThisObject)
    {
        printf("Sprite_finalized ...\n");
        Node* thiz = (Node*) nativeThisObject;
        SAFE_RELEASE(thiz);
    }
}
SE_FINALIZE_FUNC_END

SE_FUNC_BEGIN(Sprite_create, se::DONT_NEED_THIS)
{
    std::string filePath = args[0].toString();
    Sprite* sprite = Sprite::create(filePath);
    sprite->retain();
    auto obj = se::Object::createObjectWithClass(__jsb_Sprite_class, false);
    obj->setPrivateData(sprite);
    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END

SE_FUNC_BEGIN(Sprite_initWithFile, se::DONT_NEED_THIS)
{
    assert(argc == 1);
    assert(args[0].isString());
    std::string filePath = args[0].toString();
    Sprite* nativeObj = (Sprite*)nativeThisObject;
    bool ok = nativeObj->initWithFile(filePath);
    SE_SET_RVAL(se::Value(ok));
}
SE_FUNC_END

SE_CTOR_BEGIN(Sprite_constructor, __jsb_Sprite_class, Sprite_finalized)
{
//    printf("Sprite_constructor1: %p, jsret: %p\n", _constructor, _jsRet);
    Sprite* obj = new Sprite();
    thisObject->setPrivateData(obj);
//    printf("Sprite_constructor2, this: %p\n", thisObject);
}
SE_CTOR_END

SE_CTOR2_BEGIN(Sprite_ctor, __jsb_Sprite_class, Sprite_finalized)
{
//    printf("Sprite_ctor: %p\n", _thisObject);
    Sprite* obj = new Sprite();
    thisObject->setPrivateData(obj);
//    printf("cc.Sprite native obj: %p\n", obj);
}
SE_CTOR2_END

static double __test_static_property = 100.0;

SE_GET_PROPERTY_BEGIN(Sprite_test_static_property_getter, se::DONT_NEED_THIS)
{
    SE_SET_RVAL(se::Value(__test_static_property));
}
SE_GET_PROPERTY_END

SE_SET_PROPERTY_BEGIN(Sprite_test_static_property_setter, se::DONT_NEED_THIS)
{
    __test_static_property = data.toNumber();
}
SE_SET_PROPERTY_END

bool jsb_register_Sprite()
{
    auto cls = se::Class::create("Sprite", __ccObj, __jsb_Node_proto, Sprite_constructor);
    cls->defineStaticFunction("create", Sprite_create);
    cls->defineStaticProperty("test_static_property", Sprite_test_static_property_getter, Sprite_test_static_property_setter);
    cls->defineFunction("initWithFile", Sprite_initWithFile);
    cls->defineFunction("ctor", Sprite_ctor);

    cls->defineFinalizedFunction(Sprite_finalized);

    cls->install();

    __jsb_Sprite_proto = cls->getProto();
    __jsb_Sprite_class = cls;

    return true;
}
