#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n';

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<vector<ll> > dp(2,vector<ll>(4,0));
        dp[0][0] = 1;
        ll sum = 1;
        for (int i = 1; i <= n; ++i) {
            ll tmp = 0;
            for (int j = 0; j < 4; ++j) {
                dp[i%2][j] = sum-dp[(i+1)%2][j];
                tmp += dp[i%2][j];
            }
            sum = tmp;
        }
        cout<<dp[n%2][0]<<endl;
    }
}
