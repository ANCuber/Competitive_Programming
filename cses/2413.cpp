#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define endl '\n'
#define pb push_back

const ll mod = 1e9+7;
const int maxn = 1e6;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t; cin>>t;    
    vector<vector<ll> > dp(maxn+5,vector<ll>(2));//1 is separated
    dp[1][1] = dp[1][0] = 1;
    for (int i = 2; i <= maxn; ++i) {
        dp[i][1] = (dp[i-1][0]+dp[i-1][1]*4%mod)%mod;
        dp[i][0] = (dp[i-1][1]+dp[i-1][0]*2%mod)%mod;
    }
    while(t--) {
        cin>>n;
        cout<<(dp[n][0]+dp[n][1])%mod<<endl;
    }
    return 0;
}
