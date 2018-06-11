#include "room.h"
#include "hero.h"

int Room::getPositionX() { return positionX; }
int Room::getPositionY() { return positionY; }

void Room::setPositionX(int positionX) { this->positionX = positionX; }
void Room::setPositionY(int positionY) { this->positionY = positionY; }

Room::Room()
{
	isOpen = Randomizer::getRandomMapSize(0, 1);
	actor = NULL;

}