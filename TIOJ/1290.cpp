#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

void solve(int n, int m) {
    int st, ed; cin>>st>>ed;
    int a, b, c;
    vector<vector< pii > > g(n+1);
    while(m--) {
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    vector<int> d(n+1,1e11);
    vector<int> vis(n+1,0);
    queue < pii > pq;
    d[st] = 0;
    pq.push({0,st});

    while(pq.size()) {
        int cur = pq.front().second;
        pq.pop();
        //if (vis[cur]) continue;
        //vis[cur] = 1;

        for (auto i : g[cur]) {
            if (d[i.first] > d[cur]+i.second) {
                d[i.first] = d[cur]+i.second;
                pq.push({d[i.first],i.first});
            }
        }
    }
    if (d[ed] >= 1e11) cout<<"He is very hot"<<endl;
    else cout<<d[ed]<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    while(cin>>n>>m) {
        solve(n,m);
    }
    return 0;
}
