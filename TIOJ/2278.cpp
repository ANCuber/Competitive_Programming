#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'
#define int ll

const int mod = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, sum; cin>>n>>a;
    vector<int> dp(n+1,0);
    dp[a] = sum = 1;
    for (int j = 2; j <= n; ++j) {
        cin>>a;
        int i = sum-dp[a];
        i = (i+mod)%mod;
        dp[a] += i; dp[a] %= mod;
        sum += i; sum %= mod;
    }
    cout<<sum<<endl;
    return 0;
}
