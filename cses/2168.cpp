#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Rng{
    int l, r, id;
};

bool cmp1(Rng a, Rng b) {
    if (a.l == b.l) return a.r > b.r;
    return a.l < b.l;
}

bool cmp2(Rng a, Rng b) {
    if (a.l == b.l) return a.r < b.r;
    return a.l > b.l;
}

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        sz = _n;
        a.assign(_n+5,0);
    }
    void add(int p) {
        while(p <= sz) {
            a[p]++;
            p += p&-p;
        }
    }
    int qry(int p) {
        int ret = 0;
        while(p > 0) {
            ret += a[p];
            p -= p&-p;
        }
        return ret;
    }
} bit;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<Rng> a(n); 
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin>>a[i].l>>a[i].r;
        s.insert(a[i].l), s.insert(a[i].r);
        a[i].id = i;
    }
    int c = 0;
    map<int,int> mp;
    for (auto i : s) mp[i] = ++c;
    for (auto & [l,r,id]:a) {
        l = mp[l];
        r = mp[r];
    }
    sort(a.begin(),a.end(),cmp1);
    bit.init(c);
    vector<int> ans1(n,0), ans2(n,0);
    for (auto & [l,r,id]:a) {
        if (bit.qry(c)-bit.qry(r-1)>0) ans2[id] = 1;
        bit.add(r);
    }
    sort(a.begin(),a.end(),cmp2);
    bit.init(c);
    for (auto & [l,r,id]:a) {
        if (bit.qry(r)>0) ans1[id] = 1;
        bit.add(r);
    }
    for (int i = 0; i < n; ++i) {
        if (i) cout<<' ';
        cout<<ans1[i];
    }
    cout<<endl;
    for (int i = 0; i < n; ++i) {
        if (i) cout<<' ';
        cout<<ans2[i];
    }
    cout<<endl;
    return 0;
}
