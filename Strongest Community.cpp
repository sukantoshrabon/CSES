#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int N = 1e6 + 10;
int arr[N];

struct st {
  pair<ll,ll> segT[N * 4];

  st(){
    memset(segT, 0, sizeof(segT));
  }

  inline void pull(int node, int lc, int rc){     
    if(segT[lc].first == segT[rc].first){
        segT[node].first = segT[lc].first;
        segT[node].second = (segT[lc].second + segT[rc].second);
    } else {
        if(segT[lc].second > segT[rc].second){
            segT[node] = segT[lc];
        } else {
            segT[node] = segT[rc];
        }
    }
  }

  void build(int node, int b, int e){
    if(b == e){
      segT[node].first = arr[b];
      segT[node].second = 1;
      return;
    }
    int mid = (b + e) >> 1;
    int lc = (node << 1), rc = lc + 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(node, lc, rc);
  }

  pair<ll,ll> query(int node, int b, int e, int i, int j){
    if(b > j || e < i) return {-1, 0};      
    if(b >= i && e <= j) return segT[node];

    int mid = (b + e) >> 1;
    int lc = (node << 1), rc = lc + 1;
    auto L = query(lc, b, mid, i, j);
    auto R = query(rc, mid + 1, e, i, j);

    if(L.first == -1) return R;
    if(R.first == -1) return L;

    if(L.first == R.first){
        return {L.first , L.second + R.second};
    }
    if(L.second > R.second)
        return L;
    else
        return R;     
  }
} segT;

void solve() {
    int n, c, q; 
    cin >> n >> c >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    segT.build(1, 1, n);

    while(q--){
        int l, r;
        cin >> l >> r;
        auto ans = segT.query(1, 1, n, l, r);
        cout << ans.second << endl;
        // cout << "Community: " << ans.first << ", Frequency: " << ans.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "Case " << tc << ":" << endl;
        solve();
    }
    return 0;
}
