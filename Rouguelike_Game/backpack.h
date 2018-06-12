#pragma once

#include <list>
#include "item.h"

using namespace std;

class BackPack
{
public:
	list<Item> itemList;
	unsigned int capacity;

	void addItem();
	void removeItem(Item);
	void compareItems(Item);
	
	BackPack();
};

