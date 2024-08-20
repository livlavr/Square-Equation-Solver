#include <stdio.h>
#include <math.h>

const double EPS = 0.01;
enum NUMBER_OF_SOLUTIONS {
    ZERO_SOLUTIONS = 0,
    ONE_SOLUTION   = 1,
    TWO_SOLUTIONS  = 2,
    INFINITY_OF_SOLUTIONS = -1
};

int solve_square(double a, double b, double c, double* x1, double* x2);

int main(){
    double a = NAN, b = NAN, c = NAN;
    double x1 = 0, x2 = 0;
    int input_count = 0;
    printf("Введите коэффиценты квадратного уравнения: a b c\n");
    while ((input_count = scanf("%lg%lg%lg", &a, &b, &c)) != 3){
        for (int i = 0; i < 3 - input_count; ++i){ // TODO change name 3
            scanf("%*s");
        }
        printf("Упс, похоже вы ввели неправильные значения\n");
        printf("Попробуйте ещё раз\n");
    }
    int number_of_solutions = solve_square(a, b, c, &x1, &x2);
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
        default:
            printf("ERROR: number_of_solutions = %d\n", number_of_solutions);
    }
}

int solve_square(double a, double b, double c, double* x1, double* x2){ // TODO разделить на функции
    if (a == 0){
        if (b == 0){
            return (c == 0) ? INFINITY_OF_SOLUTIONS : 0;
        }
        else{
            *x1 = -c / b;
            return 1;
        }
    }
    else{
        double d = b*b - 4*a*c; // TODO разобраться с git
        if (d < EPS && d > -EPS){ // FIXME fabs и abs прочитать
            *x1 = -b/(2*a);
            return 1;
        }
        else if (d > EPS){
            double sqrt_d = sqrt(d);
            *x1 = (-b + sqrt_d)/(2*a);
            *x2 = (-b - sqrt_d)/(2*a);
            return 2;
        }
        else{
            return 0;
        }
    }
}

