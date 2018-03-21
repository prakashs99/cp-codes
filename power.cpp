
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
