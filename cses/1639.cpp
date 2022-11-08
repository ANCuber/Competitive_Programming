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
    string a, b; cin>>a>>b;
    int n = a.size(), m = b.size();
    vector<vector<int> > dp(n+1,vector<int>(m+1));
    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int i = 0; i <= m; ++i) dp[0][i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
