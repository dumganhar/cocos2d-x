//
//  AudioFrameProviderFactory.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#include "AudioFrameProviderFactory.h"
#include "AudioFrameProviderBuffered.h"
#include "ICallerThreadUtils.h"
#include "cocos2d.h"

namespace  {
}

class CallerThreadUtils : public ICallerThreadUtils
{
public:
    virtual void performFunctionInCallerThread(const std::function<void()>& func)
    {
        cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread(func);
    };
    
    virtual std::thread::id getCallerThreadId()
    {
        return _tid;
    };
    
    void setCallerThreadId(std::thread::id tid)
    {
        _tid = tid;
    };
    
private:
    std::thread::id _tid;
};

static CallerThreadUtils __callerThreadUtils;

std::shared_ptr<IAudioFrameProvider> AudioFrameProviderFactory::getAudioFrameProvider(const std::string& url)
{
    //TODO:
    auto provider = std::make_shared<AudioFrameProviderApple>();
    if (!provider->open(url))
    {
        return nullptr;
    }
    
    
    
    return std::make_shared<AudioFrameProviderBuffered>(url, provider, &__callerThreadUtils, true);
}