//
//  Utils.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 4/26/17.
//
//

#include "Utils.hpp"

#ifdef SCRIPT_ENGINE_CHAKRACORE

#include "Object.hpp"

namespace se { namespace internal {

    void jsToSeArgs(int argc, const JsValueRef* argv, ValueArray* outArr)
    {
        outArr->reserve(argc);
        for (int i = 0; i < argc; ++i)
        {
            Value v;
            jsToSeValue(argv[i], &v);
            outArr->push_back(v);
        }
    }

    void seToJsArgs(const ValueArray& args, JsValueRef* outArr)
    {
        for (size_t i = 0, len = args.size(); i < len; ++i)
        {
            seToJsValue(args[i], &outArr[i]);
        }
    }

    void jsToSeValue(JsValueRef jsValue, Value* data)
    {
        JsValueType type;
        JsGetValueType(jsValue, &type);

        if (type == JsNull)
        {
            data->setNull();
        }
        else if (type == JsUndefined)
        {
            data->setUndefined();
        }
        else if (type == JsNumber)
        {
            double v = 0.0;
            JsNumberToDouble(jsValue, &v);
            data->setNumber(v);
        }
        else if (type == JsBoolean)
        {
            bool v = false;
            JsBooleanToBool(jsValue, &v);
            data->setBoolean(v);
        }
        else if (type == JsString)
        {
            std::string str;
            forceConvertJsValueToStdString(jsValue, &str);
            data->setString(str);
        }
        else if (type == JsObject || type == JsFunction)
        {
            Object* obj = Object::_createJSObject(nullptr, jsValue, true);
            data->setObject(obj);
            obj->release();
        }
        else
        {
            assert(false);
        }
    }

    void seToJsValue(const Value& v, JsValueRef* jsval)
    {
        switch (v.getType()) {
            case Value::Type::Null:
                JsGetNullValue(jsval);
                break;

            case Value::Type::Number:
                JsDoubleToNumber(v.toNumber(), jsval);
                break;

            case Value::Type::String:
            {
                JsCreateString(v.toString().c_str(), v.toString().length(), jsval);
            }
                break;

            case Value::Type::Boolean:
                JsBoolToBoolean(v.toBoolean(), jsval);
                break;

            case Value::Type::Object:
                *jsval = v.toObject()->_getJSObject();
                break;
                
            default: // Undefined
                JsGetUndefinedValue(jsval);
                break;
        }
    }

    void forceConvertJsValueToStdString(JsValueRef jsval, std::string* ret)
    {
        JsValueRef strVal = JS_INVALID_REFERENCE;
        JsConvertValueToString(jsval, &strVal);
        jsStringToStdString(strVal, ret);
    }

    void jsStringToStdString(JsValueRef strVal, std::string* ret)
    {
        // Get the buffer size
        size_t bufSize = 0;
        JsCopyString(strVal, nullptr, 0, &bufSize);
        // Allocate buffer
        char* buf = (char*)malloc(bufSize + 1);
        memset(buf, 0, bufSize + 1);
        // Copy
        JsCopyString(strVal, buf, bufSize, nullptr);
        *ret = buf;
        free(buf);
    }

    bool hasPrivate(JsValueRef obj)
    {
        void* nativeObj = nullptr;
        JsGetExternalData(obj, &nativeObj);
        return nativeObj != nullptr;
    }


}} // namespace se { namespace internal {

#endif // #ifdef SCRIPT_ENGINE_CHAKRACORE
