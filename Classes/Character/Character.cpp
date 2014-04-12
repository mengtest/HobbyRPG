#include "cocos2d.h"

#include "Character.h"

#include "Common\Common.h"
#include "Item\ItemManager.h"

USING_NS_CC;
using namespace std;

Character::Character()
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

	//m_weapon = EMPTY;
	//m_armor = EMPTY;
	//m_ring = EMPTY;

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

	//Set current HP
	m_currentHP = this->getStat(HP);
}

int Character::getStat( StatsEnum type ) const
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

void Character::heal( int amount )
{
	CCLOG("[Character][heal]: %s healed for %i HP!", getInfo(ALIAS).c_str(), amount );
	m_currentHP += amount;
	regulateHP();
}

void Character::damage( int amount )
{
	CCLOG("[Character][damage]: %s takes '%d' damage!", getInfo(ALIAS).c_str(), amount );
	m_currentHP -= amount;
	regulateHP();
}

void Character::regulateHP()
{
	if ( m_currentHP < 0 )
	{
		m_currentHP = 0;
	}

	if ( m_currentHP > getStat(HP) )
	{
		m_currentHP = getStat(HP);
	}
}

bool Character::equipArmor(ItemEnum armor)
{
	if ( ItemManager::getInstance().getItemStat(armor, ARMOR_TYPE ).compare( getInfo(ARMOR)) <= 0 )
	{
		m_armor = armor;
		CCLOG("Equipping %s on %s success!", ItemManager::getInstance().getItemStat(armor, NAME).c_str(), getInfo(ALIAS).c_str());
		return true;
	}

	CCLOG("Equipping %s on %s fail! Can only equip %s type, tried to equip %s type", 
		ItemManager::getInstance().getItemStat(armor, NAME).c_str(), 
		getInfo(ALIAS).c_str(), 
		getInfo(WEAPON).c_str(),
		ItemManager::getInstance().getItemStat(armor, ARMOR_TYPE).c_str());
	return false;
}

bool Character::equipWeapon(ItemEnum weapon)
{
	if ( ItemManager::getInstance().getItemStat(weapon, WEAPON_TYPE ).compare( getInfo(WEAPON)) <= 0 )
	{
		m_weapon = weapon;
		CCLOG("Equipping %s on %s success!", ItemManager::getInstance().getItemStat(weapon, NAME).c_str(), getInfo(ALIAS).c_str());
		return true;
	}

	CCLOG("Equipping %s on %s fail! Can only equip %s type, tried to equip %s type", 
		ItemManager::getInstance().getItemStat(weapon, NAME).c_str(), 
		getInfo(ALIAS).c_str(), 
		getInfo(WEAPON).c_str(),
		ItemManager::getInstance().getItemStat(weapon, WEAPON_TYPE).c_str());
	return false;
}

bool Character::equipRing(ItemEnum ring)
{
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