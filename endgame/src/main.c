#include "tetromino.h"
#include "menu.h"

int main() {
    srand(time(NULL));

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
        printf("Can't init: %s\n", SDL_GetError());

    if (TTF_Init() == -1)
        printf("TTF_Init: %s\n", TTF_GetError());

    // SDL_ASSERT_LEVEL = 0;

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());

    SDL_Window *win = NULL;
    SDL_Renderer *ren = NULL;

    win = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL) 
        printf("Can't create window: %s\n", SDL_GetError());

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) 
        printf("Can't create renderer: %s\n", SDL_GetError());

    int p1_score = 700;
    int p2_score = 400;
    

    int action = 0;

    while (true)
    {
        if (action == 0) action = main_menu(ren);
        if (action == 1) action = tetris(ren, &p1_score, &p2_score);
        if (action == 2) {
            action = game_over_menu(ren, p1_score, p2_score);
            p1_score = 0;
            p2_score = 0;
        }
        if (action == -1) {
            break;
        }
    }

    // game_over_menu(ren);
    // game_over_menu(ren, p1_score, p2_score);



    close_game(ren, win);

}


bool init()
{

    bool succes = true;
    init_tetrominos();
    p1_init_field();
    p2_init_field();
    mana_p1_init_field();
    mana_p2_init_field();

    return succes;
}

SDL_Texture *load_texture(char *path, SDL_Renderer *g_renderer)
{
    SDL_Texture *new_texture = NULL;

    SDL_Surface *loaded_surface = IMG_Load(path);

    if (loaded_surface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path, SDL_GetError());
    }
    else
    {
        new_texture = SDL_CreateTextureFromSurface(g_renderer, loaded_surface);

        if (new_texture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
        }

        SDL_FreeSurface(loaded_surface);
    }

    return new_texture;
}

bool load_media(SDL_Renderer *g_renderer){
    bool succes = true;

    blue_block = load_texture("resource/images/blocks/blue_block.png", g_renderer);
    green_block = load_texture("resource/images/blocks/green_block.png", g_renderer);
    kyan_block = load_texture("resource/images/blocks/kyan_block.png", g_renderer);
    orange_block = load_texture("resource/images/blocks/orange_block.png", g_renderer);
    pink_block = load_texture("resource/images/blocks/pink_block.png", g_renderer);
    transparrent_block = load_texture("resource/images/blocks/transparent_block.png", g_renderer);
    packman_block = load_texture("resource/images/blocks/packman_block.png", g_renderer);
    right_full_mana = load_texture("resource/images/blocks/right_full_mana.png", g_renderer);
    background = load_texture("resource/images/background/platform_tetris_background.png", g_renderer);

    return succes;
}

void close_game(SDL_Renderer *g_renderer, SDL_Window *g_window)
{
    // SDL_DestroyTexture(g_texture);
    g_texture = NULL;

    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
    g_window = NULL;
    g_renderer = NULL;

    SDL_Quit();
}
