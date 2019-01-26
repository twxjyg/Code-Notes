#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <limits>

struct Position
{
    double x;
    double y;
    bool operator==(const Position &other)
    {
        return x == other.x && y == other.y;
    }
};

void FindBounds(const std::vector<Position> &traj, double *max_x, double *max_y, double *min_x, double *min_y)
{
    *max_x = *max_y = std::numeric_limits<double>::min();
    *min_x = *min_y = std::numeric_limits<double>::max();
    for (const auto pos : traj)
    {
        if (pos.x >= *max_x)
        {
            *max_x = pos.x;
        }
        if (pos.x <= *min_x)
        {
            *min_x = pos.x;
        }
        if (pos.y >= *max_y)
        {
            *max_y = pos.y;
        }
        if (pos.y <= *min_y)
        {
            *min_y = pos.y;
        }
    }
}
double Distance(const Position &a, const Position &b)
{
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}
int main(int argc, char const *argv[])
{
    std::vector<Position> traj_1;
    std::vector<Position> traj_2;

    double max_x, max_y, min_x, min_y;
    max_x = max_y = std::numeric_limits<double>::min();
    min_x = min_y = std::numeric_limits<double>::max();
    FindBounds(traj_1, &max_x, &max_y, &min_x, &min_y);

    const double width = max_x - min_x;
    const double height = max_y - min_x;

    double d = 0.5;
    double D = 0.5;
    int resolution_x = (int)(width / (d / 2));
    int resolution_y = (int)(height / (d / 2));
    std::map<Position, std::vector<unsigned int>> sparse_grid;

    for (unsigned int i = 0; i < traj_1.size(); i++)
    {
        // transform coords to grid map origin
        const Position &grid_pos = {(int)((traj_1[i].x - min_x) / resolution_x),
                                    (int)((traj_1[i].y - min_y) / resolution_y)};
        if (sparse_grid.find(grid_pos) != sparse_grid.end())
        {
            sparse_grid[grid_pos].push_back(i);
        }
        else
        {
            sparse_grid[grid_pos] = {i};
        }
    }
    bool intersection_found = false;
    int traj_1_index = -1;
    for (const auto &pos : traj_2)
    {
        // transform coords to grid map origin
        const Position &grid_pos = {(int)((pos.x - min_x) / resolution_x),
                                    (int)((pos.y - min_y) / resolution_y)};
        if (sparse_grid.find(grid_pos) != sparse_grid.end())
        {
            intersection_found = true;
            break;
        }
        else
        {
            // checkoutt arround position
            const Position &l = {grid_pos.x - 1, grid_pos.y};
            const Position &r = {grid_pos.x + 1, grid_pos.y};
            const Position &u = {grid_pos.x, grid_pos.y + 1};
            const Position &b = {grid_pos.x, grid_pos.y - 1};
            const Position &lu = {grid_pos.x - 1, grid_pos.y + 1};
            const Position &ru = {grid_pos.x + 1, grid_pos.y + 1};
            const Position &lb = {grid_pos.x - 1, grid_pos.y - 1};
            const Position &rb = {grid_pos.x + 1, grid_pos.y - 1};
            if (sparse_grid.find(l) != sparse_grid.end())
            {
                for (const auto &index : sparse_grid[l])
                {
                    if (Distance(pos, traj_1[index]) < D)
                    {
                        intersection_found = true;
                        break;
                    }
                }
            }
            if (sparse_grid.find(r) != sparse_grid.end())
            {
                for (const auto &index : sparse_grid[r])
                {
                    if (Distance(pos, traj_1[index]) < D)
                    {
                        intersection_found = true;
                        break;
                    }
                }
            }
            if (sparse_grid.find(u) != sparse_grid.end())
            {
                for (const auto &index : sparse_grid[u])
                {
                    if (Distance(pos, traj_1[index]) < D)
                    {
                        intersection_found = true;
                        break;
                    }
                }
            }
            if (sparse_grid.find(b) != sparse_grid.end())
            {
                for (const auto &index : sparse_grid[b])
                {
                    if (Distance(pos, traj_1[index]) < D)
                    {
                        intersection_found = true;
                        break;
                    }
                }
            }
            if (sparse_grid.find(lu) != sparse_grid.end())
            {
                for (const auto &index : sparse_grid[lu])
                {
                    if (Distance(pos, traj_1[index]) < D)
                    {
                        intersection_found = true;
                        break;
                    }
                }
            }
            if (sparse_grid.find(ru) != sparse_grid.end())
            {
                for (const auto &index : sparse_grid[ru])
                {
                    if (Distance(pos, traj_1[index]) < D)
                    {
                        intersection_found = true;
                        break;
                    }
                }
            }
            if (sparse_grid.find(lb) != sparse_grid.end())
            {
                for (const auto &index : sparse_grid[lb])
                {
                    if (Distance(pos, traj_1[index]) < D)
                    {
                        intersection_found = true;
                        break;
                    }
                }
            }
            if (sparse_grid.find(rb) != sparse_grid.end())
            {
                for (const auto &index : sparse_grid[rb])
                {
                    if (Distance(pos, traj_1[index]) < D)
                    {
                        intersection_found = true;
                        break;
                    }
                }
            }
        }
    }
    std::cout << "intersetion found:" << intersection_found << std::endl;
    return 0;
}
