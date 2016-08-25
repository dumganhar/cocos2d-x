//
//  AudioFrameCache.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/25/16.
//
//

#ifndef AudioFrameCache_hpp
#define AudioFrameCache_hpp

#include <string>
#include <memory>

class IAudioFrameProvider;
class AudioFrameBuffer;

class AudioFrameCache
{
public:
    AudioFrameCache();
    ~AudioFrameCache();
    
    IAudioFrameProvider* find(const std::string& url);
    bool insert(const std::string& url, AudioFrameBuffer buffer);
    
    bool remove(const std::string& url);
    bool removeAll();
    
private:
    std::unordered_map<std::string, IAudioFrameProvider*> _cache;
};

#endif /* AudioFrameCache_hpp */
