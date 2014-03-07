#include <cocos2d.h>
#include "Party.h"


Party::Party()
{
	m_activeMembers.resize(MAX_MEMBERS, 0);
}

Party::~Party()
{
	m_activeMembers.clear();
}

bool Party::replaceMemberAtSlot(Character *  character, int slot)
{
	if ( slot < 0 || slot >= MAX_MEMBERS )
	{
		CCLOG("[Party][replaceMemberAtSlot]: Invalid slot value %d", slot );
		return false;
	}

	m_activeMembers[slot] = character;

	return true;
}

Character * Party::getCharacterAtSlot( int slot )
{
	if ( slot < 0 || slot >= MAX_MEMBERS )
	{
		CCLOG("[Party][replaceMemberAtSlot]: Invalid slot value %d", slot );
		return 0;
	}

	return m_activeMembers[slot];
}