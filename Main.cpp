#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "MAP.h"
#include "PLAYER.h"
#include "LOGO.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    Map M1;
    Hero h1(0,0);
    Monster m1(10,11);
    Monster m2(9,9);

    std::list<Monster> list_monsters;
    list_monsters.push_back(m1);
    list_monsters.push_back(m2);
    char move;

    do
    {
        system("cls");
        DrawImage("logo.txt");
        M1.UpdateMap(h1,list_monsters);
        M1.DrawMap();
        std::cout<<"Gdzie chcesz isc? "<<std::endl;
        std::cin>>move;
        M1.MoveHero(h1,move);
        M1.MoveMonster(h1,list_monsters);
    }
    while(true);

    return 0;
}
