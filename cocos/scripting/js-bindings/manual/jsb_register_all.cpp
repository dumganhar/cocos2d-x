//
// Created by James Chen on 4/28/17.
//

#include "jsb_register_all.h"
#include "jsb_global.h"
#include "jsb_director.hpp"
#include "jsb_scene.hpp"
#include "jsb_node.hpp"
#include "jsb_sprite.hpp"
#include "jsb_menu.hpp"
#include "jsb_menuitem.hpp"

bool jsb_register_all()
{
    jsb_register_global_variables();
    jsb_register_Director();
    jsb_register_Node();
    jsb_register_Sprite();
    jsb_register_Scene();
    jsb_register_menu();
    jsb_register_menuitem();

    return true;
}
