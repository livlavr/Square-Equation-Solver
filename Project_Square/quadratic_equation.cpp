#include <stdio.h>
#include <math.h>

#include "solutions_status.h"
#include "double_compare.h"
#include "user_communication.h"
#include "solve_equation.h"
#include "unit_test.h"
#include "check_expression.h"
#include "get_mode_flag.h"
#include "manual_mode.h"

int main(int argc, char *argv[])
{
    double a = NAN, b = NAN, c = NAN;
    ROOTS answer = {INVALID, NAN, NAN};
    switch(get_mode_flag(argc, argv))
    {
        case TEST:
        {
            run_testing_system();
            break;
        }
        case MANUAL:
        {
            manual_mode(&a, &b, &c, &answer);
            break;
        }
        default:
            return 1;
    }
}
