#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int w, b, n, m; 

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) {
        cin>>w>>b>>n;
        vector<int> a(n+1), d(n+1), dp(w,0);
        for (int i = 1; i <= n; ++i) cin>>a[i]>>d[i];
        cin>>m;
        dp[0] = 0;
        
        for (int i = 1; i < w; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i-a[j]-m >= 0) dp[i] = max(dp[i],dp[i-a[j]-m]+d[j]);
            }
        }
        
        if (*max_element(dp.begin(),dp.end()) >= b) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
