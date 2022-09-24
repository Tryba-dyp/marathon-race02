#include "../inc/way_home.h"

bool mx_isspace(char c) {
    if (c == 32 || (9 <= c && c <= 13)) {
        return true;
    }
    else {
        return false;
    }     
}

