#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "parameters.h"
#include "double_compare.h"
#include "unit_test.h"
#include "solve_equation.h"
#include "user_communication.h"

int main()
{
    double a = NAN, b = NAN, c = NAN;
    ROOTS answer = {INVALID, NAN, NAN};

    if (!test_or_user_input())
    {
        user_input(&a, &b, &c);
        NUMBER_OF_SOLUTIONS count_solutions = solve_equation(a, b, c, &answer);
        result_output(count_solutions, answer);
    }
    else
    {
        run_testing_system();
    }
}
