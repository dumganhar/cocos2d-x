/****************************************************************************
Copyright (c) 2016 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxEngineDataManager.h"
#include "platform/android/jni/JniHelper.h"
#include "base/CCDirector.h"
#include "base/CCEventDispatcher.h"
#include "base/CCEventType.h"
#include "2d/CCParticleSystem.h"
#include "audio/include/AudioEngine.h"

#include <jni.h>
#include <android/log.h>

#define LOG_TAG    "Java_org_cocos2dx_lib_Cocos2dxEngineDataManager.cpp"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#define JNI_FUNC_PREFIX(func) Java_org_cocos2dx_lib_Cocos2dxEngineDataManager_##func

using namespace cocos2d;

namespace {

const char* _className = "org/cocos2dx/lib/Cocos2dxEngineDataManager";

bool _isInitialized = false;

float _defaultAnimationInterval = -1.0f;

// std::function<void(int, int)> _continuousFrameLostConfigChangedListener = nullptr;
// std::function<void(int, float)> _lowFpsConfigChangedListener = nullptr;
// std::function<void(int)> _specialEffectLevelChangedListener = nullptr;

std::unordered_map<int/*level*/, float/*particlePercent*/> _levelParticleCountMap;
std::unordered_map<unsigned int /*Ref::_ID*/, int/*particleCount*/> _psIdCountMap;

/* last time frame lost cycle was calculated */
std::chrono::steady_clock::time_point _lastContinuousFrameLostUpdate;
std::chrono::steady_clock::time_point _lastFrameLost100msUpdate;

/* last time low fps cycle was calculated */
std::chrono::steady_clock::time_point _lastLowFpsUpdate;

int _continuousFrameLostCycle = 5000;
int _continuousFrameLostThreshold = 3;
int _continuousFrameLostCount = 0;
int _frameLostCounter = 0;

int _lowFpsCycle = 1000;
float _lowFpsThreshold = 0.3f;
int _lowFpsCounter = 0;

void lazyInitLevelParticleCountMap()
{
    if (_levelParticleCountMap.empty())
    {
        #define MAP_INSERT(k, v) _levelParticleCountMap.insert(std::make_pair(k, v))

        MAP_INSERT(0, 0.0f);
        MAP_INSERT(1, 0.2f);
        MAP_INSERT(2, 0.4f);
        MAP_INSERT(3, 0.6f);
        MAP_INSERT(4, 0.8f);
        MAP_INSERT(5, 1.0f);

        #undef MAP_INSERT
    }
}

} // namespace {

namespace cocos2d {

// calculates frame lost event
// static
void EngineDataManager::calculateFrameLost()
{
    auto director = Director::getInstance();

    if (_lowFpsThreshold > 0 && _continuousFrameLostThreshold > 0)
    {
        float animationInterval = director->getAnimationInterval();
        float frameRate = director->getFrameRate();

        float expectedFPS = 1.0f / animationInterval;
        float frameLostRate = (expectedFPS - frameRate) * animationInterval;
        if (frameLostRate > _lowFpsThreshold)
        {
            ++_frameLostCounter;
            ++_lowFpsCounter;
//            log("_frameLostCounter: %d, _lowFpsCounter=%d", _frameLostCounter, _lowFpsCounter);
        }
        
        auto now = std::chrono::steady_clock::now();
        float interval = std::chrono::duration_cast<std::chrono::microseconds>(now - _lastFrameLost100msUpdate).count() / 1000000.0f;
        if (interval > 0.1f)
        {
            _lastFrameLost100msUpdate = now;
            // check lost frame count
            if (_frameLostCounter > _continuousFrameLostThreshold)
            {
                _frameLostCounter = 0;
                ++_continuousFrameLostCount;
            }
        }
        
        interval = std::chrono::duration_cast<std::chrono::microseconds>(now - _lastContinuousFrameLostUpdate).count() / 1000000.0f;
        if (interval > (_continuousFrameLostCycle / 1000.0f))
        {
            _lastContinuousFrameLostUpdate = now;
            if (_continuousFrameLostCount > 0)
            {
                // notify continuous frame lost event to system
                notifyContinuousFrameLost(_continuousFrameLostCycle, _continuousFrameLostThreshold, _continuousFrameLostCount);

                log("continuous frame lost: %d", _continuousFrameLostCount);
                _continuousFrameLostCount = 0;
            }
        }
        
        interval = std::chrono::duration_cast<std::chrono::microseconds>(now - _lastLowFpsUpdate).count() / 1000000.0f;
        if (interval > (_lowFpsCycle / 1000.0f))
        {
            _lastLowFpsUpdate = now;
            if (_lowFpsCounter > 0)
            {
                // notify low fps event to system
                notifyLowFps(_lowFpsCycle, _lowFpsThreshold, _lowFpsCounter);
                log("low fps frame count: %d", _lowFpsCounter);
                _lowFpsCounter = 0;
            }
        }
    }
}

// static
void EngineDataManager::init()
{
    if (_isInitialized)
        return;

    lazyInitLevelParticleCountMap();

    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addCustomEventListener(Director::EVENT_AFTER_VISIT, [](EventCustom* event){
        calculateFrameLost();
    });

    dispatcher->addCustomEventListener(Director::EVENT_BEFORE_SET_NEXT_SCENE, [](EventCustom* event){
        log("previous node count: %d", Node::getTotalNodeCount());
        notifyGameStatus(GameStatus::SCENE_CHANGE, 8, 2);
    });

    dispatcher->addCustomEventListener(Director::EVENT_AFTER_SET_NEXT_SCENE, [](EventCustom* event){
        notifyGameStatus(GameStatus::IN_SCENE, 9, 8);
        log("current node count: %d", Node::getTotalNodeCount());
    });

    auto resetLastTime = [](){
        _lastFrameLost100msUpdate = std::chrono::steady_clock::now();
        _lastContinuousFrameLostUpdate = _lastFrameLost100msUpdate;
        _lastLowFpsUpdate = _lastFrameLost100msUpdate;
    };

    resetLastTime();

    dispatcher->addCustomEventListener(EVENT_COME_TO_FOREGROUND, [resetLastTime](EventCustom* event){
        resetLastTime();
    });

    notifyGameStatus(GameStatus::START, 10, 10);
    _isInitialized = true;
}

// static 
void EngineDataManager::destroy()
{

}

// static
void EngineDataManager::notifyGameStatus(GameStatus type, int cpuLevel, int gpuLevel)
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, _className, "notifyGameStatus", "(III)V"))
    {
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, (int)type, cpuLevel, gpuLevel);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

