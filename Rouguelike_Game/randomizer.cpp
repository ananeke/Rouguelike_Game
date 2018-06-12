#include "randomizer.h"
#include <ctime>
#include <cstdlib>


int Randomizer::getRandomNumber(int min, int max) {
	
	return rand() % (max - min + 1) + min;
}