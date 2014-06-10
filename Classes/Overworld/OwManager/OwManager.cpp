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
#include "..\..\Battle\BattleScene.h"

#include "CCLuaEngine.h"

#include "..\..\Player\Player.h"
#include "..\OverworldScene.h"
#include "..\..\Events\EventManager.h"
#include "..\..\Character\Character.h"
#include "..\..\GameMaster\GameMaster.h"
#include "..\..\Transition\TransitionScene.h"


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
	 m_isPaused(false),
	 m_dialog(0),
	 m_stateMachine(0)
{
	m_overworldData.mapName = "testmap";
	m_overworldData.x = 10;
	m_overworldData.y = 17;
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

bool OwManager::init(OverworldScene * scene)
{
	if ( m_isInit )
	{
		CCLOG("[OwManager][init]: Already Init, please call Release");
		return false;
	}

	m_scene = scene;
	m_isInit = true;

	

	if ( !loadTileMap( m_overworldData.mapName ) )
	{
		CCLOG("[OwManager][init][error]: loadTileMap() failed!");
		return false;
	}

	if ( !loadDialog() )
	{
		CCLOG("[OwManager][init][error]: loadDialog() failed!");
		return false;
	}

	if ( !loadPlayer(m_overworldData.x, m_overworldData.y) )
	{
		CCLOG("[OwManager][init][error]: loadPlayer() failed!");
		return false;
	}

	if ( !loadEntities() )
	{
		CCLOG("[OwManager][init][error]: loadEntities() failed!");
		return false;
	}

	if ( !loadFSM() )
	{
		CCLOG("[OwManager][init][error]: loadFSM() failed!");
		return false;
	}

	// load event manager
	m_eventManager = new EventManager();

	//作成のもの全部はシーンに増加する//
	m_scene->setViewPointCenter(m_character->getSprite()->getPosition());
	m_scene->getGameLayer()->runAction(CCFollow::create(m_character->getSprite(), cocos2d::CCRect(0.0f, 0.0f, 1000.0f, 1000.0f)));

	

	// inventory test cases
	Inventory * inv = Player::getInstance().getInventory();
	inv->addItem(ItemEnum::CHILI);
	inv->addItem(ItemEnum::PLAIN_WATER);
	inv->addItem(ItemEnum::PLAIN_WATER);
	inv->addItem(ItemEnum::PLAIN_WATER);
	inv->addItem(ItemEnum::CHILI);
	inv->addItem(ItemEnum::CHILI);
	inv->addItem(ItemEnum::PLAIN_WATER);
	inv->addItem(ItemEnum::SWORD);
	inv->addItem(ItemEnum::PLAIN_WATER);
	inv->addItem(ItemEnum::CHILI);
	inv->addItem(ItemEnum::CHILI);
	inv->addItem(ItemEnum::CHILI);

	inv->addItem(ItemEnum::PLAIN_WATER, 4);
	inv->addItem(ItemEnum::SWORD); 
	inv->addItem(ItemEnum::PLAIN_WATER, 4);



	inv->outputInventory();
	//*/
	
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

	CC_SAFE_DELETE(m_tiledMap);
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
	if ( m_stateMachine ) {
		m_stateMachine->OnUpdate(dt);	
	}
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
		if ( its ) 
		{
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
	}

	return true;
	
}

// TODO: NEEDS TO MOVE TO STATES?
bool OwManager::processTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	if ( !m_controlUI )	{
		CCLOG("[OwManager][processTouchBegan][error]: m_controlUI is null");
		return false;
	}

	if ( !m_dialog )	{
		CCLOG("[OwManager][processTouchBegan][error]: m_dialog is null");
		return false;
	}

	m_controlUI->processTouchBegin(pTouch, pEvent);
	m_dialog->processTouchBegan();
    return true;
}
  
// TODO: NEEDS TO MOVE TO STATES?
void OwManager::processTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if ( !m_controlUI )	{
		CCLOG("[OwManager][processTouchEnded][error]: m_controlUI is null");
		return;
	}
	m_controlUI->processTouchEnded(pTouch, pEvent);
}

// TODO: NEEDS TO MOVE TO STATES?
void OwManager::processTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if ( !m_controlUI )	{
		CCLOG("[OwManager][processTouchMoved][error]: m_controlUI is null");
		return;
	}
	m_controlUI->processTouchMoved(pTouch, pEvent);
}

OwAICharacter * OwManager::addAICharacter(CCPoint position, const string& name, const string& spritename, const string& initialSpriteName)
{
	CCLOG("[OwManager][addAICharacter]: adding '%s'", name.c_str());
	OwAICharacter * rtn	= new OwAICharacter(position, name, spritename, initialSpriteName);
	
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
	if ( !m_eventManager )
	{
		CCLOG("[OwManager][addEvent][error]: m_eventManager is null");
		return;
	}

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
	if ( !m_scene ) { 
		CCLOG("[OwManager][addChildToGameLayer][error]: m_scene is null");
		return;
	}

	CCLayer * gameLayer = m_scene->getGameLayer();
	if ( !gameLayer ) { 
		CCLOG("[OwManager][addChildToGameLayer][error]: gameLayer is null");
		return;
	}
   gameLayer->addChild(obj);
}

void OwManager::addChildToUILayer( cocos2d::CCNode * obj )
{
	if ( !m_scene ) { 
		CCLOG("[OwManager][addChildToUILayer][error]: m_scene is null");
		return;
	}
	CCLayer * uiLayer = m_scene->getUILayer();
	if ( !uiLayer ) { 
		CCLOG("[OwManager][addChildToUILayer][error]: uiLayer is null");
		return;
	}
   uiLayer->addChild(obj);
}

