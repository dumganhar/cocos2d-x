//
//  jsb_node.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 4/26/17.
//
//

#include "jsb_node.hpp"
#include "jsb_global.h"

#include "cocos2d.h"

using namespace cocos2d;

se::Object* __jsb_Node_proto = nullptr;

SE_CTOR_BEGIN(Node_ctor, "Node")
{

}
SE_CTOR_END

SE_FINALIZE_FUNC_BEGIN(Node_finalized)
{
    printf("Node_finalized ...\n");
    Node* thiz = (Node*) nativeThisObject;
    thiz->release();
    thisObject->release();
}
SE_FINALIZE_FUNC_END

SE_FUNC_BEGIN(Node_create)
{
    Node* node = Node::create();
    node->retain();
    auto obj = se::Object::createObject("Node", false);
    obj->setPrivateData(node);
    SE_SET_RVAL(se::Value(obj));
}
SE_FUNC_END

SE_FUNC_BEGIN(Node_addChild)
{
    Node* thiz = (Node*)thisObject->getPrivateData();
    Node* child = (Node*)args[0].toObject()->getPrivateData();
    thiz->addChild(child);
}
SE_FUNC_END

SE_SET_PROPERTY_BEGIN(Node_set_x)
{
    Node* thiz = (Node*)thisObject->getPrivateData();
    float x = data.toNumber();
    thiz->setPositionX(x);
}
SE_SET_PROPERTY_END

SE_GET_PROPERTY_BEGIN(Node_get_x)
{
    Node* thiz = (Node*)thisObject->getPrivateData();
    SE_SET_RVAL(se::Value(thiz->getPositionX()));
}
SE_GET_PROPERTY_END

SE_SET_PROPERTY_BEGIN(Node_set_y)
{
    Node* thiz = (Node*)thisObject->getPrivateData();
    float y = data.toNumber();
    thiz->setPositionY(y);
}
SE_SET_PROPERTY_END

SE_GET_PROPERTY_BEGIN(Node_get_y)
{
    Node* thiz = (Node*)thisObject->getPrivateData();
    SE_SET_RVAL(se::Value(thiz->getPositionY()));
}
SE_GET_PROPERTY_END

bool jsb_register_Node()
{
    auto cls = se::Class::create("Node", __ccObj, nullptr, Node_ctor);
    cls->defineStaticFunction("create", Node_create);

    cls->defineProperty("x", Node_get_x, Node_set_x);
    cls->defineProperty("y", Node_get_y, Node_set_y);

    cls->defineFunction("addChild", Node_addChild);
    cls->defineFinalizedFunction(Node_finalized);

    cls->install();

    __jsb_Node_proto = cls->getProto();

    return true;
}
