#pragma once

#include "Base.h"

#include "Value.hpp"

namespace se {

    namespace internal {

        void jsToSeArgs(JSContext* cx, int argc, const JS::CallArgs& argv, ValueArray* outArr);
        void seToJsArgs(JSContext* cx, const ValueArray& args, JS::AutoValueVector* outArr);
        void seToJsValue(JSContext *cx, const JS::Value& jsval, Value* v);
        
        void setReturnValue(JSContext *cx, Value value, const JS::CallArgs& argv);

    } // namespace internal {
} // namespace se {
