#include "tetromino.h"

bool fill_mana_bar_p1(int width, int height, t_block mana_field[width][height]) {
    bool  flag = false;
    if(mana_field[FIELD_WIDTH - 1][0].color == RIGHT_FULL) {

        for(int x = 0; x < FIELD_WIDTH; x++) {
            mana_field[x][0].color = TRANSPARRENT_COLOR;
            flag = true;
        }
        return flag;
    } 
    if (mana_field[FIELD_WIDTH - 1][0].color != RIGHT_FULL){
        for(int x = 0; x < FIELD_WIDTH; x++) {
            if(mana_field[x][0].color == TRANSPARRENT_COLOR) {
                mana_field[x][0].color = RIGHT_FULL;
                mana_field[x + 1][0].color = RIGHT_FULL;

                break;
            }
        }
    }
    return flag;
}

bool fill_mana_bar_p2(int width, int height, t_block mana_field[width][height]) {
    bool  flag = false;
    if(mana_field[width- 1][0].color == RIGHT_FULL) { 


        for(int x = 0; x < FIELD_WIDTH; x++) {
            mana_field[x][0].color = TRANSPARRENT_COLOR;
            flag = true;
        }
    } 
    if (mana_field[FIELD_WIDTH - 1][0].color != RIGHT_FULL){
        for(int x = 0; x < FIELD_WIDTH; x++) {
            if(mana_field[x][0].color == TRANSPARRENT_COLOR) {
                mana_field[x][0].color = RIGHT_FULL;
                mana_field[x + 1][0].color = RIGHT_FULL;
                break;
            }
        }
    }
    return flag;
}
