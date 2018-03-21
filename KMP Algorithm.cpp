// Solution for TASHIFT on CodeChef

int LPS[4000005];

void lps(string a) {
    int n = a.length();
    LPS[0] = 0;
    int l = 0;
    for(int i=1;i<n;) {
	if(a[i]==a[l]) {
	    l++;
	    LPS[i] = l;
	    i++;
	}
	else {
	    if(l) {
		l = LPS[l-1];
	    }
	    else {
		LPS[i] = 0;
		i++;
	    }
	}
    }
}

void kmp(string a, string b) {   // a=pattern, b=text
    int n,m,ans=0,idx;
    n = a.length(); m = b.length();
    int cnt = 0;
    for(int i=0,j=0;i<m;) {
	if(a[j]==b[i]) {
	    cnt++;
	    if(cnt>ans) {
		ans = cnt;
		idx = i-cnt+1;
	    }
	    if(cnt==n) {
		idx = i-cnt+1;
		break;
	    }
	    j++;
	    i++;
	}
	else {
	    if(j>0) {
		j = LPS[j-1];
		cnt = LPS[j-1];
	    }
	    else {
		i++;
		cnt = 0;
	    }
	}
    }
    printf("%d\n",idx);
}
