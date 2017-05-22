#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

#include "cocos/scripting/js-bindings/manual/jsb_register_all.h"
#include "cocos/scripting/js-bindings/manual/jsb_conversions.hpp"

#include <unistd.h>
#include <iostream>
#include <string>

using namespace cocos2d;


int main_register_class(int argc, char** argv)
{
    se::ScriptEngine* se = se::ScriptEngine::getInstance();
    if ( !se->isValid() ) {
        printf("Unable to Initialize JavaScript Wrapper.\n");
        return 1;
    }

    se::AutoHandleScope hs;

    jsb_register_all();

    se->executeScriptFile("/Users/james/Project/cocos2d-x/tests/js-tests/src/test-new-jsb.js");

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
        se::Object* obj = se::Object::createPlainObject(false);
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
        se::Object* obj = se::Object::createPlainObject(false);
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
        se::Object* obj = se::Object::createPlainObject(false);
        obj->setProperty("src", se::Value(0x0302));
        obj->setProperty("dst", se::Value(0x0303));

        cocos2d::BlendFunc blendFunc;
        assert(seval_to_blendfunc(se::Value(obj), &blendFunc));

        assert(blendFunc.src == 0x0302);
        assert(blendFunc.dst == 0x0303);

        obj->release();
    }

    {
        se::Object* obj = se::Object::createArrayObject(3, false);

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
        se::Object* obj = se::Object::createArrayObject(3, false);

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
        se::Object* obj = se::Object::createArrayObject(3, false);

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
        se::Object* obj = se::Object::createArrayObject(3, false);

        {
            se::Object* subobj = se::Object::createPlainObject(false);
            subobj->setProperty("x", se::Value(2382.239f));
            subobj->setProperty("y", se::Value(348923.23923f));
            obj->setArrayElement(0, se::Value(subobj));
        }
        {
            se::Object* subobj = se::Object::createPlainObject(false);
            subobj->setProperty("x", se::Value(232003.23892f));
            subobj->setProperty("y", se::Value(23.32932f));
            obj->setArrayElement(1, se::Value(subobj));
        }

        {
            se::Object* subobj = se::Object::createPlainObject(false);
            subobj->setProperty("x", se::Value(28938923.231f));
            subobj->setProperty("y", se::Value(1278231.23891f));
            obj->setArrayElement(2, se::Value(subobj));
        }

        {
            se::Object* subobj = se::Object::createPlainObject(false);
            subobj->setProperty("x", se::Value(239184543.2372f));
            subobj->setProperty("y", se::Value(3.2389f));
            obj->setArrayElement(3, se::Value(subobj));
        }

        std::vector<cocos2d::Vec2> ret;
        assert(seval_to_std_vector_vec2(se::Value(obj), &ret));

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

    return 0;
}
