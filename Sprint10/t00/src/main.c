#include "header.h"

int main(int argc, char *argv[]){

    if (argc != 2){
        mx_printerr("usage: ./read_file [file_path]\n");
        return 0;
    }

    int isOpen = open(argv[1], O_RDONLY);
    if (isOpen == -1){
        mx_printerr("error\n");
        return 0;
    }

    int countByte = 1;
    char sym;
    while (countByte != 0) {
        countByte = read(isOpen, &sym, 1);
        if (countByte != 0) {
            mx_printchar(sym);
        }
    }

    if (close(isOpen) < 0) {
        mx_printerr("error\n");
        return 0;
    }

    return 0;
}

