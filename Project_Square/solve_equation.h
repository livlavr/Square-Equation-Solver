enum TYPES_OF_EQUATION
{
    LINEAR = 0,
    SQUARE = 1
};

NUMBER_OF_SOLUTIONS solve_equation(double a, double b, double c, ROOTS* answer);
NUMBER_OF_SOLUTIONS solve_square(double a, double b, double c, ROOTS* answer);
NUMBER_OF_SOLUTIONS solve_linear(double b, double c, ROOTS* answer);
TYPES_OF_EQUATION find_type_of_square(double a);
