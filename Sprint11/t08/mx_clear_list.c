#include "list.h"

void mx_clear_list(t_list **list){
    if (*list == NULL){
        return;
    }
    t_list * current = *list;

    while (*list != NULL) {
        current = (*list)->next;
        (*list)->next = NULL;
        free(*list);
        *list = current;
    }
}

