//
//  AudioSource.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#include "AudioSource.h"

AudioSource::AudioSource(const std::string& url, bool isStreaming)
: _audioFrameProvider(nullptr)
, _url(url)
, _isStreaming(isStreaming)
{
}

int AudioSource::getId() const
{
    return 0;
}

void AudioSource::setId(int id)
{
    
}

std::string AudioSource::getUrl() const
{
    return _url;
}

AudioSource::State AudioSource::getState() const
{
    return State::INVALID;
}

void AudioSource::play()
{
    
}

void AudioSource::pause()
{
    
}

void AudioSource::resume()
{
    
}

void AudioSource::stop()
{
    
}

void AudioSource::rewind()
{
    
}

void AudioSource::setVolume(float volume)
{
    
}

float AudioSource::getVolume() const
{
    return 0.0f;
}

void AudioSource::setLoop(bool isLoop)
{
    
}

bool AudioSource::isLoop() const
{
    return false;
}

float AudioSource::getDuration() const
{
    return 0.0f;
}

float AudioSource::getPosition() const
{
    return 0.0f;
}

bool AudioSource::setPosition(float pos)
{
    return false;
}

void AudioSource::setPlayEventCallback(const PlayEventCallback &playEventCallback)
{
    
}
