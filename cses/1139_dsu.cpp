#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<vector<int> > g;
vector<int> bs, in, out, c, nd;
vector<int> col, ans;
int dfn = 0, sum = 0;

int dfs(int u, int f) {
    in[u] = ++dfn;
    nd[dfn] = u;
    int mx = 0, id = 0, sub = 0;
    for (auto v : g[u]) {
        if (v != f) {
            int cur = dfs(v,u);
            if (cur > mx) {
                mx = cur;
                id = v;
            }
            sub += cur;
        }
    }
    out[u] = dfn;
    bs[u] = id;
    return sub+1;
}

void inline upd(int c) {
    col[c]++;
    if (col[c] == 1) sum++;
}

void slv(int u, int f, int kp) {
    for (auto v : g[u]) {
        if (v != f && v != bs[u]) {
            slv(v,u,0);
        }
    }
    if (!bs[u]) slv(bs[u],u,1);
    for (auto v : g[u]) {
        if (v != f && v != bs[u]) {
            for (int i = in[v]; i <= out[v]; ++i) {
                upd(c[nd[i]]);
            }
        }
    }
    upd(c[u]);
    ans[u] = sum;
    if (!kp) {
        sum = 0;
        for (int i = in[u]; i <= out[u]; ++i) {
            col[c[nd[i]]]--;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    c.resize(n+1);
    set<int> s; map<int,int> mp;
    for (int i = 1; i <= n; ++i) {
        cin>>c[i];
        s.insert(c[i]);
    }
    int cnt = 0;
    for (auto i : s) mp[i] = ++cnt;
    for (int i = 1; i <= n; ++i) c[i] = mp[c[i]];
    
    g.resize(n+1), bs.assign(n+1,0), in.assign(n+1,0), out.assign(n+1,0);
    nd.assign(n+1,0), col.assign(cnt+1,0), ans.assign(n+1,0);
    for (int i = 1; i < n; ++i) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,0);
    slv(1,0,1);
    for (int i = 1; i <= n; ++i) {
        if (i != 1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
