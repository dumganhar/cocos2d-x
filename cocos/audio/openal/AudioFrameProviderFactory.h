//
//  AudioFrameProviderFactory.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef AudioFrameProviderFactory_hpp
#define AudioFrameProviderFactory_hpp

#include "AudioFrameProviderApple.h"
#include <memory>


class IAudioFrameProvider;

class AudioFrameProviderFactory
{
public:
    
    static std::shared_ptr<IAudioFrameProvider> getAudioFrameProvider(const std::string& url);
    
private:
    AudioFrameProviderFactory() {};
    ~AudioFrameProviderFactory() {};
};

#endif /* AudioFrameProviderFactory_hpp */
