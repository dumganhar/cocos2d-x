//
//  jsb_cocos2dx_manual.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 5/26/17.
//
//

#include "jsb_cocos2dx_manual.hpp"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "cocos/scripting/js-bindings/manual/jsb_conversions.hpp"
#include "cocos/scripting/js-bindings/manual/jsb_global.h"
#include "cocos/scripting/js-bindings/auto/jsb_cocos2dx_auto.hpp"

#include "storage/local-storage/LocalStorage.h"

#include "cocos2d.h"

using namespace cocos2d;


class __JSPlistDelegator: public cocos2d::SAXDelegator
{
public:
    static __JSPlistDelegator* getInstance() {
        static __JSPlistDelegator* pInstance = NULL;
        if (pInstance == NULL) {
            pInstance = new (std::nothrow) __JSPlistDelegator();
        }
        return pInstance;
    };

    virtual ~__JSPlistDelegator();

    cocos2d::SAXParser* getParser();

    std::string parse(const std::string& path);
    std::string parseText(const std::string& text);

    // implement pure virtual methods of SAXDelegator
    void startElement(void *ctx, const char *name, const char **atts) override;
    void endElement(void *ctx, const char *name) override;
    void textHandler(void *ctx, const char *ch, size_t len) override;

private:
    cocos2d::SAXParser _parser;
    std::string _result;
    bool _isStoringCharacters;
    std::string _currentValue;
};

// cc.PlistParser.getInstance()
SE_FUNC_BEGIN(js_PlistParser_getInstance, se::DONT_NEED_THIS)
{
    __JSPlistDelegator* delegator = __JSPlistDelegator::getInstance();
    SAXParser* parser = delegator->getParser();

    if (parser) {
        se::Value jsval;
        native_ptr_to_seval<SAXParser>(parser, __jsb_cocos2dx_SAXParser_class, &jsval);
        SE_SET_RVAL(jsval);
    }
}
SE_FUNC_END

// cc.PlistParser.getInstance().parse(text)
SE_FUNC_BEGIN(js_PlistParser_parse, se::DONT_NEED_THIS)
{
    __JSPlistDelegator* delegator = __JSPlistDelegator::getInstance();

    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");

        std::string parsedStr = delegator->parseText(arg0);
        std::replace(parsedStr.begin(), parsedStr.end(), '\n', ' ');

        se::Value strVal;
        std_string_to_seval(parsedStr, &strVal);

        se::Object* robj = se::Object::createJSONObject(strVal.toString(), false);
        SE_SET_RVAL(se::Value(robj));
    }
    else
    {
        SE_REPORT_ERROR("js_PlistParser_parse : wrong number of arguments: %d, was expecting %d", argc, 1);
    }
}
SE_FUNC_END

cocos2d::SAXParser* __JSPlistDelegator::getParser() {
    return &_parser;
}

std::string __JSPlistDelegator::parse(const std::string& path) {
    _result.clear();

    SAXParser parser;
    if (false != parser.init("UTF-8") )
    {
        parser.setDelegator(this);
        parser.parse(FileUtils::getInstance()->fullPathForFilename(path));
    }

    return _result;
}

__JSPlistDelegator::~__JSPlistDelegator(){
    CCLOGINFO("deallocing __JSSAXDelegator: %p", this);
}

std::string __JSPlistDelegator::parseText(const std::string& text){
    _result.clear();

    SAXParser parser;
    if (false != parser.init("UTF-8") )
    {
        parser.setDelegator(this);
        parser.parse(text.c_str(), text.size());
    }

    return _result;
}

void __JSPlistDelegator::startElement(void *ctx, const char *name, const char **atts) {
    _isStoringCharacters = true;
    _currentValue.clear();

    std::string elementName = (char*)name;

    int end = (int)_result.size() - 1;
    if(end >= 0 && _result[end] != '{' && _result[end] != '[' && _result[end] != ':') {
        _result += ",";
    }

    if (elementName == "dict") {
        _result += "{";
    }
    else if (elementName == "array") {
        _result += "[";
    }
}

