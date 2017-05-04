//
//  jsb_node.hpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 4/26/17.
//
//

#ifndef jsb_node_hpp
#define jsb_node_hpp

#include "SeApi.h"

extern se::Object* __jsb_Node_proto;

SE_DECLARE_FUNC(Node_onEnter);

bool jsb_register_Node();

#endif /* jsb_node_hpp */
