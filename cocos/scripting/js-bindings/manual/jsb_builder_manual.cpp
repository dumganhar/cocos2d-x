//
//  jsb_ccb_reader.cpp
//  cocos2d_js_bindings
//
//  Created by James Chen on 6/13/17.
//
//

#include "jsb_builder_manual.hpp"
#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "cocos/scripting/js-bindings/manual/jsb_conversions.hpp"
#include "cocos/scripting/js-bindings/manual/jsb_global.h"
#include "cocos/scripting/js-bindings/auto/jsb_cocos2dx_builder_auto.hpp"

#include "cocos2d.h"
#include "cocos/editor-support/cocosbuilder/CocosBuilder.h"
#include "extensions/cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocosbuilder;

class CCBScriptCallbackProxy
: public cocos2d::Layer
, public cocosbuilder::CCBSelectorResolver
, public cocosbuilder::CCBMemberVariableAssigner
{
    std::string callBackProp;
    se::Value owner;
public:
    CCBScriptCallbackProxy () {}
    virtual ~CCBScriptCallbackProxy() {}

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CCBScriptCallbackProxy, create);
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget,
                                                                    const char * pSelectorName);

    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget,
                                                                               const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName,
                                           cocos2d::Node * pNode);
    virtual void onNodeLoaded(cocos2d::Node * pNode,
                              cocosbuilder::NodeLoader * pNodeLoader);

    virtual CCBSelectorResolver * createNew();
    void menuItemCallback(Ref *pSender);
    void controlCallback(Ref *pSender, cocos2d::extension::Control::EventType event);
    void setCallbackProperty(const char *prop);
    void setJSOwner(const se::Value& ownr);
    const se::Value& getJSOwner() const;
};

static void removeSelector(std::string &str) {
    size_t found;
    found = str.find(":");
    while (found!=std::string::npos){
        str.replace(found, found+1, "");
        found = str.find(":");
    }
}

SEL_MenuHandler CCBScriptCallbackProxy::onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget,
                                                                       const char * pSelectorName)
{
    this->callBackProp = pSelectorName;
    removeSelector(this->callBackProp);
    return menu_selector(CCBScriptCallbackProxy::menuItemCallback);
}

Control::Handler CCBScriptCallbackProxy::onResolveCCBCCControlSelector(Ref * pTarget,
                                                                       const char * pSelectorName)
{

    this->callBackProp = pSelectorName;
    removeSelector(this->callBackProp);
    return cccontrol_selector(CCBScriptCallbackProxy::controlCallback);
}

bool CCBScriptCallbackProxy::onAssignCCBMemberVariable(Ref * pTarget,
                                                       const char * pMemberVariableName,
                                                       Node * pNode)
{
    return true;
}

void CCBScriptCallbackProxy::onNodeLoaded(Node * pNode,
                                          NodeLoader * pNodeLoader)
{
}

CCBSelectorResolver * CCBScriptCallbackProxy::createNew()
{
    CCBScriptCallbackProxy * ret = new (std::nothrow) CCBScriptCallbackProxy();
    ret->setJSOwner(this->owner);
    return dynamic_cast<CCBSelectorResolver *>(ret);
}

void CCBScriptCallbackProxy::menuItemCallback(Ref *pSender)
{
//    jsval arg;
//    ScriptingCore::getInstance()->executeFunctionWithOwner(owner, callBackProp.c_str(), 0, &arg);
}

void CCBScriptCallbackProxy::controlCallback(Ref *pSender, Control::EventType event)
{
//    jsval arg;
//    ScriptingCore::getInstance()->executeFunctionWithOwner(owner, callBackProp.c_str(), 0, &arg);
}

void CCBScriptCallbackProxy::setCallbackProperty(const char *prop)
{
    callBackProp = prop;
}

void CCBScriptCallbackProxy::setJSOwner(const se::Value& ownr)
{
    owner = ownr;
}

const se::Value& CCBScriptCallbackProxy::getJSOwner() const
{
    return owner;
}

class JSLayerLoader : public cocosbuilder::LayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(JSLayerLoader, loader);

protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CCBScriptCallbackProxy);
};


static bool js_CocosBuilder_create(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 0)
    {
        NodeLoaderLibrary * ccNodeLoaderLibrary = NodeLoaderLibrary::getInstance();
        ccNodeLoaderLibrary->registerNodeLoader("", JSLayerLoader::loader());
        CCBReader* ret = new (std::nothrow) CCBReader(ccNodeLoaderLibrary);
        se::Object* jsobj = se::Object::createObjectWithClass(__jsb_cocosbuilder_CCBReader_class, false);
        jsobj->setPrivateData(ret);
        s.rval().setObject(jsobj);
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
SE_BIND_FUNC(js_CocosBuilder_create)

static bool js_cocos2dx_CCBReader_createSceneWithNodeGraphFromFile(se::State& s)
{
    return false;
}
SE_BIND_FUNC(js_cocos2dx_CCBReader_createSceneWithNodeGraphFromFile)

static bool js_cocos2dx_CCBReader_readNodeGraphFromFile(se::State& s)
{
    return false;
}
SE_BIND_FUNC(js_cocos2dx_CCBReader_readNodeGraphFromFile)

static bool js_cocos2dx_CCBAnimationManager_setCompletedAnimationCallback(se::State& s)
{
    return false;
}
SE_BIND_FUNC(js_cocos2dx_CCBAnimationManager_setCompletedAnimationCallback)

bool register_all_builder_manual(se::Object* obj)
{
    se::Value tmp;
    __ccObj->getProperty("_Reader", &tmp);
    assert(tmp.isObject());
    tmp.toObject()->defineFunction("create", _SE(js_CocosBuilder_create));
//    tmp.toObject()->defineFunction("loadScene", _SE(js_cocos2dx_CCBReader_createSceneWithNodeGraphFromFile));

//    __jsb_cocosbuilder_CCBReader_proto->defineFunction("load", _SE(js_cocos2dx_CCBReader_readNodeGraphFromFile));
    __jsb_cocosbuilder_CCBAnimationManager_proto->defineFunction("setCompletedAnimationCallback", _SE(js_cocos2dx_CCBAnimationManager_setCompletedAnimationCallback));

    return true;
}
