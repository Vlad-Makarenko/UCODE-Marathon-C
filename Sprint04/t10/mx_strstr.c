#include <stdlib.h>

int mx_strncmp(const char *s1, const char *s2, int n);

int mx_strlen(const char *s);

char *mx_strchr(const char *s, int c);

char *mx_strstr(const char *s1, const char *s2){
    if(mx_strlen(s1) < mx_strlen(s2)){
        return NULL;
    }
    while(*s1 != '\0'){
        if(mx_strncmp(s1, s2, mx_strlen(s2)) == 0){
            return mx_strchr(s1, *s2);
        }
        s1++;
    }
    return NULL;
    }
