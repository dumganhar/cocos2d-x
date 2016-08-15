//
//  AudioFrame.cpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#include "AudioFrame.h"


AudioFrame::AudioFrame(int format, unsigned char* buffer, unsigned int size)
: _format(format)
, _buffer(buffer)
, _size(size)
{
    
}

int AudioFrame::getFormat()
{
    return 0;
}

unsigned char* AudioFrame::getBufferPtr()
{
    return nullptr;
}

unsigned int AudioFrame::getBufferSize()
{
    return 0;
}