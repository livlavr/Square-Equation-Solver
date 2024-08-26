#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solutions_status.h"
#include "double_compare.h"
#include "user_communication.h"

void user_input(double* a, double* b, double* c)
{
    int input_count = 0, character = 0;

    printf("Enter the number of the square equation: a b c\n");
    while (((input_count = scanf("%lg%lg%lg", a, b, c)) != NUMBER_OF_COEFFICIENT) ||
            !coefficient_check_finite(*a, *b, *c) || !(((character = getchar()) == '\n')
            || character == ' ' || character == '\t'))
    {
        while ((character = getchar()) != '\n'){}
        printf("Oops, it looks like you entered the wrong values\n");
        printf("Try again\n");
        *a = NAN;
        *b = NAN;
        *c = NAN;
    }
}

void result_output(NUMBER_OF_SOLUTIONS count_solutions, ROOTS answer)
{
    switch (count_solutions)
    {
        case ZERO_SOLUTIONS:
            printf("Equation has no solution\n");
            break;
        case ONE_SOLUTION:
            printf("The equation has one solution: x1 = %.4lg\n", answer.x1);
            break;
        case TWO_SOLUTIONS:
            printf("The equation has two solutions:\n x1 = %.4lg\tx2 = %.4lg\n",
            ((double_comparing(answer.x1, answer.x2) == LESS)? answer.x1 : answer.x2),
            ((double_comparing(answer.x1, answer.x2) == MORE)? answer.x1 : answer.x2));
            break;
        case INFINITY_OF_SOLUTIONS:
            printf("Equation has infinite number of solutions\n");
            break;
        case INVALID:
            printf("Equation INVALID\n");
            break;
        default:
            printf("ERROR: count_solutions = %d\n", count_solutions);
    }
}

bool test_or_user_input()
{
    printf("Run the test - Enter\n");
    printf("Run the user input something else\n");
    if ((getchar()) == '\n')
    {
        return true;
    }
    else
    {
        while(getchar() != '\n');

        return false;
    }
}
