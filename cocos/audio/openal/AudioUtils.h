#pragma once

#include "audio/openal/cutils/log.h"

#define QUEUEBUFFER_NUM 3
#define QUEUEBUFFER_TIME_STEP 0.1

#define QUOTEME_(x) #x
#define QUOTEME(x) QUOTEME_(x)

#if defined(COCOS2D_DEBUG) && COCOS2D_DEBUG > 0
#define ALOGV(fmt, ...) printf("V/" LOG_TAG " (" QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#else
#define ALOGV(fmt, ...) do {} while(false)
#endif
#define ALOGD(fmt, ...) printf("D/" LOG_TAG " (" QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#define ALOGI(fmt, ...) printf("I/" LOG_TAG " (" QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#define ALOGW(fmt, ...) printf("W/" LOG_TAG " (" QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)
#define ALOGE(fmt, ...) printf("E/" LOG_TAG " (" QUOTEME(__LINE__) "): " fmt "\n", ##__VA_ARGS__)

#if defined(COCOS2D_DEBUG) && COCOS2D_DEBUG > 0
#define CHECK_AL_ERROR_DEBUG() \
do { \
GLenum __error = alGetError(); \
if (__error) { \
ALOGE("OpenAL error 0x%04X in %s %s %d\n", __error, __FILE__, __FUNCTION__, __LINE__); \
} \
} while (false)
#else
#define CHECK_AL_ERROR_DEBUG()
#endif

enum class AudioFormat
{
    PCM_16_BIT,
};

#define clockNow() std::chrono::high_resolution_clock::now()
#define intervalInMS(oldTime, newTime) (static_cast<long>(std::chrono::duration_cast<std::chrono::microseconds>((newTime) - (oldTime)).count()) / 1000.f)

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

