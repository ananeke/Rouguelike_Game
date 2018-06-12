#include "map.h"
#include "hero.h"
#include "actortype.h"
#include <memory>
#include <algorithm>


using namespace std;

Map::Map()
{
	MAPSIZE = Randomizer::getRandomNumber(8, 16);
	for (int i = 0; i < MAPSIZE; ++i)
	{
		vector<Room*> temp;
		for (int j = 0; j < MAPSIZE; ++j)
			temp.push_back(new Room);
		map.push_back(temp);
	}
}

shared_ptr<Actor> Map::getHero() {
	for (int i = 0; i < MAPSIZE; ++i) {
		for (int j = 0; j < MAPSIZE; ++j) {
			if(map[i][j]->actor != NULL)
				if (map[i][j]->actor->getActorType() == HERO)
					return map[i][j]->actor;
		}
	}
}


void Map::drawMap()
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if (map[i][j]->isOpen == 1 && j == map[i].size() - 1)
				cout << '#' << '|' << endl;
			else if (map[i][j]->isOpen == 1)
				cout << '#';
			else {
				if (map[i][j]->actor != NULL) {
					if ((map[i][j]->actor->getActorType() == HERO) && (j == map[i].size() - 1))
						cout << 'H' << endl;
					else if (map[i][j]->actor->getActorType() == HERO)
						cout << 'H';
					else if (map[i][j]->actor->getActorType() != HERO && j == map[i].size() - 1)
						cout << 'M' << endl;
					else if (map[i][j]->actor->getActorType() != HERO)
						cout << 'M';
				}
				else {
					if (map[i][j]->isExit && j == map[i].size() - 1)
						cout << 'E' << '|' << endl;
					else if (map[i][j]->isExit)
						cout << 'E';
					else if (j == map[i].size() - 1)
						cout << '_' << '|' << endl;
					else if (map[i][j]->isOpen)
						cout << '_';
				}
			}
			
			
		}
	}
}

//for Hero
void Map::actorMove(char move, shared_ptr<Actor> actor)
{
	if (actor->getActorType() == HERO) {
		switch (move)
		{
		case 'w':
			if(actor->getPositionX() - 1 < 0 || map[actor->getPositionX() - 1][actor->getPositionY()]->isOpen == 0)
				return;
			else {
				actor->setPositionX(actor->getPositionX() - 1);
				map[actor->getPositionX()][actor->getPositionY()]->actor = actor;
				map[actor->getPositionX() + 1][actor->getPositionY()]->actor = NULL;
			}
			break;
		case 'd':
			if (actor->getPositionY() + 1 >= MAPSIZE || map[actor->getPositionX()][actor->getPositionY() + 1]->isOpen == 0)
				return;
			else {
				actor->setPositionY(actor->getPositionY() + 1);
				map[actor->getPositionX()][actor->getPositionY()]->actor = actor;
				map[actor->getPositionX()][actor->getPositionY() - 1]->actor = NULL;
			}
			break;
		case 's':
			if (actor->getPositionX() + 1 >= MAPSIZE || map[actor->getPositionX() + 1][actor->getPositionY()]->isOpen == 0)
				return;
			else {
				actor->setPositionX(actor->getPositionX() + 1);
				map[actor->getPositionX()][actor->getPositionY()]->actor = actor;
				map[actor->getPositionX() - 1][actor->getPositionY()]->actor = NULL;
			}
			break;
		case 'a':
			if (actor->getPositionY() - 1 < 0 || map[actor->getPositionX()][actor->getPositionY() - 1]->isOpen == 0)
				return;
			else {
				actor->setPositionY(actor->getPositionY() - 1);
				map[actor->getPositionX()][actor->getPositionY()]->actor = actor;
				map[actor->getPositionX()][actor->getPositionY() + 1]->actor = NULL;
			}
			break;
		}
	}
}

//for Monster
void Map::actorMove(shared_ptr<Actor>)
{

}