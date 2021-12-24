#include "get_address.h"

char *mx_get_address(void *p){
    unsigned long address = (unsigned long ) p;
    char * res = mx_nbr_to_hex(address);
    char *result = mx_strnew(mx_strlen(res) + 2);

    result[0] = '0';
    result[1] = 'x';
    mx_strcpy(result + 2 , res);
    free(res);
    res = NULL;
    return result;

}

