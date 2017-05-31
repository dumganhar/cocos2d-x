#pragma once

#include "Value.hpp"

namespace se {

    class Object;

    class State
    {
    public:
        State();
        ~State();
        State(void* nativeThisObject);
        State(Object* thisObject, const ValueArray& args);
        State(void* nativeThisObject,
              const ValueArray& args,
              uint16_t argc);
        
        void* nativeThisObject() const;
        const ValueArray& args() const;
        Object* thisObject();
        uint16_t argc() const;
        Value& rval();
    private:
        void* _nativeThisObject;  //weak ref
        Object* _thisObject; //weak ref
        uint16_t _argc;
        const ValueArray* _args; //weak ref
        Value _retVal; //weak ref
    };
}
