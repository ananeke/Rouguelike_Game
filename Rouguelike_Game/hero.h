#pragma once
#include "actor.h"
#include "actortype.h"
#include "utilities.h"
#include <string>
#include <windows.h>


using namespace std;

class Hero : public Actor
{
public:

	Hero(string = "Dida", unsigned int = 20, unsigned int = 5, int = HERO);
	void Attack();
	void showBackPack();
	void showStats();
	void changeName();
};
