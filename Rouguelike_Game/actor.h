#ifndef ACTOR_H
#define ACTOR_H
#include <iostream>
#include <array>
#include <string>
#include "enemytype.h"

using namespace std;

class Actor
{
private:
	unsigned int life;
	unsigned int strength;
	string actorName;
	int type;
	Item item;
public:	
	bool isExists;

	//getters
	unsigned int getLife() {return life;}
    unsigned int getStrength() {return strength;}
	string getActorName(){return actorName;}
	int getType() {return type;}
	Item getItems() {return item;}
	//setters
	void setLife(unsigned int life) {this->life = life;}
	void setLife(unsigned int strength) {this->strength = strength;}
	void setActorName() {this->actorName = actorName;}
	void setType() {this->type = type;}
	void setItem() {this->item = item;}

	virtual void Attack() = 0;
};





class Hero
{
public:
	std::array<int, 10> back_pack;
	int points = 0;
	int position[2];
	int hp = 20;

	Hero(int x, int y)
	{
		position[0] = x; //kolumny
		position[1] = y; //wiersze
	}
};

class Monster
{
public:
	int position[2];
	int hp = 10;

	Monster(int x, int y)
	{
		position[0] = x;
		position[1] = y;
	}
};

#endif
