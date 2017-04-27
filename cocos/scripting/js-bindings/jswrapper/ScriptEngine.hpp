#pragma once

#include "config.hpp"

#ifdef SCRIPT_ENGINE_SM
 #include "sm/ScriptEngine.cpp"
#endif

#ifdef __JSWRAPPER_V8
 #include "v8/ScriptEngine.hpp"
#endif

