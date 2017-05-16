//
//  jsb_XMLHttpRequest.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 5/15/17.
//
//

#include "jsb_xmlhttprequest.hpp"

#include "SeApi.h"

#include <string>
#include <algorithm>
#include <sstream>

using namespace cocos2d;
using namespace cocos2d::network;

XMLHttpRequest::XMLHttpRequest()
: onloadstart(nullptr)
, onload(nullptr)
, onloadend(nullptr)
, onreadystatechange(nullptr)
, onabort(nullptr)
, onerror(nullptr)
, ontimeout(nullptr)
, _responseType(ResponseType:: STRING)
, _readyState(UNSENT)
, _status(0)
, _statusText()
, _timeout(0)
, _withCredentialsValue(false)
, _errorFlag(false)
, _isAborted(false)
, _httpRequest(new HttpRequest())
{

}

XMLHttpRequest::~XMLHttpRequest()
{
    // We don't need to release _httpRequest here since it will be released in the http callback.
//    CC_SAFE_RELEASE(_httpRequest);
}

bool XMLHttpRequest::open(const std::string& method, const std::string& url)
{
    _method = method;
    _url = url;

    HttpRequest::Type requestType = HttpRequest::Type::UNKNOWN;

    if (_method == "get" || _method == "GET")
        requestType = HttpRequest::Type::GET;
    else if (_method == "post" || _method == "POST")
        requestType = HttpRequest::Type::POST;
    else if (_method == "put" || _method == "PUT")
        requestType = HttpRequest::Type::PUT;
    else if (_method == "delete" || _method == "DELETE")
        requestType = HttpRequest::Type::DELETE;

    assert(requestType != HttpRequest::Type::UNKNOWN);

    _httpRequest->setRequestType(requestType);
    _httpRequest->setUrl(_url);

    _readyState = OPENED;
    _status = 0;
    _isAborted = false;

    return true;
}

void XMLHttpRequest::send()
{
    sendRequest();
}

void XMLHttpRequest::sendString(const std::string& str)
{
    setHttpRequestData(str.c_str(), str.length());
    sendRequest();
}

void XMLHttpRequest::sendBinary(const Data& data)
{
    setHttpRequestData((const char*)data.getBytes(), data.getSize());
    sendRequest();
}

void XMLHttpRequest::gotHeader(std::string& header)
{
    // Get Header and Set StatusText
    // Split String into Tokens
    char * cstr = new (std::nothrow) char [header.length()+1];

    // check for colon.
    size_t found_header_field = header.find_first_of(":");

    if (found_header_field != std::string::npos)
    {
        // Found a header field.
        std::string http_field;
        std::string http_value;

        http_field = header.substr(0,found_header_field);
        http_value = header.substr(found_header_field+1, header.length());

        // Get rid of all \n
        if (!http_value.empty() && http_value[http_value.size() - 1] == '\n') {
            http_value.erase(http_value.size() - 1);
        }

        // Get rid of leading space (header is field: value format)
        if (!http_value.empty() && http_value[0] == ' ') {
            http_value.erase(0, 1);
        }

        // Transform field name to lower case as they are case-insensitive
        std::transform(http_field.begin(), http_field.end(), http_field.begin(), ::tolower);

        _httpHeader[http_field] = http_value;

    }
    else
    {
        // Seems like we have the response Code! Parse it and check for it.
        char * pch;
        strcpy(cstr, header.c_str());

        pch = strtok(cstr," ");
        while (pch != nullptr)
        {
            std::stringstream ss;
            std::string val;

            ss << pch;
            val = ss.str();
            size_t found_http = val.find("HTTP");

            // Check for HTTP Header to set statusText
            if (found_http != std::string::npos) {

                std::stringstream mystream;

                // Get Response Status
                pch = strtok (nullptr, " ");
                mystream << pch;

                pch = strtok (nullptr, " ");
                mystream << " " << pch;

                _statusText = mystream.str();
                
            }
            
            pch = strtok (nullptr, " ");
        }
    }
    
    CC_SAFE_DELETE_ARRAY(cstr);
}

