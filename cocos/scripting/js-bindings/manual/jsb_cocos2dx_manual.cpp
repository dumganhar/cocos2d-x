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
static bool js_PlistParser_getInstance(se::State& s)
{
    __JSPlistDelegator* delegator = __JSPlistDelegator::getInstance();
    SAXParser* parser = delegator->getParser();

    if (parser) {
        native_ptr_to_seval<SAXParser>(parser, __jsb_cocos2dx_SAXParser_class, &s.rval());
        return true;
    }
    return false;
}
SE_BIND_FUNC(js_PlistParser_getInstance)

// cc.PlistParser.getInstance().parse(text)
static bool js_PlistParser_parse(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
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
        s.rval().setObject(robj);
        return true;
    }
    SE_REPORT_ERROR("js_PlistParser_parse : wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PlistParser_parse)

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

static bool JSB_localStorageGetItem(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 1)
    {
        std::string ret_val;
        bool ok = true;
        std::string key;
        ok = seval_to_std_string(args[0], &key);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");
        std::string value;
        ok = localStorageGetItem(key, &value);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");
        s.rval().setString(value);
        return true;
    }

    SE_REPORT_ERROR("Invalid number of arguments");
    return false;
}
SE_BIND_FUNC(JSB_localStorageGetItem)

static bool JSB_localStorageRemoveItem(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 1)
    {
        bool ok = true;
        std::string key;
        ok = seval_to_std_string(args[0], &key);
        JSB_PRECONDITION2(ok, false, "Error processing arguments");
        localStorageRemoveItem(key);
        return true;
    }

    SE_REPORT_ERROR("Invalid number of arguments");
    return false;
}
SE_BIND_FUNC(JSB_localStorageRemoveItem)

static bool JSB_localStorageSetItem(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
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
        return true;
    }

    SE_REPORT_ERROR("Invalid number of arguments");
    return false;
}
SE_BIND_FUNC(JSB_localStorageSetItem)

static bool JSB_localStorageClear(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0)
    {
        localStorageClear();
        return true;
    }

    SE_REPORT_ERROR("Invalid number of arguments");
    return false;
}
SE_BIND_FUNC(JSB_localStorageClear)


static bool register_sys_localStorage(se::Object* obj)
{
    se::Value sys;
    if (!obj->getProperty("sys", &sys))
    {
        se::Object* sysObj = se::Object::createPlainObject(false);
        obj->setProperty("sys", se::Value(sysObj));
        sys.setObject(sysObj);
        sysObj->release();
    }

    se::Object* localStorageObj = se::Object::createPlainObject(false);
    sys.toObject()->setProperty("localStorage", se::Value(localStorageObj));

    localStorageObj->defineFunction("getItem", _SE(JSB_localStorageGetItem));
    localStorageObj->defineFunction("removeItem", _SE(JSB_localStorageRemoveItem));
    localStorageObj->defineFunction("setItem", _SE(JSB_localStorageSetItem));
    localStorageObj->defineFunction("clear", _SE(JSB_localStorageClear));
    localStorageObj->release();

    std::string strFilePath = cocos2d::FileUtils::getInstance()->getWritablePath();
    strFilePath += "/jsb.sqlite";
    localStorageInit(strFilePath);

    return true;
}

//

