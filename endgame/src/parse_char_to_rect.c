#include "tetromino.h"

void parse_char_to_rect(t_block *block, char data[4][4], SDL_Rect *anchor) {
    
    int last_block = 0;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (data[x][y] == 1) {
                block->rect[last_block].x = anchor->x + BRICK_D_SIZE * x;
                block->rect[last_block].y = anchor->y + BRICK_D_SIZE * y;
                block->rect[last_block].w = BRICK_D_SIZE;
                block->rect[last_block].h = BRICK_D_SIZE;
                last_block++;
            }
        }
    }
    
}
