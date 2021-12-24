#include <stdbool.h>

bool mx_isdigit(int c);

int mx_atoi(const char *str);

void mx_printchar(char c);

void mx_printint(int n);

int main(int argc, char *argv[]) {
    if(argc == 3){

        int firstNum = mx_atoi(argv[1]);
        int secondNum = mx_atoi(argv[2]);
        int lowNum;
        int mult;
        if (firstNum >= 0
            && firstNum < 10
            && secondNum >= 0
            && secondNum < 10
            && mx_isdigit(argv[1][0])
            && mx_isdigit(argv[2][0])){
            int stop = firstNum - secondNum;
            if (stop < 0){
                stop = -stop;
                lowNum = firstNum;
            } else{
                lowNum = secondNum;
            }
            mult = lowNum;
            int constLow = lowNum;
            for (int i = 0; i < stop + 1; ++i) {
                for (int j = 0; j < stop + 1; ++j) {
                    mx_printint(lowNum * mult);
                    if (j < stop){
                        mx_printchar('\t');
                    }
                    mult++;
                }
                lowNum++;
                mult = constLow;
                mx_printchar('\n');
            }
        }

    }
    return 0;
}
