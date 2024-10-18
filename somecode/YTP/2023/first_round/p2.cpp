#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, w; cin>>n>>w;    
    int ans = 0;
    vector<pii> itm(n);
    for (int i = 0; i < n; ++i) {
        int a, b, c; cin>>a>>b>>c;
        itm[i].first = a;
        itm[i].second = c;
        ans += (a+b);
    }
    
    vector<int> dp(w+1,0), mx(w+1,0);
    dp[w] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = w; j >= 0; --j) {
            if (j+itm[i].second <= w) dp[j] = max(dp[j+itm[i].second]+itm[i].first,dp[j]);
        }
    }
    cout<<ans+(*max_element(dp.begin(),dp.end()))<<endl;
    
    return 0;
}
