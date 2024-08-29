#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

/// @brief Type of equation
enum TYPES_OF_EQUATION
{
    LINEAR = 0, /**< Linear equation */
    SQUARE = 1  /**< Linear equation */
};

/**
 * @brief Function call solve_square() or solve_linear() solves equation
            in case of find_type_of_square()
 *
 * @param a Coefficient №1 (quadratic)
 * @param b Coefficient №2 (linear)
 * @param c Coefficient №3 (free)
 * @param answer probably understandable lol
 * @return NUMBER_OF_SOLUTIONS
 */
int solve_equation(double a, double b, double c, ROOTS* answer);

/**
 * @brief
 *
 * @param a Coefficient №1 (quadratic)
 * @param b Coefficient №2 (linear)
 * @param c Coefficient №3 (free)
 * @param answer probably understandable lol
 * @return NUMBER_OF_SOLUTIONS
 */
int solve_square(double a, double b, double c, ROOTS* answer);

/**
 * @brief
 *
 * @param b Coefficient №2 (linear)
 * @param c Coefficient №3 (free)
 * @param answer probably understandable lol
 * @return NUMBER_OF_SOLUTIONS
 */
int solve_linear(double b, double c, ROOTS* answer);

/**
 * @brief
 *
 * @param a Coefficient №1 (quadratic)
 * @return TYPES_OF_EQUATION
 */
int find_type_of_square(double a);

#endif
