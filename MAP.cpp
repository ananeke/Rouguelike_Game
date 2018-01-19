#include <iostream>

using namespace std;

class Map
{
    int map[12][12];

public:
    Map()
    {
        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 12; ++j)
            {
                map[i][j] = 0;
            }
        }
    }

    void DrawMap()
    {
        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 12; ++j)
            {
                if (j == 12-1)
                {
                    cout << map [i][j] <<'|'<<endl;
                }
                else
                {
                    cout << map[i][j];
                }
            }
        }
    }
};

int main(int argc, char* argv[])
{
    Map M1;
    M1.DrawMap();

    return 0;
}
