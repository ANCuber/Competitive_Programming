#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int flag = 1;

void chk(int u, int c, vector<vector<int> > &g, vector<int> &col) {
    if (!flag) return;
    col[u] = c;
    for (auto v : g[u]) {
        if (!col[v]) chk(v,3-c,g,col);
        else if (col[v] == c) flag = 0;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+1);
    vector<int> col(n+1,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!col[i]) chk(i,1,g,col);
    }
    if (!flag) {
        cout<<"IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            if (i != 1) cout<<' ';
            cout<<col[i];
        }
        cout<<endl;
    }
    return 0;
}
