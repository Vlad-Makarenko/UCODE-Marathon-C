#include "menu.h"

void quit_new1(TTF_Font *font, SDL_Texture *background, SDL_Texture *button_menu, SDL_Texture *button_menu_mover, SDL_Texture *button_retry,
            SDL_Texture *button_retry_mover, SDL_Texture *game_over, SDL_Texture *p1_score_texture, SDL_Texture *p2_score_texture, 
            SDL_Texture *texture_1, SDL_Texture *texture_2, Mix_Chunk *click_button_sound);

int game_over_menu(SDL_Renderer *ren, int p1_score, int p2_score) {

    char p1_score_text[10];
    char p2_score_text[10];

    sprintf(p1_score_text, "%i", p1_score);
    sprintf(p2_score_text, "%i", p2_score);

    bool exit = false;
    SDL_Event event;

    TTF_Font *font = NULL;

    Mix_Chunk *click_button_sound = NULL;

    SDL_Texture *background = NULL;
    SDL_Texture *button_menu = NULL;
    SDL_Texture *button_menu_mover = NULL;
    SDL_Texture *button_retry = NULL;
    SDL_Texture *button_retry_mover = NULL;
    SDL_Texture *game_over = NULL;
    SDL_Texture *p1_score_texture = NULL;
    SDL_Texture *p2_score_texture = NULL;
    SDL_Texture *texture_1 = NULL;
    SDL_Texture *texture_2 = NULL;

    Mix_Chunk *game_over_sound = NULL;

    SDL_Rect viewport_btn_menu;
    SDL_Rect viewport_btn_retry;
    SDL_Rect viewport_game_over;
    SDL_Rect viewport_winner_score;
    SDL_Rect viewport_loser_score;
    SDL_Rect viewport_winner;
    SDL_Rect viewport_loser;

    SDL_Color color_white = {255, 255, 255, 0};


    click_button_sound = Mix_LoadWAV("./resource/audio/sound/click_button.wav");


    background = load_menu("./resource/images/background/background2.png", ren);
    button_menu = load_menu("./resource/images/game_over/button_menu.png", ren);
    button_menu_mover = load_menu("./resource/images/game_over/button_menu_mover.png", ren);
    button_retry = load_menu("./resource/images/game_over/button_retry.png", ren);
    button_retry_mover = load_menu("./resource/images/game_over/button_retry_mover.png", ren);
    game_over = load_menu("./resource/images/game_over/game_over.png", ren);

    game_over_sound = Mix_LoadWAV("./resource/audio/sound/game_over.wav");

    font = TTF_OpenFont("./resource/fonts/font.ttf", 70);
    if(!font) 
        printf("TTF_OpenFont: %s\n", TTF_GetError());


    viewport_btn_menu.x = 844;
    viewport_btn_menu.y = 450;
    viewport_btn_menu.w = 267;
    viewport_btn_menu.h = 90;

    viewport_btn_retry.x = 470;
    viewport_btn_retry.y = 450;
    viewport_btn_retry.w = 267;
    viewport_btn_retry.h = 90;

    viewport_game_over.x = 408;
    viewport_game_over.y = 105;
    viewport_game_over.w = 785;
    viewport_game_over.h = 495;

    viewport_winner_score.x = 955;
    viewport_winner_score.y = 290;
    viewport_winner_score.w = 100;
    viewport_winner_score.h = 39;

    viewport_loser_score.x = 955;
    viewport_loser_score.y = 360;
    viewport_loser_score.w = 100;
    viewport_loser_score.h = 39;
    
    viewport_winner.x = 800;
    viewport_winner.y = 290;
    viewport_winner.w = 36;
    viewport_winner.h = 39;

    viewport_loser.x = 800;
    viewport_loser.y = 360;
    viewport_loser.w = 36;
    viewport_loser.h = 39;

    SDL_Surface *p1_score_surface = TTF_RenderText_Solid(font, p1_score_text, color_white);
    SDL_Surface *p2_score_surface = TTF_RenderText_Solid(font, p2_score_text, color_white);
    SDL_Surface *surface_1 = TTF_RenderText_Solid(font, "1", color_white);
    SDL_Surface *surface_2 = TTF_RenderText_Solid(font, "2", color_white);

    if(p1_score_surface == NULL || p2_score_surface == NULL) 
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );

    p1_score_texture = SDL_CreateTextureFromSurface(ren, p1_score_surface);
    p2_score_texture = SDL_CreateTextureFromSurface(ren, p2_score_surface);
    texture_1 = SDL_CreateTextureFromSurface(ren, surface_1);
    texture_2 = SDL_CreateTextureFromSurface(ren, surface_2);

