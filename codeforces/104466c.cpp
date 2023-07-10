#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void bfs(int s, vector<vector<int> > &g, vector<int> &dis) {
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while(q.size()) {
        int cur = q.front();
        q.pop();
        for (auto v : g[cur]) {
            if (dis[v] < 1e9) continue;
            dis[v] = dis[cur]+1;
            q.push(v);
        }
    }
}


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k; cin>>n>>m>>k;    
    vector<int> tel;
    vector<vector<int> > g(n+5);
    for (int i = 0; i < k; ++i) {
        int x; cin>>x;
        tel.push_back(x);
    }
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    } 
    vector<int> tod(n+5,1e9), bcd(n+5,1e9);
    bfs(1,g,tod), bfs(n,g,bcd);
    int s = 0;
    for(auto v : tel) s+=bcd[v];
    pair<int,int> ans = {tod[n],1};
    for(auto v : tel){
        if(k==1) continue;
       int sum = tod[v]*(k-1);
       sum+=s-bcd[v];
       int div = __gcd(sum,(k-1));
       pair<int,int> curans={sum/div,(k-1)/div};
       if(ans.first*curans.second>ans.second*curans.first){
          ans = curans; 
       }
    }
    cout<<ans.first<<"/"<<ans.second<<"\n"; 
    return 0;
}
