#include "tetromino.h"

SDL_Renderer *p1_print_block_on_field(int x, int y, SDL_Renderer *renderer) {
    t_block block;
    block.color = p1_field[x][y].color;
    // block.color = ORANGE_COLOR;

    SDL_Rect position;
    position.x = LEFT_FIELD_ANCHOR_X + x * BRICK_D_SIZE;
    position.y = BOTTOM_FIELD_Y - y * BRICK_D_SIZE;
    position.h = BRICK_D_SIZE;
    position.w = BRICK_D_SIZE;
    SDL_Texture *block_texture = create_block(&block);
    SDL_RenderCopy(renderer, block_texture, NULL, &position);

    return renderer;
}


SDL_Renderer *p2_print_block_on_field(int x, int y, SDL_Renderer *renderer) {
    t_block block;
    block.color = p2_field[x][y].color;
    // block.color = ORANGE_COLOR;

    SDL_Rect position;
    position.x = RIGHT_FIELD_ANCHOR_X + x * BRICK_D_SIZE;
    position.y = BOTTOM_FIELD_Y - y * BRICK_D_SIZE;
    position.h = BRICK_D_SIZE;
    position.w = BRICK_D_SIZE;
    SDL_Texture *block_texture = create_block(&block);
    SDL_RenderCopy(renderer, block_texture, NULL, &position);

    return renderer;
}

SDL_Renderer *mana_p1_print_block_on_field(int x, int y, SDL_Renderer *renderer) {
    t_block block;
    block.color = mana_p1_field[x][y].color;
    // block.color = ORANGE_COLOR;

    SDL_Rect position;
    position.x = LEFT_FIELD_ANCHOR_X + x * BRICK_D_SIZE;
    position.y = BOTTOM_FIELD_Y - y * BRICK_D_SIZE + BRICK_D_SIZE;
    position.h = BRICK_D_SIZE;
    position.w = BRICK_D_SIZE;
    SDL_Texture *block_texture = create_block(&block);
    SDL_RenderCopy(renderer, block_texture, NULL, &position);

    return renderer;
}

SDL_Renderer *mana_p2_print_block_on_field(int x, int y, SDL_Renderer *renderer) {
    t_block block;
    block.color = mana_p2_field[x][y].color;
    // block.color = ORANGE_COLOR;

    SDL_Rect position;
    position.x = RIGHT_FIELD_ANCHOR_X + x * BRICK_D_SIZE;
    position.y = BOTTOM_FIELD_Y - y * BRICK_D_SIZE + BRICK_D_SIZE;
    position.h = BRICK_D_SIZE;
    position.w = BRICK_D_SIZE;
    SDL_Texture *block_texture = create_block(&block);
    SDL_RenderCopy(renderer, block_texture, NULL, &position);

    return renderer;
}