Mix_PlayChannel(-1, game_over_sound, 0);

    while (!exit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) 
                exit = true;
        }


        SDL_SetRenderDrawColor(ren, 0xff, 0xff, 0xff, 0x00);

        SDL_RenderClear(ren);

        SDL_RenderCopy(ren, background, NULL, NULL);

        SDL_RenderCopy(ren, game_over, NULL, &viewport_game_over);
        SDL_RenderCopy(ren, button_menu, NULL, &viewport_btn_menu);
        SDL_RenderCopy(ren, button_retry, NULL, &viewport_btn_retry);

        
       

        if (p1_score > p2_score) {
            SDL_RenderCopy(ren, texture_1, NULL, &viewport_winner);
            SDL_RenderCopy(ren, texture_2, NULL, &viewport_loser);
            SDL_RenderCopy(ren, p1_score_texture, NULL, &viewport_winner_score);
            SDL_RenderCopy(ren, p2_score_texture, NULL, &viewport_loser_score);
        }

        else if (p1_score < p2_score) {
            SDL_RenderCopy(ren, texture_2, NULL, &viewport_winner);
            SDL_RenderCopy(ren, texture_1, NULL, &viewport_loser);
            SDL_RenderCopy(ren, p2_score_texture, NULL, &viewport_winner_score);
            SDL_RenderCopy(ren, p1_score_texture, NULL, &viewport_loser_score);
        }

        else {
            p2_score += 25;
            sprintf(p2_score_text, "%i", p2_score);
            SDL_Surface *p2_score_surface_new = TTF_RenderText_Solid(font, p2_score_text, color_white);
            SDL_Texture *p2_score_texture_new = SDL_CreateTextureFromSurface(ren, p2_score_surface_new);

            SDL_RenderCopy(ren, texture_2, NULL, &viewport_winner);
            SDL_RenderCopy(ren, texture_1, NULL, &viewport_loser);
            SDL_RenderCopy(ren, p2_score_texture_new, NULL, &viewport_winner_score);
            SDL_RenderCopy(ren, p1_score_texture, NULL, &viewport_loser_score);
        }


         if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            int mouse_x, mouse_y;
            SDL_GetMouseState(&mouse_x, &mouse_y);

            bool mouse_inside_button_menu = true;
            bool mouse_inside_button_retry = true;

    
            if (mouse_x < viewport_btn_menu.x)
                mouse_inside_button_menu = false;
            else if (mouse_x > viewport_btn_menu.x + viewport_btn_menu.w)
                mouse_inside_button_menu = false;
            else if (mouse_y < viewport_btn_menu.y)
                mouse_inside_button_menu = false;
            else if (mouse_y > viewport_btn_menu.y + viewport_btn_menu.h)
                mouse_inside_button_menu = false;

            if (mouse_x < viewport_btn_retry.x)
                mouse_inside_button_retry = false;
            else if (mouse_x > viewport_btn_retry.x + viewport_btn_retry.w)
                mouse_inside_button_retry = false;
            else if (mouse_y < viewport_btn_retry.y)
                mouse_inside_button_retry = false;
            else if (mouse_y > viewport_btn_retry.y + viewport_btn_retry.h)
                mouse_inside_button_retry = false;

            
            if (mouse_inside_button_retry) {
                switch(event.type) {
                    case SDL_MOUSEMOTION:
                        SDL_RenderCopy(ren, button_retry_mover, NULL, &viewport_btn_retry);
                        break;
                
                    // retry
                    case SDL_MOUSEBUTTONDOWN:
                        SDL_RenderCopy(ren, button_retry, NULL, &viewport_btn_retry);
                        Mix_PlayChannel(-1, click_button_sound, 0);
                        SDL_RenderCopy(ren, button_retry_mover, NULL, &viewport_btn_retry);
                        SDL_Delay(150);
                            quit_new1(font, background, button_menu, button_menu_mover, button_retry, button_retry_mover, game_over, p1_score_texture,
                            p2_score_texture, texture_1, texture_2, click_button_sound);
                        return 1;
                        break;
                }
            }

            if (mouse_inside_button_menu) {
                switch(event.type) {
                    case SDL_MOUSEMOTION:
                        SDL_RenderCopy(ren, button_menu_mover, NULL, &viewport_btn_menu);
                        break;
                
                    // go to menu
                    case SDL_MOUSEBUTTONDOWN:
                        SDL_RenderCopy(ren, button_menu, NULL, &viewport_btn_menu);
                        Mix_PlayChannel(-1, click_button_sound, 0);
                        SDL_RenderCopy(ren, button_menu_mover, NULL, &viewport_btn_menu);
                        SDL_Delay(150);
                            quit_new1(font, background, button_menu, button_menu_mover, button_retry, button_retry_mover, game_over, p1_score_texture,
                            p2_score_texture, texture_1, texture_2, click_button_sound);
                        Mix_HaltMusic();
                        return 0;

                        break;
                }
            }     
        }
        SDL_RenderPresent(ren);
    }
    quit_new1(font, background, button_menu, button_menu_mover, button_retry, button_retry_mover, game_over, p1_score_texture,
    p2_score_texture, texture_1, texture_2, click_button_sound);
    return -1;
}

void quit_new1(TTF_Font *font, SDL_Texture *background, SDL_Texture *button_menu, SDL_Texture *button_menu_mover, SDL_Texture *button_retry,
            SDL_Texture *button_retry_mover, SDL_Texture *game_over, SDL_Texture *p1_score_texture, SDL_Texture *p2_score_texture, 
            SDL_Texture *texture_1, SDL_Texture *texture_2, Mix_Chunk *click_button_sound) {
    
    SDL_DestroyTexture(background);
    background = NULL;
    SDL_DestroyTexture(button_menu);
    button_menu = NULL;
    SDL_DestroyTexture(button_menu_mover);
    button_menu_mover = NULL;
    SDL_DestroyTexture(button_retry);
    button_retry = NULL;
    SDL_DestroyTexture(button_retry_mover);
    button_retry_mover = NULL;
    SDL_DestroyTexture(game_over);
    game_over = NULL;
    SDL_DestroyTexture(p1_score_texture);
    p1_score_texture = NULL;
    SDL_DestroyTexture(p2_score_texture);
    p2_score_texture = NULL;
    SDL_DestroyTexture(texture_1);
    texture_1 = NULL;
    SDL_DestroyTexture(texture_2);
    texture_2 = NULL;

    Mix_FreeChunk(click_button_sound);
    click_button_sound = NULL;
    
    TTF_CloseFont(font);
    font = NULL;

}