void XMLHttpRequest::onResponse(HttpClient* client, HttpResponse* response)
{
//    _elapsedTime = 0;
//    _scheduler->unscheduleAllForTarget(this);

    if(_isAborted || _readyState == UNSENT)
    {
        return;
    }

    std::string tag = response->getHttpRequest()->getTag();
    if (!tag.empty())
    {
        CCLOG("%s completed", tag.c_str());
    }

    long statusCode = response->getResponseCode();
    char statusString[64] = {0};
    sprintf(statusString, "HTTP Status Code: %ld, tag = %s", statusCode, tag.c_str());

    _responseText.clear();
    _responseData.clear();

    if (!response->isSucceed())
    {
        std::string errorBuffer = response->getErrorBuffer();
        CCLOG("Response failed, error buffer: %s", errorBuffer.c_str());
        if (statusCode == 0 || statusCode == -1)
        {
            _errorFlag = true;
            _status = 0;
            _statusText.clear();
            if (onerror != nullptr)
            {
                onerror();
            }

            if (onloadend != nullptr)
            {
                onloadend();
            }
            return;
        }
    }

    // set header
    std::vector<char> *headers = response->getResponseHeader();

    std::string header(headers->begin(), headers->end());

    std::istringstream stream(header);
    std::string line;
    while(std::getline(stream, line)) {
        gotHeader(line);
    }

    /** get the response data **/
    std::vector<char>* buffer = response->getResponseData();

    _status = statusCode;
    _readyState = DONE;

    if (_responseType == ResponseType::STRING || _responseType == ResponseType::JSON)
    {
        _responseText.append(buffer->data(), buffer->size());
    }
    else
    {
        _responseData.copy((unsigned char*)buffer->data(), buffer->size());
    }

    if (onreadystatechange != nullptr)
    {
        onreadystatechange();
    }

    if (onload != nullptr)
    {
        onload();
    }

    if (onloadend != nullptr)
    {
        onloadend();
    }
}

void XMLHttpRequest::sendRequest()
{
    setHttpRequestHeader();

    _httpRequest->setResponseCallback(CC_CALLBACK_2(XMLHttpRequest::onResponse, this));
    cocos2d::network::HttpClient::getInstance()->sendImmediate(_httpRequest);
    _httpRequest->release();

    if (onloadstart != nullptr)
    {
        onloadstart();
    }
}

void XMLHttpRequest::setHttpRequestData(const char* data, size_t len)
{
    if (len > 0 &&
        (_method == "post" || _method == "POST" || _method == "put" || _method == "PUT"))
    {
        _httpRequest->setRequestData(data, len);
    }
}

void XMLHttpRequest::setRequestHeader(const std::string& key, const std::string& value)
{
    std::stringstream header_s;
    std::stringstream value_s;
    std::string header;

    auto iter = _requestHeader.find(key);

    // Concatenate values when header exists.
    if (iter != _requestHeader.end())
    {
        value_s << iter->second << "," << value;
    }
    else
    {
        value_s << value;
    }

    _requestHeader[key] = value_s.str();
}

std::string XMLHttpRequest::getAllResponseHeaders() const
{
    std::stringstream responseheaders;
    std::string responseheader;

    for (auto it = _httpHeader.begin(); it != _httpHeader.end(); ++it)
    {
        responseheaders << it->first << ": " << it->second << "\n";
    }

    responseheader = responseheaders.str();
    return responseheader;
}

std::string XMLHttpRequest::getResonpseHeader(const std::string& key) const
{
    std::string ret;
    std::string value = key;
    std::transform(value.begin(), value.end(), value.begin(), ::tolower);

    auto iter = _httpHeader.find(value);
    if (iter != _httpHeader.end())
    {
        ret = iter->second;
    }
    return ret;
}

void XMLHttpRequest::setHttpRequestHeader()
{
    std::vector<std::string> header;

    for (auto it = _requestHeader.begin(); it != _requestHeader.end(); ++it)
    {
        const char* first = it->first.c_str();
        const char* second = it->second.c_str();
        size_t len = sizeof(char) * (strlen(first) + 3 + strlen(second));
        char* test = (char*) malloc(len);
        memset(test, 0,len);

        strcpy(test, first);
        strcpy(test + strlen(first) , ": ");
        strcpy(test + strlen(first) + 2, second);

        header.push_back(test);

        free(test);

    }

    if (!header.empty())
    {
        _httpRequest->setHeaders(header);
    }
}


se::Class* __jsb_XMLHttpRequest_class = nullptr;


SE_FINALIZE_FUNC_BEGIN(XMLHttpRequest_finalize)
{
    printf("XMLHttpRequest_finalize ... \n");
    XMLHttpRequest* request = (XMLHttpRequest*)nativeThisObject;
    delete request;
}
SE_FINALIZE_FUNC_END


