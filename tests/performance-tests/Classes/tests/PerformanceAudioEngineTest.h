#pragma once


#include "BaseTest.h"

DEFINE_TEST_SUITE(PerformceAudioEngineTests);

class PerformceAudioEngineScene : public TestCase
{
public:
    virtual bool init() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    
    const char* profilerName();
    void updateProfilerName();
    
    // for the profiler
    virtual const char* testName() = 0;
    void dumpProfilerInfo(float dt);
    
    virtual void initWithAudioFileCount(unsigned int audioFileCount);
    virtual void updateAudioCount() = 0;
    virtual void updateLabelOfAudioCount();
    
    // overrides
    virtual void onExitTransitionDidStart() override;
    virtual void onEnterTransitionDidFinish() override;
    
protected:
    PerformceAudioEngineScene();
    
    cocos2d::Menu* _menu;
    cocos2d::Label* _tipLabel;
    
    char _profilerName[256];
    int _currentAudioCount;
    int _fileCount;
};

class Play2dAfterPreload : public PerformceAudioEngineScene
{
public:
    CREATE_FUNC(Play2dAfterPreload);
    
    virtual void update(float dt) override;
    virtual const char* testName() override;
    virtual void updateAudioCount() override;
    virtual void initWithAudioFileCount(unsigned int audioFileCount) override;
    
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    
protected:
    bool _isPreloadFinished;
    bool _isPlayOver;
    int _preloadedCount;
    int _playOverCount;
    int _currentIndex;
};

class AudioEngineOverloadTest : public PerformceAudioEngineScene
{
public:
    virtual std::string subtitle() const override;
    
    virtual void update(float dt) override;
    virtual void updateAudioCount() override;
    virtual void initWithAudioFileCount(unsigned int audioFileCount) override;
    virtual std::string grabAudioFilePath() = 0;

private:
    bool _isPreloadFinished;
    int _preloadedCount;
    int _playingAudioCount;
    int _updateCounter;
};

class AudioEngineOverloadTest1 : public AudioEngineOverloadTest
{
public:
    CREATE_FUNC(AudioEngineOverloadTest1);
    virtual const char* testName() override;
    virtual std::string title() const override;
    virtual std::string grabAudioFilePath() override;
    
private:
};

class AudioEngineOverloadTest2 : public AudioEngineOverloadTest
{
public:
    CREATE_FUNC(AudioEngineOverloadTest2);
    AudioEngineOverloadTest2();
    virtual const char* testName() override;
    virtual std::string title() const override;
    virtual std::string grabAudioFilePath() override;
    
private:
    int _playIndex;
};
