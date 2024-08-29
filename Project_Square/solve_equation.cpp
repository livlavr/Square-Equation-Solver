#include <stdio.h>
#include <math.h>

#include "solutions_status.h"
#include "double_compare.h"
#include "solve_equation.h"
#include "check_expression.h"

int solve_equation(double a, double b, double c, ROOTS* answer)
{
    check_expression(&answer     != NULL, POINTER_IS_NULL);
    check_expression(&answer->x1 != NULL, POINTER_IS_NULL);
    check_expression(&answer->x2 != NULL, POINTER_IS_NULL);

    switch(find_type_of_square(a))
    {
        case LINEAR:
            return solve_linear(b, c, answer);
        case SQUARE:
            return solve_square(a, b, c, answer);
        default:
            printf("ERROR: solve_equation");

            return INVALID;
    }
}

int find_type_of_square(double a)
{
    check_expression(!isnan(a), DOUBLE_IS_NAN);

    if (double_comparing(a, 0) == EQUAL)
    {
        return LINEAR;
    }
    else
    {
        return SQUARE;
    }
}

int solve_linear(double b, double c, ROOTS * answer)
{
    check_expression(answer != NULL, POINTER_IS_NULL);
    check_expression(&answer->x1 != NULL, POINTER_IS_NULL);

    if (double_comparing(b, 0) == EQUAL)
    {
        return (double_comparing(c, 0) == EQUAL) ? INFINITY_OF_SOLUTIONS : ZERO_SOLUTIONS;
    }
    else
    {
        if (double_comparing(c, 0) != EQUAL)
        {
            answer->x1 = -c/b;
        }
        else
        {
            answer->x1 = 0;
        }
        return ONE_SOLUTION;
    }
}

int solve_square(double a, double b, double c, ROOTS * answer)
{
    check_expression(answer != NULL, POINTER_IS_NULL);

    double d = b*b - 4*a*c;

    if (double_comparing(d, 0) == EQUAL)
    {
        if (double_comparing(b, 0) != EQUAL)
        {
            answer->x1 = -b/(2*a);
        }
        else
        {
            answer->x1 = 0;
        }
        return ONE_SOLUTION;
    }
    else if (double_comparing(d, 0) == MORE)
    {
        double sqrt_d = sqrt(d);
        answer->x1 = (-b + sqrt_d)/(2*a);
        answer->x2 = (-b - sqrt_d)/(2*a);
        if (double_comparing(c, 0) == EQUAL)
        {
            if (double_comparing(answer->x1, 0) == EQUAL)
            {
                answer->x1 = 0;
            }
            else
            {
                answer->x2 = 0;
            }
        }
        return TWO_SOLUTIONS;
    }
    else
    {
        return ZERO_SOLUTIONS;
    }
}
