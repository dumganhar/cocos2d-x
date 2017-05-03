/*
 * Copyright (c) 2017 Chukong Technologies Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "scripting/js-bindings/manual/ScriptingCore.h"
#include "scripting/js-bindings/jswrapper/SeApi.h"

#include "cocos2d.h"

using namespace cocos2d;

ScriptingCore* ScriptingCore::getInstance()
{
    static ScriptingCore* instance = nullptr;
    if (instance == nullptr)
        instance = new (std::nothrow) ScriptingCore();

    return instance;
}

ScriptingCore::ScriptingCore()
: _callFromScript(false)
{

}

ScriptingCore::~ScriptingCore()
{

}

// Override functions

void ScriptingCore::retainScriptObject(Ref* owner, Ref* target)
{
    se::ScriptEngine::getInstance()->_retainScriptObject(owner, target);
}

void ScriptingCore::rootScriptObject(Ref* target)
{

}

void ScriptingCore::releaseScriptObject(Ref* owner, Ref* target)
{
    se::ScriptEngine::getInstance()->_releaseScriptObject(owner, target);
}

void ScriptingCore::unrootScriptObject(Ref* target)
{

}

void ScriptingCore::releaseAllChildrenRecursive(Node *node)
{

}

void ScriptingCore::releaseAllNativeRefs(Ref* owner)
{

}

void ScriptingCore::removeScriptObjectByObject(Ref* obj)
{

}

int ScriptingCore::executeGlobalFunction(const char* functionName)
{
    return 0;
}

int ScriptingCore::sendEvent(cocos2d::ScriptEvent* message)
{
    return 0;
}

bool ScriptingCore::parseConfig(ConfigType type, const std::string& str)
{
    return false;
}

