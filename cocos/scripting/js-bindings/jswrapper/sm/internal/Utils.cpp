//
//  Utils.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 4/26/17.
//
//

#include "Utils.hpp"
#include "Object.hpp"

namespace se { namespace internal {

    void jsToSeArgs(JSContext* cx, int argc, const JS::CallArgs& argv, ValueArray* outArr)
    {
        for (int i = 0; i < argc; ++i)
        {
            const JS::Value& v = argv[i];
            if (v.isNumber())
            {
                outArr->push_back(Value(v.toNumber()));
            }
            else if (v.isString())
            {
                JSString *jsstring = v.toString();
                const char* jsstr = JS_EncodeString( cx, jsstring );
                outArr->push_back(Value(jsstr));
                JS_free(cx, (void*)jsstr);
            }
            else if (v.isBoolean())
            {
                outArr->push_back(Value(v.toBoolean()));
            }
            else if (v.isObject())
            {
                Object* object = nullptr;
                void* nativeObj = JS_GetPrivate(v.toObjectOrNull());
                if (nativeObj != nullptr)
                {
                    object = se::Object::getObjectWithPtr(nativeObj);
                }
                if (object == nullptr)
                {
                    object = new Object(&v.toObject(), true);
                }
                outArr->push_back(Value(object));
                object->release();
            }
            else if (v.isNull())
            {
                outArr->push_back(Value::Null);
            }
            else
            {
                outArr->push_back(Value::Undefined);
            }
        }
    }

    void seToJsArgs(JSContext* cx, const ValueArray& args, JS::AutoValueVector* outArr)
    {
        for (const auto& arg : args)
        {
            switch( arg.getType())
            {
                case Value::Type::Number:
                {
                    JS::RootedValue value(cx);
                    value.setDouble(arg.toNumber());
                    outArr->append(value);
                }
                    break;

                case Value::Type::String:
                {
                    JSString *string = JS_NewStringCopyN(cx, arg.toString().c_str(), arg.toString().length());
                    JS::RootedValue value(cx); value.setString( string);
                    outArr->append(value);
                }
                    break;

                case Value::Type::Boolean:
                {
                    JS::RootedValue value(cx);
                    value.setBoolean(arg.toBoolean());
                    outArr->append(value);
                }
                    break;

                case Value::Type::Object:
                {
                    JS::RootedValue value(cx, JS::ObjectValue(*arg.toObject()->_getJSObject()));
                    outArr->append(value);
                }
                    break;

                case Value::Type::Null:
                {
                    JS::RootedValue value(cx);
                    value.setNull();
                    outArr->append(value);
                }
                    break;

                default:
                {
                    JS::RootedValue value(cx);
                    value.setUndefined();
                    outArr->append(value);
                }
                    break;

            }
        }
    }

    // --- Fills in an Value from an SM Property

    void seToJsValue(JSContext *cx, const JS::Value& jsval, Value* v)
    {
        if (jsval.isNumber())
        {
            v->setNumber(jsval.toNumber());
        }
        else if (jsval.isString())
        {
            JSString* jsstr = jsval.toString();
            char* str = JS_EncodeString( cx, jsstr );
            v->setString(str);
            JS_free(cx, str);
        }
        else if (jsval.isBoolean())
        {
            v->setBoolean(jsval.toBoolean());
        }
        else if (jsval.isObject())
        {
            Object* obj = new Object(&jsval.toObject(), true);
            v->setObject(obj);
            obj->release();
        }
        else if (jsval.isNull())
        {
            v->setNull();
        }
        else
        {
            v->setUndefined();
        }
    }

    // --- Sets the return value for a function

    void setReturnValue(JSContext* cx, const Value& data, const JS::CallArgs& argv)
    {
        switch (data.getType()) {
            case Value::Type::Null:
                argv.rval().setNull();
                break;
            case Value::Type::Number:
                argv.rval().setNumber(data.toNumber());
                break;
            case Value::Type::String:
            {
                JSString* jsstr = JS_NewStringCopyN( cx, data.toString().c_str(), data.toString().length());
                argv.rval().setString(jsstr);
            }
                break;
            case Value::Type::Boolean:
                argv.rval().setBoolean(data.toBoolean());
                break;
            case Value::Type::Object:
                argv.rval().setObject(*data.toObject()->_getJSObject());
                break;
            default:
                argv.rval().setUndefined();
                break;
        }
    }


}} // namespace se { namespace internal {
