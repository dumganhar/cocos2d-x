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
    
    virtual int getId() const override;
    
    virtual void setId(int id) override;
    
    virtual std::string getUrl() const override;
    
    virtual State getState() const override;
    
    virtual void play() override;
    
    virtual void pause() override;
    
    virtual void resume() override;
    
    virtual void stop() override;
    
    virtual void rewind() override;
    
    virtual void setVolume(float volume) override;
    
    virtual float getVolume() const override;
    
    virtual void setLoop(bool isLoop) override;
    
    virtual bool isLoop() const override;
    
    virtual float getDuration() const override;
    
    virtual float getPosition() const override;
    
    virtual bool setPosition(float pos) override;
    
    // @note: STOPPED event is invoked in main thread
    //        OVER event is invoked in sub thread
    virtual void setPlayEventCallback(const PlayEventCallback &playEventCallback) override;
};

#endif /* AudioPlayer_apple_hpp */
