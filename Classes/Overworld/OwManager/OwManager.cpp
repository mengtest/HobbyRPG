#include "OwManager.h"
#include "..\OwEntities\OwEntityBase.h"
#include "..\OwPlayerController\OwPlayerController.h"
#include "..\OwEntities\OwAICharacter.h"
#include "..\OwTiledMapUserData\OwTiledMapUserData.h"

#include "..\OwDialogUI\OwDialogUI.h"
#include "..\OwControlUI\OwControlUITypeB.h"
#include "..\OwAICommands\OwAIMove.h"
#include "..\..\Events\EventBase.h"

#include "..\..\World\WorldScene.h"

#include "..\..\Item\ItemManager.h"
#include "..\..\Inventory\Inventory.h"
#include "..\..\Enum\ItemEnum.h"

#include "..\..\Config\Config.h"

#include "..\..\Common\Common.h"

#include "..\..\AI\AIHeaders.h"

#include "CCLuaEngine.h"

#include "Player\Player.h"
#include "..\OverworldScene.h"
#include "..\..\Events\EventManager.h"
#include "..\..\Character\Character.h"


USING_NS_CC;
using namespace std;
USING_NS_CC_EXT;

OwManager* OwManager::instance = 0;

OwManager::OwManager()
	: m_isInit(false), 
	  m_scene(0),
	 m_tiledMap(0),
	 m_metaLayer(0),
	 m_objectGroup(0),
	 m_exitGroup(0),
	 m_tiledMapUserData(0),
	 m_controller(0),
	 m_npcCharacter(0),
	 m_character(0),
	 m_eventManager(0),
	 m_isPaused(false)
{
}

OwManager * OwManager::getInstance()
{
	if ( !instance )
	{
		instance = new OwManager();
	}

	return instance;

}

void OwManager::destroy()
{
	//clean up here
	if ( instance->m_isInit )
	{
		instance->release();
	}

}

static cocos2d::extension::CCControlSlider * slider;
bool OwManager::init(OverworldScene * scene, const string& tmxDir, int startX, int startY)
{
	if ( m_isInit )
	{
		CCLOG("[OwManager][init]: Already Init, please call Release");
		return false;
	}

	m_scene = scene;
	m_isInit = true;

	if ( !loadTileMap( tmxDir ) )
	{
		CCLOG("[OwManager][init]: loadTileMap() failed!");
		return false;
	}

	if ( !loadDialog() )
	{
		CCLOG("[OwManager][init]: loadDialog() failed!");
		return false;
	}

	if ( !loadPlayer(startX, startY) )
	{
		CCLOG("[OwManager][init]: loadPlayer() failed!");
		return false;
	}

	if ( !loadEntities() )
	{
		CCLOG("[OwManager][init]: loadEntities() failed!");
		return false;
	}

	if ( !loadFSM() )
	{
		CCLOG("[OwManager][init]: loadFSM() failed!");
		return false;
	}

	// load event manager
	m_eventManager = new EventManager();

	//作成のもの全部はシーンに増加する//
	m_scene->setViewPointCenter(m_character->getSprite()->getPosition());
	m_scene->getGameLayer()->runAction(CCFollow::create(m_character->getSprite(), cocos2d::CCRect(0.0f, 0.0f, 1000.0f, 1000.0f)));

	
	// test code
	Character * temp = new Character();
	temp->init("chika");

	// inventory test cases
	Inventory * inv = Player::getInstance().getInventory();
	inv->addItem(POTION);
	inv->addItem(PLAIN_WATER);
	inv->addItem(PLAIN_WATER);
	inv->addItem(PLAIN_WATER);
	inv->addItem(POTION);
	inv->addItem(POTION);
	inv->addItem(PLAIN_WATER);
	inv->addItem(SWORD);
	inv->addItem(PLAIN_WATER);
	inv->addItem(POTION);
	inv->addItem(POTION);
	inv->addItem(POTION);

	inv->addItem(POTION, 0);
	inv->addItem(PLAIN_WATER, 4);
	inv->addItem(SWORD); 
	inv->addItem(PLAIN_WATER);
	inv->addItem(PLAIN_WATER, 0);
	inv->addItem(PLAIN_WATER, 4);



	inv->outputInventory();
	
	//temp->equipArmor(PLAIN_WATER); //fail
	//temp->equipArmor(CHAINMAIL); //fail
	//temp->equipWeapon(SWORD); // succeed


	CCLuaEngine::defaultEngine()->executeGlobalFunction("createOverworldMenu");


	return true;
}

