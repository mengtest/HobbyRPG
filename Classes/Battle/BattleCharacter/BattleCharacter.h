#ifndef __OWENTITYBASE_H__
#define __OWENTITYBASE_H__

#include "cocos2d.h"

#include "..\..\Enum\DirectionEnum.h"


class Character;
class BattleCharacter
{
public:
	BattleCharacter(cocos2d::CCPoint position, Character * character, DirectionEnum direction);

	void setSprite(const std::string& spriteBaseName, const std::string& initialSpriteFrameName);
	void setPosition( cocos2d::CCPoint position );

	void update(float dt);

	inline const std::string& getName() { return m_name; }
	inline cocos2d::CCSprite * getSprite() { return m_sprite; }
	inline cocos2d::CCPoint getPosition() { return m_sprite->getPosition(); }

protected:
	cocos2d::CCSprite * m_sprite;
	std::string m_spriteName;
	std::string m_name;
};

#endif 