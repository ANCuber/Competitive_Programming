#include <bits/stdc++.h>
using namespace std;

long long dp[1000005];

long long f(int x) {
    if (dp[x] != 0) return dp[x];
    
    dp[x] = f(x-1) + f (x-2);
    return dp[x];
}

int main() {
    int n; cin>>n;
    dp[1] = 1;
    dp[2] = 1;
    cout<<f(n)<<'\n';
    return 0;
}