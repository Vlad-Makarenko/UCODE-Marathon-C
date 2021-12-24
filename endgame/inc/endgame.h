#define SDL_ASSERT_LEVEL 0
#ifndef ENDGAME_H
#define ENDGAME_H

#include <stdio.h>
#include <stdbool.h>


#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_ttf/SDL_ttf.h"

// #include <unistd.h>
// #include <string.h>
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 800

static SDL_Renderer *g_renderer = NULL;
static SDL_Window *g_window = NULL;


SDL_Texture *blue_block;
SDL_Texture *green_block;
SDL_Texture *kyan_block;
SDL_Texture *orange_block;
SDL_Texture *pink_block;
SDL_Texture *packman_block;
SDL_Texture *right_full_mana;

SDL_Texture *transparrent_block;
SDL_Texture *background;


SDL_Texture *load_texture(char *path, SDL_Renderer *g_renderer);

int tetris(SDL_Renderer *g_renderer, int *p1_score, int *p2_score);

int game_over_menu(SDL_Renderer *ren, int p1_score, int p2_score);

#endif
