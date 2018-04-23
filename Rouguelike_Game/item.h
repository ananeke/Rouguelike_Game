#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <ctime>

using namespace std;

array<string, 6> thing{ "Sword","Armor","Boots","Ring","Shield","Gloves" };
array<string, 3> good_prefix{ "Good","Magic","Legendary" };
array<string, 3> bad_prefix{ "Bad","Broken","Cursed" };

class Item
{
	string name;

public:
	Item()
	{
		//randomowe wybieranie nagrody
		int index = rand() % 6;
		this->name = thing[index];
	}
};

class Precious : public Item
{
	string name_good_prefix;

public:
	Precious()
	{
		srand(time(NULL));
		int index = rand() % 3;
		this->name_good_prefix = good_prefix[index];
		std::cout << name_good_prefix << std::endl;
	}
};

class Room
{
	bool room_open = true;
	bool road_open = false;

};


/*int main(int argc, char const *argv[]) {

Precious S;
//S.Print();

for(const auto &v: thing)
std::cout << v << " ";
std::cout << std::endl;
return 0;
}*/
#endif

