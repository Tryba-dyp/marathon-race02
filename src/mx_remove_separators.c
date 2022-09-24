#include "../inc/way_home.h"

char *mx_remove_separators(char *s, int file_length) {
    int str_size = file_length;
    int separators_num = 0;
    int count = 0;
    
    while (count < str_size) {
        if (s[count] == ',')
            separators_num++;
        
        count++;
    }
    
    char *res_str = mx_strnew(str_size - separators_num);
    
    for (int i = 0,j = 0; i < str_size; i++) {
        if (s[i] != ',') {
            res_str[j] = s[i];
            j++;
        }
    }
    mx_strdel(&s);
    return res_str;
}

