
int mx_max(int a, int b, int c){
    int buf;
    if (a > b){
        buf = a;
    } else {
        buf = b;
    }
    if (buf < c){
        buf = c;
        return buf;
    }else {
        return buf;
    }
}
