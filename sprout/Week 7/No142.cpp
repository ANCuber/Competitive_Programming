#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        if (k == 1) {
            long long ans = 0;
            for (int i = 0; i < n; ++i) {
                int x; cin>>x;
                ans += x;
            }
            cout<<ans<<endl;
            continue;
        }
        if (k == n) {
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                int x; cin>>x;
                ans = max(ans,x);
            }
            cout<<ans<<endl;
            continue;
        }
        vector <long long> arr(n);
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        vector <long long> dp(n,0);
        for (int i = 0; i < k; ++i) {
            dp[i] = arr[i];
        } 
        dp[k] = arr[0]+arr[k];
        for (int i = k+1; i < n; ++i) {
            long long maxsum = -1;
            for (int j = max(0,i-k-k+1); i-j >= k; j++) {
                maxsum = max(maxsum,dp[j]);
            }
            dp[i] = maxsum + arr[i];
        }
        long long ans = -1;
        for (int i = n-1; i >= n-k && i >= 0; --i) {
            ans = max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}