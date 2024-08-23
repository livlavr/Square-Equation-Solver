#ifndef UNIT_TEST_H
#define UNIT_TEST_H

struct TEST_PARAMETERS
{
    int number_of_test = -1;
    NUMBER_OF_SOLUTIONS count_solutions_exp = INVALID;
    double a = NAN, b = NAN, c = NAN;
    double x1_exp = NAN, x2_exp = NAN;
};

void run_testing_system();
bool run_test(TEST_PARAMETERS* test);
bool compare_results(const TEST_PARAMETERS* test, ROOTS answer);

#endif
