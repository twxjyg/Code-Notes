#include "geometry_types.h"
#include <vector>
#include <iostream>

bool IsCrossing(const geometry_types::Pose2D &start1,
                const geometry_types::Pose2D &end1,
                const geometry_types::Pose2D &start2,
                const geometry_types::Pose2D &end2)
{
    double line1_a = (end1.y - start1.y) / (end1.x - start1.y);
    double line1_b = start1.y - line1_a * start1.x;

    double line2_a = (end2.y - start2.y) / (end2.x - start2.y);
    double line2_b = start2.y - line2_a * start2.x;

    // judge segment1 crossing line2
    bool start1_down = line2_a * start1.x + line2_b - start1.y >= 0 ? true : false;
    bool end1_down = line2_a * end1.x + line2_b - end1.y >= 0 ? true : false;

    bool seg1_crossing_line2 = !(start1_down & end1_down);

    // judge segment2 crossing line1
    bool start2_down = line1_a * start2.x + line1_b - start2.y >= 0 ? true : false;
    bool end2_down = line1_a * end2.x + line1_b - end2.y >= 0 ? true : false;

    bool seg2_crossing_line1 = !(start2_down & end2_down);

    if (seg1_crossing_line2 && seg2_crossing_line1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool IsCrossing(const std::vector<geometry_types::Pose2D> &curve1,
                const std::vector<geometry_types::Pose2D> &curve2)
{
    for (unsigned int i = 1; i < curve1.size(); i++)
    {
        for (unsigned int j = 1; j < curve2.size(); j++)
        {
            if (IsCrossing(curve1[i - 1], curve1[i], curve2[j - 1], curve2[j]))
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    // given to curve, judge whether they intersect each other
    std::vector<geometry_types::Pose2D> discrete_curve1 = {
        {0, 0, 0},
        {1, 1, 0},
        {2, 1.9, 0},
        {3, 2.8, 0},
        {4, 3.7, 0},
        {5, 4.6, 0},
        {6, 5.5, 0}};

    std::vector<geometry_types::Pose2D> discrete_curve2 = {
        {1, 0, 0},
        {2, 3, 0},
        {3, 6, 0},
        {4, 8, 0},
        {5, 9, 0},
        {6, 12, 0},
        {7, 15, 0}};

    bool crossing = IsCrossing(discrete_curve1, discrete_curve2);
    std::cout << (crossing ? "yes" : "no") << std::endl;
    return 0;
}
