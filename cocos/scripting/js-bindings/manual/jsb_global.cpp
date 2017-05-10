//
// Created by James Chen on 4/28/17.
//

#include "jsb_global.h"

se::Object* __ccObj = nullptr;
se::Object* __jsbObj = nullptr;

bool jsb_register_global_variables()
{
    auto global = se::ScriptEngine::getInstance()->getGlobalObject();
    __ccObj = se::Object::createPlainObject(false);
    global->setProperty("cc", se::Value(__ccObj));

    __jsbObj = se::Object::createPlainObject(false);
    global->setProperty("jsb", se::Value(__jsbObj));

    return true;
}
