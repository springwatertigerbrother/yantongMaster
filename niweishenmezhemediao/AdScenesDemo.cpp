//
//  AdScenesDemo.cpp
//  AdViewCocos2dxHello
//
//  Created by the user on 12-8-20.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "AdScenesDemo.h"
#include "AdViewToolX.h"

using namespace cocos2d;

AdSceneDemo::~AdSceneDemo() {
/*	if (_grossini)              //should not release, because the layer data(array) will release.
	{
		_grossini->release();
		_grossini = NULL;
	}*/  
}

CCScene *AdSceneDemo::scene(DemoType type) {
	CCScene *s = CCScene::create();
    
    switch (type) {
        case AdSceneDemo::DemoNone:
            s->addChild(AdSceneDemo::create());
            break;
        case AdSceneDemo::DemoAdCenter:
            s->addChild(AdCenterDemo::create());
            break;
        case AdSceneDemo::DemoAdBottom:
            s->addChild(AdBottomDemo::create());
            break;
        case AdSceneDemo::DemoAdHidden:
            s->addChild(AdHiddenDemo::create());
            break;
    }
    
    return s;
}

void AdSceneDemo::handleMenuByTag(int tagId) {
    switch(tagId) {
        case 1:
            CCDirector::sharedDirector()->popScene();
            break;
        case 2:
            CCDirector::sharedDirector()->replaceScene(AdSceneDemo::scene(mType));
            break;
    }
}

void AdSceneDemo::handleMenu(CCObject* obj)
{
    CCMenuItemLabel *menu = dynamic_cast<CCMenuItemLabel*>(obj);
    
    if (NULL != menu) {
        this->handleMenuByTag(menu->getTag());
    }
}

bool AdSceneDemo::init() {
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    
    CCLabelTTF *label = CCLabelTTF::create(title(), "Marker Felt", 32);
    addChild(label, 0);
    label->setColor(ccc3(0,0,255));
    label->setPosition(ccp( s.width/2, s.height/2 + 80));    
    
    _grossini = CCSprite::create("blocks.png");
	_grossini->setPosition( ccp(s.width/2, s.height/2) );
    this->addChild(_grossini);
    
    CCLabelTTF *label1 = CCLabelTTF::create("Back", "Marker Felt", 24);
	CCMenuItemLabel *backItem = CCMenuItemLabel::create((CCNode*)label1, this, menu_selector(AdSceneDemo::handleMenu));
    backItem->setPosition(ccp(80, s.height - 20));
    
    CCLabelTTF *label2 = CCLabelTTF::create("Restart", "Marker Felt", 24);
	CCMenuItemLabel *restartItem = CCMenuItemLabel::create((CCNode*)label2, this, menu_selector(AdSceneDemo::handleMenu));
    restartItem->setPosition(ccp(s.width - 80, s.height - 20));
    
    backItem->setTag(1);
    restartItem->setTag(2);
    
    // Create a menu with the "close" menu item, it's an auto release object.
    CCMenu* pMenu = CCMenu::create(backItem, restartItem, NULL);
    pMenu->setPosition(CCPointZero);    
    this->addChild(pMenu, 1);
    
    return true;
}

void AdCenterDemo::onExit() {
    //things.
    
    AdSceneDemo::onExit();    
}

void AdCenterDemo::onEnter() {
    AdSceneDemo::onEnter();
    
    //things.
    AdViewToolX::setAdPosition(AdViewToolX::AD_POS_CENTER, AdViewToolX::AD_POS_CENTER);
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();
	ccBezierConfig bezier;
	bezier.controlPoint_1 = ccp(0, s.height/2);
	bezier.controlPoint_2 = ccp(200, -s.height/2);
	bezier.endPosition = ccp(200,100);
    
	CCBezierBy *bezierForward = CCBezierBy::create(3, bezier);
	CCActionInterval *bezierBack = bezierForward->reverse();
	CCSequence *seq = CCSequence::create(bezierForward, bezierBack);
	CCRepeatForever* rep1 = CCRepeatForever::create(seq);
    
    _grossini->runAction(rep1);
}

void AdBottomDemo::onExit() {
    //things.
    
    AdSceneDemo::onExit();    
}

void AdBottomDemo::onEnter() {
    AdSceneDemo::onEnter();
    
    //things.
    AdViewToolX::setAdPosition(AdViewToolX::AD_POS_CENTER, AdViewToolX::AD_POS_BOTTOM);
//    
//	CCRotateTo* act1 = CCRotateTo::create(1, 90);//[CCRotateTo actionWithDuration:1 angle:90];
//	CCRotateTo* act2 = CCRotateTo::create(1, 0);//[CCRotateTo actionWithDuration:1 angle:0];
//	CCSequence* seq = CCSequence::create(act1, act2);//[CCSequence actions:act1, act2, nil];
//	CCRepeatForever* rep1 = CCRepeatForever::create(seq);//[CCRepeatForever actionWithAction:seq];
//    
//    _grossini->runAction(rep1);
}

void AdHiddenDemo::onExit() {
    //things.
    AdViewToolX::setAdHidden(false);
    
    AdSceneDemo::onExit();    
}

void AdHiddenDemo::onEnter() {
    AdSceneDemo::onEnter();
    
    //things.
    AdViewToolX::setAdHidden(true);
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    _grossini->setPosition(ccp(40.0f, s.height/3));
    
	CCSequence *action = CCSequence::create(CCMoveBy::create(2, ccp(400,0)),
                                   CCRotateBy::create(4, 1080));
    
    _grossini->runAction(action);
}