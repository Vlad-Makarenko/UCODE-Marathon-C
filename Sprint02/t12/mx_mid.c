
int mx_mid(int a, int b, int c){
    int buf;
    if ((a> b && c > a)
        || (a > c && b > a)){
        buf = a;
    } else if ((b > c && a > b)
                || (b > a && c > b)) {
        buf = b;
    } else {
        buf = c;
    }
    return buf;
}
