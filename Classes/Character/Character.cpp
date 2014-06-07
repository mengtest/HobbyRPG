#include "cocos2d.h"

#include "Character.h"

#include "Common\Common.h"
#include "Item\ItemManager.h"

USING_NS_CC;
using namespace std;

Character::Character()
	:m_weapon(0), 
	m_armor(0), 
	m_ring(0),
	m_currentHP(1)
{
}

Character::~Character()
{
}

bool Character::init(const std::string& name)
{
	// load stats from csv
	string path = CCFileUtils::sharedFileUtils()->fullPathForFilename(("data/" + name + ".csv").c_str());
	string errorMsg ( path + " cannot be found!" );
	CCAssert( (CCFileUtils::sharedFileUtils()->isFileExist( path ) ) , errorMsg.c_str()  );
	if ( !Common::openCSV(path, m_data) )
	{
		CCLOG("[Character][init]: Character '%s' failed to load stats", name.c_str());
		return false;
	}

	path = CCFileUtils::sharedFileUtils()->fullPathForFilename(("data/" + name + "_info.csv").c_str());
	errorMsg = path + " cannot be found!" ;
	CCAssert( (CCFileUtils::sharedFileUtils()->isFileExist( path ) ) , errorMsg.c_str()  );
	if ( !Common::openCSV(path, m_info) )
	{
		CCLOG("[Character][init]: Character '%s' failed to load info", name.c_str());
		return false;
	}

	m_stats.resize(m_data[0].size());
	setLevel(1);

	m_weapon = 0;
	m_armor = 0;
	m_ring = 0;

	return true;
}

void Character::setLevel( int level )
{
	if ( (size_t)level >= m_data.size() || level <= 0 ) 
	{
		CCLOG("[Character][setLevel]: level '%d' invalid (max level %d)", level, m_data.size() );
		return;
	}

	int num_stats = m_data[0].size();
	for ( int i = 0; i < num_stats; ++i )
	{
		m_stats[i] = atoi(m_data[level][i].c_str());
	}
}

int Character::getStat( int type ) const
{
	if ( (size_t)type > m_stats.size() || type < 0 ) 
	{
		CCLOG("[Character][getStat]: type '%d' invalid", type );
		return 0.0f;
	}

	return m_stats[type];
}

const vector < int > & Character::getAllStats() const
{
	return m_stats;
}

bool Character::equipArmor(int armor)
{
	if ( armor < 0 || armor >= ItemManager::getInstance().getItemTypeMax() ) {
		return false;
	}
	m_armor = armor;
	return true;
}


bool Character::equipWeapon(int weapon)
{
	if ( weapon < 0 || weapon >= ItemManager::getInstance().getItemTypeMax() ) {
		return false;
	}
	m_weapon = weapon;
	return true;

}

bool Character::equipRing(int ring)
{
	if ( ring < 0 || ring >= ItemManager::getInstance().getItemTypeMax() ) {
		return false;
	}
	m_ring = ring;
	return false;

}

bool Character::unequipWeapon()
{
	//m_weapon = EMPTY;
	return true;
}

bool Character::unequipArmor()
{
	//m_armor = EMPTY;
	return false;

}

bool Character::unequipRing()
{
	//m_ring = EMPTY;
	return false;

}