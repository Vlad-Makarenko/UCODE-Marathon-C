
void mx_printchar(char c);

void mx_pyramid(int n) {
    if (n % 2 == 0
        && n > 1) {

        int countLeftDiagonal = n;
        int countSpaceBefore = countLeftDiagonal - 1;
        int countSpaceMid = -1;
        int countSpaceAfterMid = 0;

        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < countSpaceBefore; ++j) {
                mx_printchar(' ');
            }
            countSpaceBefore--;
            mx_printchar('/');
            for (int j = 0; j < countSpaceMid; ++j) {
                mx_printchar(' ');
            }
            countSpaceMid += 2;
            if (i != 0) {
                mx_printchar('\\');
            }
            for (int j = 0; j < countSpaceAfterMid; ++j) {
                mx_printchar(' ');
            }
            countSpaceAfterMid++;
            mx_printchar('\\');
            mx_printchar('\n');
        }
        countSpaceAfterMid--;
        for (int i = 0; i < n / 2 - 1; i++) {
            for (int j = 0; j < countSpaceBefore; ++j) {
                mx_printchar(' ');
            }
            countSpaceBefore--;
            mx_printchar('/');
            for (int j = 0; j < countSpaceMid; ++j) {
                mx_printchar(' ');
            }
            countSpaceMid += 2;

            mx_printchar('\\');
            for (int j = 0; j < countSpaceAfterMid; ++j) {
                mx_printchar(' ');
            }
            countSpaceAfterMid--;
            mx_printchar('|');
            mx_printchar('\n');
        }
        mx_printchar('/');
        for (int i = 0; i < (2 * n) - 3; i++) {
                mx_printchar('_');
        }
        mx_printchar('\\');
        mx_printchar('|');
        mx_printchar('\n');
    }
}

