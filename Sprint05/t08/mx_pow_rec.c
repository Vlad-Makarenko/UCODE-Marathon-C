
int mx_pow_rec( double n, unsigned int pow)
{
    if (pow > 0 ){
        return mx_pow_rec(n, pow - 1) * n;
    }else{
        return 1 ;
    }
}
