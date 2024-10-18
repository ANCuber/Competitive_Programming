#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

const int mod = 1e9+7;

int ctr[500005] = {0};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    for (auto& i : a) cin>>i;

    vector<int> dp(n,0);
    dp[0] = 1;
    ctr[a[0]] = 1;

    for (int i = 1; i < n; ++i) {
        int cur = a[i];
        for (int j = -2; j <= 2; ++j) {
            if (cur+j < 0) continue;
            dp[i] += ctr[cur+j];
            dp[i] %= mod;
        }
        dp[i]++;
        dp[i] %= mod;
        ctr[a[i]] += dp[i];
        ctr[a[i]] %= mod;
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (dp[i])%mod;
        ans %= mod;
    }
    cout<<ans<<endl;

    return 0;
}
