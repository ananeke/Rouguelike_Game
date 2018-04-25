#ifndef ACTOR_H
#define ACTOR_H
#include <iostream>
#include <array>
#include <string>
#include "actortype.h"
#include "backpack.h"

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

	//getters
	unsigned int getLife() {return life;}
    unsigned int getStrength() {return strength;}
	string getActorName(){return actorName;}
	int getActorType() {return actorType;}
	int getPositionX() {return positionX;}
	int getPositionY() {return positionY;}
	//setters
	void setLife(unsigned int life) {this->life = life;}
	void setStrength(unsigned int strength) {this->strength = strength;}
	void setActorName(string actorName) {this->actorName = actorName;}
	void setActorType(int actorType) {this->actorType = actorType;}
	void setPositionX(int positionX) { this->positionX = positionX; }
	void setPositionY(int positionY) { this->positionY = positionY; }

	virtual void Attack() = 0;
	virtual void Move() = 0;
	virtual void showBackPack() = 0;
};
#endif
