#include "menu.h"

void quit_new(SDL_Texture *background_menu_animation1[], SDL_Texture *background_controls_animation1[], SDL_Texture *button_start1, 
    SDL_Texture *button_controls1, SDL_Texture *button_quit1, SDL_Texture *button_start_mover1, 
    SDL_Texture *button_controls_mover1, SDL_Texture *button_quit_mover1,
    SDL_Texture *controls_left1, SDL_Texture *controls_right1, SDL_Texture *controls_text1, SDL_Texture *controls_button_back1,
    SDL_Texture *music_on1, SDL_Texture *music_on_mover1, SDL_Texture *music_off1, SDL_Texture *music_off_mover1,
    SDL_Texture *mute1, SDL_Texture *mute_mover1, SDL_Texture *unmute1, SDL_Texture *unmute_mover1, Mix_Chunk *click_button_sound1, Mix_Chunk *pause_sound1,
    Mix_Chunk *portal_sound1, Mix_Chunk *game_over_sound1, Mix_Chunk *end_for_one_player_sound1, Mix_Chunk *quit_sound1, Mix_Music *menu_music1, TTF_Font *font_RaM1, 
    TTF_Font *font_RaM_outline1);

int main_menu(SDL_Renderer *ren) {

    // measure bricks 
    TTF_Font *font_RaM = NULL;
    TTF_Font *font_RaM_outline = NULL;
    SDL_Texture *measure_bricks_texture = NULL;
    SDL_Texture *measure_bricks_outline_texture = NULL;
    
    SDL_Rect viewport_measure_bricks;
    SDL_Rect viewport_outline_measure_bricks;


    // music
    Mix_Music *menu_music = NULL;

    // sound effects
    Mix_Chunk *click_button_sound = NULL;
    Mix_Chunk *pause_sound = NULL;
    Mix_Chunk *portal_sound = NULL;
    Mix_Chunk *game_over_sound = NULL;
    Mix_Chunk *end_for_one_player_sound = NULL;
    Mix_Chunk *quit_sound = NULL;


    // buttons menu
    SDL_Texture *button_start = NULL;
    SDL_Texture *button_controls = NULL;
    SDL_Texture *button_quit = NULL;
    SDL_Texture *button_start_mover = NULL;
    SDL_Texture *button_controls_mover = NULL;
    SDL_Texture *button_quit_mover = NULL;

    


    SDL_Rect viewport_btn_start;
    SDL_Rect viewport_btn_controls;
    SDL_Rect viewport_btn_quit;


    // controls 
    SDL_Texture *controls_left = NULL;
    SDL_Texture *controls_right = NULL;
    SDL_Texture *controls_text = NULL;
    SDL_Texture *controls_button_back = NULL;

   

    SDL_Rect viewport_controls_left;
    SDL_Rect viewport_controls_right;
    SDL_Rect viewport_controls_text;


    // buttons controls
    SDL_Texture *music_on = NULL;
    SDL_Texture *music_on_mover = NULL;
    SDL_Texture *music_off = NULL;
    SDL_Texture *music_off_mover = NULL;
    SDL_Texture *mute = NULL;
    SDL_Texture *mute_mover = NULL;
    SDL_Texture *unmute = NULL;
    SDL_Texture *unmute_mover = NULL;
    

    SDL_Rect viewport_controls_button_back;
    SDL_Rect viewport_music_button;
    SDL_Rect viewport_sound_button;


    // colors
    SDL_Color color_black = {0, 0, 0, 0};
    SDL_Color color_white = {255, 255, 255, 0};



    // background menu 
    SDL_Texture *b0 = NULL;
    SDL_Texture *b1 = NULL;
    SDL_Texture *b2 = NULL;
    SDL_Texture *b3 = NULL;
    SDL_Texture *b4 = NULL;
    SDL_Texture *b5 = NULL;
    SDL_Texture *b6 = NULL;
    SDL_Texture *b7 = NULL;
    SDL_Texture *b8 = NULL;
    SDL_Texture *b9 = NULL;
    SDL_Texture *b10 = NULL;
    SDL_Texture *b11 = NULL;
    SDL_Texture *b12 = NULL;
    SDL_Texture *b13 = NULL;
    SDL_Texture *b14 = NULL;
    SDL_Texture *b15 = NULL;
    SDL_Texture *b16 = NULL;
    SDL_Texture *b17 = NULL;


    // background controls
    SDL_Texture *bc0 = NULL;
    SDL_Texture *bc1 = NULL;
    SDL_Texture *bc2 = NULL;
    SDL_Texture *bc3 = NULL;
    SDL_Texture *bc4 = NULL;
    SDL_Texture *bc5 = NULL;
    SDL_Texture *bc6 = NULL;
    SDL_Texture *bc7 = NULL;
    SDL_Texture *bc8 = NULL;
    SDL_Texture *bc9 = NULL;
    SDL_Texture *bc10 = NULL;


    menu_music = Mix_LoadMUS("./resource/audio/menu_music.wav");
    if(menu_music == NULL)
        printf( "Failed to load_menu beat music! SDL_mixer Error: %s\n", Mix_GetError() );

    click_button_sound = Mix_LoadWAV("./resource/audio/sound/click_button.wav");
    pause_sound = Mix_LoadWAV("./resource/audio/sound/pause.wav");
    portal_sound = Mix_LoadWAV("./resource/audio/sound/portal.wav");
    game_over_sound = Mix_LoadWAV("./resource/audio/sound/game_over.wav");
    end_for_one_player_sound = Mix_LoadWAV("./resource/audio/sound/end_for_one_player.wav");
    quit_sound = Mix_LoadWAV("./resource/audio/sound/quit.wav");


    // load_menu background menu images
    b0 = load_menu("./resource/images/background/background_menu/0.png", ren);
    b1 = load_menu("./resource/images/background/background_menu/1.png", ren);
    b2 = load_menu("./resource/images/background/background_menu/2.png", ren);
    b3 = load_menu("./resource/images/background/background_menu/3.png", ren);
    b4 = load_menu("./resource/images/background/background_menu/4.png", ren);
    b5 = load_menu("./resource/images/background/background_menu/8.png", ren);
    b6 = load_menu("./resource/images/background/background_menu/12.png", ren);
    b7 = load_menu("./resource/images/background/background_menu/16.png", ren);
    b8 = load_menu("./resource/images/background/background_menu/19.png", ren);
    b9 = load_menu("./resource/images/background/background_menu/20.png", ren);
    b10 = load_menu("./resource/images/background/background_menu/23.png", ren);
    b11 = load_menu("./resource/images/background/background_menu/27.png", ren);
    b12 = load_menu("./resource/images/background/background_menu/31.png", ren);
    b13 = load_menu("./resource/images/background/background_menu/35.png", ren);
    b14 = load_menu("./resource/images/background/background_menu/39.png", ren);
    b15 = load_menu("./resource/images/background/background_menu/40.png", ren);
    b16 = load_menu("./resource/images/background/background_menu/41.png", ren);
    b17 = load_menu("./resource/images/background/background_menu/42.png", ren);


    // load_menu bacground controls images
    bc0 = load_menu("./resource/images/background/background_controls/0.png", ren);
    bc1 = load_menu("./resource/images/background/background_controls/1.png", ren);
    bc2 = load_menu("./resource/images/background/background_controls/2.png", ren);
    bc3 = load_menu("./resource/images/background/background_controls/3.png", ren);
    bc4 = load_menu("./resource/images/background/background_controls/4.png", ren);
    bc5 = load_menu("./resource/images/background/background_controls/5.png", ren);
    bc6 = load_menu("./resource/images/background/background_controls/6.png", ren);
    bc7 = load_menu("./resource/images/background/background_controls/7.png", ren);
    bc8 = load_menu("./resource/images/background/background_controls/8.png", ren);
    bc9 = load_menu("./resource/images/background/background_controls/9.png", ren);
    bc10 = load_menu("./resource/images/background/background_controls/10.png", ren);


    // load_menu button menu images
    button_start = load_menu("./resource/images/buttons/button_start.png", ren);
    button_controls = load_menu("./resource/images/buttons/button_controls.png", ren);
    button_quit = load_menu("./resource/images/buttons/button_quit.png", ren);
    button_start_mover = load_menu("./resource/images/buttons/button_start_mover.png", ren);
    button_controls_mover = load_menu("./resource/images/buttons/button_controls_mover.png", ren);
    button_quit_mover = load_menu("./resource/images/buttons/button_quit_mover.png", ren);


    // load_menu controls content
    controls_left = load_menu("./resource/images/controls/controls_left.png", ren);
    controls_right = load_menu("./resource/images/controls/controls_right.png", ren);
    controls_text = load_menu("./resource/images/controls/controls_text.png", ren);
    controls_button_back = load_menu("./resource/images/buttons/controls_button_back.png", ren);
    music_off = load_menu("./resource/images/buttons/music_on_btn_clicked.png", ren);
    music_off_mover = load_menu("./resource/images/buttons/music_on_btn.png", ren);
    music_on = load_menu("./resource/images/buttons/music_off_btn_clicked.png", ren);
    music_on_mover = load_menu("./resource/images/buttons/music_off_btn.png", ren);
    mute = load_menu("./resource/images/buttons/unmute_btn_clicked.png", ren);
    mute_mover = load_menu("./resource/images/buttons/unmute_btn.png", ren);
    unmute = load_menu("./resource/images/buttons/mute_btn_clicked.png", ren);
    unmute_mover = load_menu("./resource/images/buttons/mute_btn.png", ren);
    

    bool exit = false;

    SDL_Event event;


    const int background_menu_animation_count = 18;
    const int background_menu_animation_delay = 15;

    SDL_Texture *background_menu_animation[] = {
        b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17 
    };

    bool reverse_backround_menu_animation = false;
    int current_background_menu_animation = 0;
    int current_background_menu_animation_delay = 0;


    const int background_controls_animation_count = 11;
    SDL_Texture *background_controls_animation[] = {
        bc0, bc1, bc2, bc3, bc4,  bc5, bc6, bc7, bc8, bc9, bc10
    };

    int current_background_controls_animation = 0;


    bool music_is_on = true;
    bool sound_is_on = true;


    // set measure bricks viewports

    viewport_measure_bricks.x = SCREEN_WIDTH / 4;
    viewport_measure_bricks.y = 50;
    viewport_measure_bricks.w = 800;
    viewport_measure_bricks.h = 160;

    viewport_outline_measure_bricks.x = SCREEN_WIDTH / 4 + 5;
    viewport_outline_measure_bricks.y = 50;
    viewport_outline_measure_bricks.w = 800;
    viewport_outline_measure_bricks.h = 160;


    // set button vieports
    viewport_btn_start.x = 1007;
    viewport_btn_start.y = 335;
    viewport_btn_start.w = 388;
    viewport_btn_start.h = 119;

    viewport_btn_controls.x = 1007;
    viewport_btn_controls.y = 490;
    viewport_btn_controls.w = 388;
    viewport_btn_controls.h = 119;

    viewport_btn_quit.x = 1007;
    viewport_btn_quit.y = 645;
    viewport_btn_quit.w = 388;
    viewport_btn_quit.h = 119;

    
    // set controls content viwports
    viewport_controls_left.x = 180;
    viewport_controls_left.y = 249;
    viewport_controls_left.w = 465;
    viewport_controls_left.h = 490;

    viewport_controls_right.x = 955;
    viewport_controls_right.y = 249;
    viewport_controls_right.w = 465;
    viewport_controls_right.h = 490;

    viewport_controls_text.x = 499;
    viewport_controls_text.y = 72;
    viewport_controls_text.w = 602;
    viewport_controls_text.h = 41;

    viewport_controls_button_back.x = 32;
    viewport_controls_button_back.y = 36;
    viewport_controls_button_back.w = 126;
    viewport_controls_button_back.h = 113;

    viewport_music_button.x = 1491;
    viewport_music_button.y = 43;
    viewport_music_button.w = 70;
    viewport_music_button.h = 59;

    viewport_sound_button.x = 1385;
    viewport_sound_button.y = 43;
    viewport_sound_button.w = 70;
    viewport_sound_button.h = 59;
   

    font_RaM = TTF_OpenFont("./resource/fonts/rick_and_morty_font.ttf", 70);
    font_RaM_outline = TTF_OpenFont("./resource/fonts/rick_and_morty_font.ttf", 70);
    if(!font_RaM || !font_RaM_outline) 
        printf("TTF_OpenFont: %s\n", TTF_GetError());

    
    SDL_Surface *measure_bricks_surface = TTF_RenderText_Solid(font_RaM, "measure bricks", color_black);
    SDL_Surface *measure_bricks_outline_surface = TTF_RenderText_Solid(font_RaM_outline, "measure bricks", color_white);

    TTF_SetFontOutline(font_RaM_outline, 1);
    if(measure_bricks_surface == NULL || measure_bricks_outline_surface == NULL) 
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );


    measure_bricks_texture = SDL_CreateTextureFromSurface(ren, measure_bricks_surface);
    measure_bricks_outline_texture = SDL_CreateTextureFromSurface(ren, measure_bricks_outline_surface);
    
    

    while (!exit) {
        while (SDL_PollEvent(&event))  {
            if (event.type == SDL_QUIT) 
                exit = true;
        }    

        SDL_SetRenderDrawColor(ren, 0xff, 0xff, 0xff, 0x00);

        if (Mix_PlayingMusic() == 0 && Mix_PausedMusic() == 0) 
            Mix_PlayMusic(menu_music, -1);


        //background animation
        SDL_RenderCopy(ren, background_menu_animation[current_background_menu_animation], NULL, NULL);
        if (reverse_backround_menu_animation) {
            current_background_menu_animation = (current_background_menu_animation - 1) % background_menu_animation_count;
            if (current_background_menu_animation == 0) {
                if (current_background_menu_animation_delay < background_menu_animation_delay) {
                    current_background_menu_animation++;
                    current_background_menu_animation_delay++;
                }
                else {
                    current_background_menu_animation_delay = 0;
                    reverse_backround_menu_animation = false; 
                }
            }
        }

        else {
            current_background_menu_animation = (current_background_menu_animation + 1) % background_menu_animation_count;
            if (current_background_menu_animation == 17) {
                if (current_background_menu_animation_delay < background_menu_animation_delay) {
                    current_background_menu_animation--;
                    current_background_menu_animation_delay++;
                }
                else {
                    current_background_menu_animation_delay = 0;
                    reverse_backround_menu_animation = true; 
                }
            }
        }


        // render measure bricks
        SDL_RenderCopy(ren, measure_bricks_texture, NULL, &viewport_outline_measure_bricks);
        SDL_RenderCopy(ren, measure_bricks_outline_texture, NULL, &viewport_measure_bricks);


        // render buttons
        SDL_RenderCopy(ren, button_start, NULL, &viewport_btn_start);
        SDL_RenderCopy(ren, button_controls, NULL, &viewport_btn_controls);
        SDL_RenderCopy(ren, button_quit, NULL, &viewport_btn_quit);

  

        // button animation
        if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            int mouse_x, mouse_y;
            SDL_GetMouseState(&mouse_x, &mouse_y);

            bool mouse_inside_button_start = true;
            bool mouse_inside_button_controls = true;
            bool mouse_inside_button_quit = true;

    
            if (mouse_x < viewport_btn_start.x)
                mouse_inside_button_start = false;
            else if (mouse_x > viewport_btn_start.x + viewport_btn_start.w)
                mouse_inside_button_start = false;
            else if (mouse_y < viewport_btn_start.y)
                mouse_inside_button_start = false;
            else if (mouse_y > viewport_btn_start.y + viewport_btn_start.h)
                mouse_inside_button_start = false;

            if (mouse_x < viewport_btn_controls.x)
                mouse_inside_button_controls = false;
            else if (mouse_x > viewport_btn_controls.x + viewport_btn_controls.w)
                mouse_inside_button_controls = false;
            else if (mouse_y < viewport_btn_controls.y)
                mouse_inside_button_controls = false;
            else if (mouse_y > viewport_btn_controls.y + viewport_btn_controls.h)
                mouse_inside_button_controls = false;

            if (mouse_x < viewport_btn_quit.x)
                mouse_inside_button_quit = false;
            else if (mouse_x > viewport_btn_quit.x + viewport_btn_quit.w)
                mouse_inside_button_quit = false;
            else if (mouse_y < viewport_btn_quit.y)
                mouse_inside_button_quit = false;
            else if (mouse_y > viewport_btn_quit.y + viewport_btn_quit.h)
                mouse_inside_button_quit = false;

            
            if (mouse_inside_button_start) {
                switch(event.type) {
                    case SDL_MOUSEMOTION:
                        SDL_RenderCopy(ren, button_start_mover, NULL, &viewport_btn_start);
                        break;
                
                    case SDL_MOUSEBUTTONDOWN:
                        SDL_RenderCopy(ren, button_start, NULL, &viewport_btn_start);
                        Mix_PlayChannel(-1, click_button_sound, 0);
                        SDL_Delay(100);
                        SDL_RenderCopy(ren, button_start_mover, NULL, &viewport_btn_start);
                        SDL_Delay(150);
                        //Stop the music
                        Mix_HaltMusic();
                        SDL_RenderClear(ren);
                        quit_new(background_menu_animation, background_controls_animation, button_start, 
                            button_controls, button_quit, button_start_mover,
                            button_controls_mover, button_quit_mover,
                            controls_left, controls_right, controls_text, controls_button_back,
                            music_on, music_on_mover, music_off, music_off_mover,
                            mute, mute_mover, unmute, unmute_mover, click_button_sound, pause_sound,
                            portal_sound, game_over_sound, end_for_one_player_sound, quit_sound, menu_music, font_RaM, 
                            font_RaM_outline);
                        return 1;
                        break;
                }
            }

            if (mouse_inside_button_controls) {
                switch(event.type) {
                    case SDL_MOUSEMOTION:
                        SDL_RenderCopy(ren, button_controls_mover, NULL, &viewport_btn_controls);
                        break;
                
                    case SDL_MOUSEBUTTONDOWN:
                        SDL_RenderCopy(ren, button_controls, NULL, &viewport_btn_controls);
                        Mix_PlayChannel(-1, click_button_sound, 0);
                        SDL_Delay(100);
                    //     break;
                    
                    // // go to controls
                    // case SDL_MOUSEBUTTONUP:
                        SDL_RenderCopy(ren, button_controls_mover, NULL, &viewport_btn_controls);

                        SDL_Delay(150);
                        SDL_RenderClear(ren);
                        bool exit_controls = false;
                        SDL_Event event_controls;

                        while (!exit_controls) {
                            while (SDL_PollEvent(&event_controls))  {
                                if (event_controls.type == SDL_QUIT) {
                                    exit_controls = true;
                                    exit = true;
                                }
                            }

                            SDL_SetRenderDrawColor(ren, 0xff, 0xff, 0xff, 0x00);

                            // background controls animation
                            SDL_RenderCopy(ren, background_controls_animation[current_background_controls_animation], NULL, NULL);
                            current_background_controls_animation = (current_background_controls_animation + 1) % background_controls_animation_count;
                            if (current_background_controls_animation == 10)
                                current_background_controls_animation = 0;


                            // content of controls
                            SDL_RenderCopy(ren, controls_left, NULL, &viewport_controls_left);
                            SDL_RenderCopy(ren, controls_right, NULL, &viewport_controls_right);
                            SDL_RenderCopy(ren, controls_text, NULL, &viewport_controls_text);
                            SDL_RenderCopy(ren, controls_button_back, NULL, &viewport_controls_button_back);
                            if (music_is_on)
                                SDL_RenderCopy(ren, music_on, NULL, &viewport_music_button);
                            else    
                                SDL_RenderCopy(ren, music_off, NULL, &viewport_music_button);
                            if (sound_is_on)
                                SDL_RenderCopy(ren, unmute, NULL, &viewport_sound_button);
                            else    
                                SDL_RenderCopy(ren, mute, NULL, &viewport_sound_button);

                            
                            // controls button back animation
                            if (event_controls.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
                                // int mouse_x, mouse_y;
                                SDL_GetMouseState(&mouse_x, &mouse_y);

                                bool mouse_inside_button_back = true;
                                bool mouse_inside_sound_button = true;
                                bool mouse_inside_music_button = true;


                                if (mouse_x < viewport_controls_button_back.x)
                                    mouse_inside_button_back = false;
                                else if (mouse_x > viewport_controls_button_back.x + viewport_controls_button_back.w)
                                    mouse_inside_button_back = false;
                                else if (mouse_y < viewport_controls_button_back.y)
                                    mouse_inside_button_back = false;
                                else if (mouse_y > viewport_controls_button_back.y + viewport_controls_button_back.h)
                                    mouse_inside_button_back = false;

                                if (mouse_x < viewport_sound_button.x)
                                    mouse_inside_sound_button = false;
                                else if (mouse_x > viewport_sound_button.x + viewport_sound_button.w)
                                    mouse_inside_sound_button = false;
                                else if (mouse_y < viewport_sound_button.y)
                                    mouse_inside_sound_button = false;
                                else if (mouse_y > viewport_sound_button.y + viewport_sound_button.h)
                                    mouse_inside_sound_button = false;

                                if (mouse_x < viewport_music_button.x)
                                    mouse_inside_music_button = false;
                                else if (mouse_x > viewport_music_button.x + viewport_music_button.w)
                                    mouse_inside_music_button = false;
                                else if (mouse_y < viewport_music_button.y)
                                    mouse_inside_music_button = false;
                                else if (mouse_y > viewport_music_button.y + viewport_music_button.h)
                                    mouse_inside_music_button = false;

                                viewport_controls_button_back.x = 32;
                                viewport_controls_button_back.y = 36;
                                if (mouse_inside_button_back) {
                                    switch(event_controls.type) {
                                        case SDL_MOUSEMOTION:
                                            viewport_controls_button_back.x = 27;
                                            viewport_controls_button_back.y = 41;
                                            SDL_RenderCopy(ren, controls_button_back, NULL, &viewport_controls_button_back);
                                            break;
                                    
                                        case SDL_MOUSEBUTTONDOWN:
                                            SDL_RenderCopy(ren, controls_button_back, NULL, &viewport_controls_button_back);
                                            Mix_PlayChannel(-1, click_button_sound, 0);
                                            SDL_Delay(100);
                                            SDL_RenderCopy(ren, controls_button_back, NULL, &viewport_controls_button_back);
                                            exit_controls = true;
                                            break;
                                    }
                                }

                                if (mouse_inside_sound_button) {
                                    if (sound_is_on) {
                                        switch(event_controls.type) {
                                            case SDL_MOUSEMOTION:
                                                SDL_RenderCopy(ren, unmute_mover, NULL, &viewport_sound_button);
                                                break;

                                            // turn off sound
                                            case SDL_MOUSEBUTTONDOWN:
                                                sound_is_on = false;
                                                Mix_Volume(-1, 0);
                                                SDL_RenderCopy(ren, mute_mover, NULL, &viewport_sound_button);
                                                break;
                                        }
                                    }
                                    
                                    else {
                                        switch(event_controls.type) {
                                            case SDL_MOUSEMOTION:
                                                SDL_RenderCopy(ren, mute_mover, NULL, &viewport_sound_button);
                                                break;
                                        
                                            // turn on sound
                                            case SDL_MOUSEBUTTONDOWN:
                                                sound_is_on = true;
                                                // Mix_PlayChannel(-1, click_button_sound, 0);
                                                Mix_Volume(-1, 128);
                                                SDL_RenderCopy(ren, unmute_mover, NULL, &viewport_sound_button);
                                                break;
                                        }
                                    }
                                }          

                                if (mouse_inside_music_button) {
                                    if (music_is_on) {
                                        switch(event_controls.type) {
                                            case SDL_MOUSEMOTION:
                                                SDL_RenderCopy(ren, music_on_mover, NULL, &viewport_music_button);
                                                break;
                                        
                                            // turn off music
                                            case SDL_MOUSEBUTTONDOWN:
                                                music_is_on = false;
                                                if (Mix_PlayingMusic() != 0)                               
                                                    Mix_PauseMusic();

                                                Mix_PlayChannel(-1, click_button_sound, 0);
                                                SDL_RenderCopy(ren, music_off_mover, NULL, &viewport_music_button);
                                                break;
                                        }
                                    }

                                    else {
                                        switch(event_controls.type) {
                                            case SDL_MOUSEMOTION:
                                                SDL_RenderCopy(ren, music_off_mover, NULL, &viewport_music_button);
                                                break;
                                        
                                            // turn on music
                                            case SDL_MOUSEBUTTONDOWN:
                                                music_is_on = true;

                                                if (Mix_PlayingMusic() == 0)                               
                                                    Mix_PlayMusic(menu_music, -1);
                                                else {
                                                    if (Mix_PausedMusic() == 1)
                                                        Mix_ResumeMusic();
                                                }

                                                SDL_RenderCopy(ren, music_on_mover, NULL, &viewport_music_button);
                                                break;
                                        }
                                    }
                                }
                            }

                            SDL_RenderPresent(ren);
                            SDL_Delay(100);
                        }

                        break;
                }
            }

            if (mouse_inside_button_quit) {
                switch(event.type) {
                    case SDL_MOUSEMOTION:
                        SDL_RenderCopy(ren, button_quit_mover, NULL, &viewport_btn_quit);
                        break;
                
                    case SDL_MOUSEBUTTONDOWN:
                        SDL_RenderCopy(ren, button_quit, NULL, &viewport_btn_quit);
                        Mix_PlayChannel(-1, quit_sound, 0);
                        SDL_RenderCopy(ren, button_quit_mover, NULL, &viewport_btn_quit);
                        SDL_Delay(150);
                        //Stop the music
                        Mix_HaltMusic();
                        exit = true;
                        break;
                }
            }
            
        }

        SDL_RenderPresent(ren);
        SDL_Delay(100);     
    }

    quit_new(background_menu_animation, background_controls_animation, button_start, 
        button_controls, button_quit, button_start_mover,
        button_controls_mover, button_quit_mover,
        controls_left, controls_right, controls_text, controls_button_back,
        music_on, music_on_mover, music_off, music_off_mover,
        mute, mute_mover, unmute, unmute_mover, click_button_sound, pause_sound,
        portal_sound, game_over_sound, end_for_one_player_sound, quit_sound, menu_music, font_RaM, 
        font_RaM_outline);
    return -1;
}

