#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <array>

class Hero
{
public:
    std::array<int, 10> back_pack;
    int points = 0;
    int position[2];
    int hp = 20;

    Hero(int x, int y)
    {
        position[0] = x; //kolumny
        position[1] = y; //wiersze
    }
};

class Monster
{
public:
    int position[2];
    int hp = 10;

    Monster(int x, int y)
    {
        position[0] = x;
        position[1] = y;
    }
};

#endif
