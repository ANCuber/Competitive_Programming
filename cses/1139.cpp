#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int c[200005];
int sz[200005]; 
int ans[200005];

int getsz(int u, int f, vector<vector<int> > &g) {
    int cnt = 0;
    for (auto v : g[u]) {
        if (v != f) cnt += getsz(v,u,g);
    }
    return sz[u] = ++cnt;
}

set<int> dfs(int u, int f, vector<vector<int> > &g) {
    int bs = 0, mxw = 0;
    set<int> cur, s;
    cur.insert(c[u]);
    for (auto v : g[u]) {
        if (v != f && sz[v] > mxw) {
            bs = v;
            mxw = sz[v];
        }
    }
    for (auto v : g[u]) {
        if (v == f) continue;
        s = dfs(v,u,g);
        if (s.size() > cur.size()) swap(s,cur);
        cur.insert(s.begin(),s.end());
    }
    ans[u] = (cur.size());
    return cur;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    for (int i = 1; i <= n; ++i) cin>>c[i];
    vector<vector<int> > g(n+1);
    for (int i = 1; i < n; ++i) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    getsz(1,0,g);
    dfs(1,0,g);
    for (int i = 1; i <= n; ++i) {
        if (i != 1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
