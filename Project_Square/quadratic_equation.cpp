#include <stdio.h>
#include <math.h>

#include "solutions_status.h"
#include "double_compare.h"
#include "unit_test.h"
#include "solve_equation.h"
#include "user_communication.h"
#include "check_expression.h"
#include "flags_handling.h"

int main(int argc, char *argv[])
{
    double a = NAN, b = NAN, c = NAN;
    ROOTS answer = {INVALID, NAN, NAN};
    switch(flags_handling(argc, argv))
    {
        case TEST:
        {
            run_testing_system();
            break;
        }
        case MANUAL:
        {
            user_input(&a, &b, &c);
            int count_solutions = 0;
            count_solutions = solve_equation(a, b, c, &answer);
            result_output(count_solutions, answer);
            break;
        }
        default:
            return 0;
    }



    if (!test_or_user_input())
    {
        user_input(&a, &b, &c);
        int count_solutions = solve_equation(a, b, c, &answer);
        result_output(count_solutions, answer);
    }
    else
    {
        run_testing_system();
    }
}
