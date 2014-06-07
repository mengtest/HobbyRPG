#include "cocos2d.h"

#include "ItemManager.h"
#include "Common\Common.h"

USING_NS_CC;
using namespace std;

ItemManager::ItemManager()
{
	// load item stuff here?
	string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("data/items.csv");

	std::vector< std::string > temp;
	if ( !Common::openCSV(path, m_data ) )
	{
		CCLOG("[ItemManager][constr] Load items failed!" );
	}

	m_itemTypeMax = m_data.size();

}

ItemManager::~ItemManager()
{
	// delete all items?
}

ItemManager& ItemManager::getInstance()
{
	static ItemManager instance;
	return instance;
}

const vector< string >& ItemManager::getItemValues( int type )
{
	if ( (size_t)type > m_data.size() || type < 0 )
	{
		CCLOG("[ItemManager][getItemValues]: type '%d' invalid", type );
		return std::vector< std::string >();
	}

	return m_data[type];
}

const string& ItemManager::getItemStat( int type, int stat )
{
	if ( (size_t)type > m_data.size() || type < 0 )
	{
		CCLOG("[ItemManager][getItemStat]: type '%d' invalid", type);
		return std::string();
	}

	if ( (size_t)stat > m_data[type].size() || stat < 0 )
	{
		CCLOG("[ItemManager][getItemStat]: stat '%d' invalid", stat);
		return std::string();
	}

	return m_data[type][stat];
}
