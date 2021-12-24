
#ifndef DESKTOP_HEADER_H
#define DESKTOP_HEADER_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

void mx_printerr(const char *s);

void mx_printchar(char c);

int mx_strlen(const char *s);

void errnoError(char *file);

bool mx_isspace (char c);

void mx_printstr(const char *s);

void mx_printint(int n);

int mx_strcmp(const char *s1, const char *s2);

#endif //DESKTOP_HEADER_H
