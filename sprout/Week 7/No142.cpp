#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector <int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        vector <long long> dp(n,0);
        for (int i = 0; i < k; ++i) {
            dp[i] = arr[i];
        }
        for (int i = k; i < n; ++i) {
            for (int j = i-k; j >= i-k-k+1; --j) {

            }
        }
    }
}