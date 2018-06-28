#pragma once
#include "actortype.h"
#include "backpack.h"
#include "map.h"

using namespace std;

class Actor
{
private:
	int life;
	int strength;
	string actorName;
	int actorType;
	int positionX;
	int positionY;
	
public:	
	bool isExists;
	BackPack backPack;
	int score;

	int getLife();
	int getStrength();
	string getActorName();
	int getActorType();
	int getPositionX();
	int getPositionY();

	void setLife(int);
	void setStrength(int);
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

