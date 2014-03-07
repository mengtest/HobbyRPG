#include "Common\Common.h"
#include "Config\Config.h"


#include "WorldScene.h"
#include "WorldManager\WorldManager.h"

USING_NS_CC;


int WorldScene::m_originNode = 0;

CCScene* WorldScene::scene(int origin_node)
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    WorldScene *layer = WorldScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

	m_originNode = origin_node;

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool WorldScene::init()
{
	CCLOG("[WorldScene][init] World scene initialization" );
	if ( !CCLayer::init() )
    {
        return false;
    }

	WorldManager * mgr = WorldManager::getInstance();


	// Misc //
	this->setTouchEnabled(true);
	this->schedule(schedule_selector(WorldScene::update), 1.0/60.0);

	// create layers
	m_nodeLayer = CCLayer::create();
	if ( !m_nodeLayer->init() ) {
		return false;
	}

	m_backgroundLayer = CCLayer::create();
	if ( !m_backgroundLayer->init() ) {
		return false;
	}

	m_characterLayer = CCLayer::create();
	if ( !m_characterLayer->init() ) {
		return false;
	}

	m_uiLayer = CCLayer::create();
	if ( !m_uiLayer->init() ) {
		return false;
	}

	this->addChild(m_backgroundLayer);
	this->addChild(m_nodeLayer);
	this->addChild(m_characterLayer);
	this->addChild(m_uiLayer);

	mgr->init(this, "MainWorld", m_originNode);


    return true;
}

void WorldScene::update(float dt)
{	
	WorldManager::getInstance()->update(dt);
}

void WorldScene::onExit()
{
	this->removeAllChildren();
	WorldManager::getInstance()->release();
}

bool WorldScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	WorldManager::getInstance()->processTouchBegan(pTouch, pEvent);
    return true;
}
  
void WorldScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	WorldManager::getInstance()->processTouchEnded(pTouch, pEvent);
}

void WorldScene::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	WorldManager::getInstance()->processTouchMoved(pTouch, pEvent);
}

void WorldScene::registerWithTouchDispatcher() {
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}