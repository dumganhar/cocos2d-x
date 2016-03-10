/****************************************************************************
 Copyright (c) 2012      greathqy
 Copyright (c) 2012      cocos2d-x.org
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

#include "platform/CCPlatformConfig.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#include "HttpClient.h"

#include <queue>
#include <errno.h>

#import "network/HttpAsynConnection-apple.h"
#include "network/HttpCookie.h"
#include "base/CCDirector.h"
#include "base/CCEventDispatcher.h"
#include "base/CCEventListenerCustom.h"
#include "base/CCThreadPool.h"
#include "platform/CCFileUtils.h"

NS_CC_BEGIN

#define LOGD  printf

namespace network {
    
static HttpClient *_httpClient = nullptr; // pointer to singleton

//Process Request
static int processTask(HttpClient* client, HttpRequest* request, NSString* requestType, void* stream, long* responseCode, void* headerStream, std::string& outErrorBuffer)
{
    if (nullptr == client)
    {
        outErrorBuffer = "client object is invalid";
        return 0;
    }
    
    //create request with url
    NSString* urlstring = [NSString stringWithUTF8String:request->getUrl()];
    NSURL *url = [NSURL URLWithString:urlstring];

    NSMutableURLRequest *nsrequest = [NSMutableURLRequest requestWithURL:url
                                               cachePolicy:NSURLRequestReloadIgnoringLocalAndRemoteCacheData
                                           timeoutInterval:HttpClient::getInstance()->getTimeoutForConnect()];
    
    //set request type
    [nsrequest setHTTPMethod:requestType];

    /* get custom header data (if set) */
    std::vector<std::string> headers=request->getHeaders();
    if(!headers.empty())
    {
        /* append custom headers one by one */
        for (std::vector<std::string>::iterator it = headers.begin(); it != headers.end(); ++it)
        {
            unsigned long i = it->find(':', 0);
            unsigned long length = it->size();
            std::string field = it->substr(0, i);
            std::string value = it->substr(i+1, length-i);
            NSString *headerField = [NSString stringWithUTF8String:field.c_str()];
            NSString *headerValue = [NSString stringWithUTF8String:value.c_str()];
            [nsrequest setValue:headerValue forHTTPHeaderField:headerField];
        }
    }

    //if request type is post or put,set header and data
    if([requestType  isEqual: @"POST"] || [requestType isEqual: @"PUT"])
    {
        if ([requestType isEqual: @"PUT"])
        {
            [nsrequest setValue: @"application/x-www-form-urlencoded" forHTTPHeaderField: @"Content-Type"];
        }
        
        char* requestDataBuffer = request->getRequestData();
        if (nullptr !=  requestDataBuffer && 0 != request->getRequestDataSize())
        {
            NSData *postData = [NSData dataWithBytes:requestDataBuffer length:request->getRequestDataSize()];
            [nsrequest setHTTPBody:postData];
        }
    }

    //read cookie propertities from file and set cookie
    std::string cookieFilename = client->getCookieFilename();
    if(!cookieFilename.empty() && nullptr != client->getCookie())
    {
        const CookiesInfo* cookieInfo = client->getCookie()->getMatchCookie(request->getUrl());
        if(cookieInfo != nullptr)
        {
            NSString *domain = [NSString stringWithCString:cookieInfo->domain.c_str() encoding:[NSString defaultCStringEncoding]];
            NSString *path = [NSString stringWithCString:cookieInfo->path.c_str() encoding:[NSString defaultCStringEncoding]];
            NSString *value = [NSString stringWithCString:cookieInfo->value.c_str() encoding:[NSString defaultCStringEncoding]];
            NSString *name = [NSString stringWithCString:cookieInfo->name.c_str() encoding:[NSString defaultCStringEncoding]];

            // create the properties for a cookie
            NSDictionary *properties = [NSDictionary dictionaryWithObjectsAndKeys: name,NSHTTPCookieName,
            value, NSHTTPCookieValue, path, NSHTTPCookiePath,
            domain, NSHTTPCookieDomain,
            nil];
            
            // create the cookie from the properties
            NSHTTPCookie *cookie = [NSHTTPCookie cookieWithProperties:properties];
            
            // add the cookie to the cookie storage
            [[NSHTTPCookieStorage sharedHTTPCookieStorage] setCookie:cookie];
        }
    }
    
    HttpAsynConnection *httpAsynConn = [[HttpAsynConnection new] autorelease];
    httpAsynConn.srcURL = urlstring;
    httpAsynConn.sslFile = nil;
    
    std::string sslCaFileName = client->getSSLVerification();
    if(!sslCaFileName.empty())
    {
        long len = sslCaFileName.length();
        long pos = sslCaFileName.rfind('.', len-1);
        
        httpAsynConn.sslFile = [NSString stringWithUTF8String:sslCaFileName.substr(0, pos).c_str()];
    }
    [httpAsynConn startRequest:nsrequest];
    
    while( httpAsynConn.finish != true)
    {
        [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
    }
    
    //if http connection return error
    if (httpAsynConn.connError != nil)
    {
        NSString* errorString = [httpAsynConn.connError localizedDescription];
        outErrorBuffer = [errorString UTF8String];
        return 0;
    }

    //if http response got error, just log the error
    if (httpAsynConn.responseError != nil)
    {
        NSString* errorString = [httpAsynConn.responseError localizedDescription];
        outErrorBuffer = [errorString UTF8String];
    }
    
    *responseCode = httpAsynConn.responseCode;
    
    //add cookie to cookies vector
    if(!cookieFilename.empty())
    {
        NSArray *cookies = [NSHTTPCookie cookiesWithResponseHeaderFields:httpAsynConn.responseHeader forURL:url];
        for (NSHTTPCookie *cookie in cookies)
        {
            //NSLog(@"Cookie: %@", cookie);
            NSString *domain = cookie.domain;
            //BOOL session = cookie.sessionOnly;
            NSString *path = cookie.path;
            BOOL secure = cookie.isSecure;
            NSDate *date = cookie.expiresDate;
            NSString *name = cookie.name;
            NSString *value = cookie.value;
            
            CookiesInfo cookieInfo;
            cookieInfo.domain = [domain cStringUsingEncoding: NSUTF8StringEncoding];
            cookieInfo.path = [path cStringUsingEncoding: NSUTF8StringEncoding];
            cookieInfo.secure = (secure == YES) ? true : false;
            cookieInfo.expires = [[NSString stringWithFormat:@"%ld", (long)[date timeIntervalSince1970]] cStringUsingEncoding: NSUTF8StringEncoding];
            cookieInfo.name = [name cStringUsingEncoding: NSUTF8StringEncoding];
            cookieInfo.value = [value cStringUsingEncoding: NSUTF8StringEncoding];
            cookieInfo.tailmatch = true;
            
            client->getCookie()->updateOrAddCookie(&cookieInfo);
        }
    }
    
    //handle response header
    NSMutableString *header = [NSMutableString string];
    [header appendFormat:@"HTTP/1.1 %ld %@\n", (long)httpAsynConn.responseCode, httpAsynConn.statusString];
    for (id key in httpAsynConn.responseHeader)
    {
        [header appendFormat:@"%@: %@\n", key, [httpAsynConn.responseHeader objectForKey:key]];
    }
    if (header.length > 0)
    {
        NSRange range = NSMakeRange(header.length-1, 1);
        [header deleteCharactersInRange:range];
    }
    NSData *headerData = [header dataUsingEncoding:NSUTF8StringEncoding];
    std::vector<char> *headerBuffer = (std::vector<char>*)headerStream;
    const void* headerptr = [headerData bytes];
    long headerlen = [headerData length];
    headerBuffer->insert(headerBuffer->end(), (char*)headerptr, (char*)headerptr+headerlen);

    //handle response data
    std::vector<char> *recvBuffer = (std::vector<char>*)stream;
    const void* ptr = [httpAsynConn.responseData bytes];
    long len = [httpAsynConn.responseData length];
    recvBuffer->insert(recvBuffer->end(), (char*)ptr, (char*)ptr+len);
    
    return 1;
}
    
