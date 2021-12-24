#include "calculator.h"

int mx_checkOnErrors(int argc, char *argv[]) {
    
    int result = -1;

    char *error_message;

    if (argc != 5) {
        error_message = createErrorMessage(INCORRECT_INPUT, NULL);
        mx_printerr(error_message);
        free(error_message);
        return INCORRECT_INPUT;
    }
    if (checkOperation(argv[2]) == INCORRECT_OPERATION) {
        error_message = createErrorMessage(INCORRECT_OPERATION, argv[2]);
        mx_printerr(error_message);
        free(error_message);
        return INCORRECT_OPERATION;
    }

    char *incorecct_operand = getIncorrectOperand(argv[1], argv[3]);
    if (incorecct_operand != NULL) {
        error_message = createErrorMessage(INCORRECT_OPERAND, incorecct_operand);
        mx_printerr(error_message);
        free(error_message);
        return INCORRECT_OPERAND;
    }

    char *incorecct_result = getIncorrectOperand(argv[4], NULL);
    if (incorecct_result != NULL) {
        error_message = createErrorMessage(INCORRECT_RESULT, incorecct_result);
        mx_printerr(error_message);
        free(error_message);
        return INCORRECT_RESULT;
    }
    
    return result;

}

char *createErrorMessage(enum e_error err, const char *error_arg) {

    char *error_messages[] = {
        "usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n",
        "Invalid operation: ",
        "Invalid operand: ",
        "Invalid result "
    };

    char *error_message;
    if (err == INCORRECT_INPUT) {
        error_message = mx_strnew(mx_strlen(error_messages[err]));
        mx_strcpy(error_message, error_messages[INCORRECT_INPUT]);
        return error_message;
    }

    error_message = mx_strnew(mx_strlen(error_messages[err]) 
                                        + mx_strlen(error_arg) + 1);
    mx_strcpy(error_message, error_messages[err]);
    mx_strcpy(error_message + mx_strlen(error_messages[err]), error_arg);
    mx_strcpy(error_message + mx_strlen(error_messages[err]) + mx_strlen(error_arg), "\n");
    return error_message;
}

char *getIncorrectOperand(char *left, char *right) {
    if (checkOnOperandError(left) == INCORRECT_OPERAND) return left;
    else if (right != NULL && checkOnOperandError(right) == INCORRECT_OPERAND) return right;
    else return NULL;
}

int checkOnOperandError(const char *operand) {
    int result = -1;
    int i = 0;

    while (mx_isspace(operand[i]))
    {
        i++;
    }
    
    if (operand[i] == '+' || operand[i] == '-') i++;

    while (operand[i] != '\0')
    {
        if ( mx_isdigit(operand[i]) || operand[i] == '?') {
            i++;
        } else {
            result = INCORRECT_OPERAND;
            break;
        }
    }
    
    return result;
}

int checkOperation(const char *operation) {
    int result = INCORRECT_OPERATION;
    if (mx_strlen(operation) == 1) {
        if (operation[0] == '?' ||
            operation[0] == '+' ||
            operation[0] == '-' ||
            operation[0] == '*' ||
            operation[0] == '/')
            result = -1;
    }
    return result;
}

int checkDiv(int right_operand) {
    if (right_operand == 0) return DIV_BY_ZERO;
    else return -1;
}
