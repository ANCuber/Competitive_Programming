#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int cnt = 0, tmp = 0;

void dfs(int p, vector<int> &d, vector<int> &v, vector<vector<int> > &g) {
    v[p] = 1;
    tmp += (d[p]%2);
    for (auto i : g[p]) {
        if (!v[i]) dfs(i,d,v,g);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, s, m, k;
    cin>>a>>b>>s>>m>>k;
    vector<int> d(a+b+5,0), v(a+b+5,0);
    vector<vector<int> > g(a+b+5);
    while(k--) {
        int u, v, c;
        cin>>u>>v>>c;
        d[u]++;
        d[a+v]++;
        g[u].pb(a+v);
        g[a+v].pb(u);
    }
    for (int i = 1; i <= a+b; ++i) {
        tmp = 0;
        if (!v[i] && d[i]) {
            dfs(i,d,v,g);
            cnt += max(tmp/2,1);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
