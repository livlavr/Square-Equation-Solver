#include <stdio.h>
#include "color_print.h"

void color_print(const char * text, MY_COLOR color, FORMAT format)
{
    switch(format)
    {
        case BOLD:
            switch(color)
            {
                case GREEN_TEXT:
                {
                    printf("\033[1;32m%s\033[0m", text);
                    break;
                }
                case RED_TEXT:
                {
                    printf("\033[1;31m%s\033[0m", text);
                    break;
                }
                default:
                {
                    printf("color_print color ERROR");
                }
            }
            break;
        case REGULAR:
            switch(color)
            {
                case GREEN_TEXT:
                {
                    printf("\033[0;32m%s\033[0m", text);
                    break;
                }
                case RED_TEXT:
                {
                    printf("\033[0;31m%s\033[0m", text);
                    break;
                }
                default:
                    printf("color_print color ERROR");
            }
            break;
        default:
            printf("color_print format ERROR");
            break;
    }
}
