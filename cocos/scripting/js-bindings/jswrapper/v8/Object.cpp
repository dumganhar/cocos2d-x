#include "Object.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Class.hpp"

namespace se {

    Object::Object(v8::Isolate *isolate, v8::Local<v8::Object> obj)
            : m_isolate(isolate), m_obj(isolate, obj) {
    }

    Object::Object(Object *object)
            : m_isolate(object->m_isolate), m_obj(object->m_isolate, object->m_obj.Get(m_isolate)) {
    }

    Object *Object::copy() {
        Object *object = new Object(this);
        return object;
    }

// --- Getter/Setter

    bool Object::get(const char *name, Value *data) {
        v8::HandleScope handle_scope(m_isolate);

        v8::Local <v8::String> nameValue = v8::String::NewFromUtf8(m_isolate, name, v8::NewStringType::kNormal).ToLocalChecked();
        v8::Local<v8::Value> result = m_obj.Get(m_isolate)->Get(nameValue);

        if (data) {
            if (result->IsNumber())
                data->setNumber(result->ToNumber()->Value());
            else if (result->IsString()) {
                v8::String::Utf8Value utf8(result);
                data->setString(*utf8);
            } else if (result->IsBoolean())
                data->setBoolean(result->ToBoolean()->Value());
            else if (result->IsObject())
                data->setObject(new Object(m_isolate, result->ToObject()));
            else if (result->IsFunction()) {
                printf("I'm function\n");
            } else if (result->IsNull())
                data->setNull();
            else data->setUndefined();
        }

        return true;
    }

    void Object::set(const char *name, Value &data) {
        v8::Local <v8::String> nameValue = v8::String::NewFromUtf8(m_isolate, name, v8::NewStringType::kNormal).ToLocalChecked();

        if (data.getType() == Value::Type::Number) {
            v8::Local <v8::Value> value = v8::Number::New(m_isolate, data.toNumber());
            m_obj.Get(m_isolate)->Set(nameValue, value);
        } else if (data.getType() == Value::Type::String) {
            v8::Local <v8::String> value = v8::String::NewFromUtf8(m_isolate, data.toString().c_str(), v8::NewStringType::kNormal).ToLocalChecked();
            m_obj.Get(m_isolate)->Set(nameValue, value);
        } else if (data.getType() == Value::Type::Boolean) {
            v8::Local <v8::Value> value = v8::Boolean::New(m_isolate, data.toBoolean());
            m_obj.Get(m_isolate)->Set(nameValue, value);
        } else if (data.getType() == Value::Type::Object) {
            m_obj.Get(m_isolate)->Set(nameValue, data.toObject()->m_obj.Get(m_isolate));
        } else if (data.getType() == Value::Type::Null) {
            m_obj.Get(m_isolate)->Set(nameValue, v8::Null(m_isolate));
        } else m_obj.Get(m_isolate)->Set(nameValue, v8::Undefined(m_isolate));
    }

// --- Call Function

    bool Object::call(ValueArray *args, Object *object, Value *data) {
        int argc = 0;
        std::vector<v8::Local < v8::Value>> argv;
        if (args) {
            argc = args->size();
            fillArgs(&argv, args);
        }

        v8::Local <v8::Value> result = m_obj.Get(m_isolate)->CallAsFunction(object->m_obj.Get(m_isolate), argc, &argv[0]);

        if (data) {
            if (result->IsNumber())
                data->setNumber(result->ToNumber()->Value());
            else if (result->IsString()) {
                v8::String::Utf8Value utf8(result);
                data->setString(*utf8);
            } else if (result->IsBoolean())
                data->setBoolean(result->ToBoolean()->Value());
            else if (result->IsObject())
                data->setObject(new Object(m_isolate, result->ToObject()));
            else if (result->IsNull())
                data->setNull();
            else data->setUndefined();
        }

        return true;
    }

// --- Register Function

    bool Object::registerFunction(const char *funcName, void (*func)(const v8::FunctionCallbackInfo <v8::Value> &args)) {
        m_obj.Get(m_isolate)->Set(v8::String::NewFromUtf8(m_isolate, funcName), v8::FunctionTemplate::New(m_isolate, func)->GetFunction());
        return true;
    }

// --- Classes

    Class *Object::createClass(const char *className, v8::FunctionCallback ctor)
    {
        Class *wrapperClass = new Class(m_isolate, className, this, ctor);

        return wrapperClass;
    }

// --- Arrays

