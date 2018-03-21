int Z[400005];

void z(string a) {
    int n = a.length();
    Z[0]=-1;
    int l,r;
    l = r = 0;
    for(int i=1;i<n;++i) {
	if(i>r) {
	    l = r = i;
	    while(r<n && a[r]==a[r-l]) {
		r++;
	    }
	    r--;
	    Z[i] = r-l+1;
	}
	else {
	    int k = i-l;
	    if(Z[k] < r-i+1) {
		Z[i] = Z[k];
	    }
	    else {
		l = i;
		while(r<n && a[r]==a[r-l]) {
		    r++;
		}
		r--;
		Z[i] = r-l+1;
	    }
	}
    }
}
