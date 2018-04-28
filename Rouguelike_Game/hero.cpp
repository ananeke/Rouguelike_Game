#include "hero.h"

Hero::Hero(string actorName, unsigned int life, unsigned int strength, int actorType)
{
	setActorName(actorName);
	setPositionX(0);
	setPositionY(0);
	setLife(life);
	setStrength(strength);
	setActorType(actorType);
}

void Hero::Attack()
{

};



void Hero::showBackPack()
{

};
