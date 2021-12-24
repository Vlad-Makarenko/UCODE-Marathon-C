#include <stdlib.h>

void mx_strdel(char **str);

void mx_del_strarr(char ***arr){
    while (**arr != NULL){
        mx_strdel(*arr);
        arr++;
    }
    free(**arr);
    **arr = NULL;
}

