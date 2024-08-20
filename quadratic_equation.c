#include <stdio.h>
#include <math.h>

const int NUMBER_OF_COEFFICIENT = 3;
const int INVALID = 1;
const double EPS = 1e-07;
enum NUMBER_OF_SOLUTIONS {
    ZERO_SOLUTIONS        = 0,
    ONE_SOLUTION          = 1,
    TWO_SOLUTIONS         = 2,
    INFINITY_OF_SOLUTIONS = -1
};
enum TYPES_OF_EQUATION {
    LINEAR              = 0,
    AB_ZERO_COEFFICIENT = 1,
    SQUARE              = 2
};

int find_type_of_square(double a, double b, double c);
int solve_equation(double a, double b, double c, double* x1, double* x2);
int solve_square(double a, double b, double c, double* x1, double* x2);
int solve_linear(double b, double c, double* x1);

int main(){
    double a = NAN, b = NAN, c = NAN;
    double x1 = 0, x2 = 0;
    int input_count = 0;

    printf("Введите коэффиценты квадратного уравнения: a b c\n");
    while ((input_count = scanf("%lg%lg%lg", &a, &b, &c)) != NUMBER_OF_COEFFICIENT){
        for (int i = 0; i < NUMBER_OF_COEFFICIENT - input_count; ++i){
            scanf("%*s");
        }
        printf("Упс, похоже вы ввели неправильные значения\n");
        printf("Попробуйте ещё раз\n");
    }

    int number_of_solutions = solve_equation(a, b, c, &x1, &x2);
    switch (number_of_solutions){
        case ZERO_SOLUTIONS:
            printf("D < 0, Уравнение не имеет решений\n");
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
            printf("ERROR: number_of_solutions = %d\n", number_of_solutions);
    }
}

int solve_equation(double a, double b, double c, double* x1, double* x2){
    switch(find_type_of_square(a, b, c)){
        case LINEAR:
            return solve_linear(b, c, x1);
        case AB_ZERO_COEFFICIENT:
            return (c == 0) ? INFINITY_OF_SOLUTIONS : ZERO_SOLUTIONS;
        case SQUARE:
            return solve_square(a, b, c, x1, x2);
        default:
            printf("ERROR: solve_equation");
            return INVALID;
    }
}

int find_type_of_square(double a, double b, double c){
    if (a == 0){
        return LINEAR;
    }
    else {
        return SQUARE;
    }
}

int solve_linear(double b, double c, double* x1){
    if (b == 0){
        return (c == 0) ? INFINITY_OF_SOLUTIONS : ZERO_SOLUTIONS;
    }
    else{
        *x1 = -c/b;
        return ONE_SOLUTION;
    }
}

int solve_square(double a, double b, double c, double* x1, double* x2){
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
