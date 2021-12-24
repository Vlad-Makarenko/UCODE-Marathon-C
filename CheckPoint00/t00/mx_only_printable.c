#include <unistd.h>

void mx_printchar(char c){
    char *sym = &c;
    write(1, sym, 1);
}

void mx_only_printable(void){
    for (int i = 127; i >= 32; i--) {
        mx_printchar(i);
    }
    mx_printchar('\n');
}
