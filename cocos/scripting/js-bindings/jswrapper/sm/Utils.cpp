//
//  Utils.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 4/26/17.
//
//

#include "Utils.hpp"

#ifdef SCRIPT_ENGINE_SM

#include "Object.hpp"

namespace se { namespace internal {

    void jsToSeArgs(JSContext* cx, int argc, const JS::CallArgs& argv, ValueArray* outArr)
    {
        outArr->reserve(argc);
        for (int i = 0; i < argc; ++i)
        {
            Value v;
            jsToSeValue(cx, argv[i], &v);
            outArr->push_back(v);
        }
    }

    void seToJsArgs(JSContext* cx, const ValueArray& args, JS::AutoValueVector* outArr)
    {
        for (const auto& arg : args)
        {
            JS::RootedValue v(cx);
            seToJsValue(cx, arg, &v);
            outArr->append(v);
        }
    }

    void seToJsValue(JSContext* cx, const Value& arg, JS::MutableHandleValue outVal)
    {
        switch( arg.getType())
        {
            case Value::Type::Number:
            {
                JS::RootedValue value(cx);
                value.setDouble(arg.toNumber());
                outVal.set(value);
            }
                break;

            case Value::Type::String:
            {
                JSString *string = JS_NewStringCopyN(cx, arg.toString().c_str(), arg.toString().length());
                JS::RootedValue value(cx);
                value.setString( string);
                outVal.set(value);
            }
                break;

            case Value::Type::Boolean:
            {
                JS::RootedValue value(cx);
                value.setBoolean(arg.toBoolean());
                outVal.set(value);
            }
                break;

            case Value::Type::Object:
            {
                JS::RootedValue value(cx, JS::ObjectValue(*arg.toObject()->_getJSObject()));
                outVal.set(value);
            }
                break;

            case Value::Type::Null:
            {
                JS::RootedValue value(cx);
                value.setNull();
                outVal.set(value);
            }
                break;

            case Value::Type::Undefined:
            {
                JS::RootedValue value(cx);
                value.setUndefined();
                outVal.set(value);
            }
                break;
            default:
                assert(false);
                break;
        }
    }

    void jsToSeValue(JSContext *cx, JS::HandleValue jsval, Value* v)
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
            Object* object = nullptr;

            if (hasPrivate(jsval.toObjectOrNull()))
            {
                void* nativeObj = JS_GetPrivate(jsval.toObjectOrNull());
                object = se::Object::getObjectWithPtr(nativeObj);
            }

            if (object == nullptr)
            {
                object = Object::_createJSObject(jsval.toObjectOrNull(), true); //FIXME: ?? should root?
            }
            v->setObject(object);
            object->release();
        }
        else if (jsval.isNull())
        {
            v->setNull();
        }
        else if (jsval.isUndefined())
        {
            v->setUndefined();
        }
        else
        {
            assert(false);
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

    bool hasPrivate(JSObject* obj)
    {
        const JSClass* cls = JS_GetClass(obj);
        return !!(cls->flags & JSCLASS_HAS_PRIVATE);
    }


}} // namespace se { namespace internal {

#endif // #ifdef SCRIPT_ENGINE_SM
