//
// Created by Vladyslav Makarenko on 9/21/21.
//

#ifndef DESKTOP_MINILIBMX_H
#define DESKTOP_MINILIBMX_H

#include <stdbool.h>
#include <unistd.h>

void mx_printchar(char c);

void mx_printint(int n);

void mx_printstr(const char *s);

int mx_strlen(const char *s);

int mx_strcmp(const char *s1, const char *s2);

bool mx_isdigit(int c);

bool mx_isspace(char c);

int mx_atoi(const char *str);

void mx_printerr(const char *s);

int calc(int argc, char *argv[]);

bool isCorrectOperand(char *operand);

#endif //DESKTOP_MINILIBMX_H
