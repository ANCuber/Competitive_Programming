#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

inline int Hash(int u, int v) {
    return (u+v*100000)^8191-(v+u*10000)&4095;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    vector<int> w(n+1,0);
    int c, u, v, k;
    while(m--) {
        cin>>c;
        if (!c) {
            cin>>u>>v;
            if (u > v) swap(u,v);
            w[u] += Hash(u,v);
            w[v] -= Hash(u,v);
        } else if (c == 1) {
            cin>>u>>v;
            if (u > v) swap(u,v);
            w[u] -= Hash(u,v);
            w[v] += Hash(u,v);
        } else {
            cin>>k;
            int sum = 0;
            for (int i = 0; i < k; ++i) {
                int a; cin>>a;
                sum += w[a];
            }
            if (!sum) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
