#include "backpack.h"
#include <iostream>
#include <algorithm>

using namespace std;

BackPack::BackPack() {
	capacity = 6;
}

void BackPack::addItem() {

	Item* item = new Item();
	if (capacity < 6) {
		itemList.push_back(*item);
		capacity += 1;
	}
	else
		cout << "You don't have space in Backpack!" << endl;
}
void BackPack::removeItem(Item item) {
	if (capacity < 0)
		cout << "You don't have anything in Backpack!" << endl;
	else {
		itemList.remove(item);
		capacity -= 1;
	}
}
void BackPack::compareItems(Item item) {
	auto findItem = find(itemList.begin(), itemList.end(), item);
}
