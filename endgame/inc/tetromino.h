#ifndef TETROMINO_H
#define TETROMINO_H

#define SDL_ASSERT_LEVEL 0
#include <stdlib.h>
#include <time.h>
#include "endgame.h"

#define BRICK_D_SIZE 100
#define FIELD_WIDTH 15
#define FIELD_HEIGHT 25

#define LEFT_FIELD_ANCHOR_X 400
#define RIGHT_FIELD_BORDER_X 1700
#define BOTTOM_FIELD_Y 2500

/////////////////////////////////////////////////

#define RIGHT_FIELD_ANCHOR_X 3400
#define P2_RIGHT_FIELD_BORDER_X 4700


/////////////////////////////////////////////////


#define TETROMINOS_SIZE 19
#define SPAWN_POSITION_Y -500

#define FEATURES_NUM 3

// block == brick

typedef enum {
    NONE_COLOR,
    GREEN_COLOR,
    ORANGE_COLOR,
    KYAN_COLOR,
    BLUE_COLOR,
    PINK_COLOR,
    PACKMAN_COLOR,
    RIGHT_FULL,
    TRANSPARRENT_COLOR = 0,
    
}   BLOCK_COLORS;


typedef struct s_block {
    BLOCK_COLORS color;
    SDL_Rect rect[4];

}              t_block;


typedef struct s_tetromino {

    BLOCK_COLORS color;
    char data[4][4];
    struct s_tetromino *next;

}             t_tetromino;

t_tetromino tetrominos[TETROMINOS_SIZE];
t_block blocks[7];
t_block p1_field[FIELD_WIDTH][FIELD_HEIGHT];
t_block p2_field[FIELD_WIDTH][FIELD_HEIGHT];
t_block mana_p1_field[FIELD_WIDTH][BRICK_D_SIZE / 100];
t_block mana_p2_field[FIELD_WIDTH][BRICK_D_SIZE / 100];

static bool p1_game_is_end = false;
static bool p2_game_is_end = false;

static int p1_updated_x = 0;
static int p2_updated_x = 0;


bool init();

bool load_media();

void close_game( SDL_Renderer *g_renderer, SDL_Window *g_window);

static SDL_Renderer *move_renderer = NULL;
static SDL_Texture *g_texture = NULL;
static SDL_Event event;


#define MIN_SPEED 400
#define MAX_SPEED 15000

static int speed_up = 1000;
static int current_speed_p1 = MIN_SPEED;
static int current_speed_p2 = MIN_SPEED;
static bool p1_down_key_down = false;
static bool p2_down_key_down = false;

static const int X_SPEED = BRICK_D_SIZE;

static bool left_button_pressed = false;
static bool right_button_pressed = false;

static bool up_button_pressed = false;
static bool down_button_pressed = false;

static bool a_button_pressed = false;
static bool d_button_pressed = false;

static bool w_button_pressed = false;
static bool s_button_pressed = false;

SDL_Texture *create_block(t_block *brick);

void p1_init_field();

void p2_init_field();

void mana_p1_init_field();

void mana_p2_init_field();



SDL_Renderer * p1_print_field(SDL_Renderer *renderer);

SDL_Renderer * p2_print_field(SDL_Renderer *renderer);

SDL_Renderer * mana_p1_print_field(SDL_Renderer *renderer);

SDL_Renderer * mana_p2_print_field(SDL_Renderer *renderer);

SDL_Renderer *p1_print_block_on_field(int x, int y, SDL_Renderer *renderer);

SDL_Renderer *p2_print_block_on_field(int x, int y, SDL_Renderer *renderer);

SDL_Renderer *mana_p1_print_block_on_field(int x, int y, SDL_Renderer *renderer);

SDL_Renderer *mana_p2_print_block_on_field(int x, int y, SDL_Renderer *renderer);

bool fill_mana_bar_p1(int width, int height, t_block mana_field[width][height]);

bool fill_mana_bar_p2(int width, int height, t_block mana_field[width][height]);



void parse_char_to_rect(t_block *block, char data[4][4], SDL_Rect *anchor);

void init_tetrominos();

SDL_Renderer *create_tetromino_texture(t_tetromino *tetromino, SDL_Rect *anchor, SDL_Renderer *renderer);

bool p2_check_on_collission(t_tetromino **tetromino, SDL_Rect *left_anchor);

bool p1_check_on_collission(t_tetromino **tetromino, SDL_Rect *left_anchor);

bool p1_check_x(t_tetromino **tetromino, SDL_Rect *left_anchor, int step);

bool p2_check_x(t_tetromino **tetromino, SDL_Rect *left_anchor, int step);

void p1_add_on_field_by_xy(int x, int y, BLOCK_COLORS color);

void p2_add_on_field_by_xy(int x, int y, BLOCK_COLORS color);

void p1_add_on_field(t_tetromino **tetromino, SDL_Rect *left_anchor);

void p2_add_on_field(t_tetromino **tetromino, SDL_Rect *left_anchor);

int get_score(int x, int y, t_block _field[x][y]);

void eat_blocks(int width, int height, t_block field[width][height], t_tetromino **block);

void landslide_feature();

void illusion_feature(t_tetromino **block);

void packman_feature(t_tetromino **block);

#endif
