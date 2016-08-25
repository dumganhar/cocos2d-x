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
    unsigned char* raw;
};

#endif /* AudioFrameBuffer_hpp */
