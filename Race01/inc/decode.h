#ifndef DECODE_H
#define DECODE_H

#include "calculator.h"

int *mx_getArrOfCorrectElements(char *pattern, int *correct_len);

void mx_doCorrectOperation(char *left, char *right, char *result, char operation);

int getMinPattern(char *pattern);

int getMaxPattern(char *pattern);

int getCountQ(char *pattern);


#endif
