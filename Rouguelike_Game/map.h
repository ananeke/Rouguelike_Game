#pragma once
#include "actor.h"
#include "room.h"
#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <memory>

#define MAPSIZE 10

using namespace std;
class Room;
class Actor;
class Map
{
public:
	vector<vector<Room*>> map;

	Map();

	void drawMap();
	void actorMove(char, shared_ptr<Actor>);		//for Hero
	void actorMove(shared_ptr<Actor>);				//for Monsters
	shared_ptr<Actor> getHero();

	/*void UpdateMap(Hero &hero, list<Monster> &list)
	{
		//map[hero.position[0]][hero.position[1]] = 1;
		map[2][3] = 1;

		if (!list.empty())
		{
			for (Monster var : list)
				//map[var.position[0]][var.position[1]] = 2;
		}
	}

	void MoveHero(Hero &hero, char &move)
	{
		//map[hero.position[0]][hero.position[1]] = 0;
		
		if (hero.position[0] >= MAPSIZE)
			hero.position[0] = MAPSIZE - 1;
		else if (hero.position[1] >= MAPSIZE)
			hero.position[1] = MAPSIZE - 1;
		else if (hero.position[0] < 0)
			hero.position[0] = 0;
		else if (hero.position[1] < 0)
			hero.position[1] = 0;
	}

	void MoveMonster(Hero &hero, list<Monster> &list)
	{
		if (!list.empty())
		{
			for (std::list<Monster>::iterator var = list.begin(); var != list.end(); ++var)
			{
				map[var->position[0]][var->position[1]] = 0;

				if (((hero.position[0] == var->position[0]) && (hero.position[1] == var->position[1])) | ((var->position[0] == hero.position[0]) && (var->position[1] == hero.position[1])))
				{
					StartBattle(hero, list);
					map[hero.position[0]][hero.position[1]] = 0;
					return;
				}
				else
				{
					if (rand() % 2 == 1)
					{
						if (var->position[1] > hero.position[1])
						{
							var->position[1] -= 1;
							std::cout << var->position[0] << " " << var->position[1];
						}
						else
						{
							var->position[1] += 1;
							std::cout << var->position[0] << " " << var->position[1];
						}
					}
					else
					{
						if (var->position[0] > hero.position[0])
							var->position[0] -= 1;
						else
							var->position[0] += 1;
					}
				}
			}
		}
	}*/
};

