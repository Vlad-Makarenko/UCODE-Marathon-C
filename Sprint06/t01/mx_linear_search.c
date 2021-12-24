#include <stdlib.h>

int mx_strcmp(const char *s1, const char *s2);

int mx_linear_search(char **arr, const char *s){
    int index = 0;
    int flag = 0;
    for (; arr[index] != NULL; index++) {
        if (mx_strcmp(arr[index], s) == 0){
            flag = 1;
            break;
        }
    }
    if (flag){
        return  index;
    } else {
        return -1;
    }
}

