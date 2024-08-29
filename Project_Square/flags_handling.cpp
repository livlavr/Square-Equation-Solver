#include <stdio.h> //TODO check () and '\'
#include <string.h>
#include "flags_handling.h"

int flags_handling(int argc, char* argv[])
{
    if (argc != 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "-test") == 0)
            {
                return TEST;
            }
            else
            {
                return MANUAL;
            }
        }
    }
    else
    {
        return MANUAL;
    }
    return 0;
}
