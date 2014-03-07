#include "AppDelegate.h"

#include "CCDirector.h"
#include "script_support\CCScriptSupport.h"
#include "CCLuaEngine.h"
#include "LuaBinding\GameToLua.h"
#include "Config\Config.h"
#include "Common\Common.h"

#include "Overworld\OwManager\OwManager.h"
#include "Overworld\OverworldScene.h"


#include "World\WorldManager\WorldManager.h"
#include "World\WorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {
	OwManager::getInstance();
	WorldManager::getInstance();
}

AppDelegate::~AppDelegate() 
{
	OwManager::destroy();
	WorldManager::destroy();
}

bool AppDelegate::applicationDidFinishLaunching() {
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
    
	CCLuaStack *pStack = CCLuaEngine::defaultEngine()->getLuaStack();
    lua_State *tolua_s = pStack->getLuaState();
    
	tolua_GameToLua_open(tolua_s);
	tolua_StatsEnumToLua_open(tolua_s);

	// init assets //
	if ( Common::init() == 0 )
	{
		CCLog("Failed to init common");
		return false;
	}

	// create a scene. it's an autorelease object
    //CCScene *pScene = WorldScene::scene(0);
	CCScene *pScene = OverworldScene::scene("testmap", 10, 17);

    // run
	pDirector->setProjection(kCCDirectorProjection2D);
	//pDirector->setDepthTest(false);
    pDirector->runWithScene(pScene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
