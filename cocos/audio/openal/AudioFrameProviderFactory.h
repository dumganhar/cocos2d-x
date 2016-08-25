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

class IAudioFrameProvider;

class AudioFrameProviderFactory
{
public:
    static bool registerAudioFrameProvider(const std::string& suffix);
    static void unregisterAudioFrameProvider(const std::string& suffix);
    static void unregisterAll();
    
    static IAudioFrameProvider* getAudioProvider(const std::string& suffix);
    
private:
    static AudioFrameProviderApple __provider;;
};

#endif /* AudioFrameProviderFactory_hpp */
