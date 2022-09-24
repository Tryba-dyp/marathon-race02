#include "../inc/way_home.h"

int mx_get_height(const char *s, int length) {
    int str_size = length;
    int height = 0;
    for (int i = 0; i < str_size; i++) {
        if (s[i] == '\n')
            height++;
    }
    return height;
}

