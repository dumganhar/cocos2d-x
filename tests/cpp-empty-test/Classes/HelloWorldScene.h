#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(HelloWorld);

    cocos2d::Sprite* sprite2d;
    cocos2d::Sprite3D *ship3D;
    cocos2d::Sprite3D *ship3D2;
    cocos2d::Sprite3D *ship3D3;

    cocos2d::RenderTexture *renderTexDefault;
    cocos2d::RenderTexture *renderTexWithBuffer;

    int frame;
    void update(float delta);
};

#endif // __HELLOWORLD_SCENE_H__
