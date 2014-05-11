#include "cocos2d.h"

USING_NS_CC;

template < typename T >
CCScene* TransitionScene<T>::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    TransitionScene *layer = TransitionScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
template < typename T >
bool TransitionScene<T>::init()
{
	if ( !CCLayer::init() )
    {
        return false;
    }

	  
    return true;
}

template < typename T >
void TransitionScene<T>::onEnter()
{
	CCLayer::onEnter();	
	CCDirector::sharedDirector()->replaceScene( OverworldScene::scene() );
}

template < typename T >
void TransitionScene<T>::onExit()
{
	CCLayer::onExit();
}
