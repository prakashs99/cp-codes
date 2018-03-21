
int p[20][400005];

typedef struct entry {
    int r[2];
    int idx;
} entry;

entry l[400005];
int stp, len;
int sa[400005];
int LCP[400005];

bool cmp(entry a, entry b) {
    if(a.r[0] == b.r[0]) {
	return a.r[1] < b.r[1];
    }
    return a.r[0] < b.r[0];
}

bool cmp2(int a, int b) {
    return p[stp-1][a] < p[stp-1][b];
}

void SA(string s) {
    int n = s.length();
    for(int i=0;i<n;++i) {
	p[0][i] = s[i]-'a';
    }
    for(len=1,stp=1;len/2 < n; ++stp,len *= 2) {
	for(int i=0;i<n;++i) {
	    if(i+len<n) {
		l[i].r[0] = p[stp-1][i];
		l[i].r[1] = p[stp-1][i+len];
		l[i].idx = i;
	    }
	    else {
		l[i].r[0] = p[stp-1][i];
		l[i].r[1] = -1;
		l[i].idx = i;
	    }
	}
	sort(l,l+n,cmp);
	for(int i=0;i<n;++i) {
	    if(i>0) {
		if(l[i].r[0]==l[i-1].r[0] && l[i].r[1]==l[i-1].r[1]) {
		    p[stp][l[i].idx] = p[stp][l[i-1].idx];
		}
		else {
		    p[stp][l[i].idx] = i;
		}
	    }
	    else {
		p[stp][l[i].idx] = i;
	    }
	}
    }
    for(int i=0;i<n;++i) {
	sa[i] = i;
    }
    sort(sa,sa+n,cmp2);
    // For LCP Array
    for(int i=1;i<n;++i) {
	LCP[i] = 0;
	int x=sa[i-1],y=sa[i];
	for(int k=stp-1;k>=0 && x<n && y<n;--k) {
	    if(p[k][x]==p[k][y]) {
		LCP[i] += 1<<k;
		x += 1<<k;
		y += 1<<k;
	    }
	}
    }
}
