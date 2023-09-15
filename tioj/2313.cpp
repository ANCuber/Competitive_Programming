#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb emplace_back

vector<int> pm;
bitset<210000> vis(0);
bitset<31627> isp;
int n, S;

const int MAXPN = sqrt(1e9)+5;

inline void Sieve(){
    isp.set();
    for (ll i = 2; i <= MAXPN; ++i) {
        if (!isp[i]) continue;
        pm.pb(i);
        for (ll j = i+i; j <= MAXPN; j += i) isp[j] = 0;
    }
}

inline void Dij(int s, vector<ll> &dis, vector<vector<pair<int,ll> > > &g) {
    dis[s] = 0;
    p_q <pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0ll,0});
    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        for (auto [v,w] : g[cur]) {
            if (dis[cur]+w < dis[v]) {
                dis[v] = dis[cur]+w;
                pq.push({dis[v],v});
            }
        }
    }
}

signed main() {
    scanf("%d",&n);
    int a[n+2];
    Sieve();
    int cnt = 3401;
    map<int,int> mp;
    vector<vector<pair<int,ll> > > g(210000);
    for (int i = 1; i <= n; ++i) scanf("%d",&a[i]);
    for (int i = 1; i <= n; ++i) {
        ll b;
        scanf("%lld",&b);
        for (int j = 0; j < 3401; ++j) {
            if (a[i]%pm[j]) continue;
            g[i].pb(n+j+1,b);
            g[n+j+1].pb(i,0);
            while(!(a[i]%pm[j])) a[i] /= pm[j];
        }
        if (a[i] != 1) {
            if (!mp.count(a[i])) mp[a[i]] = ++cnt;
            g[i].pb(n+mp[a[i]],b);
            g[n+mp[a[i]]].pb(i,0);
        }
    }
    scanf("%d",&S);
    for (int i = 0; i < 3401; ++i) {
        if (S%pm[i]) continue;
        g[0].pb(n+i+1,0);
        while(!(S%pm[i])) S /= pm[i];
    }
    if (S != 1) {
        if (!mp.count(S)) mp[S] = ++cnt;
        g[0].pb(n+mp[S],0);
    }

    vector<ll> dis(210000,2e18);
    Dij(0,dis,g);
    for (int i = 1; i <= n; ++i) {
        if (i-1) printf(" ");
        if (dis[i] < 1e18) printf("%lld",dis[i]);
        else printf("-1");
    }
    printf("\n");
    return 0;
}

