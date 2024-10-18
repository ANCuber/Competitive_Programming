#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int ans[100005];

struct MON{
    int l, r, k, id;
};

struct SEG{
    vector<int> a, tg;
    void init(int _n) {
        a.assign(_n<<2,0);
        tg.assign(_n<<2,0);
    }
    void push(int p, int c) {
        if (tg[p]) {
            a[p] += tg[p];
            if (c) {
                tg[p<<1] += tg[p];
                tg[p<<1|1] += tg[p];
            }
            tg[p] = 0;
        }
    }
    void add(int l, int r, int p, int ql, int qr, int v) {
        push(p,r-l);
        if (ql <= l && r <= qr) {
            tg[p] += v;
            return;
        }
        int m = (l+r)>>1;
        if (qr <= m) add(l,m,p<<1,ql,qr,v);
        else if (ql > m) add(m+1,r,p<<1|1,ql,qr,v);
        else {
            add(l,m,p<<1,ql,qr,v);
            add(m+1,r,p<<1|1,ql,qr,v);
        }
        a[p] = max(a[p<<1]+tg[p<<1],a[p<<1|1]+tg[p<<1|1]);
    }
    int qmx(int l, int r, int p, int ql, int qr) {
        push(p,r-l);
        if (ql <= l && r <= qr) return a[p];
        int m = (l+r)>>1;
        if (qr <= m) return qmx(l,m,p<<1,ql,qr);
        else if (ql > m) return qmx(m+1,r,p<<1|1,ql,qr);
        else return max(qmx(l,m,p<<1,ql,qr),qmx(m+1,r,p<<1|1,ql,qr));
    }
} seg;

int m, n, q;

void slv(vector<MON> &qry,vector<MON> &mon, int l, int r) {
    if (l == r) {
        for (auto [al,ar,k,id] : mon) {
            ans[id] = l;
        }
        return;
    }
    int mid = (l+r)/2;
    vector<MON> ml, mr, ql, qr;
    for (int i = 0; i < qry.size(); ++i) {
        if (qry[i].id > mid) {
            qr.pb(qry[i]);
            continue;
        }
        seg.add(1,m,1,qry[i].l,qry[i].r,qry[i].k);
        ql.pb(qry[i]);
    }
    for (int i = 0; i < mon.size(); ++i) {
        int mx = seg.qmx(1,m,1,mon[i].l,mon[i].r);
        if (mx < mon[i].k) mr.pb(mon[i]);
        else ml.pb(mon[i]);
    }
    slv(qr,mr,mid+1,r);
    for (int i = 0; i < ql.size(); ++i) {
        seg.add(1,m,1,ql[i].l,ql[i].r,-ql[i].k);
    }
    slv(ql,ml,l,mid);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>m>>n>>q;
    vector<MON> mon(n);
    vector<MON> qry(q);
    for (int i = 0; i < n; ++i) {
        cin>>mon[i].l>>mon[i].r>>mon[i].k;
        mon[i].id = i;
    }
    for (int i = 0; i < q; ++i) {
        cin>>qry[i].l>>qry[i].r>>qry[i].k;
        qry[i].id = i;
    }
    seg.init(m);
    slv(qry,mon,0,q);
    for (int i = 0; i < n; ++i) {
        if (i) cout<<' ';
        if (ans[i]+1 <= q) cout<<ans[i]+1;
        else cout<<-1;
    }
    cout<<endl;
    return 0;
}
