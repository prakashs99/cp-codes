

void matmult(ll ret[32][32], ll x[32][32], ll y[32][32]) {
    ll temp[32][32];
    for(int i=0;i<32;i++) {
	for(int j=0;j<32;j++) {
	    temp[i][j] = 0;
	    for(int k=0;k<32;k++) {
		temp[i][j] += (x[i][k] * y[k][j])%mod;
		temp[i][j] %= mod;
	    }
	}
    }
    for(int i=0;i<32;i++) {
	for(int j=0;j<32;j++) {
	    ret[i][j] = temp[i][j];
	}
    }
}

void matexpo(ll x[32][32], ll  b) {
    ll ans[32][32];
    for(int i=0;i<32;i++) {
	for(int j=0;j<32;j++) {
	    ans[i][j] = 0;
	    if(i==j) {
		ans[i][j] = 1;
	    }
	}
    }
    while(b) {
	if(b&1) {
	    matmult(ans,ans,x);
	}
	b = b>>1;
	matmult(x,x,x);
    }
    for(int i=0;i<32;i++) {
	for(int j=0;j<32;j++) {
	    x[i][j] = ans[i][j];
	}
    }
}

