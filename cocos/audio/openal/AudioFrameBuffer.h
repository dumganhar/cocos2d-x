//
//  AudioFrameBuffer.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef AudioFrameBuffer_hpp
#define AudioFrameBuffer_hpp


struct AudioFrameBuffer
{
    int frameCount;
    int sampleRate;
    int bytesPerFrame;
    unsigned char* raw;
    
    AudioFrameBuffer()
    : frameCount(0)
    , sampleRate(0)
    , bytesPerFrame(0)
    , raw(nullptr)
    {}
};

#endif /* AudioFrameBuffer_hpp */
