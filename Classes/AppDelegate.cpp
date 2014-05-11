#include "AppDelegate.h"
#include "GameMaster\GameMaster.h"

USING_NS_CC;

AppDelegate::AppDelegate() {
	GameMaster::getInstance();
}

AppDelegate::~AppDelegate() 
{
	GameMaster::destroy();
}

bool AppDelegate::applicationDidFinishLaunching() {
    

	return GameMaster::getInstance().startGame();
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
