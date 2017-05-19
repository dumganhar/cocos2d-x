#pragma once

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "cocos2d.h"

#define JSB_PRECONDITION3( condition, ret_value, ...) do { \
        if( ! (condition) ) { \
            cocos2d::log("jsb: ERROR: File %s: Line: %d, Function: %s", __FILE__, __LINE__, __FUNCTION__ ); \
            cocos2d::log(__VA_ARGS__); \
            return (ret_value); \
        } \
    } while(0)


bool jsval_to_Vec2(const se::Value& v, cocos2d::Vec2* pt);
bool jsval_to_Vec3(const se::Value& v, cocos2d::Vec3* pt);
bool jsval_to_Vec4(const se::Value& v, cocos2d::Vec4* pt);
bool jsval_to_Mat4(const se::Value& v, cocos2d::Mat4* mat);
bool jsval_to_Size(const se::Value& v, cocos2d::Size* size);
bool jsval_to_Rect(const se::Value& v, cocos2d::Rect* rect);
bool jsval_to_Color3B(const se::Value& v, cocos2d::Color3B* color);
bool jsval_to_Color4B(const se::Value& v, cocos2d::Color4B* color);
bool jsval_to_Color4F(const se::Value& v, cocos2d::Color4F* color);