static bool js_EventListenerMouse_create(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 0) {
        auto ret = EventListenerMouse::create();
        ret->retain();

        ret->onMouseDown = [ret](Event* event) {
//FIXME:            ScriptingCore::getInstance()->handleMouseEvent(ret, EventMouse::MouseEventType::MOUSE_DOWN, event);
        };

        ret->onMouseUp = [ret](Event* event) {
//            ScriptingCore::getInstance()->handleMouseEvent(ret, EventMouse::MouseEventType::MOUSE_UP, event);
        };

        ret->onMouseMove = [ret](Event* event) {
//            ScriptingCore::getInstance()->handleMouseEvent(ret, EventMouse::MouseEventType::MOUSE_MOVE, event);
        };

        ret->onMouseScroll = [ret](Event* event) {
//            ScriptingCore::getInstance()->handleMouseEvent(ret, EventMouse::MouseEventType::MOUSE_SCROLL, event);
        };

        se::Object* obj = se::Object::createObjectWithClass(__jsb_cocos2dx_EventListenerMouse_class, false);
        obj->setPrivateData(ret);
        s.rval().setObject(obj);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
SE_BIND_FUNC(js_EventListenerMouse_create)

static bool js_EventListenerTouchOneByOne_create(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 0) {
        auto ret = EventListenerTouchOneByOne::create();
        ret->retain();

        ret->onTouchBegan = [ret](Touch* touch, Event* event) -> bool {
//FIXME:            JS::RootedValue jsret(cx);
//            bool ok = ScriptingCore::getInstance()->handleTouchEvent(ret, EventTouch::EventCode::BEGAN, touch, event, &jsret);
//
//            // Not found the method, just return false.
//            if (!ok)
//                return false;
//
//            if (jsret.isBoolean()) {
//                return jsret.toBoolean();
//            }
            return false;
        };

        ret->onTouchMoved = [ret](Touch* touch, Event* event) {
//            ScriptingCore::getInstance()->handleTouchEvent(ret, EventTouch::EventCode::MOVED, touch, event);
        };

        ret->onTouchEnded = [ret](Touch* touch, Event* event) {
//            ScriptingCore::getInstance()->handleTouchEvent(ret, EventTouch::EventCode::ENDED, touch, event);
        };

        ret->onTouchCancelled = [ret](Touch* touch, Event* event) {
//            ScriptingCore::getInstance()->handleTouchEvent(ret, EventTouch::EventCode::CANCELLED, touch, event);
        };

        se::Object* obj = se::Object::createObjectWithClass(__jsb_cocos2dx_EventListenerTouchOneByOne_class, false);
        obj->setPrivateData(ret);
        s.rval().setObject(obj);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
SE_BIND_FUNC(js_EventListenerTouchOneByOne_create)

static bool js_EventListenerTouchAllAtOnce_create(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 0) {
        auto ret = EventListenerTouchAllAtOnce::create();
        ret->retain();

        ret->onTouchesBegan = [ret](const std::vector<Touch*>& touches, Event* event) {
//FIXME:            ScriptingCore::getInstance()->handleTouchesEvent(ret, EventTouch::EventCode::BEGAN, touches, event);
        };

        ret->onTouchesMoved = [ret](const std::vector<Touch*>& touches, Event* event) {
//            ScriptingCore::getInstance()->handleTouchesEvent(ret, EventTouch::EventCode::MOVED, touches, event);
        };

        ret->onTouchesEnded = [ret](const std::vector<Touch*>& touches, Event* event) {
//            ScriptingCore::getInstance()->handleTouchesEvent(ret, EventTouch::EventCode::ENDED, touches, event);
        };

        ret->onTouchesCancelled = [ret](const std::vector<Touch*>& touches, Event* event) {
//            ScriptingCore::getInstance()->handleTouchesEvent(ret, EventTouch::EventCode::CANCELLED, touches, event);
        };

        se::Object* obj = se::Object::createObjectWithClass(__jsb_cocos2dx_EventListenerTouchAllAtOnce_class, false);
        obj->setPrivateData(ret);
        s.rval().setObject(obj);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
SE_BIND_FUNC(js_EventListenerTouchAllAtOnce_create)

static bool js_EventListenerKeyboard_create(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 0) {
        auto ret = EventListenerKeyboard::create();
        ret->retain();

        ret->onKeyPressed = [ret](EventKeyboard::KeyCode keyCode, Event* event) {
//FIXME:            ScriptingCore::getInstance()->handleKeyboardEvent(ret, keyCode, true, event);
        };

        ret->onKeyReleased = [ret](EventKeyboard::KeyCode keyCode, Event* event) {
//            ScriptingCore::getInstance()->handleKeyboardEvent(ret, keyCode, false, event);
        };

        se::Object* obj = se::Object::createObjectWithClass(__jsb_cocos2dx_EventListenerKeyboard_class, false);
        obj->setPrivateData(ret);
        s.rval().setObject(obj);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
SE_BIND_FUNC(js_EventListenerKeyboard_create)

static bool js_EventListenerAcceleration_create(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 1) {

        std::function<void (Acceleration*, Event*)> arg0;
        do {
            if (args[0].isObject() && args[0].toObject()->isFunction())
            {
                se::Value jsThis(s.thisObject());
                se::Value jsFunc(args[0]);
                jsThis.toObject()->attachChild(jsFunc.toObject());
                auto lambda = [=](Acceleration* acc, Event* event) -> void {
                    bool ok = true;
                    se::ValueArray args;
                    args.resize(2);
                    ok = Acceleration_to_seval(acc, &args[0]);
                    ok = native_ptr_to_seval<Event>(event, &args[1]);
                    se::Value rval;
                    se::Object* thisObj = jsThis.toObject();
                    se::Object* funcObj = jsFunc.toObject();
                    bool succeed = funcObj->call(args, thisObj, &rval);
                    if (!succeed) {
                        se::ScriptEngine::getInstance()->clearException();
                    }
                };
                arg0 = lambda;
            }
            else
            {
                arg0 = nullptr;
            }
        } while(false);

        auto ret = EventListenerAcceleration::create(arg0);
        ret->retain();

        se::Object* obj = se::Object::createObjectWithClass(__jsb_cocos2dx_EventListenerMouse_class, false);
        obj->setPrivateData(ret);
        s.rval().setObject(obj);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_EventListenerAcceleration_create)

static bool js_EventListenerFocus_create(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 0) {
        auto ret = EventListenerFocus::create();
        ret->retain();

        assert(false);

        se::Object* obj = se::Object::createObjectWithClass(__jsb_cocos2dx_EventListenerMouse_class, false);
        obj->setPrivateData(ret);
        s.rval().setObject(obj);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
SE_BIND_FUNC(js_EventListenerFocus_create)

static bool js_EventListenerCustom_create(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 2) {
        assert(false);
        auto ret = nullptr;//EventListenerCustom::create();
//        ret->retain();



        se::Object* obj = se::Object::createObjectWithClass(__jsb_cocos2dx_EventListenerMouse_class, false);
        obj->setPrivateData(ret);
        s.rval().setObject(obj);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
SE_BIND_FUNC(js_EventListenerCustom_create)

static bool register_eventlistener(se::Object* obj)
{
    se::Value v;
    __ccObj->getProperty("EventListenerMouse", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("create", _SE(js_EventListenerMouse_create));

    __ccObj->getProperty("EventListenerTouchOneByOne", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("create", _SE(js_EventListenerTouchOneByOne_create));

    __ccObj->getProperty("EventListenerTouchAllAtOnce", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("create", _SE(js_EventListenerTouchAllAtOnce_create));

    __ccObj->getProperty("EventListenerKeyboard", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("create", _SE(js_EventListenerKeyboard_create));

    __ccObj->getProperty("EventListenerAcceleration", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("create", _SE(js_EventListenerAcceleration_create));

    __ccObj->getProperty("EventListenerFocus", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("create", _SE(js_EventListenerFocus_create));

    __ccObj->getProperty("EventListenerCustom", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("create", _SE(js_EventListenerCustom_create));

    return true;
}

//

static bool js_cocos2dx_Sequence_or_Spawn_create(se::State& s, se::Class* cls)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    bool ok = true;

    if (argc > 0)
    {
        Vector<FiniteTimeAction*> array;

        if (argc == 1 && args[0].isObject() && args[0].toObject()->isArray())
        {
            ok &= seval_to_Vector(args[0], &array);
            JSB_PRECONDITION2(ok, false, "Error processing arguments");
        }
        else
        {
            uint32_t i = 0;
            while (i < argc)
            {
                assert(args[i].isObject());
                FiniteTimeAction* item = (FiniteTimeAction*)args[i].toObject()->getPrivateData();

                array.pushBack(item);
                i++;
            }
        }
        auto ret = new (std::nothrow) Sequence();
        ok = ret->init(array);
        if (ok)
        {
            se::Object* obj = se::Object::createObjectWithClass(cls, false);
            obj->setPrivateData(ret);
            s.rval().setObject(obj);
        }
        return ok;
    }
    SE_REPORT_ERROR("wrong number of arguments");
    return false;
}

static bool js_cocos2dx_Sequence_create(se::State& s)
{
    return js_cocos2dx_Sequence_or_Spawn_create(s, __jsb_cocos2dx_Sequence_class);
}
SE_BIND_FUNC(js_cocos2dx_Sequence_create)

static bool js_cocos2dx_Spawn_create(se::State& s)
{
    return js_cocos2dx_Sequence_or_Spawn_create(s, __jsb_cocos2dx_Spawn_class);
}
SE_BIND_FUNC(js_cocos2dx_Spawn_create)

// ActionInterval

static void rebindNativeObject(se::Object* seObj, cocos2d::Ref* oldRef, cocos2d::Ref* newRef)
{
    // Release the old reference as it have been retained by 'action' previously,
    // and the 'action' won't have any chance to release it in the future
    oldRef->release();
    seObj->clearPrivateData();
    seObj->setPrivateData(newRef);
}

static bool js_cocos2dx_ActionInterval_repeat(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    cocos2d::ActionInterval* cobj = (cocos2d::ActionInterval *)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_ActionInterval_repeat : Invalid Native Object");

    if (argc == 1)
    {
        double times;
        if( !seval_to_double(args[0], &times) ) {
            return false;
        }
        int timesInt = (int)times;
        if (timesInt <= 0) {
            SE_REPORT_ERROR("js_cocos2dx_ActionInterval_repeat : Repeat times must be greater than 0");
        }

        cocos2d::Repeat* action = new (std::nothrow) cocos2d::Repeat;
        bool ok = action->initWithAction(cobj, timesInt);
        if (ok)
        {
            rebindNativeObject(s.thisObject(), cobj, action);
            s.rval().setObject(s.thisObject());
        }
        return ok;
    }

    SE_REPORT_ERROR("js_cocos2dx_ActionInterval_repeat : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_ActionInterval_repeat)

static bool js_cocos2dx_ActionInterval_repeatForever(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    cocos2d::ActionInterval* cobj = (cocos2d::ActionInterval *)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_ActionInterval_repeatForever : Invalid Native Object");

    if (argc == 0) {
        cocos2d::RepeatForever* action = new (std::nothrow) cocos2d::RepeatForever;
        bool ok = action->initWithAction(cobj);
        if (ok)
        {
            rebindNativeObject(s.thisObject(), cobj, action);
            s.rval().setObject(s.thisObject());
        }
        return ok;
    }

    SE_REPORT_ERROR("js_cocos2dx_ActionInterval_repeatForever : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_ActionInterval_repeatForever)

static bool js_cocos2dx_ActionInterval_speed(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    cocos2d::ActionInterval* cobj = (cocos2d::ActionInterval *)s.nativeThisObject();
    JSB_PRECONDITION2( cobj, false, "js_cocos2dx_ActionInterval_speed : Invalid Native Object");

    if (argc == 1)
    {
        double speed;
        if( !seval_to_double(args[0], &speed) ) {
            return false;
        }
        if (speed < 0) {
            SE_REPORT_ERROR("js_cocos2dx_ActionInterval_speed : Speed must not be negative");
            return false;
        }

        cocos2d::Speed* action = new (std::nothrow) cocos2d::Speed;
        bool ok = action->initWithAction(cobj, speed);
        if (ok)
        {
            rebindNativeObject(s.thisObject(), cobj, action);
            s.rval().setObject(s.thisObject());
        }
        return ok;
    }

    SE_REPORT_ERROR("js_cocos2dx_ActionInterval_speed : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_ActionInterval_speed)

enum ACTION_TAG {
    EASE_IN = 0,
    EASE_OUT,
    EASE_INOUT,
    EASE_EXPONENTIAL_IN,
    EASE_EXPONENTIAL_OUT,
    EASE_EXPONENTIAL_INOUT,
    EASE_SINE_IN,
    EASE_SINE_OUT,
    EASE_SINE_INOUT,
    EASE_ELASTIC_IN,
    EASE_ELASTIC_OUT,
    EASE_ELASTIC_INOUT,
    EASE_BOUNCE_IN,
    EASE_BOUNCE_OUT,
    EASE_BOUNCE_INOUT,
    EASE_BACK_IN,
    EASE_BACK_OUT,
    EASE_BACK_INOUT,

    EASE_BEZIER_ACTION,
    EASE_QUADRATIC_IN,
    EASE_QUADRATIC_OUT,
    EASE_QUADRATIC_INOUT,
    EASE_QUARTIC_IN,
    EASE_QUARTIC_OUT,
    EASE_QUARTIC_INOUT,
    EASE_QUINTIC_IN,
    EASE_QUINTIC_OUT,
    EASE_QUINTIC_INOUT,
    EASE_CIRCLE_IN,
    EASE_CIRCLE_OUT,
    EASE_CIRCLE_INOUT,
    EASE_CUBIC_IN,
    EASE_CUBIC_OUT,
    EASE_CUBIC_INOUT
};

static bool js_cocos2dx_ActionInterval_easing(se::State& s)
{
    const auto& args = s.args();
    uint32_t argc = (uint32_t)args.size();
    cocos2d::ActionInterval* oldAction = (cocos2d::ActionInterval *)s.nativeThisObject();
    JSB_PRECONDITION2 (oldAction, false, "js_cocos2dx_ActionInterval_easing : Invalid Native Object");

    cocos2d::ActionInterval* newAction = nullptr;
    se::Value jsTag;
    se::Value jsParam;
    double tag = 0.0;
    double parameter = 0.0;

    for (uint32_t i = 0; i < argc; i++)
    {
        const auto& vpi = args[i];
        bool ok = vpi.isObject() && vpi.toObject()->getProperty("tag", &jsTag) && seval_to_double(jsTag, &tag);
        if (vpi.toObject()->getProperty("param", &jsParam))
            seval_to_double(jsParam, &parameter);

        bool hasParam = (parameter == parameter);
        if (!ok) continue;

        ok = true;
        if (tag == EASE_IN)
        {
            if (!hasParam) ok = false;
            auto tmpaction = new (std::nothrow) cocos2d::EaseIn;
            tmpaction->initWithAction(oldAction, parameter);
            newAction = tmpaction;
        }
        else if (tag == EASE_OUT)
        {
            if (!hasParam) ok = false;
            auto tmpaction = new (std::nothrow) cocos2d::EaseOut;
            tmpaction->initWithAction(oldAction, parameter);
            newAction = tmpaction;
        }
        else if (tag == EASE_INOUT)
        {
            if (!hasParam) ok = false;
            auto tmpaction = new (std::nothrow) cocos2d::EaseInOut;
            tmpaction->initWithAction(oldAction, parameter);
            newAction = tmpaction;
        }
        else if (tag == EASE_EXPONENTIAL_IN)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseExponentialIn;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_EXPONENTIAL_OUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseExponentialOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_EXPONENTIAL_INOUT)
        {
            auto tmpaction = new (std::nothrow)cocos2d::EaseExponentialInOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_SINE_IN)
        {
            auto tmpaction = new (std::nothrow)cocos2d::EaseSineIn;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_SINE_OUT)
        {
            auto tmpaction = new (std::nothrow)cocos2d::EaseSineOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_SINE_INOUT)
        {
            auto tmpaction = new (std::nothrow)cocos2d::EaseSineInOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_ELASTIC_IN)
        {
            if (!hasParam) parameter = 0.3;
            auto tmpaction = new (std::nothrow)cocos2d::EaseElasticIn;
            tmpaction->initWithAction(oldAction, parameter);
            newAction = tmpaction;
        }
        else if (tag == EASE_ELASTIC_OUT)
        {
            if (!hasParam) parameter = 0.3;
            auto tmpaction = new (std::nothrow)cocos2d::EaseElasticOut;
            tmpaction->initWithAction(oldAction, parameter);
            newAction = tmpaction;
        }
        else if (tag == EASE_ELASTIC_INOUT)
        {
            if (!hasParam) parameter = 0.3;
            auto tmpaction = new (std::nothrow)cocos2d::EaseElasticInOut;
            tmpaction->initWithAction(oldAction, parameter);
            newAction = tmpaction;
        }
        else if (tag == EASE_BOUNCE_IN)
        {
            auto tmpaction = new (std::nothrow)cocos2d::EaseBounceIn;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_BOUNCE_OUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseBounceOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_BOUNCE_INOUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseBounceInOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_BACK_IN)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseBackIn;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_BACK_OUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseBackOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_BACK_INOUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseBackInOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_QUADRATIC_IN)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseQuadraticActionIn;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_QUADRATIC_OUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseQuadraticActionOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_QUADRATIC_INOUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseQuadraticActionInOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_QUARTIC_IN)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseQuarticActionIn;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_QUARTIC_OUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseQuarticActionOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_QUARTIC_INOUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseQuarticActionInOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_QUINTIC_IN)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseQuinticActionIn;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_QUINTIC_OUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseQuinticActionOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_QUINTIC_INOUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseQuinticActionInOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_CIRCLE_IN)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseCircleActionIn;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_CIRCLE_OUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseCircleActionOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_CIRCLE_INOUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseCircleActionInOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_CUBIC_IN)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseCubicActionIn;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_CUBIC_OUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseCubicActionOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_CUBIC_INOUT)
        {
            auto tmpaction = new (std::nothrow) cocos2d::EaseCubicActionInOut;
            tmpaction->initWithAction(oldAction);
            newAction = tmpaction;
        }
        else if (tag == EASE_BEZIER_ACTION)
        {
            se::Value jsParam2;
            se::Value jsParam3;
            se::Value jsParam4;
            double parameter2, parameter3, parameter4;
            ok &= vpi.toObject()->getProperty("param2", &jsParam2);
            ok &=seval_to_double(jsParam2, &parameter2);
            ok &= vpi.toObject()->getProperty("param3", &jsParam3);
            ok &=seval_to_double(jsParam3, &parameter3);
            ok &= vpi.toObject()->getProperty("param4", &jsParam4);
            ok &=seval_to_double(jsParam4, &parameter4);
            if (!ok) continue;

            auto tmpaction = new (std::nothrow) cocos2d::EaseBezierAction;
            tmpaction->initWithAction(oldAction);
            tmpaction->setBezierParamer(parameter, parameter2, parameter3, parameter4);
            newAction = tmpaction;
        }
        else
            continue;

        if (!ok || !newAction) {
            SE_REPORT_ERROR("js_cocos2dx_ActionInterval_easing : Invalid action: At least one action was expecting parameter");
            return false;
        }
    }

    rebindNativeObject(s.thisObject(), oldAction, newAction);
    s.rval().setObject(s.thisObject());

    return true;
}
SE_BIND_FUNC(js_cocos2dx_ActionInterval_easing)

//

static bool js_cocos2dx_CallFunc_init(cocos2d::CallFuncN* nativeObj, se::Object* jsobj, const se::ValueArray& args)
{
    int argc = (int)args.size();

    se::Value funcVal = args[0];
    se::Value thisVal;
    se::Value dataVal;

    if (!funcVal.isObject() || !funcVal.toObject()->isFunction())
    {
        JSB_PRECONDITION2(false, false, "js_cocos2dx_CallFunc_create, args[0](func) isn't a function object");
    }

    jsobj->attachChild(funcVal.toObject());

    if (argc >= 2)
    {
        thisVal = args[1];
        if (!thisVal.isObject())
        {
            JSB_PRECONDITION2(false, false, "js_cocos2dx_CallFunc_create, args[1](this) isn't an object");
        }
        jsobj->attachChild(thisVal.toObject());
    }

    if (argc >= 3)
    {
        dataVal = args[2];
        jsobj->attachChild(dataVal.toObject());
    }

    bool ok = nativeObj->initWithFunction([=](Node* sender){

        se::ScriptEngine::getInstance()->clearException();

        if (sender == nullptr)
        {
            sender = nativeObj->getTarget();
        }

        se::Value senderVal;
        if (sender != nullptr)
        {
            native_ptr_to_seval<Node>(sender, &senderVal);
        }

        if (!funcVal.isNullOrUndefined())
        {
            se::ValueArray valArr;
            valArr.reserve(2);
            valArr.push_back(senderVal);
            valArr.push_back(dataVal);

            funcVal.toObject()->call(valArr, thisVal.toObject());
        }
        else
        {
            JSB_PRECONDITION2_VOID(false, "js_cocos2dx_CallFunc_create, funcVal is null or undefined!");
        }
    });

    return ok;
}

// cc.CallFunc.create( func, this, [data])
// cc.CallFunc.create( func )
static bool js_cocos2dx_CallFunc_create(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc >= 1 && argc <= 3)
    {
        CallFuncN* ret = new (std::nothrow) CallFuncN;
        se::Object* jsobj = se::Object::createObjectWithClass(__jsb_cocos2dx_CallFuncN_class, false);
        jsobj->setPrivateData(ret);

        if (js_cocos2dx_CallFunc_init(ret, jsobj, args))
        {
            s.rval().setObject(jsobj);
            return true;
        }
        SE_REPORT_ERROR("js_cocos2dx_CallFunc_create: initWithFunction failed!");
        return false;
    }
    SE_REPORT_ERROR("js_cocos2dx_CallFunc_create: Invalid number of arguments");
    return false;
}
SE_BIND_FUNC(js_cocos2dx_CallFunc_create)

// callFunc.initWithFunction( func, this, [data])
// callFunc.initWithFunction( func )
static bool js_cocos2dx_CallFunc_initWithFunction(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc >= 1 && argc <= 3)
    {
        se::Object* jsobj = s.thisObject();
        if (js_cocos2dx_CallFunc_init((CallFuncN*)s.nativeThisObject(), jsobj, args))
        {
            s.rval().setBoolean(true);
            return true;
        }
        SE_REPORT_ERROR("js_cocos2dx_CallFunc_initWithFunction: initWithFunction failed!");
        return false;
    }
    SE_REPORT_ERROR("js_cocos2dx_CallFunc_initWithFunction: Invalid number of arguments");
    return false;
}
SE_BIND_FUNC(js_cocos2dx_CallFunc_initWithFunction)

bool register_all_cocos2dx_manual(se::Object* obj)
{
    se::Value v;
    __ccObj->getProperty("PlistParser", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("getInstance", _SE(js_PlistParser_getInstance));

    __jsb_cocos2dx_SAXParser_proto->defineFunction("parse", _SE(js_PlistParser_parse));

    register_sys_localStorage(obj);
    register_eventlistener(obj);

    __ccObj->getProperty("Sequence", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("create", _SE(js_cocos2dx_Sequence_create));

    __ccObj->getProperty("Spawn", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("create", _SE(js_cocos2dx_Spawn_create));

    se::Object* proto = __jsb_cocos2dx_ActionInterval_proto;
    proto->defineFunction("repeat", _SE(js_cocos2dx_ActionInterval_repeat));
    proto->defineFunction("repeatForever", _SE(js_cocos2dx_ActionInterval_repeatForever));
    proto->defineFunction("_speed", _SE(js_cocos2dx_ActionInterval_speed));
    proto->defineFunction("easing", _SE(js_cocos2dx_ActionInterval_easing));

    __ccObj->getProperty("CallFunc", &v);
    assert(v.isObject());
    v.toObject()->defineFunction("create", _SE(js_cocos2dx_CallFunc_create));

    proto = __jsb_cocos2dx_CallFuncN_proto;
    proto->defineFunction("initWithFunction", _SE(js_cocos2dx_CallFunc_initWithFunction));

    return true;
}

