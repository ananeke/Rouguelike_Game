#ifndef BACKPACK_H
#define BACKPACK_H
#include <iostream>
#include <list>
//#include "item.h"

using namespace std;

class BackPack
{
	unsigned int capacity;
public:
	//list<Item> itemList;
	unsigned int getCapacity() { return capacity; }
	void setCapacity(unsigned int capacity) { this->capacity = capacity; }

};

#endif

