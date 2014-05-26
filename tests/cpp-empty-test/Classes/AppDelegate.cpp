#include "AppDelegate.h"

#include <vector>
#include <string>

#include "HelloWorldScene.h"
#include "AppMacros.h"

#include "Poco/Notification.h"
#include "Poco/NotificationQueue.h"
#include "Poco/ThreadPool.h"
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/Mutex.h"
//#include "Poco/Random.h"
#include "Poco/AutoPtr.h"
#include <iostream>


using Poco::Notification;
using Poco::NotificationQueue;
using Poco::ThreadPool;
using Poco::Thread;
using Poco::Runnable;
using Poco::FastMutex;
using Poco::AutoPtr;


class WorkNotification: public Notification
// The notification sent to worker threads.
{
public:
	typedef AutoPtr<WorkNotification> Ptr;
	
	WorkNotification(int data):
    _data(data)
	{
	}
	
	int data() const
	{
		return _data;
	}
    
private:
	int _data;
};


class Worker
// A worker thread that gets work items
// from a NotificationQueue.
{
public:
	Worker(const std::string& name, NotificationQueue& queue):
    _name(name),
    _queue(queue)
	{
	}
	
	void run()
	{
//		Poco::Random rnd;
		for (;;)
		{
			Notification::Ptr pNf(_queue.waitDequeueNotification());
			if (pNf)
			{
				WorkNotification::Ptr pWorkNf = pNf.cast<WorkNotification>();
				if (pWorkNf)
				{
					{
						FastMutex::ScopedLock lock(_mutex);
						std::cout << _name << " got work notification " << pWorkNf->data() << std::endl;
					}
					Thread::sleep(200);
				}
			}
			else break;
		}
	}
	
private:
	std::string        _name;
	NotificationQueue& _queue;
	static FastMutex   _mutex;
};


FastMutex Worker::_mutex;

void foo(bool bo, int a, float b)
{
    printf("a:%d, b:%f\n", a, b);
}

int poco_main()
{
    
    std::function<void(bool)> aaa = std::bind(&foo, std::placeholders::_1, 4, 5.1f);
    aaa(false);
    static FastMutex   _mutex;
	NotificationQueue queue;
	
	// create some worker threads
//	Worker worker1("Worker 1", queue);
//	Worker worker2("Worker 2", queue);
//	Worker worker3("Worker 3", queue);
    
    auto run = [&](std::string name)
	{
        //		Poco::Random rnd;
		for (;;)
		{
			Notification::Ptr pNf(queue.waitDequeueNotification());
			if (pNf)
			{
				WorkNotification::Ptr pWorkNf = pNf.cast<WorkNotification>();
				if (pWorkNf)
				{
					{
						FastMutex::ScopedLock lock(_mutex);
						std::cout << name << " got work notification " << pWorkNf->data() << std::endl;
					}
					Thread::sleep(200);
				}
			}
			else break;
		}
	};
    
    for (int i = 0; i < 50; ++i)
    {
        // start worker threads
        ThreadPool::defaultPool().start([run, i](){
            char buf[30] = {0};
            sprintf(buf, "Worker%d", i);
            run(buf);
        });
    }

	// distribute some work
	for (int i = 0; i < 50; ++i)
	{
		queue.enqueueNotification(new WorkNotification(i));
	}
	
	// wait until queue is empty and all threads are
	// waiting for new work.
	while (!queue.empty()) Thread::sleep(200);
	Thread::sleep(500);
	
	// stop all worker threads
	queue.wakeUpAll();
	ThreadPool::defaultPool().joinAll();
	
	return 0;
}


USING_NS_CC;
using namespace std;




AppDelegate::AppDelegate() {
//    poco_main();
}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("Cpp Empty Test");
        director->setOpenGLView(glview);
    }

    director->setOpenGLView(glview);

    // Set the design resolution
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    // a bug in DirectX 11 level9-x on the device prevents ResolutionPolicy::NO_BORDER from working correctly
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::SHOW_ALL);
#else
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
#endif

	Size frameSize = glview->getFrameSize();
    
    vector<string> searchPath;

    // In this demo, we select resource according to the frame's height.
    // If the resource size is different from design resolution size, you need to set contentScaleFactor.
    // We use the ratio of resource's height to the height of design resolution,
    // this can make sure that the resource's height could fit for the height of design resolution.

    // if the frame's height is larger than the height of medium resource size, select large resource.
	if (frameSize.height > mediumResource.size.height)
	{
        searchPath.push_back(largeResource.directory);

        director->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
	}
    // if the frame's height is larger than the height of small resource size, select medium resource.
    else if (frameSize.height > smallResource.size.height)
    {
        searchPath.push_back(mediumResource.directory);
        
        director->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium resource size, select small resource.
	else
    {
        searchPath.push_back(smallResource.directory);

        director->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
    }
    
    // set searching path
    FileUtils::getInstance()->setSearchPaths(searchPath);
	
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::scene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
