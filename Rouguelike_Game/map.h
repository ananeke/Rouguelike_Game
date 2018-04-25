#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include "actor.h"
//#include "battle.h"
#include "room.h"
#define MAPSIZE 10

using namespace std;

class Map
{
	vector<vector<Room*>> map;
public:
	Map()
	{
		for (int i = 0; i < MAPSIZE; ++i)
		{
			vector<Room*> temp;
			for (int j = 0; j < MAPSIZE; ++j)
				temp.push_back(new Room);
			map.push_back(temp);
		}
	}

	void DrawMap()
	{
		for (int i = 0; i < map.size(); ++i)
		{
			for (int j = 0; j < map[i].size(); ++j)
			{
				if ((map[i][j]->actor->getActorType() == HERO) && (i == map[i][j]->actor->getPositionX()) && (j == map[i][j]->actor->getPositionY()) && (j == map[i].size() - 1))
					cout << 'H' << endl;
				else if (map[i][j]->actor->getActorType() == HERO && i == map[i][j]->actor->getPositionX() && j == map[i][j]->actor->getPositionY())
					cout << 'H';
				else if (map[i][j]->actor->getActorType() != HERO && j == map[i].size() - 1)
					cout << 'M' << endl;
				else if (map[i][j]->actor->getActorType() != HERO)
					cout << 'M';
				else if (map[i][j]->isOpen && j == map[i].size() - 1)
					cout << '_' << '|' << endl;
				else if (map[i][j]->isOpen)
					cout << '_';
			}
		}
	}

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
		switch (move)
		{
		case 'w':
			hero.position[0] -= 1;
			break;
		case 'd':
			hero.position[1] += 1;
			break;
		case 's':
			hero.position[0] += 1;
			break;
		case 'a':
			hero.position[1] -= 1;
			break;
		}
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

#endif
