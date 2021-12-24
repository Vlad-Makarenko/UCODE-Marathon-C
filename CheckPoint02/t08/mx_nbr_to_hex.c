#include <stdlib.h>
#include <unistd.h>

char *mx_strnew(const int size){
    if(size < 0){
        return NULL;
    }
    char *Str = malloc(size + 1);
    for (int i = 0; i < size + 1; ++i) {
        *(Str + i) = '\0';
    }
    return Str;
}

char *mx_nbr_to_hex(unsigned long nbr){
    char s[100];
    int len = 0;
    for (int i=0; nbr != 0; i++) {
        int x = nbr % 16;
        nbr /= 16;
        s[i] = x < 10 ? x + '0' : x - 10 + 'a';
        len++;
    }
    char *res = mx_strnew(len);
    res[0] = '0';
    for (int i = 0; i < len; ++i) {
        res[i] = s[len - i - 1];
    }
    return res;
}
