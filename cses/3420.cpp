#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    
    set <int> s;
    int pre = -1;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        while (s.find(a[i]) != s.end())
            s.erase(a[++pre]);
        s.insert(a[i]);
        ans += (i - pre);
    }
    
    cout << ans << "\n";
    return 0;
}
