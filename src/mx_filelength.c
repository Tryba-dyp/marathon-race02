#include "../inc/way_home.h"

int mx_filelength(int file) {
    int length = 0;
    char c;
    
    while (read(file, &c, 1) != 0)
        length++;

    return length;
}

