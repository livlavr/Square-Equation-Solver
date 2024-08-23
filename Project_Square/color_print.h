#ifndef COLOR_PRINT_H
#define COLOR_PRINT_H

enum MY_COLOR
{
    GREEN_TEXT = 32,
    RED_TEXT = 31
};

enum FORMAT
{
    BOLD = 1,
    REGULAR = 0
};

void color_print(const char * text, MY_COLOR color, FORMAT format);

#endif
