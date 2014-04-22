//
//  EventListenerController.h
//  cocos2d_libs
//
//  Created by James Chen on 4/21/14.
//
//

#ifndef __cocos2d_libs__EventListenerController__
#define __cocos2d_libs__EventListenerController__

#include "CCPlatformMacros.h"
#include "CCEventListener.h"

NS_CC_BEGIN

class Event;
class Controller;
class ControllerButtonInput;
class ControllerElement;
class ControllerDirectionPad;

class EventListenerController : public EventListener
{
public:
    static const std::string LISTENER_ID;
    
	static EventListenerController* create();
    
    /// Overrides
    virtual bool checkAvailable() override;
    virtual EventListenerController* clone() override;
    
	std::function<void(Controller*, Event*)> onConnected;
	std::function<void(Controller*, Event*)> onDisconnected;
    
	std::function<void(Controller*, ControllerButtonInput*, Event*)> onButtonPressed;
	std::function<void(Controller*, ControllerButtonInput*, Event*)> onButtonReleased;
	std::function<void(Controller*, ControllerDirectionPad*, Event*)> onDirectionPadChanged;
    
	std::function<void(Controller*, ControllerElement*, Event*)> onValueChanged;
    
protected:
    bool init();
};

NS_CC_END

#endif /* defined(__cocos2d_libs__EventListenerController__) */
