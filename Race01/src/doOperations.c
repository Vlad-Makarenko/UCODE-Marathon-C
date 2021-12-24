#include "decode.h"

void mx_doCorrectOperation(char *left, char *right, char *result, char operation){

    if(operation == '?') {
        mx_doCorrectOperation(left, right, result, '+');
        mx_doCorrectOperation(left, right, result, '-');
        mx_doCorrectOperation(left, right, result, '*');
        mx_doCorrectOperation(left, right, result, '/');
        return;
    }


    int patternLen = mx_strlen(result);
    int rightCorrectLen = 0;
    int leftCorrectLen = 0;
    int *rightCorrect = mx_getArrOfCorrectElements(right, &rightCorrectLen);
    int *leftCorrect = mx_getArrOfCorrectElements(left, &leftCorrectLen);
    int minRes = getMinPattern(result);
    int maxRes = getMaxPattern(result);
    if (result[0] == '-'){
        int buf = maxRes;
        maxRes = minRes;
        minRes = buf;
    }
    for (int leftIdx = 0; leftIdx < leftCorrectLen; leftIdx++) {
        for (int rightIdx = 0; rightIdx < rightCorrectLen; rightIdx++) {
            int number = 0;
            if (operation == '+') {
                number = leftCorrect[leftIdx] + rightCorrect[rightIdx];
            } else if (operation == '-') {
                number = leftCorrect[leftIdx] - rightCorrect[rightIdx];
            } else if (operation == '*') {
                number = leftCorrect[leftIdx] * rightCorrect[rightIdx];
            } else if (operation == '/') {
                if (rightCorrect[rightIdx] == 0) continue;
                number = leftCorrect[leftIdx] / rightCorrect[rightIdx];
            }
            if(number >= minRes && number <= maxRes){
                char *numberStr = mx_itoa(number);
                int numberStrLen = mx_strlen(numberStr);



                int isCorrect = 1;
                for (int j = 0; j < numberStrLen; j++) {
                    if (result[j + (patternLen - numberStrLen)] == '?') continue;
                    if (result[j + (patternLen - numberStrLen)] != numberStr[j]) {
                        isCorrect = 0;
                        break;
                    }
                }
                if (isCorrect) {
                    mx_printResult(leftCorrect[leftIdx], rightCorrect[rightIdx], numberStr, operation);
                }
                free(numberStr);
            }
        }
    }
    free(rightCorrect);
    free(leftCorrect);
}
