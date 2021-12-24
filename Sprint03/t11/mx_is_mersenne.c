#include <stdbool.h>

bool mx_is_prime(int num);

double mx_pow(double n, unsigned int pow);

bool mx_is_mersenne(int n){
    bool flag = false;
    int buf = 0;
    if (mx_is_prime(n)) {
        unsigned int p;
        for (p  = 2; buf < n; ++p) {
            buf = (int) mx_pow(2, p);
            if (n == buf - 1) {
                flag = true;
                break;
            }
        }
        if (!(flag && mx_is_prime(p)) ) {
            flag = false;
        }
    }
    return flag;
}

