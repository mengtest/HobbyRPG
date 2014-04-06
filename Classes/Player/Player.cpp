#include "Inventory\Inventory.h"
#include "Character\Character.h"
#include "Player.h"
#include "Common\Common.h"
#include "cocos2d.h"
#include "Party\Party.h"

using namespace std;
USING_NS_CC;

Player::Player()
{
	m_inventory = new Inventory();
	m_party = new Party();

	vector< vector< string > > data;
	string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("data/character_names.csv");
	if ( !Common::openCSV(path, data) )
	{
		CCLOG("[Player][init]: Player failed to load character_names.csv");
		CCAssert(1, "[Player][init]: Player failed to load character_names.csv");
	}

	int size = data[0].size();
	for ( int i = 0; i < size; ++i )
	{
		Character * character = new Character();
		character->init(data[0][i]);
		m_characterMap.insert( make_pair(data[0][i], character) );
	} 

	// TODO: for now...
	m_party->replaceMemberAtSlot(m_characterMap.find("Chika")->second, 0);
	m_party->replaceMemberAtSlot(m_characterMap.find("Laksa")->second, 1);
	m_party->replaceMemberAtSlot(m_characterMap.find("Prata")->second, 2);
}

Player::~Player()
{
	delete m_inventory;
	delete m_party;

	CharacterMapType::iterator beg = m_characterMap.begin();
	CharacterMapType::iterator end = m_characterMap.end();

	for ( ; beg != end; ++beg )
	{
		delete beg->second;
	}

	m_characterMap.clear();
	
}

Player& Player::getInstance()
{
	static Player instance;
	return instance;
}