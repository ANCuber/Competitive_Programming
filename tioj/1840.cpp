#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define int long long

struct BIT{
    vector<int> a;
    int sz = 0;
    void init(int _n) { 
        sz = _n;
        a.assign(_n+5,0); 
    }
    void add(int p, int v) {
        while(p <= sz) {
            a[p] += v;
            p += p&-p;
        }
    }
    int sum(int p) {
        int ret = 0;
        while(p) {
            ret += a[p];
            p -= p&-p;
        }
        return ret;
    }
} bit;

struct Query{ int cmd, l, r, k, id; };

vector<int> ans(10005,1LL<<31);
vector<int> arr(50005);

void slv(int l, int r, vector<Query> &q) {
    if (l == r || q.empty()) {
        for (auto[cmd,ql,qr,k,id] : q) if(cmd) ans[id] = l;
        return;
    }
    int mid = (l+r)>>1;
    vector<Query> q1, q2;
    for (auto[cmd,ql,qr,k,id] : q) {
        if (cmd) {
            if (k <= bit.sum(qr)-bit.sum(ql-1)) q1.pb({cmd,ql,qr,k,id});
            else q2.pb({cmd,ql,qr,k-bit.sum(qr)+bit.sum(ql-1),id});
        } else {
            if (qr <= mid) {
                bit.add(ql,k);
                q1.pb({cmd,ql,qr,k,id});
            } else {
                q2.pb({cmd,ql,qr,k,id});
            }
        }
    }
    for (auto[cmd,ql,qr,k,id] : q1) if (!cmd) bit.add(ql,-k);
    slv(l,mid,q1), slv(mid+1,r,q2);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, qq; 
    cin>>t;
    vector<Query> q;
    while(t--) {
        cin>>n>>qq;
        q.clear();
        bit.init(n);
        
        for (int i = 1; i <= n; ++i) {
            cin>>arr[i];
            q.pb({0,i,arr[i],1,0});
        }
        int cmd, l, r, k;
        for (int i = 1; i <= qq; ++i) {
            cin>>cmd>>l>>r;
            if (cmd == 1) {
                cin>>k;
                q.pb({1,l,r,k,i});
            } else if (cmd == 2) {
                q.pb({0,l,arr[l],-1,0});
                q.pb({0,l,r,1,0});
                arr[l] = r;
            } else {
                ans[i] = 7122;
            }
        }
        slv(-(1LL<<31),(1LL<<31),q);
        for (auto& i : ans) {
            if (i < (1LL<<31)) {
                cout<<i<<endl;
                i = (1LL<<31);
            }
        }
    }
    return 0;
}

