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

static bool Director_getInstance(se::State& s)
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
    s.rval().setObject(obj);

    return true;
}
SE_BIND_FUNC(Director_getInstance)


static bool Director_runWithScene(se::State& s)
{
    const auto& args = s.args();
    printf("cc.Director.runWithScene ...\n");
    auto thiz = (Director*)s.nativeThisObject();
    thiz->runWithScene((Scene*)args[0].toObject()->getPrivateData());
    return true;
}
SE_BIND_FUNC(Director_runWithScene)

static bool Director_replaceScene(se::State& s)
{
    const auto& args = s.args();
    printf("cc.Director.replaceScene ...\n");
    auto thiz = (Director*)s.nativeThisObject();
    thiz->replaceScene((Scene*)args[0].toObject()->getPrivateData());
    return true;
}
SE_BIND_FUNC(Director_replaceScene)

static bool Director_finalize(se::State& s)
{
    printf("cc.Director finalized\n");
    return true;
}
SE_BIND_FINALIZE_FUNC(Director_finalize)

static bool Director_ctor(se::State& s)
{
    return true;
}
SE_BIND_CTOR(Director_ctor, __jsb_Director_class, Director_finalize)


bool jsb_register_Director()
{
    auto cls = se::Class::create("Director", __ccObj, nullptr, _SE(Director_ctor));
    cls->defineStaticFunction("getInstance", _SE(Director_getInstance));
    cls->defineFunction("runWithScene", _SE(Director_runWithScene));
    cls->defineFunction("replaceScene", _SE(Director_replaceScene));

    cls->defineFinalizedFunction(_SE(Director_finalize));

    cls->install();

    __jsb_Director_class = cls;

    return true;
}
