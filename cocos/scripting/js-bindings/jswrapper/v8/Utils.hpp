#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_V8

#include "Base.h"
#include "../Value.hpp"

namespace se {

    namespace internal {

        void jsToSeArgs(const v8::FunctionCallbackInfo<v8::Value>& _v8args, ValueArray* outArr);
        void seToJsArgs(v8::Isolate* isolate, const ValueArray& args, std::vector<v8::Local<v8::Value>>* outArr);
        void seToJsValue(const v8::PropertyCallbackInfo<void> &info, const v8::Local<v8::Value>& jsval, Value* v);

        void setReturnValue(const Value& data, const v8::FunctionCallbackInfo<v8::Value>& argv);
        void setReturnValue(const Value& data, const v8::PropertyCallbackInfo<v8::Value>& argv);

        bool hasPrivate(v8::Local<v8::Value> value);

    } // namespace internal {
} // namespace se {

#endif // #ifdef SCRIPT_ENGINE_V8
