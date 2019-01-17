#include <array>
#include <iostream>
#include <vector>

void Search(const std::array<std::array<int, 100>, 100> &map, int x0, int y0, int x1, int y1, std::vector<std::pair<int, int>> *path, bool *found)
{
    for (auto p : *path)
    {
        if (x0 == p.first && y0 == p.second)
        {
            std::cout << "second visited" << std::endl;
            return;
        }
    }
    if (x0 >= 100 || y0 >= 100 || x0 < 0 || y0 < 0)
    {
        std::cout << "out map" << std::endl;
        return;
    }
    if (*found)
    {
        std::cout << "return" << std::endl;
        return;
    }
    if (x0 == x1 && y0 == y1)
    {
        std::cout << "found a path" << std::endl;
        *found = true;
        return;
    }
    if (map[x0][y0] == 1)
    {
        return; // has obstacle
    }

    std::cout << "move on:" << x0 << "," << y0 << std::endl;
    path->push_back({x0, y0});
    
    Search(map, x0 + 1, y0, x1, y1, path, found);
    Search(map, x0, y0 + 1, x1, y1, path, found);
    Search(map, x0 - 1, y0, x1, y1, path, found);
    Search(map, x0, y0 - 1, x1, y1, path, found);
}
int main(int argc, char const *argv[])
{
    std::array<std::array<int, 100>, 100> map;
    for (int i = 0; i < 70; i++)
    {
        map[10][i] = 1;
    }
    std::vector<std::pair<int, int>> path;
    bool found = false;
    Search(map, 0, 0, 50, 50, &path, &found);
    if (found)
    {
        for (auto p : path)
        {
            std::cout << p.first << "," << p.second << std::endl;
        }
    }
    return 0;
}
