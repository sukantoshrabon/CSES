#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n,q;
    cin >> n >> q;
    vector<ll>l(n),r(n);
    for(int i=0; i<n; i++){
      cin >> l[i] >> r[i];
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    while (q--){
      int x; cin >> x;
      ll st = upper_bound(l.begin(),l.end(),x) - l.begin();
      ll ed = lower_bound(r.begin(),r.end(),x) - r.begin();
      int ans = st - ed;
      if(ans > 0){
        cout << ans << endl;
      } else {
        cout << 0 << endl;
      }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
      cout << "Case " << tc << ":" << endl;
      solve(); 
    }
    return 0;
}