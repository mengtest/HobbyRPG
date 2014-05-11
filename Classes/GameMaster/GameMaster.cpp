#include "GameMaster.h"
#include "CCDirector.h"
#include "script_support\CCScriptSupport.h"
#include "CCLuaEngine.h"
#include "LuaBinding\AllLua.h"
#include "Config\Config.h"
#include "Common\Common.h"

#include "Overworld\OwManager\OwManager.h"
#include "Overworld\OverworldScene.h"

#include "World\WorldManager\WorldManager.h"
#include "World\WorldScene.h"

GameMaster::GameMaster()
{
	OwManager::getInstance();
	WorldManager::getInstance();
}


GameMaster& GameMaster::getInstance()
{
	static GameMaster instance;
	return instance;
}

void GameMaster::destroy()
{
	OwManager::destroy();
	WorldManager::destroy();
}

bool GameMaster::startGame()
{
	// initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
   
	pDirector->setOpenGLView(pEGLView);
	pEGLView->setDesignResolutionSize(Config::getInstance().getDesignWidth(), Config::getInstance().getDesignHeight(), kResolutionShowAll);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
 
	// register lua engine
    CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);
    
	CCLuaStack *pStack = pEngine->getLuaStack();
    lua_State *tolua_s = pStack->getLuaState();	
	tolua_AllLua_open (tolua_s);	

	// init assets //
	if ( Common::init() == 0 )
	{
		CCLog("Failed to init common");
		return false;
	}

	// create a scene. it's an autorelease object
    //CCScene *pScene = WorldScene::scene(0);

	CCScene *pScene = OverworldScene::scene();

    // run
	pDirector->setProjection(kCCDirectorProjection2D);
	//pDirector->setDepthTest(false);
    pDirector->runWithScene(pScene);

	return true;
}
