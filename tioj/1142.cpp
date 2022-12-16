#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<int> tm(n+1), in(n+1,0), out(n+1,0), mx(n+1,0), cnt(n+1,0);
    vector<vector<int> > g(n+1);
    for (int i = 1; i <= n; ++i) cin>>tm[i];
    while(m--) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
        out[a]++, in[b]++;
    }
    queue < pii > q;
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            q.push({i,0});
        }
    }
    int amx = 0, ans = 0;
    while(!q.empty()) {
        int cur = q.front().first;
        int cst = q.front().second;
        q.pop();
        
        if (!out[cur]) {
            if (cst+tm[cur] > amx) {
                ans = cnt[cur]+1;
                amx = cst+tm[cur];
            } else if (cst+tm[cur] == amx) {
                ans = max(ans,cnt[cur]+1);
            }
        }
    
        for (auto v : g[cur]) {

            if (tm[cur]+cst == mx[v]) {
                cnt[v] += cnt[cur]+1;
            } else if (tm[cur]+cst > mx[v]) {
                cnt[v] = cnt[cur]+1;
                mx[v] = tm[cur]+cst;
            }
            
            if (--in[v] == 0) q.push({v,mx[v]});
        }
    }
    cout<<ans<<endl;
    return 0;
}