void OwManager::release()
{
	if ( !m_isInit )
	{
		CCLOG("[OwManager][release]: Already Released, please call Init");
		return;
	}

	m_isInit = false;

	CC_SAFE_DELETE( m_tiledMap );
	CC_SAFE_DELETE(m_tiledMapUserData );
	CC_SAFE_DELETE(m_controlUI);
	CC_SAFE_DELETE(m_dialog);
	CC_SAFE_DELETE(m_stateMachine);
	CC_SAFE_DELETE(m_eventManager);
	

	// delete AI list
	AIListType::iterator beg = m_aiList.begin();
	AIListType::iterator end = m_aiList.end();
	for ( ; beg != end; ++beg )
	{
		CC_SAFE_DELETE(beg->second);
	}
	m_aiList.clear();
}

void OwManager::update(float dt)
{
	m_stateMachine->OnUpdate(dt);	
}
 
bool OwManager::loadEntities()
{
	CCTMXObjectGroup * objectGroup = getTiledMap()->objectGroupNamed("Entity");
	if(objectGroup == NULL){
		CCLOG("tile map has no Entity layer");
		return false;
	}

	CCObject* it = NULL;
	CCARRAY_FOREACH(objectGroup->getObjects(), it)
	{
		CCDictionary * its = dynamic_cast<CCDictionary*>(it);
		CCString * name = (CCString*)its->objectForKey("name");
		if (name && name->m_sString == "npc") // it's an npc
        {
            // load npc logic
			// spawn points
			int x = ((CCString)*its->valueForKey("x")).intValue();
			int y = ((CCString)*its->valueForKey("y")).intValue();

			this->addAICharacter(ccp(x,y), 
								((CCString*)its->objectForKey("namae"))->m_sString, 
								((CCString*)its->objectForKey("sprite"))->m_sString,
								((CCString*)its->objectForKey("initial_sprite"))->m_sString ); // TODO: expose this to tmx?

        }
	}

	return true;
	
}

bool OwManager::processTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	m_controlUI->processTouchBegin(pTouch, pEvent);
	m_dialog->processTouchBegan();
    return true;
}
  
void OwManager::processTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

	m_controlUI->processTouchEnded(pTouch, pEvent);
}

void OwManager::processTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	m_controlUI->processTouchMoved(pTouch, pEvent);
}

OwAICharacter * OwManager::addAICharacter(CCPoint position, const string& name, const string& spritename, const string& initialSpriteName)
{
	CCLOG("[OwManager][addAICharacter]: adding '%s'", name.c_str());
	OwAICharacter * rtn	= new OwAICharacter(position, name, spritename, initialSpriteName, m_aiList.size());
	
	if ( rtn->loadLUA() )
	{
		m_scene->getGameLayer()->addChild(rtn->getSprite());
		m_aiList.insert(make_pair(name, rtn));

		// run the ai's init function
		CCLuaEngine::defaultEngine()->executeGlobalFunction( (name + "_init").c_str() );
		
		return rtn;
	}

	//something bad happened to loadLUA
	CC_SAFE_DELETE(rtn);
	return 0;
}

void OwManager::addEvent( EventBase * event )
{
	m_eventManager->addEvent(event);
}

void OwManager::callback( const string& msg, void * data )
{

}

OwAICharacter* OwManager::getAICharacterByName(const string& name)
{
	return m_aiList[name];
}

  
void OwManager::addChildToGameLayer( cocos2d::CCNode * obj )
{
    m_scene->getGameLayer()->addChild(obj);
}

void OwManager::addChildToUILayer( cocos2d::CCNode * obj )
{
    m_scene->getUILayer()->addChild(obj); 
}

void OwManager::removeChildFromGameLayer(cocos2d::CCNode * obj )
{
    m_scene->getGameLayer()->removeChild(obj);
}

void OwManager::removeChildFromUILayer( cocos2d::CCNode * obj )
{
    m_scene->getUILayer()->removeChild(obj); 
}
    
bool OwManager::loadTileMap(const string& tmxDir)
{
	// TileMapは作成します
	m_tiledMap = new CCTMXTiledMap();
    if ( !m_tiledMap->initWithTMXFile(tmxDir.c_str()) )
	{
		CCLOG("tile map '%s' failed to load", tmxDir.c_str());
		return false;
	}
 

	//Metaは見たくないです.
	m_metaLayer = m_tiledMap->layerNamed("Meta");
	m_tiledMap->layerNamed("Meta")->setVisible(Config::getInstance().isDebug()); 

	// Init user data map
	// ユーザーデーターを作成します
	m_tiledMapUserData = new OwTiledMapUserData();
	m_tiledMapUserData->init(m_tiledMap->getMapSize().width, m_tiledMap->getMapSize().height);

	m_objectGroup = getTiledMap()->objectGroupNamed("Objects");
	if(m_objectGroup == NULL){
		CCLOG("tile map has no Objects layer");
	}

	m_exitGroup = getTiledMap()->objectGroupNamed("Exits");
	if(m_exitGroup == NULL){
		CCLOG("tile map has no Exit layer");
	}

	m_scene->getGameLayer()->addChild(getTiledMap());
	return true;
}


