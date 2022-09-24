#include "../inc/way_home.h"

void mx_strdel(char **str) {
    free(*str);
    *str = NULL;   
}

