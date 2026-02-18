#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int x,y;
    cin >> x >>y;
    int maxx  = max(x,y);
    ll s = 1LL * maxx * maxx;

    if (maxx % 2 == 0) {
        cout << s - (maxx - x) - (y - 1) << endl;
    } else {
        cout << s - (x - 1) - (maxx - y) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}