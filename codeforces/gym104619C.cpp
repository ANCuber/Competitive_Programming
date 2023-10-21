#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s, b; cin>>s>>b;
    if (s == "0") {
        cout<<"0\n";
        return 0;
    }
    int n = s.size(), m = b.size();
    vector<vector<int> > dp(n+5,vector<int>(m+5,1e8));
    for (int i = 1; i <= m; ++i) dp[n-i][i] = (s[n-i]!=0)?(0):(1e8);
    if (s.substr(n-m,m) > b.substr(0,m)) dp[n-m][m] = 1e8;
    
    for (int i = n-2; i >= 0; --i) {
        if (s[i] == '0') continue;
        for (int j = 1; j <= m && i+j+j-1 < n; ++j) {
            if (s.substr(i,j) <= s.substr(i+j,j)) dp[i][j] = min(dp[i][j],dp[i+j][j]+1);//len = j
            for (int k = j+1; k <= m && i+j+k-1 < n; ++k) {//len > j
                dp[i][j] = min(dp[i][j],dp[i+j][k]+1);
            }
        }
    }
    int ans = 1e8;
    for (int i = 1; i <= m; ++i) {
        ans = min(ans,dp[0][i]);
    }
    if (ans == 1e8) cout<<"NO WAY\n";
    else cout<<ans<<'\n';
    return 0;
}
