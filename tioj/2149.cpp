#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int maxn = 1000, maxx = 1024;
const int nd = 1000+1024*1000;

int n, m, s, t;
int a, b, x;
ll y;

inline int mp(int id, int xr) {
    return id+xr*maxn;
}

signed main() {
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%d%d%d%d",&n,&m,&s,&t);
    vector<vector<pair<int,ll> > > g(nd+5);
    while(m--) {
        scanf("%d%d%d%lld",&a,&b,&x,&y);
        for (int i = 0; i <= 1024; ++i) {
            g[mp(a,i)].pb({mp(b,i^x),y});
            g[mp(b,i)].pb({mp(a,i^x),y});
        }
    }
    p_q <pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
    bitset<1025005> vis(0);
    vector<ll> d(nd+5,1e18);
    d[s] = 0;
    pq.push({0,s});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v,w] : g[u]) {
            if (d[v] > d[u]+w) {
                d[v] = d[u]+w;
                pq.push({d[v],v});
            }
        }
    }
    if (d[t] == 1e18) d[t] = -1;
    printf("%lld\n",d[t]);
    return 0;
}
