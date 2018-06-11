// Rouguelike_Game.cpp : Defines the entry point for the console application.
//
#pragma once
#include "map.h"
#include "actor.h"
#include "hero.h"
#include "logo.h"
#include "utilities.h"
#include <iostream>
#include <list>
#include <windows.h>
#include <ctime>
#include <memory>

//#include "item.h"

using namespace std;


int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	srand(time(NULL));
	MoveWindow(console, r.left, r.top, 1000, 800, TRUE);

	
	unique_ptr<Map> map = make_unique<Map>();
	map->map[0][0]->actor = make_shared<Hero>();



	char option;
	map->map[0][0]->actor->changeName();

	do {
		system("cls");
		DrawImage("logo.txt");
		map->drawMap();
		cout << endl;
		DrawImage("instructions.txt");
		cout << endl; cout << "MAPSSIZE: " << map->MAPSIZE << " x " << map->MAPSIZE << endl;
		cout << "What you want to do? " << endl;
		cin >> option;
		if (option == 'w' || option == 'd' || option == 's' || option == 'a') {
			map->actorMove(option, map->getHero());
		}
		else if (option == 'i') {
			savingGame(map, true);
		}
		else if (option == 'k') {
			savingGame(map, false);
		}
		else if (option == 'o') {
			loadGame(map, true);
		}
		else if (option == 'l') {
			loadGame(map, false);
		}
		else if (option == 'c') {
			map->getHero()->showStats();
		}
		

	} while (true);


	
	
	/*Map M1;
	Hero h1(0, 0);
	Monster m1(10, 11);
	Monster m2(9, 9);

	std::list<Monster> list_monsters;
	list_monsters.push_back(m1);
	list_monsters.push_back(m2);
	

	do
	{
		
		
		M1.UpdateMap(h1, list_monsters);
		M1.DrawMap();
		M1.MoveHero(h1, move);
		M1.MoveMonster(h1, list_monsters);
	} while (true);

	//M1.DrawMap();*/



	clearConsoleBuffer();
	getchar();
	return 0;
}

