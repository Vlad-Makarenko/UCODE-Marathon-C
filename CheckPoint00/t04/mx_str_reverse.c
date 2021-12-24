
int mx_strlen(const char *s){
    int index = 0;
    while (s[index] != '\0'){
        index++;
    }
    return index;
}

void mx_swap_char (char *s1, char *s2){
    char buf = *s1;
    *s1 = *s2;
    *s2 = buf;
}


void mx_str_reverse(char *s){
    int len = mx_strlen(s);
    for (int i = 0; i <= len / 2; ++i) {
        mx_swap_char(&s[i], &s[len - i - 1]);
    }
}

