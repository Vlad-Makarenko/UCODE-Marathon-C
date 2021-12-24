
#ifndef DESKTOP_LIST_H
#define DESKTOP_LIST_H

#include <stdlib.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
}               t_list;

int mx_list_size(t_list*);


#endif //DESKTOP_LIST_H
