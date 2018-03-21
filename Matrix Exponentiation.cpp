const int mod = 1000000007;

vector<vector<ll> > matMult(vector<vector<ll> > a, vector<vector<ll> > b) {  // returns a*b
    int r1 = a.size();
    int c1 = a[0].size();
    int r2 = b.size();
    int c2 = b[0].size();
    vector<vector<ll> > temp;
    temp.resize(r1);
    for(int i=0;i<r1;i++) {
	temp[i].resize(c2);
    }
    for(int i=0;i<r1;i++) {
	for(int j=0;j<c2;j++) {
	    temp[i][j] = 0;
	    for(int k=0;k<c1;k++) {
		temp[i][j] += (a[i][k]*b[k][j])%mod;
		temp[i][j] %= mod;
	    }
	}
    }
    return temp;
}

vector<vector<ll> > matExpo(vector<vector<ll> > g, int b) {  // return g^b
    vector<vector<ll> > res;
    int r1 = g.size();
    int c1 = g[0].size();
    res.resize(r1);
    for(int i=0;i<r1;i++) {
	res[i].resize(r1);
	for(int j=0;j<c1;j++) {
	    res[i][j] = 0;
	    if(i==j) res[i][j] = 1;
	}
    }
    while(b) {
	if(b&1) {
	    res = matMult(res,g);
	}
	b = b>>1;
	g = matMult(g,g);
    }
    return res;
}
