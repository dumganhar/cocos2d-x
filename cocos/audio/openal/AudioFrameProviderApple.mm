//
//  AudioFrameProviderApple.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#define LOG_TAG "AudioFrameProviderApple"

#include "AudioFrameProviderApple.h"
#include "AudioUtils.h"
#include "AudioFrameBuffer.h"

#import <Foundation/Foundation.h>
#import <OpenAL/alc.h>
#import <AudioToolbox/ExtendedAudioFile.h>


AudioFrameProviderApple::AudioFrameProviderApple()
: _isOpened(false)
, _fileURL(nil)
, _extRef(nullptr)
, _sampleRate(-1)
, _totalFrames(0)
, _currentFrameIndex(0)
, _bufferList(nullptr)
{
    memset(&_inFormat, 0, sizeof(AudioStreamBasicDescription));
    memset(&_outFormat, 0, sizeof(AudioStreamBasicDescription));
}

AudioFrameProviderApple::~AudioFrameProviderApple()
{
    close();
}

bool AudioFrameProviderApple::open(const std::string& url)
{
    if (_isOpened)
    {
        ALOGE("%s was opened!", url.c_str());
        return false;
    }
    
    _url = url;
    bool ret = false;
    do
    {
        UInt32 propertySize = 0;
        
        NSString* filePath = [[NSString alloc] initWithCString:url.c_str() encoding:NSUTF8StringEncoding];
        _fileURL = (CFURLRef)[[NSURL alloc] initFileURLWithPath:filePath];
        [filePath release];
        
        OSStatus error = ExtAudioFileOpenURL(_fileURL, &_extRef);
        if (error)
        {
            ALOGE("%s: ExtAudioFileOpenURL FAILED, Error = %ld", __PRETTY_FUNCTION__, (long)error);
            break;
        }
        
        // Get the audio data format
        propertySize = sizeof(AudioStreamBasicDescription);
        error = ExtAudioFileGetProperty(_extRef, kExtAudioFileProperty_FileDataFormat, &propertySize, &_inFormat);
        
        if (error)
        {
            ALOGE("%s: ExtAudioFileGetProperty(kExtAudioFileProperty_FileDataFormat) FAILED, Error = %ld", __PRETTY_FUNCTION__, (long)error);
            break;
        }
        
        if (_inFormat.mChannelsPerFrame > 2)
        {
            ALOGE("%s: Unsupported Format, channel count is greater than stereo",__PRETTY_FUNCTION__);
            break;
        }
        
        // Set the client format to 16 bit signed integer (native-endian) data
        // Maintain the channel count and sample rate of the original source format
        _outFormat.mSampleRate = _inFormat.mSampleRate;
        _outFormat.mChannelsPerFrame = _inFormat.mChannelsPerFrame;
        
        UInt32 bytesPerFrame = 2 * _outFormat.mChannelsPerFrame;
        _outFormat.mFormatID = kAudioFormatLinearPCM;
        _outFormat.mBytesPerPacket = bytesPerFrame;
        _outFormat.mFramesPerPacket = 1;
        _outFormat.mBytesPerFrame = bytesPerFrame;
        _outFormat.mBitsPerChannel = 16;
        _outFormat.mFormatFlags = kAudioFormatFlagsNativeEndian | kAudioFormatFlagIsPacked | kAudioFormatFlagIsSignedInteger;
        
        error = ExtAudioFileSetProperty(_extRef, kExtAudioFileProperty_ClientDataFormat, sizeof(_outFormat), &_outFormat);
        
        if (error)
        {
            ALOGE("%s: ExtAudioFileSetProperty FAILED, Error = %ld", __PRETTY_FUNCTION__, (long)error);
            break;
        }
        
        // Get the total frame count
        propertySize = sizeof(_totalFrames);
        error = ExtAudioFileGetProperty(_extRef, kExtAudioFileProperty_FileLengthFrames, &propertySize, &_totalFrames);
        
        if (error)
        {
            ALOGE("%s: ExtAudioFileGetProperty(kExtAudioFileProperty_FileLengthFrames) FAILED, Error = %ld", __PRETTY_FUNCTION__, (long)error);
            break;
        }
        
        _sampleRate = (ALsizei)_outFormat.mSampleRate;
        
        _bufferList = new AudioBufferList();
        _bufferList->mNumberBuffers = 1;
        _bufferList->mBuffers[0].mNumberChannels = _outFormat.mChannelsPerFrame;
        
        ret = true;
        _isOpened = true;
    } while (false);
    
    return ret;
}

