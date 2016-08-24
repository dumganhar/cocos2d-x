#include "PerformanceAudioEngineTest.h"
#include "Profile.h"
#include "cocos/audio/include/AudioEngine.h"

#include <algorithm>

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocos2d::experimental;

// Enable profiles for this file
#undef CC_PROFILER_DISPLAY_TIMERS
#define CC_PROFILER_DISPLAY_TIMERS() Profiler::getInstance()->displayTimers()
#undef CC_PROFILER_PURGE_ALL
#define CC_PROFILER_PURGE_ALL() Profiler::getInstance()->releaseAllTimers()

#undef CC_PROFILER_START
#define CC_PROFILER_START(__name__) ProfilingBeginTimingBlock(__name__)
#undef CC_PROFILER_STOP
#define CC_PROFILER_STOP(__name__) ProfilingEndTimingBlock(__name__)
#undef CC_PROFILER_RESET
#define CC_PROFILER_RESET(__name__) ProfilingResetTimingBlock(__name__)

#undef CC_PROFILER_START_CATEGORY
#define CC_PROFILER_START_CATEGORY(__cat__, __name__) do{ if(__cat__) ProfilingBeginTimingBlock(__name__); } while(0)
#undef CC_PROFILER_STOP_CATEGORY
#define CC_PROFILER_STOP_CATEGORY(__cat__, __name__) do{ if(__cat__) ProfilingEndTimingBlock(__name__); } while(0)
#undef CC_PROFILER_RESET_CATEGORY
#define CC_PROFILER_RESET_CATEGORY(__cat__, __name__) do{ if(__cat__) ProfilingResetTimingBlock(__name__); } while(0)

#undef CC_PROFILER_START_INSTANCE
#define CC_PROFILER_START_INSTANCE(__id__, __name__) do{ ProfilingBeginTimingBlock( String::createWithFormat("%08X - %s", __id__, __name__)->getCString() ); } while(0)
#undef CC_PROFILER_STOP_INSTANCE
#define CC_PROFILER_STOP_INSTANCE(__id__, __name__) do{ ProfilingEndTimingBlock(    String::createWithFormat("%08X - %s", __id__, __name__)->getCString() ); } while(0)
#undef CC_PROFILER_RESET_INSTANCE
#define CC_PROFILER_RESET_INSTANCE(__id__, __name__) do{ ProfilingResetTimingBlock( String::createWithFormat("%08X - %s", __id__, __name__)->getCString() ); } while(0)


