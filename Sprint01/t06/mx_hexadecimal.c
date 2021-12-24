
void mx_printchar(char c);

void mx_hexadecimal(void){
    for (int i = 48; i <= 70; ++i) {
        if (i > 57 && i < 65){
            continue;
        }else {
            mx_printchar(i);
        }
    }
    mx_printchar('\n');
}

