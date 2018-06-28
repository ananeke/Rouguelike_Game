#include "actor.h"
#include "logo.h"
#include "map.h"
#include "monster.h"
#include "utilities.h"
#include <iostream>
#include <windows.h>
#include <ctime>
#include <list>

void startBattle(shared_ptr<Actor> hero, shared_ptr<Actor> monster)
{
	bool win = false;
	while (!win)
	{
		system("cls");
		DrawImage("monster.txt");
		if ((monster->getLife() > 0) | (hero->getLife() > 0))
		{
			cout << "\n Monster life: " << monster->getLife() << endl << endl;
			cout << "\n Hero life: " << hero->getLife() << endl << endl;
			cout << " Attack options: " << endl;
			cout << "\t\t f - normal attack " << hero->getStrength() << " points of damage\n";
			cout << "\t\t g - mega attack " << hero->getStrength() * 2 <<" points of damage (chance 30%)\n";
			char dec;
			cout << " Your choice: \n";
			cin >> dec;

			switch (dec)
			{
			case 'f':
				if (monster->getLife() > 0)
				{
					monster->setLife(monster->getLife() - hero->getStrength());
					hero->setLife(hero->getLife() - monster->getStrength());
					cout << "\n Hero beat the Monster for "<< hero->getStrength() <<" points and Monster hit the Hero for " << monster->getStrength() << " points\n";
					Sleep(3000);
				}
				break;
			case 'g':
				if (rand() % 3 == 1)
				{
					monster->setLife(monster->getLife() - hero->getStrength() * 2);
					hero->setLife(hero->getLife() - monster->getStrength());
					cout << "\n Hero beat the Monster for " << hero->getStrength() * 2 << " points and Monster hit the Hero for " << monster->getStrength() << " points\n";
					Sleep(3000);
				}
				else
				{
					cout << "\n\n Hero don't hit the Monster!\n";
					hero->setLife(hero->getLife() - monster->getStrength());
					cout << "\n Monster hit the Hero for " << monster->getStrength() << " points\n";
					Sleep(3000);
				}
				break;
				//return;
			default:
				cout << "Wrong key !!! \nFor a punishment, the monster beats Hero for 5 points!\n";
				Sleep(3000);
				hero->setLife(hero->getLife() - 5);
				break;
				//return;
			}
		}
		if (monster->getLife() <= 0)
		{
			system("cls");
			DrawImage("hero.txt");
			cout << "\n\n Hero kills the Monster!\n";
			Sleep(3000);
			return;
		}
		if (hero->getLife() <= 0)
		{
			system("cls");
			DrawImage("monster_wins.txt");
			Sleep(2000);
			gameOver(hero);
			exit(666);
		}
	}
}