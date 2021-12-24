#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *mx_strnew(const int size);

void mx_printchar(char c);

void mx_printerr(const char *s);

int mx_strlen(const char *s);

char *mx_strnew(const int size);

void mx_printstr(const char *s);

void mx_printchar(char c) {
    write(1,&c,1);
}

void mx_printstr(const char *s) {
    write(1, s, mx_strlen(s));
}

void mx_printerr(const char *s) {
    write(2, s, mx_strlen(s));
}

int mx_strlen(const char *s){
    int index = 0;
    while (s[index] != '\0'){
        index++;
    }
    return index;
}

char *mx_strnew(const int size){
    if(size < 0){
        return NULL;
    }
    char *Str = malloc(size + 1);
    for (int i = 0; i < size + 1; ++i) {
        *(Str + i) = '\0';
    }
    return Str;
}

int main(int argc, char *argv[])
{
    int file;
    int file_len = 0;
    int i = 0;
    char buf[1];
    char *contents = NULL;
    const char error[] = "error\n";
    const char usage[] = "usage: ./read_file [file_path]\n";

    if (argc == 2)
    {
        file = open(argv[1], O_RDONLY);
        if (file < 0)
        {
            mx_printerr(error);
            return 0;
        }
        while (read(file, buf, 1))
            file_len++;
        contents = (char *)mx_strnew(file_len);
        if (contents == NULL)
        {
            mx_printerr(error);
            return 0;
        }
        close(file);
        file = open(argv[1], O_RDONLY);
        if (file < 0){
            mx_printerr(error);
            return 0;
        }
        while (read(file, buf, 1))
        {
            contents[i] = buf[0];
            i++;
        }
        contents[i] = '\0';
        mx_printstr(contents);
        close(file);
    }
    else
    {
        mx_printerr(usage);
    }
}
