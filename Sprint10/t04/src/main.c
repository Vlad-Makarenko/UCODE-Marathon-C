#include "header.h"

int main(int argc, char *argv[]){

    int total_count_str = argc - 1;
    int total_count_words = 0;
    int total_count_bytes = 0;

    if (argc < 2){
        int count_str = 0;
        int count_words = 0;
        int count_bytes = 0;
        char sym;
        char tmp;
        while (read(0, &sym, 1)){
            if(mx_isspace(sym) && !mx_isspace(tmp)){
                count_words++;
                total_count_words++;
            }
            if (sym == '\n'){
                count_str++;
                total_count_str++;
            }
            count_bytes++;
            total_count_bytes++;
            tmp = sym;
        }
        mx_printchar('\t');
        mx_printint(count_str);
        mx_printchar('\t');
        mx_printint(count_words);
        mx_printchar('\t');
        mx_printint(count_bytes);
        mx_printchar('\n');
        return 0;
    }
    for (int i = 1; i < argc; ++i) {
        int count_str = 1;
        int count_words = 0;
        int count_bytes = 0;
        char sym;
        char tmp;
        int file = open(argv[i], O_RDONLY);

        if (errno){
            mx_printerr("mx_wc: ");
            mx_printerr(argv[i]);
            mx_printerr(": open: ");
            mx_printerr(strerror(errno));
            mx_printerr("\n");
            return 0;
        }

        while (read(file, &sym, 1)){
            if (errno){
                mx_printerr("mx_wc: ");
                mx_printerr(argv[i]);
                mx_printerr(": read: ");
                mx_printerr(strerror(errno));
                mx_printerr("\n");
                return 0;
            }
            if(mx_isspace(sym) && !mx_isspace(tmp)){
                count_words++;
                total_count_words++;
            }
            if (sym == '\n'){
                count_str++;
                total_count_str++;
            }
            count_bytes++;
            total_count_bytes++;
            tmp = sym;
        }
        if (!mx_isspace(tmp)) {
            count_words++;
            total_count_words++;
        }
        if (mx_isspace(tmp)){
            count_str--;
            total_count_str--;
        }
        close(file);
        if (errno){
            mx_printerr("mx_wc: ");
            mx_printerr(argv[i]);
            mx_printerr(": ");
            mx_printerr(strerror(errno));
            mx_printerr("\n");
            return 0;
        }
        mx_printchar('\t');
        mx_printint(count_str);
        mx_printchar('\t');
        mx_printint(count_words);
        mx_printchar('\t');
        mx_printint(count_bytes);
        mx_printchar(' ');
        mx_printstr(argv[i]);
        mx_printchar('\n');
    }
    if (argc > 2){
        mx_printchar('\t');
        mx_printint(total_count_str);
        mx_printchar('\t');
        mx_printint(total_count_words);
        mx_printchar('\t');
        mx_printint(total_count_bytes);
        mx_printchar(' ');
        mx_printstr("total");
        mx_printchar('\n');
    }
    return 0;
}


