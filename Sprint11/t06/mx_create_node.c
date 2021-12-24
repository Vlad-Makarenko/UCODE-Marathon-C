#include "list.h"

t_list *mx_create_node(void *data){
    t_list *newNode = malloc(sizeof(t_list));
    newNode->data = malloc(sizeof(data));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

