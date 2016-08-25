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

#import <AudioToolbox/AudioToolbox.h>
#import <OpenAL/al.h>

class AudioFrameProviderApple : public IAudioFrameProvider
{
public:
    virtual int read(AudioFrameBuffer* ioFrame) override;
    virtual int tell() const override;
    virtual int seek(int frameIndex) override;
    virtual int getTotalFrames() const override;
    virtual int getSampleRate() const override;
    
private:
    AudioFrameProviderApple();
    virtual ~AudioFrameProviderApple();
    bool init(const std::string& url);
    
private:
    CFURLRef _fileURL;
    ExtAudioFileRef _extRef;
    
    AudioStreamBasicDescription _inFormat;
    AudioStreamBasicDescription _outFormat;
    
    ALsizei _sampleRate;
    
    SInt64 _totalFrames;
    SInt64 _currentFrameIndex;
    
    friend class AudioFrameProviderFactory;
};

#endif /* AudioFrameProviderApple_hpp */
