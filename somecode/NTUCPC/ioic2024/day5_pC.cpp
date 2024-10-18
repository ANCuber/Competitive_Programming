#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const ll M = 1e9+7;

void Dij(int s, int t, vector<vector<pair<int,ll> > > &g, int ban, vector<ll> &dis, vector<ll> &cnt) {
    if (ban == s || ban == t) return;
    //p_q <pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
    p_q<pair<ll,int> > pq;
    //queue<pair<ll,int> > pq;
    dis[s] = 0, cnt[s] = 1;
    pq.push({0,s});
    while(!pq.empty()) {
        pair<ll,int> cur = pq.top();
        //pair<ll,int> cur = pq.front();
        ll cw = cur.first;
        int u = cur.second;
        pq.pop();
        for (auto &[v,w] : g[u]) {
            if (ban == v) continue;
            if (cw+w == dis[v]) {
                cnt[v] = (cnt[v]+cnt[u])%M;
                //pq.push({dis[v],v});
                //cout<<ban<<' '<<u<<' '<<v<<endl;
            } else if (cw+w < dis[v]) {
                dis[v] = cw+w;
                cnt[v] = cnt[u];
                pq.push({dis[v],v});
            }
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin>>N>>M;    
    if (N > 1000) return 0;
    vector<vector<pair<int,ll> > > g(N+2);
    vector<ll> dis(N+2), cnt(N+2);
    while(M--) {
        int u, v, w; cin>>u>>v>>w;
        g[u].pb({v,-w});
    }
    for (int i = 1; i <= N; ++i) {
        fill(dis.begin(),dis.end(),1e9);
        fill(cnt.begin(),cnt.end(),0);
        Dij(1,N,g,i,dis,cnt);
        //for (int j = 1; j <= N; ++j) cout<<cnt[j]<<' '; cout<<endl;
        if (dis[N] >= 0) cout<<-1<<endl;
        else cout<<-1*dis[N]<<' '<<cnt[N]<<endl;
    }
    return 0;
}
