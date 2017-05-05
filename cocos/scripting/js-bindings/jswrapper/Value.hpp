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

        static Value Null;
        static Value Undefined;

        Value();
        Value(const Value& v);
        Value(Value&& v);

        explicit Value(bool v);
        explicit Value(double v);
        explicit Value(const char* v);
        explicit Value(const std::string& v);
        explicit Value(Object* o);

        ~Value();

        Value& operator=(const Value& v);
        Value& operator=(Value&& v);
        Value& operator=(bool v);
        Value& operator=(double v);
        Value& operator=(const char* v);
        Value& operator=(const std::string& v);
        Value& operator=(Object* o);

        void setUndefined();
        void setNull();
        void setBoolean(bool v);
        void setNumber(double v);
        void setString(const char* v);
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
        explicit Value(Type type);
        void reset(Type type);

        Type _type;

        union {
            bool _boolean;
            double _number;
            std::string* _string;
            Object* _object;
        } _u;
    };

    using ValueArray = std::vector<Value>;
    extern ValueArray EmptyValueArray;

} // namespace se {