void AudioFrameProviderApple::close()
{
    if (_fileURL != nil)
    {
        CFRelease(_fileURL);
        _fileURL = nil;
    }
    
    if (_extRef != nullptr)
    {
        ExtAudioFileDispose(_extRef);
        _extRef = nullptr;
    }
    
    if (_bufferList != nullptr)
    {
        delete _bufferList;
        _bufferList = nullptr;
    }
}

int AudioFrameProviderApple::read(AudioFrameBuffer* ioFrame)
{
    if (!_isOpened)
    {
        ALOGE("not opened!");
        return -1;
    }
    
    if (ioFrame == nullptr)
    {
        ALOGE("%s, ioFrame is null", __PRETTY_FUNCTION__);
        return -1;
    }
    
    SInt64 toReadFrameCount = ioFrame->frameCount;
    SInt64 remainingFrameCount = _totalFrames - _currentFrameIndex;
    
    if (remainingFrameCount <= 0)
    {
        ALOGV("%s, remainingFrameCount is 0", __PRETTY_FUNCTION__);
        return -1;
    }
    
    if (toReadFrameCount <= 0)
    {
        ALOGE("%s, toReadFrameCount is 0", __PRETTY_FUNCTION__);
        return -1;
    }
    
    if (toReadFrameCount > remainingFrameCount)
    {
        toReadFrameCount = remainingFrameCount;
    }
    
    ALOGV("toReadFrameCount=%d, remainingFrameCount=%d", (int)toReadFrameCount, (int)remainingFrameCount);
    
    UInt32 currentReadFrameCount = 0;
    UInt32 remainingToReadFrameCount = (UInt32)toReadFrameCount;
    
    do
    {
        _bufferList->mBuffers[0].mDataByteSize = remainingToReadFrameCount * _outFormat.mBytesPerFrame;
        _bufferList->mBuffers[0].mData = (void*)(ioFrame->raw + currentReadFrameCount * _outFormat.mBytesPerFrame);
        
        UInt32 frameCount = remainingToReadFrameCount;
        OSStatus status = ExtAudioFileRead(_extRef, &frameCount, _bufferList);

        if (status)
        {
            ALOGE("%s, ExtAudioFileRead failed!", __PRETTY_FUNCTION__);
            return -1;
        }
        
        currentReadFrameCount += frameCount;
        remainingToReadFrameCount -= frameCount;
        ALOGV("read frame: %d, remain: %d", currentReadFrameCount, remainingToReadFrameCount);
    } while (currentReadFrameCount < (UInt32)toReadFrameCount);
    
    _currentFrameIndex += toReadFrameCount;
    ioFrame->frameCount = ((int)toReadFrameCount);
    ioFrame->bytesPerFrame = _outFormat.mBytesPerFrame;
    
    return (int)toReadFrameCount;
}

int AudioFrameProviderApple::tell() const
{
    return (int)_currentFrameIndex;
}

int AudioFrameProviderApple::seek(int frameIndex)
{
    if (!_isOpened)
    {
        ALOGE("not opened!");
        return -1;
    }
    
    if (frameIndex >= _totalFrames)
        return -1;
    
    _currentFrameIndex = frameIndex;
    ExtAudioFileSeek(_extRef, _currentFrameIndex);
    
    return (int)_currentFrameIndex;
}

int AudioFrameProviderApple::getTotalFrames() const
{
    return (int)_totalFrames;
}

int AudioFrameProviderApple::getSampleRate() const
{
    return (int)_sampleRate;
}

int AudioFrameProviderApple::getBytesPerFrame() const
{
    if (!_isOpened)
    {
        ALOGE("not opened!");
        return -1;
    }
    
    return _outFormat.mBytesPerFrame;
}

float AudioFrameProviderApple::getDuration() const
{
    return 1.0f * _totalFrames / _sampleRate;
}
