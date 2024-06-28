#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll ans = 0;

void dfs(int f) {
    int u; cin>>u;
    if (!u) return;
    if (f) ans += abs(u-f);
    if (u&1) {
        dfs(u); dfs(u); dfs(u);
    } else {
        dfs(u); dfs(u);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    dfs(0);
    cout<<ans<<'\n';
    return 0;
}
