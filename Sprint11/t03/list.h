//
// Created by Vladyslav Makarenko on 9/24/21.
//

#ifndef DESKTOP_LIST_H
#define DESKTOP_LIST_H

#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
}   t_list;

t_list *mx_create_node(void *data);

void mx_push_front(t_list **list, void *data);

void mx_push_back(t_list **list, void *data);

void mx_pop_back(t_list **list);


#endif //DESKTOP_LIST_H
