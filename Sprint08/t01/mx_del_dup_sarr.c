#include "duplicate.h"

t_intarr *mx_del_dup_sarr(t_intarr *src) {
    if (src == NULL){
        return NULL;
    }
    int *mas = mx_copy_int_arr(src->arr, src->size);
    int newSize = src->size;
    for (int i = 0; i < newSize; i++) {
        for (int j = i + 1; j < newSize; j++) {
            if (mas[i] == mas[j]) {
                for (int k = j; k < newSize - 1; k++) {
                    mas[k] = mas[k + 1];
                }
                newSize -= 1;
            }
        }
    }
    t_intarr *newArr = malloc(sizeof(t_intarr));
    newArr->arr = mx_copy_int_arr(mas, newSize);
    newArr->size = newSize;
    free(mas);
    mas = NULL;
    return newArr;
}


