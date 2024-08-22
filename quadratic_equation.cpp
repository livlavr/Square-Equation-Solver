#include <stdio.h>
#include <math.h>
#include <assert.h>

const int NUMBER_OF_COEFFICIENT = 3;
const int NUMBER_OF_TESTS       = 8;
const double EPS                = 0.001;

enum NUMBER_OF_SOLUTIONS
{
    ZERO_SOLUTIONS        = 0,
    ONE_SOLUTION          = 1,
    TWO_SOLUTIONS         = 2,
    INFINITY_OF_SOLUTIONS = -1,
    INVALID               = -2
};

enum TYPES_OF_EQUATION
{
    LINEAR = 0,
    SQUARE = 1
};

enum DOUBLE_COMPARE
{
    LESS  = -1,
    EQUAL = 0,
    MORE  = 1
};

struct ROOTS
{
    NUMBER_OF_SOLUTIONS count_solutions;
    double x1;
    double x2;
};

struct TEST_PARAMETERS
{
    int number_of_test;
    NUMBER_OF_SOLUTIONS count_solutions_exp;
    double a, b, c;
    double x1_exp, x2_exp;
};

TYPES_OF_EQUATION find_type_of_square(double a, double b, double c);
NUMBER_OF_SOLUTIONS solve_equation(double a, double b, double c, ROOTS* answer);
NUMBER_OF_SOLUTIONS solve_square(double a, double b, double c, ROOTS* answer);
NUMBER_OF_SOLUTIONS solve_linear(double b, double c, ROOTS* answer);
void user_input(double* a, double* b, double* c);
void result_output(NUMBER_OF_SOLUTIONS count_solutions, ROOTS answer);
int coefficient_check_finite(double a, double b, double c);
DOUBLE_COMPARE double_comparing(double a, double b);
void run_testing_system();
bool run_test(TEST_PARAMETERS* test);
bool compare_results(TEST_PARAMETERS* test, ROOTS answer);
bool test_or_user_input();

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

void user_input(double* a, double* b, double* c)
{
    int input_count = 0;

    printf("Enter the number of the square equation: a b c\n");
    while ((input_count = scanf("%lg%lg%lg", a, b, c)) != NUMBER_OF_COEFFICIENT
            && coefficient_check_finite(*a, *b, *c))
    {
        for (int i = 0; i < NUMBER_OF_COEFFICIENT - input_count; ++i)
        {
            scanf("%*s");
        }
        printf("Oops, it looks like you entered the wrong values\n");
        printf("Try again\n");
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
        default:
            printf("ERROR: count_solutions = %d\n", count_solutions);
    }
}

int coefficient_check_finite(double a, double b, double c)
{
    return isfinite(a) && isfinite(a) && isfinite(a);
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

NUMBER_OF_SOLUTIONS solve_equation(double a, double b, double c, ROOTS* answer)
{
    assert(answer != NULL);
    assert(&answer->x1 != NULL);
    assert(&answer->x2 != NULL);

    switch(find_type_of_square(a, b, c))
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

TYPES_OF_EQUATION find_type_of_square(double a, double b, double c)
{
    if (double_comparing(a, 0) == EQUAL)
    {
        return LINEAR;
    }
    else
    {
        return SQUARE;
    }
}

NUMBER_OF_SOLUTIONS solve_linear(double b, double c, ROOTS * answer)
{
    assert(answer != NULL);
    assert(&answer->x1 != NULL);

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

NUMBER_OF_SOLUTIONS solve_square(double a, double b, double c, ROOTS * answer)
{
    assert(answer != NULL);

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

bool compare_results(TEST_PARAMETERS* const test, ROOTS answer) // TODO const????
{
    if (test->count_solutions_exp == answer.count_solutions)
    {
        switch(test->count_solutions_exp)
        {
            case ZERO_SOLUTIONS:
                if (isnan(answer.x1) && isnan(answer.x2))
                {
                    return true;
                }
            case INFINITY_OF_SOLUTIONS:
                if (isnan(answer.x1) && isnan(answer.x2))
                {
                    return true;
                }
            case ONE_SOLUTION:
                if ((double_comparing(test->x1_exp, answer.x1) == EQUAL) && isnan(answer.x2))
                {
                    return true;
                }
            case TWO_SOLUTIONS:
                if ((double_comparing(test->x1_exp, answer.x1) == EQUAL) &&
                    (double_comparing(test->x2_exp, answer.x2) == EQUAL))
                {
                    return true;
                }
            case INVALID:
                return false;
            default:
                return false;
        }
    }
    else
    {
        return false;
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

bool run_test(TEST_PARAMETERS* const test)
{
    ROOTS answer = {INVALID, NAN, NAN};

    answer.count_solutions = solve_equation(test->a, test->b, test->c, &answer);
    if (compare_results(test, answer))
    {
        printf("TEST №%d STATUS CORRECT\n", test->number_of_test);

        return true;
    }
    else
    {
        printf("TEST №%d STATUS false\n", test->number_of_test);
        printf("\tRESULT: count_solutions     = %d\tx1     = %.4lg\tx2     = %.4lg\n",
                answer.count_solutions, answer.x1, answer.x2);
        printf("\tEXPECT: count_solutions_exp = %d\tx1_exp = %lg\tx2_exp = %lg\n",
        test->count_solutions_exp, test->x1_exp, test->x2_exp);

        return false;
    }
}

void run_testing_system(){
    TEST_PARAMETERS array_of_tests[NUMBER_OF_TESTS] =
    {
        {.number_of_test     = 1,
        .a                   = 0,
        .b                   = 0,
        .c                   = 0,
        .count_solutions_exp = INFINITY_OF_SOLUTIONS,
        .x1_exp              = NAN,
        .x2_exp              = NAN},

        {.number_of_test     = 2,
        .a                   = 0,
        .b                   = 0,
        .c                   = 1,
        .count_solutions_exp = ZERO_SOLUTIONS,
        .x1_exp              = NAN,
        .x2_exp              = NAN},

        {.number_of_test     = 3,
        .a                   = 0,
        .b                   = 1,
        .c                   = 0,
        .count_solutions_exp = ONE_SOLUTION,
        .x1_exp              = 0,
        .x2_exp              = NAN},

        {.number_of_test     = 4,
        .a                   = 1,
        .b                   = 0,
        .c                   = 0,
        .count_solutions_exp = ONE_SOLUTION,
        .x1_exp              = 0,
        .x2_exp              = NAN},

        {.number_of_test     = 5,
        .a                   = 1.5,
        .b                   = 1.5,
        .c                   = 1.5,
        .count_solutions_exp = ZERO_SOLUTIONS,
        .x1_exp              = NAN,
        .x2_exp              = NAN},

        {.number_of_test     = 6,
        .a                   = 0,
        .b                   = 4,
        .c                   = 3,
        .count_solutions_exp = ONE_SOLUTION,
        .x1_exp              = -0.75,
        .x2_exp              = NAN},

        {.number_of_test     = 7,
        .a                   = -3,
        .b                   = -5.7,
        .c                   = 0,
        .count_solutions_exp = TWO_SOLUTIONS,
        .x1_exp              = -1.9,
        .x2_exp              = 0},

        {.number_of_test     = 8,
        .a                   = 1,
        .b                   = 5,
        .c                   = -4,
        .count_solutions_exp = TWO_SOLUTIONS,
        .x1_exp              = 0.7016,
        .x2_exp              = -5.702}
    };

    for (int i = 0; i < NUMBER_OF_TESTS; ++i)
    {
        run_test(&array_of_tests[i]);
    }
}
