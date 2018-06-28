#pragma once
#include "actor.h"
#include "room.h"
#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <memory>
#include "randomizer.h"

using namespace std;
class Room;
class Actor;
class Map
{
public:
	vector<vector<Room*>> map;
	int MAPSIZE;
	Map();

	void drawMap();
	void actorMove(char, shared_ptr<Actor>);		//for Hero
	void actorMove(shared_ptr<Actor>);				//for Monsters
	shared_ptr<Actor> getHero();
	shared_ptr<Actor> getMonster();
};