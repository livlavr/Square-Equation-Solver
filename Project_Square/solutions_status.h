#ifndef SOLUTIONS_STATUS_H
#define SOLUTIONS_STATUS_H

enum NUMBER_OF_SOLUTIONS
{
    ZERO_SOLUTIONS        =  0,
    ONE_SOLUTION          =  1,
    TWO_SOLUTIONS         =  2,
    INFINITY_OF_SOLUTIONS = -1,
    INVALID               = -2
};

struct ROOTS
{
    NUMBER_OF_SOLUTIONS count_solutions;
    double x1;
    double x2;
};

#endif
