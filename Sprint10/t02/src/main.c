#include "header.h"

int main(int argc, char *argv[]){

    if (argc != 2){
        mx_printerr("hello\n");
        mx_printstr("hello\n");
        return 0;
    }

    int file1 = open(argv[1], O_RDONLY);
    if (errno){
        errnoError(argv[1]);
        return 0;
    }

    int countByte = 1;
    char sym;
    while (countByte != 0) {
        countByte = read(file1, &sym, 1);
        if (countByte != 0) {
            mx_printchar(sym);
        }
    }

    if (close(file1) < 0) {
        errnoError(argv[1]);
        return 0;
    }

    return 0;
}

void errnoError(char *file){
    mx_printerr("mx_cat: ");
    mx_printerr(file);
    mx_printerr(": ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
}

