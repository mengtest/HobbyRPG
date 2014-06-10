#ifndef __ITEM_MANAGER_H__
#define __ITEM_MANAGER_H__

#include <vector>

#include "..\Enum\ItemEnum.h"
#include "..\Enum\ItemStatEnum.h"

class ItemManager
{
public:
	static ItemManager& getInstance();

	const std::vector< std::string >& getItemValues( ItemEnum type );
	const std::string& getItemStat( ItemEnum type, ItemStatEnum stat ); 
protected:
	
	std::vector< std::vector< std::string > > m_data;

	//singleton
	ItemManager();
	ItemManager( const ItemManager&  ) {};
	~ItemManager();
	void operator=( const ItemManager&  ) {};
	
};


#endif