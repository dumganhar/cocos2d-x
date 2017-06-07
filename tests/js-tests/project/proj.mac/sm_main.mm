//
//  sm_main.c
//  TestV8
//
//  Created by James Chen on 4/20/17.
//  Copyright © 2017 James Chen. All rights reserved.
//

#import <Foundation/Foundation.h>

#include <stdio.h>
#include <functional>

int main_accessjs(int argc, char** argv);
int main_register_class(int argc, char** argv);
int main_registerfunction(int argc, char** argv);
int main_helloworld(int argc, char** argv);

//@interface NSTimerWrapper : NSObject
//{
//    std::function<void()> _timeoutCallback;
//}
//
//@end
//
//@implementation NSTimerWrapper
//
//-(id) initWithTimeInterval:(double) seconds callback:(const std::function<void()>&) cb
//{
//    if (self = [super init])
//    {
//        _timeoutCallback = cb;
//        NSTimer* timer = [NSTimer timerWithTimeInterval:seconds target: self selector:@selector(onTimeoutCallback:) userInfo:nil repeats:NO];
//        [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSDefaultRunLoopMode];
//    }
//
//    return self;
//}
//
//-(void) onTimeoutCallback: (NSTimer*) timer
//{
//    if (_timeoutCallback != nullptr)
//    {
//        _timeoutCallback();
//        _timeoutCallback = nullptr;
//    }
//}
//
//
//@end
//
//void setTimeout(double seconds, const std::function<void()>& cb)
//{
//    [[NSTimerWrapper alloc] initWithTimeInterval:seconds callback:cb];
//}


int test_main(int argc, char* argv[])
{
    main_register_class(argc, argv);
    return 0;
}

