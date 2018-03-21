int p[1000005];       // p[i] stores number of divisors of i.

void factorize() {
    for(int i=2;i<=1000000;++i) {
        if(p[i]==1) {
            for(int j=i+i;j<=1000000;j+=i) {
                int cnt = 0, save = j;
                while(save%i==0) {
                    cnt++;
                    save /= i;
                }
                p[j] *= (cnt+1);
            }
        }
    }
    for(int i=2;i<=1000000;++i) {
        if(p[i]==1) {
            p[i]=2;
        }
    }
}

