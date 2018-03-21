int p[SZ];
int sz[SZ];

struct dsu {

    dsu() {
	for(int i=0;i<SZ;i++) {
	    p[i] = i;
	    sz[i] = 1;
	}
    }

    int get_parent(int u) {
	if(u==p[u]) {
	    return u;
	}
	return p[u] = get_parent(p[u]);
    }

    void dsu_union(int u, int v) {
	int pu = get_parent(u);
	int pv = get_parent(v);
	if(pu==pv) return;
	else {
	    if(sz[pu]>=sz[pv]) {
		p[pv] = pu;
		sz[pu] = sz[pu] + sz[pv];
	    }
	    else {
		p[pu] = pv;
		sz[pv] = sz[pv] + sz[pu];
	    }
	}
	return;
    }
};
