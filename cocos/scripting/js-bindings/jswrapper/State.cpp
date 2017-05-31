//
//  State.cpp
//  cocos2d_js_bindings
//
//  Created by guanghui on 5/27/17.
//
//

#include "State.hpp"
#include "Object.hpp"

namespace se {

/*
 void* _nativeThisObject;  //weak ref
 const ValueArray* _args; //weak ref
 uint16_t _argc;
 Object* _thisObject; //weak ref
 Value _retVal; //weak ref
 */

    State::State()
    : _nativeThisObject(nullptr)
    , _thisObject(nullptr)
    , _argc(0)
    , _args(nullptr)
    {
        
    }
    
    State::~State()
    {
        SAFE_RELEASE(_thisObject);
    }
    
    State::State(void* nativeThisObject)
    : _nativeThisObject(nativeThisObject)
    , _thisObject(nullptr)
    , _argc(0)
    , _args(nullptr)
    {
    }
    
    State::State(void* nativeThisObject,
                 const ValueArray& args,
                 uint16_t argc)
    : _nativeThisObject(nativeThisObject)
    , _thisObject(nullptr)
    , _argc(argc)
    , _args(&args)
    {
    }
    
    State::State(Object* thisObject, const ValueArray& args)
    : _nativeThisObject(nullptr)
    , _thisObject(thisObject)
    , _argc(0)
    , _args(&args)
    {
    }
    
    void* State::nativeThisObject() const
    {
        return _nativeThisObject;
    }

    const ValueArray& State::args() const
    {
        return *(_args);
    }

    Object* State::thisObject()
    {
        if (nullptr == _thisObject && nullptr != _nativeThisObject)
        {
            _thisObject = se::Object::getObjectWithPtr(_nativeThisObject);
        }
        assert(_thisObject != nullptr);
        return _thisObject;
    }
    
    uint16_t State::argc() const
    {
        return _argc;
    }
    
    Value& State::rval()
    {
        return _retVal;
    }
} // namespace se {
