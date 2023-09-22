#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mod = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k, D; cin>>k>>D;
    vector<vector<int> > T(k+5,vector<int>(k+5));
    for (int i = 1; i <= k; ++i) { 
        for (int j = 1; j <= k; ++j) {
            cin>>T[i][j];
        }
    }
    
    int n; cin>>n;
    vector<vector<int> > dp(k+5,vector<int>(n+5,0));
    vector<int> nx(k+5,0);
    for (int i = 1; i <= k; ++i) dp[i][0] = 1;
    
    for (int i = 1; i <= n-1; ++i) {
        int tmp; cin>>tmp;
        for (int j = 1; j <= k; ++j) {
            if (T[j][1]-D > tmp || T[j][k]+D < tmp) continue;
            int l = 1, r = k+1;
            int L, R;
            
            while(r-l > 1) {
                int mid = (l+r)>>1;
                if (tmp >= T[j][mid]-D) l = mid;
                else r = mid;
            }
            R = l;
            
            l = 0, r = k;
            while(r-l > 1) {
                int mid = (l+r)>>1;
                if (tmp <= T[j][mid]+D) r = mid;
                else l = mid;
            }
            L = r;
            
            //cout<<j<<"->"<<L<<"~"<<R<<endl;
            if (R < L) continue;
            nx[L] += dp[j][i-1];
            nx[R+1] -= dp[j][i-1];
        }
        
        for (int j = 1; j <= k; ++j) {
            nx[j] += nx[j-1];
            nx[j] %= mod;
            dp[j][i] = nx[j];
        }
        for (int j = 0; j <= k; ++j) nx[j] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += dp[i][n-1];
        ans %= mod;
    }
    cout<<ans<<endl;
    
    return 0;
}
