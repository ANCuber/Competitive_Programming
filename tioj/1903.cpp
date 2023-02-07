#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

struct DSU{
    vector<int> bs, sz;
    vector< pii > hsp;
    vector<int> num;
    int cnt;
    void init(int _n) {
        bs.assign(_n+5,0);
        sz.assign(_n+5,1);
        num.clear(), hsp.clear();
        cnt = _n;
        for (int i = 1; i <= _n; ++i) bs[i] = i;
    }
    int find(int p) {
        return (p == bs[p])?p:find(bs[p]);
    }
    void add(int u, int v) {
        int a = find(u), b = find(v);
        if (a == b) {
            hsp.pb({0,0});
            num.pb(0);
            return;
        }
        if (sz[a] < sz[b]) swap(a,b);
        bs[b] = a;
        num.pb(b);
        hsp.pb({a,sz[a]});
        sz[a] += sz[b];
        cnt--;
    }
    void undo() {
        if (num.back()) {
            sz[hsp.back().first] = hsp.back().second;
            bs[num.back()] = num.back();
            cnt++;
        }
        num.pop_back();
        hsp.pop_back();
    }
} dsu;

struct SEG{
    vector<vector< pii > > a;
    void init(int _n) {
        a.assign(_n<<2,vector< pii >());
    }
    void mdf(int l, int r, int p, int ql, int qr, int u, int v) {
        if (ql <= l && r <= qr) {
            a[p].pb({u,v});
            return;
        }
        if (ql > mid) mdf(mid+1,r,p<<1|1,ql,qr,u,v);
        else if (qr <= mid) mdf(l,mid,p<<1,ql,qr,u,v);
        else {
            mdf(mid+1,r,p<<1|1,ql,qr,u,v);
            mdf(l,mid,p<<1,ql,qr,u,v);
        }
    }
    void dfs(int l, int r, int p) {
        for (auto [u,v] : a[p]) dsu.add(u,v);
        if (l == r) {
            if (l) cout<<dsu.cnt<<endl;
            for (int i = 0; i < a[p].size(); ++i) dsu.undo();
            return;
        }
        dfs(l,mid,p<<1);
        dfs(mid+1,r,p<<1|1);
        for (int i = 0; i < a[p].size(); ++i) dsu.undo();
    }
} seg;

void slv() {
    int n, m, q;
    cin>>n>>m>>q;
    dsu.init(n);
    int a, b;
    map< pii,pii > mp;
    while(m--) {
        cin>>a>>b;
        a++, b++;
        if (a > b) swap(a,b);
        mp[{a,b}].second++;
    }
    char c;
    seg.init(q);
    for (int i = 1; i <= q; ++i) {
        cin>>c>>a>>b;
        a++, b++;
        if (a > b) swap(a,b);
        if (c == 'N') {
            if (!mp.count({a,b}) || !mp[{a,b}].second) mp[{a,b}].first = i;
            mp[{a,b}].second++;
        } else {
            if (--mp[{a,b}].second == 0) {
                seg.mdf(0,q,1,mp[{a,b}].first,i-1,a,b);
            }
        }
    }
    for (auto it : mp) {
        if (!it.second.second) continue;
        seg.mdf(0,q,1,it.second.first,q,it.first.first,it.first.second);
    }
    seg.dfs(0,q,1);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        slv();
    }
    return 0;
}
