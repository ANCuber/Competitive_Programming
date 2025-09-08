#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    for (ll i = n - 1, j = 0; i >= 0; --i, ++j)
        ans += max(0ll, m - j) * a[i];
    cout << ans << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
