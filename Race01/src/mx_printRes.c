#include "calculator.h"

void mx_printResult(int leftCorrect, int rightCorrect, char *result, char operation) {
    mx_printstr(mx_itoa(leftCorrect));
    mx_printstr(" ");
    mx_printchar(operation);
    mx_printstr(" ");
    mx_printstr(mx_itoa(rightCorrect));
    mx_printstr(" ");
    mx_printstr("=");
    mx_printstr(" ");
    mx_printstr(result);
    mx_printstr("\n");
}
