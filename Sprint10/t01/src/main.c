#include "header.h"

int main(int argc, char *argv[]){

    if (argc != 3){
        mx_printerr("usage: ./read_file [file_path]\n");
        return 0;
    }

    int file1 = open(argv[1], O_RDONLY);
    if (errno){
        errnoError(argv[1]);
        return 0;
    }
    int file2 = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, S_IREAD | S_IWRITE);
    if (errno){
        return 0;
    }

    int countByte = 1;
    char sym;
    while (countByte != 0) {
        countByte = read(file1, &sym, 1);
        if (countByte != 0) {
            write(file2, &sym, 1);
        }
    }

    if (close(file1) < 0) {
        errnoError(argv[1]);
        return 0;
    }
    if (close(file2) < 0) {
        errnoError(argv[2]);
        return 0;
    }

    return 0;
}

void errnoError(char *file){
    mx_printerr("mx_cp: ");
    mx_printerr(file);
    mx_printerr(": ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
}

