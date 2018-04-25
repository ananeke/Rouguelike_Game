#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "actor.h"
//#include "item.h"
#include "hero.h"


class Room
{
private:
	int positionX;
	int positionY;
public:
	bool isOpen;
	Actor* actor;
	//Item item;

	//getters
	/*int getPositionX() { return positionX; }
	int getPositionY() { return positionY; }
	//setters
	void setPositionX(int positionX) { this->positionX = positionX; }
	void setPositionY(int positionY) { this->positionY = positionY; }*/

	Room()
	{
		actor = new Hero("Dida");
		isOpen = true;

	}
};

#endif
