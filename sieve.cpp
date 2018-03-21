
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
#define pb push_back

bitset<1000001> b;
vector<int> v;

void sieve() {
    for(int i=3;i<=1000;i+=2) {
	for(int j=i*i;j<=1000000;j+=i) {
	    b[j]=1;
	}
    }
    v.pb(2);
    for(int i=3;i<=1000000;i+=2) {
	if(b[i]==0) {
	    v.pb(i);
	}
    }
}

