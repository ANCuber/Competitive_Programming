#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int k; cin >> k;
    ll x; cin >> x;
    ll y = (1ll << (k + 1)) - x;
    vector<int> ans;
    if (x & 1ll) {
        if (x > y) {
            x -= y;
            y += y;
            ans.push_back(2);
        } else {
            y -= x;
            x += x;
            ans.push_back(1);
        }
    }
    while (x != y) {
        if (x > y) {
            x -= y;
            y += y;
            ans.push_back(2);
        } else {
            y -= x;
            x += x;
            ans.push_back(1);
        }
    }
    cout << (int)ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; --i) {
        if (i != ans.size() - 1) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
