#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
 
struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        a.assign(_n+5,0);
        sz = _n;
    }
    void mdf(int p, int v) {
        while(p <= sz) {
            a[p] += v;
            p += p&-p;
        }
    }
    int val(int p) {
        int ret = 0;
        while(p) {
            ret += a[p];
            p -= p&-p;
        }
        return ret;
    }
} bit;

struct Query{
    int l, r, id;
    bool operator<(Query b) {
        return l < b.l;
    }
};
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q; cin>>N>>Q;    
    bit.init(N);
    int cnt = 0;
    vector<vector<int> > pos(N+1);
    vector<int> a(N+1);
    vector<Query> q(Q);
    set<int> s;
    map<int,int> mp;
    
    for (int i = 1; i <= N; ++i) {
        cin>>a[i];
        s.insert(a[i]);
    }
    for (auto i : s) mp[i] = ++cnt;
    for (int i = 1; i <= N; ++i) {
        a[i] = mp[a[i]];
        pos[a[i]].pb(i);
        if (pos[a[i]].size() == 1) bit.mdf(i,1);
    }
    
    for (int i = 0; i < Q; ++i) {
        cin>>q[i].l>>q[i].r;
        q[i].id = i;
    }
    sort(q.begin(),q.end());
    
    vector<int> ans(Q);
    int id = 1;
    for (auto [l,r,x] : q) {
        while(id < l) {
            auto iter = lower_bound(pos[a[id]].begin(),pos[a[id]].end(),id);
            if (*iter != pos[a[id]].back()) {
                bit.mdf(id,-1);
                iter++;
                bit.mdf(*iter,1);
            }
            id++;
        }
        ans[x] = bit.val(r)-bit.val(l-1);
    }
    for (int i = 0; i < Q; ++i) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
