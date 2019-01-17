#include <eigen3/Eigen/Dense>
#include "geometry_types.h"
#include <vector>
#include <iostream>

// A * x = b
// A is filled with x_values
// b is filled with y_values
// x is our target [a_0, a_1, a_2, a_3]'
// householderQr this can help us sovle the matrix
// solve means to compute x at min{|Ax - b|}
std::vector<double> PolynomialFit(const std::vector<geometry_types::Pose2D> &data, const int order)
{

    // Pre-assumption check:
    Eigen::VectorXd x_values(data.size());
    Eigen::VectorXd y_values(data.size());
    for (unsigned int i = 0; i < data.size(); i++)
    {
        x_values(i) = data[i].x;
        y_values(i) = data[i].y;
    }
    assert(x_values.size() == y_values.size());
    assert(order >= 1 && order <= x_values.size() - 1);

    // Initialize polynomial matrix A:
    Eigen::MatrixXd A(x_values.size(), order + 1);

    // Build polynomial matrix A:
    for (int i = 0; i < x_values.size(); i++)
    {
        A(i, 0) = 1.0;
    }
    for (int j = 0; j < x_values.size(); j++)
    {
        for (int i = 0; i < order; i++)
        {
            A(j, i + 1) = A(j, i) * x_values(j);
        }
    }

    // Solve coefficients:
    auto Q = A.householderQr();
    auto result = Q.solve(y_values);
    std::vector<double> coeffs;
    std::stringstream text;
    text << "[";
    for (unsigned int i = 0; i < result.size(); i++)
    {
        text << result(i) << ",";
        coeffs.push_back(result(i));
    }
    coeffs.push_back(data.front().x);
    coeffs.push_back(data.back().x);
    text << data.front().x << ",";
    text << data.back().x << ",";
    text << "]";
    std::cout << text.str() << std::endl;
    return coeffs;
}
int main(int argc, char const *argv[])
{
    std::vector<geometry_types::Pose2D> data = {
        {-1, 1.0, 0.0},
        {0, 1.0, 0.0},
        {1.0, 2.0, 0.0},
        {1.5, 2.4, 0.0},
        {2.0, 2.5, 0.0},
        {2.5, 2.6, 0.0},
        {3.0, 3.0, 0.0}};
    // 3 is coefficient size
    std::vector<double> coefs = PolynomialFit(data, 3);
    return 0;
}
