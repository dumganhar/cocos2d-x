#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init() {
    if (!Layer::init() ) return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    sprite2d = Sprite::create("bang.png");
//    sprite2d->setPosition(origin + visibleSize/2);
    sprite2d->retain();

    // Ship - Model is from cocos2d-x test project
    ship3D = Sprite3D::create("fonts/boss.c3b");
    ship3D->setScale(17);
    ship3D->setRotation3D(Vec3(180,45,0));
    ship3D->setPosition(Vec2(1280/4 + origin.x, visibleSize.height/2 + origin.y));
    ship3D->retain();
//    addChild(ship3D, 1);

    ship3D->setForce2DQueue(true);


    ship3D2 = Sprite3D::create("fonts/boss.c3b");
    ship3D2->setScale(17);
    ship3D2->setRotation3D(Vec3(180,45,0));
    ship3D2->setPosition(Vec2(1280/4 + origin.x, visibleSize.height/2 + origin.y));
    ship3D2->retain();
    ship3D2->setForce2DQueue(true);

    ship3D3 = Sprite3D::create("fonts/boss.c3b");
    ship3D3->setScale(17);
    ship3D3->setRotation3D(Vec3(180,45,0));
    ship3D3->setPosition(Vec2(0 + origin.x, visibleSize.height/2 + origin.y));
    ship3D3->retain();
    ship3D3->setForce2DQueue(true);


    // Rotate Ship
//    auto spin = RotateBy::create(4, Vec3(0,180,0));
//    auto repeatspin = RepeatForever::create(spin);
//    ship3D->runAction(repeatspin);

    // RenderTextures
//    renderTexDefault = RenderTexture::create(1280, 720, Texture2D::PixelFormat::RGBA8888);
//    addChild(renderTexDefault);
//    renderTexDefault->setPosition(1280/4 * 3, 720/2);

    renderTexWithBuffer = RenderTexture::create(1280, 720, Texture2D::PixelFormat::RGBA8888, GL_DEPTH24_STENCIL8);
    addChild(renderTexWithBuffer);
    renderTexWithBuffer->setPosition(1280/4 * 4, 720/2);

    // Update
    scheduleUpdate();

    // Labels
    auto label = Label::createWithTTF("Sprite3D with RenderTextures", "fonts/arial.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    auto label1 = Label::createWithTTF("Normal Sprite3D\n", "fonts/arial.ttf", 24);
    label1->setPosition(Vec2(1280/4 * 1, 100));
    this->addChild(label1, 1);

    auto label2 = Label::createWithTTF("RenderTexture\nDefault - No depth buffer", "fonts/arial.ttf", 24);
    label2->setPosition(Vec2(1280/4 * 2, 100));
    this->addChild(label2, 1);

    auto label3 = Label::createWithTTF("RenderTexture\nGL_DEPTH24_STENCIL8", "fonts/arial.ttf", 24);
    label3->setPosition(Vec2(1280/4 * 3, 100));
    this->addChild(label3, 1);

    return true;
}

void HelloWorld::update(float delta)
{
    static float rotationY = 0.0f;
    rotationY += 1.0f;
    ship3D->setRotation3D(Vec3(0, rotationY, 0));
    ship3D2->setRotation3D(Vec3(0, rotationY, 0));
    ship3D3->setRotation3D(Vec3(0, rotationY, 0));

//    ship3D->visit(Director::getInstance()->getRenderer(), Mat4::IDENTITY, FLAGS_TRANSFORM_DIRTY);

//    Mat4 translate;
//    translate.translate(300, 0, 0);
//
//    renderTexDefault->beginWithClear(1, 0, 0, 0, 0, 0);
//    ship3D2->visit(Director::getInstance()->getRenderer(), translate, FLAGS_TRANSFORM_DIRTY);
//    renderTexDefault->end();

    Mat4 translate2;
    translate2.translate(100, 100, 0);

    renderTexWithBuffer->beginWithClear(0, 1, 0, 0, 1, 0);
    sprite2d->visit(Director::getInstance()->getRenderer(), translate2, 0);
    ship3D3->visit(Director::getInstance()->getRenderer(), translate2, 0);
    renderTexWithBuffer->end();
}

