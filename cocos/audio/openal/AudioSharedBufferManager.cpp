//
//  AudioSharedBufferManager.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/29/16.
//
//

#include "AudioSharedBufferManager.h"
#include "IAudioFrameProvider.h"

namespace  {
    AudioSharedBufferManager* _instance = nullptr;
}

std::unordered_map<std::string, AudioCachedInfo*> AudioSharedBufferManager::_cachedInfo;

AudioSharedBufferManager* AudioSharedBufferManager::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new AudioSharedBufferManager();
    }
    
    return _instance;
}

void AudioSharedBufferManager::destroyInstance()
{
    delete _instance;
    _instance = nullptr;
}

AudioSharedBufferManager::AudioSharedBufferManager()
{
    
}

AudioSharedBufferManager::~AudioSharedBufferManager()
{
    removeAllCachedInfos();
}

AudioCachedInfo* AudioSharedBufferManager::getOrCreateCachedInfo(std::shared_ptr<IAudioFrameProvider> provider, const std::string& url)
{
    auto iter = _cachedInfo.find(url);
    if (iter != _cachedInfo.end())
    {
        return iter->second;
    }
    
    AudioCachedInfo* info = new AudioCachedInfo(provider);
    _cachedInfo.insert(std::make_pair(url, info));
    return info;
}

void AudioSharedBufferManager::removeCachedInfo(const std::string& url)
{
    auto iter = _cachedInfo.find(url);
    if (iter != _cachedInfo.end())
    {
        delete iter->second;
        _cachedInfo.erase(iter);
    }
}

void AudioSharedBufferManager::removeAllCachedInfos()
{
    for (auto&& e : _cachedInfo)
    {
        delete e.second;
    }
    
    _cachedInfo.clear();
}