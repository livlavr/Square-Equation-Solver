#include <stdio.h>
#include <math.h>
#include <assert.h>

const int NUMBER_OF_COEFFICIENT = 3;
const double EPS = 0.01;

enum NUMBER_OF_SOLUTIONS
{
    ZERO_SOLUTIONS        = 0,
    ONE_SOLUTION          = 1,
    TWO_SOLUTIONS         = 2,
    INFINITY_OF_SOLUTIONS = -1,
    INVALID = -2
};

enum TYPES_OF_EQUATION
{
    LINEAR              = 0,
    SQUARE              = 1
};

TYPES_OF_EQUATION find_type_of_square(double a, double b, double c);
NUMBER_OF_SOLUTIONS solve_equation(double a, double b, double c, double* x1, double* x2);
NUMBER_OF_SOLUTIONS solve_square(double a, double b, double c, double* x1, double* x2);
NUMBER_OF_SOLUTIONS solve_linear(double b, double c, double* x1);
void user_input(double* a, double* b, double* c);
void result_output(NUMBER_OF_SOLUTIONS count_solutions, double x1, double x2);
//int run_testing_system(void);
//int run_test(int count_test, a, b, c, );

int main()
{
    double a = NAN, b = NAN, c = NAN;
    double x1 = 0, x2 = 0;

    user_input(&a, &b, &c);
    NUMBER_OF_SOLUTIONS count_solutions = solve_equation(a, b, c, &x1, &x2);
    result_output(count_solutions, x1, x2);
}

void user_input(double* a, double* b, double* c)
{
    int input_count = 0;

    printf("Введите коэффиценты квадратного уравнения: a b c\n");
    while ((input_count = scanf("%lg%lg%lg", &*a, &*b, &*c)) != NUMBER_OF_COEFFICIENT)
    {
        for (int i = 0; i < NUMBER_OF_COEFFICIENT - input_count; ++i)
        {
            scanf("%*s");
        }
        printf("Упс, похоже вы ввели неправильные значения\n");
        printf("Попробуйте ещё раз\n");
    }

    assert(*a != NAN); // TODO use ifs for user input
    assert(*b != NAN); // TODO use isnan() isinf() and isfinite() (read in K&R)
    assert(*c != NAN);
}

void result_output(NUMBER_OF_SOLUTIONS count_solutions, double x1, double x2)
{
    switch (count_solutions)
    {
        case ZERO_SOLUTIONS:
            printf("Уравнение не имеет решений\n");
            break;
        case ONE_SOLUTION:
            printf("Уравнение имеет одно решение: x1 = %lg\n", x1);
            break;
        case TWO_SOLUTIONS:
            printf("Уравнение имеет два решения:\n"
                    "x1 = %lg\tx2 = %lg\n", x1, x2);
            break;
        case INFINITY_OF_SOLUTIONS:
            printf("Уравнение имеет бесконечное количество решений\n");
            break;
        default:
            printf("ERROR: count_solutions = %d\n", count_solutions);
    }
}

NUMBER_OF_SOLUTIONS solve_equation(double a, double b, double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);

    switch(find_type_of_square(a, b, c))
    {
        case LINEAR:
            return solve_linear(b, c, x1);
        case SQUARE:
            return solve_square(a, b, c, x1, x2);
        default:
            printf("ERROR: solve_equation");

            return INVALID;
    }
}

TYPES_OF_EQUATION find_type_of_square(double a, double b, double c)
{
    if (fabs(a) <= EPS)
    {
        return LINEAR;
    }
    else
    {
        return SQUARE;
    }
}

NUMBER_OF_SOLUTIONS solve_linear(double b, double c, double* x1)
{
    assert(x1 != NULL);

    if (fabs(b) <= EPS)
    {
        return (fabs(c) <= EPS) ? INFINITY_OF_SOLUTIONS : ZERO_SOLUTIONS;
    }
    else
    {
        *x1 = -c/b;

        return ONE_SOLUTION;
    }
}

NUMBER_OF_SOLUTIONS solve_square(double a, double b, double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);

    double d = b*b - 4*a*c;

    if (fabs(d) < EPS)
    {
        *x1 = -b/(2*a);

        return ONE_SOLUTION;
    }
    else if (d > EPS)
    {
        double sqrt_d = sqrt(d);
        *x1 = (-b + sqrt_d)/(2*a);
        *x2 = (-b - sqrt_d)/(2*a);

        return TWO_SOLUTIONS;
    }
    else
    {
        return ZERO_SOLUTIONS;
    }
}
