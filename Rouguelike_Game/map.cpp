#include "map.h"
#include <memory>
#include "hero.h"

using namespace std;

Map::Map()
{
	for (int i = 0; i < MAPSIZE; ++i)
	{
		vector<Room*> temp;
		for (int j = 0; j < MAPSIZE; ++j)
			temp.push_back(new Room);
		map.push_back(temp);
	}

	map[0][0]->actor = make_shared<Hero>("Dida");

}

void Map::drawMap()
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if (map[i][j]->actor != NULL) {
				if ((map[i][j]->actor->getActorType() == HERO) && (i == map[i][j]->actor->getPositionX()) && (j == map[i][j]->actor->getPositionY()) && (j == map[i].size() - 1))
					cout << 'H' << endl;
				else if (map[i][j]->actor->getActorType() == HERO && i == map[i][j]->actor->getPositionX() && j == map[i][j]->actor->getPositionY())
					cout << 'H';
				else if (map[i][j]->actor->getActorType() != HERO && j == map[i].size() - 1)
					cout << 'M' << endl;
				else if (map[i][j]->actor->getActorType() != HERO)
					cout << 'M';
			}
			else {
				if (map[i][j]->isOpen && j == map[i].size() - 1)
					cout << '_' << '|' << endl;
				else if (map[i][j]->isOpen)
					cout << '_';
			}
			
			
		}
	}
}

void Map::actorMove(char move, Actor* actor)
{
	if (actor->getActorType() == HERO) {
		switch (move)
		{
		case 'w':
			actor->setPositionX(actor->getPositionX() - 1);
			break;
		case 'd':
			actor->setPositionY(actor->getPositionY() + 1);
			break;
		case 's':
			actor->setPositionX(actor->getPositionX() + 1);
			break;
		case 'a':
			actor->setPositionY(actor->getPositionY() - 1);
			break;
		}
	}
}
