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

#include <string>
#import <AudioToolbox/AudioToolbox.h>
#import <OpenAL/al.h>

class AudioFrameProviderApple : public IAudioFrameProvider
{
public:
    AudioFrameProviderApple();
    virtual ~AudioFrameProviderApple();
    
    bool open(const std::string& url);
    void close();
    
    virtual int read(AudioFrameBuffer* ioFrame) override;
    virtual int tell() const override;
    virtual int seek(int frameIndex) override;
    virtual int getTotalFrames() const override;
    virtual int getSampleRate() const override;
    virtual int getBytesPerFrame() const override;
    virtual float getDuration() const override;
    
private:
    bool _isOpened;
    std::string _url;
    CFURLRef _fileURL;
    ExtAudioFileRef _extRef;
    
    AudioStreamBasicDescription _inFormat;
    AudioStreamBasicDescription _outFormat;
    
    ALsizei _sampleRate;
    
    SInt64 _totalFrames;
    SInt64 _currentFrameIndex;
    
    AudioBufferList* _bufferList;
    
    std::mutex _readMutex;
    
    friend class AudioFrameProviderFactory;
};

#endif /* AudioFrameProviderApple_hpp */
