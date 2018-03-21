
#include<bits/stdc++.h>

using namespace std;

#define si(x) scanf("%d",&x)
#define pri(x) printf("%d",x)
#define sll(x) scanf("%lld",&x)
#define pll(x) printf("%lld",x)
#define sstr(s) scanf("%s",s)
#define pstr(s) printf("%s",s)
#define nl printf("\n")
#define ll long long int

ll power(ll a, ll b) {   // a^b
    ll ans = 1;
    while(b) {
	if(b&1) {
	    ans = (ans*a)%mod;
	}
	b = b>>1;
	a = (a*a)%mod;
    }
    return ans;
}

void comp() {
    fact[0]=1;
    fact[1]=1;
    invfact[1]=1;
    invfact[0]=1;
    for(int i=2;i<=1000000;++i) {
	fact[i] = (fact[i-1]*i)%mod;
	invfact[i] = (invfact[i-1]*power(i,mod-2))%mod;
    }
}

