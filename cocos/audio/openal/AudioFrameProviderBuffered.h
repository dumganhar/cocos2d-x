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
#include "AudioBlock.h"

class AudioCachedInfo;
class ICallerThreadUtils;

class AudioFrameProviderBuffered : public IAudioFrameProvider
{
public:
    AudioFrameProviderBuffered(const std::string& url,
                               std::shared_ptr<IAudioFrameProvider> frameProvider,
                               ICallerThreadUtils* callerThreadUtils,
                               bool toCacheWholeFile);
    
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

    int readToBuffer(int blockIndex);
    void readToBufferAsync();
    
private:
    std::string _url;
    std::shared_ptr<IAudioFrameProvider> _frameProvider;
    
    bool _isCacheWholeFile;
    AudioCachedInfo* _cacheInfo;
    int _currentBlockIndex;
    ICallerThreadUtils* _callerThreadUtils;
    
    int _readFrameIndex;
};

#endif /* AudioFrameProviderBuffered_hpp */
