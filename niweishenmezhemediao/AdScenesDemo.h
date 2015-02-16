//
//  AdScenesDemo.h
//  AdViewCocos2dxHello
//
//  Created by the user on 12-8-20.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef AdViewCocos2dxHello_AdScenesDemo_h
#define AdViewCocos2dxHello_AdScenesDemo_h

#include "cocos2d.h"


// for the subclass of CCLayer, each has to implement the static "create" method
#define LAYER_CREATE_FUNC(layer) \
static layer* create() \
{ \
layer *pRet = new layer(); \
if (pRet && pRet->init()) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}


class AdSceneDemo : public cocos2d::CCLayer
{
public:
    enum DemoType {
        DemoNone,
        DemoAdCenter,
        DemoAdBottom,
        DemoAdHidden
    };
public:
    AdSceneDemo():_grossini(NULL), mType(DemoNone){};
    virtual ~AdSceneDemo();
    bool init();
    
    static cocos2d::CCScene *scene(DemoType type);
    
    void handleMenu(CCObject*obj);
    
    virtual void handleMenuByTag(int tagId);
    
    virtual void onEnter() {
        CCLayer::onEnter();
    }
    
    virtual void onExit() {
        CCLayer::onExit();
    }
    
    virtual const char* title() {
        return "AdSceneDemo";
    }
    
    CC_SYNTHESIZE_READONLY(cocos2d::CCSprite*, _grossini, grossini);
    DemoType mType;
};

class AdCenterDemo : public AdSceneDemo
{
public:
    AdCenterDemo(){mType = DemoAdCenter;};
    
    LAYER_CREATE_FUNC(AdCenterDemo);
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual const char* title() {
        return "AdCenterDemo";
    }    
};

class AdBottomDemo : public AdSceneDemo
{
public:
    AdBottomDemo(){mType = DemoAdBottom;};
    LAYER_CREATE_FUNC(AdBottomDemo);
    virtual void onEnter();
    virtual void onExit();
    
    virtual const char* title() {
        return "AdBottomDemo";
    }    
};


class AdHiddenDemo : public AdSceneDemo
{
public:
    AdHiddenDemo(){mType = DemoAdHidden;};
    LAYER_CREATE_FUNC(AdHiddenDemo);
    virtual void onEnter();
    virtual void onExit();
    
    virtual const char* title() {
        return "AdHiddenDemo";
    }    
};

#endif
