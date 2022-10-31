#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

ll n, m, u, v;
ll c;

struct node{
    ll w, a, b;
    bool operator>(const node& y) const {
        return w > y.w;
    }
};

signed main() {
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%lld%lld",&n,&m);
    vector<vector<pair<ll,ll> > > g(n+1);
    vector<ll> d(n+1,2e18);
    vector<ll> vis(n+1,0);
    d[0] = d[1] = 0;
    while(m--) {
        scanf("%lld%lld%lld",&u,&v,&c);
        g[u].pb({v,c});
    }
    p_q <node,vector<node>,greater<node> > pq;
    pq.push({0,0,1});
    while(!pq.empty()) {
        node cur = pq.top();
        pq.pop();
        if (vis[cur.b]) continue;
        vis[cur.b] = 1;
        for (auto [i,c] : g[cur.b]) {
            if (d[i] > d[cur.b]+c) {
                d[i] = d[cur.b]+c;
                pq.push({d[i],cur.b,i});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i!=1) printf(" ");
        printf("%lld",d[i]);
    }
    printf("\n");
    return 0;
}
