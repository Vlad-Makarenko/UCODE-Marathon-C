#include <stdlib.h>

int mx_strlen(const char *s){
    int index = 0;
    while (s[index] != '\0'){
        index++;
    }
    return index;
}

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


char *mx_strcpy(char *dst, const char *src){
    int i;
    for ( i = 0; *(src + i) != '\0'; ++i) {
        *(dst + i) = *(src + i);
    }
    *(dst + i) = '\0';

    return dst;
}

char *mx_strdup(const char *str){
    if (str == NULL){
        return NULL;
    }
    char *Newstr = mx_strnew(mx_strlen(str));
    if (Newstr != NULL){
        mx_strcpy(Newstr, str);
        return Newstr;
    } else{
        return NULL;
    }
}


