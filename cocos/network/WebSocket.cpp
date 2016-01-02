/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
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

"[WebSocket module] is based in part on the work of the libwebsockets  project
(http://libwebsockets.org)"

 ****************************************************************************/

#include "WebSocket.h"
#include "base/CCDirector.h"
#include "base/CCScheduler.h"

#include <thread>
#include <mutex>
#include <queue>
#include <list>
#include <signal.h>
#include <errno.h>

#include "libwebsockets.h"

#define WS_WRITE_BUFFER_SIZE (4096 - 3)

#define  LOG_TAG    "Websocket.cpp"
#ifdef ANDROID
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG,__VA_ARGS__)
#else
#define  LOGD(...) printf(__VA_ARGS__)
#endif

NS_CC_BEGIN

namespace network {

class WsMessage
{
public:
    WsMessage() : id(++__id), what(0), obj(nullptr){}
    unsigned int id;
    unsigned int what; // message type
    void* obj;
    
private:
    static unsigned int __id;
};
    
unsigned int WsMessage::__id = 0;

/**
 *  @brief Websocket thread helper, it's used for sending message between UI thread and websocket thread.
 */
class WsThreadHelper
{
public:
    WsThreadHelper();
    ~WsThreadHelper();
        
    // Creates a new thread
    bool createThread(const WebSocket& ws);
    // Quits sub-thread (websocket thread).
    void quitSubThread();
    
    // Sends message to UI thread. It's needed to be invoked in sub-thread.
    void sendMessageToUIThread(WsMessage *msg);
    
    // Sends message to sub-thread(websocket thread). It's needs to be invoked in UI thread.
    void sendMessageToSubThread(WsMessage *msg);
    
    // Waits the sub-thread (websocket thread) to exit,
    void joinSubThread();
    
    
protected:
    void wsThreadEntryFunc();
    
private:
    std::list<WsMessage*>* _subThreadWsMessageQueue;
    std::mutex   _subThreadWsMessageQueueMutex;
    std::thread* _subThreadInstance;
    WebSocket* _ws;
    bool _needQuit;
    friend class WebSocket;
};

// Wrapper for converting websocket callback from static function to member function of WebSocket class.
class WebSocketCallbackWrapper {
public:
    
