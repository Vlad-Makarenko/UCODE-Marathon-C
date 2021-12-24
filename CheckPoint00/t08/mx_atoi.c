#include <stdbool.h>

bool mx_isdigit(int c){
    if (c > 47 && c < 58){
        return 1;
    } else {
        return 0;
    }
}

bool mx_isspace (char c){
    if (c == '\t'
        || c == '\n'
        || c == '\v'
        || c == '\f'
        || c == '\r'
        || c == ' '){
        return 1;
    } else {
        return  0;
    }
}

int mx_atoi(const char *str){
    while (mx_isspace((char )*str)){
        str++;
    }
    int flag = 1;
    if (*str == '-'){
        flag = -1;
        str++;
    }
    int res = 0;
    for ( ; (mx_isdigit((char ) *str)); ) {
        res = (res * 10) + ((*str) - '0');
        str++;
    }

    return res * flag;
}

