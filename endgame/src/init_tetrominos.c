#include "tetromino.h"

void init_tetrominos() {

    //////////// Straight line vertical
    tetrominos[0].color = ORANGE_COLOR;
    
    tetrominos[0].data[0][0] = 1;
    tetrominos[0].data[0][1] = 1;
    tetrominos[0].data[0][2] = 1;
    tetrominos[0].data[0][3] = 1;
    tetrominos[0].next = &tetrominos[1];
    
    ////////// Straigght line horizontal
    tetrominos[1].color = ORANGE_COLOR;
    
    tetrominos[1].data[0][0] = 1;
    tetrominos[1].data[1][0] = 1;
    tetrominos[1].data[2][0] = 1;
    tetrominos[1].data[3][0] = 1;
    tetrominos[1].next = &tetrominos[0];

    
    ////////// Z-form-left horizontal
    tetrominos[2].color = PINK_COLOR;
    
    tetrominos[2].data[0][2] = 1;
    tetrominos[2].data[1][2] = 1;
    tetrominos[2].data[1][3] = 1;
    tetrominos[2].data[2][3] = 1;
    tetrominos[2].next = &tetrominos[3];

    
    ////////// Z-form-left vertical
    tetrominos[3].color = PINK_COLOR;
    
    tetrominos[3].data[1][1] = 1;
    tetrominos[3].data[1][2] = 1;
    tetrominos[3].data[0][2] = 1;
    tetrominos[3].data[0][3] = 1;
    tetrominos[3].next = &tetrominos[2];


    ////////// Z-form-right horizontal
    tetrominos[4].color = PINK_COLOR;
    
    tetrominos[4].data[0][3] = 1;
    tetrominos[4].data[1][3] = 1;
    tetrominos[4].data[1][2] = 1;
    tetrominos[4].data[2][2] = 1;
    tetrominos[4].next = &tetrominos[5];

    
    ////////// Z-form-right vertical
    tetrominos[5].color = PINK_COLOR;
    
    tetrominos[5].data[0][1] = 1;
    tetrominos[5].data[0][2] = 1;
    tetrominos[5].data[1][2] = 1;
    tetrominos[5].data[1][3] = 1;
    tetrominos[5].next = &tetrominos[4];
    
    ////////// T-form horizontal
    tetrominos[6].color = KYAN_COLOR;
    
    tetrominos[6].data[0][3] = 1;
    tetrominos[6].data[1][2] = 1;
    tetrominos[6].data[1][3] = 1;
    tetrominos[6].data[2][3] = 1;
    tetrominos[6].next = &tetrominos[8];

    ////////// T-form vertical left
    tetrominos[7].color = KYAN_COLOR;
    
    tetrominos[7].data[0][2] = 1;
    tetrominos[7].data[1][1] = 1;
    tetrominos[7].data[1][2] = 1;
    tetrominos[7].data[1][3] = 1;
    tetrominos[7].next = &tetrominos[6];

    ////////// T-form vertical right
    tetrominos[8].color = KYAN_COLOR;
    
    tetrominos[8].data[0][1] = 1;
    tetrominos[8].data[0][2] = 1;
    tetrominos[8].data[0][3] = 1;
    tetrominos[8].data[1][2] = 1;
    tetrominos[8].next = &tetrominos[9];


    ////////// T-form vertical right
    tetrominos[9].color = KYAN_COLOR;
    
    tetrominos[9].data[0][2] = 1;
    tetrominos[9].data[1][2] = 1;
    tetrominos[9].data[1][3] = 1;
    tetrominos[9].data[2][2] = 1;
    tetrominos[9].next = &tetrominos[7];

    ////////// L-form horizontal left up
    tetrominos[10].color = GREEN_COLOR;
    
    tetrominos[10].data[0][3] = 1;
    tetrominos[10].data[1][3] = 1;
    tetrominos[10].data[2][2] = 1;
    tetrominos[10].data[2][3] = 1;
    tetrominos[10].next = &tetrominos[11];

    ////////// L-form vertical left up
    tetrominos[11].color = GREEN_COLOR;
    
    tetrominos[11].data[0][1] = 1;
    tetrominos[11].data[1][1] = 1;
    tetrominos[11].data[1][2] = 1;
    tetrominos[11].data[1][3] = 1;
    tetrominos[11].next = &tetrominos[12];

    ////////// L-form horizontal left down
    tetrominos[12].color = GREEN_COLOR;
    
    tetrominos[12].data[0][2] = 1;
    tetrominos[12].data[0][3] = 1;
    tetrominos[12].data[1][2] = 1;
    tetrominos[12].data[2][2] = 1;
    tetrominos[12].next = &tetrominos[13];

    ////////// L-form vertical left down
    tetrominos[13].color = GREEN_COLOR;
    
    tetrominos[13].data[0][1] = 1;
    tetrominos[13].data[0][2] = 1;
    tetrominos[13].data[0][3] = 1;
    tetrominos[13].data[1][3] = 1;
    tetrominos[13].next = &tetrominos[10];

    ////////// L-form horizontal right up
    tetrominos[14].color = BLUE_COLOR;
    
    tetrominos[14].data[0][2] = 1;
    tetrominos[14].data[0][3] = 1;
    tetrominos[14].data[1][3] = 1;
    tetrominos[14].data[2][3] = 1;
    tetrominos[14].next = &tetrominos[15];

    ////////// L-form vertical right up
    tetrominos[15].color = BLUE_COLOR;
    
    tetrominos[15].data[0][1] = 1;
    tetrominos[15].data[0][2] = 1;
    tetrominos[15].data[0][3] = 1;
    tetrominos[15].data[1][1] = 1;
    tetrominos[15].next = &tetrominos[16];

    ////////// L-form horizontal right down
    tetrominos[16].color = BLUE_COLOR;
    
    tetrominos[16].data[0][2] = 1;
    tetrominos[16].data[1][2] = 1;
    tetrominos[16].data[2][2] = 1;
    tetrominos[16].data[2][3] = 1;
    tetrominos[16].next = &tetrominos[17];

    ////////// L-form vertical right down
    tetrominos[17].color = BLUE_COLOR;
    
    tetrominos[17].data[0][3] = 1;
    tetrominos[17].data[1][1] = 1;
    tetrominos[17].data[1][2] = 1;
    tetrominos[17].data[1][3] = 1;
    tetrominos[17].next = &tetrominos[14];

    ////////// L-form vertical right down
    tetrominos[18].color = BLUE_COLOR;
    
    tetrominos[18].data[0][2] = 1;
    tetrominos[18].data[0][3] = 1;
    tetrominos[18].data[1][2] = 1;
    tetrominos[18].data[1][3] = 1;
    tetrominos[18].next = &tetrominos[18];
}

