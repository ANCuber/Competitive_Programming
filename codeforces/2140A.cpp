#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == '1') cnt++;
    int ans = 0;
    for (int i = n - cnt; i < n; ++i) {
        if (s[i] == '1') continue;
        ans++;
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
