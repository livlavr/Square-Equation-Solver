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
    LINEAR = 0,
    SQUARE = 1
};

enum DOUBLE_COMPARE
{
    LESS = -1,
    EQUAL = 0,
    MORE = 1
};

enum TEST_STATUS
{
    FALSE = 0,
    CORRECT = 1
};

struct answer
{
    NUMBER_OF_SOLUTIONS count_solutions;
    double x1;
    double x2;
};

struct testing_system
{
    NUMBER_OF_SOLUTIONS count_solutions_exp;
    struct coefficient
    {
        double a, b, c;
    };
    struct roots
    {
        double x1_exp, x2_exp;
    };
};

TYPES_OF_EQUATION find_type_of_square(double a, double b, double c);
NUMBER_OF_SOLUTIONS solve_equation(double a, double b, double c, answer * ans);
NUMBER_OF_SOLUTIONS solve_square(double a, double b, double c, answer * ans);
NUMBER_OF_SOLUTIONS solve_linear(double b, double c, answer * ans);
void user_input(double* a, double* b, double* c);
void result_output(NUMBER_OF_SOLUTIONS count_solutions, answer ans);
int coefficient_check_finite(double a, double b, double c);
DOUBLE_COMPARE double_comparing(double a, double b);
//int run_testing_system(void);
TEST_STATUS run_test(int number_of_test, double a, double b, double c, NUMBER_OF_SOLUTIONS count_solutions_exp, double x1_exp, double x2_exp);
TEST_STATUS compare_results(NUMBER_OF_SOLUTIONS count_solutions_exp, double x1_exp, double x2_exp,
                    NUMBER_OF_SOLUTIONS count_solutions, double x1, double x2);

int main()
{
    double a = NAN, b = NAN, c = NAN;
    answer ans = {INVALID, NAN, NAN};

    // user_input(&a, &b, &c);
    // NUMBER_OF_SOLUTIONS count_solutions = solve_equation(a, b, c, &ans);
    // result_output(count_solutions, ans);
    run_test(1, 0, 0, 0, INFINITY_OF_SOLUTIONS, NAN, NAN);

}

void user_input(double* a, double* b, double* c)
{
    int input_count = 0;

    printf("Введите коэффиценты квадратного уравнения: a b c\n");
    while ((input_count = scanf("%lg%lg%lg", a, b, c)) != NUMBER_OF_COEFFICIENT
    && coefficient_check_finite(*a, *b, *c))
    {
        for (int i = 0; i < NUMBER_OF_COEFFICIENT - input_count; ++i)
        {
            scanf("%*s");
        }
        printf("Упс, похоже вы ввели неправильные значения\n");
        printf("Попробуйте ещё раз\n");
    }
}

void result_output(NUMBER_OF_SOLUTIONS count_solutions, answer ans)
{
    switch (count_solutions)
    {
        case ZERO_SOLUTIONS:
            printf("Уравнение не имеет решений\n");
            break;
        case ONE_SOLUTION:
            printf("Уравнение имеет одно решение: x1 = %lg\n", ans.x1);
            break;
        case TWO_SOLUTIONS:
            printf("Уравнение имеет два решения:\n"
                    "x1 = %lg\tx2 = %lg\n", ans.x1, ans.x2);
            break;
        case INFINITY_OF_SOLUTIONS:
            printf("Уравнение имеет бесконечное количество решений\n");
            break;
        default:
            printf("ERROR: count_solutions = %d\n", count_solutions);
    }
}

int coefficient_check_finite(double a, double b, double c) //BUG int or bool
{
    return isfinite(a) && isfinite(a) && isfinite(a);
}

DOUBLE_COMPARE double_comparing(double a, double b){
    if (fabs(a) < b + EPS)
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

NUMBER_OF_SOLUTIONS solve_equation(double a, double b, double c, answer * ans)
{
    assert(ans != NULL);
    assert(&ans->x1 != NULL);
    assert(&ans->x2 != NULL);

    switch(find_type_of_square(a, b, c))
    {
        case LINEAR:
            return solve_linear(b, c, ans);
        case SQUARE:
            return solve_square(a, b, c, ans);
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

NUMBER_OF_SOLUTIONS solve_linear(double b, double c, answer * ans)
{
    assert(ans != NULL); //BUG when link could be NULL and what link has NAN
    assert(&ans->x1 != NULL);

    if (double_comparing(b, 0) == EQUAL)
    {
        return (double_comparing(c, 0) == EQUAL) ? INFINITY_OF_SOLUTIONS : ZERO_SOLUTIONS;
    }
    else
    {
        ans->x1 = -c/b;

        return ONE_SOLUTION;
    }
}

NUMBER_OF_SOLUTIONS solve_square(double a, double b, double c, answer * ans)
{
    assert(&ans->x1 != NULL);
    assert(&ans->x2 != NULL);

    double d = b*b - 4*a*c;

    if (double_comparing(d, 0) == EQUAL)
    {
        ans->x1 = -b/(2*a);

        return ONE_SOLUTION;
    }
    else if (double_comparing(d, 0) == MORE)
    {
        double sqrt_d = sqrt(d);
        ans->x1 = (-b + sqrt_d)/(2*a);
        ans->x2 = (-b - sqrt_d)/(2*a);

        return TWO_SOLUTIONS;
    }
    else
    {
        return ZERO_SOLUTIONS;
    }
}

TEST_STATUS compare_results(NUMBER_OF_SOLUTIONS count_solutions_exp, double x1_exp, double x2_exp,
                    NUMBER_OF_SOLUTIONS count_solutions, double x1, double x2)
{
    if ((count_solutions_exp == count_solutions) && (x1_exp == x1) && (x2_exp == x2))
    {
        return CORRECT;
    }
    else
    {
        return FALSE;
    }
}

TEST_STATUS run_test(int number_of_test, double a, double b, double c,
            NUMBER_OF_SOLUTIONS count_solutions_exp, double x1_exp, double x2_exp)
{
    TEST_STATUS status = CORRECT;
    double x1 = NAN, x2 = NAN;
    NUMBER_OF_SOLUTIONS count_colutions = INVALID;

    count_colutions = solve_equation(a, b, c, &x1, &x2);
    if (compare_results(count_solutions_exp, x1_exp, x2_exp, count_colutions, x1, x2))
    {
        printf("TEST №%d STATUS CORRECT\n", number_of_test);

        return CORRECT;
    }
    else
    {
        printf("TEST STATUS FLASE\n");
        printf("RESULT: count_solutions = %d\tx1 = %lg\tx2 = %lg\n", count_colutions, x1, x2);
        printf("EXPECT: count_solutions_exp = %d\tx1_exp = %lg\tx2_exp = %lg\t", count_solutions_exp, x1_exp, x2_exp);

        return FALSE;
    }
}
