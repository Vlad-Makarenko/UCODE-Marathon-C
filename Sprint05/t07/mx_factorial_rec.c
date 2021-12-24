
int mx_factorial_rec(int n){
    if (n < 0 || n > 12){
        return 0;
    }else {
        int res = 1;
        if (n > 0){
            res *= mx_factorial_rec(n - 1) * n;
        }
        return res;
    }
}

