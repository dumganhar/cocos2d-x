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
: _fileURL(nil)
, _extRef(nullptr)
, _format(AL_FORMAT_STEREO16)
, _sampleRate(-1)
, _totalFrames(0)
, _currentFrameIndex(0)
{
    memset(&_inFormat, 0, sizeof(AudioStreamBasicDescription));
    memset(&_outFormat, 0, sizeof(AudioStreamBasicDescription));
}

AudioFrameProviderApple::~AudioFrameProviderApple()
{
    if (_fileURL != nil)
    {
        CFRelease(_fileURL);
    }
    
    if (_extRef != nullptr)
    {
        ExtAudioFileDispose(_extRef);
    }
}

bool AudioFrameProviderApple::init(const std::string& url)
{
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
        
        ret = true;
    } while (false);
    
    return ret;
}

int AudioFrameProviderApple::read(AudioFrameBuffer* ioFrame)
{
    if (ioFrame == nullptr)
    {
        ALOGE("%s, ioFrame is null", __PRETTY_FUNCTION__);
        return -1;
    }
    
    SInt64 toReadFrameCount = ioFrame->frameCount;
    SInt64 remainingFrameCount = _totalFrames - _currentFrameIndex;
    
    if (remainingFrameCount <= 0)
    {
        ALOGE("%s, remainingFrameCount is 0", __PRETTY_FUNCTION__);
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
    
    UInt32 currentReadFrameCount = 0;
    UInt32 remainingToReadFrameCount = (UInt32)toReadFrameCount;
    
    do
    {
        AudioBufferList bufferList;
        bufferList.mNumberBuffers = 1;
        
        bufferList.mBuffers[0].mNumberChannels = _outFormat.mChannelsPerFrame;
        bufferList.mBuffers[0].mDataByteSize = remainingToReadFrameCount * 2;
        bufferList.mBuffers[0].mData = (void*)(ioFrame->raw + currentReadFrameCount * 2);
        
        UInt32 frameCount = remainingToReadFrameCount;
        OSStatus status = ExtAudioFileRead(_extRef, &frameCount, &bufferList);
        
        if (status)
        {
            ALOGE("%s, ExtAudioFileRead failed!", __PRETTY_FUNCTION__);
            return -1;
        }
        
        currentReadFrameCount += frameCount;
        remainingToReadFrameCount -= frameCount;
    
    } while (currentReadFrameCount < (UInt32)toReadFrameCount);
    
    _currentFrameIndex += toReadFrameCount;
    ioFrame->frameCount = ((int)toReadFrameCount);
    
    return (int)toReadFrameCount;
}

int AudioFrameProviderApple::tell() const
{
    return (int)_currentFrameIndex;
}

int AudioFrameProviderApple::seek(int frameIndex)
{
    if (frameIndex >= _totalFrames)
        return -1;
    
    _currentFrameIndex = frameIndex;
    
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
