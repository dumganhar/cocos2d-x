//
//  AudioFrameProviderFactory.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef AudioFrameProviderFactory_hpp
#define AudioFrameProviderFactory_hpp

class IAudioFrameProvider;

class AudioFrameProviderFactory
{
public:
    static AudioFrameProviderFactory* getInstance();
    static void destroyInstance();
    
    bool registerAudioFrameProvider(const std::string& suffix);
    void unregisterAudioFrameProvider(const std::string& suffix);
    
    IAudioFrameProvider* getAudioProvider(const std::string& suffix);
    
};

#endif /* AudioFrameProviderFactory_hpp */
