#include <libalglib/stdafx.h>
#include <libalglib/optimization.h>

#include <math.h>

using namespace alglib;

main(int argc, char const *argv[])
{
    // target optimization function: F(x, y) = x^2 + y^2 -6*x -4*y,
    // subject to bound constraints 0 <= x <= 2.5, 0<= y <= 2.5
    // expected solution is [x, y] = [2.5, 2]
    // transform the function to QP target form: F(x, y) = 0.5 *(2*x^2 + 2*y^2) + ((-6)*x + (-4)*y)
    // and accroding yo QP target function: f(x) = 0.5*x'*A*x + b'*x
    // we have A:
    // [[2, 0];[0,2]]
    // we have b:
    // [-6, -4]
    // we have our x matrix:
    // [x, y]
    // we give a initial guess for [x, y]:
    // [1,0]
    // we have upper bound matrix:
    // [2.5, 2.5]
    // we have lower bound matrix:
    // [0, 0]
    real_2d_array A = "[[2,0],[0,2]]";
    real_1d_array b = "[-6,-4]";
    real_1d_array initial_guess = "[1, 0]";
    real_1d_array bound_upper = "[2.5, 2.5]";
    real_1d_array bound_lower = "[0,0]";
    real_1d_array scale = "[1, 1]";

    // create solver, set quadratic/linear terms
    minqpstate state;
    minqpcreate(2, state);
    minqpsetquadraticterm(state, A);
    minqpsetlinearterm(state, b);
    minqpsetstartingpoint(state, initial_guess);
    minqpsetbc(state, bound_lower, bound_upper);

    // Set scale of the parameters.
    // It is strongly recommended that you set scale of your variables.
    // Knowing their scales is essential for evaluation of stopping criteria
    // and for preconditioning of the algorithm steps.
    // You can find more information on scaling at http://www.alglib.net/optimization/scaling.php
    //
    // NOTE: for convex problems you may try using minqpsetscaleautodiag()
    //       which automatically determines variable scales.

    minqpsetscale(state, scale);
    //
    // Solve problem with QuickQP solver.
    //
    // This solver is intended for medium and large-scale problems with box
    // constraints (general linear constraints are not supported).
    //
    // Default stopping criteria are used, Newton phase is active.
    //
    minqpsetalgoquickqp(state, 0.0, 0.0, 0.0, 0, true);
    minqpoptimize(state);
    minqpreport report;
    real_1d_array result;
    minqpresults(state, result, report);

    std::cout << report.terminationtype << std::endl; // EXPECTED: 4

    std::cout << result.tostring(4) << std::endl; // EXPECTED: [2.5,2]

    // TODO: add other solver code example

    return 0;
}
