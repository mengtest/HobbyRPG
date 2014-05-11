#ifndef __OWPLAYERCONTROLLER_H__
#define __OWPLAYERCONTROLLER_H__

#include "cocos2d.h"
#include "../../Enum/DirectionEnum.h"

// Contains actions players can do to a character
class OwCharacter;
class OwPlayerController : public cocos2d::CCObject
{
public:
	OwPlayerController() : m_bDisabled(false), m_bStartMoving(false), m_bCheckBattle(false), m_bCheckExit(false) {}
	~OwPlayerController() {}

	inline OwCharacter * getCharacter() { return m_character; }
	inline void setCharacter( OwCharacter * character ) { m_character = character; }

	void update( float dt );
	
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void interact();

	inline void setDisabled( bool disabled ) { m_bDisabled = disabled; }

	// to be removed
	/*
	void processTouchBegin(cocos2d::CCLayer * layer, cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchEnded(cocos2d::CCLayer * layer, cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	void processTouchMoved(cocos2d::CCLayer * layer, cocos2d::CCTouch *touch, cocos2d::CCEvent *event);//*/

private:
	void move( DirectionEnum type );
	void doExitCheck();
	void doBattleCheck();
	void updateMovement(float dt);
	cocos2d::CCPoint m_movingDirection;

	bool m_bDisabled;
	bool m_bStartMoving;
	bool m_bCheckExit;
	bool m_bCheckBattle;
	OwCharacter * m_character;
};

#endif