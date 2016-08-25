//
//  AudioFrameProviderFactory.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#include "AudioFrameProviderFactory.h"


namespace  {
    std::unordered_map<std::string, IAudioFrameProvider*> __providerMap;
}

bool AudioFrameProviderFactory::registerAudioFrameProvider(const std::string& suffix)
{
    auto iter = __providerMap.find(suffix);
    if (iter == __providerMap.end())
    {
        // FIXME:
        return true;
    }
    return false;
}

void AudioFrameProviderFactory::unregisterAudioFrameProvider(const std::string& suffix)
{
    
}

void AudioFrameProviderFactory::unregisterAll()
{
    
}

IAudioFrameProvider* AudioFrameProviderFactory::getAudioProvider(const std::string& suffix)
{
    //TODO:
    return &__provider;
}