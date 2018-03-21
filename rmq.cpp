int spt[20][400005];
int lg2[400005];

int rmq(int a, int b) {
    int len = b-a+1;
    int k = lg2[len];
    return min(spt[k][a],spt[k][b-(1<<k)+1]);
}

void rmqBuild() {
    int n = s.length();
    for(int i=1;i<=n;++i) {
	lg2[i] = log2(i);
    }
    for(int i=1;i<n;++i) {
	spt[0][i] = LCP[i];
    }
    for(int i=1;i<stp;++i) {
	for(int j=1;j+(1<<i)-1<n+n+1;++j) {
	    spt[i][j] = min(spt[i-1][j],spt[i-1][j+(1<<(i-1))]);
	}
    }
}