    static int onSocketCallback(struct lws *wsi,
                                enum lws_callback_reasons reason,
                                void *user, void *in, size_t len)
    {
        // Gets the user data from context. We know that it's a 'WebSocket' instance.
        if (wsi == nullptr) {
            return 0;
        }
        
        lws_context* context = lws_get_context(wsi);
        WebSocket* wsInstance = (WebSocket*)lws_context_user(context);
        if (wsInstance)
        {
            return wsInstance->onSocketCallback(wsi, reason, user, in, len);
        }
        return 0;
    }
};

// Implementation of WsThreadHelper
WsThreadHelper::WsThreadHelper()
: _subThreadInstance(nullptr)
, _ws(nullptr)
, _needQuit(false)
{
    _subThreadWsMessageQueue = new std::list<WsMessage*>();
}

WsThreadHelper::~WsThreadHelper()
{
    joinSubThread();
    CC_SAFE_DELETE(_subThreadInstance);
    delete _subThreadWsMessageQueue;
}

bool WsThreadHelper::createThread(const WebSocket& ws)
{
    _ws = const_cast<WebSocket*>(&ws);
    
    // Creates websocket thread
    _subThreadInstance = new std::thread(&WsThreadHelper::wsThreadEntryFunc, this);
    return true;
}

void WsThreadHelper::quitSubThread()
{
    _needQuit = true;
}

void WsThreadHelper::wsThreadEntryFunc()
{
    _ws->onSubThreadStarted();
    
    while (!_needQuit)
    {
        if (_ws->onSubThreadLoop())
        {
            break;
        }
    }
    
    LOGD("Websocket thread exit!\n");
}

void WsThreadHelper::sendMessageToUIThread(WsMessage *msg)
{
    Director::getInstance()->getScheduler()->performFunctionInCocosThread([this, msg](){
        if (_ws)
        {
            _ws->onUIThreadReceiveMessage(msg);
        }
        
        delete msg;
    });
}

void WsThreadHelper::sendMessageToSubThread(WsMessage *msg)
{
    std::lock_guard<std::mutex> lk(_subThreadWsMessageQueueMutex);
    _subThreadWsMessageQueue->push_back(msg);
}

void WsThreadHelper::joinSubThread()
{
    if (_subThreadInstance->joinable())
    {
        _subThreadInstance->join();
    }
}

enum WS_MSG {
    WS_MSG_TO_SUBTRHEAD_SENDING_STRING = 0,
    WS_MSG_TO_SUBTRHEAD_SENDING_BINARY,
    WS_MSG_TO_UITHREAD_OPEN,
    WS_MSG_TO_UITHREAD_MESSAGE,
    WS_MSG_TO_UITHREAD_ERROR,
    WS_MSG_TO_UITHREAD_CLOSE
};

WebSocket::WebSocket()
: _readyState(State::CONNECTING)
, _port(80)
, _currentDataLen(0)
, _currentData(nullptr)
, _wsHelper(nullptr)
, _wsInstance(nullptr)
, _wsContext(nullptr)
, _delegate(nullptr)
, _SSLConnection(0)
, _wsProtocols(nullptr)
{
    static unsigned int id = 0;
    _id = ++id;
}

WebSocket::~WebSocket()
{
    close();
    CC_SAFE_DELETE(_wsHelper);
    
    for (int i = 0; _wsProtocols[i].callback != nullptr; ++i)
    {
        CC_SAFE_DELETE_ARRAY(_wsProtocols[i].name);
    }
	CC_SAFE_DELETE_ARRAY(_wsProtocols);
}
    
bool WebSocket::init(const Delegate& delegate,
                     const std::string& url,
                     const std::vector<std::string>* protocols/* = nullptr*/)
{
    bool ret = false;
    bool useSSL = false;
    std::string host = url;
    size_t pos = 0;
    int port = 80;
    
    _delegate = const_cast<Delegate*>(&delegate);
    
    //ws://
    pos = host.find("ws://");
    if (pos == 0) host.erase(0,5);
    
    pos = host.find("wss://");
    if (pos == 0)
    {
        host.erase(0,6);
        useSSL = true;
    }
    
    pos = host.find(":");
    if (pos != std::string::npos) port = atoi(host.substr(pos+1, host.size()).c_str());
    
    pos = host.find("/", 0);
    std::string path = "/";
    if (pos != std::string::npos) path += host.substr(pos + 1, host.size());
    
    pos = host.find(":");
    if(pos != std::string::npos){
        host.erase(pos, host.size());
    }else if((pos = host.find("/")) != std::string::npos) {
    	host.erase(pos, host.size());
    }
    
    _host = host;
    _port = port;
    _path = path;
    _SSLConnection = useSSL ? 1 : 0;
    
    CCLOG("[WebSocket::init] _host: %s, _port: %d, _path: %s", _host.c_str(), _port, _path.c_str());

    size_t protocolCount = 0;
    if (protocols && protocols->size() > 0)
    {
        protocolCount = protocols->size();
    }
    else
    {
        protocolCount = 1;
    }
    
	_wsProtocols = new lws_protocols[protocolCount+1];
	memset(_wsProtocols, 0, sizeof(lws_protocols)*(protocolCount+1));

    if (protocols && protocols->size() > 0)
    {
        int i = 0;
        for (std::vector<std::string>::const_iterator iter = protocols->begin(); iter != protocols->end(); ++iter, ++i)
        {
            char* name = new char[(*iter).length()+1];
            strcpy(name, (*iter).c_str());
            _wsProtocols[i].name = name;
            _wsProtocols[i].callback = WebSocketCallbackWrapper::onSocketCallback;
        }
    }
    else
    {
        char* name = new char[256];
        strcpy(name, "default");
        _wsProtocols[0].name = name;
        _wsProtocols[0].callback = WebSocketCallbackWrapper::onSocketCallback;
        _wsProtocols[0].per_session_data_size = sizeof(unsigned int);
    }
    
    // WebSocket thread needs to be invoked at the end of this method.
    _wsHelper = new (std::nothrow) WsThreadHelper();
    ret = _wsHelper->createThread(*this);
    
    return ret;
}

void WebSocket::send(const std::string& message)
{
    if (_readyState == State::OPEN)
    {
        // In main thread
        WsMessage* msg = new (std::nothrow) WsMessage();
        msg->what = WS_MSG_TO_SUBTRHEAD_SENDING_STRING;
        Data* data = new (std::nothrow) Data();
        data->bytes = (char*)malloc(message.length()+1);
        strcpy(data->bytes, message.c_str());
        data->len = static_cast<ssize_t>(message.length());
        msg->obj = data;
        _wsHelper->sendMessageToSubThread(msg);
    }
    else
    {
        LOGD("Couldn't send since websocket was closed!\n");
    }
}

void WebSocket::send(const unsigned char* binaryMsg, unsigned int len)
{
    if (_readyState == State::OPEN)
    {
        // In main thread
        WsMessage* msg = new (std::nothrow) WsMessage();
        msg->what = WS_MSG_TO_SUBTRHEAD_SENDING_BINARY;
        Data* data = new (std::nothrow) Data();
        if (len == 0)
        {
            data->bytes = (char*)malloc(len + 1);
            data->bytes[0] = '\0';
        }
        else
        {
            data->bytes = (char*)malloc(len);
            memcpy((void*)data->bytes, (void*)binaryMsg, len);
        }
        data->len = len;
        msg->obj = data;
        _wsHelper->sendMessageToSubThread(msg);
    }
}

void WebSocket::close()
{
    if (_readyState == State::CLOSING || _readyState == State::CLOSED)
    {
        return;
    }
    
    CCLOG("websocket (%p) connection closed by client", this);
    _readyState = State::CLOSED;

    _wsHelper->joinSubThread();
    
    // onClose callback needs to be invoked at the end of this method
    // since websocket instance may be deleted in 'onClose'.
    _delegate->onClose(this);
}

WebSocket::State WebSocket::getReadyState()
{
    return _readyState;
}

