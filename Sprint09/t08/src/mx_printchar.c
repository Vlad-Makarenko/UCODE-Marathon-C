#include "calculator.h"

void mx_printchar(char c){
    char *sym = &c;
    write(1, sym, 1);
}
