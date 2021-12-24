#include "matrix_rain.h"

void mx_print_matrix(const t_vector2 *limit) {

    int xs[limit->x];
    mx_generate_x_idxs(limit->x, xs);
    int last_in_generated = 0;
    t_drop *activated_drops[limit->x];
    int last_in_drop = 0;

    int start_y = 0;
    t_drop drops[limit->x];

    int SPEED = limit->x * 1100;
    

   
    while(1) {

        if (last_in_generated < limit->x) {
            int count_of_generated = rand() % (limit->x / (limit->x / 4));
            int stop_index = last_in_generated + count_of_generated;
            if (stop_index > limit->x) stop_index = limit->x;
            for (int i = last_in_generated; i < stop_index; i++) {
                int y;
                if (start_y == 0) y = start_y;
                else y = rand() % start_y;
                t_vector2 start = {xs[i], 0};
                mx_start_drop(&drops[xs[i]], start, limit);
                activated_drops[last_in_drop] = &drops[xs[i]];
                last_in_drop++;
                start_y++;
            }
            last_in_generated += count_of_generated;
            start_y = (start_y + 1) % limit->y;

        }

        for (int i = 0; i < last_in_drop; i++) {
            mx_drop_char(activated_drops[i], limit);
        }

        usleep(SPEED);
        noecho();
        halfdelay(1);

        char input = getch();

        if (input == '+') {
            SPEED -= 10000;
            if (SPEED <= 0) {
                SPEED = 1;
            }
        } else if (input == '-') {
            SPEED += 10000;
        } else if (input == 'q') {
            exit(0);
        } else if (input == '0') {
            init_pair(SYMBOL_COLOUR, COLOR_GREEN, COLOR_BLACK);
        } else if (input == '1') {
            init_pair(SYMBOL_COLOUR, COLOR_YELLOW | COLOR_GREEN, COLOR_BLACK);
        } else if (input == '2') {
            init_pair(SYMBOL_COLOUR, COLOR_RED, COLOR_BLACK);
        } else if (input == '3') {
            init_pair(SYMBOL_COLOUR, COLOR_CYAN, COLOR_BLACK);
        } else if (input == '4') {
            init_pair(SYMBOL_COLOUR, COLOR_BLUE, COLOR_BLACK);
        } else if (input == '5') {
            init_pair(SYMBOL_COLOUR, COLOR_MAGENTA, COLOR_BLACK);
        }
    }

    endwin();
}


