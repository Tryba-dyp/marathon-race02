#include "../inc/way_home.h"

char *mx_file_to_str(const char *filename) {
    if(!filename)
        return NULL;
    
    int src_file = open(filename, O_RDONLY);
    
    if (src_file < 0) {
        return NULL;
    }
    
    int length = 0;
    char c;
    
    while (read(src_file, &c, 1) != 0)
        length++;
    
    close(src_file);
    
    src_file = open(filename, O_RDONLY);
    
    char *str = mx_strnew(length);
    read(src_file, str, length);
    close(src_file);
    
    return str;
}


