#include <stdlib.h>

int mx_strncmp(const char *s1, const char *s2, int n);

int mx_strlen(const char *s);

char *mx_strchr(const char *s, int c);

char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char* sub){
    int res = 0;
    if(mx_strlen(str) < mx_strlen(sub)){
        return res;
    }
    while (*str != '\0'){
        str = mx_strstr(str, sub);
        if (str != NULL) {
            str++;
            res++;
        } else {
            break;
        }
    }
    return res;
}

