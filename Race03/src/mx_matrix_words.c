#include "matrix_rain.h"

void printPhrases(){

    char phrase1[] = "Wake up , Neo..";
    char phrase2[] = "The Matrix has you..";
    char phrase3[] = "Follow the white rabbit";
    char phrase4[] = "Knock, knock, Neo";
    int x = 4;
    int y = 4;
    int bufX = x;

    attrset(COLOR_PAIR(SYMBOL_COLOUR));
    for (int i = 0; i < 15; ++i) {
        move(y, bufX++);
        addch(phrase1[i]);
        usleep(SPEEDCHAR);
        refresh();
    }
    bufX = x;
    usleep(SPEEDBTW);
    refresh();
    clear();
    for (int i = 0; i < 20; ++i) {
        move(y, bufX++);
        addch(phrase2[i]);
        usleep(SPEEDCHAR);
        refresh();
    }
    bufX = x;
    usleep(SPEEDBTW);
    refresh();
    clear();
    for (int i = 0; i < 23; ++i) {
        move(y, bufX++);
        addch(phrase3[i]);
        usleep(SPEEDCHAR);
        refresh();
    }
    bufX = x;
    usleep(SPEEDBTW);
    refresh();
    clear();
    for (int i = 0; i < 17; ++i) {
        move(y, bufX++);
        addch(phrase4[i]);
        usleep(SPEEDCHAR);
        refresh();
    }
    usleep(SPEEDBTW);
    refresh();
    clear();
    attroff(COLOR_PAIR(SYMBOL_COLOUR));
}
