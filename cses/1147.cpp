#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+2,vector<int>(m+2,-1));
    for (int i = 1; i <= m; ++i) g[0][i] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char x; cin>>x;
            if (x == '.') {
                g[i][j] = 1;
                g[i][j] += g[i-1][j];
            } else {
                g[i][j] = 0;
            }
        }
    }
    vector<int> tmp(m+2,0);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> stk, h;
        stk.pb(0);
        h.pb(-1);
        for (int j = 1; j <= m; ++j) {
            int id = lower_bound(h.begin(),h.end(),g[i][j])-h.begin()-1;
            tmp[j] = (j-stk[id]);
            while(!stk.empty() && g[i][stk.back()] > g[i][j]) {
                stk.pop_back();
                h.pop_back();
            }
            stk.pb(j);
            h.pb(g[i][j]);
        }
        stk.clear(), h.clear();
        stk.pb(m+1);
        h.pb(-1);
        for (int j = m; j > 0; --j) {
            int id = lower_bound(h.begin(),h.end(),g[i][j])-h.begin()-1;
            tmp[j] += (stk[id]-j-1);
            while(!stk.empty() && g[i][stk.back()] > g[i][j]) {
                stk.pop_back();
                h.pop_back();
            }
            stk.pb(j);
            h.pb(g[i][j]);
        }
        for (int j = 1; j <= m; ++j) {
            //cout<<i<<' '<<j<<':'<<tmp[j]<<' '<<g[i][j]<<endl;
            ans = max(ans,tmp[j]*g[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
