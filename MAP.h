#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <ctime>
#include <list>
#include "PLAYER.h"
#include "BATTLE.h"
#define MAPSIZE 12

using namespace std;

class Map
{
    int map[MAPSIZE][MAPSIZE];

public:
    Map()
    {
        for (int i = 0; i < MAPSIZE; ++i)
        {
            for (int j = 0; j < MAPSIZE; ++j)
                map[i][j] = 0;
        }
    }

    void DrawMap()
    {
        for (int i = 0; i < MAPSIZE; ++i)
        {
            for (int j = 0; j < MAPSIZE; ++j)
            {
                if (map[i][j] == 0 && j == MAPSIZE-1)
                    cout <<'_' <<'|'<<endl;
                else if (map[i][j] == 0)
                    cout <<'_';
                else if (map[i][j] == 1 && j == MAPSIZE-1)
                    cout << 'H'<<endl;
                else if (map[i][j] == 1)
                    cout << 'H';
                else if (map[i][j] == 2 && j == MAPSIZE-1)
                    cout << 'M'<<endl;
                else if (map[i][j] == 2)
                    cout << 'M';
            }
        }
    }

    void UpdateMap(Hero &hero, list<Monster> &list)
    {
        map[hero.position[0]][hero.position[1]] = 1;

        if (!list.empty())
        {
            for (Monster var : list)
                map[var.position[0]][var.position[1]] = 2;
        }
    }

    void MoveHero(Hero &hero, char &move)
    {
        map[hero.position[0]][hero.position[1]] = 0;
        switch (move)
        {
        case 'w':
            hero.position[0] -= 1;
            break;
        case 'd':
            hero.position[1] += 1;
            break;
        case 's':
            hero.position[0] += 1;
            break;
        case 'a':
            hero.position[1] -= 1;
            break;
        }
        if (hero.position[0] >= MAPSIZE)
            hero.position[0] = MAPSIZE - 1;
        else if (hero.position[1] >= MAPSIZE)
            hero.position[1] = MAPSIZE - 1;
        else if (hero.position[0] < 0)
            hero.position[0] = 0;
        else if (hero.position[1] < 0)
            hero.position[1] = 0;
    }

    void MoveMonster(Hero &hero, list<Monster> &list)
    {
        if (!list.empty())
        {
            for (std::list<Monster>::iterator var = list.begin(); var != list.end(); ++var)
            {
                map[var->position[0]][var->position[1]] = 0;

                if (((hero.position[0] == var->position[0])&&(hero.position[1] == var->position[1]))||((var->position[0] == hero.position[0])&&(var->position[1] == hero.position[1])))
                {
                    StartBattle(hero, list);
                }
                else
                {
                    if (rand() % 2 == 1)
                    {
                        if (var->position[1] > hero.position[1])
                        {
                            var->position[1] -= 1;
                            std::cout<<var->position[0]<<" "<<var->position[1];
                        }
                        else
                        {
                            var->position[1] += 1;
                            std::cout<<var->position[0]<<" "<<var->position[1];
                        }
                    }
                    else
                    {
                        if (var->position[0] > hero.position[0])
                            var->position[0] -= 1;
                        else
                            var->position[0] += 1;
                    }
                }
            }
        }
    }
};

#endif
