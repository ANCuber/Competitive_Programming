#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mod = 1073741824;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+1);
    vector<int> dg(n+1,0), cnt(n+1,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        dg[v]++;
    }
    int st, ed; cin>>st>>ed;
    cnt[st] = 1;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!dg[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            dg[v]--;
            cnt[v] = (cnt[v]+cnt[u])%mod;
            if (!dg[v]) {
                q.push(v);
            }
        }
    }
    cout<<cnt[ed]<<endl;
    return 0;
}
