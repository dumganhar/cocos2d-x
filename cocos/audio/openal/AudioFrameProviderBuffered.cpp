//
//  AudioFrameProviderBuffered.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/26/16.
//
//

#define LOG_TAG "AudioFrameProviderBuffered"

#include "AudioFrameProviderBuffered.h"
#include "CCThreadPool.h"
#include "AudioFrameBuffer.h"
#include "AudioUtils.h"
#include "AudioCachedInfo.h"
#include "AudioSharedBufferManager.h"
#include "ICallerThreadUtils.h"

namespace  {
    ThreadPool* __threadPool = nullptr;
}

AudioFrameProviderBuffered::AudioFrameProviderBuffered(const std::string& url,
                                                       std::shared_ptr<IAudioFrameProvider> frameProvider,
                                                       ICallerThreadUtils* callerThreadUtils,
                                                       bool cacheWholeFile)
: _url(url)
, _frameProvider(frameProvider)
, _isCacheWholeFile(cacheWholeFile)
, _currentBlockIndex(0)
, _cacheInfo(nullptr)
, _callerThreadUtils(callerThreadUtils)

{
    init();
}

AudioFrameProviderBuffered::~AudioFrameProviderBuffered()
{
    //FIXME:
//    delete _threadPool;
}

bool AudioFrameProviderBuffered::init()
{
    if (__threadPool == nullptr)
    {
        __threadPool = ThreadPool::newFixedThreadPool(4);
    }
    
    if (_isCacheWholeFile)
    {
        _cacheInfo = AudioSharedBufferManager::getInstance()->getOrCreateCachedInfo(_frameProvider, _url);
    }
    
    readToBufferAsync();
    return true;
}

int AudioFrameProviderBuffered::read(AudioFrameBuffer* ioFrame)
{
    assert(ioFrame->frameCount <= _cacheInfo->_frameCountInBlock);
    
    AudioBlockRange range = _cacheInfo->getBlockRange(_frameProvider->tell(), ioFrame->frameCount);
    
    for (int blockIndex = range.blockStart; blockIndex < range.blockEnd; ++blockIndex)
    {
        switch (_cacheInfo->getBlock(blockIndex).status)
        {
            case AudioBlock::Status::INITIALIZED:
                break;
            case AudioBlock::Status::READING:
                break;
            case AudioBlock::Status::CACHED:
                break;
        }
    }
    
//    if (_cacheInfo->_idleBlockCount == _cacheInfo->_blockCount)
//    {
//        readToBuffer();
//    }
//    
//    ioFrame->raw = _cacheInfo->_bufferBase + _cacheInfo->_currentBlockIndex * _cacheInfo->_frameCountInBlock * _frameProvider->getBytesPerFrame();
////    ioFrame->frameCount = 
//    
//    ++_idleBlockCount;
//    
//    readToBufferAsync();
    
    return ioFrame->frameCount;
}

int AudioFrameProviderBuffered::tell() const
{
    return _frameProvider->tell();
}

int AudioFrameProviderBuffered::seek(int frameIndex)
{
    int ret =  _frameProvider->seek(frameIndex);
    
    __threadPool->stopAllTasks();
    
    //FIXME:
//    _idleBlockCount = 0;
    
    
    return ret;
}

int AudioFrameProviderBuffered::getTotalFrames() const
{
    return _frameProvider->getTotalFrames();
}

int AudioFrameProviderBuffered::getSampleRate() const
{
    return _frameProvider->getSampleRate();
}

int AudioFrameProviderBuffered::getBytesPerFrame() const
{
    return _frameProvider->getBytesPerFrame();
}

float AudioFrameProviderBuffered::getDuration() const
{
    return _frameProvider->getDuration();
}

void AudioFrameProviderBuffered::readToBuffer()
{
//    std::lock_guard<std::mutex> lk(_readMutex);
// 
//    if (_idleBlockCount <= 0)
//        return;
//    
//    AudioFrameBuffer ioFrame;
//    ioFrame.frameCount = _frameCountInBlock * _blockCount;
//    ioFrame.raw = _bufferBase + _currentBlockIndex * _frameCountInBlock * _frameProvider->getBytesPerFrame();
//    _frameProvider->read(&ioFrame);
//    
//    ++_currentBlockIndex;
//    --_idleBlockCount;
}

void AudioFrameProviderBuffered::readToBufferAsync()
{
//    if (_idleBlockCount <= 0)
//        return;
    
    if (_cacheInfo->_isAllBlocksCached)
    {
        ALOGV("%s was cached, no need to read", _url.c_str());
        return;
    }
    
    if (_currentBlockIndex >= _cacheInfo->_blockCount)
    {
        assert(false);
        return;
    }
    
    _cacheInfo->getBlock(_currentBlockIndex).status = AudioBlock::Status::READING;
    
    __threadPool->pushTask([this](int tid){
        std::lock_guard<std::mutex> lk(_cacheInfo->_readMutex);
        
        auto& blockInfo = _cacheInfo->getBlock(_currentBlockIndex);
        AudioFrameBuffer ioFrame;
        ioFrame.frameCount = _cacheInfo->_frameCountInBlock;
        ioFrame.raw = blockInfo.raw;
        ALOGV("current block index: %d", _currentBlockIndex);
        _frameProvider->read(&ioFrame);
        
        blockInfo.status = AudioBlock::Status::CACHED;
        
        ++_currentBlockIndex;
        
        if (_frameProvider->tell() < _frameProvider->getTotalFrames())
        {
            _callerThreadUtils->performFunctionInCallerThread([this](){
                readToBufferAsync();
                
            });
        }
        else
        {
            
        }
    });
    
    
//    --_idleBlockCount;
}


