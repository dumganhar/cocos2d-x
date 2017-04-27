#pragma once

#include "config.hpp"

#ifdef SCRIPT_ENGINE_SM

#include "Base.h"
#include "Value.hpp"

namespace se {

    class Class;

    class Object
    {
    public:
        Object(JSContext* cx, JSObject* obj);
        Object(Object* obj);
        ~Object();

        // --- Getter/Setter
        bool get(const char *name,  Value *data );
        void set(const char *name,  Value& data );	

        JS::Value* getSMValue() { return m_rawValue; }

        // --- Function
        bool isFunction() { return JS_ObjectIsFunction( m_cx, &m_rawValue->toObject() ); }
        bool call(const ValueArray& args, Object* thisObject, Value* rval = nullptr);

        bool registerFunction(const char *funcName, JSNative func, int minArgs=0 );


        // ---
        Object *copy();

        // --- TypedArrays
        bool isTypedArray() { return JS_IsTypedArrayObject( &m_rawValue->toObject() ); }
        void getAsUint8Array( unsigned char **ptr, unsigned int *length ) { 
            uint8_t *pt; uint32_t len;
            bool isSharedMemory = false;
            JS_GetObjectAsUint8Array(  &m_rawValue->toObject(), &len, &isSharedMemory, &pt );
            *ptr=pt; *length=len;
        }
        void getAsUint16Array( unsigned short **ptr, unsigned int *length ) { 
            unsigned short *pt; unsigned int len;
            bool isSharedMemory = false;
            JS_GetObjectAsUint16Array(  &m_rawValue->toObject(), &len, &isSharedMemory, &pt );
            *ptr=pt; *length=len;
        }	
        void getAsUint32Array( unsigned int **ptr, unsigned int *length ) { 
            unsigned int *pt; unsigned int len;
            bool isSharedMemory = false;
            JS_GetObjectAsUint32Array(  &m_rawValue->toObject(), &len, &isSharedMemory, &pt );
            *ptr=pt; *length=len;
        }		
        void getAsFloat32Array( float **ptr, unsigned int *length ) { 
            float *pt; unsigned int len;
            bool isSharedMemory = false;
            JS_GetObjectAsFloat32Array(  &m_rawValue->toObject(), &len, &isSharedMemory, &pt );
            *ptr=pt; *length=len;
        }	

        // --- Arrays
        bool isArray() {
            JS::RootedValue value( m_cx, *m_rawValue );
            bool isArray = false;
            return JS_IsArrayObject( m_cx, value, &isArray ) && isArray;
        }
        void getArrayLength( unsigned int *length );
        void getArrayElement( unsigned int index, Value *data );

        // --- Private
        void *getPrivate() { return JS_GetPrivate( &m_rawValue->toObject() ); }

    private:
        JSContext               *m_cx;
        JS::Value               *m_rawValue;
    };

} // namespace se {

#endif // SCRIPT_ENGINE_SM

