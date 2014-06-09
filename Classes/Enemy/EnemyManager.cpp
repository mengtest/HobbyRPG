#include "cocos2d.h"

#include "EnemyManager.h"
#include "Common\Common.h"

USING_NS_CC;
using namespace std;

EnemyManager::EnemyManager()
{
	// load item stuff here?
	string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("data/enemies.csv");

	std::vector< std::string > temp;
	if ( !Common::openCSV(path, m_data ) )
	{
		CCLOG("[EnemyManager][constr] Load items failed!" );
	}

	m_enemyTypeMax = m_data.size();

}

EnemyManager::~EnemyManager()
{
	// delete all items?
}

EnemyManager& EnemyManager::getInstance()
{
	static EnemyManager instance;
	return instance;
}

const vector< string >& EnemyManager::getEnemyValues( int type )
{
	if ( (size_t)type > m_data.size() || type < 0 )
	{
		CCLOG("[EnemyManager][getItemValues]: type '%d' invalid", type );
		return std::vector< std::string >();
	}

	return m_data[type];
}

const string& EnemyManager::getEnemyStat( int type, int stat )
{
	if ( (size_t)type > m_data.size() || type < 0 )
	{
		CCLOG("[EnemyManager][getEnemyStat]: type '%d' invalid", type);
		return std::string();
	}

	if ( (size_t)stat > m_data[type].size() || stat < 0 )
	{
		CCLOG("[EnemyManager][getEnemyStat]: stat '%d' invalid", stat);
		return std::string();
	}

	return m_data[type][stat];
}
