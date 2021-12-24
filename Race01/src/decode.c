#include "decode.h"


int *mx_getArrOfCorrectElements(char *pattern, int *correct_len) {
    int length = mx_strlen(pattern);
    int factor = 1;

     if (pattern[0] == '-' || pattern[0] == '+') {
        length--;
        if (pattern[0] == '-') {
            factor = -1;
        }
        pattern++;
    }
    
    int max = mx_pow(10, length);


    int correctNum[max];
    int lastIdx = 0;

    int countQ = getCountQ(pattern);

    if (countQ == 0) {
        correctNum[lastIdx] = mx_atoi(pattern) * factor;
        lastIdx++;
    } else {
      int patternLen = mx_strlen(pattern);
        int number = getMinPattern(pattern);
        for (; number < max; number++) {
            char *numberStr = mx_itoa(number);
            int numberStrLen = mx_strlen(numberStr);

            
            int isCorrect = 1;
            for (int j = 0; j < numberStrLen; j++) {
                if (pattern[j + (patternLen - numberStrLen)] == '?') continue;
                if (pattern[j + (patternLen - numberStrLen)] != numberStr[j]) {
                    isCorrect = 0;
                    break;
                }
            }
            if (isCorrect) {
                correctNum[lastIdx] = number * factor;
                lastIdx++;
            }
            free(numberStr);
        } 
    }

    *correct_len = lastIdx;
    int *result = mx_copy_int_arr(correctNum, *correct_len);
    
    return result;
}



int getCountQ(char *pattern) {
    int count = 0;
    int len = mx_strlen(pattern);
    for (int i = 0; i < len; i++) {
        if (pattern[i] == '?') {
            count++;
        }
    }
    return count;
}
