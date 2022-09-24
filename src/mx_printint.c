#include "../inc/way_home.h"

void mx_printint(int n) {
    int arr_ints[10];
    int index = 0;
    
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    
    if (n == 0) 
    	mx_printchar('0');
    
    if (n < 0) {
        mx_printchar('-');
        n *= -1;
    }
    
    while (n > 0) {
        arr_ints[index] = n % 10;
        n /= 10;
        index++;
    }

    for (int i = index - 1; i >= 0; i--)
        mx_printchar(arr_ints[i] + 48);
}

