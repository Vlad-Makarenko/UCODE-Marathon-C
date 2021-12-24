#include "list.h"

void mx_pop_front(t_list **list){
    if (*list == NULL){
        return;
    }

    t_list *current = (*list)->next;
    free(*list);
    *list = current;
}