void quit_new(SDL_Texture *background_menu_animation1[], SDL_Texture *background_controls_animation1[], SDL_Texture *button_start1, 
    SDL_Texture *button_controls1, SDL_Texture *button_quit1, SDL_Texture *button_start_mover1, 
    SDL_Texture *button_controls_mover1, SDL_Texture *button_quit_mover1,
    SDL_Texture *controls_left1, SDL_Texture *controls_right1, SDL_Texture *controls_text1, SDL_Texture *controls_button_back1,
    SDL_Texture *music_on1, SDL_Texture *music_on_mover1, SDL_Texture *music_off1, SDL_Texture *music_off_mover1,
    SDL_Texture *mute1, SDL_Texture *mute_mover1, SDL_Texture *unmute1, SDL_Texture *unmute_mover1, Mix_Chunk *click_button_sound1, Mix_Chunk *pause_sound1,
    Mix_Chunk *portal_sound1, Mix_Chunk *game_over_sound1, Mix_Chunk *end_for_one_player_sound1, Mix_Chunk *quit_sound1, Mix_Music *menu_music1, TTF_Font *font_RaM1, 
    TTF_Font *font_RaM_outline1)
 {

    for (int i = 0; i < 18; i++) {
        SDL_DestroyTexture(background_menu_animation1[i]);
        background_menu_animation1[i] = NULL;
    }

    for (int i = 0; i < 11; i++) {
        SDL_DestroyTexture(background_controls_animation1[i]);
        background_controls_animation1[i] = NULL;
    }

    SDL_DestroyTexture(button_start1);
    button_start1 = NULL;
    SDL_DestroyTexture(button_controls1);
    button_controls1 = NULL;
    SDL_DestroyTexture(button_quit1);
    button_quit1 = NULL;
    SDL_DestroyTexture(button_start_mover1);
    button_start_mover1 = NULL;

    SDL_DestroyTexture(button_controls_mover1);
    button_controls_mover1 = NULL;
    SDL_DestroyTexture(button_quit_mover1);
    button_quit_mover1 = NULL;

    SDL_DestroyTexture(controls_left1);
    controls_left1 = NULL;

    SDL_DestroyTexture(controls_right1);
    controls_right1 = NULL;
    SDL_DestroyTexture(controls_text1);
    controls_text1 = NULL;
    SDL_DestroyTexture(controls_button_back1);
    controls_button_back1 = NULL;
    SDL_DestroyTexture(music_on1);
    music_on1 = NULL;
    SDL_DestroyTexture(music_on_mover1);
    music_on_mover1 = NULL;
    SDL_DestroyTexture(music_off1);
    music_off1 = NULL;
    SDL_DestroyTexture(music_off_mover1);
    music_off_mover1 = NULL;
    SDL_DestroyTexture(mute1);
    mute1 = NULL;
    SDL_DestroyTexture(mute_mover1);
    mute_mover1 = NULL;
    SDL_DestroyTexture(unmute1);
    unmute1 = NULL;
    SDL_DestroyTexture(unmute_mover1);
    unmute_mover1 = NULL;
    Mix_FreeChunk(click_button_sound1);
    click_button_sound1 = NULL;
    Mix_FreeChunk(pause_sound1);
    pause_sound1 = NULL;
    Mix_FreeChunk(portal_sound1);
    portal_sound1 = NULL;
    Mix_FreeChunk(game_over_sound1);
    game_over_sound1 = NULL;
    Mix_FreeChunk(end_for_one_player_sound1);
    end_for_one_player_sound1 = NULL;
    Mix_FreeChunk(quit_sound1);
    quit_sound1 = NULL;
    Mix_FreeMusic(menu_music1);
    menu_music1 = NULL;
    TTF_CloseFont(font_RaM1);
    font_RaM1 = NULL;
    TTF_CloseFont(font_RaM_outline1);
    font_RaM_outline1 = NULL;
}
