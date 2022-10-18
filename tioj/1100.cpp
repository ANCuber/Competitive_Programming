#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n && n) {
        vector<int> p(n+1), l(n+1), r(n+1);
        //vector<vector<int> > dp(n+1,vector<int>(n+1,0));
        int dp[n+1][n+1] = {{0}};
        for (int i = 1; i <= n; ++i) cin>>l[i]>>r[i]>>p[i];
        for (int i = 1; i <= n; ++i) {
            l[i]--;
            for (int j = 1; j <= n; ++j) {
                if (j > i) {
                    dp[i][j] = 1e9;
                    continue;
                }
                if (i == 1) dp[i][j] = (l[i]+p[i] <= r[i])?(l[i]+p[i]):(1e9);
                else {
                    dp[i][j] = dp[i-1][j];
                    if (max(dp[i-1][j-1],l[i])+p[i] <= r[i]) {
                        dp[i][j] = min(max(dp[i-1][j-1],l[i])+p[i],dp[i][j]);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) if(dp[n][i] <= r[n]) ans = i;
        cout<<ans<<endl;
    }
    return 0;
}