// Process Response
void HttpClient::processResponse(HttpResponse* response)
{
    auto request = response->getHttpRequest();
    long responseCode = -1;
    int retValue = 0;
    NSString* requestType = nil;
    
    // Process the request -> get response packet
    switch (request->getRequestType())
    {
        case HttpRequest::Type::GET: // HTTP GET
            requestType = @"GET";
            break;
            
        case HttpRequest::Type::POST: // HTTP POST
            requestType = @"POST";
            break;
            
        case HttpRequest::Type::PUT:
            requestType = @"PUT";
            break;
            
        case HttpRequest::Type::DELETE:
            requestType = @"DELETE";
            break;
            
        default:
            CCASSERT(true, "CCHttpClient: unknown request type, only GET and POSt are supported");
            break;
    }
    
    std::string errorMessage;
    
    retValue = processTask(this,
                           request,
                           requestType,
                           response->getResponseData(),
                           &responseCode,
                           response->getResponseHeader(),
                           errorMessage);
    
    // write data to HttpResponse
    response->setResponseCode(responseCode);
    
    if (retValue != 0) 
    {
        response->setSucceed(true);
    }
    else
    {
        response->setSucceed(false);
        response->setErrorBuffer(errorMessage.c_str());
    }
}

void HttpClient::handleRequest(HttpRequest* request)
{
    // Create a HttpResponse object, the default setting is http access failed
    HttpResponse *response = new (std::nothrow) HttpResponse(request);  // request ref = 4
    processResponse(response);

    _notHandledResponseQueueMutex.lock();
    _notHandledResponseQueue.pushBack(response);
    _notHandledResponseQueueMutex.unlock();
    
    _schedulerMutex.lock();
    if (_scheduler != nullptr)
    {
        std::shared_ptr<bool> isDestroyed = _isDestroyed;
        
        _scheduler->performFunctionInCocosThread([isDestroyed, this, response, request]{
            
            _notHandledRequestQueueMutex.lock();
            _notHandledResponseQueueMutex.lock();
            
            if (*isDestroyed)
            {
                LOGD("Cocos Thread: HttpClient was destroyed!\n");
            }
            else if (!_notHandledRequestQueue.empty() && !_notHandledResponseQueue.empty())
            {
                const ccHttpRequestCallback& callback = request->getCallback();
                Ref* pTarget = request->getTarget();
                SEL_HttpResponse pSelector = request->getSelector();
                
                if (callback != nullptr)
                {
                    callback(this, response);
                }
                else if (pTarget && pSelector)
                {
                    (pTarget->*pSelector)(this, response);
                }
            }
            
            if (!_notHandledResponseQueue.empty())
            {
                _notHandledResponseQueue.eraseObject(response);
                CC_SAFE_RELEASE(response);    // request ref = 3
            }
            
            if (!_notHandledRequestQueue.empty())
            {
                _notHandledRequestQueue.eraseObject(request);  // request ref = 2
                CC_SAFE_RELEASE(request);     // request ref = 1
            }
            
            _notHandledRequestQueueMutex.unlock();
            _notHandledResponseQueueMutex.unlock();
        });
    }

    _schedulerMutex.unlock();
}

