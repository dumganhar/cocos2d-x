#include "Utils.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Object.hpp"
#include "Class.hpp"

namespace se {

    namespace internal {

        void jsToSeArgs(const v8::FunctionCallbackInfo<v8::Value>& v8args, ValueArray* outArr)
        {
            for (int i = 0; i < v8args.Length(); i++)
            {
                v8::HandleScope handle_scope(v8args.GetIsolate());
                // todo: uses jsToSeValue
                if (v8args[i]->IsUndefined()) {
                    outArr->push_back(Value::Undefined);
                } else if (v8args[i]->IsNull()) {
                    outArr->push_back(Value::Null);
                } else if (v8args[i]->IsNumber()) {
                    outArr->push_back(Value(v8args[i]->ToNumber()->Value()));
                } else if (v8args[i]->IsString()) {
                    v8::String::Utf8Value utf8(v8args[i]);
                    outArr->push_back(Value(*utf8));
                } else if (v8args[i]->IsBoolean()) {
                    outArr->push_back(Value(v8args[i]->ToBoolean()->Value()));
                } else if (v8args[i]->IsObject()) {
                    Object *object = Object::_createJSObject(v8args[i]->ToObject(), false);
                    outArr->push_back(Value(object));
                    object->release();
                }
            }
        }

        void seToJsArgs(v8::Isolate* isolate, const ValueArray& args, std::vector<v8::Local<v8::Value>>* outArr)
        {
            for (const auto& data : args)
            {
                v8::Local<v8::Value> jsval;
                seToJsValue(isolate, data, &jsval);
                outArr->push_back(jsval);
            }
        }

        void seToJsValue(v8::Isolate* isolate, const Value& v, v8::Local<v8::Value>* outJsVal)
        {
            switch (v.getType())
            {
                case Value::Type::Number:
                    *outJsVal = v8::Number::New(isolate, v.toNumber());
                    break;
                case Value::Type::String:
                    *outJsVal = v8::String::NewFromUtf8(isolate, v.toString().c_str(), v8::NewStringType::kNormal).ToLocalChecked();
                    break;
                case Value::Type::Boolean:
                    *outJsVal = v8::Boolean::New(isolate, v.toBoolean());
                    break;
                case Value::Type::Object:
                    *outJsVal = v.toObject()->_getJSObject();
                    break;
                case Value::Type::Null:
                    *outJsVal = v8::Null(isolate);
                    break;
                case Value::Type::Undefined:
                    *outJsVal = v8::Undefined(isolate);
                    break;

                default:
                    assert(false);
                    break;
            }
        }

        void jsToSeValue(const v8::PropertyCallbackInfo<void> &info, const v8::Local<v8::Value>& jsval, Value* v)
        {
            v8::HandleScope handle_scope(info.GetIsolate());

            if (jsval->IsUndefined()) {
                v->setUndefined();
            } else if (jsval->IsNull()) {
                v->setNull();
            } else if (jsval->IsNumber()) {
                v->setNumber(jsval->ToNumber()->Value());
            } else if (jsval->IsString()) {
                v8::String::Utf8Value utf8(jsval);
                v->setString(std::string(*utf8));
            } else if (jsval->IsBoolean()) {
                v->setBoolean(jsval->ToBoolean()->Value());
            } else if (jsval->IsObject()) {
                Object* obj = Object::_createJSObject(jsval->ToObject(), false);
                v->setObject(obj);
                obj->release();
            }
        }

        template<typename T>
        void _setReturnValue(const Value& data, const T& argv)
        {
            if (data.getType() == Value::Type::Undefined) {
                argv.GetReturnValue().Set(v8::Undefined(argv.GetIsolate()));
            } else if (data.getType() == Value::Type::Null) {
                argv.GetReturnValue().Set(v8::Null(argv.GetIsolate()));
            } else if (data.getType() == Value::Type::Number) {
                argv.GetReturnValue().Set(v8::Number::New(argv.GetIsolate(), data.toNumber()));
            } else if (data.getType() == Value::Type::String) {
                v8::Local<v8::String> value = v8::String::NewFromUtf8(argv.GetIsolate(), data.toString().c_str(), v8::NewStringType::kNormal).ToLocalChecked();
                argv.GetReturnValue().Set(value);
            } else if (data.getType() == Value::Type::Boolean) {
                argv.GetReturnValue().Set(v8::Boolean::New(argv.GetIsolate(), data.toBoolean()));
            } else if (data.getType() == Value::Type::Object) {
                argv.GetReturnValue().Set(data.toObject()->_getJSObject());
            }
        }

        void setReturnValue(const Value& data, const v8::FunctionCallbackInfo<v8::Value>& argv)
        {
            _setReturnValue(data, argv);
        }

        void setReturnValue(const Value& data, const v8::PropertyCallbackInfo<v8::Value>& argv)
        {
            _setReturnValue(data, argv);
        }

        const char* KEY_PRIVATE_DATE = "__cc_private_data";

        bool hasPrivate(v8::Isolate* isolate, v8::Local<v8::Value> value)
        {
            v8::Local<v8::Object> obj = v8::Local<v8::Object>::Cast(value);
            int c =  obj->InternalFieldCount();
            if (c > 0)
                return true;

            // Pure JS subclass object doesn't have a internal field
            v8::Local<v8::String> key = v8::String::NewFromUtf8(isolate, KEY_PRIVATE_DATE, v8::NewStringType::kNormal).ToLocalChecked();
            return obj->Has(key);
        }

        void setPrivate(v8::Isolate* isolate, ObjectWrap& wrap, void* data)
        {
            v8::Local<v8::Object> obj = wrap.handle(isolate);
            int c =  obj->InternalFieldCount();
            if (c > 0)
            {
                wrap.wrap(data);
//                printf("setPrivate1: %p\n", data);
            }
            else
            {
                Object* privateObj = Object::createObject("__CCPrivateData", false);
                internal::PrivateData* privateData = (internal::PrivateData*)malloc(sizeof(internal::PrivateData));
                privateData->data = data;
                privateData->seObj = privateObj;

                privateObj->_getWrap().setFinalizeCallback(privateObj->_getClass()->_getFinalizeFunction());
                privateObj->_getWrap().wrap(privateData);

                v8::Local<v8::String> key = v8::String::NewFromUtf8(isolate, KEY_PRIVATE_DATE, v8::NewStringType::kNormal).ToLocalChecked();
                obj->Set(key, privateObj->_getJSObject());
//                printf("setPrivate: native data: %p\n", privateData);
//                privateObj->release();
            }
        }

        void* getPrivate(v8::Isolate* isolate, v8::Local<v8::Value> value)
        {
            v8::Local<v8::Object> obj = value->ToObject(isolate);
            int c =  obj->InternalFieldCount();
            if (c > 0)
            {
                void* nativeObj = ObjectWrap::unwrap(obj);
//                printf("getPrivate1: %p\n", nativeObj);
                return nativeObj;
            }

            // Pure JS subclass object doesn't have a internal field
            v8::Local<v8::String> key = v8::String::NewFromUtf8(isolate, KEY_PRIVATE_DATE, v8::NewStringType::kNormal).ToLocalChecked();

            if (obj->Has(key))
            {
                v8::Local<v8::Object> privateObj = obj->Get(key)->ToObject(isolate);
                internal::PrivateData* privateData =  (internal::PrivateData*)ObjectWrap::unwrap(privateObj);
//                printf("getPrivate: native data: %p\n", privateData);
                return privateData->data;
            }
            return nullptr;
        }

    } // namespace internal {
} // namespace se {

#endif // #ifdef SCRIPT_ENGINE_V8
