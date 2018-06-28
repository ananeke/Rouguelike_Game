#include "item.h"
#include "randomizer.h"

Item::Item()
{ 
	this->type = itemtype::type[Randomizer::getRandomNumber(0, 5)];

	if (Randomizer::getRandomNumber(0, 1))
		this->goodPrefix = itemtype::goodPrefix[Randomizer::getRandomNumber(0, 2)];
	else
		this->badPrefix = itemtype::badPrefix[Randomizer::getRandomNumber(0, 2)];
}