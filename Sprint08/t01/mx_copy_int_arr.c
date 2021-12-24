#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size){
    if (src == NULL || size < 0){
        return NULL;
    }
    int *newArr = malloc(4 * size);
    if (newArr != NULL) {
        for (int i = 0; i < size; ++i) {
            *(newArr + i) = *(src + i);
        }
    }
    return newArr;
}

