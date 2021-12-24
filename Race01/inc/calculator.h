#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "minilibmx.h"

int mx_add(int a, int b);
int mx_sub(int a, int b);
int mx_mul(int a, int b);
int mx_div(int a, int b);
int mx_mod(int a, int b);

typedef struct s_operation
{
    char op;
    int (*f)(int a, int b);
}              t_operation;

enum e_operation {
    SUB,
    ADD,
    MUL,
    DIV,
    MOD
};

enum e_error {
    INCORRECT_INPUT,
    INCORRECT_OPERATION,
    INCORRECT_OPERAND,
    INCORRECT_RESULT,
    DIV_BY_ZERO
};

int checkOnOperandError(const char *operand);

int checkOperation(const char *operation);

int checkDiv(int right_operand);

enum e_operation getOperation(const char operation);

t_operation *createOperation(const char op);

int mx_checkOnErrors(int argc, char *argv[]);

char *createErrorMessage(enum e_error err, const char *error_arg);

char *getIncorrectOperand(char *left, char *right);

int mx_calc(int argc, char *argv[]);

void mx_printResult(int leftCorrect, int rightCorrect, char *result, char operation);

#endif
