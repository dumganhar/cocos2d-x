#include "Object.hpp"
#include "internal/Utils.hpp"

#ifdef SCRIPT_ENGINE_SM

namespace se {

    // ------------------------------------------------------- Object

    Object::Object( JSContext *cx, JSObject *object) : m_cx( cx)
    {
        m_rawValue=new JS::Value( JS::ObjectValue( *object));
        js::AddRawValueRoot( m_cx, m_rawValue, "Protected_Object");    
    }

    Object::Object( Object *obj) : m_cx(obj->m_cx)
    {
        m_rawValue=new JS::Value( *obj->m_rawValue);
        js::AddRawValueRoot( m_cx, m_rawValue, "Protected_Object");    
    }

    Object::~Object()
    {
        if (m_rawValue) {
            js::RemoveRawValueRoot( m_cx, m_rawValue);
            delete m_rawValue;
        }
    }

    Object *Object::copy()
    {
        Object *object=new Object( this);
        return object;
    }

    // --- Getter/Setter

    bool Object::get(const char *name, Value *data)
    {
        JS::RootedObject object( m_cx, &m_rawValue->toObject());

        JS::RootedValue rcValue( m_cx);
        bool ok=JS_GetProperty( m_cx, object, name, &rcValue);

        if (data)
        {
            if (rcValue.isString())
            {
                JSString *jsstring = rcValue.toString();
                const char *stringData=JS_EncodeString( m_cx, jsstring);

                data->setString( stringData);
                JS_free( m_cx, (void *) stringData);
            }
            else if (rcValue.isNumber())
            {
                data->setNumber( rcValue.toNumber());
            }
            else if (rcValue.isBoolean())
            {
                data->setBoolean( rcValue.toBoolean());
            }
            else if (rcValue.isObject())
            {
                data->setObject( new Object( m_cx, &rcValue.toObject()));
            }
            else if (rcValue.isNull())
            {
                data->setNull();
            }
            else
            {
                data->setUndefined();
            }
        }

        return ok;
    }

    void Object::set(const char *name,  Value& data)
    {
        JS::RootedObject object( m_cx, &m_rawValue->toObject());

        if (data.getType() == Value::Type::Number)
        {
            JS::RootedValue value( m_cx);
            value.setDouble( data.toNumber());
            JS_SetProperty( m_cx, object, name, value);
        }
        else if (data.getType() == Value::Type::String)
        {
            JSString *string = JS_NewStringCopyN( m_cx, data.toString().c_str(), data.toString().length());
            JS::RootedValue value( m_cx);
            value.setString( string);
            JS_SetProperty( m_cx, object, name, value);
        }
        else if (data.getType() == Value::Type::Boolean)
        {
            JS::RootedValue value( m_cx);
            value.setBoolean( data.toBoolean());
            JS_SetProperty( m_cx, object, name, value);
        }
        else if (data.getType() == Value::Type::Object)
        {
            JS::RootedValue value( m_cx);
            value.setObject( data.toObject()->getSMValue()->toObject());
            JS_SetProperty( m_cx, object, name, value);
        }
        else if (data.getType() == Value::Type::Null)
        {
            JS::RootedValue value( m_cx);
            value.setNull();
            JS_SetProperty( m_cx, object, name, value);
        }
        else
        {
            JS::RootedValue value( m_cx);
            value.setUndefined();
            JS_SetProperty( m_cx, object, name, value);
        }
    }

    // --- call

    bool Object::call(const ValueArray& args, Object* thisObject, Value* rval/* = nullptr*/)
    {
        JS::AutoValueVector jsarr(m_cx);
        jsarr.reserve(args.size());
        internal::seToJsArgs(m_cx, args, &jsarr);

        JS::RootedObject contextObject( m_cx, &thisObject->getSMValue()->toObject());
        JS::RootedValue fun( m_cx, *m_rawValue);
        JS::RootedValue rcValue(m_cx);

        bool ok = JS::Call(m_cx, contextObject, fun, jsarr, &rcValue);

        if (rval != nullptr)
        {
            if (rcValue.isString())
            {
                JSString *jsstring = rcValue.toString();
                const char *stringData=JS_EncodeString( m_cx, jsstring);
                rval->setString( stringData);
                JS_free( m_cx, (void *) stringData);
            }
            else if (rcValue.isNumber())
            {
                rval->setNumber( rcValue.toNumber());
            }
            else if (rcValue.isBoolean())
            {
                rval->setBoolean( rcValue.toBoolean());
            }
            else if (rcValue.isObject())
            {
                rval->setObject( new Object( m_cx, &rcValue.toObject()));
            }
            else if (rcValue.isNull())
            {
                rval->setNull();
            }
            else
            {
                rval->setUndefined();
            }
        }

        return ok;    
    }

    // --- Register Function

    bool Object::registerFunction(const char *funcName, JSNative func, int minArgs)
    {
        JS::RootedObject object( m_cx, &m_rawValue->toObject());
        bool ok = JS_DefineFunction( m_cx, object, funcName, func, minArgs, 0);
        return ok;
    }

    // --- Arrays

    void Object::getArrayLength( unsigned int *length) 
    {
        unsigned int len;
        JS::RootedObject object( m_cx, &m_rawValue->toObject());
        JS_GetArrayLength( m_cx, object, &len);
        *length=len;
    }

    void Object::getArrayElement( unsigned int index, Value *data) 
    {
        JS::RootedObject object( m_cx, &m_rawValue->toObject());
        JS::RootedValue rcValue( m_cx);    
        JS_GetElement( m_cx, object, index, &rcValue);

        if (data)
        {
            if (rcValue.isString())
            {
                JSString *jsstring = rcValue.toString();
                const char *stringData=JS_EncodeString( m_cx, jsstring);

                data->setString( stringData);
                JS_free( m_cx, (void *) stringData);
            }
            else if (rcValue.isNumber())
            {
                data->setNumber( rcValue.toNumber());
            }
            else if (rcValue.isBoolean())
            {
                data->setBoolean( rcValue.toBoolean());
            }
            else if (rcValue.isObject())
            {
                data->setObject( new Object( m_cx, &rcValue.toObject()));
            }
            else if (rcValue.isNull())
            {
                data->setNull();
            }
            else
            {
                data->setUndefined();
            }
        }    
    }

    

} // namespace se {

#endif // SCRIPT_ENGINE_SM
