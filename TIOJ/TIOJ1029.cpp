#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int dp[1005][1005];

int main() {
    int n; cin>>n;
    int s = 0;
    for (int i = 2; i <= n-1; ++i) {
        cin>>dp[i][i];
        s += dp[i][i];
        
    }
    
}