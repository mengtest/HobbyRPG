#include "EnemyManager.h"
#include "cocos2d.h"
#include "Common\Common.h"

USING_NS_CC;
using namespace std;

EnemyManager::EnemyManager()
{
	// load stats from csv
	string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("data/enemies.csv");
	string errorMsg ( path + " cannot be found!" );
	CCAssert( (CCFileUtils::sharedFileUtils()->isFileExist( path ) ) , errorMsg.c_str()  );
	if ( !Common::openCSV(path, m_data) )
	{
		CCLOG("[EnemyManager][constr]: EnemyManager cannot find 'data/enemies.csv'");
	}
}

const std::vector< std::string >& EnemyManager::getEnemyValues( EnemyEnum type )
{
	if ( (size_t)type.getValue() > m_data.size() || type.getValue() < 0 )
	{
		CCLOG("[EnemyManager][getEnemyValues]: type '%d' invalid", type );
		return std::vector< std::string >();
	}

	return m_data[type.getValue()];
}

const std::string& EnemyManager::getEnemyStat( EnemyEnum type, EnemyStatsEnum stat )
{
	if ( (size_t)type.getValue() > m_data.size() || type.getValue() < 0 )
	{
		CCLOG("[EnemyManager][getEnemyStat]: type '%d' invalid", type.getValue());
		return std::string();
	}

	if ( (size_t)stat.getValue() > m_data[type.getValue()].size() || stat.getValue() < 0 )
	{
		CCLOG("[EnemyManager][getEnemyStat]: stat '%d' invalid", stat);
		return std::string();
	}

	return m_data[type.getValue()][stat.getValue()];
}


EnemyManager& EnemyManager::getInstance()
{
	static EnemyManager instance;
	return instance;
}

