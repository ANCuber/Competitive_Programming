#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    int g = 0, l = 0;
    for (int i = 0; i < n; ++i) {
        g += max(a[i] - b[i], 0);
        // l += max(b[i] - a[i], 0);
    }
    cout << g + 1 << "\n";
    return;
    if (g == l) cout << g + 1 << "\n";
    else if (g > l) cout << g + 1 << "\n";
    else cout << g + 1 << "\n";
} 

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;
    while (T--) solve();
    return 0;
}
