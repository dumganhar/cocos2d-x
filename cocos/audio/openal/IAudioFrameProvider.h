//
//  IAudioFrameProvider.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef IAudioFrameProvider_hpp
#define IAudioFrameProvider_hpp

class AudioFrameBuffer;

class IAudioFrameProvider
{
public:
    virtual ~IAudioFrameProvider() {};
    
    virtual int read(AudioFrameBuffer* ioFrame) = 0;
    virtual int tell() const = 0;
    virtual int seek(int frameIndex) = 0;
    virtual int getTotalFrames() const = 0;
    virtual int getSampleRate() const = 0;
};

#endif /* IAudioFrameProvider_hpp */
