#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int s1 = a[i], s2 = a[j] - a[i], s3 = a[n] - a[j];
            if ((s1 % 3 == s2 % 3 && s2 % 3 == s3 % 3) || (s1 % 3 != s2 % 3 && s2 % 3 != s3 % 3 && s3 % 3 != s1 % 3)) {
                cout << i << " " << j << "\n";
                return;
            } 
        }
    }
    cout << 0 << " " << 0 << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
