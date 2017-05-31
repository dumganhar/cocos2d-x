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

static bool Sprite_finalized(se::State& s)
{
    if (s.nativeThisObject())
    {
        printf("Sprite_finalized ...\n");
        Node* thiz = (Node*) s.nativeThisObject();
        SAFE_RELEASE(thiz);
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(Sprite_finalized)


static bool Sprite_create(se::State& s)
{
    const auto& args = s.args();
    std::string filePath = args[0].toString();
    Sprite* sprite = Sprite::create(filePath);
    sprite->retain();
    auto obj = se::Object::createObjectWithClass(__jsb_Sprite_class, false);
    obj->setPrivateData(sprite);
    s.rval().setObject(obj);
    return true;
}
SE_BIND_FUNC(Sprite_create)

static bool Sprite_initWithFile(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    assert(argc == 1);
    assert(args[0].isString());
    std::string filePath = args[0].toString();
    Sprite* nativeObj = (Sprite*)s.nativeThisObject();
    bool ok = nativeObj->initWithFile(filePath);
    s.rval().setBoolean(ok);
    return true;
}
SE_BIND_FUNC(Sprite_initWithFile)

static bool Sprite_constructor(se::State& s)
{
//    printf("Sprite_constructor1: %p, jsret: %p\n", _constructor, _jsRet);
    Sprite* obj = new Sprite();
    s.thisObject()->setPrivateData(obj);
    s.thisObject()->addRef();
//    printf("Sprite_constructor2, this: %p\n", thisObject);
    return true;
}
SE_BIND_CTOR(Sprite_constructor, __jsb_Sprite_class, Sprite_finalized)


static bool Sprite_ctor(se::State& s)
{
//    printf("Sprite_ctor: %p\n", _thisObject);
    Sprite* obj = new Sprite();
    s.thisObject()->setPrivateData(obj);
    s.thisObject()->addRef();
//    printf("cc.Sprite native obj: %p\n", obj);
    return true;
}
SE_BIND_SUB_CLS_CTOR(Sprite_ctor, __jsb_Sprite_class, Sprite_finalized)

static double __test_static_property = 100.0;

static bool Sprite_test_static_property_getter(se::State& s)
{
    s.rval().setNumber(__test_static_property);
    return true;
}
SE_BIND_PROP_GET(Sprite_test_static_property_getter)

static bool Sprite_test_static_property_setter(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 1)
    {
        __test_static_property = args[0].toNumber();
        return true;
    }
    return false;
}
SE_BIND_PROP_SET(Sprite_test_static_property_setter)

bool jsb_register_Sprite()
{
    auto cls = se::Class::create("Sprite", __ccObj, __jsb_Node_proto, _SE(Sprite_constructor));
    cls->defineStaticFunction("create", _SE(Sprite_create));
    cls->defineStaticProperty("test_static_property", _SE(Sprite_test_static_property_getter), _SE(Sprite_test_static_property_setter));
    cls->defineFunction("initWithFile", _SE(Sprite_initWithFile));
    cls->defineFunction("ctor", _SE(Sprite_ctor));

    cls->defineFinalizedFunction(_SE(Sprite_finalized));

    cls->install();

    __jsb_Sprite_proto = cls->getProto();
    __jsb_Sprite_class = cls;

    return true;
}