// static
void EngineDataManager::notifyContinuousFrameLost(int continueFrameLostCycle, int continueFrameLostThreshold, int times)
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, _className, "notifyContinuousFrameLost", "(III)V"))
    {
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, continueFrameLostCycle, continueFrameLostThreshold, times);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

// static
void EngineDataManager::notifyLowFps(int lowFpsCycle, float lowFpsThreshold, int frames)
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, _className, "notifyLowFps", "(IFI)V"))
    {
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, lowFpsCycle, lowFpsThreshold, frames);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

// static
// void EngineDataManager::setContinuousFrameLostConfigChangedListener(const std::function<void(int/*frameLostCycle*/, int/*threshold*/)>& listener)
// {
//     // _continuousFrameLostConfigChangedListener = listener;
// }

// // static
// void EngineDataManager::setLowFpsConfigChangedListener(const std::function<void(int/*lowFpsCycle*/, float/*threshold*/)>& listener)
// {
//     _lowFpsConfigChangedListener = listener;
// }

// // static
// void EngineDataManager::setSpecialEffectLevelChangedListener(const std::function<void(int/*level*/)>& listener)
// {
//     _specialEffectLevelChangedListener = listener;
// }

} // namespace cocos2d {


extern "C" {

JNIEXPORT void JNICALL JNI_FUNC_PREFIX(nativeOnQueryFps)(JNIEnv* env, jobject thiz, jintArray arrExpectedFps, jintArray arrRealFps)
{
    LOGD("nativeOnQueryFps");
    jsize arrLenExpectedFps = env->GetArrayLength(arrExpectedFps);
    jsize arrLenRealFps = env->GetArrayLength(arrRealFps);

    if (arrLenExpectedFps > 0 && arrLenRealFps > 0)
    {
        jboolean isCopy = JNI_FALSE;
        jint* expectedFps = env->GetIntArrayElements(arrExpectedFps, &isCopy);
        *expectedFps = (int)std::ceil(1.0f / cocos2d::Director::getInstance()->getAnimationInterval());
        env->ReleaseIntArrayElements(arrExpectedFps, expectedFps, 0);

        jint* realFps = env->GetIntArrayElements(arrRealFps, &isCopy);
        *realFps = (int)cocos2d::Director::getInstance()->getFrameRate();
        env->ReleaseIntArrayElements(arrRealFps, realFps, 0);
    }
    else
    {
        LOGE("Invalid array size, expectedFps.size=%d, realFps.size=%d", arrLenExpectedFps, arrLenRealFps);
    }
}

JNIEXPORT void JNICALL JNI_FUNC_PREFIX(nativeOnChangeContinuousFrameLostConfig)(JNIEnv* env, jobject thiz, jint continueFrameLostCycle, jint continueFrameLostThreshold)
{
    LOGD("nativeOnChangeContinuousFrameLostConfig, continueFrameLostCycle: %d, continueFrameLostThreshold: %d", continueFrameLostCycle, continueFrameLostThreshold);

    _continuousFrameLostCycle = continueFrameLostCycle;
    _continuousFrameLostThreshold = continueFrameLostThreshold;

    // if (_continuousFrameLostConfigChangedListener != nullptr)
    // {
    //     _continuousFrameLostConfigChangedListener(continueFrameLostCycle, continueFrameLostThreshold);
    // }
    // else
    // {
    //     LOGE("_continuousFrameLostConfigChangedListener == nullptr");
    // }
}

JNIEXPORT void JNICALL JNI_FUNC_PREFIX(nativeOnChangeLowFpsConfig)(JNIEnv* env, jobject thiz, jint lowFpsCycle, jfloat lowFpsThreshold)
{
    LOGD("nativeOnChangeLowFpsConfig, lowFpsCycle: %d, lowFpsThreshold: %f", lowFpsCycle, lowFpsThreshold);
    _lowFpsCycle = lowFpsCycle;
    _lowFpsThreshold = lowFpsThreshold;
    // if (_lowFpsConfigChangedListener != nullptr)
    // {
    //     _lowFpsConfigChangedListener(lowFpsCycle, lowFpsThreshold);
    // }
    // else
    // {
    //     LOGE("_lowFpsConfigChangedListener == nullptr");
    // }
}

JNIEXPORT void JNICALL JNI_FUNC_PREFIX(nativeOnChangeExpectedFps)(JNIEnv* env, jobject thiz, jint fps)
{
    LOGD("nativeOnChangeExpectedFps, fps: %d", fps);
    auto director = cocos2d::Director::getInstance();
    if (_defaultAnimationInterval < 0)
    {
        _defaultAnimationInterval = director->getAnimationInterval();
    }

    fps = std::min(fps, 60);
    if (fps > 0)
    {
        director->setAnimationInterval(1.0f/fps);
    }
    else if (fps == -1) // -1 means to reset to default FPS
    {
        if (_defaultAnimationInterval > 0)
        {
            director->setAnimationInterval(_defaultAnimationInterval);
        }
        else
        {
            LOGE("_defaultAnimationInterval <= 0");
        }
    }
}

JNIEXPORT void JNICALL JNI_FUNC_PREFIX(nativeOnChangeSpecialEffectLevel)(JNIEnv* env, jobject thiz, jint level)
{
    LOGD("nativeOnChangeSpecialEffectLevel, level: %d", level);
    // if (_specialEffectLevelChangedListener != nullptr)
    // {
    //     _specialEffectLevelChangedListener(level);
    // }
    // else
    // {
    //     LOGE("_specialEffectLevelChangedListener == nullptr");
    // }

    if (_levelParticleCountMap.find(level) == _levelParticleCountMap.end())
    {
        LOGE("Pass a wrong level value: %d, only 0 ~ 5 is supported!", level);
        return;
    }

    auto& particleSystems = cocos2d::ParticleSystem::getAllParticleSystems();
    if (particleSystems.empty())
    {
        LOGD("There isn't any ParticleSystem instance!");
        return;
    }

    std::vector<unsigned int> validIDs;
    validIDs.reserve(particleSystems.size());

    for (auto&& system : particleSystems)
    {
        if (_psIdCountMap.find(system->_ID) == _psIdCountMap.end())
        {
            _psIdCountMap.insert(std::make_pair(system->_ID, system->getTotalParticles()));
        }
        validIDs.push_back(system->_ID);

        int defaultParticleCount = _psIdCountMap[system->_ID];
        int expectedParticleCount = _levelParticleCountMap[level] * defaultParticleCount;

        LOGD("Set ParticleSystem(%p)'s total particle count from (%d) to (%d)", system, defaultParticleCount, expectedParticleCount);

        system->setTotalParticles(expectedParticleCount);
    }

    // Remove unused elements in _psIdCountMap
    std::vector<unsigned int> invalidIDs;
    for (const auto& e : _psIdCountMap)
    {
        auto iter = std::find(std::begin(validIDs), std::end(validIDs), e.first);
        if (iter == std::end(validIDs))
        {
            invalidIDs.push_back(e.first);
        }
    }

    for (unsigned int id : invalidIDs)
    {
        LOGD("Remove unused particle system id: %u", id);
        _psIdCountMap.erase(id);
    }
}

JNIEXPORT void JNICALL JNI_FUNC_PREFIX(nativeOnChangeMuteEnabled)(JNIEnv* env, jobject thiz, jboolean enabled)
{
    LOGD("nativeOnChangeMuteEnabled, enabled: %d", enabled);
    if (enabled)
    {
        cocos2d::experimental::AudioEngine::stopAll();
    }
}

} // extern "C" {
