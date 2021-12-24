#include <stdlib.h>

void mx_printchar(char c);

char *mx_strchr(const char *s, int c);

void mx_printstr(const char *s);

int mx_strlen(const char *s);

int main(int argc, char *argv[]){
    for (int i = 0; i < 1; ++i) {
        argc++;
    }
    char *res;
    while (argv[0][0] != '\0'){
        argv[0] = mx_strchr(argv[0], '/');
        if (argv[0] != NULL) {
            argv[0]++;
            res = argv[0];
        } else {
            break;
        }
    }

    mx_printstr(res);
    mx_printchar('\n');

    return 0;
}


