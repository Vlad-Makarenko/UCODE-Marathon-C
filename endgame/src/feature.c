#include "tetromino.h"

void landslide_feature(int width, int height, t_block field[width][height] ) {

    for(int i = 0; i < FIELD_HEIGHT; i++) {
        for(int x = 0; x < FIELD_WIDTH; x++) {
            for(int y = 1; y < FIELD_HEIGHT; y++) {
                if(field[x][y - 1].color == NONE_COLOR && field[x][y].color != NONE_COLOR) {
                    field[x][y - 1].color = field[x][y].color;
                    field[x][y].color = TRANSPARRENT_COLOR; 
                }
            }
        }
    }

}

void illusion_feature(t_tetromino **block) {
    *block = &tetrominos[rand() % TETROMINOS_SIZE];
}

void packman_feature(t_tetromino **block) {
    (*block)->color = PACKMAN_COLOR;
}


void eat_blocks(int width, int height, t_block field[width][height], t_tetromino **block){
    for(int i = 0; i < FIELD_HEIGHT; i++) {
        for(int x = 0; x < FIELD_WIDTH; x++) {
            for(int y = 1; y < FIELD_HEIGHT; y++) {
                if((field[x][y].color == PACKMAN_COLOR) 
                    || (field[x][y - 1].color != NONE_COLOR && field[x][y - 1].color == PACKMAN_COLOR) 
                    || (field[x][y - 1].color != NONE_COLOR && field[x][y - 1].color == TRANSPARRENT_COLOR)) {
                    field[x][y - 1].color = PACKMAN_COLOR;
                    field[x][y].color = TRANSPARRENT_COLOR; 
                }
            }
        }
        for(int check = 0; check < FIELD_HEIGHT; check++) {
            if (field[check][FIELD_HEIGHT].color == PACKMAN_COLOR){
                field[check][FIELD_HEIGHT].color = TRANSPARRENT_COLOR;
            }
        }
        if (field[0][0].color == PACKMAN_COLOR)
        {
            field[0][0].color = TRANSPARRENT_COLOR;
        }
        
    }
    (*block)->color = (*block)->next->color;
}
