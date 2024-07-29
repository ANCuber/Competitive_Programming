#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const ll M = 1e9+7;

ll power(ll a, int x) {
    ll ret = 1, bs = a;
    while(x) {
        if (x&1) ret = ret*bs%M;
        bs = bs*bs%M;
        x >>= 1;
    }
    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<vector<int> > g(n+2);
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = g[i].size();
        ans = (ans+power(2,cur)-1)%M;
    }
    cout<<(ans-(n-1)+M)%M<<'\n';
    return 0;
}
