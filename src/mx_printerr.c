#include "../inc/way_home.h"

void mx_printerr(const char *err_msg) {
    write(2, err_msg, mx_strlen(err_msg));
}

