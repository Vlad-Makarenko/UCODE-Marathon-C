
#ifndef DESKTOP_HEADER_H
#define DESKTOP_HEADER_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct s_agent {
    char *name;
    int power;
    int strength;
}              t_agent;


void mx_exterminate_agents(t_agent ***agents);

int errorCheck(int argc, char *argv[]);

void mx_printerr(const char *s);

void mx_printchar(char c);

int mx_strlen(const char *s);

bool mx_isspace (char c);

void mx_printstr(const char *s);

void mx_printint(int n);

int mx_strcmp(const char *s1, const char *s2);

char *mx_strchr(const char *s, int c);

int mx_strncmp(const char *s1, const char *s2, int n);

char *mx_strchr(const char *s, int c);

char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char* sub);

bool mx_isdigit(int c);

int mx_atoi(const char *str);

char *mx_file_to_str(const char *filename);

char *mx_strnew(const int size);

char *mx_strncpy(char *dst, const char *src, int len);

void sortAgentsByStrength (t_agent **arr, int size);

void sortAgentsByPower (t_agent **arr, int size);

void sortAgentsByName (t_agent **arr, int size);

char *mx_del_extra_whitespaces(const char *str);

void mx_strdel(char **str);

char *mx_strtrim(const char *str);

#endif //DESKTOP_HEADER_H
