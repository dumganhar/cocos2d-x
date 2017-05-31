//
//  jsb_menu.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 5/3/17.
//
//

#include "jsb_menu.hpp"
#include "jsb_global.h"
#include "jsb_node.hpp"
#include "cocos2d.h"

using namespace cocos2d;

se::Object* __jsb_Menu_proto = nullptr;
se::Class* __jsb_Menu_class = nullptr;

static bool Menu_finalized(se::State& s)
{
    if (s.nativeThisObject())
    {
        printf("Menu_finalized ...\n");
        Node* thiz = (Node*) s.nativeThisObject();
        SAFE_RELEASE(thiz);
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(Menu_finalized)

static bool Menu_constructor(se::State& s)
{
    Menu* obj = new Menu();
    s.thisObject()->setPrivateData(obj);
    return true;
}
SE_BIND_CTOR(Menu_constructor, __jsb_Menu_class, Menu_finalized)


static bool Menu_ctor(se::State& s)
{
    Menu* obj = new Menu();
    s.thisObject()->setPrivateData(obj);
    return true;
}
SE_BIND_CTOR2(Menu_ctor, __jsb_Menu_class, Menu_finalized)

static bool Menu_create(se::State& s)
{
    Menu* menu = Menu::create();
    menu->retain();
    auto obj = se::Object::createObjectWithClass(__jsb_Menu_class, false);
    obj->setPrivateData(menu);
    menu->_scriptObject = obj;
    s.rval().setObject(obj);
    return true;
}
SE_BIND_FUNC(Menu_create)

bool jsb_register_Menu()
{
    auto cls = se::Class::create("Menu", __ccObj, __jsb_Node_proto, _SE(Menu_constructor));
    cls->defineFunction("ctor", _SE(Menu_ctor));

    cls->defineStaticFunction("create", _SE(Menu_create));

    cls->defineFinalizedFunction(_SE(Menu_finalized));

    cls->install();

    __jsb_Menu_proto = cls->getProto();
    __jsb_Menu_class = cls;

    return true;
}
