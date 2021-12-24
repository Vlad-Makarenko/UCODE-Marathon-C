#include "decode.h"

int getMinPattern(char *pattern) {
    int len = mx_strlen(pattern);
    char *patternMin = malloc(sizeof(*pattern) * len);
    mx_strcpy(patternMin, pattern);

    patternMin[len] = '\0';
    for (int i = 0; i < len; i++) {
        if (pattern[i] == '?') {
            patternMin[i] = '0';
        } else {
            patternMin[i] = pattern[i];
        }
    }

    int min = mx_atoi(patternMin);
    free(patternMin);
    return min;
}

int getMaxPattern(char *pattern) {
    int len = mx_strlen(pattern);
    char *patternMax = malloc(sizeof(*pattern) * len);
    mx_strcpy(patternMax, pattern);

    for (int i = 0; i < len; i++) {
        if (pattern[i] == '?') {
            patternMax[i] = '9';

        } else {
            patternMax[i] = pattern[i];
        }
    }

    int max = mx_atoi(patternMax);
    free(patternMax);
    return max;
}
