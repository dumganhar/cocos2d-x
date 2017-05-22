//
// Created by James Chen on 4/28/17.
//

#include "jsb_global.h"
#include "jsb_conversions.hpp"

using namespace cocos2d;

se::Object* __ccObj = nullptr;
se::Object* __jsbObj = nullptr;

namespace {

    SE_FUNC_BEGIN(ccpAdd, se::DONT_NEED_THIS)
    {
        if (argc == 2)
        {
            Vec2 pt1, pt2;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt1);
            SE_ASSERT(ok, "Error processing arguments");
            ok = seval_to_Vec2(args[1], &pt2);
            SE_ASSERT(ok, "Error processing arguments");
            Vec2 result = pt1 + pt2;
            se::Value seVal;
            ok = Vec2_to_seval(result, &seVal);
            SE_ASSERT(ok, "Error processing arguments");
            SE_SET_RVAL(seVal);
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpDistanceSQ, se::DONT_NEED_THIS)
    {
        if (argc == 2)
        {
            Vec2 pt1, pt2;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt1);
            SE_ASSERT(ok, "Error processing arguments");
            ok = seval_to_Vec2(args[1], &pt2);
            SE_ASSERT(ok, "Error processing arguments");
            float result = pt1.getDistanceSq(pt2);
            SE_SET_RVAL(se::Value(result));
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpDistance, se::DONT_NEED_THIS)
    {
        if (argc == 2)
        {
            Vec2 pt1, pt2;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt1);
            SE_ASSERT(ok, "Error processing arguments");
            ok = seval_to_Vec2(args[1], &pt2);
            SE_ASSERT(ok, "Error processing arguments");
            float result = pt1.getDistance(pt2);
            SE_SET_RVAL(se::Value(result));
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpSub, se::DONT_NEED_THIS)
    {
        if (argc == 2)
        {
            Vec2 pt1, pt2;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt1);
            SE_ASSERT(ok, "Error processing arguments");
            ok = seval_to_Vec2(args[1], &pt2);
            SE_ASSERT(ok, "Error processing arguments");
            Vec2 result = pt1 - pt2;
            se::Value seVal;
            ok = Vec2_to_seval(result, &seVal);
            SE_ASSERT(ok, "Error processing arguments");
            SE_SET_RVAL(seVal);
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpNeg, se::DONT_NEED_THIS)
    {
        if (argc == 1)
        {
            Vec2 pt;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt);
            SE_ASSERT(ok, "Error processing arguments");
            pt = -pt;
            se::Value seVal;
            ok = Vec2_to_seval(pt, &seVal);
            SE_ASSERT(ok, "Error processing arguments");
            SE_SET_RVAL(seVal);
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpMult, se::DONT_NEED_THIS)
    {
        if (argc == 2)
        {
            Vec2 pt;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt);
            SE_ASSERT(ok, "Error processing arguments");
            SE_ASSERT(args[1].isNumber(), "Error processing arguments");
            Vec2 result = pt * args[1].toFloat();
            se::Value seVal;
            ok = Vec2_to_seval(result, &seVal);
            SE_ASSERT(ok, "Error processing arguments");
            SE_SET_RVAL(seVal);
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpMidpoint, se::DONT_NEED_THIS)
    {
        if (argc == 2)
        {
            Vec2 pt1, pt2;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt1);
            SE_ASSERT(ok, "Error processing arguments");
            ok = seval_to_Vec2(args[1], &pt2);
            SE_ASSERT(ok, "Error processing arguments");
            Vec2 result = pt1.getMidpoint(pt2);
            se::Value seVal;
            ok = Vec2_to_seval(result, &seVal);
            SE_ASSERT(ok, "Error processing arguments");
            SE_SET_RVAL(seVal);
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpDot, se::DONT_NEED_THIS)
    {
        if (argc == 2)
        {
            Vec2 pt1, pt2;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt1);
            SE_ASSERT(ok, "Error processing arguments");
            ok = seval_to_Vec2(args[1], &pt2);
            SE_ASSERT(ok, "Error processing arguments");
            float result = pt1.dot(pt2);
            SE_SET_RVAL(se::Value(result));
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpCross, se::DONT_NEED_THIS)
    {
        if (argc == 2)
        {
            Vec2 pt1, pt2;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt1);
            SE_ASSERT(ok, "Error processing arguments");
            ok = seval_to_Vec2(args[1], &pt2);
            SE_ASSERT(ok, "Error processing arguments");
            float result = pt1.cross(pt2);
            SE_SET_RVAL(se::Value(result));
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpPerp, se::DONT_NEED_THIS)
    {
        if (argc == 1)
        {
            Vec2 pt;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt);
            SE_ASSERT(ok, "Error processing arguments");
            Vec2 result = pt.getPerp();
            se::Value seVal;
            ok = Vec2_to_seval(result, &seVal);
            SE_ASSERT(ok, "Error processing arguments");
            SE_SET_RVAL(seVal);
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpRPerp, se::DONT_NEED_THIS)
    {
        if (argc == 1)
        {
            Vec2 pt;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt);
            SE_ASSERT(ok, "Error processing arguments");
            Vec2 result = pt.getRPerp();
            se::Value seVal;
            ok = Vec2_to_seval(result, &seVal);
            SE_ASSERT(ok, "Error processing arguments");
            SE_SET_RVAL(seVal);
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpProject, se::DONT_NEED_THIS)
    {
        if (argc == 2)
        {
            Vec2 pt1, pt2;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt1);
            SE_ASSERT(ok, "Error processing arguments");
            ok = seval_to_Vec2(args[1], &pt2);
            SE_ASSERT(ok, "Error processing arguments");
            Vec2 result = pt1.project(pt2);
            se::Value seVal;
            ok = Vec2_to_seval(result, &seVal);
            SE_ASSERT(ok, "Error processing arguments");
            SE_SET_RVAL(seVal);
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpRotate, se::DONT_NEED_THIS)
    {
        if (argc == 2)
        {
            Vec2 pt1, pt2;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt1);
            SE_ASSERT(ok, "Error processing arguments");
            ok = seval_to_Vec2(args[1], &pt2);
            SE_ASSERT(ok, "Error processing arguments");
            Vec2 result = pt1.rotate(pt2);
            se::Value seVal;
            ok = Vec2_to_seval(result, &seVal);
            SE_ASSERT(ok, "Error processing arguments");
            SE_SET_RVAL(seVal);
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpNormalize, se::DONT_NEED_THIS)
    {
        if (argc == 1)
        {
            Vec2 pt;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt);
            SE_ASSERT(ok, "Error processing arguments");
            pt.normalize();
            se::Value seVal;
            ok = Vec2_to_seval(pt, &seVal);
            SE_ASSERT(ok, "Error processing arguments");
            SE_SET_RVAL(seVal);
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpClamp, se::DONT_NEED_THIS)
    {
        if (argc == 3)
        {
            Vec2 pt1, pt2, pt3;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt1);
            SE_ASSERT(ok, "Error processing arguments");
            ok = seval_to_Vec2(args[1], &pt2);
            SE_ASSERT(ok, "Error processing arguments");
            ok = seval_to_Vec2(args[1], &pt3);
            SE_ASSERT(ok, "Error processing arguments");
            Vec2 result = pt1.getClampPoint(pt2, pt3);
            se::Value seVal;
            ok = Vec2_to_seval(result, &seVal);
            SE_ASSERT(ok, "Error processing arguments");
            SE_SET_RVAL(seVal);
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 3);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpLengthSQ, se::DONT_NEED_THIS)
    {
        if (argc == 1)
        {
            Vec2 pt;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt);
            SE_ASSERT(ok, "Error processing arguments");
            float result = pt.getLengthSq();
            SE_SET_RVAL(se::Value(result));
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
            ret = false;
        }
    }
    SE_FUNC_END

    SE_FUNC_BEGIN(ccpLength, se::DONT_NEED_THIS)
    {
        if (argc == 1)
        {
            Vec2 pt;
            bool ok = false;
            ok = seval_to_Vec2(args[0], &pt);
            SE_ASSERT(ok, "Error processing arguments");
            float result = pt.getLength();
            SE_SET_RVAL(se::Value(result));
        }
        else
        {
            SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
            ret = false;
        }
    }
    SE_FUNC_END


    bool jsb_register_var_under_cc()
    {
        // Vec2 Math
        __ccObj->defineFunction("pAdd", ccpAdd);
        __ccObj->defineFunction("pDistanceSQ", ccpDistanceSQ);
        __ccObj->defineFunction("pDistance", ccpDistance);
        __ccObj->defineFunction("pSub", ccpSub);
        __ccObj->defineFunction("pNeg", ccpNeg);
        __ccObj->defineFunction("pMult", ccpMult);
        __ccObj->defineFunction("pMidpoint", ccpMidpoint);
        __ccObj->defineFunction("pDot", ccpDot);
        __ccObj->defineFunction("pCross", ccpCross);
        __ccObj->defineFunction("pPerp", ccpPerp);
        __ccObj->defineFunction("pRPerp", ccpRPerp);
        __ccObj->defineFunction("pProject", ccpProject);
        __ccObj->defineFunction("pRotate", ccpRotate);
        __ccObj->defineFunction("pNormalize", ccpNormalize);
        __ccObj->defineFunction("pClamp", ccpClamp);
        __ccObj->defineFunction("pLengthSQ", ccpLengthSQ);
        __ccObj->defineFunction("pLength", ccpLength);

        //

        return true;
    }
}

bool jsb_register_global_variables()
{
    auto global = se::ScriptEngine::getInstance()->getGlobalObject();
    __ccObj = se::Object::createPlainObject(false);
    global->setProperty("cc", se::Value(__ccObj));

    jsb_register_var_under_cc();

    __jsbObj = se::Object::createPlainObject(false);
    global->setProperty("jsb", se::Value(__jsbObj));

    return true;
}
