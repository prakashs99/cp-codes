/* phi[n] will contain the value of phi(n) */

ll prime[10000005]={0};
ll phi[10000005];
ll a[10000005];

ll power(ll a, ll b) {   // a^b
    ll ans = 1;
    while(b) {
	if(b&1) {
	    ans = (ans*a);
	}
	b = b>>1;
	a = (a*a);
    }
    return ans;
}

void sieve() {
    for(int i=2;i<=10000000;++i) {
	if(!prime[i]) {
	    for(int j=i+i;j<=10000000;j+=i) { // prime[i] stores nearest prime which divides n.
		prime[j]=i;
	    }
	}
    }
}

void comp() {
    sieve();
    phi[1]=1;
    for(int i=2;i<=10000000;++i) {
	if(!prime[i]) {
	    phi[i] = i-1;
	}
	else {
	    int n = 0,save = i;
	    while(save%prime[i]==0) {
		save /= prime[i];
		n++;
	    }
	    phi[i] = power(prime[i],n) - power(prime[i],n-1);
	    phi[i] = phi[i]*phi[save];
	}
    }
    a[1]=phi[1];
    for(int i=2;i<=10000000;++i) {
	a[i]=a[i-1]+phi[i];
    }
}
