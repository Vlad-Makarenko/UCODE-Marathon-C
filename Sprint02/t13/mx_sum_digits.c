
int mx_sum_digits(int num){
    if (num < 0){
        num = -num;
    }
    int len = 0;
    int tmp = num;
    int res = 0;
    if (tmp / 10 == 0){
        return num;
    } else {
        while (tmp > 0) {
            tmp /= 10;
            len++;
        }
    }
    int array[len];
    for (int i = 0; i < len; ++i) {
        array[i] = num % 10;
        num /= 10;
    }
    for (int i = 0; i < len; ++i) {
        res += array[i];
    }
    return res;
}
