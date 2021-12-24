
int mx_atoi(const char *str);

void mx_printchar(char c);

void mx_printint(int n);

int main(int argc, char *argv[]) {
    int arrArg[argc - 1];
    for (int i = 1; i < argc; ++i) {
        arrArg[i - 1] = mx_atoi(argv[i]);
    }
    for (int j = 0; j < argc - 1; ++j) {
        for (int i = 4 * 8 - 1; i >= 0; --i) {
            mx_printint((arrArg[j] >> i) & 1);
        }
        mx_printchar('\n');
    }
    return 0;
}