// Worker thread
void HttpClient::networkThreadAlone(HttpRequest* request, unsigned long threadID)
{
    handleRequest(request);
}
    
// HttpClient implementation
HttpClient* HttpClient::getInstance()
{
    if (_httpClient == nullptr) {
        _httpClient = new (std::nothrow) HttpClient();
    }
    
    return _httpClient;
}

void HttpClient::destroyInstance()
{
    if (_httpClient == nullptr)
    {
        LOGD("HttpClient singleton is NULL\n");
        return;
    }
    
    LOGD("HttpClient::destroyInstance ...\n");
    
    auto thiz = _httpClient;
    _httpClient = nullptr;
    
    thiz->_scheduler->unscheduleAllForTarget(thiz);
    
    thiz->_schedulerMutex.lock();
    thiz->_scheduler = nullptr;
    thiz->_schedulerMutex.unlock();
    
    *thiz->_isDestroyed = true;
    
    thiz->cleanup();
    
    LOGD("HttpClient::destroyInstance() finished!\n");
}

void HttpClient::enableCookies(const char* cookieFile) {
    if (cookieFile) {
        _cookieFilename = std::string(cookieFile);
    }
    else {
        _cookieFilename = (FileUtils::getInstance()->getWritablePath() + "cookieFile.txt");
    }
}

