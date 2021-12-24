
void mx_printchar(char c);

void mx_str_separate(const char *str, char delim){
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != delim) {
            mx_printchar(str[i]);
        } else if (str[i] == delim) {
            if (str[i + 1] != delim) {
                mx_printchar('\n');
            } else{
                continue;
            }
        }
    }
    mx_printchar('\n');
}

