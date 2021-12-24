#ifndef MINILIBMX_H
#define MINILIBMX_H
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool mx_isdigit(int c);

bool mx_isspace(char c);

void mx_printchar(char c);

int mx_atoi(const char *str);

void mx_printint(int n);

int mx_strlen(const char *s);

char *mx_strcpy(char *dst, const char *src);

int mx_strcmp(const char *s1, const char *s2);

void mx_printstr(const char *s);

void mx_printerr(const char *s);

char *mx_strnew(const int size);

char *mx_strtrim(const char *str);

char *mx_strncpy(char *dst, const char *src, int len);

int mx_pow(int n, unsigned int pow);

char *mx_itoa(int num);

int *mx_copy_int_arr(const int *src, int size);

#endif
