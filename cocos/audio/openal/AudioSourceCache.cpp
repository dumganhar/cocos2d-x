//
//  AudioSourceCache.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#include "AudioSourceCache.h"

AudioSourceCache::AudioSourceCache()
{
    
}

AudioSourceCache::~AudioSourceCache()
{
    
}

AudioSource* AudioSourceCache::find(const std::string& url)
{
    return nullptr;
}

bool AudioSourceCache::insert(const std::string& url, AudioSource* source)
{
    return false;
}

bool AudioSourceCache::remove(const std::string& url)
{
    return false;
}

bool AudioSourceCache::removeAll()
{
    return false;
}