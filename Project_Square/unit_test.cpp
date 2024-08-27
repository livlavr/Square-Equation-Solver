#include <stdio.h>
#include <math.h>

#include "solutions_status.h"
#include "double_compare.h"
#include "unit_test.h"
#include "solve_equation.h"
#include "color_print.h"

const int NUMBER_OF_TESTS = 8;

bool compare_results(const TEST_PARAMETERS* test, ROOTS answer)
{
    if (test->count_solutions_exp == answer.count_solutions)
    {
        switch(test->count_solutions_exp)
        {
            case ZERO_SOLUTIONS:
                return (isnan(answer.x1) && isnan(answer.x2));
                break;
            case INFINITY_OF_SOLUTIONS:
                return (isnan(answer.x1) && isnan(answer.x2));
                break;
            case ONE_SOLUTION:
                return ((double_comparing(test->x1_exp, answer.x1) == EQUAL)
                        && isnan(answer.x2));
                break;
            case TWO_SOLUTIONS:
                return ((double_comparing(test->x1_exp, answer.x1) == EQUAL) &&
                        (double_comparing(test->x2_exp, answer.x2) == EQUAL));
                break;
            case INVALID:
                return false;
                break;
            default:
                return false;
        }
    }
    else
    {
        return false;
    }
}

bool run_test(const TEST_PARAMETERS* test)
{
    ROOTS answer = {INVALID, NAN, NAN};

    answer.count_solutions = solve_equation(test->a, test->b, test->c, &answer);
    if (compare_results(test, answer))
    {
        printf("TEST №%d STATUS ", test->number_of_test);
        color_print(GREEN_TEXT , BOLD, "%s", "CORRECT\n\n");

        return true;
    }
    else
    {
        printf("TEST №%d STATUS ", test->number_of_test);
        color_print(RED_TEXT   , BOLD, "%s", "WRONG\a\n");
        color_print(GREEN_TEXT , BOLD, "%s", "\tEXPECT");
        printf(": count_solutions_exp = %d\tx1_exp = %lg\tx2_exp = %lg\n",
                test->count_solutions_exp, test->x1_exp, test->x2_exp);
        color_print(YELLOW_TEXT, BOLD, "%s", "\tRESULT");
        printf(": count_solutions     = %d\tx1     = %.4lg\tx2     = %.4lg\n",
                answer.count_solutions, answer.x1, answer.x2);

        return false;
    }
}

void run_testing_system(){
    TEST_PARAMETERS array_of_tests[NUMBER_OF_TESTS] =
    {
       {.number_of_test      = 0,
        .count_solutions_exp = INFINITY_OF_SOLUTIONS,
        .a                   = 0,
        .b                   = 0,
        .c                   = 0,
        .x1_exp              = NAN,
        .x2_exp              = NAN},

       {.number_of_test      = 1,
        .count_solutions_exp = ZERO_SOLUTIONS,
        .a                   = 0,
        .b                   = 0,
        .c                   = 1,
        .x1_exp              = NAN,
        .x2_exp              = NAN},

       {.number_of_test      = 2,
        .count_solutions_exp = ONE_SOLUTION,
        .a                   = 0,
        .b                   = 1,
        .c                   = 0,
        .x1_exp              = 0,
        .x2_exp              = NAN},

       {.number_of_test      = 3,
        .count_solutions_exp = ONE_SOLUTION,
        .a                   = 1,
        .b                   = 0,
        .c                   = 0,
        .x1_exp              = 0,
        .x2_exp              = NAN},

       {.number_of_test      = 4,
        .count_solutions_exp = ZERO_SOLUTIONS,
        .a                   = 1.5,
        .b                   = 1.5,
        .c                   = 1.5,
        .x1_exp              = NAN,
        .x2_exp              = NAN},

       {.number_of_test      =  5,
        .count_solutions_exp =  ONE_SOLUTION,
        .a                   =  0,
        .b                   =  4,
        .c                   =  3,
        .x1_exp              = -0.75,
        .x2_exp              =  NAN},

       {.number_of_test      =  6,
        .count_solutions_exp =  TWO_SOLUTIONS,
        .a                   = -3,
        .b                   = -5.7,
        .c                   =  0,
        .x1_exp              = -1.9,
        .x2_exp              =  0},

       {.number_of_test      =  7,
        .count_solutions_exp =  TWO_SOLUTIONS,
        .a                   =  1,
        .b                   =  5,
        .c                   = -4,
        .x1_exp              =  0.7016,
        .x2_exp              = -5.702}
    };

    for (int i = 0; i < NUMBER_OF_TESTS; ++i)
    {
        printf("TEST №%d STATUS running...\n", i);
        run_test(&array_of_tests[i]);
    }
}
