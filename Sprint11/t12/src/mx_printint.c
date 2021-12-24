#include "header.h"

void mx_printint(int n){
    if (n < 0){
        mx_printchar('-');
        n = -n;
    }
    if (n == 0){
        mx_printchar('0');
    } else {
        int arrayint[10];
        int len = 0;
        for (int i = 0; n != 0; ++i) {
            arrayint[i] = n % 10;
            n /= 10;
            len++;
        }
        char arraychar[len];
        for (int i = 0; i < len; ++i) {
            arraychar[i] = arrayint[i] + '0';
        }
        for (int i = len - 1; i >= 0; --i) {
            mx_printchar(arraychar[i]);
        }
    }
}

