#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m, flag = 0;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;   
    vector<vector< pii > > g(n+1);
    for (int i = 1; i <= n; ++i) g[0].pb({i,0});
    while(m--) {
        int u, v, w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
    }
    vector<int> d(n+1,1e18), pre(n+1,0);
    d[0] = 0;
    int cur;
    for (int i = 0; i <= n; ++i) {
        cur = 0;
        for (int u = 0; u <= n; ++u) {
            for (auto [v,w] : g[u]) {
                if (d[v] > d[u]+w) {
                    d[v] = d[u]+w;
                    pre[v] = u;
                    cur = v;
                }
            }
        }
    }
    if (cur) {
        cout<<"YES"<<endl; 
        for (int i = 0; i <= n; ++i) cur = pre[cur];
        vector<int> ans;
        int hd = cur;
        while(pre[cur] != hd) {
            ans.pb(cur);
            cur = pre[cur];
        }
        ans.pb(cur), ans.pb(pre[cur]);
        for (int i = ans.size()-1; i >= 0; --i) {
            cout<<ans[i];
            if (i) cout<<' ';
        }
        cout<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    return 0;
}
