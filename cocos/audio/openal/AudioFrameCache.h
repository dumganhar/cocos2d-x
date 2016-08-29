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
#include <vector>

//class IAudioFrameProvider;
//class AudioFrameBuffer;
//
//class AudioFrameCache
//{
//public:
//    AudioFrameCache(std::shared_ptr<IAudioFrameProvider> provider, int bufferCount, int frameCountInBuffer);
//    ~AudioFrameCache();
//    
//    bool queue();
//    bool unqueue();
//    
//    unsigned char* read(int* outFrameCount);
//    
//    int tell() const;
//    int seek(int frameIndex);
//    int getTotalFrames() const;
//    int getSampleRate() const;
//    int getBytesPerFrame() const;
//
////    IAudioFrameProvider* find(const std::string& url);
////    bool insert(const std::string& url, const AudioFrameBuffer& buffer);
////    
////    bool remove(const std::string& url);
////    bool removeAll();
//    
//private:
////    std::unordered_map<std::string, IAudioFrameProvider*> _cache;
//    std::shared_ptr<IAudioFrameProvider> _frameProvider;
//    unsigned char* _bufBase;
//    int _queueIndex;
//    int _readIndex;
//    int _unreadBufferCount;
//    
//    struct BufferInfo
//    {
//        unsigned char* raw;
//        bool isRead;
//        int frameCount;
//        
//        BufferInfo(unsigned char* raw_, bool isRead_, int frameCount_)
//        {
//            this->raw = raw_;
//            this->isRead = isRead_;
//            this->frameCount = frameCount_;
//        }
//    };
//    
//    std::vector<BufferInfo> _bufferInfo;
//    
//    int _bufferCount;
//    int _frameCountInBuffer;
//};

#endif /* AudioFrameCache_hpp */
