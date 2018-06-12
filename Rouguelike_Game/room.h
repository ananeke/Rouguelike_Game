#pragma once
//#include "item.h"
#include "actor.h"
#include <memory>

using namespace std;

class Actor;

class Room
{
private:
	int positionX;
	int positionY;
public:
	int isOpen;
	bool isExit;
	shared_ptr<Actor> actor;
	//Item item;

	//getters
	int getPositionX();
	int getPositionY();
	//setters
	void setPositionX(int);
	void setPositionY(int);

	Room();
};

