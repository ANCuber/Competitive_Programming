#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<string> a(n+1), b(n+1);
        vector<vector<int> > dp(n+1,vector<int>(n+1,0));

        for (int i = n; i > 0; --i) cin>>a[i];
        for (int i = n; i > 0; --i) cin>>b[i];
        for (int i = 1; i <= n; ++i) {
            int mx = 0;
            for (int j = 1; j <= n; ++j) {
                dp[i%2]
                if (a[i]>b[i]) {
                    
                }
                if (a[i] == b[i]) {
                    
                }
            }
        }

    }
    
    return 0;
}
