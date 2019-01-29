#include <vector>
#include <map>
#include <iostream>

std::vector<int> second_short_path(const std::map<int, std::vector<int>> &adjacency, int source, int target)
{
    static std::vector<int> curr_path;
    static std::vector<std::vector<int>> paths;
    curr_path.push_back(source);
    if (source == target)
    {
        int length = curr_path.size();
        if (paths.empty())
        {
            paths.insert(paths.begin(), curr_path);
        }
        else
        {
            if (length < paths.front().size())
            {
                paths.insert(paths.begin(), curr_path);
            }
            else
            {
                paths.push_back(curr_path);
            }
        }
        if (paths.size() > 2)
        {
            paths.pop_back();
        }
        return {};
    }
    auto next_targets = adjacency.at(source);
    for (auto next_target : next_targets)
    {
        second_short_path(adjacency, next_target, target);
        curr_path.pop_back();
    }
    if (paths.empty())
    {
        return {};
    }
    else
    {
        return paths.back();
    }
}
int main(int argc, char const *argv[])
{
    /*
    1-->2-->3-->6-->8
    |  |\    |   |  /\
    |  | \   |   |  |
    |  |  \ /   |   |
    | \/  \/   \/  |
    |  4-->5-->7-->9
    |______\__/\   /\
            \_____/
    */
    std::map<int, std::vector<int>> adjacency = {
        {1, {2, 7}},
        {2, {3, 4, 5}},
        {3, {6, 5}},
        {4, {5}},
        {5, {7, 9}},
        {6, {7, 8}},
        {7, {9}},
        {8, {}},
        {9, {8}}};
    std::vector<int> path = second_short_path(adjacency, 1, 9);
    for (auto vertex : path)
    {
        std::cout << vertex << "->";
    }
    std::cout << "(end)" << std::endl;
    return 0;
}
