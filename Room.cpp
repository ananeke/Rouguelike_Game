#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <ctime>

std::array<std::string, 6> thing {"Sword","Armor","Boots","Ring","Shield","Gloves"};
std::array<std::string, 3> good_prefix {"Good","Magic","Legendary"};
std::array<std::string, 3> bad_prefix {"Bad","Broken","Cursed"};

class Stuff
{
    std::string name;

public:
    Stuff()
    {
        //randomowe wybieranie nagrody
        int index = rand() % 6;
        this->name = thing[index];
    }
};

class Precious: public Stuff
{
    std::string name_good_prefix;

public:
    Precious()
    {
        srand(time(NULL));
        int index = rand() % 3;
        this->name_good_prefix = good_prefix[index];
        std::cout<<name_good_prefix<<std::endl;
    }
};

class Room
{
    bool room_open = true;
    bool road_open = false;

};


int main(int argc, char const *argv[]) {

    Precious S;
    //S.Print();

    for(const auto &v: thing)
        std::cout << v << " ";
    std::cout << std::endl;
    return 0;
}
