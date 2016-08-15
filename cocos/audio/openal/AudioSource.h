//
//  AudioSource.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef AudioSource_hpp
#define AudioSource_hpp

class IAudioPlayer;
class IAudioFrameProvider;

class AudioSource
{
public:
    static AudioSource* create(const std::string& url, bool isStreaming);
    
    IAudioPlayer* getAudioPlayer();

private:
    IAudioPlayer* _audioPlayer;
    IAudioFrameProvider* _audioFrameProvider;
};

#endif /* AudioSource_hpp */
