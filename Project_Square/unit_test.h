#ifndef UNIT_TEST_H
#define UNIT_TEST_H

/// @brief Struct that contains parameters for test
struct TEST_PARAMETERS
{
    int number_of_test = 0;
    NUMBER_OF_SOLUTIONS count_solutions_exp = INVALID;
    double a = 0, b = 0, c = 0;
    double x1_exp = 0, x2_exp = 0;
};


/// @brief Function starts tests
void run_testing_system();

/**
 * @brief Function starts one exact test
 * @param test Variable in TEST_PARAMETERS struct
 */
bool run_test(const TEST_PARAMETERS* test);

/**
 * @brief Compare result of test with expect values
 *
 * @param test Variable in TEST_PARAMETERS struct
 * @param answer probably understandable lol
 */
bool compare_results(const TEST_PARAMETERS* test, ROOTS answer);

#endif
