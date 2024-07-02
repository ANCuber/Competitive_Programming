#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    vector<ll> tsk(n+5,0), t(n);
    for (int i = 0; i < m; ++i) {
        int l, r, w;
        cin>>l>>r>>w;
        tsk[l] += w, tsk[r+1] -= w;
    }
    for (int i = 1; i <= n; ++i) tsk[i] += tsk[i-1];
    for (auto &i : t) cin>>i;
    sort(t.begin(),t.end());
    sort(tsk.begin()+1,tsk.begin()+n+1);
    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += t[i]*tsk[n-i];
    cout<<ans<<'\n';
    return 0;
}
