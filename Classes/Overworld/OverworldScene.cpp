#include <algorithm>
#include "Config\Config.h"
#include "OverworldScene.h"

#include "Common\Common.h"
#include "CustomActionManager\CustomActionManager.h"
#include "OwManager\OwManager.h"
#include "UI/cInGameUI.h"


USING_NS_CC;


std::string OverworldScene::m_mapName = "";
int OverworldScene::m_startX = 0;
int OverworldScene::m_startY = 0;

CCScene* OverworldScene::scene(std::string mapFilename, int x, int y)
{
	m_mapName = mapFilename;
	m_startX = x;
	m_startY = y;

    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    OverworldScene *layer = OverworldScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool OverworldScene::init()
{
	if ( !CCLayer::init() )
    {
        return false;
    }

	

    return true;
}

void OverworldScene::onEnter()
{
	CCLayer::onEnter();
	OwManager * mgr = OwManager::getInstance();
	if ( !mgr ) {
		CCLOG("[OverworldScene][onEnter][error]: mgr is null!");
		return;
	}
  
	// Misc //
	this->setTouchEnabled(true);
	this->schedule(schedule_selector(OverworldScene::update), 1.0/60.0);

	// Init Layers //
	m_gameLayer = CCLayer::create();
	if ( !m_gameLayer->init() ) {
		CCLOG("[OverworldScene][onEnter][error]: m_gameLayer failed to init!");
		return;
	}

	m_uiLayer = CCLayer::create();
	if ( !m_uiLayer->init() ) {
		CCLOG("[OverworldScene][onEnter][error]: m_uiLayer failed to init!");
		return;
	}

	m_customActionManager = new CustomActionManager();
	m_gameLayer->setActionManager(m_customActionManager);

	this->addChild(m_gameLayer);
	this->addChild(m_uiLayer);

	// Init Manager //
	mgr->init(this, "maps//" + m_mapName + ".tmx", m_startX, m_startY);

	//ui = new cInGameUI();
	//ui->init(this);
	//m_uiLayer->addChild(ui);


}

void OverworldScene::onExit()
{
	CCLayer::onExit();
	this->removeAllChildren();
	
	OwManager * mgr = OwManager::getInstance();
	if ( !mgr ) {
		CCLOG("[OverworldScene][onExit][error]: mgr is null!");
		return;
	}
	mgr->release();
}


void OverworldScene::registerWithTouchDispatcher() {
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}
 
bool OverworldScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	bool ret = false;
	if ( m_uiLayer ) {
		ret = m_uiLayer->ccTouchBegan(pTouch, pEvent);
	} else {
		CCLOG("[OverworldScene][ccTouchBegan][error]: m_uiLayer is null!");
	}

	OwManager * mgr = OwManager::getInstance();
	if ( mgr ) {
		ret = mgr->processTouchBegan(pTouch, pEvent);
	} else {
		CCLOG("[OverworldScene][ccTouchBegan][error]: mgr is null!");
	}

    return ret;
}
  
void OverworldScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	OwManager * mgr = OwManager::getInstance();
	if ( mgr ) {
		mgr->processTouchEnded(pTouch, pEvent);
	} else {
		CCLOG("[OverworldScene][ccTouchEnded][error]: mgr is null!");
	}


}

void OverworldScene::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	OwManager * mgr = OwManager::getInstance();
	if ( mgr ) {
		mgr->processTouchMoved(pTouch, pEvent);
	} else {
		CCLOG("[OverworldScene][ccTouchMoved][error]: mgr is null!");
	}
}

void OverworldScene::setViewPointCenter(CCPoint position)
{
	OwManager * mgr = OwManager::getInstance();
	if ( !mgr ) {
		CCLOG("[OverworldScene][setViewPointCenter][error]: mgr is null!");
		return;
	}

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
 
	int x1 = MAX(position.x, winSize.width/2);
    int y1 = MAX(position.y, winSize.height/2);
	x1 = MIN(x1, (mgr->getTiledMap()->getMapSize().width * mgr->getTiledMap()->getTileSize().width) - winSize.width / 2);
    y1 = MIN(y1, (mgr->getTiledMap()->getMapSize().height * mgr->getTiledMap()->getTileSize().height) - winSize.height/2);
    CCPoint actualPosition = ccp(x1, y1);
 
    CCPoint centerOfView = ccp(winSize.width/2, winSize.height/2);
    CCPoint viewPoint = ccpSub(centerOfView, actualPosition);

	if ( !m_gameLayer ) {
		CCLOG("[OverworldScene][setViewPointCenter][error]: m_gameLayer is null!");
		return;
	}
    m_gameLayer->setPosition(viewPoint);
	
}

void OverworldScene::ResetUI()
{
	/*if(ui)
	{
		m_uiLayer->removeChild(ui);
		delete ui;
		ui = new cInGameUI();
		ui->init(this);
		m_uiLayer->addChild(ui);

	}*/
}

void OverworldScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}



void OverworldScene::update(float dt)
{	
	OwManager::getInstance()->update(dt);
	m_customActionManager->stepUpdate(dt);

}
