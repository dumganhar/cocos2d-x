//
//  jsb_menuitem.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 5/3/17.
//
//

#include "jsb_menuitem.hpp"

#include "jsb_global.h"
#include "jsb_node.hpp"
#include "cocos2d.h"

using namespace cocos2d;

se::Object* __jsb_MenuItem_proto = nullptr;
se::Class* __jsb_MenuItem_class = nullptr;
se::Class* __jsb_MenuItemLabel_class = nullptr;
se::Class* __jsb_MenuItemFont_class = nullptr;

static bool MenuItem_finalized(se::State& s)
{
    if (s.nativeThisObject())
    {
        printf("MenuItem_finalized ...\n");
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(MenuItem_finalized)

static bool MenuItem_create(se::State& s)
{
    MenuItem* nativeObj = MenuItem::create();
    nativeObj->retain();
    auto obj = se::Object::createObjectWithClass(__jsb_MenuItem_class, false);
    obj->setPrivateData(nativeObj);
    s.rval().setObject(obj);
    return true;
}
SE_BIND_FUNC(MenuItem_create)

static bool MenuItem_ctor(se::State& s)
{
    return true;
}
SE_BIND_SUB_CLS_CTOR(MenuItem_ctor, __jsb_MenuItem_class, MenuItem_finalized);


///

se::Object* __jsb_MenuItemLabel_proto = nullptr;

static bool MenuItemLabel_finalized(se::State& s)
{
    if (s.nativeThisObject())
    {
        printf("MenuItemLabel_finalized ...\n");
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(MenuItemLabel_finalized)

static bool MenuItemLabel_create(se::State& s)
{
//    MenuItemLabel* nativeObj = MenuItemLabel::create();
//    nativeObj->retain();
//    auto obj = se::Object::createObjectWithClass(__jsb_MenuItemLabel_class, false);
//    obj->setPrivateData(nativeObj);
//    SE_SET_RVAL(se::Value(obj));
    return true;
}
SE_BIND_FUNC(MenuItemLabel_create)

static bool MenuItemLabel_ctor(se::State& s)
{
    return true;
}
SE_BIND_SUB_CLS_CTOR(MenuItemLabel_ctor, __jsb_MenuItemLabel_class, MenuItemLabel_finalized)

///
se::Object* __jsb_MenuItemFont_proto = nullptr;

static bool MenuItemFont_finalized(se::State& s)
{
    if (s.nativeThisObject())
    {
        printf("MenuItemFont_finalized...\n");
        Node* thiz = (Node*) s.nativeThisObject();
        SAFE_RELEASE(thiz);
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(MenuItemFont_finalized)

static bool MenuItemFont_create(se::State& s)
{
    const auto& args = s.args();
    std::string str = args[0].toString();
    se::Value func(args[1]);
    se::Value target(args[2]);
    auto item = se::Object::createObjectWithClass(__jsb_MenuItemFont_class, false);
    item->attachChild(func.toObject());
    MenuItemFont* nativeObj = MenuItemFont::create(str, [func, target](Ref* sender){
        se::Object* funcObj = func.toObject();
        se::Object* targetObj = target.toObject();
        se::Object* senderObj = se::Object::getObjectWithPtr(sender);
        se::ValueArray args;
        args.push_back(se::Value(senderObj));
        funcObj->call(args, targetObj);
        senderObj->release();
    });
    nativeObj->retain();
    item->setPrivateData(nativeObj);
    nativeObj->_scriptObject = item;
    s.rval().setObject(item);
    return true;
}
SE_BIND_FUNC(MenuItemFont_create)

static bool MenuItemFont_ctor(se::State& s)
{
    return true;
}
SE_BIND_SUB_CLS_CTOR(MenuItemFont_ctor, __jsb_MenuItemFont_class, MenuItemFont_finalized)

bool jsb_register_MenuItem()
{
    auto cls = se::Class::create("MenuItem", __ccObj, __jsb_Node_proto, _SE(MenuItem_ctor));
    cls->defineFinalizedFunction(_SE(MenuItem_finalized));
    cls->install();
    __jsb_MenuItem_proto = cls->getProto();
    __jsb_MenuItem_class = cls;
    //
    cls = se::Class::create("MenuItemLabel", __ccObj, __jsb_MenuItem_proto, _SE(MenuItemLabel_ctor));
    cls->defineFinalizedFunction(_SE(MenuItemLabel_finalized));
    cls->install();
    __jsb_MenuItemLabel_proto = cls->getProto();
    __jsb_MenuItemLabel_class = cls;
    //
    cls = se::Class::create("MenuItemFont", __ccObj, __jsb_MenuItemLabel_proto, _SE(MenuItemFont_ctor));
    cls->defineStaticFunction("create", _SE(MenuItemFont_create));
    cls->defineFinalizedFunction(_SE(MenuItemFont_finalized));
    cls->install();
    __jsb_MenuItemFont_proto = cls->getProto();
    __jsb_MenuItemFont_class = cls;

    return true;
}
