/****************************************************************************
 Copyright (c) 2014 Chukong Technologies Inc.
 
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

#define LOG_TAG "AudioCache"

#include "platform/CCPlatformConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC

#include "audio/apple/AudioCache.h"

#import <Foundation/Foundation.h>
#import <OpenAL/alc.h>
#import <AudioToolbox/ExtendedAudioFile.h>
#include <thread>
#include "base/CCDirector.h"
#include "base/CCScheduler.h"

#include "cocos/audio/openal/AudioFrameProviderFactory.h"
#include "cocos/audio/openal/AudioFrameBuffer.h"


#define VERY_VERY_VERBOSE_LOGGING
#ifdef VERY_VERY_VERBOSE_LOGGING
#define ALOGVV ALOGV
#else
#define ALOGVV(...) do{} while(false)
#endif

namespace {
unsigned int __idIndex = 0;
}

#define INVALID_AL_BUFFER_ID 0xFFFFFFFF
#define PCMDATA_CACHEMAXSIZE 1048576

typedef ALvoid	AL_APIENTRY	(*alBufferDataStaticProcPtr) (const ALint bid, ALenum format, ALvoid* data, ALsizei size, ALsizei freq);
static ALvoid  alBufferDataStaticProc(const ALint bid, ALenum format, ALvoid* data, ALsizei size, ALsizei freq)
{
    static alBufferDataStaticProcPtr proc = nullptr;
    
    if (proc == nullptr) {
        proc = (alBufferDataStaticProcPtr) alcGetProcAddress(nullptr, (const ALCchar*) "alBufferDataStatic");
    }
    
    if (proc){
        proc(bid, format, data, size, freq);
    }
	
    return;
}
using namespace cocos2d;
using namespace cocos2d::experimental;

AudioCache::AudioCache()
: _dataSize(0)
, _format(-1)
, _duration(0.0f)
, _bytesPerFrame(0)
, _alBufferId(INVALID_AL_BUFFER_ID)
, _pcmData(nullptr)
, _bytesOfRead(0)
, _queBufferFrames(0)
, _queBufferBytes(0)
, _state(State::INITIAL)
, _isDestroyed(std::make_shared<bool>(false))
, _id(++__idIndex)
, _isLoadingFinished(false)
, _isSkipReadDataTask(false)
{
    ALOGVV("AudioCache() %p, id=%u", this, _id);
    for (int i = 0; i < QUEUEBUFFER_NUM; ++i)
    {
        _queBuffers[i] = nullptr;
        _queBufferSize[i] = 0;
    }    
}

AudioCache::~AudioCache()
{
    ALOGVV("~AudioCache() %p, id=%u, begin", this, _id);
    *_isDestroyed = true;
    while (!_isLoadingFinished)
    {
        if (_isSkipReadDataTask)
        {
            ALOGV("id=%u, Skip read data task, don't continue to wait!", _id);
            break;
        }
        ALOGVV("id=%u, waiting readData thread to finish ...", _id);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    //wait for the 'readDataTask' task to exit
    _readDataTaskMutex.lock();
    _readDataTaskMutex.unlock();
    
    if (_pcmData)
    {
        if (_state == State::READY)
        {
            if (_alBufferId != INVALID_AL_BUFFER_ID && alIsBuffer(_alBufferId))
            {
                ALOGV("~AudioCache(id=%u), delete buffer: %u", _id, _alBufferId);
                alDeleteBuffers(1, &_alBufferId);
                _alBufferId = INVALID_AL_BUFFER_ID;
            }
        }
        else
        {
            ALOGW("AudioCache (%p), id=%u, buffer isn't ready, state=%d", this, _id, _state);
        }
        
        free(_pcmData);
    }
    
    if (_queBufferFrames > 0)
    {
        for (int index = 0; index < QUEUEBUFFER_NUM; ++index)
        {
            free(_queBuffers[index]);
        }
    }
    ALOGVV("~AudioCache() %p, id=%u, end", this, _id);
}

void AudioCache::readDataTask(unsigned int selfId)
{
    //Note: It's in sub thread
    ALOGVV("readDataTask, cache id=%u", selfId);
    
    _readDataTaskMutex.lock();
    _state = State::LOADING;
    
    
    auto provider = AudioFrameProviderFactory::getAudioFrameProvider(_fileFullPath);

    do
    {
        if (provider == nullptr) break;
        
        _dataSize = provider->getTotalFrames() * provider->getBytesPerFrame();
        _sampleRate = provider->getSampleRate();
        if (provider->getBytesPerFrame() == 2)
        {
            _format = AL_FORMAT_MONO16;
        }
        else if (provider->getBytesPerFrame() == 4)
        {
            _format = AL_FORMAT_STEREO16;
        }
        
        if (_dataSize <= PCMDATA_CACHEMAXSIZE)
        {
            _pcmData = (unsigned char*)malloc(_dataSize);
            memset(_pcmData, 0, _dataSize);
            
            alGenBuffers(1, &_alBufferId);
            
            auto alError = alGetError();
            if (alError != AL_NO_ERROR) {
                ALOGE("%s: attaching audio to buffer fail: %x", __PRETTY_FUNCTION__, alError);
                break;
            }
            
            if (*_isDestroyed) break;
            
            alBufferDataStaticProc(_alBufferId, _format, _pcmData, _dataSize, _sampleRate);
            
            int readInFrames = provider->getSampleRate() * QUEUEBUFFER_TIME_STEP * QUEUEBUFFER_NUM;
            bool toReadOnce = false;
            if (readInFrames > provider->getTotalFrames())
            {
                readInFrames = provider->getTotalFrames();
                toReadOnce = true;
            }
            
            AudioFrameBuffer ioFrame;
            ioFrame.frameCount = readInFrames;
            ioFrame.raw = (unsigned char*) _pcmData;
            provider->read(&ioFrame);
            
            _state = State::READY;
            
            invokingPlayCallbacks();
            
            if (!toReadOnce)
            {
                while (!*_isDestroyed)
                {
                    ioFrame.frameCount = readInFrames;
                    ioFrame.raw = _pcmData + (provider->tell() * provider->getBytesPerFrame());
                    
                    if (provider->read(&ioFrame) <= 0)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            _queBufferFrames = provider->getSampleRate() * QUEUEBUFFER_TIME_STEP;
            if (_queBufferFrames == 0)
                break;
            
            _queBufferBytes = _queBufferFrames * provider->getBytesPerFrame();
            
            AudioFrameBuffer ioFrame;
            
            for (int index = 0; index < QUEUEBUFFER_NUM; ++index) {
                _queBuffers[index] = (char*)malloc(_queBufferBytes);
                
                ioFrame.frameCount = _queBufferFrames;
                ioFrame.raw = (unsigned char*) _queBuffers[index];
                provider->read(&ioFrame);
                _queBufferSize[index] = ioFrame.frameCount * provider->getBytesPerFrame();
            }
            
            _state = State::READY;
        }
        
    } while (false);
    

    //FIXME: Why to invoke play callback first? Should it be after 'load' callback?
    invokingPlayCallbacks();
    invokingLoadCallbacks();
    
    _isLoadingFinished = true;
    if (_state != State::READY)
    {
        _state = State::FAILED;
        if (_alBufferId != INVALID_AL_BUFFER_ID && alIsBuffer(_alBufferId))
        {
            ALOGV("readDataTask failed, delete buffer: %u", _alBufferId);
            alDeleteBuffers(1, &_alBufferId);
            _alBufferId = INVALID_AL_BUFFER_ID;
        }
    }
    
    _readDataTaskMutex.unlock();
}

void AudioCache::addPlayCallback(const std::function<void()>& callback)
{
    std::lock_guard<std::mutex> lk(_playCallbackMutex);
    switch (_state)
    {
        case State::INITIAL:
        case State::LOADING:
            _playCallbacks.push_back(callback);
            break;
            
        case State::READY:
        // If state is failure, we still need to invoke the callback
        // since the callback will set the 'AudioPlayer::_removeByAudioEngine' flag to true.
        case State::FAILED:
            callback();
            break;
            
        default:
            ALOGE("Invalid state: %d", _state);
            break;
    }
}

void AudioCache::invokingPlayCallbacks()
{
    std::lock_guard<std::mutex> lk(_playCallbackMutex);
    
    for (auto&& cb : _playCallbacks)
    {
        cb();
    }
    
    _playCallbacks.clear();
}

void AudioCache::addLoadCallback(const std::function<void(bool)>& callback)
{
    switch (_state)
    {
        case State::INITIAL:
        case State::LOADING:
            _loadCallbacks.push_back(callback);
            break;
            
        case State::READY:
            callback(true);
            break;
        case State::FAILED:
            callback(false);
            break;
            
        default:
            ALOGE("Invalid state: %d", _state);
            break;
    }
}

void AudioCache::invokingLoadCallbacks()
{
    if (*_isDestroyed)
    {
        ALOGV("AudioCache (%p) was destroyed, don't invoke preload callback ...", this);
        return;
    }
    
    auto isDestroyed = _isDestroyed;
    auto scheduler = Director::getInstance()->getScheduler();
    scheduler->performFunctionInCocosThread([&, isDestroyed](){
        if (*isDestroyed)
        {
            ALOGV("invokingLoadCallbacks perform in cocos thread, AudioCache (%p) was destroyed!", this);
            return;
        }
        
        for (auto&& cb : _loadCallbacks)
        {
            cb(_state == State::READY);
        }

        _loadCallbacks.clear();
    });
}

#endif
