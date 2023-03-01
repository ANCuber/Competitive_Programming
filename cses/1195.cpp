#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m;

void dij(int s, vector<vector< pii > > &g, vector<int> &d) {
    vector<int> v(n+1,0);
    p_q < pii,vector< pii >, greater< pii > > pq;
    pq.push({0,s});
    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if (v[cur.second]) continue;
        v[cur.second] = 1;
        for (auto [i,c] : g[cur.second]) {
            if (d[i] > cur.first+c) {
                d[i] = cur.first+c;
                pq.push({d[i],i});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;    
    int u, v, w;
    vector<vector< pii > > fg(n+1), bg(n+1);
    vector<int> fd(n+1,1e18), bd(n+1,1e18);
    fd[1] = bd[n] = 0;
    while(m--) {
        cin>>u>>v>>w;
        fg[u].pb({v,w});
        bg[v].pb({u,w});
    }
    dij(1,fg,fd), dij(n,bg,bd);
    int mn = 1e18;
    for (int i = 1; i <= n; ++i) {
        for (auto [j,c] : fg[i]) {
            mn = min(mn,fd[i]+bd[j]+c/2);
        }
    }
    cout<<mn<<endl;
    return 0;
}
