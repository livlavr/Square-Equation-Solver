#ifndef UNIT_TEST_H
#define UNIT_TEST_H

struct TEST_PARAMETERS
{
    int number_of_test = 0;
    NUMBER_OF_SOLUTIONS count_solutions_exp = INVALID;
    double a = 0, b = 0, c = 0;
    double x1_exp = 0, x2_exp = 0;
};

void run_testing_system();
bool run_test(const TEST_PARAMETERS* test);
bool compare_results(const TEST_PARAMETERS* test, ROOTS answer);

#endif