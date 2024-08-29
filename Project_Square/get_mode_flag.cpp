#include <stdio.h>
#include <string.h>
#include "get_mode_flag.h"

FLAG_MODE get_mode_flag(int argc, char* argv[])
{
    if (argc != 1)
    {
        for(int i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "--test") == 0)
            {
                return TEST;
            }
            else
            {
                return MANUAL;
            }
        }
    }
    return MANUAL;
}
