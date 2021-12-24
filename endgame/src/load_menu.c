#include "menu.h"

SDL_Texture *load_menu(char *filename, SDL_Renderer *ren) {
    bool ok = true;

    SDL_Surface * temp_surf = NULL;
    temp_surf = IMG_Load(filename);
    if (temp_surf == NULL) {
        printf("Can't load image: %s\n", IMG_GetError());
        ok = false;
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, temp_surf);
    if (texture == NULL) {
        printf("Can't create texture from surface: %s\n", SDL_GetError());
        ok = false;
        return NULL;
    }

    SDL_FreeSurface(temp_surf);
    temp_surf = NULL;


    return texture;
}
