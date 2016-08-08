//
//  AudioSourceCache.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef AudioSourceCache_hpp
#define AudioSourceCache_hpp

#include <string>
#include <unordered_map>

class AudioSource;

class AudioSourceCache
{
public:
    AudioSourceCache();
    ~AudioSourceCache();
    
    AudioSource* find(const std::string& url);
    bool insert(const std::string& url, AudioSource* source);
    
    bool remove(const std::string& url);
    bool removeAll();
    
private:
    std::unordered_map<std::string, AudioSource*> _cache;
};

#endif /* AudioSourceCache_hpp */
