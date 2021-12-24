#include <stdbool.h>


double mx_pow(double n, unsigned int pow);

bool mx_is_narcissistic(int num){
    if (num < 0){
        return false;
    }

    int arrayint[10];
    int len = 0;
    int n = num;
    for (int i = 0; n != 0; ++i) {
        arrayint[i] = n % 10;
        n /= 10;
        len++;
    }
    int res = 0;
    for (int i = 0; i < len; ++i) {
        res += (int)mx_pow(arrayint[i], len);
    }
    if(res == num){
        return true;
    }else{
        return false;
    }
}

