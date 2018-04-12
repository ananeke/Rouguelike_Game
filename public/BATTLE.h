#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include <windows.h>
#include <ctime>
#include <list>
#include "player.h"
#include "logo.h"
#include "map.h"

void StartBattle(Hero &hero, std::list<Monster> &list)
{
    bool win = false;
    while (!win)
    {
        system("cls");
        DrawImage("Monster.txt");
        for (std::list<Monster>::iterator var = list.begin(); var != list.end(); ++var)
        {
            if ((hero.position[0] == var->position[0])&&(hero.position[1] == var->position[1]))
            {
                if ((var->hp > 0)|(hero.hp >0))
                {
                    std::cout<<"\n Pozostale zycie potwora: "<<var->hp<<std::endl<<std::endl;
                    std::cout<<"\n Pozostale zycie bohatera: "<<hero.hp<<std::endl<<std::endl;
                    std::cout<<" Mozliwosci ataku: "<<std::endl;
                    std::cout<<"\t\t f - zwykly atak za 4 punkty obrazen\n";
                    std::cout<<"\t\t g - mega atak za 10 punktow obrazen (szansa 30%)\n";
                    char dec;
                    std::cout <<" Twoj wybor: \n";
                    std::cin>>dec;

                    switch (dec)
                    {
                    case 'f':
                        if (var->hp > 0)
                        {
                            var->hp -= 4;
                            hero.hp -= 3;
                            std::cout<<"\n Bijesz potwora za 4 punkty, a potwor ciebie za 3 punkty\n";
                            Sleep(2000);
                        }
                        else
                        {
                            win = true;
                            list.erase(var);
                        }
                        break;
                    case 'g':
                        if (rand() % 3 == 1)
                        {
                            win = true;
                            var->hp = 0;
                        }
                        else
                        {
                            std::cout<<"\n\n nie zabijasz potwora!\n";
                            Sleep(2000);
                        }
                        break;
                        //return;
                    default:
                        std::cout<<"Zły klawisz!!!\n Za kare potwor bije cie za 5 punktow!\n";
                        hero.hp -= 5;
                        break;
                        //return;
                    }
                }
                if (var->hp <= 0)
                {
                    system("cls");
                    list.erase(var);
                    DrawImage("Hero.txt");
                    std::cout<<"\n\n Zabiles potwora!\n";
                    Sleep(2000);
                    return;
                }
                if (hero.hp <= 0)
                {
                    system("cls");
                    DrawImage("Monster_Wins.txt");
                    Sleep(2000);
                    return;
                }

            }
        }
    }
}



#endif
