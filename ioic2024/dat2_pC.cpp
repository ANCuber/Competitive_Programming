#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Edge{
    int x, y;
} e[100005];

struct DSU{
    vector<int> f;
    int tot;
    void init(int _n) {
        f.resize(_n+5);
        tot = _n;
        for (int i = 1; i <= _n; ++i) f[i] = i;
    }
    int ff(int p) {
        if (p == f[p]) return p;
        return f[p] = ff(f[p]);
    }
    void link(int u, int v) {
        int fu = ff(u), fv = ff(v);
        if (fu == fv) return;
        f[fu] = fv;
        tot--;
    }
} dsu;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M; cin>>N>>M;    
    for (int i = 1; i <= M; ++i) {
        int x, y; cin>>x>>y;
        e[i] = {x,y};
    }
    int Q, pa = 0; cin>>Q;
    while(Q--) {
        int a, b; cin>>a>>b;
        int l = (a-1+pa)%M+1, r = (b-1+pa)%M+1;
        if (r < l) swap(l,r);
        dsu.init(N);
        for (int i = l; i <= r; ++i) {
            dsu.link(e[i].x,e[i].y);
        }
        pa = dsu.tot;
        cout<<pa<<endl;
    }
    
    return 0;
}

