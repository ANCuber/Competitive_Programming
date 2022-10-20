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
    int m, n; cin>>m>>n;
    int mx = -2e9;
    vector<vector<int> > dp(2,vector<int>(n+1,0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int a; cin>>a;
            dp[i%2][j] = max({dp[i%2][j-1],dp[(i+1)%2][j],0})+a;
            if (i == m || j == n) mx = max(mx,dp[i%2][j]);
        }
    }
    cout<<mx<<endl;
    return 0;
}
