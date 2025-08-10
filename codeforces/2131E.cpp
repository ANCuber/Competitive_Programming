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
    bool flag = true;
    if (a[n - 1] != b[n - 1]) {
        cout << "NO\n";
        return;
    } 
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] != b[i]) {
            if ((a[i] ^ b[i + 1]) == b[i])  {
                continue;
            } else if ((a[i] ^ a[i + 1]) == b[i]) {
                continue;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << (flag ? "YES" : "NO") << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
