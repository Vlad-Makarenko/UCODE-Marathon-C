#include "calculator.h"
#include "decode.h"

int mx_calc(int argc, char *argv[]) {
    
    for (int i = 1; i < argc; i++) {
        argv[i] = mx_strtrim(argv[i]);
    }
    
    int err = mx_checkOnErrors(argc, argv);
    if (err == -1) {
        mx_doCorrectOperation(argv[1], argv[3], argv[4], argv[2][0]);
    }

    for (int i = 1; i < argc; i++) {
        free(argv[i]);
    }
    
    return 0;
}



enum e_operation get_operation(const char operation) {
    int result = SUB;
    if (operation ==  '+') {
        result = ADD;
    }
    else if (operation ==  '-') {
        result = SUB;
    }
    else if (operation ==  '*') {
        result = MUL;
    }
    else if (operation ==  '/') {
        result = DIV;
    }
    else if (operation ==  '%') {
        result = MOD;
    }
    return result;
}

t_operation *create_operation(const char op) {
    t_operation *operation = (t_operation *)malloc(sizeof(t_operation));
    operation->op = op;
    enum e_operation e_op = get_operation(operation->op);
    if (e_op == ADD) {
        operation->f = mx_add;
    }
    else if (e_op == SUB) {
        operation->f = mx_sub;
    }
    else if (e_op == MUL) {
        operation->f = mx_mul;
    }
    else if (e_op == DIV) {
        operation->f = mx_div;
    }
    else if (e_op == MOD) {
        operation->f = mx_mod;
    }
    return operation;
}
