#ifndef __TransitionScene_SCENE_H_
#define __TransitionScene_SCENE_H_

#include "cocos2d.h"

class cBaseUI;
class CustomActionManager;

/* This class exists because of various complications created by replacing a scene with the same scene. */

template < typename T >
class TransitionScene : public cocos2d::CCLayer
{
public:

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	void onEnter();
	void onExit();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
        
    // implement the "static node()" method manually
    CREATE_FUNC(TransitionScene);
	
};

#endif // __TransitionScene_SCENE_H_

#include "TransitionScene.cpp"