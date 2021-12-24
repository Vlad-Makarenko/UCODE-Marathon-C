
void mx_printchar(char c);

void mx_cube(int n){
    if(n <= 1){
        return;
    }


    //first line
    for(int i = 0; i <= n/2; i++){
        mx_printchar(' ');
    }
    mx_printchar('+');
    for(int i = 0; i <= n * 2; i++){
        mx_printchar('-');
    }
    mx_printchar('+');
    mx_printchar('\n');


    //second part
    int c = n/2; //spaces before '/'
    int d = 0; //spaces between last '/' and '|'
    int counter_c = 0;
    int counter_d = n/2;
    for(int i = n/2; i > 0; i--){

        for(; c > 0; c--){
            mx_printchar(' ');
        }
        counter_c++;
        c = n/2 - counter_c;
        mx_printchar('/'); //first part of line before first '/'

        for(int j = 0; j <= n * 2; j++){
            mx_printchar(' ');
        } //making spaces between '/'

        mx_printchar('/');
        for(; d <= n/2; d++){// 'd' doljno pri pervoi iteracii vihodit`
            if(d == 0){
                break;
            }else{
                mx_printchar(' ');
            }
        }  //making spaces between '/' && '|'
        mx_printchar('|');
        counter_d--;
        d -= n/2 - counter_d;//decrementing counter for making more spaces with each iteration

        mx_printchar('\n');
    }

    //making "bridge"
    mx_printchar('+');
    for(int i = 0; i <= n * 2; i++){
        mx_printchar('-');
    }
    mx_printchar('+');
    for(int i = 0; i < counter_c; i++){
        mx_printchar(' ');
    }
    mx_printchar('|');
    mx_printchar('\n');

    //creating body till '+' of bottom side
    for(int i = 0; i <= n - n/2 - 2; i++){
        mx_printchar('|');
        for(int j = 0; j <= n*2; j++){
            mx_printchar(' ');
        }
        mx_printchar('|');
        for(int j = 0; j < counter_c; j++){
            mx_printchar(' ');
        }
        mx_printchar('|');
        mx_printchar('\n');
    }

    //creating one more bridge
    mx_printchar('|');
    for(int j = 0; j <= n*2; j++){
        mx_printchar(' ');
    }
    mx_printchar('|');
    for(int j = 0; j < counter_c; j++){
        mx_printchar(' ');
    }
    mx_printchar('+');
    mx_printchar('\n');

    //creating body from '*' of the bottom side
    int new_c = n/2 - 1;
    int new_counter_c = 0;
    for(int i = 0; i < n/2; i++){
        mx_printchar('|');
        for(int j = 0; j <= n*2; j++){
            mx_printchar(' ');
        }
        mx_printchar('|');
        for(; new_c > 0; new_c--){
            mx_printchar(' ');
        }
        new_counter_c++;
        new_c = n/2 - new_counter_c - 1;
        mx_printchar('/');
        mx_printchar('\n');
    }

    //creating bottom line
    mx_printchar('+');
    for(int i = 0; i <= n * 2; i++){
        mx_printchar('-');
    }
    mx_printchar('+');
    mx_printchar('\n');
}

