#include "matrix_rain.h"


int main() {
    srand(time(NULL));

    initscr();
    start_color();
    init_pair(FRONT_COLOUR, COLOR_WHITE, COLOR_BLACK);
    init_pair(SYMBOL_COLOUR, COLOR_GREEN, COLOR_BLACK);
    curs_set(0);

    printPhrases();

    t_vector2 limit = {0, 0};
    int max_x = 0, max_y = 0;
    int matrix_arr_size_y = 0;
    getmaxyx(stdscr, max_y, max_x);
    matrix_arr_size_y = max_y / 2;

    limit.x = max_x;
    limit.y = max_y;

    mx_print_matrix(&limit);
    
}
