#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long dp[1001];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 1000; ++i) {
        dp[i] = 2*dp[i-2]+1+dp[i-1];
    }
    for (int i = 1; i <= 1000; ++i) {
        cout<<dp[i]<<',';
    }
    return 0;
}
