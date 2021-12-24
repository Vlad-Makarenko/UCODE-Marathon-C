#include <stdlib.h>

char *mx_strjoin(char const *s1, char const *s2);

void mx_strdel(char **str);

char *mx_strdup(const char *str);

char *mx_concat_words(char **words) {
    if (words == NULL){
        return NULL;
    }

    char *res = mx_strdup(words[0]);

    for (int i = 1; words[i] != NULL; i++) {
        char *temp = mx_strjoin(res, " ");
        mx_strdel(&res);
        res = mx_strjoin(temp, words[i]);
        mx_strdel(&temp);
    }
    return res;
}
