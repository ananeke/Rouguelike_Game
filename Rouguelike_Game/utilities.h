#pragma once
#include "map.h"
#include "actor.h"
#include "hero.h"
#include <iostream>
#include <fstream>
#include <string>

bool savingGame(const unique_ptr<Map>&, bool);
bool loadGame(unique_ptr<Map>&, bool);
void clearConsoleBuffer();
