#pragma once

#include <vector>
#include <string>

namespace se {

    class Object;

    class Value
    {
    public:
        enum class Type
        {
            Undefined = 0,
            Null,
            Number,
            Boolean,
            String,
            Object
        };

        Value();
        Value(Type type);
        Value(const Value& v);
        Value(Value&& v);

        Value(bool v);
        Value(double v);
        Value(const std::string& v);
        Value(Object* o);

        ~Value();

        Value& operator=(const Value& v);
        Value& operator=(Value&& v);

        void setUndefined();
        void setNull();
        void setBoolean(bool v);
        void setNumber(double v);
        void setString(const std::string& v);
        void setObject(Object* o);

        double toNumber() const;
        bool toBoolean() const;
        const std::string& toString() const;
        Object* toObject() const;

        inline Type getType() const { return _type; }
        inline bool isNumber() const { return _type == Type::Number; }
        inline bool isString() const { return _type == Type::String; }
        inline bool isObject() const { return _type == Type::Object; }
        inline bool isBoolean() const { return _type == Type::Boolean; }
        inline bool isUndefined() const { return _type == Type::Undefined; }
        inline bool isNull() const { return _type == Type::Null; }

    private:

        void reset();

        Type _type;

        union {
            bool _boolean;
            double _number;
            std::string* _string;
            Object* _object;
        } _u;
    };

    using ValueArray = std::vector<Value>;

} // namespace se {
