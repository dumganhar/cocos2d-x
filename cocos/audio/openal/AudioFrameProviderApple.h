//
//  AudioFrameProviderApple.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef AudioFrameProviderApple_hpp
#define AudioFrameProviderApple_hpp

#include "IAudioFrameProvider.h"

class AudioFrameProviderApple : public IAudioFrameProvider
{
public:
    virtual int read(AudioFrame* ioFrame) override;
    virtual int tell() override;
    virtual int seek(int frameIndex) override;
    virtual int getTotalFrames() override;
    
private:
    AudioFrameProviderApple();
    virtual ~AudioFrameProviderApple();
    bool init(const std::string& url);
};

#endif /* AudioFrameProviderApple_hpp */
