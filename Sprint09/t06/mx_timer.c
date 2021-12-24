#include <time.h>

double mx_timer(void (*f)()) {
    clock_t begin = clock();
    f();
    clock_t end = clock();
    double time = (double) (end - begin) / CLOCKS_PER_SEC;
    if (begin <= 0
        || end <= 0
        || end < begin) {
        return -1;
    } else {
        return time;
    }
}

