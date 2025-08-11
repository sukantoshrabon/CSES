#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    ll steps = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            steps += (a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }
    }

    cout << steps << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}