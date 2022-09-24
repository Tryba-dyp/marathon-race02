#include "../inc/way_home.h"

int mx_atoi(const char *str) {
    int i = 0;
    int result = 0;
    bool minus = false;

	while (str[i]) {
		if (mx_isspace(str[i]))
			i++;
		else
			break;
	}

    if (str[i] == '+') {
		i++;
	}
	else if (str[i] == '-') {
		minus = true;
		i++;
	}

    while (str[i] != '\0') {
        if (mx_isdigit(str[i])) {
        	result = result * 10 + (str[i] - '0');    
        	i++;
        }
        else
        	return 0;
    }
    
    if (minus) 
        return -1 * result;
    else
        return result;
}

