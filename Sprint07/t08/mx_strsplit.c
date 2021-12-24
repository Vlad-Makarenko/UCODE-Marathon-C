#include <stdlib.h>
#include <stdio.h>

void mx_strdel(char **str);

int mx_count_words(const char *str, char delimiter);

char *mx_strncpy(char *dst, const char *src, int len);

char *mx_strnew(const int size);

void mx_del_strarr(char ***arr);

char **mx_strsplit(char const *s, char c){
    if (s == NULL){
        return NULL;
    }
    int countForCopy = 0;
    int countWords = mx_count_words(s, c);
    char **res = malloc(countWords);
    for (int i = 0; i < countWords; ++i) {
        for (int j = 0; *s != '\0'; ++j) {
            if (*s == c){
                s++;
            } else if (*s != c){
                for (int k = 0; *(s + k) != c; ++k) {
                    countForCopy++;
                }
                res[i] = mx_strnew(countForCopy);
                mx_strncpy(res[i], s, countForCopy);
                for (int k = 0; k < countForCopy; ++k) {
                    s++;
                }
                countForCopy = 0;
                break;
            }
        }
    }
    res[countWords] = NULL;
    return res;
}

