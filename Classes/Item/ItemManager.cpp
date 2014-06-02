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

const vector< string >& ItemManager::getItemValues( ItemEnum type )
{
	if ( (size_t)type.getValue() > m_data.size() || type.getValue() < 0 )
	{
		CCLOG("[ItemManager][getItemValues]: type '%d' invalid", type );
		return std::vector< std::string >();
	}

	return m_data[type.getValue()];
}

const string& ItemManager::getItemStat( ItemEnum type, ItemStatEnum stat )
{
	if ( (size_t)type.getValue() > m_data.size() || type.getValue() < 0 )
	{
		CCLOG("[ItemManager][getItemStat]: type '%d' invalid", type.getValue());
		return std::string();
	}

	if ( (size_t)stat.getValue() > m_data[type.getValue()].size() || stat.getValue() < 0 )
	{
		CCLOG("[ItemManager][getItemStat]: stat '%d' invalid", stat);
		return std::string();
	}

	return m_data[type.getValue()][stat.getValue()];
}
