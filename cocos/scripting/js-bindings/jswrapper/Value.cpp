#include "Value.hpp"

namespace se {

    Value::Value()
    {
        _type = Type::Undefined;
    }

    Value::Value(Type type)
    {
        _type = type;
    }

    Value::Value(const Value& v)
    {

    }

    Value::Value(Value&& v)
    {

    }

    Value::~Value()
    {

    }

    Value& Value::operator=(const Value& v)
    {
        return *this;
    }

    Value& Value::operator=(Value&& v)
    {
        return *this;
    }

   	void Value::setUndefined()
    {

    }

   	void Value::setNull()
    {

    }

   	void Value::setBoolean(bool value)
    {

    }

   	void Value::setNumber(double value)
    {

    }

   	void Value::setString(const std::string& value)
    {

    }

   	void Value::setObject(Object* object)
    {

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

    void Value::reset()
    {

    }

} // namespace se {
