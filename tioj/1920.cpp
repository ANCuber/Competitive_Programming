#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int maxn = 300005; 

vector<int> arr(10005,0);
vector<int> ans(1000005,0);

struct QUERY{
    int l, r, v, id;
    bool operator<(QUERY b) {
        return r < b.r;
    }
};

struct TRIE{
    vector<vector<int> > t;
    vector<int> nr;
    int cnt = 0;
    void init() {
        t.assign(maxn,vector<int>(2,0));
        nr.assign(maxn,0);
    }
    void upd(int p, int x, int d, int l) {
        nr[p] = l;
        int c = (x>>d)&1;
        if (!t[p][c]) t[p][c] = ++cnt;
        if (d >= 0) upd(t[p][c],x,d-1,l);
    }
    int query(int p, int x, int d, int l) {
        int c = ((x>>d)&1)^1;
        if (!t[p][c] || nr[t[p][c]] < l) c ^= 1;
        if (d == 0) return x^(c<<d);
        return (c<<d)^query(t[p][c],x,d-1,l);
    }
} trie;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, Q; cin>>n>>Q;
    vector<QUERY> q(Q+1);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        arr[i] ^= arr[i-1];
    }
    int l, r, v;
    for (int i = 1; i <= Q; ++i) {
        cin>>l>>r>>v;
        q[i] = {l,r,v,i};
    }
    sort(q.begin()+1,q.end());
    int p = 1;
    trie.init();
    for (int i = 0; i <= n; ++i) {
        while(p <= Q && q[p].r == i) {
            ans[q[p].id] = trie.query(0,q[p].v^arr[i],30,q[p].l);
            p++;
        }
        trie.upd(0,arr[i],30,i);
    }
    for (int i = 1; i <= Q; ++i) cout<<ans[i]<<endl;
    return 0;
}
