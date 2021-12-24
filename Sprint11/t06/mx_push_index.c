#include "list.h"

void mx_push_index (t_list **list, void *data, int index){
    if (*list == NULL){
        *list = mx_create_node(data);
        return;
    }

    if (index <= 0){
        mx_push_front(list, data);
        return;
    }
    t_list *current = *list;
    for (int i = 0;  i <= index; ++i) {
        if (current->next == NULL) {
            mx_push_back(list, data);
            break;
        }
        if (i == index - 1) {
            t_list *tmp = current->next;
            current->next = mx_create_node(data);
            current->next->next = tmp;
            break;
        } else {
            current = current->next;
        }
    }
}

