#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> a(n+1,0), dp(n+1,0), tmp(n+1,1e9+5);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    dp[1] = 1, tmp[1] = a[1], tmp[0] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i] = (lower_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin());
        tmp[dp[i]] = min(tmp[dp[i]],a[i]);
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
    return 0;
}
