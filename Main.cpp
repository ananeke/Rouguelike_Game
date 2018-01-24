#include <iostream>
#include <list>
#include <cstdlib>
#include "MAP.h"
#include "PLAYER.h"

int main(int argc, char* argv[])
{
    Map M1;
    Hero h1(0,0);
    Monster m1(5,5);
    Monster m2(9,2);

    std::list<Monster> list_monsters;
    list_monsters.push_back(m1);
    list_monsters.push_back(m2);
    char move;

    do
    {
        system("cls");
        M1.UpdateMap(h1,list_monsters);
        M1.DrawMap();
        std::cout<<"Gdzie chcesz isc? "<<std::endl;
        std::cin>>move;
        M1.MoveHero(h1,move);
    }
    while(true);






    return 0;
}
