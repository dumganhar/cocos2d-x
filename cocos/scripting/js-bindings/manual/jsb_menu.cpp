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

SE_FINALIZE_FUNC_BEGIN(Menu_finalized)
{
    if (nativeThisObject)
    {
        printf("Menu_finalized ...\n");
        Node* thiz = (Node*) nativeThisObject;
        SAFE_RELEASE(thiz);
    }
}
SE_FINALIZE_FUNC_END

SE_CTOR_BEGIN(Menu_ctor, "Menu", Menu_finalized)
{

}
SE_CTOR_END

SE_FUNC_BEGIN(Menu_create)
{
    Menu* menu = Menu::create();
    menu->retain();
    auto obj = se::Object::createObject("Menu", false);
    obj->setPrivateData(menu);
    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END

bool jsb_register_menu()
{
    auto cls = se::Class::create("Menu", __ccObj, __jsb_Node_proto, Menu_ctor);
    cls->defineStaticFunction("create", Menu_create);

    cls->defineFinalizedFunction(Menu_finalized);

    cls->install();

    __jsb_Menu_proto = cls->getProto();

    return true;
}
