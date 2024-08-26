#ifndef DOUBLE_COMPARE_H
#define DOUBLE_COMPARE_H

const double EPS = 0.001; //**< Accuracy */

/// @brief An enum type
/// DOUBLE COMPARING RESULT
enum DOUBLE_COMPARE
{
    LESS  = -1,
    EQUAL = 0,
    MORE  = 1
};

/**
 * @brief Compares two doubles
 *
 * @param a First double
 * @param b Second double
 * @return DOUBLE_COMPARE Result of (a <=> b) with respective meanings:
            LESS, EQUAL, MORE
 */
DOUBLE_COMPARE double_comparing(double a, double b);

/**
 * @brief Checks if the number has a valid double value
 *
 * @param a Coefficient №1 (quadratic)
 * @param b Coefficient №2 (linear)
 * @param c Coefficient №3 (free)
 * @return bool
 */
bool coefficient_check_finite(double a, double b, double c);

#endif
