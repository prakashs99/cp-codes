LL pwrmod( LL a,LL b,LL mod) {
    if(b==0) {
        return 1;
    }
    LL ans=1;
    while(b) {
        if(b&1) {
            ans=((ans%mod)*(a%mod))%mod;
        }
        b/=2;
        a=((a%mod)*(a%mod))%mod;
    }
    return ans;
}

bool miillerTest(LL d, LL n) {
    LL a = 2 + rand() % (n - 4);
    LL x = pwrmod(a, d, n);
    if (x == 1  || x == n-1)
        return true;
    while (d != n-1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}
bool isPrime(LL n, int k) {
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    LL d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < k; i++)
        if (miillerTest(d, n) == false)
            return false;
    return true;
}

// Call isPrime(x,k) to check if x is prime. k = no. of iterations.
