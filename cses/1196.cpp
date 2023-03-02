#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m, k;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;    
    vector<vector< pii > > g(n+1);
    while(m--) {
        int u, v, w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
    }
    vector<int> d(n+1,1e18);
    vector<vector<int> > ans(n+1);
    d[1] = 0;
    p_q < pii, vector< pii >, greater< pii > > pq;
    pq.push({0,1});
    while(!pq.empty()) {
        int u = pq.top().second, cw = pq.top().first;
        pq.pop();
        if (ans[u].size() >= k) continue;
        ans[u].pb(cw);
        for (auto [v,w] : g[u]) {
            pq.push({cw+w,v});
        }
    }
    for (int i = 0; i < k; ++i) {
        if (i) cout<<' ';
        cout<<ans[n][i];
    }
    cout<<endl;
    return 0;
}
