//
//  jsb_director.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 4/26/17.
//
//

#include "jsb_director.hpp"

#include "jsb_global.h"

#include "cocos2d.h"

using namespace cocos2d;

se::Class* __jsb_Director_class = nullptr;

SE_FUNC_BEGIN(Director_getInstance, se::DONT_NEED_THIS)
{
    auto director = Director::getInstance();
    se::Object* obj = nullptr;
    if (director->_scriptObject == nullptr)
    {
        obj = se::Object::createObjectWithClass(__jsb_Director_class, true);
        obj->setPrivateData(director);
        director->_scriptObject = obj;
    }
    else
    {
        obj = se::Object::getObjectWithPtr(director);
    }

    assert(obj);
    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END


SE_FUNC_BEGIN(Director_runWithScene, se::DONT_NEED_THIS)
{
    printf("cc.Director.runWithScene ...\n");
    auto thiz = (Director*)nativeThisObject;
    thiz->runWithScene((Scene*)args[0].toObject()->getPrivateData());
}
SE_FUNC_END

SE_FUNC_BEGIN(Director_replaceScene, se::DONT_NEED_THIS)
{
    printf("cc.Director.replaceScene ...\n");
    auto thiz = (Director*)nativeThisObject;
    thiz->replaceScene((Scene*)args[0].toObject()->getPrivateData());
}
SE_FUNC_END

SE_FINALIZE_FUNC_BEGIN(Director_finalize)
{
    printf("cc.Director finalized\n");
}
SE_FINALIZE_FUNC_END

SE_CTOR_BEGIN(Director_ctor, Director, Director_finalize)
{

}
SE_CTOR_END

bool jsb_register_Director()
{
    auto cls = se::Class::create("Director", __ccObj, nullptr, Director_ctor);
    cls->defineStaticFunction("getInstance", Director_getInstance);
    cls->defineFunction("runWithScene", Director_runWithScene);
    cls->defineFunction("replaceScene", Director_replaceScene);

    cls->defineFinalizedFunction(Director_finalize);

    cls->install();

    __jsb_Director_class = cls;

    return true;
}
