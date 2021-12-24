#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size);

int *mx_del_dup_arr(int *src, int src_size, int *dst_size) {
    int *mas = mx_copy_int_arr(src, src_size);
    int newSize = src_size;
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

    *dst_size = newSize;
    int *newArr = mx_copy_int_arr(mas, *dst_size);
    free(mas);
    mas = NULL;
    return newArr;
}


