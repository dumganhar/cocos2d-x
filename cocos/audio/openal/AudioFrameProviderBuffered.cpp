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

namespace  {
    ThreadPool* __threadPool = nullptr;
}

AudioFrameProviderBuffered::AudioFrameProviderBuffered(const std::string& url, IAudioFrameProvider* frameProvider, bool cacheWholeFile)
: _url(url)
, _frameProvider(frameProvider)
, _blockCountToCache(3)
, _frameCountInBlock(frameProvider->getSampleRate() * 0.1f)
, _isCacheWholeFile(cacheWholeFile)
, _bufferBase(nullptr)
, _currentBlockIndex(0)
, _isAllBlocksCached(false)
, _finalBlockFrameIndex(-1)
, _finalBlockFrameCount(-1)
, _blockCount(0)
{
    init();
}

AudioFrameProviderBuffered::~AudioFrameProviderBuffered()
{
    //FIXME:
//    delete _threadPool;
    free(_bufferBase);
}

bool AudioFrameProviderBuffered::init()
{
    if (__threadPool == nullptr)
    {
        __threadPool = ThreadPool::newFixedThreadPool(4);
    }
    
    int divResult = _frameProvider->getTotalFrames() / _frameCountInBlock;
    int remainder = _frameProvider->getTotalFrames() % _frameCountInBlock;
    
    _blockCount = remainder > 0 ?  divResult + 1 : divResult;
    
    int totalSize = 0;
    
    if (_isCacheWholeFile)
    {
        totalSize = _frameProvider->getTotalFrames() * _frameProvider->getBytesPerFrame();
    }
    else
    {
        totalSize = _blockCountToCache * _frameCountInBlock * _frameProvider->getBytesPerFrame();
    }

    _bufferBase = (unsigned char*) malloc(totalSize);
    memset(_bufferBase, 0, totalSize);
    
    _finalBlockFrameIndex = (_blockCount - 1) * _frameCountInBlock;
    
    if (_isCacheWholeFile)
    {
        _cachedBlocks.reserve(_blockCount);
        
        for (int i = 0; i < _blockCount; ++i)
        {
            Block block;
            block.raw = _bufferBase + (i * _frameCountInBlock);
            block.frameCount = (i == _blockCount-1 && remainder > 0) ? remainder : _frameCountInBlock;
            block.status = Block::Status::INITIALIZED;
            _cachedBlocks.push_back(block);
        }
    }
    
    readToBufferAsync();
    return true;
}

int AudioFrameProviderBuffered::read(AudioFrameBuffer* ioFrame)
{
    assert(ioFrame->frameCount <= _frameCountInBlock);
    
    if (_idleBlockCount == _blockCount)
    {
        readToBuffer();
    }
    
    ioFrame->raw = _bufferBase + _currentBlockIndex * _frameCountInBlock * _frameProvider->getBytesPerFrame();
//    ioFrame->frameCount = 
    
    ++_idleBlockCount;
    
    readToBufferAsync();
    
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
    _idleBlockCount = 0;
    
    
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
    
    if (_currentBlockIndex >= _blockCount)
    {
        return;
    }
    
    _cachedBlocks.at(_currentBlockIndex).status = Block::Status::READING;
    
    __threadPool->pushTask([this](int tid){
        std::lock_guard<std::mutex> lk(_readMutex);
        
        AudioFrameBuffer ioFrame;
        ioFrame.frameCount = _frameCountInBlock;
        ioFrame.raw = getCurrentBuffer();
        ALOGV("current block index: %d", _currentBlockIndex);
        _frameProvider->read(&ioFrame);
        
        _cachedBlocks.at(_currentBlockIndex).status = Block::Status::CACHED;
        
        ++_currentBlockIndex;
        
        if (_frameProvider->tell() < _frameProvider->getTotalFrames())
        {
            readToBufferAsync();
        }
        else
        {
            
        }
    });
    
    
//    --_idleBlockCount;
}

unsigned char* AudioFrameProviderBuffered::getCurrentBuffer() const
{
    return _cachedBlocks.at(_currentBlockIndex).raw;
}

int AudioFrameProviderBuffered::getBlockIndex(int frameIndex) const
{
    return 0;
}

AudioFrameProviderBuffered::BlockRange AudioFrameProviderBuffered::getBlockRange(int frameIndex, int toReadFrameCount) const
{
    BlockRange aaa;
    return aaa;
}
