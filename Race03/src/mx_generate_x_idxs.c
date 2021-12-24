#include "matrix_rain.h"

void mx_generate_x_idxs(int size, int arr[]) {

    int buff_arr[size];
    for (int i = 0; i < size; i++) {
        buff_arr[i] = i;
    }

    for (int j = 0; j < size; j++) {
        int index = rand() % size;
        
        for (int i = index; ; i = (i + 1) % size ) {
            if (buff_arr[i] != -1) {
                arr[j] = buff_arr[i];
                buff_arr[i] = -1;
                break;
            }
        }
        
    }

}
