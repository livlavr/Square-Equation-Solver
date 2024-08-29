#include <stdio.h>
#include <math.h>

#include "solutions_status.h"
#include "user_communication.h"
#include "solve_equation.h"
#include "manual_mode.h"

void manual_mode(double* a, double* b, double* c, ROOTS* answer)
{
    user_input(a, b, c);
    int count_solutions = 0;
    count_solutions = solve_equation(*a, *b, *c, answer);
    result_output(count_solutions, *answer);
    if (!isnan(answer->x1))
    {
        check(answer->x1);
    }
    if (!isnan(answer->x2))
    {
        check(answer->x2);
    }
}
