int nCr[1001][1001];

void comp() {
    for(int i=0;i<=1000;++i) {
        nCr[i][0] = 1;
    }
    nCr[0][0] = 1;
    for(int i=1;i<=1000;++i) {
        for(int j=1;j<=i;++j) {
            nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1])%mod;
        }
    }
}
