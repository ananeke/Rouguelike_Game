#pragma once
#include "actor.h"
#include "actortype.h"
#include <string>


using namespace std;

class Hero : public Actor
{
public:

	Hero(string, unsigned int = 20, unsigned int = 5, int = HERO);
	void Attack();
	void showBackPack();
};
