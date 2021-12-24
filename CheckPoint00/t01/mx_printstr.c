#include <unistd.h>

int mx_strlen(const char *s){
    int len = 0;
    while (s[len] != '\0'){
        len++;
    }
    return len;
}

void mx_printstr(const char *s){
    write(1, s, mx_strlen(s));
}

