//
//  AudioFrameCache.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/25/16.
//
//

#define LOG_TAG "AudioFrameCache"

#include "AudioFrameCache.h"
#include "IAudioFrameProvider.h"
#include "AudioFrameBuffer.h"
#include "AudioUtils.h"

class AudioFrameBufferAdapter : public IAudioFrameProvider
{
public:
    AudioFrameBufferAdapter(AudioFrameBuffer buffer)
    : _buffer(buffer)
    {
    }
    
    virtual int read(AudioFrameBuffer* ioFrame)
    {
        if (ioFrame == nullptr)
        {
            ALOGE("%s, ioFrame is null", __FUNCTION__);
            return -1;
        }
        
        int toReadFrameCount = ioFrame->frameCount;
        int remainingFrameCount = _buffer.frameCount - _currentFrameIndex;
        
        if (remainingFrameCount <= 0)
        {
            ALOGE("%s, remainingFrameCount is 0", __PRETTY_FUNCTION__);
            return -1;
        }
        
        if (toReadFrameCount <= 0)
        {
            ALOGE("%s, toReadFrameCount is 0", __PRETTY_FUNCTION__);
            return -1;
        }
        
        if (toReadFrameCount > remainingFrameCount)
        {
            toReadFrameCount = remainingFrameCount;
        }
        
        ioFrame->raw = _buffer.raw + toReadFrameCount * 2;
        ioFrame->frameCount = toReadFrameCount;
        ioFrame->sampleRate = _buffer.sampleRate;
        
        return toReadFrameCount;
    }
    
    virtual int tell() const
    {
        return _currentFrameIndex;
    }
    
    virtual int seek(int frameIndex)
    {
        if (frameIndex >= _buffer.frameCount)
            return -1;
        
        _currentFrameIndex = frameIndex;
        return _currentFrameIndex;
    }
    
    virtual int getTotalFrames() const
    {
        return _buffer.frameCount;
    }
    
    virtual int getSampleRate() const
    {
        return _buffer.sampleRate;
    }
private:
    AudioFrameBuffer _buffer;
    int _currentFrameIndex;
};

AudioFrameCache::AudioFrameCache()
{
    
}

AudioFrameCache::~AudioFrameCache()
{
    
}

IAudioFrameProvider* AudioFrameCache::find(const std::string& url)
{
    auto iter = _cache.find(url);
    if (iter != _cache.end())
    {
        return iter->second;
    }
    return nullptr;
}

bool AudioFrameCache::insert(const std::string& url, AudioFrameBuffer buffer)
{
    if (find(url) != nullptr)
    {
        ALOGV("%s, %s cache exists, no need to insert!", __FUNCTION__, url.c_str());
        return false;
    }
    
    _cache.insert(std::make_pair(url, new AudioFrameBufferAdapter(buffer)));
    
    return true;
}

bool AudioFrameCache::remove(const std::string& url)
{
    auto iter = _cache.find(url);
    if (iter != _cache.end())
    {
        delete iter->second;
        _cache.erase(iter);
        return true;
    }
    return false;
}

bool AudioFrameCache::removeAll()
{
    for (auto&& e : _cache)
    {
        delete e.second;
    }
    
    _cache.clear();
    return true;
}