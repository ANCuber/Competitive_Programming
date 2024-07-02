#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int p, q, r, m;
    cin>>p>>q>>r>>m;
    queue<int> Q;
    vector<int> val(p+q+r+5,-1), vis(p+q+r+5,0);
    vector<int> t(p+q+r+5,0);
    vector<vector<int> > g(p+q+5);
    for (int i = 1; i <= p; ++i) {
        cin>>val[i];
        vis[i] = 1;
        t[i] = -1;
        Q.push(i);
    }
    for (int i = p+1; i <= p+q; ++i) cin>>t[i];
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
    }
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (auto nx : g[cur]) {
            vis[nx] = max(vis[nx],vis[cur]+1);
            if (!t[nx]) {
                val[nx] = val[cur];
            } else if (t[nx] == 4) {
                val[nx] = !val[cur];
                Q.push(nx);
            } else if (val[nx] < 0) {
                val[nx] = val[cur];
            } else if (t[nx] == 1) {
                val[nx] &= val[cur];
                Q.push(nx);
            } else if (t[nx] == 2) {
                val[nx] |= val[cur];
                Q.push(nx);
            } else if (t[nx] == 3) {
                val[nx] ^= val[cur];
                Q.push(nx);
            }
        }
    }
    cout<<*max_element(vis.begin()+p+q+1,vis.begin()+p+q+r+1)-2<<'\n';
    for (int i = 0; i < r; ++i) {
        if (i) cout<<' ';
        cout<<val[i+p+q+1];
    }
    cout<<'\n';
    return 0;
}
