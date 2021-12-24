#include <unistd.h>

int mx_strlen(const char *s){
    int index = 0;
    while (s[index] != '\0'){
        index++;
    }
    return index;
}

void mx_printstr(const char *s){
    write(1, s, mx_strlen(s));
}
