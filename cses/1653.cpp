#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n;
ll x;

pii solve(int s, vector<int> &dp) {
    if (!s) return dp[s] = {0,0};
    for (int i = 0; i < n; ++i) {
        
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>x;
    vector<ll> w(n);
    vector<int> dp(1<<n,0);
    for (auto& i : w) cin>>i;
    
    return 0;
}
