#pragma once
#include "item.h"
#include <list>

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