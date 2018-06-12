#pragma once
#include "itemtype.h"
#include <string>

using namespace std;

class Item
{
public:
	string type;
	string goodPrefix;
	string badPrefix;
	string fullName;

	int toStrength;
	int toLife;

	Item();
	bool operator == (const Item& i) const { return fullName == i.fullName; }
	bool operator != (const Item& i) const { return !operator == (i);  }
};
