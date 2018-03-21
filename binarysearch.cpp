
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

int solve(int low, int high, int q) {
    int mid=(high-low)/2;
    bool flg=false;
    while(low<=high) {
	//      mid = (low+high)/2;
	int x = check(mid);
	if(x==q) {
	    high=mid-1;
	    flg = true;
	    mid=(low+high)/2;
	}
	if(x>q) {
	    high=mid-1;
	    mid=(low+high)/2;
	}
	if(x<q) {
	    low=mid+1;
	    mid=(low+high)/2;
	}
    }
    if(flg) {
	return mid+1;
    }
    else {
	return -1;
    }
}

