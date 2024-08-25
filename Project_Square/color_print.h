#ifndef COLOR_PRINT_H
#define COLOR_PRINT_H

enum MY_COLOR
{
    DEFAULT = 0,
    GREEN_TEXT = 32,
    RED_TEXT = 31
};

enum FORMAT
{
    BOLD = 1,
    REGULAR = 0
};

void color_print(const char * format, MY_COLOR color, FORMAT font);
void color_print_pro(MY_COLOR color, FORMAT font, const char * format, ...);
void style_selector(MY_COLOR color, FORMAT font);

#endif