    void Object::getArrayLength(unsigned int *length) {
        int len = m_obj.Get(m_isolate)->Get(v8::String::NewFromUtf8(m_isolate, "length"))->ToObject()->Int32Value();
        *length = len;
    }

    void Object::getArrayElement(unsigned int index, Value *data) {
        v8::Local <v8::Value> result = m_obj.Get(m_isolate)->Get(index);

        if (data) {
            if (result->IsNumber())
                data->setNumber(result->ToNumber()->Value());
            else if (result->IsString()) {
                v8::String::Utf8Value utf8(result);
                data->setString(*utf8);
            } else if (result->IsBoolean())
                data->setBoolean(result->ToBoolean()->Value());
            else if (result->IsObject())
                data->setObject(new Object(m_isolate, result->ToObject()));
            else if (result->IsNull())
                data->setNull();
            else data->setUndefined();
        }
    }

    void Object::getAsFloat32Array(float **ptr, unsigned int *length) {
        float *pt;
        unsigned int len;

        v8::Local <v8::Value> value = m_obj.Get(m_isolate);

        v8::Local <v8::Float32Array> myarr = m_obj.Get(m_isolate).As<v8::Float32Array>();
        len = myarr->Length();
        pt = (float *) ((char *) myarr->Buffer()->GetContents().Data() + myarr->ByteOffset());

        *length = len;
        *ptr = pt;
    }

    void Object::getAsUint8Array(unsigned char **ptr, unsigned int *length) {
        unsigned char *pt;
        unsigned int len;

        v8::Local<v8::Value> value = m_obj.Get(m_isolate);

        v8::Local <v8::Uint8Array> myarr = m_obj.Get(m_isolate).As<v8::Uint8Array>();

        len = myarr->Length();
        pt = (unsigned char *) myarr->Buffer()->GetContents().Data() + myarr->ByteOffset();

        *length = len;
        *ptr = pt;
    }

    void Object::getAsUint16Array(unsigned short **ptr, unsigned int *length) {
        unsigned short *pt;
        unsigned int len;

        v8::Local<v8::Value> value = m_obj.Get(m_isolate);

        v8::Local <v8::Uint16Array> myarr = m_obj.Get(m_isolate).As<v8::Uint16Array>();

        len = myarr->Length();
        pt = (unsigned short *) myarr->Buffer()->GetContents().Data();

        *length = len;
        *ptr = pt;
    }

    void Object::getAsUint32Array(unsigned int **ptr, unsigned int *length) {
        unsigned int *pt;
        unsigned int len;

        v8::Local<v8::Value> value = m_obj.Get(m_isolate);

        v8::Local <v8::Uint32Array> myarr = m_obj.Get(m_isolate).As<v8::Uint32Array>();

        len = myarr->Length();

        //ArrayBuffer::Contents float_c=pt=myarr->Buffer()->GetContents();
        pt = (unsigned int *) myarr->Buffer()->GetContents().Data();

        *length = len;
        *ptr = pt;
    }

// --- Fill Arguments

    void Object::fillArgs(std::vector<v8::Local < v8::Value>> *vector, ValueArray *args) {
    for(int i = 0; i<args->size(); ++i ) {
    Value data = args->at(i);

    switch( data.

    getType()

    ) {
    case
    Value::Type::Number:
            vector
    ->
    push_back( v8::Number::New(m_isolate, data.toNumber()) );
    break;

    case

    Value::Type::String: {
        v8::Local <v8::String> valueString = v8::String::NewFromUtf8(m_isolate, data.toString().c_str(), v8::NewStringType::kNormal).ToLocalChecked();
        vector->push_back(valueString);
    }

    break;

    case
    Value::Type::Boolean:
            vector
    ->
    push_back( v8::Boolean::New(m_isolate, data.toBoolean()) );
    break;

    case
    Value::Type::Object:
            vector
    ->
    push_back( data
    .

    toObject() -> m_obj

    .
    Get( m_isolate )
    );
    break;

    case
    Value::Type::Null:
            vector
    ->
    push_back( v8::Null(m_isolate));
    break;

    case
    Value::Type::Undefined:
            vector
    ->
    push_back( v8::Undefined(m_isolate));
    break;
}
}
}

Object::~Object() {
}

} // namespace se {

#endif // SCRIPT_ENGINE_V8
