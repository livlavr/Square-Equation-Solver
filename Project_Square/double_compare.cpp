#include <stdio.h>
#include <math.h>

#include "double_compare.h"
#include "check_expression.h"

bool coefficient_check_finite(double a, double b, double c)
{
    return (isfinite(a) && isfinite(b) && isfinite(c));
}

DOUBLE_COMPARE double_comparing(double a, double b){
    check_expression(!isnan(a), WRONG_COMPARE);
    check_expression(!isnan(b), WRONG_COMPARE);

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
