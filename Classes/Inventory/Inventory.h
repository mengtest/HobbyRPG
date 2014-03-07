#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <map>

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
	const std::map< ItemEnum, int >& getItemList() { return m_masterItemList; }

	void outputInventory();

private:
	typedef std::map< ItemEnum, int > ItemListType;
	ItemListType m_masterItemList;
};

#endif