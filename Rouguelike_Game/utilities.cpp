#include "utilities.h"
#include "hero.h"
#include <algorithm>
#include <vector>

bool savingGame(const unique_ptr<Map>& map, bool isTxt)
{
	bool ret = true;
	shared_ptr<Actor> actor = map->getHero();

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

bool isFileExist(const char *fileName)
{
	std::ifstream infile(fileName);
	return infile.good();
}

void gameOver(shared_ptr<Actor>& hero) {
	system("cls");
	DrawImage("game_over.txt");
	Sleep(2000);
	system("cls");
	Hero* temp;
	std::vector<Actor*> heroList;
	size_t size = 0;
	if (!isFileExist("saves/highScore.bin")) {
		ofstream gameOver("saves/highScore.bin", ofstream::binary);
		size = 1;
		gameOver.write((char*)&size, sizeof(size));
		gameOver.write((char*)hero.get(), sizeof(Hero));
		gameOver.close();
		heroList.push_back(hero.get());
	}
	else
	{
		ifstream gameOver("saves/highScore.bin", ifstream::binary);
		gameOver.read((char*)&size, sizeof(size));
		
		for (int i = 0; i < size; ++i) {
			temp = new Hero();
			gameOver.read((char*)temp, sizeof(Hero));
			heroList.push_back(temp);
		}
		gameOver.close();
		heroList.push_back(hero.get());

		size = heroList.size();

		ofstream gameOver2("saves/highScore.bin", ofstream::binary);
		gameOver2.write((char*)&size, sizeof(size));
		for (int i = 0; i < size; ++i) {
			gameOver2.write((char*)heroList[i], sizeof(Hero));
		}
		gameOver2.close();
	}

	sort(heroList.begin(), heroList.end());

	cout << endl << endl;
	cout << "\t\t\t****HIGH SCORE****" << endl;
	cout << "\t\t\tHERO NAME \t SCORE" << endl << endl;

	for (int i = 0; i < size; ++i) {
		cout << "\t\t\t " << i+1 << ". " << heroList[i]->getActorName() << " \t " << heroList[i]->score << endl;
	}

	Sleep(4000);
}

void gameOver(shared_ptr<Hero>& hero) {
	system("cls");
	DrawImage("game_over.txt");
	Sleep(2000);
	system("cls");
	Hero* temp;
	std::vector<Actor*> heroList;
	size_t size = 0;
	if (!isFileExist("saves/highScore.bin")) {
		ofstream gameOver("saves/highScore.bin", ofstream::binary);
		size = 1;
		gameOver.write((char*)&size, sizeof(size));
		gameOver.write((char*)hero.get(), sizeof(Hero));
		gameOver.close();
		heroList.push_back(hero.get());
	}
	else
	{
		ifstream gameOver("saves/highScore.bin", ifstream::binary);
		gameOver.read((char*)&size, sizeof(size));

		for (int i = 0; i < size; ++i) {
			temp = new Hero();
			gameOver.read((char*)temp, sizeof(Hero));
			heroList.push_back(temp);
		}
		gameOver.close();
		heroList.push_back(hero.get());

		size = heroList.size();

		ofstream gameOver2("saves/highScore.bin", ofstream::binary);
		gameOver2.write((char*)&size, sizeof(size));
		for (int i = 0; i < size; ++i) {
			gameOver2.write((char*)heroList[i], sizeof(Hero));
		}
		gameOver2.close();
	}

	sort(heroList.begin(), heroList.end());

	cout << endl << endl;
	cout << "\t\t\t****HIGH SCORE****" << endl;
	cout << "\t\t\tHERO NAME \t SCORE" << endl << endl;

	for (int i = 0; i < size; ++i) {
		cout << "\t\t\t " << i + 1 << ". " << heroList[i]->getActorName() << " \t " << heroList[i]->score << endl;
	}

	Sleep(4000);
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
	for (int i = 0; i < Randomizer::getRandomNumber(1, 8); ++i) {
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
		cout << "\tDUNGEON LEVEL " << hero->dungeonLevel << "/3" << endl;
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
			if (hero->dungeonLevel == 3) {
				hero->score += 7;
				gameOver(hero);
				exit(666);
			}
			else {
				hero->score += 3;
				return;
			}
		}
		
	} while (true);
}