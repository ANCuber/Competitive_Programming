#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)
#define int ll

int mpk;
vector<vector< pii > > g;

struct SEG{
    int sz, t;
    void setedge(int l, int r, int p) {
        if (l == r) {
            if (t) g[p+mpk].pb({(p>>1)+mpk,0});
            else {
                g[p].pb({p+mpk,0});
                g[p+mpk].pb({p,0});
            }
            return;
        }
        setedge(l,mid,p<<1);
        setedge(mid+1,r,p<<1|1);
        if (!t) {
            g[p].pb({p<<1,0});
            g[p].pb({p<<1|1,0});
        } else if (p != 1) {
            g[p+mpk].pb({(p>>1)+mpk,0});
        }
    }
    void init(int _n,int _t) {
        sz = _n;
        t = _t;
        setedge(1,_n,1);
    }
    int find_node(int tar) {
        int l = 1, r = sz, p = 1;
        while(l != r) {
            p <<= 1;
            if (tar <= mid) r = mid;
            else {
                l = mid+1;
                p++;
            }
        }
        return t?(p+mpk):p;
    }
    void add(int l, int r, int p, int v, int ql, int qr, int w) {
        if (ql <= l && r <= qr) {
            if (!t) g[find_node(v)].pb({p,w});
            else g[p+mpk].pb({find_node(v),w});
            return;
        }
        if (qr <= mid) add(l,mid,p<<1,v,ql,qr,w);
        else if (ql > mid) add(mid+1,r,p<<1|1,v,ql,qr,w);
        else {
            add(l,mid,p<<1,v,ql,qr,w);
            add(mid+1,r,p<<1|1,v,ql,qr,w);
        }
    }
} seg[2];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, s;
    cin>>n>>q>>s;
    mpk = 4*n;
    g.resize(2*mpk+5);
    seg[0].init(n,0), seg[1].init(n,1);
    while(q--) {
        int c, v, l, r, w;
        cin>>c>>v;
        if (c == 1) {
            cin>>l>>w;
            seg[0].add(1,n,1,v,l,l,w);
        } else if (c == 2) {
            cin>>l>>r>>w;
            seg[0].add(1,n,1,v,l,r,w);
        } else {
            cin>>l>>r>>w;
            seg[1].add(1,n,1,v,l,r,w);
        }
    }
    vector<int> dis(2*mpk+5,2e18), vis(2*mpk+5,0);
    dis[seg[0].find_node(s)] = 0;
    priority_queue< pii,vector< pii >,greater< pii > > pq;
    pq.push({0,seg[0].find_node(s)});
    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if (vis[cur.second]) continue;
        vis[cur.second] = 1;
        for (auto [u,w] : g[cur.second]) {
            if (dis[u] >= dis[cur.second]+w) {
                dis[u] = dis[cur.second]+w;
                pq.push({dis[u],u});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i != 1) cout<<' ';
        int ans = min(dis[seg[0].find_node(i)],dis[seg[1].find_node(i)]);
        if (ans >= 2e18) cout<<-1;
        else cout<<ans;
    }
    cout<<endl;
    return 0;
}
