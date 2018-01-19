#include <iostream>

using namespace std;

int map[10][10];

int main(int argc, char* argv[])
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (j == 10-1)
            {
                cout << '_'<<'|'<<endl;
            }
            else
            {
                cout << '_';
            }
        }
    }

    return 0;
}
