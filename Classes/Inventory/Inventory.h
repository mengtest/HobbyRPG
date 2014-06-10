#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <vector>

#include "..\Enum\ItemEnum.h"

class Inventory
{
public:
	
	struct ItemStorage
	{
		ItemEnum item;
		int stacks;
	};

	Inventory();
	~Inventory();

	bool addItem(ItemEnum item, int amount = 1);
	bool removeItem(ItemEnum item, int amount = 1);
	
	int getItemByIndex( int index ) { return m_masterItemList[index]; }
	int getInventorySize() { return m_masterItemList.size(); }

	void outputInventory();

private:
	typedef std::vector< int > ItemListType;
	ItemListType m_masterItemList;
};

#endif