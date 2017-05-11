#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_SM

#include "Base.h"

#include "../Value.hpp"

namespace se {

    namespace internal {

        void jsToSeArgs(JSContext* cx, int argc, const JS::CallArgs& argv, ValueArray* outArr);
        void jsToSeValue(JSContext *cx, JS::HandleValue jsval, Value* v);
        void seToJsArgs(JSContext* cx, const ValueArray& args, JS::AutoValueVector* outArr);
        void seToJsValue(JSContext* cx, const Value& v, JS::MutableHandleValue outVal);
        
        void setReturnValue(JSContext* cx, const Value& data, const JS::CallArgs& argv);

        bool hasPrivate(JSObject* obj);

    } // namespace internal {
} // namespace se {

#endif // #ifdef SCRIPT_ENGINE_SM
