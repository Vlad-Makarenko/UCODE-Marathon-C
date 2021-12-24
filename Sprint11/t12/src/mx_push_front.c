#include "list.h"

void mx_push_front(t_list **list, void *data){
    if (*list == NULL){
        *list = mx_create_node(data);
        return;
    }
    t_list *tmp = *list;
    *list = mx_create_node(data);
    (*list)->next = tmp;

}


