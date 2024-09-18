#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    vector<vector<int> > dp(n+1,vector<int>(n+1,1e18)), base, mn;
    mn = base = dp;
    while(m--) {
        int a, b, t;
        cin>>a>>b>>t;
        dp[a][b] = min(t,dp[a][b]);
    }
    int k, q; cin>>k>>q;
    while(k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int mini = 1e18;
                for (int l = 1; l <= n; ++l) {
                    mini = min(mini,dp[i][l]+dp[l][j]);
                }
                base[i][j] = mini;
                mn[i][j] = min(base[i][j],mn[i][j]);
            }
        }
        dp = base;
        k--;
    }
    
    while(q--) {
        int c, d; cin>>c>>d;
        cout<<mn[c][d]<<endl;
    }
    return 0;
}
