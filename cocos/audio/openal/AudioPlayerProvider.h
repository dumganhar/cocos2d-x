//
//  AudioPlayerProvider.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef AudioPlayerProvider_hpp
#define AudioPlayerProvider_hpp

class AudioPlayerProvider
{
public:
    AudioPlayerProvider();
    ~AudioPlayerProvider();
    
    IAudioPlayerProvider* get();
};

#endif /* AudioPlayerProvider_hpp */
