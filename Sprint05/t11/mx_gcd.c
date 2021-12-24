
int mx_gcd(int a, int b) {
    if(a < 0){
        a = -a;
    }
    if (b < 0){
        b = -b;
    }
    if (a % b == 0){
        return b;
    }
    if (b % a == 0){
        return a;
    }
    if (a > b){
        return mx_gcd(a % b, b);
    } else {
        return mx_gcd(a, b % a);
    }
}

