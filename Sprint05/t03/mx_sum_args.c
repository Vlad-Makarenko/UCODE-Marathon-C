#include <stdbool.h>

bool mx_isdigit(int c);

bool mx_isspace (char c);

int mx_atoi(const char *str);

void mx_printchar(char c);

void mx_printint(int n);

int mx_strlen(const char *s){
    int index = 0;
    while (s[index] != '\0'){
        index++;
    }
    return index;
}


int main(int argc, char *argv[]){
    int arrArg[argc - 1];
    for (int i = 1; i < argc; ++i) {
        if ((argv[i][0] == '-' || argv[i][0] == '+' || mx_isdigit(argv[i][0]))
            && mx_isdigit(argv[i][mx_strlen(argv[i]) - 1])){
            if(argv[i][1] == '+' || argv[i][1] == '-'){
                arrArg[i - 1] = 0;
                continue;
            }
            if(argv[i][0] == '+'){
                argv[i]++;
            }

            arrArg[i - 1] = mx_atoi(argv[i]);
        } else {
            arrArg[i - 1] = 0;
        }
    }
    int res = 0;
    for (int i = 0; i < argc - 1; ++i) {
        res += arrArg[i];
    }
    mx_printint(res);
    mx_printchar('\n');

    return 0;
}


