
#ifndef DESKTOP_HEADER_H
#define DESKTOP_HEADER_H

#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_song
{
    char *artist;
    char *name;
}              t_song;


void mx_printerr(const char *s);

void mx_printchar(char c);

int mx_strlen(const char *s);

bool mx_isspace (char c);

void mx_printstr(const char *s);

void mx_printint(int n);

int mx_strcmp(const char *s1, const char *s2);

bool mx_isdigit(int c);

int mx_atoi(const char *str);


char *mx_strnew(const int size);

char *mx_strcpy(char *dst, const char *src);

char *mx_strdup(const char *str);

char *mx_file_to_str(const char *filename);

char *mx_strncpy(char *dst, const char *src, int len);

char **mx_strsplit(char const *s, char c);

int mx_count_words(const char *str, char delimiter);

char *mx_strjoin(char const *s1, char const *s2);

char *mx_strcat (char *s1, const char * s2);

int mx_tolower(int c);

//other

char *mx_strchr(const char *s, int c);

int mx_strncmp(const char *s1, const char *s2, int n);

char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char* sub);

char *mx_del_extra_whitespaces(const char *str);

void mx_strdel(char **str);

char *mx_strtrim(const char *str);

#endif //DESKTOP_HEADER_H
