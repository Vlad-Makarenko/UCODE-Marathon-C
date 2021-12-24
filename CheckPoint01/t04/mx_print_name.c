#include <unistd.h>

void mx_printchar(char c){
    char *sym = &c;
    write(1, sym, 1);
}


int mx_strlen(const char *s){
    int index = 0;
    while (s[index] != '\0'){
        index++;
    }
    return index;
}


void mx_printstr(const char *s){
    write(1, s, mx_strlen(s));
}

void mx_printint(int n){
    if (n < 0){
        mx_printchar('-');
        n = -n;
    }
    if (n == 0){
        mx_printchar('0');
    } else {
        int arrayint[10];
        int len = 0;
        for (int i = 0; n != 0; ++i) {
            arrayint[i] = n % 10;
            n /= 10;
            len++;
        }
        char arraychar[len];
        for (int i = 0; i < len; ++i) {
            arraychar[i] = arrayint[i] + '0';
        }
        for (int i = len - 1; i >= 0; --i) {
            mx_printchar(arraychar[i]);
        }
    }
}

int main(int argc, char *argv[]){
    mx_printstr(argv[0]);
    mx_printchar('\n');
    mx_printint(argc);
    mx_printchar('\n');
    return 0;
}

