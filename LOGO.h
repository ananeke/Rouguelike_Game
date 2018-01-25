#ifndef LOGO_H
#define LOGO_H
#include <iostream>
#include <fstream>
#include <string>

void Draw_Logo()
{
    std::fstream logo;
    logo.open("logo.txt");
    std::string line;

    do
    {
        std::getline(logo, line);
        std::cout << line << "\n";
    } while (line !="");

    logo.close();
}

void Draw_Hero()
{
    std::fstream hero;
    hero.open("Hero.txt");
    std::string line;

    do
    {
        std::getline(hero, line);
        std::cout << line << "\n";
    } while (line !="");

    hero.close();
}


#endif
