#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct DSU{
    vector<int> bs;
    vector<int> p;
    vector<int> sz;
    void init(int _n) {
        bs.resize(_n+5);
        p.assign(_n+5,0);
        sz.assign(_n+5,1);
        for (int i = 1; i <= _n; ++i) bs[i] = i;
    }
    int find(int x) {
        if (x == bs[x]) return x;
        return find(bs[x]);
    }
    void add(int u, int v, int t) {
        int fu = find(u), fv = find(v);
        if (sz[fu] > sz[fv]) {
            bs[fv] = fu;
            p[fv] = t;
            sz[fu] += sz[fv];
        } else {
            bs[fu] = fv;
            p[fu] = t;
            sz[fv] += sz[fu];
        }
    }
} dsu;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    dsu.init(n);
    vector<int> x(500005);
    for (int i = 1; i <= q; ++i) {
        int e; cin>>e;
        if (e == 1) {
            int u, v; cin>>u>>v;
            dsu.add(u,v,i);
        } else {
            int k; cin>>k;
            int cur, flg = 0, tmp;
            for (int j = 0; j < k; ++j) {
                cin>>x[j];
                if (!j) cur = dsu.find(x[j]);
                else {
                    tmp = dsu.find(x[j]);
                    if (cur != tmp) flg = 1;
                }
            }
            if (flg) {
                cout<<-1<<endl;
                continue;
            }
            
            unordered_map<int,int> mp;
            for (int j = 0; j < k; ++j) {
                int cur = x[j], tar = dsu.find(x[j]);
                while(cur != tar) {
                    mp[dsu.p[cur]]++;
                    cur = dsu.bs[cur];
                }
            }
            int ans = 0;
            for (auto [a,b] : mp) {
                if (b == k) continue;
                ans = max(ans,a);
            }
            cout<<ans<<endl;
        }
    }
    
    return 0;
}
