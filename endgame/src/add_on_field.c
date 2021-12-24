#include "tetromino.h"

void p1_add_on_field_by_xy(int x, int y, BLOCK_COLORS color)
{
    p1_field[x][y].color = color;
}

void p2_add_on_field_by_xy(int x, int y, BLOCK_COLORS color)
{
    p2_field[x][y].color = color;
}

void p1_add_on_field(t_tetromino **tetromino, SDL_Rect *left_anchor)
{
    t_tetromino *_tetromino = *tetromino;
    int field_index_y = (BOTTOM_FIELD_Y - left_anchor->y) / BRICK_D_SIZE;
    int field_index_x = (left_anchor->x - LEFT_FIELD_ANCHOR_X) / BRICK_D_SIZE;

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (_tetromino->data[x][y] == 1)
            {
                p1_add_on_field_by_xy(field_index_x + x, field_index_y - y, _tetromino->color);
            }
        }
    }
}

void p2_add_on_field(t_tetromino **tetromino, SDL_Rect *left_anchor)
{
    t_tetromino *_tetromino = *tetromino;
    int field_index_y = (BOTTOM_FIELD_Y - left_anchor->y) / BRICK_D_SIZE;
    int field_index_x = (left_anchor->x - RIGHT_FIELD_ANCHOR_X) / BRICK_D_SIZE;

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (_tetromino->data[x][y] == 1)
            {
                p2_add_on_field_by_xy(field_index_x + x, field_index_y - y, _tetromino->color);
            }
        }
    }
}
