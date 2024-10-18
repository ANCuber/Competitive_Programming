#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, a, b, c;    
    cin>>n>>q>>a>>b>>c;
    if (q != 0 || a != 0) return 0;
    string s; cin>>s;
    vector<vector< pii > > dp(2,vector< pii >(n+5,{0,0}));
    s = "!"+s;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'A') {
            dp[1][i].first = 0;
            dp[1][i].second = min(dp[1][i-1].second,dp[0][i-1].second)+1;
            dp[1][i].first = dp[1][i-1].first+dp[0][i-1].first;
        } else if (s[i] == 'C') {
            dp[0][i].first = 0;
            dp[0][i].second = min(dp[0][i-1].second,dp[1][i-1].first);
            dp[0][i].first = dp[1][i-1].first+dp[0][i-1].first+dp[1][i-1].second+dp[0][i-1].second;
        } else {
            dp[1][i].first = 0;
            dp[1][i].second = min(dp[1][i-1].second,dp[0][i-1].second)+1;
            dp[1][i].first = dp[1][i-1].first+dp[0][i-1].first;
            dp[0][i].first = 0;
            dp[0][i].second = min(dp[0][i-1].second,dp[1][i-1].first);
            dp[0][i].first = dp[1][i-1].first+dp[0][i-1].first+dp[1][i-1].second+dp[0][i-1].second;

        }
    }
    cout<<(dp[0][n].first+dp[1][n].first)*(b)<<endl;
    return 0;
}
