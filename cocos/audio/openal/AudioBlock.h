//
//  AudioBlock.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/29/16.
//
//

#ifndef AudioBlock_hpp
#define AudioBlock_hpp

struct AudioBlock
{
    unsigned char* raw; // Pointer to buffer
    int frameIndex;
    int frameCount;  // Filled frame count, final block may smaller than frameCountInBlock.
    
    enum class Status
    {
        INITIALIZED,
        READING,
        CACHED
    };
    Status status; // 0: not read, 1: in reading, 2: cached
};

struct AudioBlockRange
{
    int blockStart;
    int blockEnd;
    
    AudioBlockRange()
    : blockStart(-1)
    , blockEnd(-1)
    {};
    bool isValid() const { return blockStart >= 0 && blockEnd > 0;};
};

#endif /* AudioBlock_hpp */
