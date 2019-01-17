#include "geometry_types.h"
#include <iostream>

using geometry_types::Vector2D;

int area2(int a_x, int a_y, int b_x, int b_y, int t_x, int t_y)
{
    return (a_x - t_x) * (b_y - t_y) - (a_y - t_y) * (b_x - t_x);
}
bool to_left(int a_x, int a_y, int b_x, int b_y, int t_x, int t_y)
{
    return area2(a_x, a_y, b_x, b_y, t_x, t_y) > 0;
}
bool to_left1(int a_x, int a_y, int b_x, int b_y, int t_x, int t_y)
{
    return Vector2D(a_x - t_x, a_y - t_y).cross(Vector2D(b_x - t_x, b_y - t_y)) > 0;
}

int main(int argc, char **argv)
{
    if (!to_left(0, 0, 10, 10, 5, 2))
    {
        std::cout << "right" << std::endl;
    }
    if (to_left1(0, 0, 10, 10, 2, 5))
    {
        std::cout << "left" << std::endl;
    }
    return 0;
}