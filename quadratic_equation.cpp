#include <stdio.h>
#include <math.h>
#include <assert.h>

// **************************************************** consts

const int NUMBER_OF_COEFFICIENT = 3;
const int INVALID = 1;
const double EPS = 0.01;

enum NUMBER_OF_SOLUTIONS {
    ZERO_SOLUTIONS        = 0,
    ONE_SOLUTION          = 1,
    TWO_SOLUTIONS         = 2,
    INFINITY_OF_SOLUTIONS = -1
};

enum TYPES_OF_EQUATION {
    LINEAR              = 0,
    SQUARE              = 1
};

// ************************************** function declaration

int find_type_of_square(double a, double b, double c);
int solve_equation(double a, double b, double c, double* x1, double* x2);
int solve_square(double a, double b, double c, double* x1, double* x2);
int solve_linear(double b, double c, double* x1);
void user_input(double* a, double* b, double* c);
void result_output(int number_of_solutions, double x1, double x2);

// ****************************************************** main

int main(){ // BUG NAN or NULL and why?
    double a = NAN, b = NAN, c = NAN;
    double x1 = 0, x2 = 0;

    user_input(&a, &b, &c);
    int number_of_solutions = solve_equation(a, b, c, &x1, &x2);
    result_output(number_of_solutions, x1, x2);
}

// *************************************** function definition

void user_input(double* a, double* b, double* c){
    int input_count = 0;

    printf("Введите коэффиценты квадратного уравнения: a b c\n");
    while ((input_count = scanf("%lg%lg%lg", &*a, &*b, &*c)) != NUMBER_OF_COEFFICIENT){
        for (int i = 0; i < NUMBER_OF_COEFFICIENT - input_count; ++i){
            scanf("%*s");
        }
        printf("Упс, похоже вы ввели неправильные значения\n");
        printf("Попробуйте ещё раз\n");
    }

    assert(*a != NAN);
    assert(*b != NAN);
    assert(*c != NAN);
}

void result_output(int number_of_solutions, double x1, double x2){
    switch (number_of_solutions){
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
        default: //BUG assert and default difference in usage
            printf("ERROR: number_of_solutions = %d\n", number_of_solutions);
    }
}

int solve_equation(double a, double b, double c, double* x1, double* x2){
    assert(x1 != NULL);
    assert(x2 != NULL);

    switch(find_type_of_square(a, b, c)){
        case LINEAR:
            return solve_linear(b, c, x1);
        case SQUARE:
            return solve_square(a, b, c, x1, x2);
        default:
            printf("ERROR: solve_equation");

            return INVALID;
    }
}

int find_type_of_square(double a, double b, double c){
    if (fabs(a) <= EPS){
        return LINEAR;
    }
    else{
        return SQUARE;
    }
}

int solve_linear(double b, double c, double* x1){
    assert(x1 != NULL);

    if (fabs(b) <= EPS){
        return (fabs(c) <= EPS) ? INFINITY_OF_SOLUTIONS : ZERO_SOLUTIONS;
    }
    else{
        *x1 = -c/b;

        return ONE_SOLUTION;
    }
}

int solve_square(double a, double b, double c, double* x1, double* x2){
    assert(x1 != NULL);
    assert(x2 != NULL);

    double d = b*b - 4*a*c;

    if (fabs(d) < EPS){
        *x1 = -b/(2*a);

        return ONE_SOLUTION;
    }
    else if (d > EPS){
        double sqrt_d = sqrt(d);
        *x1 = (-b + sqrt_d)/(2*a);
        *x2 = (-b - sqrt_d)/(2*a);

        return TWO_SOLUTIONS;
    }
    else{
        return ZERO_SOLUTIONS;
    }
}
