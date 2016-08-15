//
//  AudioFrame.hpp
//  cocos2d_libs
//
//  Created by James Chen on 8/5/16.
//
//

#ifndef AudioFrame_hpp
#define AudioFrame_hpp

class AudioFrame
{
public:
    AudioFrame(int format, unsigned char* buffer, unsigned int size);
    
    int getFormat();
    unsigned char* getBufferPtr();
    unsigned int getBufferSize();
    
private:
    int _format;
    unsigned char* _buffer;
    unsigned int _size;
};

#endif /* AudioFrame_hpp */
