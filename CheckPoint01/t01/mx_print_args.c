#include <unistd.h>

int main(int argc, char *argv[]){
    char *buf;
    for (int i = 1; i < argc; i++) {
        buf = argv[i];
        while (*buf) {
            write(1, buf++, 1);
        }
        write(1, "\n", 1);
    }

    return 0;
}
