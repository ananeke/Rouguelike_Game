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