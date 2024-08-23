#ifndef DOUBLE_COMPARE_H
#define DOUBLE_COMPARE_H

const double EPS = 0.001;

enum DOUBLE_COMPARE
{
    LESS  = -1,
    EQUAL = 0,
    MORE  = 1
};

DOUBLE_COMPARE double_comparing(double a, double b);
int coefficient_check_finite(double a, double b, double c);

#endif
