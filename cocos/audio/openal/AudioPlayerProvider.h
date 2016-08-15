//
//  AudioPlayerProvider.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef AudioPlayerProvider_hpp
#define AudioPlayerProvider_hpp

class IAudioPlayer;

class AudioPlayerProvider
{
public:
    AudioPlayerProvider();
    ~AudioPlayerProvider();
    
    IAudioPlayer* get();
};

#endif /* AudioPlayerProvider_hpp */
