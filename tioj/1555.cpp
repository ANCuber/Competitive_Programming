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
    int n, m; cin>>n>>m;    
    vector<vector<ll> > dp(2,vector<ll>(m+2,0));
    ll cnt = 0, mx = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char x; cin>>x;
            dp[i&1][j] = (x=='0')*(min({dp[i&1^1][j-1],dp[i&1^1][j],dp[i&1][j-1]})+1);
            mx = max(mx,dp[i&1][j]);
            cnt += dp[i&1][j];
        }
    }
    cout<<cnt<<' '<<mx<<endl;
    return 0;
}
