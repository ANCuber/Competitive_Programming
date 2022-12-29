#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

#define int ll

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<int> v(n), t(n);
    for (auto& i : v) cin>>i;
    for (auto& i : t) cin>>i;
    int sum = 0;
    for (auto i : v) sum += i;

    if (n < 22) {
        int ans = 0;
        for (int i = 0; i < (1<<n); ++i) {
            int cur = 0, tt = 0;
            for (int j = 0; j < n; ++j) {
                if ((1<<j)&i) {
                    cur += v[j];
                    tt += t[j];
                }
            }
            if (tt <= m) ans = max(ans,cur);
        }
        
        cout<<sum-ans<<endl;
    } else {
        vector<vector<int> > dp(2,vector<int>(m+2,-1e9));
        dp[1][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j-t[i] >= 0) dp[i&1][j] = max(dp[i&1^1][j],dp[i&1^1][j-t[i]]+v[i]);
                else dp[i&1][j] = dp[i&1^1][j];
            }
        }
        cout<<sum-*max_element(dp[n&1^1].begin(),dp[n&1^1].end())<<endl;
    }
    return 0;
}
