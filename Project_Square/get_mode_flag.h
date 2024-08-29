#ifndef FLAGS_HANDLING_H
#define FLAGS_HANDLING_H

/// @brief An enum type for CLI flags
enum FLAG_MODE
{
    TEST   = 1,
    MANUAL = 2
};

/**
 * @brief Function processes incoming flags
 *
 * @param argc Number of input parameters
 * @param argv List of input parameters
 * @return int
 */
FLAG_MODE get_mode_flag(int argc, char* argv[]);

#endif
