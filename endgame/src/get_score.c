#include "tetromino.h"


int get_score(int x, int y, t_block _field[x][y]){
    int score = 0;
    for (int i = 0; i < FIELD_WIDTH; i++){
        for (int j = 0; j < FIELD_HEIGHT; j++){
            if (_field[i][j].color != NONE_COLOR){
                score += 25;
            }
            
        }
    }
    return score;
}
