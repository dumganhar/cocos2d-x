//
//  AudioFrameProviderBuffered.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/26/16.
//
//

#ifndef AudioFrameProviderBuffered_hpp
#define AudioFrameProviderBuffered_hpp

#include "IAudioFrameProvider.h"

class AudioFrameProviderBuffered : public IAudioFrameProvider
{
public:
    AudioFrameProviderBuffered(const std::string& url, IAudioFrameProvider* frameProvider, bool toCacheWholeFile);
    virtual ~AudioFrameProviderBuffered();
    
    
    bool init();
    // Override functions
    virtual int read(AudioFrameBuffer* ioFrame) override;
    virtual int tell() const override;
    virtual int seek(int frameIndex) override;
    virtual int getTotalFrames() const override;
    virtual int getSampleRate() const override;
    virtual int getBytesPerFrame() const override;
    virtual float getDuration() const override;
    //
    
private:
    unsigned char* getCurrentBuffer() const;
    int getBlockIndex(int frameIndex) const;
    bool isAllBlocksCached() const;
    
    struct Block
    {
        unsigned char* raw; // Pointer to buffer
        int frameCount;  // Filled frame count, final block may smaller than frameCountInBlock.
        
        enum class Status
        {
            INITIALIZED,
            READING,
            CACHED
        };
        Status status; // 0: not read, 1: in reading, 2: cached
    };
    
    struct BlockRange
    {
        int blockStart;
        int blockEnd;
    };
    
    BlockRange getBlockRange(int frameIndex, int toReadFrameCount) const;

    void readToBuffer();
    void readToBufferAsync();
    
    
private:
    std::string _url;
    IAudioFrameProvider* _frameProvider;
    int _blockCountToCache;
    
    int _idleBlockCount;
    
    int _frameCountInBlock;
    bool _isCacheWholeFile;
    
    unsigned char* _bufferBase;
    int _currentBlockIndex;
    std::mutex _readMutex;
    
    std::vector<Block> _cachedBlocks; // Used only in cacheWholeFile mode
    bool _isAllBlocksCached; // If all blocks are cached, _cachedBlocks need to be cleared to release memory
    
    int _blockCount;
    int _finalBlockFrameIndex;
    int _finalBlockFrameCount;
    
    struct CachedInfo
    {
        
    };
    
    static std::unordered_map<std::string, CachedInfo> _cachedInfo;
    
};

#endif /* AudioFrameProviderBuffered_hpp */
