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
, _readFrameIndex(0)

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
//    assert(ioFrame->frameCount <= _cacheInfo->_frameCountInBlock);
    
    int curPos = tell();
    AudioBlockRange range = _cacheInfo->getBlockRange(curPos, ioFrame->frameCount);
    
    if (!range.isValid())
    {
        ALOGV("out of range!");
        ioFrame->raw = nullptr;
        ioFrame->frameCount = 0;
        return 0;
    }
    
    int totalFrameCount = 0;
    
    for (int blockIndex = range.blockStart; blockIndex < range.blockEnd; ++blockIndex)
    {
        auto& block = _cacheInfo->getBlock(blockIndex);
        totalFrameCount += block.frameCount;
        
        switch (block.status)
        {
            case AudioBlock::Status::INITIALIZED:
                ALOGV("block %d in init status, try read to buffer!", blockIndex);
                readToBuffer(blockIndex);
                break;
            case AudioBlock::Status::READING:
                ALOGV("block %d in reading status, waiting, start ...", blockIndex);
                // Wait to read finish
                for(;;)
                {
//                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    if (block.status == AudioBlock::Status::CACHED)
                        break;
                }
                ALOGV("block %d in reading status, waiting, finish!", blockIndex);
                break;
            case AudioBlock::Status::CACHED:
                ALOGV("block %d in cached status, great!", blockIndex);
                // Just skip
                break;
        }
    }
    
    ioFrame->raw = _cacheInfo->_bufferBase + curPos * _frameProvider->getBytesPerFrame();
    ioFrame->bytesPerFrame = _frameProvider->getBytesPerFrame();
    ioFrame->sampleRate = _frameProvider->getSampleRate();
    ioFrame->frameCount = (curPos + ioFrame->frameCount) > _frameProvider->getTotalFrames() ? (_frameProvider->getTotalFrames() - curPos) : ioFrame->frameCount;
    
    seek(curPos + ioFrame->frameCount);

    return ioFrame->frameCount;
}

int AudioFrameProviderBuffered::tell() const
{
    return _readFrameIndex;
}

int AudioFrameProviderBuffered::seek(int frameIndex)
{
    _readFrameIndex = frameIndex;
    return _readFrameIndex;
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

int AudioFrameProviderBuffered::readToBuffer(int blockIndex)
{
    auto& block = _cacheInfo->getBlock(blockIndex);
    
    if (block.status == AudioBlock::Status::CACHED)
    {
        return block.frameCount;
    }
    
    _frameProvider->seek(block.frameIndex);

    _cacheInfo->_readMutex.lock();
    
    AudioFrameBuffer ioFrame;
    ioFrame.frameCount = _cacheInfo->_frameCountInBlock;
    ioFrame.raw = block.raw;
    _frameProvider->read(&ioFrame);
    block.status = AudioBlock::Status::CACHED;
    
    _cacheInfo->_readMutex.unlock();
    return ioFrame.frameCount;
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
        _cacheInfo->_isAllBlocksCached = true;
        return;
    }
    
    auto& block = _cacheInfo->getBlock(_currentBlockIndex);
    if (block.status != AudioBlock::Status::INITIALIZED)
    {
        ++_currentBlockIndex;
        readToBufferAsync();
        return;
    }

    _cacheInfo->_readMutex.lock();
    block.status = AudioBlock::Status::READING;
    _cacheInfo->_readMutex.unlock();
    
    __threadPool->pushTask([this](int tid){
        
        readToBuffer(_currentBlockIndex);
        
        ++_currentBlockIndex;
        
        if (_frameProvider->tell() < _frameProvider->getTotalFrames())
        {
            //FIXME: remove sleep
//            std::this_thread::sleep_for(std::chrono::microseconds(200));
            
            _callerThreadUtils->performFunctionInCallerThread([this](){
                readToBufferAsync();
                
            });
        }

    });
    
    
//    --_idleBlockCount;
}


