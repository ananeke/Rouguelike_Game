#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <string>
#include "actor.h"
#include "actortype.h"

using namespace std;

class Hero : public Actor
{
public:

	Hero(string actorName, unsigned int life = 20, unsigned int strength = 5, int actorType = HERO)
	{
		setActorName(actorName);
		setPositionX(0);
		setPositionY(0);
		setLife(life);
		setStrength(strength);
		setActorType(actorType);
	}
	
	void Attack();
	void Move();
	void showBackPack();

};

void Hero::Attack()
{

}

void Hero::Move()
{

}

void Hero::showBackPack()
{

}
#endif
