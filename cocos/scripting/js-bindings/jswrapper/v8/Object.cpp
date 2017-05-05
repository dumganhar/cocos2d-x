#include "Object.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Class.hpp"

namespace se {

    namespace {
        v8::Isolate* __isolate = nullptr;
    }

    Object::Object(v8::Local<v8::Object> obj)
            : _obj(__isolate, obj) {
    }

    Object::~Object()
    {
    }

    /* static */
    void Object::setIsolate(v8::Isolate* isolate)
    {
        __isolate = isolate;
    }

    bool Object::get(const char *name, Value *data) {
        v8::HandleScope handle_scope(__isolate);

        v8::Local<v8::String> nameValue = v8::String::NewFromUtf8(__isolate, name, v8::NewStringType::kNormal).ToLocalChecked();
        v8::Local<v8::Value> result = _obj.Get(__isolate)->Get(nameValue);

        if (data) {
            if (result->IsNumber())
                data->setNumber(result->ToNumber()->Value());
            else if (result->IsString()) {
                v8::String::Utf8Value utf8(result);
                data->setString(*utf8);
            } else if (result->IsBoolean())
                data->setBoolean(result->ToBoolean()->Value());
            else if (result->IsObject())
                data->setObject(new Object(result->ToObject()));
            else if (result->IsFunction()) {
                printf("I'm function\n");
            } else if (result->IsNull())
                data->setNull();
            else data->setUndefined();
        }

        return true;
    }

    void Object::set(const char *name, Value &data) {
        v8::Local<v8::String> nameValue = v8::String::NewFromUtf8(__isolate, name, v8::NewStringType::kNormal).ToLocalChecked();

        if (data.getType() == Value::Type::Number) {
            v8::Local<v8::Value> value = v8::Number::New(__isolate, data.toNumber());
            _obj.Get(__isolate)->Set(nameValue, value);
        } else if (data.getType() == Value::Type::String) {
            v8::Local<v8::String> value = v8::String::NewFromUtf8(__isolate, data.toString().c_str(), v8::NewStringType::kNormal).ToLocalChecked();
            _obj.Get(__isolate)->Set(nameValue, value);
        } else if (data.getType() == Value::Type::Boolean) {
            v8::Local<v8::Value> value = v8::Boolean::New(__isolate, data.toBoolean());
            _obj.Get(__isolate)->Set(nameValue, value);
        } else if (data.getType() == Value::Type::Object) {
            _obj.Get(__isolate)->Set(nameValue, data.toObject()->_obj.Get(__isolate));
        } else if (data.getType() == Value::Type::Null) {
            _obj.Get(__isolate)->Set(nameValue, v8::Null(__isolate));
        } else _obj.Get(__isolate)->Set(nameValue, v8::Undefined(__isolate));
    }

    bool Object::isFunction() const
    {
        return _obj.Get(__isolate)->IsCallable();
    }

    bool Object::isTypedArray() const
    {
        return _obj.Get(__isolate)->IsTypedArray();
    }

    bool Object::isArray() const
    {
        return _obj.Get(__isolate)->IsArray();
    }

    void* Object::getPrivateData() const
    {
        return v8::Local<v8::External>::Cast(_obj.Get(__isolate)->GetInternalField(0))->Value();
    }

// --- Call Function

    bool Object::call(ValueArray *args, Object *object, Value *data) {
        int argc = 0;
        std::vector<v8::Local<v8::Value>> argv;
        if (args) {
            argc = args->size();
            fillArgs(&argv, args);
        }

        v8::Local<v8::Value> result = _obj.Get(__isolate)->CallAsFunction(object->_obj.Get(__isolate), argc, &argv[0]);

        if (data) {
            if (result->IsNumber())
                data->setNumber(result->ToNumber()->Value());
            else if (result->IsString()) {
                v8::String::Utf8Value utf8(result);
                data->setString(*utf8);
            } else if (result->IsBoolean())
                data->setBoolean(result->ToBoolean()->Value());
            else if (result->IsObject())
                data->setObject(new Object(result->ToObject()));
            else if (result->IsNull())
                data->setNull();
            else data->setUndefined();
        }

        return true;
    }

// --- Register Function

    bool Object::registerFunction(const char *funcName, void (*func)(const v8::FunctionCallbackInfo<v8::Value> &args)) {
        _obj.Get(__isolate)->Set(v8::String::NewFromUtf8(__isolate, funcName), v8::FunctionTemplate::New(__isolate, func)->GetFunction());
        return true;
    }

// --- Arrays

    void Object::getArrayLength(unsigned int *length) {
        int len = _obj.Get(__isolate)->Get(v8::String::NewFromUtf8(__isolate, "length"))->ToObject()->Int32Value();
        *length = len;
    }

    void Object::getArrayElement(unsigned int index, Value *data) {
        v8::Local<v8::Value> result = _obj.Get(__isolate)->Get(index);

        if (data) {
            if (result->IsNumber())
                data->setNumber(result->ToNumber()->Value());
            else if (result->IsString()) {
                v8::String::Utf8Value utf8(result);
                data->setString(*utf8);
            } else if (result->IsBoolean())
                data->setBoolean(result->ToBoolean()->Value());
            else if (result->IsObject())
                data->setObject(new Object(result->ToObject()));
            else if (result->IsNull())
                data->setNull();
            else data->setUndefined();
        }
    }

    void Object::getAsFloat32Array(float **ptr, unsigned int *length) {
        float *pt;
        unsigned int len;

        v8::Local<v8::Value> value = _obj.Get(__isolate);

        v8::Local<v8::Float32Array> myarr = _obj.Get(__isolate).As<v8::Float32Array>();
        len = myarr->Length();
        pt = (float *) ((char *) myarr->Buffer()->GetContents().Data() + myarr->ByteOffset());

        *length = len;
        *ptr = pt;
    }

    void Object::getAsUint8Array(unsigned char **ptr, unsigned int *length) {
        unsigned char *pt;
        unsigned int len;

        v8::Local<v8::Value> value = _obj.Get(__isolate);

        v8::Local<v8::Uint8Array> myarr = _obj.Get(__isolate).As<v8::Uint8Array>();

        len = myarr->Length();
        pt = (unsigned char *) myarr->Buffer()->GetContents().Data() + myarr->ByteOffset();

        *length = len;
        *ptr = pt;
    }

    void Object::getAsUint16Array(unsigned short **ptr, unsigned int *length) {
        unsigned short *pt;
        unsigned int len;

        v8::Local<v8::Value> value = _obj.Get(__isolate);

        v8::Local<v8::Uint16Array> myarr = _obj.Get(__isolate).As<v8::Uint16Array>();

        len = myarr->Length();
        pt = (unsigned short *) myarr->Buffer()->GetContents().Data();

        *length = len;
        *ptr = pt;
    }

    void Object::getAsUint32Array(unsigned int **ptr, unsigned int *length) {
        unsigned int *pt;
        unsigned int len;

        v8::Local<v8::Value> value = _obj.Get(__isolate);

        v8::Local<v8::Uint32Array> myarr = _obj.Get(__isolate).As<v8::Uint32Array>();

        len = myarr->Length();

        //ArrayBuffer::Contents float_c=pt=myarr->Buffer()->GetContents();
        pt = (unsigned int *) myarr->Buffer()->GetContents().Data();

        *length = len;
        *ptr = pt;
    }



} // namespace se {

#endif // SCRIPT_ENGINE_V8