SE_CTOR_BEGIN(XMLHttpRequest_constructor, XMLHttpRequest, XMLHttpRequest_finalize)
{
    XMLHttpRequest* request = new XMLHttpRequest();
    thisObject->setPrivateData(request);

    se::Value thiz(thisObject);

    auto cb = [thiz](const char* eventName){
        se::Object* thizObj = thiz.toObject();

        se::Value onloadstart;
        if (thizObj->getProperty(eventName, &onloadstart))
        {
            onloadstart.toObject()->call(se::EmptyValueArray, thizObj);
        }
    };

    request->onloadstart = [cb, thiz](){
        thiz.toObject()->switchToRooted();
        cb("onloadstart");
    };
    request->onload = [cb](){
        cb("onload");
    };
    request->onloadend = [cb, thiz](){
        cb("onloadend");
        thiz.toObject()->switchToUnrooted();
    };
    request->onreadystatechange = [cb](){
        cb("onreadystatechange");
    };
    request->onabort = [cb](){
        cb("onabort");
    };
    request->onerror = [cb](){
        cb("onerror");
    };
    request->ontimeout = [cb](){
        cb("ontimeout");
    };
}
SE_CTOR_END

SE_FUNC_BEGIN(XMLHttpRequest_open, se::DONT_NEED_THIS)
{
    XMLHttpRequest* request = (XMLHttpRequest*)nativeThisObject;
    const std::string& method = args[0].toString();
    const std::string& url = args[1].toString();
    request->open(method, url);
}
SE_FUNC_END

SE_FUNC_BEGIN(XMLHttpRequest_abort, se::DONT_NEED_THIS)
{

}
SE_FUNC_END

SE_FUNC_BEGIN(XMLHttpRequest_send, se::DONT_NEED_THIS)
{
    XMLHttpRequest* request = (XMLHttpRequest*)nativeThisObject;

    if (argc == 0)
    {
        request->send();
    }
    else if (argc > 0)
    {
        if (args[0].isString())
        {
            request->sendString(args[0].toString());
        }
        else if (args[0].isObject())
        {
//            se::Object* obj = args[0].toObject();
//            unsigned char* ptr = nullptr;
//            unsigned int length = 0;
//            obj->getAsUint8Array(&ptr, &length);
        }
    }


}
SE_FUNC_END

SE_FUNC_BEGIN(XMLHttpRequest_setRequestHeader, se::DONT_NEED_THIS)
{
    XMLHttpRequest* xhr = (XMLHttpRequest*)nativeThisObject;
    assert(argc == 2);
    assert(args[0].isString() && args[1].isString());
    xhr->setRequestHeader(args[0].toString(), args[1].toString());
}
SE_FUNC_END

SE_FUNC_BEGIN(XMLHttpRequest_getAllResponseHeaders, se::DONT_NEED_THIS)
{
    XMLHttpRequest* xhr = (XMLHttpRequest*)nativeThisObject;
    std::string headers = xhr->getAllResponseHeaders();
    SE_SET_RVAL(se::Value(headers));
}
SE_FUNC_END

SE_FUNC_BEGIN(XMLHttpRequest_getResonpseHeader, se::DONT_NEED_THIS)
{
    XMLHttpRequest* xhr = (XMLHttpRequest*)nativeThisObject;
    assert(argc > 0);
    assert(args[0].isString());
    std::string header = xhr->getResonpseHeader(args[0].toString());
    SE_SET_RVAL(se::Value(header));
}
SE_FUNC_END

SE_FUNC_BEGIN(XMLHttpRequest_overrideMimeType, se::DONT_NEED_THIS)
{

}
SE_FUNC_END

// getter

SE_GET_PROPERTY_BEGIN(XMLHttpRequest_getReadyState, se::DONT_NEED_THIS)
{
    XMLHttpRequest* xhr = (XMLHttpRequest*)nativeThisObject;
    SE_SET_RVAL(se::Value((double)xhr->getReadyState()));
}
SE_GET_PROPERTY_END

SE_GET_PROPERTY_BEGIN(XMLHttpRequest_getStatus, se::DONT_NEED_THIS)
{
    XMLHttpRequest* xhr = (XMLHttpRequest*)nativeThisObject;
    SE_SET_RVAL(se::Value((double)xhr->getStatus()));
}
SE_GET_PROPERTY_END

