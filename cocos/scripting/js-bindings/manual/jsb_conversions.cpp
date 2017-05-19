//
//  jsb_conversions.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 5/17/17.
//
//

#include "jsb_conversions.hpp"

bool jsval_to_Vec2(const se::Value& v, cocos2d::Vec2* pt)
{
    assert(v.isObject() && pt != nullptr);
    se::Object* obj = v.toObject();
    se::Value x;
    se::Value y;
    bool ok = obj->getProperty("x", &x);
    JSB_PRECONDITION3(ok && x.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("y", &y);
    JSB_PRECONDITION3(ok && y.isNumber(), false , "Error processing arguments");
    pt->x = x.toFloat();
    pt->y = y.toFloat();
    return true;
}

bool jsval_to_Vec3(const se::Value& v, cocos2d::Vec3* pt)
{
    assert(v.isObject() && pt != nullptr);
    se::Object* obj = v.toObject();
    se::Value x;
    se::Value y;
    se::Value z;
    bool ok = obj->getProperty("x", &x);
    JSB_PRECONDITION3(ok && x.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("y", &y);
    JSB_PRECONDITION3(ok && y.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("z", &z);
    JSB_PRECONDITION3(ok && z.isNumber(), false , "Error processing arguments");
    pt->x = x.toFloat();
    pt->y = y.toFloat();
    pt->z = z.toFloat();
    return true;
}

bool jsval_to_Vec4(const se::Value& v, cocos2d::Vec4* pt)
{
    assert(v.isObject() && pt != nullptr);
    se::Object* obj = v.toObject();
    se::Value x;
    se::Value y;
    se::Value z;
    se::Value w;
    bool ok = obj->getProperty("x", &x);
    JSB_PRECONDITION3(ok && x.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("y", &y);
    JSB_PRECONDITION3(ok && y.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("z", &z);
    JSB_PRECONDITION3(ok && z.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("w", &w);
    JSB_PRECONDITION3(ok && w.isNumber(), false , "Error processing arguments");
    pt->x = x.toFloat();
    pt->y = y.toFloat();
    pt->z = z.toFloat();
    pt->w = w.toFloat();
    return true;
}

bool jsval_to_Mat4(const se::Value& v, cocos2d::Mat4* mat)
{
    assert(v.isObject() && mat != nullptr);

    JSB_PRECONDITION3(v.toObject()->isArray(), false, "Matrix object must be an Array");

    se::Object* obj = v.toObject();

    bool ok = false;
    uint32_t len = 0;
    ok = obj->getArrayLength(&len);
    JSB_PRECONDITION3(ok, false, "getArrayLength failed!");

    if (len != 16)
    {
        SE_REPORT_ERROR("Array length error: %d, was expecting 16", len);
        return false;
    }

    se::Value tmp;
    for (uint32_t i = 0; i < len; ++i)
    {
        ok = obj->getArrayElement(i, &tmp);
        JSB_PRECONDITION3(ok, false, "getArrayElement failed!");

        if (tmp.isNumber())
        {
            mat->m[i] = tmp.toFloat();
        }
        else
        {
            SE_REPORT_ERROR("%u, not supported type in matrix", i);
            return false;
        }

        tmp.setUndefined();
    }

    return true;
}

bool jsval_to_Size(const se::Value& v, cocos2d::Size* size)
{
    assert(v.isObject() && size != nullptr);
    se::Object* obj = v.toObject();
    se::Value width;
    se::Value height;

    bool ok = obj->getProperty("width", &width);
    JSB_PRECONDITION3(ok && width.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("height", &height);
    JSB_PRECONDITION3(ok && height.isNumber(), false , "Error processing arguments");
    size->width = width.toFloat();
    size->height = height.toFloat();
    return true;
}

bool jsval_to_Rect(const se::Value& v, cocos2d::Rect* rect)
{
    assert(v.isObject() && rect != nullptr);
    se::Object* obj = v.toObject();
    se::Value x;
    se::Value y;
    se::Value width;
    se::Value height;

    bool ok = obj->getProperty("x", &x);
    JSB_PRECONDITION3(ok && x.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("y", &y);
    JSB_PRECONDITION3(ok && y.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("width", &width);
    JSB_PRECONDITION3(ok && width.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("height", &height);
    JSB_PRECONDITION3(ok && height.isNumber(), false , "Error processing arguments");
    rect->origin.x = x.toFloat();
    rect->origin.y = y.toFloat();
    rect->size.width = width.toFloat();
    rect->size.height = height.toFloat();

    return true;
}

bool jsval_to_Color3B(const se::Value& v, cocos2d::Color3B* color)
{
    assert(v.isObject() && color != nullptr);
    se::Object* obj = v.toObject();
    se::Value r;
    se::Value g;
    se::Value b;
    bool ok = obj->getProperty("r", &r);
    JSB_PRECONDITION3(ok && r.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("g", &g);
    JSB_PRECONDITION3(ok && g.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("b", &b);
    JSB_PRECONDITION3(ok && b.isNumber(), false , "Error processing arguments");
    color->r = (GLubyte)r.toUint16();
    color->g = (GLubyte)g.toUint16();
    color->b = (GLubyte)b.toUint16();
    return true;
}

bool jsval_to_Color4B(const se::Value& v, cocos2d::Color4B* color)
{
    assert(v.isObject() && color != nullptr);
    se::Object* obj = v.toObject();
    se::Value r;
    se::Value g;
    se::Value b;
    se::Value a;
    bool ok = obj->getProperty("r", &r);
    JSB_PRECONDITION3(ok && r.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("g", &g);
    JSB_PRECONDITION3(ok && g.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("b", &b);
    JSB_PRECONDITION3(ok && b.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("a", &a);
    JSB_PRECONDITION3(ok && b.isNumber(), false , "Error processing arguments");
    color->r = (GLubyte)r.toUint16();
    color->g = (GLubyte)g.toUint16();
    color->b = (GLubyte)b.toUint16();
    color->a = (GLubyte)a.toUint16();
    return true;
}

bool jsval_to_Color4F(const se::Value& v, cocos2d::Color4F* color)
{
    assert(v.isObject() && color != nullptr);
    se::Object* obj = v.toObject();
    se::Value r;
    se::Value g;
    se::Value b;
    se::Value a;
    bool ok = obj->getProperty("r", &r);
    JSB_PRECONDITION3(ok && r.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("g", &g);
    JSB_PRECONDITION3(ok && g.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("b", &b);
    JSB_PRECONDITION3(ok && b.isNumber(), false , "Error processing arguments");
    ok = obj->getProperty("a", &a);
    JSB_PRECONDITION3(ok && b.isNumber(), false , "Error processing arguments");
    color->r = r.toFloat();
    color->g = g.toFloat();
    color->b = b.toFloat();
    color->a = a.toFloat();
    return true;
}
