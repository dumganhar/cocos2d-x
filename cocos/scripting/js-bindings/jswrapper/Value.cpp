#include "Value.hpp"
#include "Object.hpp"

namespace se {

    ValueArray EmptyValueArray;

    Value Value::Null = Value(Type::Null);
    Value Value::Undefined = Value(Type::Undefined);

    Value::Value()
    : _type(Type::Undefined)
    {
    }

    Value::Value(Type type)
    : _type(Type::Undefined)
    {
        reset(type);
    }

    Value::Value(const Value& v)
    : _type(Type::Undefined)
    {
        *this = v;
    }

    Value::Value(Value&& v)
    : _type(Type::Undefined)
    {
        *this = std::move(v);
    }

    Value::Value(bool v)
    : _type(Type::Undefined)
    {
        setBoolean(v);
    }

    Value::Value(double v)
    : _type(Type::Undefined)
    {
        setNumber(v);
    }

    Value::Value(const char* v)
    : _type(Type::Undefined)
    {
        setString(v);
    }

    Value::Value(const std::string& v)
    : _type(Type::Undefined)
    {
        setString(v);
    }

    Value::Value(Object* o)
    : _type(Type::Undefined)
    {
        setObject(o);
    }

    Value::~Value()
    {
        reset(Type::Undefined);
    }

    Value& Value::operator=(const Value& v)
    {
        if (this != &v)
        {
            reset(v.getType());

            switch (_type) {
                case Type::Null:
                    break;
                case Type::Number:
                    _u._number = v._u._number;
                    break;
                case Type::String:
                    *_u._string = *v._u._string;
                    break;
                case Type::Boolean:
                    _u._boolean = v._u._boolean;
                    break;
                case Type::Object:
                    _u._object = v._u._object;
                    _u._object->addRef();
                    break;
                default:
                    break;
            }
        }
        return *this;
    }

    Value& Value::operator=(Value&& v)
    {
        if (this != &v)
        {
            reset(v.getType());

            switch (_type) {
                case Type::Null:
                    break;
                case Type::Number:
                    _u._number = v._u._number;
                    break;
                case Type::String:
                    *_u._string = std::move(*v._u._string);
                    break;
                case Type::Boolean:
                    _u._boolean = v._u._boolean;
                    break;
                case Type::Object:
                    _u._object = v._u._object;
                    v._u._object = nullptr;
                    break;
                default:
                    break;
            }

            v.reset(Type::Undefined);
        }
        return *this;
    }

    Value& Value::operator=(bool v)
    {
        setBoolean(v);
        return *this;
    }

    Value& Value::operator=(double v)
    {
        setNumber(v);
        return *this;
    }

    Value& Value::operator=(const std::string& v)
    {
        setString(v);
        return *this;
    }

    Value& Value::operator=(Object* o)
    {
        setObject(o);
        return *this;
    }

   	void Value::setUndefined()
    {
        reset(Type::Undefined);
    }

   	void Value::setNull()
    {
        reset(Type::Null);
    }

   	void Value::setBoolean(bool v)
    {
        reset(Type::Boolean);
        _u._boolean = v;
    }

   	void Value::setNumber(double v)
    {
        reset(Type::Number);
        _u._number = v;
    }

    void Value::setString(const char* v)
    {
        reset(Type::String);
        *_u._string = v;
    }

   	void Value::setString(const std::string& v)
    {
        reset(Type::String);
        *_u._string = v;
    }

   	void Value::setObject(Object* object)
    {
        reset(Type::Object);
        if (_u._object != object)
        {
            SAFE_RELEASE(_u._object);
            _u._object = object;
            SAFE_ADD_REF(_u._object);
        }
    }

   	double Value::toNumber() const
    {
        return _u._number;
    }

   	bool Value::toBoolean() const
    {
        return _u._boolean;
    }

   	const std::string& Value::toString() const
    {
        return *_u._string;
    }

    Object* Value::toObject() const
    {
        return _u._object;
    }

    void Value::reset(Type type)
    {
        if (_type != type)
        {
            switch (_type) {
                case Type::Null:
                    break;
                case Type::Number:
                    break;
                case Type::Boolean:
                    break;
                case Type::String:
                    delete _u._string;
                    break;
                case Type::Object:
                    SAFE_RELEASE(_u._object);
                    break;
                default:
                    break;
            }

            memset(&_u, 0, sizeof(_u));

            switch (type) {
                case Type::Null:
                    break;
                case Type::Number:
                    break;
                case Type::Boolean:
                    break;
                case Type::String:
                    _u._string = new std::string();
                    break;
                case Type::Object:
                    break;
                default:
                    break;
            }
            _type = type;
        }
    }

} // namespace se {
