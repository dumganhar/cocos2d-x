//
//  AudioCachedInfo.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/29/16.
//
//

#ifndef AudioCachedInfo_hpp
#define AudioCachedInfo_hpp

#include "AudioBlock.h"

#include <vector>
#include <memory>

class IAudioFrameProvider;

class AudioCachedInfo
{
public:
    AudioCachedInfo(std::shared_ptr<IAudioFrameProvider> provider);
    ~AudioCachedInfo();
    
    bool init();
    inline AudioBlock& getBlock(int blockIndex) { return _cachedBlocks.at(blockIndex); };
    
    int getBlockIndex(int frameIndex) const;
    AudioBlockRange getBlockRange(int frameIndex, int toReadFrameCount) const;
    
public:
    int _blockCountToCache;
    int _idleBlockCount;
    int _frameCountInBlock;
    
    unsigned char* _bufferBase;
    
    bool _isAllBlocksCached; // If all blocks are cached, _cachedBlocks need to be cleared to release memory
    
    int _blockCount;
    int _finalBlockFrameIndex;
    int _finalBlockFrameCount;
    
    std::mutex _readMutex;
    std::vector<AudioBlock> _cachedBlocks; // Used only in cacheWholeFile mode
    std::shared_ptr<IAudioFrameProvider> _frameProvider;
};

#endif /* AudioCachedInfo_hpp */
