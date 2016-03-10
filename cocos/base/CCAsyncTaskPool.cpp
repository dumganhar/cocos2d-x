/****************************************************************************
Copyright (c) 2010      cocos2d-x.org
Copyright (c) 2013-2014 Chukong Technologies Inc.

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

#include "base/CCAsyncTaskPool.h"
#include "base/CCThreadPool.h"

NS_CC_BEGIN

AsyncTaskPool* AsyncTaskPool::s_asyncTaskPool = nullptr;

static ThreadPool::TaskType asyncTaskTypeToThreadPoolTaskType(AsyncTaskPool::TaskType type)
{
    ThreadPool::TaskType t = ThreadPool::TASK_TYPE_DEFAULT;
    
    if (type == AsyncTaskPool::TaskType::TASK_IO)
    {
        t = ThreadPool::TASK_TYPE_IO;
    } else if (type == AsyncTaskPool::TaskType::TASK_NETWORK)
    {
        t = ThreadPool::TASK_TYPE_NETWORK;
    }
    return t;
}

AsyncTaskPool* AsyncTaskPool::getInstance()
{
    if (s_asyncTaskPool == nullptr)
    {
        s_asyncTaskPool = new (std::nothrow) AsyncTaskPool();
    }
    return s_asyncTaskPool;
}

void AsyncTaskPool::destroyInstance()
{
    delete s_asyncTaskPool;
    s_asyncTaskPool = nullptr;
}

AsyncTaskPool::AsyncTaskPool()
{
}

AsyncTaskPool::~AsyncTaskPool()
{
}

void AsyncTaskPool::stopTasks(TaskType type)
{
    ThreadPool::getDefaultThreadPool()->stopTasksByType(asyncTaskTypeToThreadPoolTaskType(type));
}

void AsyncTaskPool::enqueue(TaskType type, const TaskCallBack& callback, void* callbackParam, const std::function<void()>& f)
{
    ThreadPool::getDefaultThreadPool()->pushTask([callback, callbackParam, f](int tid){
        f();
        
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([callback, callbackParam](){
            callback(callbackParam);
        });
    }, asyncTaskTypeToThreadPoolTaskType(type));
}

NS_CC_END