void HttpClient::setSSLVerification(const std::string& caFile)
{
    _sslCaFilename = caFile;
}

HttpClient::HttpClient()
: _timeoutForConnect(30)
, _timeoutForRead(60)
, _isDestroyed(std::make_shared<bool>(false))
{
    LOGD("In the constructor of HttpClient!\n");
    _scheduler = Director::getInstance()->getScheduler();
    
    std::shared_ptr<bool> isDestroyed = _isDestroyed;
    _resetDirectorListener = Director::getInstance()->getEventDispatcher()->addCustomEventListener(Director::EVENT_RESET, [this, isDestroyed](EventCustom*){
        if (*isDestroyed)
            return;
        HttpClient::destroyInstance();
    });
}

HttpClient::~HttpClient()
{
    LOGD("In the destructor of HttpClient!\n");
    Director::getInstance()->getEventDispatcher()->removeEventListener(_resetDirectorListener);
}

//Add a get task to queue
void HttpClient::send(HttpRequest* request)
{
    sendImmediate(request);
}

void HttpClient::sendImmediate(HttpRequest* request)
{
    if(!request)
    {
        return;
    }
    
    request->retain();   // request ref = 2
    
    _notHandledRequestQueueMutex.lock();
    _notHandledRequestQueue.pushBack(request); // request ref = 3
    _notHandledRequestQueueMutex.unlock();
    
    static unsigned long __aloneThreadID = 0;
    unsigned long aloneThreadID = __aloneThreadID++;
    
    ThreadPool::getDefaultThreadPool()->pushTask([this, aloneThreadID, request](int tid){
        networkThreadAlone(request, aloneThreadID);
    }, ThreadPool::TASK_TYPE_NETWORK);
}
    
void HttpClient::cleanup()
{
    LOGD("cleanup begin!\n");

    // clear not handled requests & responses
    _notHandledRequestQueueMutex.lock();
    _notHandledResponseQueueMutex.lock();
    
    for (const auto& notHandledRequest : _notHandledRequestQueue)
    {
        LOGD("release not handled request ...\n");
        CC_SAFE_RELEASE(notHandledRequest);
    }
    _notHandledRequestQueue.clear();
    
    for (const auto& notHandledResponse : _notHandledResponseQueue)
    {
        LOGD("release not handled response ...\n");
        CC_SAFE_RELEASE(notHandledResponse);
    }
    _notHandledResponseQueue.clear();
    
    _notHandledRequestQueueMutex.unlock();
    _notHandledResponseQueueMutex.unlock();
    
    LOGD("cleanup DONE!\n");
}
    
void HttpClient::setTimeoutForConnect(int value)
{
    std::lock_guard<std::mutex> lock(_timeoutForConnectMutex);
    _timeoutForConnect = value;
}
    
int HttpClient::getTimeoutForConnect()
{
    std::lock_guard<std::mutex> lock(_timeoutForConnectMutex);
    return _timeoutForConnect;
}
    
void HttpClient::setTimeoutForRead(int value)
{
    std::lock_guard<std::mutex> lock(_timeoutForReadMutex);
    _timeoutForRead = value;
}
    
int HttpClient::getTimeoutForRead()
{
    std::lock_guard<std::mutex> lock(_timeoutForReadMutex);
    return _timeoutForRead;
}
    
const std::string& HttpClient::getCookieFilename()
{
    std::lock_guard<std::mutex> lock(_cookieFileMutex);
    return _cookieFilename;
}
    
const std::string& HttpClient::getSSLVerification()
{
    std::lock_guard<std::mutex> lock(_sslCaFileMutex);
    return _sslCaFilename;
}
    
}

NS_CC_END

#endif // #if CC_TARGET_PLATFORM == CC_PLATFORM_MAC



