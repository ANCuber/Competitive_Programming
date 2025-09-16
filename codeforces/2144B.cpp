#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> usd(n + 3, 0), arr(n + 3);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        if (arr[i]) usd[arr[i]] = 1;
    }
    int ptr = n;
    for (int i = 1; i <= n; ++i) {
        if (arr[i]) continue;
        while (usd[ptr]) ptr--;
        arr[i] = ptr--;
    }
    vector<int> cnt(n + 3, 0);
    for (int i = 1; i <= n; ++i) {
        if (arr[i] != i) {
            int u = min(i, arr[i]), v = max(i, arr[i]);
            cnt[u]++, cnt[v + 1]--;
        }
    }
    int mn = 0, mx = -1, cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += cnt[i];
        if (cur) {
            if (!mn) mn = i;
            mx = i;
        }
    }
    cout << max(0, mx - mn + 1) << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
