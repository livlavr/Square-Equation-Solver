#include <stdio.h>
#include <stdarg.h>
#include "color_print.h"

void style_selector(MY_COLOR color, FORMAT font)
{
    switch(font)
    {
        case BOLD:
            printf("\033[1m");
            break;
        case REGULAR:
            printf("\033[0m");
            break;
        default:
            printf("FONT SELECTOR ERROR");
            break;
    }
    switch(color)
    {
        case GREEN_TEXT:
            printf("\033[32m");
            break;
        case RED_TEXT:
            printf("\033[31m");
            break;
        case DEFAULT:
            printf("\033[0m");
            break;
        default:
            printf("COLOR SELECTOR ERROR");
            break;
    }
}

// TODO remove _pro suffix
void color_print_pro(MY_COLOR color, FORMAT font, const char * format, ...)
{
    va_list arguments;
    style_selector(color, font);
    va_start(arguments, format);
    vprintf(format, arguments);
    va_end(arguments);
    style_selector(DEFAULT, REGULAR);
}

// TODO remove
void color_print(const char * format, MY_COLOR color, FORMAT font)
{
    switch(font)
    {
        case BOLD:
            switch(color)
            {
                case GREEN_TEXT:
                    printf("\033[1;32m%s\033[0m", format);
                    break;
                case RED_TEXT:
                    printf("\033[1;31m%s\033[0m", format);
                    break;
                case DEFAULT:
                    break;
                default:
                    printf("color_print color ERROR");
                    break;
            }
            break;
        case REGULAR:
            switch(color)
            {
                case GREEN_TEXT:
                    printf("\033[0;32m%s\033[0m", format);
                    break;
                case RED_TEXT:
                    printf("\033[0;31m%s\033[0m", format);
                    break;
                case DEFAULT:
                    break;
                default:
                    printf("color_print color ERROR");
                    break;
            }
            break;
        default:
            printf("color_print format ERROR");
            break;
    }
}
