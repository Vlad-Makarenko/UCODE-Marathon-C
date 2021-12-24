
#include "calculator.h"

bool isCorrectOperand(char *operand){
    bool flag = true;
    while (*operand != '\0'){
        if (!mx_isdigit(*operand)){
            flag &= false;
        }
        operand++;
    }
    return flag;
}

int calc(int argc, char *argv[]){

    if (argc != 4){
        mx_printerr("usage: ./calc [operand1] [operation] [operand2]\n");
        return -1;
    }

    enum e_error error = -1;
    t_operation calc;

    int left = mx_atoi(argv[1]);
    char *oper = argv[2];
    int right = mx_atoi(argv[3]);

    if ((left == 0 && mx_strcmp(argv[1], "0") != 0)
        || (right == 0 &&  mx_strcmp(argv[3], "0") != 0)
        || !isCorrectOperand(argv[1])
        || !isCorrectOperand(argv[3])){
        error = INCORRECT_OPERAND;
    }
    if ((mx_strcmp(argv[2], "%") == 0 || mx_strcmp(argv[2], "/") == 0)
        && mx_strcmp(argv[3], "0") == 0){
        error = DIV_BY_ZERO;
    }
    if(mx_strcmp(oper, "+") == 0){
        calc.op = ADD;
        calc.f = mx_add;
    } else if (mx_strcmp(oper, "-") == 0){
        calc.op = SUB;
        calc.f = mx_sub;
    } else if (mx_strcmp(oper, "*") == 0){
        calc.op = MUL;
        calc.f = mx_mul;
    } else if (mx_strcmp(oper, "/") == 0){
        calc.op = DIV;
        calc.f = mx_div;
    } else if (mx_strcmp(oper, "%") == 0) {
        calc.op = MOD;
        calc.f = mx_mod;
    } else {
        error = INCORRECT_OPERATION;
    }

    if(error == INCORRECT_OPERAND){
        mx_printerr("error: invalid number\n");
        return -1;
    }
    if(error == INCORRECT_OPERATION){
        mx_printerr("error: invalid operation\n");
        return -1;
    }
    if (error == DIV_BY_ZERO){
        mx_printerr("error: division by zero\n");
        return -1;
    }


    mx_printint(calc.f(left, right));
    mx_printchar('\n');

    return 0;

}

