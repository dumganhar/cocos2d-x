#include "AppDelegate.h"
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <android/log.h>
#include <android/api-level.h>

using namespace cocos2d;

#define LOG_TAG "main"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

// ndk break compatibility, refer to https://github.com/cocos2d/cocos2d-x/issues/16267 for detail information
// should remove it when using NDK r13 since NDK r13 will add back bsd_signal()
#if 1//__ANDROID_API__ > 19
#include <signal.h>
#include <dlfcn.h>
extern "C" {
    __sighandler_t bsd_signal(int s, __sighandler_t f) {
    return signal(s, f);
    }
}
#endif // __ANDROID_API__ > 19
 
void cocos_android_app_init (JNIEnv* env) {
    LOGD("cocos_android_app_init");
    AppDelegate *pAppDelegate = new AppDelegate();
}