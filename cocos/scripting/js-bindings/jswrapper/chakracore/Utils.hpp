#pragma once

#include "../config.hpp"

#ifdef SCRIPT_ENGINE_CHAKRACORE

#include "Base.h"

#include "../Value.hpp"

namespace se {

    namespace internal {

        void jsToSeArgs(JSContextRef cx, int argc, const JSValueRef* argv, ValueArray* outArr);
        void seToJsArgs(JSContextRef cx, const ValueArray& args, JSValueRef* outArr);
        void jsToSeValue(JSContextRef cx, JSValueRef jsval, Value* v);
        void seToJsValue(JSContextRef cx, const Value& v, JSValueRef* jsval);

        void forceConvertJsValueToStdString(JSContextRef cx, JSValueRef jsval, std::string* ret);
        void jsStringToStdString(JSContextRef cx, JSStringRef jsStr, std::string* ret);

        bool hasPrivate(JsValueRef obj);

    } // namespace internal {
} // namespace se {

#endif // #ifdef SCRIPT_ENGINE_CHAKRACORE
