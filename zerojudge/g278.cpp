#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin>>n>>k;
    vector<int> a(n+2);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    
    vector<vector<int> > dp(n+2,vector<int>(k+2,0));
    vector<int> bnd(n+2,0), ex(1e5+5,0), mx(n+2,0);
    deque<int> q;//by index
    int ptr = 1;
    for (int i = 1; i <= n; ++i) {
        while(ex[a[i]]) ex[a[ptr++]] = 0;
        ex[a[i]] = 1;
        bnd[i] = ptr;
        dp[i][1] = (i-bnd[i]+1);
    }
    for (int i = 2; i <= k; ++i) {
        fill(mx.begin(),mx.end(),0);
        for (int j = 1; j <= n; ++j) mx[j] = max(mx[j-1],dp[j][i-1]);
        for (int j = 1; j <= n; ++j) {
            while(!q.empty() && q.front() < bnd[j]) q.pop_front();
            if (!q.empty()) dp[j][i] = max(mx[bnd[j]-1]+(j-bnd[j]+1),dp[q.front()][i-1]+(j-q.front()));
            else dp[j][i] = mx[bnd[j]-1]+(j-bnd[j]+1);
            while(!q.empty() && dp[j][i-1] >= dp[q.back()][i-1]+(j-q.back())) q.pop_back();
            q.push_back(j);
            //cout<<dp[j][i]<<' ';
        }
        //cout<<endl;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans,dp[i][k]);
    cout<<ans<<'\n';
    return 0;
}