void __JSPlistDelegator::endElement(void *ctx, const char *name) {
    _isStoringCharacters = false;
    std::string elementName = (char*)name;

    if (elementName == "dict") {
        _result += "}";
    }
    else if (elementName == "array") {
        _result += "]";
    }
    else if (elementName == "key") {
        _result += "\"" + _currentValue + "\":";
    }
    else if (elementName == "string") {
        _result += "\"" + _currentValue + "\"";
    }
    else if (elementName == "false" || elementName == "true") {
        _result += elementName;
    }
    else if (elementName == "real" || elementName == "integer") {
        _result += _currentValue;
    }
}

void __JSPlistDelegator::textHandler(void* /*ctx*/, const char *ch, size_t len) {
    std::string text((char*)ch, 0, len);

    if (_isStoringCharacters)
    {
        _currentValue += text;
    }
}

// cc.sys.localStorage

SE_FUNC_BEGIN(JSB_localStorageGetItem, se::DONT_NEED_THIS)
{
    if (argc == 1)
    {
        std::string ret_val;
        bool ok = true;
        std::string key;
        ok = seval_to_std_string(args[0], &key);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");
        ok = localStorageGetItem(key, &ret_val);
        if (ok)
        {
            SE_SET_RVAL(se::Value(ret_val));
        }
    }
    else
    {
        SE_REPORT_ERROR("Invalid number of arguments");
    }
}
SE_FUNC_END

SE_FUNC_BEGIN(JSB_localStorageRemoveItem, se::DONT_NEED_THIS)
{
    if (argc == 1)
    {
        bool ok = true;
        std::string key;
        ok = seval_to_std_string(args[0], &key);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");
        localStorageRemoveItem(key);
    }
    else
    {
        SE_REPORT_ERROR("Invalid number of arguments");
    }
}
SE_FUNC_END

SE_FUNC_BEGIN(JSB_localStorageSetItem, se::DONT_NEED_THIS)
{
    if (argc == 2)
    {
        bool ok = true;
        std::string key;
        ok = seval_to_std_string(args[0], &key);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");

        std::string value;
        ok = seval_to_std_string(args[0], &value);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");
        localStorageSetItem(key, value);
    }
    else
    {
        SE_REPORT_ERROR("Invalid number of arguments");
    }
}
SE_FUNC_END

SE_FUNC_BEGIN(JSB_localStorageClear, se::DONT_NEED_THIS)
{
    if (argc == 0)
    {
        localStorageClear();
    }
    else
    {
        SE_REPORT_ERROR("Invalid number of arguments");
    }
}
SE_FUNC_END


static bool register_sys_localStorage(se::Object* obj)
{
    se::Value sys;
    if (!obj->getProperty("sys", &sys))
    {
        se::Object* sysObj = se::Object::createPlainObject(false);
        obj->setProperty("sys", se::Value(sysObj));
        sys.setObject(sysObj);
    }

    se::Object* localStorageObj = se::Object::createPlainObject(false);
    sys.toObject()->setProperty("localStorage", se::Value(localStorageObj));

    localStorageObj->defineFunction("getItem", JSB_localStorageGetItem);
    localStorageObj->defineFunction("removeItem", JSB_localStorageRemoveItem);
    localStorageObj->defineFunction("setItem", JSB_localStorageSetItem);
    localStorageObj->defineFunction("clear", JSB_localStorageClear);

    std::string strFilePath = cocos2d::FileUtils::getInstance()->getWritablePath();
    strFilePath += "/jsb.sqlite";
    localStorageInit(strFilePath);

    return true;
}

bool register_all_cocos2dx_manual(se::Object* obj)
{
    se::Value v;
    __ccObj->getProperty("PlistParser", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("getInstance", js_PlistParser_getInstance);

    __jsb_cocos2dx_SAXParser_proto->defineFunction("parse", js_PlistParser_parse);

    register_sys_localStorage(obj);

    return true;
}

