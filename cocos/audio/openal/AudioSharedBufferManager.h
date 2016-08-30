//
//  AudioSharedBufferManager.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/29/16.
//
//

#ifndef AudioSharedBufferManager_hpp
#define AudioSharedBufferManager_hpp

#include "AudioBlock.h"
#include "AudioCachedInfo.h"

#include <string>
#include <unordered_map>
#include <memory>

class AudioSharedBufferManager
{
public:
    static AudioSharedBufferManager* getInstance();
    static void destroyInstance();
    
    AudioCachedInfo* getOrCreateCachedInfo(std::shared_ptr<IAudioFrameProvider> provider, const std::string& url);
    void removeCachedInfo(const std::string& url);
    void removeAllCachedInfos();
    
private:
    AudioSharedBufferManager();
    ~AudioSharedBufferManager();
    
private:
    static std::unordered_map<std::string, AudioCachedInfo*> _cachedInfo;
};

#endif /* AudioSharedBufferManager_hpp */
