#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int N = 1e6 + 10;
int arr[N];

// Segment Tree for max. pull,upd,query....
struct st {
  ll segT[N * 4];
  static const int inf = 1e9;

  st(){
    memset( segT, 0, sizeof(segT) );
  }
  inline void pull(int node, int lc, int rc){     
    segT[node] = min(segT[lc], segT[rc]);
  }
  void build(int node, int b, int e){
    if( b == e ){
      segT[node] = arr[e];
      return;
    }
    int mid = (b + e) >> 1;
    int lc = (node << 1), rc = (node << 1) + 1;
    build( lc, b, mid );
    build( rc, mid + 1, e );
    pull( node, lc, rc );
  }
  void upd(int node, int b, int e, int i, int val){
    if( b > i || e < i ) {return;}
    if( b == e && e == i ){
      segT[node] = val;
      return;
    }
    int mid = (b + e) >> 1;
    int lc = (node << 1), rc = (node << 1) + 1;
    upd( lc, b, mid, i, val);
    upd( rc, mid + 1, e, i, val);
    pull( node, lc, rc );
  }
  ll query(int node, int b, int e, int i, int j){
    if( b > j || e < i ) {return inf;}      
    if( b >= i && e <= j ) {return segT[node];}
    int mid = (b + e) >> 1;
    int lc = (node << 1), rc = (node << 1) + 1;
    ll L = query(lc, b, mid, i, j);
    ll R = query(rc, mid + 1, e, i, j);
    return min(L, R);       
  }
} segT;

void solve() {
    ll n,q; cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    segT.build(1,1,n);
    while(q--){
        ll l,r; cin >> l >> r;
        ll ans = segT.query(1,1,n,l,r);
         cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}