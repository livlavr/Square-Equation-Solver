#ifndef USER_COMMUNICATION_H_ // TODO user_communication.h
#define USER_COMMUNICATION_H_ // TODO use in every header

const int NUMBER_OF_COEFFICIENT = 3;

void user_input(double* a, double* b, double* c);
void result_output(NUMBER_OF_SOLUTIONS count_solutions, ROOTS answer);
bool test_or_user_input();

#endif
