#include "HelloWorldScene.h"
#include "AppMacros.h"

#include "cocos/audio/include/AudioEngine.h"
#include "cocos/audio/openal/AudioFrameProviderFactory.h"
#include "cocos/audio/openal/AudioFrameBuffer.h"

USING_NS_CC;
using namespace cocos2d::experimental;

Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
    
    closeItem->setPosition(origin + Vec2(visibleSize) - Vec2(closeItem->getContentSize() / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/arial.ttf", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    label->setPosition(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height);

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize / 2) + origin);

    // add the sprite as a child to this layer
    this->addChild(sprite);
    
    return true;
}

std::shared_ptr<IAudioFrameProvider> provider;

void HelloWorld::menuCloseCallback(Ref* sender)
{
//    AudioEngine::play2d("fonts/test.mp3");
    AudioEngine::play2d("fonts/background.mp3", true);
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
    
//    provider = AudioFrameProviderFactory::getAudioFrameProvider("fonts/test.mp3");
////    std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    AudioFrameBuffer ioFrame;
//    ioFrame.frameCount = 112;
//    log("read frame count1: %d", provider->read(&ioFrame));
//    ioFrame.frameCount = 31 * 100;
//    log("read frame count11: %d", provider->read(&ioFrame));
//    
//    scheduleOnce([](float dt){
//        {
//        AudioFrameBuffer ioFrame;
//        ioFrame.frameCount = 1102 * 5;
//        log("read frame count2: %d", provider->read(&ioFrame));
//        }
//    }, 0.01f, "test");
//    
    
}
