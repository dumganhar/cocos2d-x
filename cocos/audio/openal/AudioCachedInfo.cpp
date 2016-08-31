//
//  AudioCachedInfo.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/29/16.
//
//

#include "AudioCachedInfo.h"
#include "AudioBlock.h"
#include "IAudioFrameProvider.h"

#define DEFAULT_FRAME_COUNT_IN_BLOCK (0.1f * provider->getSampleRate())

AudioCachedInfo::AudioCachedInfo(std::shared_ptr<IAudioFrameProvider> provider)
: _frameProvider(provider)
, _frameCountInBlock(DEFAULT_FRAME_COUNT_IN_BLOCK)
, _bufferBase(nullptr)
, _isAllBlocksCached(false)
, _blockCount(0)
, _finalBlockFrameIndex(0)
, _finalBlockFrameCount(0)
{
    init();
}

AudioCachedInfo::~AudioCachedInfo()
{
    
}

bool AudioCachedInfo::init()
{
    int divResult = _frameProvider->getTotalFrames() / _frameCountInBlock;
    int remainder = _frameProvider->getTotalFrames() % _frameCountInBlock;
    
    _blockCount = remainder > 0 ?  divResult + 1 : divResult;
    
    int totalSize = _frameProvider->getTotalFrames() * _frameProvider->getBytesPerFrame();
    _bufferBase = (unsigned char*) malloc(totalSize);
    memset(_bufferBase, 0, totalSize);
    
    _finalBlockFrameIndex = (_blockCount - 1) * _frameCountInBlock;
    
    _cachedBlocks.reserve(_blockCount);
    
    for (int i = 0; i < _blockCount; ++i)
    {
        AudioBlock block;
        block.frameIndex = i * _frameCountInBlock;
        block.raw = _bufferBase + block.frameIndex * _frameProvider->getBytesPerFrame();
        block.frameCount = (i == _blockCount-1 && remainder > 0) ? remainder : _frameCountInBlock;
        block.status = AudioBlock::Status::INITIALIZED;
        _cachedBlocks.push_back(block);
    }
    return true;
}

int AudioCachedInfo::getBlockIndex(int frameIndex) const
{
    //FIXME: improvement
    int i = 0;
    for (auto&& block : _cachedBlocks)
    {
        if (frameIndex >= block.frameIndex && frameIndex < block.frameIndex + block.frameCount)
        {
            return i;
        }
        ++i;
    }
    return (int)_cachedBlocks.size();
}

AudioBlockRange AudioCachedInfo::getBlockRange(int frameIndex, int toReadFrameCount) const
{
    AudioBlockRange ret;
    ret.blockStart = getBlockIndex(frameIndex);
    ret.blockEnd = getBlockIndex(frameIndex + toReadFrameCount);
    
    if (ret.blockStart >= _blockCount)
    {
        ret.blockStart = ret.blockEnd = -1;
        return ret;
    }
    
    if (ret.blockStart >= 0 && ret.blockStart == ret.blockEnd)
        ++ret.blockEnd;
    
    if (ret.blockEnd > _blockCount)
        ret.blockEnd = _blockCount;
    
    return ret;
}