#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod  1000007

vector <long long> dp(100001,0);

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t; cin>>t;
    dp[2] = 3;
    dp[4] = dp[2]*dp[2] + 2;
    int id = 6;
    while(id <= 100000) {
        for (int i = 1; i <= 4; ++i) {
            dp[id] += dp[id-2];
            dp[id] %= mod;
        }
        dp[id] -= dp[id-4];
        dp[id] = (dp[id]+mod) % mod;
        id += 2;
    }
    while(t--) {
        int n; cin>>n;
        if (n & 1) cout<<0<<endl;
        else {
            cout<<dp[n]<<endl;
        }
    }
    return 0;
}