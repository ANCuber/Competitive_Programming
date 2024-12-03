#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void Run() {
    int n; cin>>n;
    vector<vector<ll> > a(3,vector<ll>(n+5));
    ll bs = 0;
    for (int i = 1; i <= n; ++i) cin>>a[1][i];
    for (int i = 1; i <= n; ++i) {
        cin>>a[2][i];
        bs += max(a[1][i], a[2][i]);
    }
    ll ans = -1e18;
    for (int i = 1; i <= n; ++i) ans = max(ans,bs+min(a[1][i], a[2][i]));
    cout<<ans<<'\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--) Run();
    return 0;
}
