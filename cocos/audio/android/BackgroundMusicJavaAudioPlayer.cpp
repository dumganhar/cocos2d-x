#include "audio/android/BackgroundMusicJavaAudioPlayer.h"
#include "platform/android/jni/JniHelper.h"
#include "audio/android/ccdandroidUtils.h"

// Java class
static const std::string HELPER_CLASS_NAME = "org/cocos2dx/lib/Cocos2dxHelper";

#define LOG_TAG "BackgroundMusicJavaAudioPlayer"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

namespace {
    cocos2d::experimental::BackgroundMusicJavaAudioPlayer* __bgMusicInstance = nullptr;
}
extern "C" {

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxMusic_nativeOnBackgroundMusicCompletion(JNIEnv* env, jobject thiz, jint reason)
{
    LOGD("Java_org_cocos2dx_lib_Cocos2dxMusic_nativeOnBackgroundMusicCompletion ...");
    if (__bgMusicInstance != nullptr)
    {
        auto cb = __bgMusicInstance->getPlayEventCallback();
        if (cb != nullptr)
        {
            cb(cocos2d::experimental::IAudioPlayer::State::OVER);
        }
    }
}

} // extern "C"

namespace cocos2d { namespace experimental {

/* static */
void BackgroundMusicJavaAudioPlayer::stopPreviousBackgroundMusic()
{
    if (__bgMusicInstance != nullptr)
    {
        __bgMusicInstance->stop();
        __bgMusicInstance = nullptr;
    }
}

/* static */
void BackgroundMusicJavaAudioPlayer::preloadBackgroundMusic(const std::string& filePath)
{
    std::string fullPath = CocosDenshion::android::getFullPathWithoutAssetsPrefix(filePath.c_str());
    JniHelper::callStaticVoidMethod(HELPER_CLASS_NAME, "preloadBackgroundMusic", fullPath);
}

BackgroundMusicJavaAudioPlayer::BackgroundMusicJavaAudioPlayer()
: _id(-1)
, _volume(0.0f)
, _duration(0.0f)
, _isLoop(false)
, _isAudioFocus(false)
, _state(State::INVALID)
, _playEventCallback(nullptr)
{
    __bgMusicInstance = this;
}

BackgroundMusicJavaAudioPlayer::~BackgroundMusicJavaAudioPlayer()
{
    LOGD("In the destructor of BackgroundMusicJavaAudioPlayer: %p", this);
    __bgMusicInstance = nullptr;
}

void BackgroundMusicJavaAudioPlayer::play()
{
    setState(State::PLAYING);
    std::string fullPath = CocosDenshion::android::getFullPathWithoutAssetsPrefix(_url.c_str());
    JniHelper::callStaticVoidMethod(HELPER_CLASS_NAME, "playBackgroundMusic", fullPath, _isLoop);
}

void BackgroundMusicJavaAudioPlayer::pause()
{
    setState(State::PAUSED);
    JniHelper::callStaticVoidMethod(HELPER_CLASS_NAME, "pauseBackgroundMusic");
}

void BackgroundMusicJavaAudioPlayer::resume()
{
    setState(State::PLAYING);
    JniHelper::callStaticVoidMethod(HELPER_CLASS_NAME, "resumeBackgroundMusic");
}

void BackgroundMusicJavaAudioPlayer::stop()
{
    JniHelper::callStaticVoidMethod(HELPER_CLASS_NAME, "stopBackgroundMusic");
    setState(State::STOPPED);
    if (_playEventCallback != nullptr)
    {
        _playEventCallback(IAudioPlayer::State::STOPPED);
    }
    delete this;
}

void BackgroundMusicJavaAudioPlayer::rewind()
{
    setState(State::PLAYING);
    JniHelper::callStaticVoidMethod(HELPER_CLASS_NAME, "rewindBackgroundMusic");
}

void BackgroundMusicJavaAudioPlayer::setVolume(float volume)
{
    _volume = volume;
    if (_isAudioFocus)
    {
        JniHelper::callStaticVoidMethod(HELPER_CLASS_NAME, "setBackgroundMusicVolume", volume);
    }
}

float BackgroundMusicJavaAudioPlayer::getVolume() const
{
    return _volume;
}

void BackgroundMusicJavaAudioPlayer::setAudioFocus(bool isFocus)
{
    _isAudioFocus = isFocus;
    float volume = _isAudioFocus ? _volume : 0.0f;
    JniHelper::callStaticVoidMethod(HELPER_CLASS_NAME, "setBackgroundMusicVolume", volume);
}

void BackgroundMusicJavaAudioPlayer::setLoop(bool isLoop)
{
    _isLoop = isLoop;
    JniHelper::callStaticVoidMethod(HELPER_CLASS_NAME, "setBackgroundMusicLoop", isLoop);
}

bool BackgroundMusicJavaAudioPlayer::isLoop() const
{
    return _isLoop;
}

float BackgroundMusicJavaAudioPlayer::getDuration() const
{
    int durationInMilliSeconds = JniHelper::callStaticIntMethod(HELPER_CLASS_NAME, "getBackgroundMusicDuration");
    if (durationInMilliSeconds < 0)
    {
        return -1.0f;
    }

    return durationInMilliSeconds / 1000.0f;
}

float BackgroundMusicJavaAudioPlayer::getPosition() const
{
    int positionInMilliSeconds = JniHelper::callStaticIntMethod(HELPER_CLASS_NAME, "getBackgroundMusicPosition");
    if (positionInMilliSeconds < 0)
    {
        return 0.0f;
    }

    return positionInMilliSeconds / 1000.0f;
}

bool BackgroundMusicJavaAudioPlayer::setPosition(float pos)
{
    float milliSecond = 1000.0f * pos;

    JniHelper::callStaticVoidMethod(HELPER_CLASS_NAME, "setBackgroundMusicPosition", milliSecond);

    return true;
}

void BackgroundMusicJavaAudioPlayer::setPlayEventCallback(const PlayEventCallback &playEventCallback)
{
    _playEventCallback = playEventCallback;
}

bool BackgroundMusicJavaAudioPlayer::prepare(const std::string &url)
{
    _url = url;
    setState(State::INITIALIZED);
    return true;
}

const IAudioPlayer::PlayEventCallback& BackgroundMusicJavaAudioPlayer::getPlayEventCallback() const
{
    return _playEventCallback;
}

}} // namespace cocos2d { namespace experimental {
