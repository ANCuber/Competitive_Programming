#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, r; cin>>n>>r;
    vector<vector<int> > g(n+3);
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    bitset<300005> rmv;
    rmv.reset();
    p_q <int,vector<int>,greater<int> > pq;
    pq.push(r);
    int cnt = 1, ans = 0;
    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        if (rmv[cur]) continue;
        ans += cnt*cur;
        cnt++;
        rmv[cur] = 1;
        for (auto v : g[cur]) {
            if (rmv[v]) continue;
            pq.push(v);
        }
    }
    cout<<ans<<endl;
    return 0;
}
