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

SE_FINALIZE_FUNC_BEGIN(MenuItem_finalized)
{
    if (nativeThisObject)
    {
        printf("MenuItem_finalized ...\n");
    }
}
SE_FINALIZE_FUNC_END

SE_FUNC_BEGIN(MenuItem_create, se::DONT_NEED_THIS)
{
    MenuItem* nativeObj = MenuItem::create();
    nativeObj->retain();
    auto obj = se::Object::createObjectWithClass(__jsb_MenuItem_class, false);
    obj->setPrivateData(nativeObj);
    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END

SE_CTOR_BEGIN(MenuItem_ctor, __jsb_MenuItem_class, MenuItem_finalized)
{

}
SE_CTOR_END

///

se::Object* __jsb_MenuItemLabel_proto = nullptr;

SE_FINALIZE_FUNC_BEGIN(MenuItemLabel_finalized)
{
    if (nativeThisObject)
    {
        printf("MenuItemLabel_finalized ...\n");
    }
}
SE_FINALIZE_FUNC_END

SE_FUNC_BEGIN(MenuItemLabel_create, se::DONT_NEED_THIS)
{
//    MenuItemLabel* nativeObj = MenuItemLabel::create();
//    nativeObj->retain();
//    auto obj = se::Object::createObjectWithClass(__jsb_MenuItemLabel_class, false);
//    obj->setPrivateData(nativeObj);
//    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END

SE_CTOR_BEGIN(MenuItemLabel_ctor, __jsb_MenuItemLabel_class, MenuItemLabel_finalized)
{

}
SE_CTOR_END

///
se::Object* __jsb_MenuItemFont_proto = nullptr;

SE_FINALIZE_FUNC_BEGIN(MenuItemFont_finalized)
{
    if (nativeThisObject)
    {
        printf("MenuItemFont_finalized...\n");
        Node* thiz = (Node*) nativeThisObject;
        SAFE_RELEASE(thiz);
    }
}
SE_FINALIZE_FUNC_END

SE_FUNC_BEGIN(MenuItemFont_create, se::DONT_NEED_THIS)
{
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
    SE_SET_RVAL(se::Value(item));
}
SE_FUNC_END

SE_CTOR_BEGIN(MenuItemFont_ctor, __jsb_MenuItemFont_class, MenuItemFont_finalized)
{

}
SE_CTOR_END

bool jsb_register_MenuItem()
{
    auto cls = se::Class::create("MenuItem", __ccObj, __jsb_Node_proto, MenuItem_ctor);
    cls->defineFinalizedFunction(MenuItem_finalized);
    cls->install();
    __jsb_MenuItem_proto = cls->getProto();
    __jsb_MenuItem_class = cls;
    //
    cls = se::Class::create("MenuItemLabel", __ccObj, __jsb_MenuItem_proto, MenuItemLabel_ctor);
    cls->defineFinalizedFunction(MenuItemLabel_finalized);
    cls->install();
    __jsb_MenuItemLabel_proto = cls->getProto();
    __jsb_MenuItemLabel_class = cls;
    //
    cls = se::Class::create("MenuItemFont", __ccObj, __jsb_MenuItemLabel_proto, MenuItemFont_ctor);
    cls->defineStaticFunction("create", MenuItemFont_create);
    cls->defineFinalizedFunction(MenuItemFont_finalized);
    cls->install();
    __jsb_MenuItemFont_proto = cls->getProto();
    __jsb_MenuItemFont_class = cls;

    return true;
}
