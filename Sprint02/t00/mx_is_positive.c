
#include <unistd.h>

int mx_strlen(const char *s);

void mx_is_positive(int i){
    char* positive = "positive\n";
    char* negative = "negative\n";
    char* zero = "zero\n";
    if (i > 0){
        write(1, positive, mx_strlen(positive));
    } else if (i < 0){
        write(1, negative, mx_strlen(negative));
    } else {
        write(1, zero, mx_strlen(zero));
    }
}
