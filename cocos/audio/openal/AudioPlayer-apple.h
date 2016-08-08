//
//  AudioPlayer-apple.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef AudioPlayer_apple_hpp
#define AudioPlayer_apple_hpp

#include "IAudioPlayer.h"

class AudioPlayerApple : public IAudioPlayer
{
public:
    AudioPlayerApple();
    virtual ~AudioPlayerApple();
    
    virtual int getId() const;
    
    virtual void setId(int id);
    
    virtual std::string getUrl();
    
    virtual State getState();
    
    virtual void play();
    
    virtual void pause();
    
    virtual void resume();
    
    virtual void stop();
    
    virtual void rewind();
    
    virtual void setVolume(float volume);
    
    virtual float getVolume() const;
    
    virtual void setLoop(bool isLoop);
    
    virtual bool isLoop() const;
    
    virtual float getDuration() const;
    
    virtual float getPosition() const;
    
    virtual bool setPosition(float pos);
    
    // @note: STOPPED event is invoked in main thread
    //        OVER event is invoked in sub thread
    virtual void setPlayEventCallback(const PlayEventCallback &playEventCallback);
};

#endif /* AudioPlayer_apple_hpp */
