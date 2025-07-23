#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const ll M = 1e9 + 7;

ll fpow(int a, int x) {
    ll ret = 1, bs = a;
    while (x) {
        if (x & 1) ret = ret * bs % M;
        bs = bs * bs % M;
        x >>= 1;
    }
    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll ans = 0, cur = 1;
    map <int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        /*cout << cur << "\n";*/
        if (mp.find(x) == mp.end()) {
            ans = (ans + cur) % M;
            mp[x] = 1;
        } else {
            ans = (ans + cur * fpow(mp[x] + 1, M - 2) % M) % M;
            mp[x]++;
        }
        cur = cur * fpow(mp[x], M - 2) % M;
        cur = cur * (mp[x] + 1) % M;
    }
    cout << ans << "\n";
    return 0;
}
