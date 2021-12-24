#include "matrix_rain.h"

void mx_drop_char(t_drop *drop, const t_vector2 *limit) {


    char last_char = mvwinch(stdscr, drop->last.y, drop->last.x) & A_CHARTEXT;
    
    if (last_char == ' ') last_char++;

    mx_print_charxy(SYMBOL_COLOUR, &(drop->last), last_char);

    drop->last.y += 1;
    if (drop->last.y > limit->y - 1) {
        drop->last.y = 0;
    }


    last_char = rand() % 94 + 33;

    
    mx_print_charxy(FRONT_COLOUR, &(drop->last), last_char);
    
    int correct_length = drop->last.y - drop->first.y;

    if (correct_length < 0) correct_length = -correct_length;

    if (correct_length >= drop->length) {
        char space = ' ';
        mx_print_charxy(SYMBOL_COLOUR, &(drop->first), space);
        drop->first.y++;

        if (drop->first.y >= limit->y) {
            drop->first.y = 0;
        }

    }

}

void mx_start_drop(t_drop *drop, t_vector2 start, const t_vector2 *limit) {
    char buff[2];
    attron(COLOR_PAIR(FRONT_COLOUR));
    buff[0] = rand() % 94 + 33;
    buff[1] = '\0';
    mvprintw(start.y, start.x, buff);
    refresh();
    attroff(COLOR_PAIR(FRONT_COLOUR));

    drop->first.x = start.x;
    drop->first.y = start.y;

    int min_length = limit->y / 4;
    int max_length = limit->y / 3;
    drop->length = min_length + rand() % max_length;

    drop->last.x = start.x;
    drop->last.y = drop->first.y;

    start.y += 1;
}
