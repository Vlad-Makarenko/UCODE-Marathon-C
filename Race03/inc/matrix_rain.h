#ifndef MATRIX_RAIN
#define MATRIX_RAIN

#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

#define SPEEDCHAR 300000
#define SPEEDBTW 500000
#define FRONT_COLOUR 1
#define SYMBOL_COLOUR 2


typedef struct s_vector2
{
    int x;
    int y;
}               t_vector2;

typedef struct s_drop {
    t_vector2 first;
    t_vector2 last;
    int length;
}              t_drop;

void mx_print_matrix(const t_vector2 *limit);

void mx_drop_char(t_drop *last, const t_vector2 *limit);

void mx_start_drop(t_drop *drop, t_vector2 start, const t_vector2 *limit);

void mx_print_charxy(int type, t_vector2 *coord, char value);

void printPhrases();

void mx_generate_x_idxs(int size, int arr[]);

int mx_strlen(const char *s);


#endif
