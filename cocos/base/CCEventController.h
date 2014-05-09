/****************************************************************************
 Copyright (c) 2014 cocos2d-x.org
 Copyright (c) 2014 Chukong Technologies Inc.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __cocos2d_libs__EventController__
#define __cocos2d_libs__EventController__

#include "base/CCPlatformMacros.h"
#include "base/CCEvent.h"

NS_CC_BEGIN

class ControllerButtonInput;
class ControllerDirectionPad;
class ControllerElement;
class Controller;

class EventController : public Event
{
public:
    enum class ControllerEventType
    {
        CONNECTION,
        BUTTON_STATUS_CHANGED,
        AXIS_STATUS_CHANGED,
    };
    
	EventController(ControllerEventType type, Controller* controller, ControllerButtonInput* button);
    EventController(ControllerEventType type, Controller* controller, ControllerDirectionPad* dpad);
    EventController(ControllerEventType type, Controller* controller, bool isConnected);

    ControllerEventType getControllerEventType() const;
    Controller* getController() const;
    ControllerElement* getControllerElement() const;
    bool isConnected() const;
    
protected:
    ControllerEventType _controllerEventType;
    ControllerElement* _element;
    Controller* _controller;
    bool _isConnected;
};

NS_CC_END

#endif /* defined(__cocos2d_libs__EventController__) */
