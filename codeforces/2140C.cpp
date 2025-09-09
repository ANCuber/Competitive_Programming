#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n + 3), b, c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i & 1) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    if (n == 1) {
        cout << a[1] << "\n";
        return;
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) sum += a[i];
        else sum -= a[i];
    }
    if (b[0] > c.back()) {
        if (n == 2) {
            cout << sum << "\n";
        } else {
            if (n & 1) cout << sum + (n - 1) << "\n";
            else cout << sum + (n - 2) << "\n";
        }
    } else if (b[0] == c.back()) {
        if (n == 2) {
            cout << sum + 1 << "\n";
        } else {
            if (n & 1) cout << sum + (n - 1) << "\n";
            else if (a[1] == b[0] && a[n] == b[0]) cout << sum + (n - 1) << "\n";
            else cout << sum + (n - 2) << "\n";
        }
    } else {
        sum -= 2 * b[0], sum += 2 * c.back();
        int mx1 = 0, mx2 = 0, mn1 = 1e9 + 5, mn2 = 1e9 + 5;
        for (int i = 1; i <= n; ++i) {
            if ((i & 1) ^ 1) continue; 
            if (a[i] == b[0]) {
                mx1 = max(mx1, i);
                mn1 = min(mn1, i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (i & 1) continue;
            if (a[i] == c.back()) {
                mx2 = max(mx2, i);
                mn2 = min(mn2, i);
            }
        }
        cout << sum + max({mx2 - mn1, mx1 - mn2, mx1 - mn1, mx2 - mn2}) << "\n";
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
