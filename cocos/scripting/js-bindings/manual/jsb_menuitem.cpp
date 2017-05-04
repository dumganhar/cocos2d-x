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

SE_CTOR_BEGIN(MenuItem_ctor, "MenuItem")
{

}
SE_CTOR_END

SE_FINALIZE_FUNC_BEGIN(MenuItem_finalized)
{
    printf("MenuItem_finalized ...\n");
}
SE_FINALIZE_FUNC_END

SE_FUNC_BEGIN(MenuItem_create)
{
    MenuItem* nativeObj = MenuItem::create();
    nativeObj->retain();
    auto obj = se::Object::createObject("MenuItem", false);
    obj->setPrivateData(nativeObj);
    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END

///

se::Object* __jsb_MenuItemLabel_proto = nullptr;

SE_CTOR_BEGIN(MenuItemLabel_ctor, "MenuItemLabel")
{

}
SE_CTOR_END

SE_FINALIZE_FUNC_BEGIN(MenuItemLabel_finalized)
{
    printf("MenuItemLabel_finalized ...\n");
}
SE_FINALIZE_FUNC_END

SE_FUNC_BEGIN(MenuItemLabel_create)
{
//    MenuItemLabel* nativeObj = MenuItemLabel::create();
//    nativeObj->retain();
//    auto obj = se::Object::createObject("MenuItemLabel", false);
//    obj->setPrivateData(nativeObj);
//    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END

///
se::Object* __jsb_MenuItemFont_proto = nullptr;

SE_CTOR_BEGIN(MenuItemFont_ctor, "MenuItemFont")
{

}
SE_CTOR_END

SE_FINALIZE_FUNC_BEGIN(MenuItemFont_finalized)
{
    printf("MenuItemFont_finalized ...\n");
    Node* thiz = (Node*) nativeThisObject;
    thiz->release();
    SAFE_RELEASE(thisObject);
}
SE_FINALIZE_FUNC_END

SE_FUNC_BEGIN(MenuItemFont_create)
{
    std::string str = args[0].toString();
    se::Value func(args[1]);
    se::Value target(args[2]);
    MenuItemFont* nativeObj = MenuItemFont::create(str, [func, target](Ref* sender){
        se::Object* funcObj = func.toObject();
        se::Object* targetObj = target.toObject();
        se::Object* senderObj = se::Object::getObjectWithPtr(sender);
        se::ValueArray args;
        args.push_back(se::Value(senderObj));
        funcObj->call(args, targetObj);
    });
    nativeObj->retain();
    auto obj = se::Object::createObject("MenuItemFont", false);
    obj->setPrivateData(nativeObj);
    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END

bool jsb_register_menuitem()
{
    auto cls = se::Class::create("MenuItem", __ccObj, __jsb_Node_proto, MenuItem_ctor);
    cls->defineFinalizedFunction(MenuItem_finalized);
    cls->install();
    __jsb_MenuItem_proto = cls->getProto();
    //
    cls = se::Class::create("MenuItemLabel", __ccObj, __jsb_MenuItem_proto, MenuItemLabel_ctor);
    cls->defineFinalizedFunction(MenuItemLabel_finalized);
    cls->install();
    __jsb_MenuItemLabel_proto = cls->getProto();
    //
    cls = se::Class::create("MenuItemFont", __ccObj, __jsb_MenuItemLabel_proto, MenuItemFont_ctor);
    cls->defineStaticFunction("create", MenuItemFont_create);
    cls->defineFinalizedFunction(MenuItemFont_finalized);
    cls->install();
    __jsb_MenuItemFont_proto = cls->getProto();


    return true;
}
