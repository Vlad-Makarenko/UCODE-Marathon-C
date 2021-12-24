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
int mx_atoi(const char *str)
{
    while (mx_isspace(*str))
    {
        str++;
    }

    int factor = 1;
    if (*str == '-' || *str == '+') {
        if (*str == '-') factor = -1;
        str++;
    }
    int result = 0;
    while (mx_isdigit(*str))
    {
        result = result * 10 + *str - '0';
        str++;
    }

    return result * factor;
}

