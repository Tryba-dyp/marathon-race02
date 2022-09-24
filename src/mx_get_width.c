#include "../inc/way_home.h"

int mx_get_width(const char *s) {
    int width = 0;
    
    while (s[width] != '\n')
        width++;
    
    return width;
}

