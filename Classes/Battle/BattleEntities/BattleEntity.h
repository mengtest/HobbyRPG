#ifndef __BATTLE_ENTITY_H__
#define __BATTLE_ENTITY_H__

#include "cocos2d.h"

class BattleEntity
{
public:
	BattleEntity(cocos2d::CCPoint position, const std::string& spriteBaseName, const std::string& initialSpriteFrameName);
	
	virtual void update(float dt) = 0;
    
    void setPosition( cocos2d::CCPoint position );
    
	inline const std::string& getName() { return m_name; }
	inline cocos2d::CCPoint getPosition() { return m_sprite->getPosition(); }

protected:
    void setSprite(const std::string& spriteBaseName, const std::string& initialSpriteFrameName);

	cocos2d::CCSprite * m_sprite;
	std::string m_spriteBaseName;
	std::string m_name;
};

#endif 