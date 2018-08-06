#include "geometry_types.h"
#include <vector>

bool IsIntersected(const geometry_types::Pose2D &start1,
                   const geometry_types::Pose2D &end1,
                   const geometry_types::Pose2D &start2,
                   const geometry_types::Pose2D &end2)
{
    
}
bool IsIntersected(const std::vector<geometry_types::Pose2D> &curve1,
                   const std::vector<geometry_types::Pose2D> &curve2)
{
    for (unsigned int i = 1; i < curve1.size(); i++) {
        for (unsigned int j = 1; j < curve2.size(); j++) {
            if (IsIntersected(curve1[i-1], curve1[i], curve2[j-1], curve2[j])) {
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

    bool intersected = IsIntersected(discrete_curve1, discrete_curve2);
    return 0;
}
