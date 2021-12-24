#include "tetromino.h"

bool p1_check_x(t_tetromino **tetromino, SDL_Rect *left_anchor, int step) { // step is shift by x
    if (left_anchor->y <= 0) return false;

    t_tetromino *_tetromino = *tetromino;

    if (left_anchor->x + step < LEFT_FIELD_ANCHOR_X) {
        return false;
    }

    int field_index_y = (BOTTOM_FIELD_Y - left_anchor->y) / BRICK_D_SIZE;
    int field_index_x = ((left_anchor->x + step) - LEFT_FIELD_ANCHOR_X) / BRICK_D_SIZE;

    for (int x = 0; x < 4; x++){
        for (int y = 0; y < 4; y++){
            if (_tetromino->data[x][y] == 1){
                if (p1_field[field_index_x + x][field_index_y - y].color != NONE_COLOR){
                    return false;
                }
                if (field_index_x + x >= FIELD_WIDTH ) {
                    return false;
                }
            }
        }
    }
    return true;
}


bool p2_check_x(t_tetromino **tetromino, SDL_Rect *left_anchor, int step) { // step is shift by x
    if (left_anchor->y <= 0) return false;


    t_tetromino *_tetromino = *tetromino;

    if (left_anchor->x + step < RIGHT_FIELD_ANCHOR_X)
        return false;

    int field_index_y = (BOTTOM_FIELD_Y - left_anchor->y) / BRICK_D_SIZE;
    int field_index_x = ((left_anchor->x + step) - RIGHT_FIELD_ANCHOR_X) / BRICK_D_SIZE;


    for (int x = 0; x < 4; x++)  {
        for (int y = 0; y < 4; y++){      
            if (_tetromino->data[x][y] == 1){

                if (p2_field[field_index_x + x][field_index_y - y].color != NONE_COLOR){
                    return false;
                }

                if (field_index_x + x >= FIELD_WIDTH ) {
                    return false;
                }
            }

            
        }
    }
    return true;
}
