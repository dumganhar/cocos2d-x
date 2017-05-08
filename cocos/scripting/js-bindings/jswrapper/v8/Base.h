#pragma once


#include "libplatform/libplatform.h"
#include "v8.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <assert.h>

#include "HelperMacros.h"


namespace se {
    using V8FinalizeFunc = void (*)(void* nativeObj);
}
