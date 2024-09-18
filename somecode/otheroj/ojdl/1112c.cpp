#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, w, f;    
    cin>>n>>m>>w>>f;
    vector<vector<int> > g(n+2,vector<int>(n+2,0));
    vector<int> a(n+5), b(n+5);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    for (int i = 1; i <= n; ++i) cin>>b[i];
    int u, v, d;
    while(m--) {
        cin>>u>>v>>d;
        g[u][v] = g[v][u] = d;
    }
    int s, e, bb, gg;
    cin>>s>>e>>bb>>gg;
    vector<int> dis(n+5,1e8);
    dis[s] = 0;
    priority_queue< pii , vector< pii >, greater< pii > > pq;
    pq.push({0,s});
    while(!pq.empty()) {
        int cur = pq.top().second, val = pq.top().first;
        pq.pop();
        for (int i = 1; i <= n; ++i) {
            if (g[i][cur]) {
                if (dis[i] > dis[cur]+g[i][cur]) {
                    dis[i] = dis[cur]+g[i][cur];
                    pq.push({dis[cur]+g[i][cur],i});
                }
            }
        }
    }
    cout<<min(0,bb-dis[e])<<endl;
    
    return 0;
}
