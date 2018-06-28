#pragma once
#include "actor.h"
#include "actortype.h"
#include "utilities.h"
#include "randomizer.h"
#include <string>
#include <windows.h>

using namespace std;

class Monster : public Actor
{
public:
	Monster(int = 10, int = 3, int = Randomizer::getRandomNumber(1, 4));
	void Attack();
	void showBackPack();
	void showStats();
	void changeName();
};