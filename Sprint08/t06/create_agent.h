
#ifndef DESKTOP_CREATE_AGENT_H
#define DESKTOP_CREATE_AGENT_H

#include <stdlib.h>
#include "agent.h"

int mx_strlen(const char *s);

char *mx_strnew(const int size);

char *mx_strcpy(char *dst, const char *src);

char *mx_strdup(const char *str);

t_agent *mx_create_agent(char *name, int power, int strength);


#endif //DESKTOP_CREATE_AGENT_H
