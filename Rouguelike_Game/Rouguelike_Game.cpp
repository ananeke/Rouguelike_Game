// Rouguelike_Game.cpp : Defines the entry point for the console application.
//
#pragma once
#include "map.h"
#include "actor.h"
#include "hero.h"
#include "monster.h"
#include "logo.h"
#include "utilities.h"
#include <iostream>
#include <list>
#include <windows.h>
#include <ctime>
#include <memory>

using namespace std;

class Hero;
int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	srand(time(NULL));
	MoveWindow(console, r.left, r.top, 1000, 1000, TRUE);

	shared_ptr<Hero> hero = make_shared<Hero>();

	hero->changeName();
	while (true) {
		newGame(hero);
		hero->setPositionX(0);
		hero->setPositionY(0);
		hero->dungeonLevel++;
	}
	

	clearConsoleBuffer();
	getchar();
	return 0;
}