#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "PLAYER.h"
#define MAPSIZE 24

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
            {
                map[i][j] = 0;
            }
        }
    }

    void DrawMap()
    {
        for (int i = 0; i < MAPSIZE; ++i)
        {
            for (int j = 0; j < MAPSIZE; ++j)
            {
                if (map[i][j] == 0 && j == MAPSIZE-1)
                {
                    cout <<'_' <<'|'<<endl;
                }
                else if (map[i][j] == 0)
                {
                    cout <<'_';
                }
                else if (map[i][j] == 1)
                {
                    cout << 'G';
                }
                else if (map[i][j] == 2)
                {
                    cout << 'P';
                }
            }
        }
    }

    void UpdateMap(Hero &hero, list<Monster> &list)
    {
        map[hero.position[0]][hero.position[1]] = 1;

        if (!list.empty())
        {
            for (Monster var : list)
            {
                map[var.position[0]][var.position[1]] = 2;
            }
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
    }
};

#endif
