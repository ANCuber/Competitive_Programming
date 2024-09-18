#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Dij(int s, vector<int> &d, vector<vector<pii> > &g) {
    d[s] = 0;
    p_q <pii,vector<pii>,greater<pii> > pq;
    pq.push({d[s],s});
    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if(cur.first!=d[cur.second]) continue;
        for (auto [v,w] : g[cur.second]) {
            if (cur.first+w < d[v]) {
                d[v] = cur.first+w;
                pq.push({d[v],v});
            }
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin>>N>>M;    
    int S, T, L, K; cin>>S>>T>>L>>K;
    vector<vector<pii> > g(N+2);
    while(M--) {
        int u, v, w; cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    vector<int> ds(N+2,2e18), dt(N+2,2e18);
    Dij(S,ds,g), Dij(T,dt,g);
    if (ds[T] <= K) {
        cout<<N*(N-1)/2<<endl;
        return 0;
    }
    sort(dt.begin()+1,dt.begin()+N+1);
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (ds[i] > K-L) continue;
        int l = 1, r = N+1;
        while(r-l > 1) {
            int mid = (l+r)/2;
            if (ds[i]+dt[mid] <= K-L) l = mid;
            else r = mid;
        }
        ans += l;
    }
    cout<<ans<<endl;
    return 0;
}
