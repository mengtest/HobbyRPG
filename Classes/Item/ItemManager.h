#ifndef __ITEM_MANAGER_H__
#define __ITEM_MANAGER_H__

#include <vector>

class ItemManager
{
public:
	static ItemManager& getInstance();

	const std::vector< std::string >& getItemValues( int type );
	const std::string& getItemStat( int type, int stat ); 

	inline int getItemTypeMax() { return m_itemTypeMax; }
protected:
	int m_itemTypeMax;
	std::vector< std::vector< std::string > > m_data;

	//singleton
	ItemManager();
	ItemManager( const ItemManager&  ) {};
	~ItemManager();
	void operator=( const ItemManager&  ) {};
	
};


#endif