#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q; 
    cin>>n>>m>>q;    
    vector<vector<int> > g(n+1,vector<int>(n+1,1e18));
    while(m--) {
        int u, v, w; 
        cin>>u>>v>>w;
        g[u][v] = g[v][u] = min(g[v][u],w);
    }
    
    for (int i = 1; i <= n; ++i) g[i][i] = 0;

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    
    while(q--) {
        int u, v; cin>>u>>v;
        if (g[u][v] < 1e18) cout<<g[u][v]<<endl;
        else cout<<-1<<endl;
    }
    
    return 0;
}
