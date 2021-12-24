

#ifndef DESKTOP_GET_ADDRESS_H
#define DESKTOP_GET_ADDRESS_H

#include <stdlib.h>


char *mx_get_address(void *p);

char *mx_strnew(const int size);

char *mx_nbr_to_hex(unsigned long nbr);

char *mx_strcpy(char *dst, const char *src);

int mx_strlen(const char *s);

#endif //DESKTOP_GET_ADDRESS_H
