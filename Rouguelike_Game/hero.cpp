#include "hero.h"
#include "logo.h"
#include <string>

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

void Hero::changeName() {

	int error;
	string name;
	do {
		DrawImage("logo.txt");
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t" << " How you want name your Hero?" << endl << endl;
		cout << "\t\t\t\t";
		getline(cin, name);
		if (name.length() > 10) {
			error = 2;
			cout << "Hero name is too long.";
			Sleep(1500);
		}
		else if (name.empty()) {
			error = 3;
			cout << "Hero name is too short.";
			Sleep(1500);
		}
		else {
			error = 1;
			setActorName(name);
		}
		system("cls");
	}
	while (error >= 2);
};