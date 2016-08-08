//
//  IAudioFrameProvider.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef IAudioFrameProvider_hpp
#define IAudioFrameProvider_hpp

class AudioFrame;

class IAudioFrameProvider
{
public:
    virtual ~IAudioFrameProvier() {};
    
    virtual int read(AudioFrame* ioFrame) = 0;
    virtual int tell() = 0;
    virtual int seek(int frameIndex) = 0;
    virtual int getTotalFrames() = 0;
};

#endif /* IAudioFrameProvider_hpp */
