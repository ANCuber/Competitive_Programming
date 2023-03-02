#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mod = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    vector<vector< pii > > g(n+1);
    while(m--) {
        int a, b, c;
        cin>>a>>b>>c;
        g[a].pb({b,c});
    }
    p_q < pii,vector< pii >,greater< pii > > pq;
    vector<int> d(n+1,1e18), cnt(n+1,0);
    d[1] = 0;
    cnt[1] = 1;
    pq.push({0,1});
    while(!pq.empty()) {
        
    }
    return 0;
}
