#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    int n, k; cin >> n >> k;
    vector<int> s(n), t(n);
    multiset<int> st;
    for (auto &i : s) {
        cin >> i;
        i %= k;
        st.insert(i);
    }
    bool flag = false;
    for (auto &i : t) {
        cin >> i;
        i %= k;
        if (st.find(i) != st.end()) {
            st.erase(st.find(i));
        } else if (st.find(k - i) != st.end()) {
            st.erase(st.find(k - i));
        } else if (!flag) {
            cout << "NO\n";
            flag = true;
        }
    }
    if (!flag) cout << "YES\n";
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
