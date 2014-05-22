#include <algorithm>
#include "Config\Config.h"
#include "Common\Common.h"
#include "CustomActionManager\CustomActionManager.h"
#include "BattleManager\BattleManager.h"
#include "BattleScene.h"
#include "..\GameMaster\GameMaster.h"

USING_NS_CC;

CCScene* BattleScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    BattleScene *layer = BattleScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool BattleScene::init()
{
	if ( !CCLayer::init() )
    {
        return false;
    }

    return true;
}

void BattleScene::onEnter()
{
	CCLayer::onEnter();
	BattleManager * mgr = BattleManager::getInstance(); 
	// Misc //
	this->setTouchEnabled(true);
	this->schedule(schedule_selector(BattleScene::update), 1.0/60.0);

	// Init Layers //
	m_gameLayer = CCLayer::create();
	if ( !m_gameLayer->init() ) {
		return;
	}

	m_uiLayer = CCLayer::create();
	if ( !m_uiLayer->init() ) {
		return;
	}

	m_customActionManager = new CustomActionManager();
	m_gameLayer->setActionManager(m_customActionManager);

	this->addChild(m_gameLayer);
	this->addChild(m_uiLayer);

	// Init Manager //
	mgr->init(this);

	//ui = new cInGameUI();
	//ui->init(this);
	//m_uiLayer->addChild(ui);


}

void BattleScene::onExit()
{
	CCLayer::onExit();
	this->removeAllChildren();
	BattleManager::getInstance()->release();
}


void BattleScene::registerWithTouchDispatcher() {
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}
 
bool BattleScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	m_uiLayer->ccTouchBegan(pTouch, pEvent);
	BattleManager::getInstance()->processTouchBegan(pTouch, pEvent);
    return true;
}
  
void BattleScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	BattleManager::getInstance()->processTouchEnded(pTouch, pEvent);

}

void BattleScene::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	BattleManager::getInstance()->processTouchMoved(pTouch, pEvent);
}


void BattleScene::update(float dt)
{	
	BattleManager::getInstance()->update(dt);
	m_customActionManager->stepUpdate(dt);

}

