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

//class AudioFrameBufferAdapter : public IAudioFrameProvider
//{
//public:
//    AudioFrameBufferAdapter(const AudioFrameBuffer& buffer)
//    : _buffer(buffer)
//    {
//    }
//    
//    virtual bool open(const std::string& url)
//    {
//        return true;
//    }
//    
//    virtual void close()
//    {
//        
//    }
//    
//    virtual int read(AudioFrameBuffer* ioFrame)
//    {
//        if (ioFrame == nullptr)
//        {
//            ALOGE("%s, ioFrame is null", __FUNCTION__);
//            return -1;
//        }
//        
//        int toReadFrameCount = ioFrame->frameCount;
//        int remainingFrameCount = _buffer.frameCount - _currentFrameIndex;
//        
//        if (remainingFrameCount <= 0)
//        {
//            ALOGE("%s, remainingFrameCount is 0", __PRETTY_FUNCTION__);
//            return -1;
//        }
//        
//        if (toReadFrameCount <= 0)
//        {
//            ALOGE("%s, toReadFrameCount is 0", __PRETTY_FUNCTION__);
//            return -1;
//        }
//        
//        if (toReadFrameCount > remainingFrameCount)
//        {
//            toReadFrameCount = remainingFrameCount;
//        }
//        
//        ioFrame->raw = _buffer.raw + toReadFrameCount * 2;
//        ioFrame->frameCount = toReadFrameCount;
//        ioFrame->sampleRate = _buffer.sampleRate;
//        
//        return toReadFrameCount;
//    }
//    
//    virtual int tell() const
//    {
//        return _currentFrameIndex;
//    }
//    
//    virtual int seek(int frameIndex)
//    {
//        if (frameIndex >= _buffer.frameCount)
//            return -1;
//        
//        _currentFrameIndex = frameIndex;
//        return _currentFrameIndex;
//    }
//    
//    virtual int getTotalFrames() const
//    {
//        return _buffer.frameCount;
//    }
//    
//    virtual int getSampleRate() const
//    {
//        return _buffer.sampleRate;
//    }
//    
//    virtual int getBytesPerFrame() const
//    {
//        return _buffer.bytesPerFrame;
//    }
//    
//private:
//    AudioFrameBuffer _buffer;
//    int _currentFrameIndex;
//};



//IAudioFrameProvider* AudioFrameCache::find(const std::string& url)
//{
//    auto iter = _cache.find(url);
//    if (iter != _cache.end())
//    {
//        return iter->second;
//    }
//    return nullptr;
//}
//
//bool AudioFrameCache::insert(const std::string& url, const AudioFrameBuffer& buffer)
//{
//    if (find(url) != nullptr)
//    {
//        ALOGV("%s, %s cache exists, no need to insert!", __FUNCTION__, url.c_str());
//        return false;
//    }
//    
//    _cache.insert(std::make_pair(url, new AudioFrameBufferAdapter(buffer)));
//    
//    return true;
//}
//
//bool AudioFrameCache::remove(const std::string& url)
//{
//    auto iter = _cache.find(url);
//    if (iter != _cache.end())
//    {
//        delete iter->second;
//        _cache.erase(iter);
//        return true;
//    }
//    return false;
//}
//
//bool AudioFrameCache::removeAll()
//{
//    for (auto&& e : _cache)
//    {
//        delete e.second;
//    }
//    
//    _cache.clear();
//    return true;
//}
//
//AudioFrameCache::AudioFrameCache(std::shared_ptr<IAudioFrameProvider> provider, int bufferCount, int frameCountInBuffer)
//: _frameProvider(nullptr)
//, _bufBase(nullptr)
//, _queueIndex(0)
//, _readIndex(0)
//, _bufferCount(bufferCount)
//, _frameCountInBuffer(frameCountInBuffer)
//{
//    assert(provider != nullptr && bufferCount > 0 && frameCountInBuffer > 0);
//    const auto bufSize = _bufferCount * frameCountInBuffer * provider->getBytesPerFrame();
//    _bufBase = (unsigned char*) malloc(bufSize);
//    memset(_bufBase, 0, bufSize);
//    
//    _bufferInfo.reserve(bufferCount);
//    for (int i = 0; i < bufferCount; ++i)
//    {
//        _bufferInfo.push_back(BufferInfo());
//    }
//}
//
//AudioFrameCache::~AudioFrameCache()
//{
//    free(_bufBase);
//}
//
//bool AudioFrameCache::queue()
//{
//    // Check whether read
//    
//    
//    AudioFrameBuffer ioFrame;
//    ioFrame.frameCount = _frameCountInBuffer;
//    ioFrame.raw = _bufBase + _queueIndex * _frameCountInBuffer * _frameProvider->getBytesPerFrame();
//    _frameProvider->read(&ioFrame);
//    _bufferInfo[_queueIndex].frameCount = ioFrame.frameCount;
//    
//    ++_queueIndex;
//    if (_queueIndex >= _bufferCount)
//    {
//        _queueIndex = 0;
//    }
//    
//    return true;
//}
//
//bool AudioFrameCache::unqueue()
//{
//    return true;
//}
//
//unsigned char* AudioFrameCache::read(int* outFrameCount)
//{
//    if (outFrameCount == nullptr)
//    {
//        return nullptr;
//    }
//    
//    do
//    {
//        if (_readIndex >= _bufferCount)
//        {
//            ALOGE("read index >= buffer count");
//            break;
//        }
//
//        assert(!_bufferInfo[_readIndex].isRead);
//        
//        *outFrameCount = _bufferInfo[_readIndex].frameCount;
//        _bufferInfo[_readIndex].isRead = false;
//        ++_readIndex;
//        
//        return ;
//    } while (false);
//    
//    *outFrameCount = 0;
//    return nullptr;
//}
//
//int AudioFrameCache::tell() const
//{
//    return _frameProvider->tell();
//}
//
//int AudioFrameCache::seek(int frameIndex)
//{
//    return _frameProvider->seek(frameIndex);
//}
//
//int AudioFrameCache::getTotalFrames() const
//{
//    return _frameProvider->getTotalFrames();
//}
//
//int AudioFrameCache::getSampleRate() const
//{
//    return _frameProvider->getSampleRate();
//}
//
//int AudioFrameCache::getBytesPerFrame() const
//{
//    return _frameProvider->getBytesPerFrame();
//}