bool OwManager::loadDialog()
{
	//dialog test//
	m_dialog = new OwDialogUI();
	if ( m_dialog->load("menu_background.png"))
	{
		m_scene->getUILayer()->addChild(m_dialog->getSprite());
		return true;
	}

	return false;
}

bool OwManager::loadPlayer(int x, int y)
{
	CCTMXObjectGroup * objectGroup = getTiledMap()->objectGroupNamed("Objects");
	CCDictionary *spawnPoint = objectGroup->objectNamed("player_spawn");
 
	//int tx = ((CCString)*spawnPoint->valueForKey("x")).intValue();
	//int ty = ((CCString)*spawnPoint->valueForKey("y")).intValue();

	x *= getTiledMap()->getTileSize().width;
	y = ( getTiledMap()->getMapSize().height -  y ) * getTiledMap()->getTileSize().height;
 	
	m_character = addAICharacter(ccp(x,y), "Player", "chika", "chika_front_2.png");
	if ( m_character == 0 )
	{
		return false;
	}

	m_controller = new OwPlayerController();
	m_controller->setCharacter(m_character);

	m_controlUI = new OwControlUITypeB(m_controller);
	
	if ( !m_controlUI->onInit() )
	{
		return false;
	}

	m_scene->getUILayer()->addChild(m_controlUI);

	return true;
}

bool OwManager::loadFSM()
{
	// State Machine //
	m_stateMachine = new cStateMachine<OwManager>(this);

	cStateTemplate<OwManager> * normalState;
	normalState = m_stateMachine->AddState(&OwManager::NORMAL_LOAD,
											&OwManager::NORMAL_INIT,
											&OwManager::NORMAL_UPDATE,
											&OwManager::NORMAL_FREE,
											&OwManager::NORMAL_UNLOAD );

	cStateTemplate<OwManager> * eventState;
	eventState = m_stateMachine->AddState( &OwManager::EVENT_LOAD,
											  &OwManager::EVENT_INIT,
											  &OwManager::EVENT_UPDATE,
											  &OwManager::EVENT_FREE,
											  &OwManager::EVENT_UNLOAD );

	cStateTemplate<OwManager> * pauseState;
	pauseState = m_stateMachine->AddState(    &OwManager::PAUSE_LOAD,
											  &OwManager::PAUSE_INIT,
											  &OwManager::PAUSE_UPDATE,
											  &OwManager::PAUSE_FREE,
											  &OwManager::PAUSE_UNLOAD );
	
	normalState->AddTriggerCheck( &OwManager::NORMAL_TO_EVENT, eventState);
	normalState->AddTriggerCheck( &OwManager::NORMAL_TO_PAUSE, pauseState);
	eventState->AddTriggerCheck( &OwManager::EVENT_TO_NORMAL, normalState);
	pauseState->AddTriggerCheck( &OwManager::PAUSE_TO_NORMAL, normalState);
	
	m_stateMachine->SetCurrentState(normalState);

	return true;
}

void OwManager::checkExit()
{
	CCTMXObjectGroup * exits = OwManager::getInstance()->getExitGroup();

	if ( exits == NULL ) {
		return;
	}

	CCObject * it = NULL;
	CCARRAY_FOREACH(exits->getObjects(), it )
	{
		CCDictionary * its = dynamic_cast<CCDictionary*>(it);
		CCRect exitRect = CCRectMake( its->valueForKey("x")->intValue(), 
									  its->valueForKey("y")->intValue(),
									  its->valueForKey("width")->intValue(),
									  its->valueForKey("height")->intValue() );
		if ( exitRect.containsPoint( this->m_character->getPosition() ) )
		{
			std::string destination = ((CCString*)its->objectForKey("destination"))->m_sString;
			CCLOG("[OwManager][doExitCheck]: Exiting to '%s'", destination.c_str());
			
			// do exit script
			CCLuaEngine::defaultEngine()->executeString(destination.c_str());
			return;
		}
	}

	// temp
	//CCDirector::sharedDirector()->replaceScene(WorldScene::scene() );
}

void OwManager::gotoWorld(int origin_node)
{
	CCLOG("[OwManager][gotoWorld] called at origin_node: %d", origin_node );
	CCDirector::sharedDirector()->replaceScene( WorldScene::scene(origin_node) );
}

void OwManager::gotoOverworld(const std::string& name, int x, int y)
{
	CCLOG("[OwManager][gotoOverworld] going to: %s at X: %d, Y: %d", name.c_str(), x, y );
	CCDirector::sharedDirector()->replaceScene( OverworldScene::scene(name, x, y) );
}

void OwManager::pause()
{
	m_isPaused = true;
}

void OwManager::unpause()
{
	m_isPaused = false;
}

void OwManager::resetMenuLUA()
{
	// nothing atm
}