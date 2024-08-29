#include <stdio.h>
#include <math.h>

#include "double_compare.h"
#include "check_expression.h"

bool coefficient_check_finite(double a, double b, double c)
{
    return (isfinite(a) && isfinite(b) && isfinite(c));
}

int double_comparing(double a, double b){
    check_expression(!isnan(a), DOUBLE_IS_NAN);
    check_expression(!isnan(b), DOUBLE_IS_NAN);

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
