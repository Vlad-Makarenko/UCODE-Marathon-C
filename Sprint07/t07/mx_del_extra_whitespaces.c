#include <stdbool.h>
#include <stdlib.h>

bool mx_isspace (char c);

int mx_strlen(const char *s);

char *mx_strnew(const int size);

char *mx_strncpy(char *dst, const char *src, int len);

char *mx_strtrim(const char *str);

void mx_strdel(char **str);

char *mx_del_extra_whitespaces(const char *str){
    if (str == NULL){
        return NULL;
    }
    char *newStr = mx_strtrim(str);
    char *temp = mx_strnew(mx_strlen(newStr));
    int resIdx = 0;
    bool isOneSpace = false;
    for (int i = 0; i < mx_strlen(newStr); ++i) {
        if (!mx_isspace(newStr[i])){
            temp[resIdx] = newStr[i];
            resIdx++;
            isOneSpace = true;
        } else if (mx_isspace(newStr[i]) && isOneSpace){
            temp[resIdx] = ' ';
            resIdx++;
            isOneSpace = false;
        }
    }
    char *res = mx_strnew(resIdx);
    mx_strncpy(res, temp, resIdx);
    mx_strdel(&temp);
    mx_strdel(&newStr);
    return res;
}

