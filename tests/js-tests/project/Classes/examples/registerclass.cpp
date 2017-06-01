#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

#include "cocos/scripting/js-bindings/manual/jsb_register_all.h"
#include "cocos/scripting/js-bindings/manual/jsb_global.h"
#include "cocos/scripting/js-bindings/manual/jsb_node.hpp"
#include "cocos/scripting/js-bindings/manual/jsb_cocos2dx_manual.hpp"
#include "cocos/scripting/js-bindings/manual/jsb_conversions.hpp"
#include "cocos/scripting/js-bindings/auto/jsb_cocos2dx_auto.hpp"

#include <unistd.h>
#include <iostream>
#include <string>

using namespace cocos2d;

bool register_all_cocos2dx(se::Object* obj);

int main_register_class(int argc, char** argv)
{
    se::ScriptEngine* se = se::ScriptEngine::getInstance();
    if ( !se->isValid() ) {
        printf("Unable to Initialize JavaScript Wrapper.\n");
        return 1;
    }

    se::AutoHandleScope hs;

    se::Object* global = se->getGlobalObject();
    jsb_register_global_variables();

    se->executeScriptFile("/Users/james/Project/cocos2d-x/tests/js-tests/src/new-jsb-prepare.js");
    se->executeScriptFile(FileUtils::getInstance()->fullPathForFilename("script/jsb_prepare.js"));
//    jsb_register_all();
    register_all_cocos2dx(global);

    jsb_register_Node_manual();
    register_all_cocos2dx_manual(global);

    se->executeScriptFile(FileUtils::getInstance()->fullPathForFilename("script/jsb_boot.js"));

//    se->executeScriptFile("/Users/james/Project/cocos2d-x/tests/js-tests/src/test-new-jsb.js");
    se->executeScriptFile(FileUtils::getInstance()->fullPathForFilename("main.js"));

    // conversion unit test
    {
        se::Object* obj = se::Object::createPlainObject(false);
        obj->setProperty("x", se::Value(100.3111f));
        obj->setProperty("y", se::Value(30.4222f));
        obj->setProperty("z", se::Value(120.4231f));
        obj->setProperty("w", se::Value(3430.33288f));

        {
            Vec2 pt;
            assert(seval_to_Vec2(se::Value(obj), &pt));
            assert(std::abs(pt.x - 100.3111f) < FLT_EPSILON);
            assert(std::abs(pt.y - 30.4222f) < FLT_EPSILON);
        }

        {
            Vec3 pt;
            assert(seval_to_Vec3(se::Value(obj), &pt));
            assert(std::abs(pt.x - 100.3111f) < FLT_EPSILON);
            assert(std::abs(pt.y - 30.4222f) < FLT_EPSILON);
            assert(std::abs(pt.z - 120.4231f) < FLT_EPSILON);
        }

        {
            Vec4 pt;
            assert(seval_to_Vec4(se::Value(obj), &pt));
            assert(std::abs(pt.x - 100.3111f) < FLT_EPSILON);
            assert(std::abs(pt.y - 30.4222f) < FLT_EPSILON);
            assert(std::abs(pt.z - 120.4231f) < FLT_EPSILON);
            assert(std::abs(pt.w - 3430.33288f) < FLT_EPSILON);
        }
        obj->release();
    }

    {
        se::Object* obj = se::Object::createPlainObject(false);

        obj->setProperty("width", se::Value(120.4231f));
        obj->setProperty("height", se::Value(3430.33288f));

        cocos2d::Size size;
        assert(seval_to_Size(se::Value(obj), &size));
        assert(std::abs(size.width - 120.4231f) < FLT_EPSILON);
        assert(std::abs(size.height - 3430.33288f) < FLT_EPSILON);

        obj->release();
    }

    {
        se::Object* obj = se::Object::createPlainObject(false);

        obj->setProperty("x", se::Value(100.3111f));
        obj->setProperty("y", se::Value(30.4222f));
        obj->setProperty("width", se::Value(120.4231f));
        obj->setProperty("height", se::Value(3430.33288f));

        cocos2d::Rect rc;
        assert(seval_to_Rect(se::Value(obj), &rc));
        assert(std::abs(rc.origin.x - 100.3111f) < FLT_EPSILON);
        assert(std::abs(rc.origin.y - 30.4222f) < FLT_EPSILON);
        assert(std::abs(rc.size.width - 120.4231f) < FLT_EPSILON);
        assert(std::abs(rc.size.height - 3430.33288f) < FLT_EPSILON);

        obj->release();
    }

    {
        se::Object* obj = se::Object::createPlainObject(false);

        obj->setProperty("r", se::Value(233));
        obj->setProperty("g", se::Value(123));
        obj->setProperty("b", se::Value(43));
        obj->setProperty("a", se::Value(11));

        Color4B color;
        assert(seval_to_Color4B(se::Value(obj), &color));
        assert(color.r == 233);
        assert(color.g == 123);
        assert(color.b == 43);
        assert(color.a == 11);
        obj->release();
    }

    {
        se::Object* obj = se::Object::createArrayObject(16, false);

        se::Value v;
        for (uint32_t i = 0; i < 16; ++i)
        {
            v.setFloat(i * 2.3f);
            obj->setArrayElement(i, v);
        }

        Mat4 mat4;
        seval_to_Mat4(se::Value(obj), &mat4);

        for (uint32_t i = 0; i < 16; ++i)
        {
            assert(std::abs(mat4.m[i] - i * 2.3f) < FLT_EPSILON);
        }

        obj->release();
    }

    {
        se::Object* obj = se::Object::createPlainObject(true);
        obj->setProperty("r", se::Value(233));
        obj->setProperty("g", se::Value(123));
        obj->setProperty("b", se::Value(43));
        obj->setProperty("a", se::Value(11));

        se::Object* subObj = se::Object::createPlainObject(false);
        subObj->setProperty("a", se::Value(233));
        subObj->setProperty("b", se::Value(123));
        subObj->setProperty("c", se::Value(43));
        subObj->setProperty("d", se::Value(11));
        obj->setProperty("subobj", se::Value(subObj));


        se::Object* subArr = se::Object::createArrayObject(0, false);
        subArr->setArrayElement(0, se::Value(3244));
        subArr->setArrayElement(1, se::Value(1314));
        subArr->setArrayElement(2, se::Value(520));
        subObj->setProperty("subsubarray", se::Value(subArr));

        // start test
        cocos2d::ValueMap valueMap;
        assert(seval_to_ccvaluemap(se::Value(obj), &valueMap));

        assert(valueMap["r"].asInt() == 233);
        assert(valueMap["g"].asInt() == 123);
        assert(valueMap["b"].asInt() == 43);
        assert(valueMap["a"].asInt() == 11);
        //

        auto& subObjMap = valueMap["subobj"].asValueMap();
        assert(subObjMap["a"].asInt() == 233);
        assert(subObjMap["b"].asInt() == 123);
        assert(subObjMap["c"].asInt() == 43);
        assert(subObjMap["d"].asInt() == 11);

        auto& subsubVector = subObjMap["subsubarray"].asValueVector();
        assert(subsubVector[0].asInt() == 3244);
        assert(subsubVector[1].asInt() == 1314);
        assert(subsubVector[2].asInt() == 520);


        subArr->release();
        subObj->release();
        obj->release();
    }

    {
        se::Object* obj = se::Object::createPlainObject(true);
        obj->setProperty("3", se::Value(233));
        obj->setProperty("493", se::Value(123));
        obj->setProperty("1223", se::Value(43));
        obj->setProperty("444", se::Value(11));

        cocos2d::ValueMapIntKey ret;
        assert(seval_to_ccvaluemapintkey(se::Value(obj), &ret));

        assert(ret[3].asInt() == 233);
        assert(ret[493].asInt() == 123);
        assert(ret[1223].asInt() == 43);
        assert(ret[444].asInt() == 11);

        obj->release();
    }

    {
        se::Object* obj = se::Object::createPlainObject(true);
        obj->setProperty("src", se::Value(0x0302));
        obj->setProperty("dst", se::Value(0x0303));

        cocos2d::BlendFunc blendFunc;
        assert(seval_to_blendfunc(se::Value(obj), &blendFunc));

        assert(blendFunc.src == 0x0302);
        assert(blendFunc.dst == 0x0303);

        obj->release();
    }

    {
        se::Object* obj = se::Object::createArrayObject(3, true);

        se::Value str1("str1");
        se::Value str2("str2");
        se::Value str3("str3");
        se::Value str4("str4");
        obj->setArrayElement(0, str1);
        obj->setArrayElement(1, str2);
        obj->setArrayElement(2, str3);
        obj->setArrayElement(3, str4);

        std::vector<std::string> ret;
        assert(seval_to_std_vector_string(se::Value(obj), &ret));

        assert(ret.size() == 4);
        assert(ret[0] == "str1");
        assert(ret[1] == "str2");
        assert(ret[2] == "str3");
        assert(ret[3] == "str4");

        obj->release();
    }

    {
        se::Object* obj = se::Object::createArrayObject(3, true);

        se::Value float1(1233.1334f);
        se::Value float2(84973.237f);
        se::Value float3(32038.4302f);
        se::Value float4(42093.459323f);
        obj->setArrayElement(0, float1);
        obj->setArrayElement(1, float2);
        obj->setArrayElement(2, float3);
        obj->setArrayElement(3, float4);

        std::vector<float> ret;
        assert(seval_to_std_vector_float(se::Value(obj), &ret));

        assert(ret.size() == 4);
        assert(std::abs(ret[0] - 1233.1334f) < FLT_EPSILON);
        assert(std::abs(ret[1] - 84973.237f) < FLT_EPSILON);
        assert(std::abs(ret[2] - 32038.4302f) < FLT_EPSILON);
        assert(std::abs(ret[3] - 42093.459323f) < FLT_EPSILON);

        obj->release();
    }

    {
        se::Object* obj = se::Object::createArrayObject(3, true);

        se::Value v1(123);
        se::Value v2(443);
        se::Value v3(1283);
        se::Value v4(32849234);
        obj->setArrayElement(0, v1);
        obj->setArrayElement(1, v2);
        obj->setArrayElement(2, v3);
        obj->setArrayElement(3, v4);

        std::vector<int> ret;
        assert(seval_to_std_vector_int(se::Value(obj), &ret));

        assert(ret.size() == 4);
        assert(ret[0] == 123);
        assert(ret[1] == 443);
        assert(ret[2] == 1283);
        assert(ret[3] == 32849234);

        obj->release();
    }

    {
        se::Object* obj = se::Object::createArrayObject(3, true);

        {
            se::Object* subobj = se::Object::createPlainObject(false);
            subobj->setProperty("x", se::Value(2382.239f));
            subobj->setProperty("y", se::Value(348923.23923f));
            obj->setArrayElement(0, se::Value(subobj));
            subobj->release();
        }
        {
            se::Object* subobj = se::Object::createPlainObject(false);
            subobj->setProperty("x", se::Value(232003.23892f));
            subobj->setProperty("y", se::Value(23.32932f));
            obj->setArrayElement(1, se::Value(subobj));
            subobj->release();
        }

        {
            se::Object* subobj = se::Object::createPlainObject(false);
            subobj->setProperty("x", se::Value(28938923.231f));
            subobj->setProperty("y", se::Value(1278231.23891f));
            obj->setArrayElement(2, se::Value(subobj));
            subobj->release();
        }

        {
            se::Object* subobj = se::Object::createPlainObject(false);
            subobj->setProperty("x", se::Value(239184543.2372f));
            subobj->setProperty("y", se::Value(3.2389f));
            obj->setArrayElement(3, se::Value(subobj));
            subobj->release();
        }

        std::vector<cocos2d::Vec2> ret;
        assert(seval_to_std_vector_Vec2(se::Value(obj), &ret));

        assert(ret.size() == 4);
        assert(std::abs(ret[0].x - 2382.239f) < FLT_EPSILON);
        assert(std::abs(ret[0].y - 348923.23923f) < FLT_EPSILON);

        assert(std::abs(ret[1].x - 232003.23892f) < FLT_EPSILON);
        assert(std::abs(ret[1].y - 23.32932f) < FLT_EPSILON);

        assert(std::abs(ret[2].x - 28938923.231f) < FLT_EPSILON);
        assert(std::abs(ret[2].y - 1278231.23891f) < FLT_EPSILON);

        assert(std::abs(ret[3].x - 239184543.2372f) < FLT_EPSILON);
        assert(std::abs(ret[3].y - 3.2389f) < FLT_EPSILON);

        obj->release();
    }

    {
        se::Object* obj = se::Object::createPlainObject(true);

        obj->setProperty("fontName", se::Value("MyArial"));
        obj->setProperty("fontSize", se::Value(33));
        obj->setProperty("textAlign", se::Value((int32_t)(TextHAlignment::CENTER)));
        obj->setProperty("verticalAlign", se::Value((int32_t)(TextVAlignment::BOTTOM)));
        se::Value tmp;
        Color3B_to_seval(Color3B::RED, &tmp);
        obj->setProperty("fillStyle", tmp);
        obj->setProperty("boundingWidth", se::Value(400));
        obj->setProperty("boundingHeight", se::Value(300));
        obj->setProperty("shadowEnabled", se::Value(true));
        obj->setProperty("shadowOffsetX", se::Value(12));
        obj->setProperty("shadowOffsetY", se::Value(-12));
        obj->setProperty("shadowBlur", se::Value(0.34f));
        obj->setProperty("shadowOpacity", se::Value(0.32f));
        obj->setProperty("strokeEnabled", se::Value(true));
        Color3B_to_seval(Color3B::BLUE, &tmp);
        obj->setProperty("strokeStyle", tmp);
        obj->setProperty("lineWidth", se::Value(1.23f));
        obj->setProperty("strokeAlpha", se::Value(223));

        FontDefinition ret;
        assert(seval_to_FontDefinition(se::Value(obj), &ret));
        assert(ret._fontName == "MyArial");
        assert(ret._fontSize == 33);
        assert(ret._alignment == TextHAlignment::CENTER);
        assert(ret._vertAlignment == TextVAlignment::BOTTOM);
        assert(ret._fontFillColor == Color3B::RED);
        assert(ret._dimensions.equals(cocos2d::Size(400, 300)));
        assert(ret._shadow._shadowEnabled);
        assert(std::abs(ret._shadow._shadowOffset.width - 12) < FLT_EPSILON);
        assert(std::abs(ret._shadow._shadowOffset.height - (-12)) < FLT_EPSILON);
        assert(std::abs(ret._shadow._shadowBlur - (0.34f)) < FLT_EPSILON);
        assert(std::abs(ret._shadow._shadowOpacity - (0.32f)) < FLT_EPSILON);
        assert(ret._stroke._strokeEnabled);
        assert(ret._stroke._strokeColor == Color3B::BLUE);
        assert(std::abs(ret._stroke._strokeSize - 1.23f) < FLT_EPSILON);
        assert(ret._stroke._strokeAlpha == 223);

        obj->release();
    }

    // native value -> se value
    {
        cocos2d::Vec2 v(100.2334f, 283.32891f);
        se::Value ret;
        assert(Vec2_to_seval(v, &ret));
        assert(ret.isObject());
        se::Object* obj = ret.toObject();
        se::Value x, y;
        assert(obj->getProperty("x", &x));
        assert(obj->getProperty("y", &y));

        assert(x.isNumber() && y.isNumber());

        assert(std::abs(x.toFloat() - 100.2334f) < FLT_EPSILON);
        assert(std::abs(y.toFloat() - 283.32891f) < FLT_EPSILON);
    }

    {
        cocos2d::Vec3 v(100.2334f, 283.32891f, 2382.482f);
        se::Value ret;
        assert(Vec3_to_seval(v, &ret));
        assert(ret.isObject());
        se::Object* obj = ret.toObject();
        se::Value x, y, z;
        assert(obj->getProperty("x", &x));
        assert(obj->getProperty("y", &y));
        assert(obj->getProperty("z", &z));

        assert(x.isNumber() && y.isNumber() && z.isNumber());

        assert(std::abs(x.toFloat() - 100.2334f) < FLT_EPSILON);
        assert(std::abs(y.toFloat() - 283.32891f) < FLT_EPSILON);
        assert(std::abs(z.toFloat() - 2382.482f) < FLT_EPSILON);
    }

    {
        cocos2d::Vec4 v(100.2334f, 283.32891f, 2382.482f, 1289.32f);
        se::Value ret;
        assert(Vec4_to_seval(v, &ret));
        assert(ret.isObject());
        se::Object* obj = ret.toObject();
        se::Value x, y, z, w;
        assert(obj->getProperty("x", &x));
        assert(obj->getProperty("y", &y));
        assert(obj->getProperty("z", &z));
        assert(obj->getProperty("w", &w));

        assert(x.isNumber() && y.isNumber() && z.isNumber() && w.isNumber());

        assert(std::abs(x.toFloat() - 100.2334f) < FLT_EPSILON);
        assert(std::abs(y.toFloat() - 283.32891f) < FLT_EPSILON);
        assert(std::abs(z.toFloat() - 2382.482f) < FLT_EPSILON);
        assert(std::abs(w.toFloat() - 1289.32f) < FLT_EPSILON);
    }

    {
        cocos2d::BlendFunc v;
        v.src = GL_ONE_MINUS_DST_ALPHA;
        v.dst = GL_SRC_COLOR;

        se::Value ret;
        assert(blendfunc_to_seval(v, &ret));
        assert(ret.isObject());

        se::Object* obj = ret.toObject();
        se::Value src, dst;
        assert(obj->getProperty("src", &src));
        assert(obj->getProperty("dst", &dst));
        assert(src.isNumber());
        assert(dst.isNumber());
        assert(src.toUint32() == GL_ONE_MINUS_DST_ALPHA);
        assert(dst.toUint32() == GL_SRC_COLOR);
    }

    {
        cocos2d::Uniform v;
        v.location = 103;
        v.size = 123894;
        v.type = 392;
        v.name = "hello uniform";

        se::Value ret;
        assert(uniform_to_seval(&v, &ret));
        assert(ret.isObject());

        se::Object* obj = ret.toObject();
        se::Value location, size, type, name;
        assert(obj->getProperty("location", &location));
        assert(obj->getProperty("size", &size));
        assert(obj->getProperty("type", &type));
        assert(obj->getProperty("name", &name));
        assert(location.isNumber());
        assert(size.isNumber());
        assert(type.isNumber());
        assert(name.isString());

        assert(location.toUint32() == 103);
        assert(size.toUint32() == 123894);
        assert(type.toUint32() == 392);
        assert(name.toString() == "hello uniform");
    }

    {
        cocos2d::FontDefinition v;
        v._fontName = "MyArial";
        v._fontSize = 33;
        v._alignment = TextHAlignment::CENTER;
        v._vertAlignment = TextVAlignment::BOTTOM;
        v._fontFillColor = Color3B::RED;
        v._dimensions = cocos2d::Size(400, 300);
        v._shadow._shadowEnabled = true;
        v._shadow._shadowOffset = Vec2(12, -12);
        v._shadow._shadowBlur = 0.34f;
        v._shadow._shadowOpacity = 0.32f;
        v._stroke._strokeEnabled = true;
        v._stroke._strokeColor = Color3B::BLUE;
        v._stroke._strokeSize = 1.23f;
        v._stroke._strokeAlpha = 223;


        se::Value ret;
        assert(FontDefinition_to_seval(v, &ret));
        assert(ret.isObject());
        se::Object* obj = ret.toObject();
        se::Value tmp;
        assert(obj->getProperty("fontName", &tmp) && tmp.toString() == "MyArial");
        assert(obj->getProperty("fontSize", &tmp) && tmp.toInt32() == 33);
        assert(obj->getProperty("textAlign", &tmp) && tmp.toInt32() == (int32_t)TextHAlignment::CENTER);
        assert(obj->getProperty("verticalAlign", &tmp) && tmp.toInt32() == (int32_t)TextVAlignment::BOTTOM);
        assert(obj->getProperty("fillStyle", &tmp) && tmp.isObject());
        Color3B color;
        seval_to_Color3B(tmp, &color);
        assert(color == Color3B::RED);
        assert(obj->getProperty("boundingWidth", &tmp) && std::abs(tmp.toFloat() - 400) < FLT_EPSILON);
        assert(obj->getProperty("boundingHeight", &tmp) && std::abs(tmp.toFloat() - 300) < FLT_EPSILON);

        assert(obj->getProperty("shadowEnabled", &tmp) && tmp.toBoolean());
        assert(obj->getProperty("shadowOffsetX", &tmp) && std::abs(tmp.toFloat() - 12) < FLT_EPSILON);
        assert(obj->getProperty("shadowOffsetY", &tmp) && std::abs(tmp.toFloat() - (-12)) < FLT_EPSILON);
        assert(obj->getProperty("shadowBlur", &tmp) && std::abs(tmp.toFloat() - 0.34f) < FLT_EPSILON);

        assert(obj->getProperty("strokeEnabled", &tmp) && tmp.toBoolean());
        assert(obj->getProperty("strokeStyle", &tmp) && tmp.isObject());
        seval_to_Color3B(tmp, &color);
        assert(color == Color3B::BLUE);
        assert(obj->getProperty("lineWidth", &tmp) && std::abs(tmp.toFloat() - 1.23f) < FLT_EPSILON);
        assert(obj->getProperty("strokeAlpha", &tmp) && tmp.toUint8() == 223);
    }

    {
        se::Value tmp;
        cocos2d::Value v1(323.12f);
        assert(ccvalue_to_seval(v1, &tmp) && std::abs(tmp.toFloat() - 323.12f) < FLT_EPSILON);
        cocos2d::Value v2(true);
        assert(ccvalue_to_seval(v2, &tmp) && tmp.toBoolean());
        cocos2d::Value v3(false);
        assert(ccvalue_to_seval(v3, &tmp) && !tmp.toBoolean());
        cocos2d::Value v4("aaa");
        assert(ccvalue_to_seval(v4, &tmp) && tmp.toString() == "aaa");
        cocos2d::Value v5(1002);
        assert(ccvalue_to_seval(v5, &tmp) && tmp.toInt32() == 1002);
        {
            cocos2d::ValueMap map;
            map["aaa"] = "bbb";
            map["bbb"] = true;
            map["c"] = false;
            map["int"] = 123;
            map["float"] = 239.02f;
            assert(ccvalue_to_seval(cocos2d::Value(map), &tmp) && tmp.isObject());
            se::Object* obj = tmp.toObject();
            std::vector<std::string> allKeys;
            assert(obj->getAllKeys(&allKeys) && allKeys.size() == 5);
            se::Value tmp2;
            assert(obj->getProperty("aaa", &tmp2) && tmp2.toString() == "bbb");
            assert(obj->getProperty("bbb", &tmp2) && tmp2.toBoolean());
            assert(obj->getProperty("c", &tmp2) && !tmp2.toBoolean());
            assert(obj->getProperty("int", &tmp2) && tmp2.toInt32() == 123);
            assert(obj->getProperty("float", &tmp2) && tmp2.toFloat() == 239.02f);
        }

        {
            cocos2d::ValueMapIntKey map;
            map[111] = "bbb";
            map[22] = true;
            map[334] = false;
            map[12345] = 123;
            map[11124] = 239.02f;
            assert(ccvalue_to_seval(cocos2d::Value(map), &tmp) && tmp.isObject());
            se::Object* obj = tmp.toObject();
            std::vector<std::string> allKeys;
            assert(obj->getAllKeys(&allKeys) && allKeys.size() == 5);
            se::Value tmp2;
            assert(obj->getProperty("111", &tmp2) && tmp2.toString() == "bbb");
            assert(obj->getProperty("22", &tmp2) && tmp2.toBoolean());
            assert(obj->getProperty("334", &tmp2) && !tmp2.toBoolean());
            assert(obj->getProperty("12345", &tmp2) && tmp2.toInt32() == 123);
            assert(obj->getProperty("11124", &tmp2) && tmp2.toFloat() == 239.02f);
        }

        {
            cocos2d::ValueVector vec;
            vec.push_back(cocos2d::Value("bbb"));
            vec.push_back(cocos2d::Value(true));
            vec.push_back(cocos2d::Value(false));
            vec.push_back(cocos2d::Value(123));
            vec.push_back(cocos2d::Value(239.02f));
            assert(ccvalue_to_seval(cocos2d::Value(vec), &tmp) && tmp.isObject());
            se::Object* obj = tmp.toObject();
            uint32_t len = 0;
            assert(obj->isArray() && obj->getArrayLength(&len) && len == 5);
            se::Value tmp2;
            assert(obj->getArrayElement(0, &tmp2) && tmp2.toString() == "bbb");
            assert(obj->getArrayElement(1, &tmp2) && tmp2.toBoolean());
            assert(obj->getArrayElement(2, &tmp2) && !tmp2.toBoolean());
            assert(obj->getArrayElement(3, &tmp2) && tmp2.toInt32() == 123);
            assert(obj->getArrayElement(4, &tmp2) && tmp2.toFloat() == 239.02f);
        }
    }

    {
        std::vector<std::string> vec = {"aaa", "bbb", "hello", "world"};
        se::Value tmp;
        se::Value tmp2;
        assert(std_vector_string_to_seval(vec, &tmp) && tmp.isObject());
        se::Object* obj = tmp.toObject();
        uint32_t len = 0;
        assert(obj->isArray() && obj->getArrayLength(&len) && len == 4);
        assert(obj->getArrayElement(0, &tmp2) && tmp2.toString() == "aaa");
        assert(obj->getArrayElement(1, &tmp2) && tmp2.toString() == "bbb");
        assert(obj->getArrayElement(2, &tmp2) && tmp2.toString() == "hello");
        assert(obj->getArrayElement(3, &tmp2) && tmp2.toString() == "world");
    }

    {
        std::vector<int> vec = {123, -21334, -233, 3494};
        se::Value tmp;
        se::Value tmp2;
        assert(std_vector_int_to_seval(vec, &tmp) && tmp.isObject());
        se::Object* obj = tmp.toObject();
        uint32_t len = 0;
        assert(obj->isArray() && obj->getArrayLength(&len) && len == 4);
        assert(obj->getArrayElement(0, &tmp2) && tmp2.toInt32() == 123);
        assert(obj->getArrayElement(1, &tmp2) && tmp2.toInt32() == -21334);
        assert(obj->getArrayElement(2, &tmp2) && tmp2.toInt32() == -233);
        assert(obj->getArrayElement(3, &tmp2) && tmp2.toInt32() == 3494);
    }

    {
        std::vector<float> vec = {123.03f, -21334.23f, -233.043f, 3494.2305f};
        se::Value tmp;
        se::Value tmp2;
        assert(std_vector_float_to_seval(vec, &tmp) && tmp.isObject());
        se::Object* obj = tmp.toObject();
        uint32_t len = 0;
        assert(obj->isArray() && obj->getArrayLength(&len) && len == 4);
        assert(obj->getArrayElement(0, &tmp2) && std::abs(tmp2.toFloat() - 123.03f) < FLT_EPSILON);
        assert(obj->getArrayElement(1, &tmp2) && std::abs(tmp2.toFloat() - (-21334.23f)) < FLT_EPSILON);
        assert(obj->getArrayElement(2, &tmp2) && std::abs(tmp2.toFloat() - (-233.043f)) < FLT_EPSILON);
        assert(obj->getArrayElement(3, &tmp2) && std::abs(tmp2.toFloat() - 3494.2305f) < FLT_EPSILON);
    }

    {
        cocos2d::Mat4 mat4;
        for (uint8_t i = 0; i < 16; ++i)
        {
            mat4.m[i] = i * 23.25f;
        }

        se::Value ret;
        assert(Mat4_to_seval(mat4, &ret) && ret.isObject());
        se::Object* obj = ret.toObject();
        uint32_t len = 0;
        assert(obj->isArray() && obj->getArrayLength(&len) && len == 16);

        se::Value tmp;
        for (uint8_t i = 0; i < 16; ++i)
        {
            assert(obj->getArrayElement(i, &tmp));
            assert(std::abs(tmp.toFloat() - i * 23.25f) < FLT_EPSILON);
        }

    }

    return 0;
}
