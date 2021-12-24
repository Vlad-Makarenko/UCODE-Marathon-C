
void mx_arr_rotate (int *arr, int size, int shift){
    int buf[size];
    for (int i = 0; i < size; ++i) {
        buf[i] = arr[i];
    }
    if (shift > 0){
        int last;
        for (int i = 0; i < shift; ++i) {
            last = arr[size - 1];
            for (int j = size - 1; j > 0; j--) {
                arr[j] = arr[j - 1];
            }
            arr[0] = last;
        }
    } else if (shift < 0){
        shift = -shift;
        int first;
        for (int i = 0; i < shift; ++i) {
            first = arr[0];
            for (int j = 0; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[size - 1] = first;
        }
    }
}

