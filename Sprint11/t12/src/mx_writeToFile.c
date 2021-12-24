#include "list.h"

void mx_writeToFile(t_list *list, char *filename) {
    int file = open(filename, O_TRUNC | O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (file < 0) {
        mx_printerr("ERROR\n");
        return;
    }
    t_list *current = list;
    while (current != NULL) {
        write(file, ((t_song *)current->data)->artist, mx_strlen(((t_song *)current->data)->artist));
        write(file, ",", 1);
        write(file, ((t_song *)current->data)->name, mx_strlen(((t_song *)current->data)->name));
        write(file, "\n", 1);
        current = current->next;
    }
    if (close(file) < 0) {
        mx_printerr("ERROR\n");
    }
}

// O_TRUNC |
