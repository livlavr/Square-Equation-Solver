#ifndef FLAGS_HANDLING_H
#define FLAGS_HANDLING_H

/// @brief An enum type
enum
{
    TEST = 1,
    MANUAL = 2
};

/**
 * @brief Function processes incoming flags
 *
 * @param argc Number of input parameters
 * @param argv List of input parameters
 * @return int
 */
int flags_handling(int argc, char* argv[]);

#endif
