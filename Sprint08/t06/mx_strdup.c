#include <stdlib.h>

int mx_strlen(const char *s);

char *mx_strnew(const int size);

char *mx_strcpy(char *dst, const char *src);

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


