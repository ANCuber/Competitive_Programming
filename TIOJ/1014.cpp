#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<ll> t(n);
    for (int i = 0; i < n; ++i) {
        cin>>t[i];
    }
    vector<vector<ll> > dp(1<<n,vector<ll>(n,1e12));
    dp[0][0] = 1; 
    for (int i = 1; i < (1<<n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i&(1<<j)) {
                for (int k = 0; k < n; ++k) {
                    ll x = dp[i&(~(1<<j))][k]+abs(k-j);
                    dp[i][j] = min(dp[i][j],((x-1)/t[j]+1)*t[j]);
                }
            }
        }
    }
    ll ans = 1e12;
    for (int i = 0; i < n; ++i) {
        ans = min(ans,dp[(1<<n)-1][i]);
    }
    cout<<ans<<endl;
    return 0;
}
