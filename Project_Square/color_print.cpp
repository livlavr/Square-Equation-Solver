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
        case YELLOW_TEXT:
            printf("\033[33m");
            break;
        case DEFAULT:
            printf("\033[0m");
            break;
        default:
            printf("COLOR SELECTOR ERROR");
            break;
    }
}

void color_print(MY_COLOR color, FORMAT font, const char * format_line, ...)
{
    va_list arguments;
    style_selector(color, font);
    va_start(arguments, format_line);
    vprintf(format_line, arguments);
    va_end(arguments);
    style_selector(DEFAULT, REGULAR);
}
