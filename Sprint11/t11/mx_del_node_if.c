#include "list.h"

void mx_del_node_if (t_list **list, void *del_data, bool (*cmp)(void *a, void *b)){
    if (*list == NULL || del_data == NULL || cmp == NULL){
        return;
    }
    t_list *current = *list;
    t_list *buf = current;
    while (current != NULL){
        if (cmp(del_data, current->data)){
            if (*list == current) {
                *list = current->next;
                free(current);
                current = *list;
                continue;
            }
            buf->next = current->next;
            free(current);
            current = buf->next;
        }
        buf = current;
        current = current->next;
    }
}

