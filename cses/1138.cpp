#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

#define int ll

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        sz = _n;
        a.assign(_n+5,0);
    }
    void upd(int p, int v) {
        while(p <= sz) {
            a[p] += v;
            p += p&-p;
        }
    }
    int sum(int p) {
        int ret = 0;
        while(p > 0) {
            ret += a[p];
            p -= p&-p;
        }
        return ret;
    }
} bit;

int tim = 0;

void dfs(int cur, int fa, vector<int> &st, vector<int> &ed, vector<vector<int> > &g) {
    st[cur] = ++tim;
    for (auto v : g[cur]) {
        if (v != fa) dfs(v,cur,st,ed,g);
    }
    ed[cur] = ++tim;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    vector<int> v(n+1,0);
    for (int i = 1; i <= n; ++i) cin>>v[i];
    int a, b;
    vector<vector<int> > g(n+1);
    for (int i = 1; i < n; ++i) {
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> st(n+1,0), ed(n+1,0);
    dfs(1,0,st,ed,g);
    bit.init(tim);
    for (int i = 1; i <= n; ++i) {
        bit.upd(st[i],v[i]);
        bit.upd(ed[i],-v[i]);
    }
    
    int cmd, s, x;
    while(q--) {
        cin>>cmd>>s;
        if (cmd == 1) {
            cin>>x;
            bit.upd(st[s],x-v[s]);
            bit.upd(ed[s],v[s]-x);
            v[s] = x;
        } else {
            cout<<bit.sum(st[s])<<endl;
        }
    }
    return 0;
}

