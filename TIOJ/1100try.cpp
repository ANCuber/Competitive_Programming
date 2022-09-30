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

#define int long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n && n) {
        vector< pii > a(n+1), dp(n+1,{0,0});
        vector<int> p(n+1,0);
        for (int i = 1; i <= n; ++i) cin>>a[i].first>>a[i].second>>p[i];
        //dp[1] = {1,a[1].first+p[1]-1};
        for (int i = 1; i <= n; ++i) {
            if (a[i].first-1+p[i] > a[i].second) {
                dp[i] = {0,1e9};
                continue;
            }
            int mx = 0, bd = a[i].first+p[i]-1;
            for (int j = 1; j < i; ++j) {
                if (dp[j].second < a[i].first || dp[j].second+p[i] <= a[i].second) {
                    if (mx < dp[j].first) {
                        mx = dp[j].first;
                        bd = max(dp[j].second,a[i].first-1)+p[i];
                    } else if (mx == dp[j].first) {
                        bd = min(bd,max(dp[j].second,a[i].first-1)+p[i]);
                    }
                }
            }
            dp[i] = {mx+1,bd};
            //cout<<dp[i].first<<' '<<dp[i].second<<endl;
        }
        cout<<max_element(dp.begin(),dp.end())->first<<endl;
    }
    return 0;
}

