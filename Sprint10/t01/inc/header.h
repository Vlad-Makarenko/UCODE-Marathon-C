
#ifndef DESKTOP_HEADER_H
#define DESKTOP_HEADER_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void mx_printerr(const char *s);

void mx_printchar(char c);

int mx_strlen(const char *s);

void errnoError(char *file);

#endif //DESKTOP_HEADER_H
