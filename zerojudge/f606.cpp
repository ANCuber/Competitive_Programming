#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin>>n>>m>>k;
    vector<vector<ll> > Q(n,vector<ll>(m,0)), tmp(m,vector<ll>(m,0));
    vector<int> c(n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin>>Q[i][j];
    ll ans = 4e18;
    while(k--) {
        for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) tmp[i][j] = 0;
        ll cur = 0;
        for (auto &i : c) cin>>i;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) tmp[c[i]][j] += Q[i][j];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == j) cur += tmp[i][j];
                else cur += min((ll)1000,tmp[i][j])*3+max(0ll,tmp[i][j]-1000)*2;
            }
        }
        ans = min(ans,cur);
    }
    cout<<ans<<'\n';
    return 0;
}
