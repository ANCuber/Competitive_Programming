#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector <long long> arr(n);
        vector <long long> dp(n,0);
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        dp[0] = arr[0];
        dp[1] = arr[1];
        dp[2] = arr[0]+arr[2];
        for (int i = 3; i < n; ++i) {
            dp[i] = max(dp[i-2],dp[i-3]) + arr[i];
        }
        cout<<max(dp[n-1],dp[n-2])<<endl;
    }
    return 0;
}