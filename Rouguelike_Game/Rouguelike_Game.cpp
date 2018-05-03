// Rouguelike_Game.cpp : Defines the entry point for the console application.
//
#pragma once
#include "map.h"
#include "actor.h"
#include "hero.h"
#include "logo.h"
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

	MoveWindow(console, r.left, r.top, 1000, 500, TRUE);

	//srand(time(NULL));
	
	unique_ptr<Map> map = make_unique<Map>();
	map->map[0][0]->actor = make_shared<Hero>("Dida");



	char move;

	do {
		system("cls");
		DrawImage("logo.txt");
		map->drawMap();
		cout << "Gdzie chcesz isc? " << endl;
		cin >> move;
		map->actorMove(move, map->getHero());
		
		


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




	getchar();
	return 0;
}

