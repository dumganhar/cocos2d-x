/****************************************************************************
Copyright (c) 2013-2015 Chukong Technologies Inc.

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

#ifndef __CCSYNC_TASK_POOL_H_
#define __CCSYNC_TASK_POOL_H_

#include "platform/CCPlatformMacros.h"
#include "base/CCDirector.h"
#include "base/CCScheduler.h"

#include <functional>

/**
* @addtogroup base
* @{
*/
NS_CC_BEGIN


/**
 * @class AsyncTaskPool
 * @brief This class allows to perform background operations without having to manipulate threads.
 * @js NA
 */
class CC_DLL AsyncTaskPool
{
public:
    typedef std::function<void(void*)> TaskCallBack;
    
    enum class TaskType
    {
        TASK_IO,
        TASK_NETWORK,
        TASK_OTHER,
        TASK_MAX_TYPE,
    };

    /**
     * Returns the shared instance of the async task pool.
     */
    static AsyncTaskPool* getInstance();

    /**
     * Destroys the async task pool.
     */
    static void destroyInstance();
    
    /** @deprecated Use method destroyInstance() instead. */
    CC_DEPRECATED_ATTRIBUTE static void destoryInstance() { return destroyInstance(); }
    
    /**
     * Stop tasks.
     *
     * @param type Task type you want to stop.
     */
    void stopTasks(TaskType type);
    
    /**
     * Enqueue a asynchronous task.
     *
     * @param type task type is io task, network task or others, each type of task has a thread to deal with it.
     * @param callback callback when the task is finished. The callback is called in the main thread instead of task thread.
     * @param callbackParam parameter used by the callback.
     * @param f task can be lambda function.
     * @lua NA
     */
    void enqueue(TaskType type, const TaskCallBack& callback, void* callbackParam, const std::function<void()>& f);
    
CC_CONSTRUCTOR_ACCESS:
    AsyncTaskPool();
    ~AsyncTaskPool();
    
protected:
    static AsyncTaskPool* s_asyncTaskPool;
};


NS_CC_END
// end group
/// @}
#endif //__CCSYNC_TASK_POOL_H_
