#include "list.h"

void mx_pop_index(t_list **list, int index){
    if (*list == NULL){
        return;
    }
    if (index <= 0){
        mx_pop_front(list);
        return;
    }
    t_list *current = *list;
    for (int i = 0;  i <= index; ++i) {
        if (current->next == NULL) {
            mx_pop_back(list);
            break;
        }
        if (i == index - 1) {
            t_list *tmp = current->next->next;
            free(current->next);
            current->next = tmp;
            break;
        } else {
            current = current->next;
        }
    }
}


