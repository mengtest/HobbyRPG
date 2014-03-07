#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <map>

class Inventory;
class Party;
class Character;
class Player
{
public:
	static Player& getInstance();
	inline Inventory * getInventory() { return m_inventory; }
	inline Party * getParty() { return m_party; }
	inline Character * getCharacter(const char * name ) { return m_characterMap.find(name)->second; }

private:
	// Singleton Stuff
	Player();
	Player( const Player&  ) {};
	~Player();
	void operator=( const Player&  ) {};

	Inventory * m_inventory;
	Party * m_party;

	typedef std::map< std::string, Character * > CharacterMapType;
	CharacterMapType m_characterMap;

};

#endif 