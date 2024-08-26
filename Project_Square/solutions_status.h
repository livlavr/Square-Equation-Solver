#ifndef SOLUTIONS_STATUS_H
#define SOLUTIONS_STATUS_H

/// @brief An enum type
/// Number of quadratic equation solutions
enum NUMBER_OF_SOLUTIONS
{
    ZERO_SOLUTIONS        =  0,
    ONE_SOLUTION          =  1,
    TWO_SOLUTIONS         =  2,
    INFINITY_OF_SOLUTIONS = -1,
    INVALID               = -2
};

/// @brief Struct that contains roots and number of quadratic equation solution
struct ROOTS
{
    NUMBER_OF_SOLUTIONS count_solutions; /**< Number of solutions*/
    double x1; /**< Root №1*/
    double x2; /**< Root №2*/
};

#endif
