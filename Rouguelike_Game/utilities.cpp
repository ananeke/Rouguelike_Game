#include "utilities.h"

bool savingGame(const unique_ptr<Map>& map, bool isTxt)
{
	bool ret = true;
	shared_ptr<Actor> actor = map->getHero();
	//Actor* actor = new Hero("MAti");

	if (isTxt) 
	{
		fstream saveGame;
		saveGame.open("saves/savesGames.txt", ios::out);
		saveGame << actor->getLife() << endl;
		saveGame << actor->getStrength() << endl;
		saveGame << actor->getActorName() << endl;
		saveGame << actor->getPositionX() << endl;
		saveGame << actor->getPositionY() << endl;

		saveGame.close();
	}
	else
	{
		ofstream saveGame("saves/savesGames.bin", ofstream::binary);
		saveGame.write((char*) actor.get(), sizeof(Hero));
		saveGame.close();
		
	}

	return ret;
}

bool loadGame(unique_ptr<Map>& map, bool isTxt)
{
	bool ret = true;
	string line;
	shared_ptr<Actor> actor = map->getHero();

	if (isTxt)
	{
		fstream loadGame;
		loadGame.open("saves/savesGames.txt", ios::in);
		getline(loadGame, line);
		actor->setLife(stoul(line));
		getline(loadGame, line);
		actor->setStrength(stoul(line));
		getline(loadGame, line);
		actor->setActorName(line);

		map->map[actor->getPositionX()][actor->getPositionY()]->actor = NULL;
		
		getline(loadGame, line);
		actor->setPositionX(stoi(line));
		getline(loadGame, line);
		actor->setPositionY(stoi(line));

		map->map[actor->getPositionX()][actor->getPositionY()]->actor = actor;
		loadGame.close();
	}
	else
	{
		map->map[actor->getPositionX()][actor->getPositionY()]->actor = NULL;
		ifstream loadGame("saves/savesGames.bin", ifstream::binary);
		loadGame.read((char *)actor.get(), sizeof(Hero));
		loadGame.close();
		
		map->map[actor->getPositionX()][actor->getPositionY()]->actor = actor;

	}

	return ret;
}

void clearConsoleBuffer() {
	char ch;
	while (cin.readsome(&ch, 1) != 0)
		;
}

void newGame(shared_ptr<Hero>& hero) {
	//make map
	unique_ptr<Map> map = make_unique<Map>();
	//make hero
	map->map[hero->getPositionX()][hero->getPositionY()]->actor = hero;
	// first position of hero is always open
	map->map[hero->getPositionX()][hero->getPositionY()]->isOpen = 2;
	//make monster
	list<Monster*> listMonsters;
	for (int i = 0; i < Randomizer::getRandomNumber(1, 5); ++i) {
		int monsterX = Randomizer::getRandomNumber(3, map->MAPSIZE - 1);
		int monsterY = Randomizer::getRandomNumber(3, map->MAPSIZE - 1);
		map->map[monsterX][monsterY]->actor = make_shared<Monster>();
		map->map[monsterX][monsterY]->isOpen = 2;
		listMonsters.push_back(new Monster());
	}

	//make room of exit
	int exitX = Randomizer::getRandomNumber(0, map->MAPSIZE - 1);
	int exitY = Randomizer::getRandomNumber(0, map->MAPSIZE - 1);
	// room of exit is always open
	if (map->map[exitX][exitY]->isOpen == 1)
		map->map[exitX][exitY]->isOpen = 2;
	map->map[exitX][exitY]->isExit = true;




	char option;
	

	do {
		system("cls");
		DrawImage("logo.txt");
		map->drawMap();
		cout << endl;
		DrawImage("instructions.txt");
		cout << endl; cout << "MAPSIZE: " << map->MAPSIZE << " x " << map->MAPSIZE <<
			"\t\t" << "SCORE: " << hero->score <<"\t" <<"LEVEL: " << hero->dungeonLevel << endl;
		cout << "What you want to do? " << endl;
		cin >> option;
		if (option == 'w' || option == 'd' || option == 's' || option == 'a') {
			map->actorMove(option, map->getHero());
		}
		else if (option == 'i') {
			savingGame(map, true);
		}
		else if (option == 'k') {
			savingGame(map, false);
		}
		else if (option == 'o') {
			loadGame(map, true);
		}
		else if (option == 'l') {
			loadGame(map, false);
		}
		else if (option == 'c') {
			map->getHero()->showStats();
		}


		if (map->map[map->getHero()->getPositionX()][map->getHero()->getPositionY()]->isExit == true) {
			system("cls");
			return;
		}
			
		

	} while (true);
}