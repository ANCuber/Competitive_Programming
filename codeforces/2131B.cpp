#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    int n; cin >> n;
    if (n == 2) {
        cout << "-1 2\n";
        return;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (i & 1) a[i] = 3;
        else a[i] = -1;
    }
    if (n % 2 == 0) 
        a[n - 1] = 2;
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
