#include "header.h"

int mx_strncmp(const char *s1, const char *s2, int n){
    for (int i = 0; (*s1 != '\0' && *s2 != '\0') && *s1 == *s2 && i < n; i++){
        s1++;
        s2++;
    }
    if(*s1 == *s2 || *s2 == '\0'){
        return 0;
    }else{
        return *s1 - *s2;
    }
}
