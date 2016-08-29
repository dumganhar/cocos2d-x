//
//  AudioFrameProviderFactory.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#include "AudioFrameProviderFactory.h"
#include "AudioFrameProviderBuffered.h"

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

IAudioFrameProvider* AudioFrameProviderFactory::newAudioFrameProvider(const std::string& url)
{
    //TODO:
    IAudioFrameProvider* ret = nullptr;
    auto provider = new AudioFrameProviderApple();
    if (!provider->open(url))
    {
        delete provider;
        provider = nullptr;
    }
    
    if (provider != nullptr)
    {
        // FIXME:
        ret = new AudioFrameProviderBuffered(url, provider, true);
    }
    
    return ret;
}