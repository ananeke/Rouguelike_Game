#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include <windows.h>
#include <list>
#include "PLAYER.h"
#include "LOGO.h"

void StartBattle(Hero &hero, std::list<Monster> &list)
{
    bool win = false;
    do
    {
        system("cls");
        DrawImage("Monster.txt");
        for (std::list<Monster>::iterator var = list.begin(); var != list.end(); ++var)
        {
            if ((hero.position[0] == var->position[0])&&(hero.position[1] == var->position[1]))
            {
                std::cout<<"\n Pozostale zycie potwora: "<<var->hp<<std::endl<<std::endl;
                std::cout<<"\n Pozostale zycie bohatera: "<<hero.hp<<std::endl<<std::endl;
                std::cout<<"Mozliwosci ataku: "<<std::endl;
                std::cout<<"\t\t f - zwykly atak za 4 punkty obrazen\n";
                std::cout<<"\t\t g - mega atak za 10 punktow obrazen (szansa 30%)\n";
                char dec;
                std::cout <<"Twoj wybor: \n";
                std::cin>>dec;

                switch (dec)
                {
                case 'f':
                    var->hp -= 4;
                    hero.hp -= 3;
                    std::cout<<"\n Bijesz potwora za 4 punkty, a potwor ciebie za 3 punkty\n";
                    break;
                case 'g':
                    system("cls");

                    DrawImage("Hero.txt");
                    std::cout<<"\n\n Zabijasz potwora!\n";
                    Sleep(5000);
                    win = true;
                    list.erase(var);
                    break;
                default:
                    std::cout<<"Zły klawisz!!!\n Za kare potwor bije cie za 5 punktow!\n";
                    hero.hp -= 5;
                    break;
                }
            }
        }
    } while (!win);
}
















#endif
