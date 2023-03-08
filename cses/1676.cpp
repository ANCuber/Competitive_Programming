#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct DSU{
    vector<int> a, sz;
    void init(int _n) {
        a.resize(_n+5);
        sz.assign(_n+5,1);
        for (int i = 1; i <= _n; ++i) a[i] = i;
    }
    int find(int p) {
        if (p == a[p]) return p;
        return a[p] = find(a[p]);
    }
    
} dsu;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    dsu.init(n);
    int mx = 1;
    while(m--) {
        int u, v; cin>>u>>v;
        int i = dsu.find(u), j = dsu.find(v);
        if (i != j) {
            dsu.a[i] = j;
            n--;
            dsu.sz[j] += dsu.sz[i];
            mx = max(dsu.sz[j],mx);
        }
        cout<<n<<' '<<mx<<endl;
    }
    return 0;
}
