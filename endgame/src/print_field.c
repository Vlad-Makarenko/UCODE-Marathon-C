#include "tetromino.h"

void p1_init_field() {

    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < FIELD_HEIGHT; y++) {
            p1_field[x][y].color = NONE_COLOR;
        }
    }

}

void p2_init_field() {

    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < FIELD_HEIGHT; y++) {
            p2_field[x][y].color = NONE_COLOR;
        }
    }

}

void mana_p1_init_field() {

    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < 1; y++) {
            p1_field[x][y].color = NONE_COLOR;
        }
    }

}

void mana_p2_init_field() {

    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < 1; y++) {
            p2_field[x][y].color = NONE_COLOR;
        }
    }

}

SDL_Renderer * p1_print_field(SDL_Renderer *renderer) {

    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < FIELD_HEIGHT; y++) {
            if (p1_field[x][y].color != NONE_COLOR || true) {
                p1_print_block_on_field(x, y, renderer);
            }

        }
    }
    return renderer;
}

SDL_Renderer * p2_print_field(SDL_Renderer *renderer) {

    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < FIELD_HEIGHT; y++) {
            if (p2_field[x][y].color != NONE_COLOR || true) {
                p2_print_block_on_field(x, y, renderer);
            }

        }
    }
    return renderer;
}


SDL_Renderer * mana_p1_print_field(SDL_Renderer *renderer) {

    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < 1; y++) {
            if (true) {
                mana_p1_print_block_on_field(x, 0, renderer);
            }

        }
    }
    return renderer;
}

SDL_Renderer * mana_p2_print_field(SDL_Renderer *renderer) {

    for (int x = 0; x < FIELD_WIDTH; x++) {
        for (int y = 0; y < 1; y++) {
            if (mana_p2_field[x][0].color != NONE_COLOR) {
                mana_p2_print_block_on_field(x, 0, renderer);
            }

        }
    }
    return renderer;
}

