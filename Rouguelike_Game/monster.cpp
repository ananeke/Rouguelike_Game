#include "monster.h"
#include "logo.h"
#include <string>

Monster::Monster(int life, int strength, int actorType)
{
	setPositionX(0);
	setPositionY(0);
	setLife(life);
	setStrength(strength);
	setActorType(actorType);
}

void Monster::showBackPack()
{

};

void Monster::showStats()
{
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t" << getActorType() << " CHARACTER STATS:" << endl;
	cout << "\t\t" << "Life: " << getLife() << endl;
	cout << "\t\t" << "Strength: " << getStrength() << endl;
	cout << "\t\t" << "PositionX: " << getPositionX() << endl;
	cout << "\t\t" << "PositionY: " << getPositionY() << endl;
	clearConsoleBuffer();
	getchar();
};

void Monster::changeName() {}
void Monster::Attack() {}