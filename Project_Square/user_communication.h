#ifndef USER_COMMUNICATION_H_
#define USER_COMMUNICATION_H_

/// @brief Number of equation coefficients
const int NUMBER_OF_COEFFICIENT = 3;

/// @brief Max len of user input when he choose mode of program
const int MAX_LEN_OF_INPUT = 4;

/**
 * @brief User input equation coefficients
 *
 * @param a Coefficient №1 (quadratic)
 * @param b Coefficient №2 (linear)
 * @param c Coefficient №3 (free)
 */
void user_input(double* a, double* b, double* c);

/**
 * @brief Print result of equation solving
 *
 * @param count_solutions Number of quadratic equation solutions
 * @param answer
 */
void result_output(NUMBER_OF_SOLUTIONS count_solutions, ROOTS answer);

/**
 * @brief Start test or user input selector
 * Type man to start an user input mode
 * Type test to start tests
 */
bool test_or_user_input();

#endif
