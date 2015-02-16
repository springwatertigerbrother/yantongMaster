//
//  GameStartLayer.cpp
//  niweishenmezhemediao
//
//  Created by huge on 13/9/14.
//
//

#include "GameStartLayer.h"

bool GameStartLayer::init()
{
    if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 0)))
    {
        return false;
    }
    setTouchEnabled(true);
    //    setTouchEnabled(true);
    CCSize s = CCDirector::sharedDirector()->getWinSize();

//    CCMenuItemFont* pItem1 = CCMenuItemFont::create("remove ADS", this, menu_selector(GameStartLayer::ReMoveAdvertisement));
//    
//    CCMenu* pMenu = CCMenu::create(pItem1,NULL);
//    pMenu->alignItemsVerticallyWithPadding(20);
//    pItem1->setFontSize(80);
//    
//    pMenu->setPosition(ccp(s.width/2, s.height/2));
//    addChild(pMenu);
    CCSprite* pBg = CCSprite::create("images/titleBG.jpg");
    pBg->setPosition(CCPointMake(s.width/2, s.height/2));
    pBg->setOpacity(200);
    addChild(pBg);
    
    CCLabelBMFont* pGameoverLblBM = CCLabelBMFont::create("destroy\n pipestems", "fonts/boundsTestFont.fnt");

//    CCLabelTTF* pGameoverLbl = CCLabelTTF::create("destroy the pipestem", "ArialRoundedMTBold", 40,CCSizeMake(300, 200),kCCTextAlignmentCenter);
    CCSize contentSize = pBg->getContentSize();
    pGameoverLblBM->setPosition(ccp(contentSize.width/2,contentSize.height*0.5));
    pGameoverLblBM->setScale(1.5);
    pGameoverLblBM->setAlignment(kCCTextAlignmentCenter);
    
//    pGameoverLblBM->setHorizontalAlignment(kCCTextAlignmentCenter);
    pBg->addChild(pGameoverLblBM);
    
    CCMenuItemFont* pItem2 = CCMenuItemFont::create("start",this,menu_selector(GameStartLayer::StartGame));
    pItem2->setFontSize(180);
    CCMenu* pMenu2 = CCMenu::create(pItem2,NULL);
    pItem2->setPosition(ccp(s.width/2, s.height/5));
    pMenu2->setPosition(CCPointZero);
    addChild(pMenu2);
    

    return true;
}

void GameStartLayer::ReMoveAdvertisement()
{
    
}
void GameStartLayer::StartGame()
{
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    this->runAction(CCMoveTo::create(0.2, ccp(0,s.height)));
}
void GameStartLayer::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
}

bool GameStartLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLog("gamestartlayer");
    setTouchEnabled(false);
    return true;
}