namespace  {
    const char* __audioFiles[] = {
        "SoundEffectsFX009/FX081.mp3",
        "SoundEffectsFX009/FX082.mp3",
        "SoundEffectsFX009/FX083.mp3",
        "SoundEffectsFX009/FX084.mp3",
        "SoundEffectsFX009/FX085.mp3",
        "SoundEffectsFX009/FX086.mp3",
        "SoundEffectsFX009/FX087.mp3",
        "SoundEffectsFX009/FX088.mp3",
        "SoundEffectsFX009/FX089.mp3",
        "SoundEffectsFX009/FX090.mp3"
    };
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

enum {
    kTagInfoLayer = 1,
};

enum
{
    kMaxAudioFileCount = 24,
    kAudioFileCountIncrease = 1,
};

PerformceAudioEngineTests::PerformceAudioEngineTests()
{
    ADD_TEST_CASE(Play2dAfterPreload);
    ADD_TEST_CASE(AudioEngineOverloadTest1);
    ADD_TEST_CASE(AudioEngineOverloadTest2);
}

////////////////////////////////////////////////////////
//
// PerformceAudioEngineScene
//
////////////////////////////////////////////////////////
PerformceAudioEngineScene::PerformceAudioEngineScene()
{
}

bool PerformceAudioEngineScene::init()
{
    if (TestCase::init())
    {
        initWithAudioFileCount(1);
        return true;
    }
    
    return false;
}

void PerformceAudioEngineScene::initWithAudioFileCount(unsigned int audioFileCount)
{
    auto s = Director::getInstance()->getWinSize();
    
    _currentAudioCount = audioFileCount;
    _fileCount = ARRAY_SIZE(__audioFiles);
    
    MenuItemFont::setFontSize(65);
    auto decrease = MenuItemFont::create(" - ", [&](Ref *sender) {
        _currentAudioCount -= kAudioFileCountIncrease;
        if( _currentAudioCount < 0 )
            _currentAudioCount = 0;
        
        updateLabelOfAudioCount();
        updateAudioCount();
        updateProfilerName();
        AudioEngine::stopAll();
        CC_PROFILER_PURGE_ALL();
    });
    decrease->setColor(Color3B(0,200,20));

    auto increase = MenuItemFont::create(" + ", [&](Ref *sender) {
        _currentAudioCount += kAudioFileCountIncrease;
        if( _currentAudioCount > kMaxAudioFileCount )
            _currentAudioCount = kMaxAudioFileCount;
        
        updateLabelOfAudioCount();
        updateAudioCount();
        updateProfilerName();
        AudioEngine::stopAll();
        CC_PROFILER_PURGE_ALL();
    });
    increase->setColor(Color3B(0,200,20));
    
    _menu = Menu::create(decrease, increase, nullptr);
    _menu->alignItemsHorizontally();
    _menu->setPosition(Vec2(s.width/2, s.height/2+15));
    addChild(_menu, 1);
    
    _tipLabel = Label::createWithTTF("Play 0 Audio files", "fonts/Marker Felt.ttf", 30);
    _tipLabel->setColor(Color3B(0,200,20));
    _tipLabel->setPosition(Vec2(s.width/2, s.height/2-15));
    addChild(_tipLabel, 1, kTagInfoLayer);
    
    updateLabelOfAudioCount();
    updateAudioCount();
    updateProfilerName();
}

std::string PerformceAudioEngineScene::title() const
{
    return "No title";
}

std::string PerformceAudioEngineScene::subtitle() const
{
    return "";
}

void PerformceAudioEngineScene::updateLabelOfAudioCount()
{
    auto infoLabel = static_cast<Label*>( getChildByTag(kTagInfoLayer) );
    char str[20] = {0};
    sprintf(str, "Play %u Audio files", _currentAudioCount);
    infoLabel->setString(str);
}

const char * PerformceAudioEngineScene::profilerName()
{
    return _profilerName;
}

void PerformceAudioEngineScene::updateProfilerName()
{
    snprintf(_profilerName, sizeof(_profilerName)-1, "%s(%d)", testName(), _currentAudioCount);
}

void PerformceAudioEngineScene::onExitTransitionDidStart()
{
    Scene::onExitTransitionDidStart();
    
    auto director = Director::getInstance();
    auto sched = director->getScheduler();
    
    sched->unschedule(CC_SCHEDULE_SELECTOR(PerformceAudioEngineScene::dumpProfilerInfo), this);
    
    AudioEngine::uncacheAll();
}

void PerformceAudioEngineScene::onEnterTransitionDidFinish()
{
    Scene::onEnterTransitionDidFinish();
    
    auto director = Director::getInstance();
    auto sched = director->getScheduler();
    
    CC_PROFILER_PURGE_ALL();
    sched->schedule(CC_SCHEDULE_SELECTOR(PerformceAudioEngineScene::dumpProfilerInfo), this, 2, false);
}

void PerformceAudioEngineScene::dumpProfilerInfo(float dt)
{
    CC_PROFILER_DISPLAY_TIMERS();
}

////////////////////////////////////////////////////////
//
// Play2dAfterPreload
//
////////////////////////////////////////////////////////
void Play2dAfterPreload::updateAudioCount()
{
    _currentIndex++;
    _isPlayOver = true;
    _playOverCount = 0;
    
    log("Play2dAfterPreload::updateAudioCount, index = %d", _currentIndex);
}

void Play2dAfterPreload::initWithAudioFileCount(unsigned int audioFileCount)
{
    PerformceAudioEngineScene::initWithAudioFileCount(audioFileCount);
    
    _isPreloadFinished = false;
    _preloadedCount = 0;
    _isPlayOver = true;
    _playOverCount = 0;
    _currentIndex = 0;
    
    scheduleUpdate();
    
    int count = ARRAY_SIZE(__audioFiles);
    for (int i = 0; i < count; ++i)
    {
        AudioEngine::preload(__audioFiles[i], [=](bool isSucceed){
            if (isSucceed)
            {
                _preloadedCount++;
                if (_preloadedCount == count)
                {
                    _preloadedCount = 0;
                    _isPreloadFinished = true;
                }
            }
        });
    }
}

void Play2dAfterPreload::update(float dt)
{
    if (!_isPreloadFinished || !_isPlayOver)
        return;
    
    _isPlayOver = false;
    
    CC_PROFILER_START(profilerName());

    int count = ARRAY_SIZE(__audioFiles);
    
    for (int i = 0; i < _currentAudioCount; ++i)
    {
        int captureIndex = _currentIndex;
        int audioId = AudioEngine::play2d(__audioFiles[i % count]);
        assert(audioId != -1);
        
        AudioEngine::setFinishCallback(audioId, [=](int id, const std::string& path){
            if (_currentIndex != captureIndex)
                return;
            
            _playOverCount++;
            if (_playOverCount == _currentAudioCount)
            {
                _isPlayOver = true;
                _playOverCount = 0;
            }
        });
    }
    
    CC_PROFILER_STOP(profilerName());
}

std::string Play2dAfterPreload::title() const
{
    return "Play2d after preload";
}

std::string Play2dAfterPreload::subtitle() const
{
    return "Play2d after preload test. See console";
}

const char*  Play2dAfterPreload::testName()
{
    return "AudioEngine::play2d, after preload";
}

////////////////////////////////////////////////////////
//
// AudioEngineOverloadTest
//
////////////////////////////////////////////////////////
void AudioEngineOverloadTest::updateAudioCount()
{
    log("AudioEngineOverloadTest1::updateAudioCount");
    _playingAudioCount = 0;
}

void AudioEngineOverloadTest::initWithAudioFileCount(unsigned int audioFileCount)
{
    PerformceAudioEngineScene::initWithAudioFileCount(audioFileCount);
    
    _menu->setVisible(false);
    _tipLabel->setVisible(false);

    _isPreloadFinished = false;
    _preloadedCount = 0;
    _updateCounter = 0;
    
    scheduleUpdate();
    
    int count = ARRAY_SIZE(__audioFiles);
    for (int i = 0; i < count; ++i)
    {
        AudioEngine::preload(__audioFiles[i], [=](bool isSucceed){
            if (isSucceed)
            {
                _preloadedCount++;
                if (_preloadedCount == count)
                {
                    _preloadedCount = 0;
                    _isPreloadFinished = true;
                }
            }
        });
    }
}

void AudioEngineOverloadTest::update(float dt)
{
    if (!_isPreloadFinished || _playingAudioCount > kMaxAudioFileCount)
        return;
 
    _updateCounter++;
    if (_updateCounter % 5 == 0)
    {
        std::string filePath = grabAudioFilePath();
        
        CC_PROFILER_START(profilerName());
        
        int audioId = AudioEngine::play2d(filePath);
        assert(audioId != -1);
        
        AudioEngine::setFinishCallback(audioId, [=](int id, const std::string& path){
            _playingAudioCount--;
        });

        CC_PROFILER_STOP(profilerName());
        _playingAudioCount++;
    }
}


std::string AudioEngineOverloadTest::subtitle() const
{
    return "see console and use 'adb shell top -m 10' to check CPU usage";
}

////////////////////////////////////////////////////////
//
// AudioEngineOverloadTest1
//
////////////////////////////////////////////////////////

std::string AudioEngineOverloadTest1::grabAudioFilePath()
{
    return __audioFiles[0];
}

std::string AudioEngineOverloadTest1::title() const
{
    return "Audio Overload Test 1, play the same files";
}

const char*  AudioEngineOverloadTest1::testName()
{
    return "audio overload test 1";
}

////////////////////////////////////////////////////////
//
// AudioEngineOverloadTest2
//
////////////////////////////////////////////////////////

AudioEngineOverloadTest2::AudioEngineOverloadTest2()
: _playIndex(0)
{
    
}

std::string AudioEngineOverloadTest2::grabAudioFilePath()
{
    _playIndex++;
    return __audioFiles[_playIndex % _fileCount];
}

std::string AudioEngineOverloadTest2::title() const
{
    return "Audio Overload Test 2, play different files";
}

const char*  AudioEngineOverloadTest2::testName()
{
    return "audio overload test 2";
}