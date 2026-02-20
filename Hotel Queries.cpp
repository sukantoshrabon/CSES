#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int N = 2e6 + 10;
int arr[N];

struct st {
  ll segT[N * 4];
  static const int inf = 1e9;

  st(){
    memset( segT, 0, sizeof(segT) );
  }
  inline void pull(int node, int lc, int rc){     
    segT[node] = max(segT[lc], segT[rc]);
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
    if( b == e ){
      segT[node] = val;
      return;
    }
    int mid = (b + e) >> 1;
    int lc = (node << 1), rc = (node << 1) + 1;
    if(i <= mid )
        upd( lc, b, mid, i, val); 
    else  
        upd( rc, mid + 1, e, i, val);
    pull( node, lc, rc );
  }
  ll query(int node, int b, int e, int x){     
    if(segT[node] < x ) return 0;
    if(b == e) return b;
    int mid = (b + e) >> 1;
    int lc = (node << 1), rc = (node << 1) + 1;
    if(segT[lc] >= x)
        return query(lc, b, mid, x);
    else 
        return query(rc, mid + 1, e, x);      
  }
} segT;

void solve() {
    int n,m; cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> arr[i];
    segT.build(1,1,n);
    while(m--){
        int x; cin >> x;
        int room = segT.query(1,1,n,x);
        cout << room << " ";
        if(room != 0){
            arr[room] -= x;
            segT.upd(1,1,n,room,arr[room]);
        }
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