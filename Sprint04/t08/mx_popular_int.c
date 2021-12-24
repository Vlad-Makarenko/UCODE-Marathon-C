
int mx_popular_int(const int *arr, int size){
    int res = arr[0];
    int counter = 0;
    int counterMax = 0;
    for (int i = 0; i < size; ++i) {
        if (res == arr[i]){
            counterMax++;
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (res == arr[j]){
                counter++;
            }
        }
        if (counterMax < counter){
            counterMax = counter;
            res = arr[i];

        }
        counter = 0;
    }
    return res;
}

