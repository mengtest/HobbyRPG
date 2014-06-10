#include "BattleManager.h"
#include "..\BattleScene.h"
#include "..\BattleCharacter\BattleCharacter.h"

#include "..\..\GameMaster\GameMaster.h"
#include "..\..\Overworld\OverworldScene.h"
#include "..\..\Player\Player.h"
#include "..\..\Party\Party.h"
#include "..\..\Character\Character.h"

#include "CCLuaEngine.h"

USING_NS_CC;
using namespace std;
//USING_NS_CC_EXT;

BattleManager* BattleManager::instance = 0;

BattleManager::BattleManager()
	: m_isInit(false), 
	  m_scene(0)
{
}

BattleManager * BattleManager::getInstance()
{
	if ( !instance )
	{
		instance = new BattleManager();
	}

	return instance;

}

void BattleManager::destroy()
{
	//clean up here
	if ( instance->m_isInit )
	{
		instance->release();
	}

}

bool BattleManager::init(BattleScene * scene)
{
	if ( m_isInit )
	{
		CCLOG("[BattleManager][init]: Already Init, please call Release");
		return false;
	}

	m_scene = scene;
	m_isInit = true;

	//create sprites according to how many characters in party
	
	/*for ( int i = 0; i < Player::getInstance().getParty()->MAX_MEMBERS; ++i )
	{
		Character * character = Player::getInstance().getParty()->getCharacterAtSlot(i);
		if ( NULL == character )
		{
			CCLOG("[BattleManager][init]: character is null");
			continue;
		}

		addBattleCharacter(ccp(100, 100), character, LEFT);
	}*/

	CCLuaEngine::defaultEngine()->executeGlobalFunction("BattleInit");

	return true;
}


void BattleManager::release()
{
	if ( !m_isInit )
	{
		CCLOG("[BattleManager][release]: Already Released, please call Init");
		return;
	}

	m_isInit = false;
}

BattleCharacter * BattleManager::addBattleCharacter(CCPoint position, Character * character, DirectionEnum direction, std::string name)
{
	CCLOG("[BattleManager][addBattleCharacter]: adding '%s'", name);
	BattleCharacter * rtn	= new BattleCharacter(position, character, direction, name);
	m_scene->getGameLayer()->addChild(rtn->getSprite());
	m_characterList.insert(make_pair(name, rtn));

	return rtn;
}

void BattleManager::update(float dt)
{
}


bool BattleManager::processTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	gotoOverworld();
    return true;
}
  
void BattleManager::processTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
}

void BattleManager::processTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
}

 
void BattleManager::addChildToGameLayer( cocos2d::CCNode * obj )
{
    m_scene->getGameLayer()->addChild(obj);
}

void BattleManager::addChildToUILayer( cocos2d::CCNode * obj )
{
    m_scene->getUILayer()->addChild(obj); 
}

void BattleManager::removeChildFromGameLayer(cocos2d::CCNode * obj )
{
    m_scene->getGameLayer()->removeChild(obj);
}

void BattleManager::removeChildFromUILayer( cocos2d::CCNode * obj )
{
    m_scene->getUILayer()->removeChild(obj); 
}
    
void BattleManager::gotoOverworld()
{
	CCDirector::sharedDirector()->popScene();

}