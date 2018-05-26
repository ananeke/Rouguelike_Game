#include "hero.h"

Hero::Hero(string actorName, unsigned int life, unsigned int strength, int actorType)
{
	setActorName(actorName);
	setPositionX(0);
	setPositionY(0);
	setLife(life);
	setStrength(strength);
	setActorType(actorType);
}

void Hero::Attack()
{

};



void Hero::showBackPack()
{

};

void Hero::showStats()
{
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t" << getActorName() << " CHARACTER STATS:" << endl;
	cout << "\t\t" << "Life: " << getLife() << endl;
	cout << "\t\t" << "Strength: " << getStrength() << endl;
	cout << "\t\t" << "PositionX: " << getPositionX() << endl;
	cout << "\t\t" << "PositionY: " << getPositionY() << endl;
	clearConsoleBuffer();
	getchar();
};