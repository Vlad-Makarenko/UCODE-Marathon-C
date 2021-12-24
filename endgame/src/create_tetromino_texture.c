#include "tetromino.h"

SDL_Renderer *create_tetromino_texture(t_tetromino *tetromino, SDL_Rect *anchor, SDL_Renderer *renderer) { // anchor - top left
    t_block block;
    block.color = tetromino->color;
    SDL_Texture *brick_0 = create_block(&block);
    parse_char_to_rect(&block, tetromino->data, anchor);

    SDL_RenderCopy( renderer, brick_0, NULL, &block.rect[0]);
    SDL_RenderCopy( renderer, brick_0, NULL, &block.rect[1] );
    SDL_RenderCopy( renderer, brick_0, NULL, &block.rect[2] );
    SDL_RenderCopy( renderer, brick_0, NULL, &block.rect[3] );

    return renderer; 
}
