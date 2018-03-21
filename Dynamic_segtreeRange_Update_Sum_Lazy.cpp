#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi  vector<int>
#define pb  push_back
#define mp  make_pair
#define ALL(x) x.begin(),x.end()
#define M(a,x) memset(a,x,sizeof(a))
#define sci(x) scanf("%d",&x);
#define scl(x) scanf("%lld",&x);
#define scs(x) scanf("%s",x);
#define SZ(x) (int)x.size()
#define print(x) printf("%d",x);
#define nl printf("\n")
#define fr first
#define se second
#define printl(x) printf("%lld",x)
#define F(i,a,n) for(int i=a;i<n;i++)
#define INF 100000000000000000LL
#define LL long long

const int N = 1e5+5;
struct Node {
  Node* left, *right;
  LL val;
  LL lazy;
  Node() {
    left = right = NULL;
    val = 0;
    lazy = 0;
  }
};
inline void refresh(Node* &root, int x,int y) {
  if(root->lazy!=0) {
    root->val += 1LL * (y-x+1) * root->lazy;
    if(root->left == NULL){
      root->left = new Node();
    }
    if(root->right == NULL ) {
      root->right = new Node();
    }
    root->left->lazy += root->lazy;
    root->right->lazy += root->lazy;
    root->lazy = 0;
  }
}
inline void update(Node* &root , int x, int y , int b,int e,int val) {
  refresh(root,x,y);
  if(x > e || y < b) {
    return ;
  }
  int mid = (x+y)/2;
  if(x >= b && y <= e) {
    root->lazy += val;
    refresh(root,x,y);
    return ;
  }
  if(root->left == NULL ) {
    root->left = new Node();
  }
  if(root->right == NULL ) {
    root->right = new Node();
  }
  update(root->left,x,mid,b,e,val);
  update(root->right,mid+1,y,b,e,val);
  root->val = root->left->val + root->right->val;
}
LL query(Node* &root,int x,int y,int b,int e) {
  if(root == NULL || x > e || y < b ) {
    return 0;
  }
  refresh(root,x,y);
  if( x>= b && y<=e ) {
    return root->val;
  }
  int mid = (x+y)/2;
  LL L = query(root->left,x,mid,b,e);
  LL R = query(root->right,mid+1,y,b,e);
  return L + R;
}
int main() {
  int t;
  sci(t);
  while(t--) {
    Node* root = new Node();
    int n,q;
    sci(n) ; sci(q);
    while(q--) {
      int tp;
      sci(tp);
      if(!tp) {
	int x,y,v;
	sci(x) ; sci(y) ; sci(v);
	update(root,1,n+2,x,y,v);
      }
      else {
	int x,y;
	sci(x) ; sci(y);
	printf("%lld\n",query(root,1,n+2,x,y));
      }
    }
  }
}
