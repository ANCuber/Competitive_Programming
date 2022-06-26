#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector <ll> bell(n);
        for (int i = 0; i < n; ++i) {
            cin>>bell[i];
        }
        vector <ll> dp(n);
        dp[0] = 0;
        dp[1] = abs(bell[1]-bell[0]);
        for (int i = 2; i < n; ++i) {
            dp[i] = min(dp[i-1]+abs(bell[i]-bell[i-1]),dp[i-2]+abs(bell[i]-bell[i-2]));
        }
        cout<<dp[n-1]<<endl;
    }
    return 0;
}