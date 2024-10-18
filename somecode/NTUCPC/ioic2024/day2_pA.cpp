#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

struct SEG{
    struct Node{
        ll sum, sqs; 
    };
    vector<Node> a; 
    void init(int _n) {
        a.assign(_n<<2,{0,0});
    }
    void mdf(int l, int r, int p, int t, ll v) {
        if (l == r) {
            a[p].sum = v;
            a[p].sqs = v*v;
            return;
        }
        if (t <= mid) mdf(l,mid,p<<1,t,v);
        else mdf(mid+1,r,p<<1|1,t,v);
        a[p].sum = a[p<<1].sum+a[p<<1|1].sum;
        a[p].sqs = a[p<<1].sqs+a[p<<1|1].sqs;
    }
    pair<ll,ll> query(int l, int r, int p, int ql, int qr) {
        if (ql <= l && r <= qr) return {a[p].sum,a[p].sqs};
        if (qr <= mid) return query(l,mid,p<<1,ql,qr);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr);
        else {
            pair<ll,ll> c1 = query(l,mid,p<<1,ql,qr), c2 = query(mid+1,r,p<<1|1,ql,qr);
            return {c1.first+c2.first,c1.second+c2.second};
        }
    }
} seg; 

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin>>N;    
    seg.init(N);
    for (int i = 1; i <= N; ++i) {
        ll a; cin>>a;
        seg.mdf(1,N,1,i,a);
        //cout<<seg.query(1,N,1,i,i).first<<' '<<seg.query(1,N,1,i,i).second<<endl;
    }
    //for (int i = 1; i <= N; ++i) cout<<seg.query(1,N,1,i,i).first<<' '<<seg.query(1,N,1,i,i).second<<endl;
    int Q; cin>>Q;
    for (int i = 1; i <= Q; ++i) {
        int cmd, l, r; cin>>cmd>>l>>r;
        if (cmd == 1) {
            seg.mdf(1,N,1,l,r);
        } else {
            pair<ll,ll> cur = seg.query(1,N,1,l,r);
            cout<<(cur.first*cur.first-cur.second)/2<<endl;
        }
    }
    return 0;
}
