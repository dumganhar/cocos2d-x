//
//  Utils.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 4/26/17.
//
//

#include "Utils.hpp"

#ifdef SCRIPT_ENGINE_CHAKRACORE11

#include "Object.hpp"

namespace se { namespace internal {

    void jsToSeArgs(JSContextRef cx, int argc, const JSValueRef* argv, ValueArray* outArr)
    {
        outArr->reserve(argc);
        for (int i = 0; i < argc; ++i)
        {
            Value v;
            jsToSeValue(cx, argv[i], &v);
            outArr->push_back(v);
        }
    }

    void seToJsArgs(JSContextRef cx, const ValueArray& args, JSValueRef* outArr)
    {
        for (size_t i = 0, len = args.size(); i < len; ++i)
        {
            seToJsValue(cx, args[i], &outArr[i]);
        }
    }

    void jsToSeValue(JSContextRef cx, JSValueRef jsValue, Value* data)
    {
        if (JSValueIsNull(cx, jsValue))
        {
            data->setNull();
        }
        else if (JSValueIsUndefined(cx, jsValue))
        {
            data->setUndefined();
        }
        else if (JSValueIsNumber(cx, jsValue))
        {
            data->setNumber(JSValueToNumber(cx, jsValue, nullptr));
        }
        else if (JSValueIsBoolean(cx, jsValue))
        {
            data->setBoolean(JSValueToBoolean(cx, jsValue));
        }
        else if (JSValueIsString(cx, jsValue))
        {
            std::string str;
            forceConvertJsValueToStdString(cx, jsValue, &str);
            data->setString(str);
        }
        else if (JSValueIsObject(cx, jsValue))
        {
            Object* obj = Object::_createJSObject(nullptr, JSValueToObject(cx, jsValue, nullptr), true);
            data->setObject(obj);
            obj->release();
        }
        else
        {
            assert(false);
        }
    }

    void seToJsValue(JSContextRef cx, const Value& v, JSValueRef* jsval)
    {
        switch (v.getType()) {
            case Value::Type::Null:
                *jsval = JSValueMakeNull(cx);
                break;

            case Value::Type::Number:
                *jsval = JSValueMakeNumber(cx, v.toNumber());
                break;

            case Value::Type::String:
            {
                JSStringRef str = JSStringCreateWithUTF8CString(v.toString().c_str());
                *jsval = JSValueMakeString(cx, str);
                JSStringRelease(str);
            }
                break;

            case Value::Type::Boolean:
                *jsval = JSValueMakeBoolean(cx, v.toBoolean());
                break;

            case Value::Type::Object:
                *jsval = v.toObject()->_getJSObject();
                break;
                
            default: // Undefined
                *jsval = JSValueMakeUndefined(cx);
                break;
        }
    }

    void forceConvertJsValueToStdString(JSContextRef cx, JSValueRef jsval, std::string* ret)
    {
        JSStringRef jsstr = JSValueToStringCopy(cx, jsval, nullptr);
        jsStringToStdString(cx, jsstr, ret);
        JSStringRelease(jsstr);
    }

    void jsStringToStdString(JSContextRef cx, JSStringRef jsStr, std::string* ret)
    {
        size_t len = JSStringGetLength(jsStr);
        const size_t BUF_SIZE = len * 4 + 1;
        char* buf = (char*)malloc(BUF_SIZE);
        memset(buf, 0, BUF_SIZE);
        JSStringGetUTF8CString(jsStr, buf, BUF_SIZE);
        *ret = buf;
        free(buf);
    }

    bool hasPrivate(JsValueRef obj)
    {
        return JSObjectGetPrivate(obj) != nullptr;
    }


}} // namespace se { namespace internal {

#endif // #ifdef SCRIPT_ENGINE_CHAKRACORE
