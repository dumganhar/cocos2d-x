//
//  AudioFrameProviderApple.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#import "AudioFrameProviderApple.h"

AudioFrameProviderApple::AudioFrameProviderApple()
{
    
}

AudioFrameProviderApple::~AudioFrameProviderApple()
{
    
}

bool AudioFrameProviderApple::init(const std::string& url)
{
    CFURLRef fileURL = nil;
    ExtAudioFileRef extRef = nullptr;
    
    
    return false;
}

int AudioFrameProviderApple::read(AudioFrame* ioFrame)
{
    return 0;
}

int AudioFrameProviderApple::tell()
{
    return 0;
}

int AudioFrameProviderApple::seek(int frameIndex)
{
    return 0;
}

int AudioFrameProviderApple::getTotalFrames()
{
    return 0;
}
