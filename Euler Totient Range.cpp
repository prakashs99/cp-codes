// Function to Find Euler Totient of numbers within the range [l,r]. r-l<=100000

bool siev[1000005];
vector<int> v;

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
    for(int i=2;i<=1000000;++i) {
	if(!siev[i]) {
	    v.pb(i);
	    for(int j=i+i;j<=1000000;j+=i) {
		siev[j]=true;
	    }
	}
    }
}

void ETF(int l, int r) {
	int cnt[100001];
	ll etf[100005];
	ll x[100005];
	for(int i=l;i<=r;++i) {
	    x[i-l]=i;
	    etf[i-l]=1;
	}
	for(int i=0;i<=100000;++i) {
	    etf[i]=1;
	}
	for(int j=0;j<v.size() && v[j]<=r;++j) {
	    ll temp = ceil(((double)l)/v[j]);
	    ll y;
	    while(v[j]*temp <= r) {
		y = temp*v[j];
		int c = 0;
		while(y%v[j]==0) {
		    c++;
		    y /= v[j];
		}
		etf[temp*v[j]-l] *= power(v[j],c) - power(v[j],c-1);
		x[temp*v[j]-l] /=  power(v[j],c);
		temp++;
	    }
	}
	for(int i=0;i<r-l+1;++i) {
	    if(x[i]>1) {
		etf[i] *= x[i]-1;
	    }
	}
}
