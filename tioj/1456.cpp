#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m;

bool solve() {
    vector<vector<int> > g(n+1);
    vector<int> dg(n+1,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        dg[v]++;
    }
    int flag = 1;
    
    for (int i = 1; i <= n; ++i) {
        int x; cin>>x;
        if (dg[x]) flag = 0;
        for (auto v : g[x]) {
            dg[v]--;
        }
    }
    return flag;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n>>m) {
        if (solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
