#include <bits/stdc++.h>
#define int long long

using namespace std;

int const maxn=1e6+500;
int const mod=1e9+7;
int dp[3][maxn] = {0};
int n,m;

signed main(){
    cin>>m>>n;
    dp[1][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = 1+dp[1][i-1];
    }
}