    static unsigned long long getTime() {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        
        unsigned long long curTime = ((unsigned long long)tv.tv_sec * 1000000) + tv.tv_usec;
        return curTime;
    }
    
int WebSocket::onSubThreadLoop()
{
    if (_readyState == State::CLOSED || _readyState == State::CLOSING)
    {
        lws_context_destroy(_wsContext);
        // return 1 to exit the loop.
        return 1;
    }
    
    if (_wsContext && _readyState != State::CLOSED && _readyState != State::CLOSING)
    {
//        unsigned long long oldTime = getTime();
        lws_service(_wsContext, 50);
//        unsigned long long curtime = getTime();
//        printf("lws_service waste: %ldus\n", (long)(curtime - oldTime));
    }
    
    // return 0 to continue the loop.
    return 0;
}

void WebSocket::onSubThreadStarted()
{
	struct lws_context_creation_info info;
	memset(&info, 0, sizeof info);
    
    
	/*
	 * create the websocket context.  This tracks open connections and
	 * knows how to route any traffic and which protocol version to use,
	 * and if each connection is client or server side.
	 *
	 * For this client-only demo, we tell it to not listen on any port.
	 */
    
	info.port = CONTEXT_PORT_NO_LISTEN;
	info.protocols = _wsProtocols;
#ifndef LWS_NO_EXTENSIONS
	info.extensions = lws_get_internal_extensions();
#endif
	info.gid = -1;
	info.uid = -1;
    info.options = 0;
    info.user = this;
    
    int log_level = LLL_ERR | LLL_WARN | LLL_NOTICE /*| LLL_INFO | LLL_DEBUG/* | LLL_PARSER*/ | LLL_HEADER | LLL_EXT | LLL_CLIENT | LLL_LATENCY;
    lws_set_log_level(log_level, nullptr);
    
	_wsContext = lws_create_context(&info);
    
	if(nullptr != _wsContext)
    {
        _readyState = State::CONNECTING;
        std::string name;
        for (int i = 0; _wsProtocols[i].callback != nullptr; ++i)
        {
            name += (_wsProtocols[i].name);
            
            if (_wsProtocols[i+1].callback != nullptr) name += ", ";
        }
        
        char portStr[10];
        sprintf(portStr, "%d", _port);
        std::string ads_port = _host + ":" + portStr;
        
        _wsInstance = lws_client_connect(_wsContext, _host.c_str(), _port, _SSLConnection,
                                             _path.c_str(), ads_port.c_str(), ads_port.c_str(),
                                             name.c_str(), -1);
        
        if (nullptr == _wsInstance) {
            WsMessage* msg = new (std::nothrow) WsMessage();
            msg->what = WS_MSG_TO_UITHREAD_ERROR;
            _readyState = State::CLOSING;
            _wsHelper->sendMessageToUIThread(msg);
        }

	}
}

void WebSocket::onSubThreadEnded()
{

}

static void* _oldUser = nullptr;

void WebSocket::onClientWritable()
{
    std::lock_guard<std::mutex> lk(_wsHelper->_subThreadWsMessageQueueMutex);
    
    std::list<WsMessage*>::iterator iter = _wsHelper->_subThreadWsMessageQueue->begin();
    
    ssize_t bytesWrite = 0;
    if (iter != _wsHelper->_subThreadWsMessageQueue->end())
    {
        WsMessage* subThreadMsg = *iter;
        
        if ( WS_MSG_TO_SUBTRHEAD_SENDING_STRING == subThreadMsg->what
            || WS_MSG_TO_SUBTRHEAD_SENDING_BINARY == subThreadMsg->what)
        {
            Data* data = (Data*)subThreadMsg->obj;
            
            const size_t c_bufferSize = WS_WRITE_BUFFER_SIZE;
            
            size_t remaining = data->len - data->issued;
            size_t n = std::min(remaining, c_bufferSize );
            //fixme: the log is not thread safe
            //                        CCLOG("[websocket:send] total: %d, sent: %d, remaining: %d, buffer size: %d", static_cast<int>(data->len), static_cast<int>(data->issued), static_cast<int>(remaining), static_cast<int>(n));
            
            unsigned char buf[LWS_SEND_BUFFER_PRE_PADDING + n + LWS_SEND_BUFFER_POST_PADDING];
            memcpy((char*)&buf[LWS_SEND_BUFFER_PRE_PADDING], data->bytes + data->issued, n);
            
            int writeProtocol;
            
            if (data->issued == 0)
            {
                if (WS_MSG_TO_SUBTRHEAD_SENDING_STRING == subThreadMsg->what)
                {
                    writeProtocol = LWS_WRITE_TEXT;
                }
                else
                {
                    writeProtocol = LWS_WRITE_BINARY;
                }
                
                // If we have more than 1 fragment
                if (data->len > c_bufferSize)
                    writeProtocol |= LWS_WRITE_NO_FIN;
            } else {
                // we are in the middle of fragments
                writeProtocol = LWS_WRITE_CONTINUATION;
                // and if not in the last fragment
                if (remaining != n)
                    writeProtocol |= LWS_WRITE_NO_FIN;
            }
            
            bytesWrite = lws_write(_wsInstance,  &buf[LWS_SEND_BUFFER_PRE_PADDING], n, (lws_write_protocol)writeProtocol);
            
            // Handle the result of lws_write
            // Buffer overrun?
            if (bytesWrite < 0)
            {
                LOGD("ERROR: msg(%u), lws_write return: %ld\n", subThreadMsg->id, bytesWrite);
            }
            // Do we have another fragments to send?
            else if (remaining > bytesWrite)
            {
                LOGD("msg(%u) append: %ld + %ld = %ld\n", subThreadMsg->id, data->issued, bytesWrite, data->issued + bytesWrite);
                data->issued += bytesWrite;
            }
            // Safely done!
            else
            {
                if (remaining == bytesWrite)
                {
                    LOGD("msg(%u) append: %ld + %ld = %ld\n", subThreadMsg->id, data->issued, bytesWrite, data->issued + bytesWrite);
                    LOGD("msg(%u) was totally sent!\n", subThreadMsg->id);
                }
                else
                {
                    LOGD("ERROR: msg(%u), remaining(%ld) < byteWrite(%ld)\n", subThreadMsg->id, remaining, bytesWrite);
                    LOGD("Drop the msg(%u)\n", subThreadMsg->id);
                }
                
                CC_SAFE_FREE(data->bytes);
                CC_SAFE_DELETE(data);
                _wsHelper->_subThreadWsMessageQueue->erase(iter);
                CC_SAFE_DELETE(subThreadMsg);
                
                LOGD("-----------------------------------------------------------\n");
            }
        }
    }
    
    /* get notified as soon as we can write again */
    lws_callback_on_writable(_wsInstance);
}

void WebSocket::onClientReceivedData(void* user, void* in, ssize_t len)
{
    if (_oldUser != user) {
        if (user) {
            printf("user=%p, %d\n", user, *((unsigned int*)user));
        }
        _oldUser = user;
    }
    
    if (in != nullptr && len > 0)
    {
        LOGD("Receiving data: len=%ld\n", len);
        // Accumulate the data (increasing the buffer as we go)
        ssize_t newLength = _currentDataLen + len;
        char* newData = (char*)realloc(_currentData, newLength + 1); // plus 1 to ensure string end with '\0'
        newData[newLength] = '\0';
        if (newData != nullptr)
        {
            memcpy (newData + _currentDataLen, in, len);
        }
        else
        {
            LOGD("ERROR: No enough memory!\n");
        }
        
        _currentData = newData;
        _currentDataLen = newLength;
    }
    else
    {
        LOGD("Emtpy message received!\n");
    }
    
    // If no more data pending, send it to the client thread
    if (lws_remaining_packet_payload (_wsInstance) == 0 && lws_is_final_fragment(_wsInstance))
    {
        WsMessage* msg = new (std::nothrow) WsMessage();
        msg->what = WS_MSG_TO_UITHREAD_MESSAGE;
        
        Data* data = new (std::nothrow) Data();
        
        //
        if (_currentData == nullptr && _currentDataLen == 0)
        {
            _currentData = (char*)malloc(1);
            _currentData[0] = '\0';
        }
        data->isBinary = lws_frame_is_binary(_wsInstance);
        data->bytes = _currentData;
        data->len = _currentDataLen;
        msg->obj = (void*)data;
        
        LOGD("Notify data len %ld to Cocos thread.\n", _currentDataLen);
        
        _currentData = nullptr;
        _currentDataLen = 0;
        
        _wsHelper->sendMessageToUIThread(msg);
    }
}
    
void WebSocket::onConnectionOpened(void* user)
{
    unsigned int* sessionData = (unsigned int*)user;
    *sessionData = _id;
    printf("id = %d\n", _id);
    /*
     * start the ball rolling,
     * LWS_CALLBACK_CLIENT_WRITEABLE will come next service
     */
    lws_callback_on_writable(_wsInstance);
    
    WsMessage* msg = new (std::nothrow) WsMessage();
    msg->what = WS_MSG_TO_UITHREAD_OPEN;
    _readyState = State::OPEN;
    
    _wsHelper->sendMessageToUIThread(msg);
}
    
void WebSocket::onConnectionClosing()
{
    _readyState = State::CLOSING;
    
    WsMessage* msg = new (std::nothrow) WsMessage();
    msg->what = WS_MSG_TO_UITHREAD_ERROR;
    _wsHelper->sendMessageToUIThread(msg);
}
    
void WebSocket::onConnectionClosed()
{
    //fixme: the log is not thread safe
    LOGD("%s", "connection closing..\n");
    
    _wsHelper->quitSubThread();
    
    if (_readyState == State::CLOSED)
    {
        LOGD("Websocket %p was closed, no need to close it again!", this);
        return;
    }
    
    _readyState = State::CLOSED;
    
    WsMessage* msg = new (std::nothrow) WsMessage();
    msg->what = WS_MSG_TO_UITHREAD_CLOSE;
    _wsHelper->sendMessageToUIThread(msg);
}
    
int WebSocket::onSocketCallback(struct lws *wsi,
                     int reason,
                     void *user, void *in, ssize_t len)
{
	//CCLOG("socket callback for %d reason", reason);
    
//    lws_context* ctx = nullptr;
//    if (wsi) {
//        ctx = lws_get_context(wsi);
//    }
//    CCASSERT(_wsContext == nullptr || ctx == _wsContext, "Invalid context.");
//    CCASSERT(_wsInstance == nullptr || wsi == nullptr || wsi == _wsInstance, "Invaild websocket instance.");

//    switch(reason) {
//        case LWS_CALLBACK_ESTABLISHED: { LOGD("LWS_CALLBACK_ESTABLISHED\n"); break; }
//        case LWS_CALLBACK_CLIENT_CONNECTION_ERROR: { LOGD("LWS_CALLBACK_CLIENT_CONNECTION_ERROR\n"); break; }
//        case LWS_CALLBACK_CLIENT_FILTER_PRE_ESTABLISH: { LOGD("LWS_CALLBACK_CLIENT_FILTER_PRE_ESTABLISH\n"); break; }
//        case LWS_CALLBACK_CLIENT_ESTABLISHED: { LOGD("LWS_CALLBACK_CLIENT_ESTABLISHED\n"); break; }
//        case LWS_CALLBACK_CLOSED: { LOGD("LWS_CALLBACK_CLOSED\n"); break; }
//        case LWS_CALLBACK_CLOSED_HTTP: { LOGD("LWS_CALLBACK_CLOSED_HTTP\n"); break; }
//        case LWS_CALLBACK_RECEIVE: { LOGD("LWS_CALLBACK_RECEIVE\n"); break; }
//        case LWS_CALLBACK_CLIENT_RECEIVE: { LOGD("LWS_CALLBACK_CLIENT_RECEIVE\n"); break; }
//        case LWS_CALLBACK_CLIENT_RECEIVE_PONG: { LOGD("LWS_CALLBACK_CLIENT_RECEIVE_PONG\n"); break; }
//        case LWS_CALLBACK_CLIENT_WRITEABLE: { LOGD("LWS_CALLBACK_CLIENT_WRITEABLE\n"); break; }
//        case LWS_CALLBACK_SERVER_WRITEABLE: { LOGD("LWS_CALLBACK_SERVER_WRITEABLE\n"); break; }
//        case LWS_CALLBACK_HTTP: { LOGD("LWS_CALLBACK_HTTP\n"); break; }
//        case LWS_CALLBACK_HTTP_BODY: { LOGD("LWS_CALLBACK_HTTP_BODY\n"); break; }
//        case LWS_CALLBACK_HTTP_BODY_COMPLETION: { LOGD("LWS_CALLBACK_HTTP_BODY_COMPLETION\n"); break; }
//        case LWS_CALLBACK_HTTP_FILE_COMPLETION: { LOGD("LWS_CALLBACK_HTTP_FILE_COMPLETION\n"); break; }
//        case LWS_CALLBACK_HTTP_WRITEABLE: { LOGD("LWS_CALLBACK_HTTP_WRITEABLE\n"); break; }
//        case LWS_CALLBACK_FILTER_NETWORK_CONNECTION: { LOGD("LWS_CALLBACK_FILTER_NETWORK_CONNECTION\n"); break; }
//        case LWS_CALLBACK_FILTER_HTTP_CONNECTION: { LOGD("LWS_CALLBACK_FILTER_HTTP_CONNECTION\n"); break; }
//        case LWS_CALLBACK_SERVER_NEW_CLIENT_INSTANTIATED: { LOGD("LWS_CALLBACK_SERVER_NEW_CLIENT_INSTANTIATED\n"); break; }
//        case LWS_CALLBACK_FILTER_PROTOCOL_CONNECTION: { LOGD("LWS_CALLBACK_FILTER_PROTOCOL_CONNECTION\n"); break; }
//        case LWS_CALLBACK_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS: { LOGD("LWS_CALLBACK_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS\n"); break; }
//        case LWS_CALLBACK_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS: { LOGD("LWS_CALLBACK_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS\n"); break; }
//        case LWS_CALLBACK_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION: { LOGD("LWS_CALLBACK_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION\n"); break; }
//        case LWS_CALLBACK_CLIENT_APPEND_HANDSHAKE_HEADER: { LOGD("LWS_CALLBACK_CLIENT_APPEND_HANDSHAKE_HEADER\n"); break; }
//        case LWS_CALLBACK_CONFIRM_EXTENSION_OKAY: { LOGD("LWS_CALLBACK_CONFIRM_EXTENSION_OKAY\n"); break; }
//        case LWS_CALLBACK_CLIENT_CONFIRM_EXTENSION_SUPPORTED:
//        {
//            LOGD("LWS_CALLBACK_CLIENT_CONFIRM_EXTENSION_SUPPORTED\n");
//            break;
//        }
//        case LWS_CALLBACK_PROTOCOL_INIT: { LOGD("LWS_CALLBACK_PROTOCOL_INIT\n"); break; }
//        case LWS_CALLBACK_PROTOCOL_DESTROY: { LOGD("LWS_CALLBACK_PROTOCOL_DESTROY\n"); break; }
//        case LWS_CALLBACK_WSI_CREATE: { LOGD("LWS_CALLBACK_WSI_CREATE\n"); break; }
//        case LWS_CALLBACK_WSI_DESTROY: { LOGD("LWS_CALLBACK_WSI_DESTROY\n"); break; }
//        case LWS_CALLBACK_GET_THREAD_ID: { LOGD("LWS_CALLBACK_GET_THREAD_ID\n"); break; }
//            
//        case LWS_CALLBACK_ADD_POLL_FD: { LOGD("LWS_CALLBACK_ADD_POLL_FD\n"); break; }
//        case LWS_CALLBACK_DEL_POLL_FD: { LOGD("LWS_CALLBACK_DEL_POLL_FD\n"); break; }
//        case LWS_CALLBACK_CHANGE_MODE_POLL_FD: { LOGD("LWS_CALLBACK_CHANGE_MODE_POLL_FD\n"); break; }
//        case LWS_CALLBACK_LOCK_POLL: { LOGD("LWS_CALLBACK_LOCK_POLL\n"); break; }
//        case LWS_CALLBACK_UNLOCK_POLL: { LOGD("LWS_CALLBACK_UNLOCK_POLL\n"); break; }
//            
//        default: { 
//            LOGD("callback - unhandled.\n");
//            break;
//        }
//    }
    
	switch (reason)
    {
        case LWS_CALLBACK_DEL_POLL_FD:
        case LWS_CALLBACK_PROTOCOL_DESTROY:
        case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
            {
                if (reason == LWS_CALLBACK_CLIENT_CONNECTION_ERROR
                    || (reason == LWS_CALLBACK_PROTOCOL_DESTROY && _readyState == State::CONNECTING)
                    || (reason == LWS_CALLBACK_DEL_POLL_FD && _readyState == State::CONNECTING)
                    )
                {
                    onConnectionClosing();
                }
                else if (reason == LWS_CALLBACK_PROTOCOL_DESTROY && _readyState == State::CLOSING)
                {
                    onConnectionClosed();
                }
            }
            break;
        case LWS_CALLBACK_CLIENT_ESTABLISHED:
            onConnectionOpened(user);
            break;
            
        case LWS_CALLBACK_CLIENT_WRITEABLE:
            onClientWritable();
            break;
            
        case LWS_CALLBACK_CLOSED:
            onConnectionClosed();
            break;
            
        case LWS_CALLBACK_CLIENT_RECEIVE:
            onClientReceivedData(user, in, len);
            break;
        default:
            break;
	}
    
	return 0;
}

void WebSocket::onUIThreadReceiveMessage(WsMessage* msg)
{
    switch (msg->what) {
        case WS_MSG_TO_UITHREAD_OPEN:
            {
                _delegate->onOpen(this);
            }
            break;
        case WS_MSG_TO_UITHREAD_MESSAGE:
            {
                Data* data = (Data*)msg->obj;
                _delegate->onMessage(this, *data);
                CC_SAFE_FREE(data->bytes);
                CC_SAFE_DELETE(data);
            }
            break;
        case WS_MSG_TO_UITHREAD_CLOSE:
            {
                //Waiting for the subThread safety exit
                _wsHelper->joinSubThread();
                _delegate->onClose(this);
            }
            break;
        case WS_MSG_TO_UITHREAD_ERROR:
            {
                // FIXME: The exact error needs to be checked.
                WebSocket::ErrorCode err = ErrorCode::CONNECTION_FAILURE;
                _delegate->onError(this, err);
            }
            break;
        default:
            break;
    }
}

}

NS_CC_END
