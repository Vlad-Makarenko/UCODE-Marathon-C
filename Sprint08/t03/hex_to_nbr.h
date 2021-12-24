
#ifndef DESKTOP_HEX_TO_NBR_H
#define DESKTOP_HEX_TO_NBR_H

#include <stdbool.h>
#include <stdlib.h>

bool mx_isdigit(int c);

bool mx_islower(int c);

bool mx_isupper(int c);

bool mx_isalpha(int c);

unsigned long mx_hex_to_nbr(const char *hex);

#endif //DESKTOP_HEX_TO_NBR_H
