#pragma once
#include "actortype.h"
#include "backpack.h"
#include "map.h"


using namespace std;

class Actor
{
private:
	unsigned int life;
	unsigned int strength;
	string actorName;
	int actorType;
	int positionX;
	int positionY;
	
public:	
	bool isExists;
	BackPack backPack;

	unsigned int getLife();
	unsigned int getStrength();
	string getActorName();
	int getActorType();
	int getPositionX();
	int getPositionY();

	void setLife(unsigned int);
	void setStrength(unsigned int);
	void setActorName(string);
	void setActorType(int);
	void setPositionX(int);
	void setPositionY(int);

	virtual void Attack() = 0;
	virtual void showBackPack() = 0;
	virtual void showStats() = 0;
	virtual void changeName() = 0; 

	virtual ~Actor() = 0;
};

