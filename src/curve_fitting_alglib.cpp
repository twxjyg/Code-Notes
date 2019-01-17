#include <iostream>
#include <libalglib/stdafx.h>
#include <libalglib/interpolation.h>
#include "geometry_types.h"
#include <array>
#include <vector>

using namespace alglib;
using geometry_types::Pose2D;

std::vector<Pose2D> AlglibSmooth(const std::vector<Pose2D> &data)
{
    using namespace alglib;
    const std::size_t n = data.size();
    std::vector<double> raw_x(n);
    std::vector<double> raw_y(n);
    std::vector<double> raw_theta(n);
    for (unsigned int i = 0; i < n; i++)
    {
        raw_x[i] = data[i].x;
        raw_y[i] = data[i].y;
        raw_theta[i] = data[i].theta;
    }
    ae_int_t info;
    double v;
    spline1dinterpolant s_x_y;
    spline1dinterpolant s_x_theta;
    spline1dfitreport rep_x_y;
    spline1dfitreport rep_x_theta;
    double rho = -5.0;
    const auto ae_int_n = static_cast<ae_int_t>(n);
    real_1d_array x, y, theta;
    x.setcontent(ae_int_n, raw_x.data());
    y.setcontent(ae_int_n, raw_y.data());
    theta.setcontent(ae_int_n, raw_theta.data());
    spline1dfitpenalized(x, y, 50, rho, info, s_x_y, rep_x_y);
    spline1dfitpenalized(x, theta, 50, rho, info, s_x_theta, rep_x_theta);
    std::vector<Pose2D> smoothed_data;
    smoothed_data.resize(n);
    for (unsigned int i = 0; i < n; i++)
    {
        smoothed_data[i].x = data[i].x;
        smoothed_data[i].y = spline1dcalc(s_x_y, data[i].x);
        smoothed_data[i].theta = spline1dcalc(s_x_theta, data[i].x);
    }
    return smoothed_data;
}

std::vector<double> PolynomialFit(const std::vector<geometry_types::Pose2D> &data, const int order)
{
    real_1d_array x;
    x.setlength(data.size());
    real_1d_array y;
    y.setlength(data.size());
    real_1d_array w;
    w.setlength(data.size());
    for (unsigned int i = 0; i < data.size(); i++)
    {
        x[i] = data[i].x;
        y[i] = data[i].y;
        w[i] = 1;
    }
    real_1d_array xc = "[0]";
    real_1d_array yc = "[0]";
    integer_1d_array dc = "[0]";
    ae_int_t m = order;
    ae_int_t info;
    barycentricinterpolant p;
    polynomialfitreport rep;
    // output is barycentric form
    polynomialfitwc(x, y, w, xc, yc, dc, m, info, p, rep);
    real_1d_array coefs;
    // convert to coefficient form
    polynomialbar2pow(p, coefs);
    if (info == 1) {
        std::cout << "fitting is successful" << std::endl;
    }
    // 4 is accuracy
    std::cout << coefs.tostring(4) << std::endl;
    std::vector<double> ret_coefs;
    ret_coefs.resize(order);
    std::string formular_vis = "f(x) = ";
    for (unsigned int i = 0; i < order; i++)
    {
        ret_coefs[i] = coefs[i];
        formular_vis += std::to_string(coefs[i]) + " * x{" + std::to_string(i) + "}" + (i == order-1 ? "":" + ");
    }
    std::cout << formular_vis << std::endl;
    ret_coefs.push_back(data.front().x);
    ret_coefs.push_back(data.back().x);
    std::cout << "[" << data.front().x << "," << data.back().x << "]" << std::endl;
    return ret_coefs;
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
    std::vector<double> coefs = PolynomialFit(data, 4);

    return 0;
}
