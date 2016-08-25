//
//  AudioSource.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef AudioSource_hpp
#define AudioSource_hpp

#include <string>

class IAudioFrameProvider;

class AudioSource
{
public:
    enum class State
    {
        INVALID = 0,
        INITIALIZED,
        PLAYING,
        PAUSED,
        STOPPED,
        OVER
    };
    
    using PlayEventCallback = std::function<void(State)>;
    
    AudioSource(const std::string& url, bool isStreaming);
    ~AudioSource();
    
    int getId() const;
    
    void setId(int id);
    
    std::string getUrl() const;
    
    State getState() const;
    
    void play();
    
    void pause();
    
    void resume();
    
    void stop();
    
    void rewind();
    
    void setVolume(float volume);
    
    float getVolume() const;
    
    void setLoop(bool isLoop);
    
    bool isLoop() const;
    
    float getDuration() const;
    
    float getPosition() const;
    
    bool setPosition(float pos);
    
    void setPlayEventCallback(const PlayEventCallback &playEventCallback);
    
private:
    IAudioFrameProvider* _audioFrameProvider;
    std::string _url;
    bool _isStreaming;
};

#endif /* AudioSource_hpp */
