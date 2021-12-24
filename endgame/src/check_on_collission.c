#include "tetromino.h"


bool p1_check_on_collission(t_tetromino **tetromino, SDL_Rect *left_anchor)
{
    if (left_anchor->y <= 0) return false;
    if(left_anchor->y > FIELD_HEIGHT * BRICK_D_SIZE) return true;

    t_tetromino *_tetromino = *tetromino;
    int field_index_y = (BOTTOM_FIELD_Y - left_anchor->y) / BRICK_D_SIZE;
    int field_index_x = (left_anchor->x - LEFT_FIELD_ANCHOR_X) / BRICK_D_SIZE;

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {

            if (_tetromino->data[x][y] == 1)
            {
                if (y < 3)
                {
                    if (_tetromino->data[x][y + 1] == 0)
                    {
                        if (field_index_y - y == 0)
                        {
                            return true;
                        }
                        else if (p1_field[field_index_x + x][field_index_y - y - 1].color != NONE_COLOR)
                        {
                            return true;
                        }
                    }
                }
                else
                {
                    if (field_index_y - y == 0)
                    {
                        return true;
                    }
                    else if (p1_field[field_index_x + x][field_index_y - y - 1].color != NONE_COLOR)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool p2_check_on_collission(t_tetromino **tetromino, SDL_Rect *left_anchor)
{
    if (left_anchor->y <= 0) return false;
    if(left_anchor->y > FIELD_HEIGHT * BRICK_D_SIZE) return true;

    t_tetromino *_tetromino = *tetromino;
    int field_index_y = (BOTTOM_FIELD_Y - left_anchor->y) / BRICK_D_SIZE;
    int field_index_x = (left_anchor->x - RIGHT_FIELD_ANCHOR_X) / BRICK_D_SIZE;

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {

            if (_tetromino->data[x][y] == 1)
            {
                if (y < 3)
                {
                    if (_tetromino->data[x][y + 1] == 0)
                    {
                        if (field_index_y - y == 0)
                        {
                            return true;
                        }
                        else if (p2_field[field_index_x + x][field_index_y - y - 1].color != NONE_COLOR)
                        {
                            return true;
                        }
                    }
                }
                else
                {
                    if (field_index_y - y == 0)
                    {
                        return true;
                    }
                    else if (p2_field[field_index_x + x][field_index_y - y - 1].color != NONE_COLOR)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
