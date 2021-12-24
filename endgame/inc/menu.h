#ifndef MENU_H
#define MENU_H

// static const int SCREEN_WIDTH = 1600;
// static const int SCREEN_HEIGHT = 900;
#define SDL_ASSERT_LEVEL 0

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
// #include <SDL2/SDL_timer.h>

#include "endgame.h"



int main_menu(SDL_Renderer *ren);

SDL_Texture *load_menu(char *filename, SDL_Renderer *ren);

#endif
