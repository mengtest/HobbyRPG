#ifndef __PARTY_H__
#define __PARTY_H__

#include <vector>

class Character;
class Party
{
public:
	Party();
	~Party();

	bool replaceMemberAtSlot( Character *  character, int slot);
	Character * getCharacterAtSlot( int slot );

	const static int MAX_MEMBERS = 3;

private:
	std::vector<Character*> m_activeMembers;

	
};

#endif