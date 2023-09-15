#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;    
    while(cin>>n>>k) {
        int pre = 0; 
        vector<vector<int> > dp(22,vector<int>(22,0));
        dp[0][0] = pre = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = pre;
            for (int j = 1; j < k; ++j) {
                dp[i][j] = dp[i-1][j-1];
                pre += dp[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < k; ++i) ans += dp[n][i];
        cout<<ans<<endl;
    }
    return 0;
}
