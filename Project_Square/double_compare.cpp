#include <stdio.h>
#include <math.h>

#include "double_compare.h"

int coefficient_check_finite(double a, double b, double c)
{
    return isfinite(a) && isfinite(b) && isfinite(c);
}

DOUBLE_COMPARE double_comparing(double a, double b){
    if (fabs(a - b) <= EPS)
    {
        return EQUAL;
    }
    else if (a > b + EPS)
    {
        return MORE;
    }
    else
    {
        return LESS;
    }
}
