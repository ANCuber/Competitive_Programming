#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        sz = _n;
        a.assign(_n+5,0);
    }
    void add(int p, int x) {
        while(p <= sz) {
            a[p] += x;
            p += p&-p;
        }
    }
    int query(int p) {
        int ret = 0;
        while(p) {
            ret += a[p];
            p -= p&-p;
        }
        return ret;
    }
} bit, subtr;

vector<int> num(200005), ord(200005), dep(200005), f(200005,0), wws(200005), sz(200005,1);
int cnt = 0;

int dfs1(int u, int d, vector<vector<int> > &tr) {
    int cws = 0, cmx = 0;
    dep[u] = d;
    for (auto v : tr[u]) {
        int tmp = dfs1(v,d+1,tr);
        if (tmp > cmx) {
            cws = v;
            cmx = tmp;
        }
        sz[u] += tmp;
    }
    wws[u] = cws;
    return sz[u];
}

void decp(int u, int tp,  vector<vector<int> > &tr) {
    num[u] = tp;//which group?
    ord[u] = ++cnt;//dfs order
    if (wws[u]) decp(wws[u],tp,tr);
    for (auto v : tr[u]) {
        if (v == wws[u]) continue;
        decp(v,v,tr);
    }
}

int LCA(int u, int v) {
    while(num[u] != num[v]) {
        if (dep[num[u]] > dep[num[v]]) swap(u,v);
        v = f[num[v]];
    }
    if (dep[u] > dep[v]) swap(u,v);
    return u;
}

int chain(int anc, int u) {
    int ret = 0;
    while(num[u] != num[anc]) {
        ret += bit.query(ord[u])-bit.query(ord[num[u]]-1);
        u = f[num[u]];
    }
    return ret+bit.query(ord[u])-bit.query(ord[anc]-1);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q; cin>>N>>Q;    
    bit.init(N), subtr.init(N);
    vector<vector<int> > tr(N+2);
    for (int i = 2; i <= N; ++i) {
        int F; cin>>F;
        tr[F].pb(i);
        f[i] = F;
    }
    dfs1(1,1,tr);
    decp(1,1,tr);
    while(Q--) {
        int cmd, u, v, c; cin>>cmd>>u;
        if (cmd == 1) {
            cin>>c;
            bit.add(ord[u],c);
            subtr.add(ord[u],c);
        } else if (cmd == 2) {
            cin>>v;
            int lca = LCA(u,v);
            //cout<<"LCA:"<<lca<<endl;
            //cout<<lca<<' '<<u<<':'<<lca<<' '<<v<<endl;
            //cout<<chain(lca,u)<<' '<<chain(lca,v)<<' '<<chain(lca,lca)<<endl;
            cout<<chain(lca,u)+chain(lca,v)-chain(lca,lca)<<endl;
        } else {
            cout<<subtr.query(ord[u]+sz[u]-1)-subtr.query(ord[u]-1)<<endl;
        }
    }
    
    return 0;
}
