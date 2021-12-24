#include "matrix_rain.h"


void mx_print_charxy(int type, t_vector2 *coord, char value) {
    attron(COLOR_PAIR(type));
    char buff[2];
    buff[0] = value;
    buff[1] = '\0';
    mvprintw(coord->y, coord->x, buff);
    refresh();
    attroff(COLOR_PAIR(SYMBOL_COLOUR));
}
