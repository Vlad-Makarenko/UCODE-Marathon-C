#include <stdbool.h>


bool mx_is_prime(int num){
    bool flag = true;
    for (int i = 2; i < num; ++i) {
        if (num % i == 0){
            flag = false;
        }
    }
    return flag;
}

