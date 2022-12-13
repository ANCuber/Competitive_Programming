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
    int n; cin>>n;    
    string s; cin>>s;
    int dp[2][2];
    s = "$"+s;
    dp[0][1] = (s[1] == '1');
    dp[1][1] = (s[1] == '0');
    for (int i = 2; i <= n; ++i) {
        if (s[i] == '0') {
            dp[0][i&1] = min(dp[0][i&1^1],dp[1][i&1^1]+1);
            dp[1][i&1] = min(dp[0][i&1^1]+1,dp[1][i&1^1]+1);
        } else {
            dp[0][i&1] = min(dp[0][i&1^1]+1,dp[1][i&1^1]+1);
            dp[1][i&1] = min(dp[1][i&1^1],dp[0][i&1^1]+1);
        }
    }
    cout<<dp[1][n&1]<<endl;
    return 0;
}