void OwManager::removeChildFromGameLayer(cocos2d::CCNode * obj )
{
	if ( !m_scene ) { 
		CCLOG("[OwManager][removeChildFromGameLayer][error]: m_scene is null");
		return;
	}
    CCLayer * gameLayer = m_scene->getGameLayer();
	if ( !gameLayer ) { 
		CCLOG("[OwManager][removeChildFromGameLayer][error]: gameLayer is null");
		return;
	}
	gameLayer->removeChild(obj);
}

void OwManager::removeChildFromUILayer( cocos2d::CCNode * obj )
{
	if ( !m_scene ) { 
		CCLOG("[OwManager][removeChildFromUILayer][error]: m_scene is null");
		return;
	}

   CCLayer * uiLayer = m_scene->getUILayer();
	if ( !uiLayer ) { 
		CCLOG("[OwManager][removeChildFromUILayer][error]: uiLayer is null");
		return;
	}
   uiLayer->removeChild(obj);
}
    
bool OwManager::loadTileMap(const string& tmxDir)
{
	// TileMapは作成します
	m_tiledMap = new CCTMXTiledMap();
    if ( !m_tiledMap->initWithTMXFile( ("maps//" + tmxDir + ".tmx").c_str() ))
	{
		CCLOG("tile map '%s' failed to load", tmxDir.c_str());
		return false;
	}
 

	//Metaは見たくないです.
	m_metaLayer = m_tiledMap->layerNamed("Meta");
	if ( !m_metaLayer ) 	{
		CCLOG("[OwManager][loadTileMap][error]: m_metaLayer is null");
		return false;
	}
	m_metaLayer->setVisible(Config::getInstance().isDebug()); 

	// Init user data map
	// ユーザーデーターを作成します
	m_tiledMapUserData = new OwTiledMapUserData();
	m_tiledMapUserData->init(m_tiledMap->getMapSize().width, m_tiledMap->getMapSize().height);

	m_objectGroup = getTiledMap()->objectGroupNamed("Objects");
	if(m_objectGroup == NULL){
		CCLOG("[OwManager][loadTileMap][error]: tile map has no Objects layer");
		return false;
	}

	m_exitGroup = getTiledMap()->objectGroupNamed("Exits");
	if(m_exitGroup == NULL){
		CCLOG("[OwManager][loadTileMap][error]: tile map has no Exit layer");
		return false;
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
	if ( !m_scene ) { 
		CCLOG("[OwManager][loadPlayer][error]: m_scene is null");
		return false;
	}

	if ( !m_scene->getUILayer() ) { 
		CCLOG("[OwManager][loadPlayer][error]: m_scene->getUILayer() is null");
		return false;
	}

	CCTMXObjectGroup * objectGroup = getTiledMap()->objectGroupNamed("Objects");
	CCDictionary *spawnPoint = objectGroup->objectNamed("player_spawn");

	if ( !objectGroup ) {
		CCLOG("[OwManager][loadPlayer][error]: objectGroup is null");
		return false;
	}

	if ( !spawnPoint ) {
		CCLOG("[OwManager][loadPlayer][error]: spawnPoint is null");
		return false;
	}
 
	//int tx = ((CCString)*spawnPoint->valueForKey("x")).intValue();
	//int ty = ((CCString)*spawnPoint->valueForKey("y")).intValue();

	x *= getTiledMap()->getTileSize().width;
	y = ( getTiledMap()->getMapSize().height -  y ) * getTiledMap()->getTileSize().height;
 	
    // get topmost player
    Character * topCharacter = Party::getInstance().getCharacterAtSlot(0);
   
    
	m_character = addAICharacter(ccp(x,y), 
                                "Player",  
                                topCharacter->getInfo(CharacterInfoEnum::BASE_SPRITE), 
                                topCharacter->getInfo(CharacterInfoEnum::INITIAL_SPRITE));
    
	if ( m_character == 0 )
	{
		CCLOG("[OwManager][loadPlayer][error]: m_character is null");
		return false;
	}

	m_controller = new OwPlayerController();
	m_controller->setCharacter(m_character);

	m_controlUI = new OwControlUITypeB(m_controller);
	
	if ( !m_controlUI->onInit() ) {
		CCLOG("[OwManager][loadPlayer][error]: m_controlUI failed to init");
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
		CCLOG("[OwManager][checkExit][error]: exits is null");
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

void OwManager::tickBattle()
{
	CCLOG("[OwManager][tickBattle] ticking battle" );
    srand(time(NULL));
    int chance = rand() % 100;
    if ( chance < Config::getInstance().getEncounterRate() ) {    
        gotoBattle();
    }
}


// TODO: should shift all these goto functions to GameMaster
void OwManager::gotoWorld(int origin_node)
{
	CCLOG("[OwManager][gotoWorld] called at origin_node: %d", origin_node );
	CCDirector::sharedDirector()->replaceScene( WorldScene::scene(origin_node) );
}

void OwManager::gotoOverworld(const std::string& name, int x, int y)
{
	CCLOG("[OwManager][gotoOverworld] going to: %s at X: %d, Y: %d", name.c_str(), x, y );

	OverworldData data;
	data.mapName = name;
	data.x = x;
	data.y = y;

	setOverworldData(data);
	//wait for transition class
	CCDirector::sharedDirector()->replaceScene( TransitionScene< OverworldScene >::scene() );
}

void OwManager::gotoBattle()
{
	CCLOG("[OwManager][gotoBattle] going to Battle!");

	//GameMaster::getInstance().setCurrentOverworldScene(m_scene);
	CCDirector::sharedDirector()->pushScene( BattleScene::scene() );
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