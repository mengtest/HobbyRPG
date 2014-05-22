#ifndef __OVERWORLD_CHARACTER_H__
#define __OVERWORLD_CHARACTER_H__

/****************************************************************
Dumb character with basic movement and facing methods.
*****************************************************************/
#include <string>

#include "cocos2d.h"
#include "OwEntityBase.h"
#include "..\..\Enum\DirectionEnum.h"

class OwController;
class OwCharacter : public OwEntityBase
{
public:
	OwCharacter(cocos2d::CCPoint position, 
				const std::string& name, 
				const std::string& spriteName = "chika", 
				const std::string& initialSpriteBaseName = "chika_front_2.png");
	~OwCharacter();

	inline bool isMoving() { return m_bIsMoving; }
	inline DirectionEnum getCurrentDir() { return m_currentDirection; }

	bool move(DirectionEnum type);
	bool face(DirectionEnum type);
	
	virtual void update(float dt);

	virtual void onAttach() {}
	virtual void onDetech() {}
protected:
	DirectionEnum m_currentDirection;

	bool checkTileMovable( cocos2d::CCPoint position);

	void updateMovement(float dt);
	bool stop(DirectionEnum type);
	void stopAnimations();

	cocos2d::CCActionInterval * m_action;

	// ˆÚ“®‚Ì‚½‚ß‚É
	bool m_bIsMoving;
	cocos2d::CCPoint m_startPoint;
	cocos2d::CCPoint m_endPoint;
	float m_moveTime;
	float m_moveDuration;

	
};

#endif //OVERWORLD_CHARACTER_H__