SE_GET_PROPERTY_BEGIN(XMLHttpRequest_getStatusText, se::DONT_NEED_THIS)
{
    XMLHttpRequest* xhr = (XMLHttpRequest*)nativeThisObject;
    SE_SET_RVAL(se::Value(xhr->getStatusText()));
}
SE_GET_PROPERTY_END

SE_GET_PROPERTY_BEGIN(XMLHttpRequest_getResponseText, se::DONT_NEED_THIS)
{
    XMLHttpRequest* xhr = (XMLHttpRequest*)nativeThisObject;
    SE_SET_RVAL(se::Value(xhr->getResponseText()));
}
SE_GET_PROPERTY_END


SE_GET_PROPERTY_BEGIN(XMLHttpRequest_getResponseXML, se::DONT_NEED_THIS)
{
    SE_SET_RVAL(se::Value::Null);
}
SE_GET_PROPERTY_END

SE_GET_PROPERTY_BEGIN(XMLHttpRequest_getResponse, se::DONT_NEED_THIS)
{
    XMLHttpRequest* xhr = (XMLHttpRequest*)nativeThisObject;

    if (xhr->getResponseType() == XMLHttpRequest::ResponseType::STRING)
    {
        SE_SET_RVAL(se::Value(xhr->getResponseText()));
    }
    else
    {
        if (xhr->getReadyState() != XMLHttpRequest::DONE)
        {
            SE_SET_RVAL(se::Value::Null);
        }
        else
        {
            if (xhr->getResponseType() == XMLHttpRequest::ResponseType::JSON)
            {
                assert(false); // FIXME:
            }
            else if (xhr->getResponseType() == XMLHttpRequest::ResponseType::ARRAY_BUFFER)
            {
                assert(false); // FIXME:
            }
            else
            {
                assert(false); // FIXME:
            }
        }
    }

}
SE_GET_PROPERTY_END

SE_GET_PROPERTY_BEGIN(XMLHttpRequest_getTimeout, se::DONT_NEED_THIS)
{

}
SE_GET_PROPERTY_END

SE_GET_PROPERTY_BEGIN(XMLHttpRequest_getResponseType, se::DONT_NEED_THIS)
{
    XMLHttpRequest* xhr = (XMLHttpRequest*)nativeThisObject;
    SE_SET_RVAL(se::Value((double)xhr->getResponseType()));
}
SE_GET_PROPERTY_END

SE_GET_PROPERTY_BEGIN(XMLHttpRequest_getWithCredentials, se::DONT_NEED_THIS)
{

}
SE_GET_PROPERTY_END


void jsb_register_XMLHttpRequest()
{
    se::ScriptEngine* engine = se::ScriptEngine::getInstance();
    se::Object* global = engine->getGlobalObject();

    se::Class* cls = se::Class::create("XMLHttpRequest", global, nullptr, XMLHttpRequest_constructor);
    cls->defineFinalizedFunction(XMLHttpRequest_finalize);

    cls->defineFunction("open", XMLHttpRequest_open);
    cls->defineFunction("abort", XMLHttpRequest_abort);
    cls->defineFunction("send", XMLHttpRequest_send);
    cls->defineFunction("setRequestHeader", XMLHttpRequest_setRequestHeader);
    cls->defineFunction("getAllResponseHeaders", XMLHttpRequest_getAllResponseHeaders);
    cls->defineFunction("getResponseHeader", XMLHttpRequest_getResonpseHeader);
    cls->defineFunction("overrideMimeType", XMLHttpRequest_overrideMimeType);

    cls->defineProperty("readyState", XMLHttpRequest_getReadyState, nullptr);
    cls->defineProperty("status", XMLHttpRequest_getStatus, nullptr);
    cls->defineProperty("statusText", XMLHttpRequest_getStatusText, nullptr);
    cls->defineProperty("responseText", XMLHttpRequest_getResponseText, nullptr);
    cls->defineProperty("responseXML", XMLHttpRequest_getResponseXML, nullptr);
    cls->defineProperty("response", XMLHttpRequest_getResponse, nullptr);
    cls->defineProperty("timeout", XMLHttpRequest_getTimeout, nullptr);
    cls->defineProperty("responseType", XMLHttpRequest_getResponseType, nullptr);
    cls->defineProperty("withCredentials", XMLHttpRequest_getWithCredentials, nullptr);

    cls->install();

    __jsb_XMLHttpRequest_class = cls;
}
