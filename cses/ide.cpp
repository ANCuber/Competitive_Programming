#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define int long long

const int mod = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    vector<int> a(n);
    for (auto& i : a) cin>>i;
    vector<int> dp(m+2,0);
    if (a[0]) {
        dp[a[0]]++;
    } else {
        for (auto& i : dp) i = 1;
        dp[0] = dp[m+1] = 0;
    }
    
    for (int i = 1; i < n; ++i) {
        if (a[i]) {
            for (int j = 1; j <= m; ++j) {
                if(abs(a[i]-j) == 1) dp[a[i]] = (dp[j]+dp[a[i]])%mod;  
                if(j != a[i]) dp[j] = 0;
            }
        } else {
            vector<int> tmp = dp;
            for (int j = 1; j <= m; ++j) {
                dp[j] = tmp[j-1]+tmp[j]+tmp[j+1];
                dp[j] %= mod;
            }
        }
        //for (auto i : dp) cout<<i;
        //cout<<endl;
    }

    if (a[n-1]) {
        cout<<dp[a[n-1]]<<endl;
    } else {
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans += dp[i];
            ans %= mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}
