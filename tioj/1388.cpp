#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        int a[n+5] = {0};
        for (int i = 0; i < n; ++i) cin>>a[i];
        vector<vector<int> > dp(n,vector<int>(n,-1e9));
        
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i+l-1 < n; ++i) {
                int j = i+l-1;
                if (l == 1) {
                    dp[i][j] = a[i];
                    continue;
                }
                for (int k = i; k < j; ++k) {
                    if (l&1) {
                        dp[i][j] = max(dp[i][j],dp[i][k]*dp[k+1][j]);
                    } else {
                        dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
                    }
                }
            }
        }
        cout<<dp[0][n-1]<<endl;
    }
    return 0;
}

