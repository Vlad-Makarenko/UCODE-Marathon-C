#include "tetromino.h"


int tetris(SDL_Renderer *g_renderer, int *p1_score, int *p2_score) {
    bool quit = false;


    Mix_Music  *game_music = Mix_LoadMUS("./resource/audio/game_theme.wav");

    SDL_RenderSetScale(g_renderer, 0.3, 0.3);
    // init(g_renderer, g_window);
    p1_game_is_end = false;
    p2_game_is_end = false;
    init();
    load_media(g_renderer);

    SDL_Rect p1_current_position = {LEFT_FIELD_ANCHOR_X, -400, 0, 0};
    t_tetromino *p1_droped_figure = NULL;
    

    /////////////////////////////

    SDL_Rect p2_current_position = {RIGHT_FIELD_ANCHOR_X, -400, 0, 0};
    t_tetromino *p2_droped_figure = NULL;




    int delay = 1000 / 30;

    while (!quit)
    {

        p1_down_key_down = false;
        p2_down_key_down = false;
        while (SDL_PollEvent(&event) && event.type != SDL_MOUSEMOTION)
        {
            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_a) a_button_pressed = false;
                if (event.key.keysym.sym == SDLK_d) d_button_pressed = false;
            }

            //////////////// BUTTON HANDLE


            if (d_button_pressed && p1_check_x(&p1_droped_figure, &p1_current_position, X_SPEED) ) {
                p1_current_position.x += X_SPEED;
            }
            if (right_button_pressed && p2_check_x(&p2_droped_figure, &p2_current_position, X_SPEED)) {
                p2_current_position.x += X_SPEED;
            } 

            if (a_button_pressed && p1_check_x(&p1_droped_figure, &p1_current_position, -X_SPEED)) {

                p1_current_position.x -= X_SPEED;
            }  
            
            if (left_button_pressed && p2_check_x(&p2_droped_figure, &p2_current_position, -X_SPEED)) {

                p2_current_position.x -= X_SPEED;
            }
            
            
            

            ///////////////// LEFT

            if (event.type == SDL_KEYDOWN) {
                if(event.key.keysym.sym == SDLK_a) a_button_pressed = true;
                if (event.key.keysym.sym == SDLK_d) d_button_pressed = true;
            }

            

            if(event.key.keysym.sym == SDLK_LEFT) {
                if(event.type == SDL_KEYDOWN) {
                    left_button_pressed = true;
                }
                
                if(event.type == SDL_KEYUP) {
                    left_button_pressed = false;
                }
            }

            /////////////////// RIGHT
        

            if (event.key.keysym.sym == SDLK_RIGHT) {
                if(event.type == SDL_KEYDOWN) right_button_pressed = true;
                if(event.type == SDL_KEYUP) right_button_pressed = false;           
            }
            

            ///////////////// DOWN

            if (event.key.keysym.sym == SDLK_DOWN) {
                if(event.type == SDL_KEYDOWN) down_button_pressed = true;
                            
                if(event.type == SDL_KEYUP) down_button_pressed = false;           
            }
            
            
            if (event.key.keysym.sym == SDLK_s) {
                if(event.type == SDL_KEYDOWN) s_button_pressed = true;
                            
                if(event.type == SDL_KEYUP) s_button_pressed = false;           
            }

            ///////////////// UP

            if (event.key.keysym.sym == SDLK_UP) {
                if(event.type == SDL_KEYDOWN) up_button_pressed = true;
                            
                if(event.type == SDL_KEYUP) up_button_pressed = false;           
            }
            
            
            if (event.key.keysym.sym == SDLK_w) {
                if(event.type == SDL_KEYDOWN) w_button_pressed = true;
                            
                if(event.type == SDL_KEYUP) w_button_pressed = false;           
            }

            if (s_button_pressed && current_speed_p1 < MAX_SPEED) {
                current_speed_p1 += speed_up;
                p1_down_key_down = true;

            }
            

            if (down_button_pressed && current_speed_p2 < MAX_SPEED) {
                current_speed_p2 += speed_up; 
                p2_down_key_down = true;
            }

             if (up_button_pressed && event.key.keysym.sym == SDLK_UP) {
                if (p2_check_x(&p2_droped_figure->next, &p2_current_position, 0) && p2_droped_figure->color != PACKMAN_COLOR)
                    p2_droped_figure = p2_droped_figure->next;
            }

            if (w_button_pressed && event.key.keysym.sym == SDLK_w && p1_droped_figure->color != PACKMAN_COLOR)
            {
                if (p1_check_x(&p1_droped_figure->next, &p1_current_position, 0))
                    p1_droped_figure = p1_droped_figure->next;
                            
            }

            
            


            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            
        }

        if (Mix_PlayingMusic() == 0 && Mix_PausedMusic() == 0) 
            Mix_PlayMusic(game_music, -1);
        SDL_RenderClear(g_renderer);

        SDL_RenderCopy(g_renderer, background, NULL, NULL);

        g_renderer = p1_print_field(g_renderer);
        g_renderer = p2_print_field(g_renderer);
        
        g_renderer = mana_p1_print_field(g_renderer);
        g_renderer = mana_p2_print_field(g_renderer);



        if(!p2_game_is_end) {
            if (p2_droped_figure != NULL && p2_check_on_collission(&p2_droped_figure, &p2_current_position)) {
                if(p2_current_position.y <= BRICK_D_SIZE * 2) {
                    p2_game_is_end = true;
                }
                p2_add_on_field(&p2_droped_figure, &p2_current_position);
                if(p2_droped_figure->color == PACKMAN_COLOR) { 
                    eat_blocks(FIELD_WIDTH, FIELD_HEIGHT, p2_field, &p2_droped_figure);
                }  
                //////////////////////////////////
                if(fill_mana_bar_p2(FIELD_WIDTH, 1, mana_p2_field)){
                    int feature = rand() % FEATURES_NUM;
                    
                    switch(feature) {
                        case 0:
                            landslide_feature(FIELD_WIDTH, FIELD_HEIGHT, &p2_field);
                            break;
                        case 1:
                            illusion_feature(&p1_droped_figure);
                            break;
                        case 2:
                            packman_feature(&p1_droped_figure);
                            break;
                        default:
                            break;
                    }

                }
                p2_current_position.y = SPAWN_POSITION_Y;
                p2_current_position.x = RIGHT_FIELD_ANCHOR_X;
                p2_droped_figure = NULL;
            }
            
            
            if (p2_droped_figure == NULL) {
                p2_current_position.y = SPAWN_POSITION_Y;
                p2_current_position.x = RIGHT_FIELD_ANCHOR_X + (rand() % FIELD_WIDTH) * BRICK_D_SIZE - 3 * BRICK_D_SIZE; 
                if(p2_current_position.x >= P2_RIGHT_FIELD_BORDER_X ) p2_current_position.x = P2_RIGHT_FIELD_BORDER_X - BRICK_D_SIZE;
                if(p2_current_position.x < RIGHT_FIELD_ANCHOR_X ) p2_current_position.x = RIGHT_FIELD_ANCHOR_X + BRICK_D_SIZE;
                p2_droped_figure = &tetrominos[rand() % TETROMINOS_SIZE];
            }

            if (p2_droped_figure != NULL )  {
                g_renderer = create_tetromino_texture(p2_droped_figure, &p2_current_position, g_renderer);

            }
            p2_current_position.y += current_speed_p2 / delay;
            if (!p2_down_key_down) current_speed_p2 = MIN_SPEED; 
        }

         if(!p1_game_is_end) {
        
            
            if (p1_droped_figure != NULL && p1_check_on_collission(&p1_droped_figure, &p1_current_position))
            {
                if(p1_current_position.y <= BRICK_D_SIZE * 2) {
                    p1_game_is_end = true;

                }
                p1_add_on_field(&p1_droped_figure, &p1_current_position);

                if(p1_droped_figure->color == PACKMAN_COLOR) { 
                    eat_blocks(FIELD_WIDTH, FIELD_HEIGHT, p1_field, &p1_droped_figure);
                }  

                if(fill_mana_bar_p1(FIELD_WIDTH, 1, mana_p1_field)){
                    int feature = rand() % FEATURES_NUM ;
                    switch(feature) {
                        case 0:
                            landslide_feature(FIELD_WIDTH, FIELD_HEIGHT, p1_field);
                            break;
                        case 1:
                            illusion_feature(&p2_droped_figure);
                            break;
                        case 2:
                            packman_feature(&p2_droped_figure);
                            break;
                        default:
                            break;
                    }
                }

                p1_current_position.y = SPAWN_POSITION_Y;
                p1_current_position.x = LEFT_FIELD_ANCHOR_X;
                p1_droped_figure = NULL;
            }
            
            
            if (p1_droped_figure == NULL){
                p1_current_position.y = SPAWN_POSITION_Y;
                p1_current_position.x = LEFT_FIELD_ANCHOR_X + (rand() % FIELD_WIDTH) * BRICK_D_SIZE - 3 * BRICK_D_SIZE;
                if(p1_current_position.x >= RIGHT_FIELD_BORDER_X) p1_current_position.x = RIGHT_FIELD_BORDER_X - BRICK_D_SIZE;
                if(p1_current_position.x < LEFT_FIELD_ANCHOR_X) p1_current_position.x = LEFT_FIELD_ANCHOR_X + BRICK_D_SIZE;
                p1_droped_figure = &tetrominos[rand() % TETROMINOS_SIZE];
            }

            if (p1_droped_figure != NULL )
            {
                g_renderer = create_tetromino_texture(p1_droped_figure, &p1_current_position, g_renderer);

            }
            p1_current_position.y += current_speed_p1 / delay;
            if (!p1_down_key_down) current_speed_p1 = MIN_SPEED; 
        }

        
        

        SDL_RenderPresent(g_renderer);


        if (p1_game_is_end && p2_game_is_end) break;
        SDL_Delay(delay);
    }
    
    SDL_RenderSetScale(g_renderer, 1, 1);

    // printf("Score P1: %d\n", get_score(FIELD_WIDTH, FIELD_HEIGHT, p1_field));

    // printf("Score P2: %d\n", get_score(FIELD_WIDTH, FIELD_HEIGHT, p2_field));

    *p1_score = get_score(FIELD_WIDTH, FIELD_HEIGHT, p1_field);
    *p2_score = get_score(FIELD_WIDTH, FIELD_HEIGHT, p2_field); 


    if (quit) return -1;
    else return 2;

    // close();
}
