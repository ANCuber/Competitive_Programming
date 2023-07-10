#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Run() {
    int n; cin>>n;
    int ans = 0;
    vector<int> a(n+5), dp(n+5,0), pmx(n+5,0), nmx(n+5,-1e9);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    nmx[a[1]] = -1;
    for (int i = 2; i <= n; ++i) {
        if (nmx[a[i]] != -1e9) dp[i] = i+1+nmx[a[i]];
        else dp[i] = 0;
        pmx[i] = max(pmx[i-1],dp[i]);
        nmx[a[i]] = max(nmx[a[i]],pmx[i-1]-i);
        ans = max(dp[i],ans);
        //cout<<dp[i]<<' ';
    }
    //cout<<endl;
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
