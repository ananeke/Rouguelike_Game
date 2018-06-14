#pragma once
#include "map.h"
#include "actor.h"
#include "hero.h"
#include "monster.h"
#include "logo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <list>
#include <windows.h>
#include <ctime>
#include <memory>

class Hero;

bool savingGame(const unique_ptr<Map>&, bool);
bool loadGame(unique_ptr<Map>&, bool);
void clearConsoleBuffer();
void newGame(shared_ptr<Hero>&);
