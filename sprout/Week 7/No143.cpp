#include <bits/stdc++.h>
using namespace std;

long long solve (int l, int r, vector<vector<long long> > &dp, vector <int> &arr, vector<long long> &presum) {
    if (dp[l][r]) return dp[l][r];
    if (l == r) return 0;
    if (r - l == 1) {
        dp[l][r] = arr[l]+arr[r];
        return dp[l][r];
    }
    long long minans = LONG_LONG_MAX;
    for (int i = l; i < r; ++i) {
        long long x = solve(l,i,dp,arr,presum)+solve(i+1,r,dp,arr,presum);
        x += presum[r+1]-presum[l];
        minans = min(minans,x);
    }
    dp[l][r] = minans;
    return dp[l][r];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector <int> arr(n);
        vector <long long> presum(n+1,0);//amount of elements
        presum[0] = 0;
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
            presum[i+1] = arr[i]+presum[i];
        }
        vector <vector<long long> > dp(n, vector<long long> (n,0));
        //the smallest amount in dp[l,r]
        cout<<solve(0,n-1,dp,arr,presum)<<endl;
    }
    return 0;
}