#include "tetromino.h"

SDL_Texture *create_block(t_block *brick) 
{

    SDL_Texture *brick_texture = NULL;
    if (brick->color == ORANGE_COLOR) {
        brick_texture = orange_block;
    } else if (brick->color == GREEN_COLOR) {
        brick_texture = green_block;
    } else if (brick->color == KYAN_COLOR) {
        brick_texture = kyan_block;
    } else if (brick->color == PINK_COLOR) {
        brick_texture = pink_block;
    } else if (brick->color == BLUE_COLOR) {
        brick_texture = blue_block;
    } else if (brick->color == PACKMAN_COLOR) {
        brick_texture = packman_block;
    } else if (brick->color == RIGHT_FULL) {
        brick_texture = right_full_mana;
    } else if (brick->color == TRANSPARRENT_COLOR) {
        brick_texture = transparrent_block;
    } 
    return brick_texture;
}
