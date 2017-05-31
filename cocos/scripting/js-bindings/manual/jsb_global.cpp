//
// Created by James Chen on 4/28/17.
//

#include "jsb_global.h"
#include "jsb_conversions.hpp"

using namespace cocos2d;

se::Object* __jscObj = nullptr;
se::Object* __ccObj = nullptr;
se::Object* __jsbObj = nullptr;

namespace {

    SE_FUNC_BEGIN(require, se::DONT_NEED_THIS)
    {
        assert(argc >= 1);
        assert(args[0].isString());
        se::Value rval;
        std::string fullPath = FileUtils::getInstance()->fullPathForFilename(args[0].toString());
        se::ScriptEngine::getInstance()->executeScriptFile(fullPath, &rval);
        SE_SET_RVAL(rval);
    }
    SE_FUNC_END

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

    SE_FUNC_BEGIN(ccassert, se::DONT_NEED_THIS)
    {
        if (argc >= 1)
        {
            if (argc == 1)
            {
                SE_ASSERT(args[0].toBoolean(), "NO MESSAGE");
            }
            else
            {
                SE_ASSERT(args[0].toBoolean(), "%s", args[1].toString().c_str());
            }
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
        __ccObj->defineFunction("assert", ccassert);

        return true;
    }
}

SE_FUNC_BEGIN(jsc_garbageCollect, se::DONT_NEED_THIS)
{
    se::ScriptEngine::getInstance()->gc();
}
SE_FUNC_END

SE_FUNC_BEGIN(jsc_dumpRoot, se::DONT_NEED_THIS)
{
    assert(false);
}
SE_FUNC_END

SE_FUNC_BEGIN(JSBCore_platform, se::DONT_NEED_THIS)
{
    if (argc!=0)
    {
        SE_REPORT_ERROR("Invalid number of arguments in __getPlatform");
    }
    else
    {
        Application::Platform platform;

        // config.deviceType: Device Type
        // 'mobile' for any kind of mobile devices, 'desktop' for PCs, 'browser' for Web Browsers
        // #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
        //     platform = JS_InternString(_cx, "desktop");
        // #else
        platform = Application::getInstance()->getTargetPlatform();
        // #endif

        SE_SET_RVAL(se::Value((int32_t)platform));
    }
}
SE_FUNC_END

SE_FUNC_BEGIN(JSBCore_version, se::DONT_NEED_THIS)
{
    if (argc!=0)
    {
        SE_REPORT_ERROR("Invalid number of arguments in __getVersion");
    }
    else
    {
        char version[256];
        snprintf(version, sizeof(version)-1, "%s", cocos2dVersion());

        SE_SET_RVAL(se::Value(version));
    }
}
SE_FUNC_END

SE_FUNC_BEGIN(JSBCore_os, se::DONT_NEED_THIS)
{
    if (argc!=0)
    {
        SE_REPORT_ERROR("Invalid number of arguments in __getOS");
        return false;
    }

    se::Value os;

    // osx, ios, android, windows, linux, etc..
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    os.setString("iOS");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    os.setString("Android");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    os.setString("Windows");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
    os.setString("Marmalade");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    os.setString("Linux");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BADA)
    os.setString("Bada");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
    os.setString("Blackberry");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    os.setString("OS X");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    os.setString("WINRT");
#else
    os.setString("Unknown");
#endif

    SE_SET_RVAL(os);
}
SE_FUNC_END

SE_FUNC_BEGIN(JSB_cleanScript, se::DONT_NEED_THIS)
{
    assert(false);
}
SE_FUNC_END

SE_FUNC_BEGIN(JSB_core_restartVM, se::DONT_NEED_THIS)
{
    assert(false);
}
SE_FUNC_END

SE_FUNC_BEGIN(JSB_closeWindow, se::DONT_NEED_THIS)
{
    assert(false);
}
SE_FUNC_END

SE_FUNC_BEGIN(JSB_isObjectValid, se::DONT_NEED_THIS)
{
    SE_SET_RVAL(se::Value(true));
}
SE_FUNC_END

static bool getOrCreatePlainObject_r(const char* name, se::Object* parent, se::Object** outObj)
{
    assert(parent != nullptr);
    assert(outObj != nullptr);
    se::Value tmp;

    if (parent->getProperty(name, &tmp) && tmp.isObject())
    {
        *outObj = tmp.toObject();
        (*outObj)->addRef();
    }
    else
    {
        *outObj = se::Object::createPlainObject(false);
        parent->setProperty(name, se::Value(*outObj));
    }

    return true;
}

bool jsb_register_global_variables()
{
    auto global = se::ScriptEngine::getInstance()->getGlobalObject();

    global->defineFunction("require", require);

    getOrCreatePlainObject_r("cc", global, &__ccObj);

    jsb_register_var_under_cc();

    getOrCreatePlainObject_r("jsb", global, &__jsbObj);
    getOrCreatePlainObject_r("__jsc__", global, &__jscObj);

    __jscObj->defineFunction("garbageCollect", jsc_garbageCollect);

    global->defineFunction("__getPlatform", JSBCore_platform);
    global->defineFunction("__getOS", JSBCore_os);
    global->defineFunction("__getVersion", JSBCore_version);
    global->defineFunction("__restartVM", JSB_core_restartVM);
    global->defineFunction("__cleanScript", JSB_cleanScript);
    global->defineFunction("__isObjectValid", JSB_isObjectValid);
    global->defineFunction("close", JSB_closeWindow);

    return true;
}
